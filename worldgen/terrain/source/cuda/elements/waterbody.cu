// Copyright (c) Princeton University.
// This source code is licensed under the GPL license found in the LICENSE file in the root directory of this source tree.

// Authors: Zeyu Ma
// Date Signed: June 5 2023

#include "header.h"


__global__ void waterbody_kernel(
    size_t size,
    float3_nonbuiltin *position,
    float *sdfs, float *auxs,
    int mark_boundary, int is_caved,
    int *i_params, float *f_params,
    int *landtiles_i_params, float *landtiles_f_params,
    int *caves_i_params, float *caves_f_params
) {
    size_t idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < size) {
        int n_auxiliaries = 1;
        if (auxs == NULL) n_auxiliaries = 0;
        waterbody(
            position[idx], sdfs + idx, auxs + idx * n_auxiliaries,
            mark_boundary, is_caved, i_params, f_params,
            landtiles_i_params, landtiles_f_params,
            caves_i_params, caves_f_params
        );
    }
}



extern "C" {
    void call(
        size_t size,
        float3_nonbuiltin *positions,
        float *sdfs,
        float *auxs
    ) {
        using namespace data;
        const int n_auxiliaries = 1;
        float3_nonbuiltin *d_positions;
        cudaMalloc((void **)&d_positions, size * sizeof(float3_nonbuiltin));
        cudaMemcpy(d_positions, positions, size * sizeof(float3_nonbuiltin), cudaMemcpyHostToDevice);
        float *d_sdfs;
        cudaMalloc((void **)&d_sdfs, size * sizeof(float));
        float *d_auxs=NULL;
        if (auxs != NULL) cudaMalloc((void **)&d_auxs, size * n_auxiliaries * sizeof(float));
        waterbody_kernel<<<ceil(size / 256.0), 256>>>(
            size, d_positions, d_sdfs, d_auxs, meta_param, second_meta_param,
            d_i_params, d_f_params, second_d_i_params, second_d_f_params, third_d_i_params, third_d_f_params
        );
        cudaMemcpy(sdfs, d_sdfs, size * sizeof(float), cudaMemcpyDeviceToHost);
        if (auxs != NULL) cudaMemcpy(auxs, d_auxs, size * n_auxiliaries * sizeof(float), cudaMemcpyDeviceToHost);
        cudaFree(d_positions);
        cudaFree(d_sdfs);
    }
}