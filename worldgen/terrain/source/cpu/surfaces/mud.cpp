// Copyright (c) Princeton University.
// This source code is licensed under the GPL license found in the LICENSE file in the root directory of this source tree.

// Authors: Zeyu Ma
// Date Signed: June 5 2023

#include "header.h"
#include "../../common/surfaces/mud.h"

extern "C" {

    void call(
        size_t size,
        float3_nonbuiltin *positions,
        float3_nonbuiltin *normals,
        size_t n_f_params, float *f_params,
        size_t n_f4_params, float4_nonbuiltin *f4_params,
        float3_nonbuiltin *offsets
    ) {
        #pragma omp parallel for
        for (size_t idx = 0; idx < size; idx++) {
            geo_mud(
                positions[idx], normals[idx], f_params, f4_params, 
                offsets + idx
            );
        }
    }

}