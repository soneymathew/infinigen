// Copyright (c) Princeton University.
// This source code is licensed under the GPL license found in the LICENSE file in the root directory of this source tree.

// Authors: Zeyu Ma
// Date Signed: June 5 2023

#include "header.h"


extern "C" {
    void call(
        size_t size,
        float3_nonbuiltin *positions,
        float *sdfs,
        float *auxs
    ) {
        using namespace data;
        int n_auxiliaries = 1;
        if (auxs == NULL) n_auxiliaries = 0;
        #pragma omp parallel for
        for (size_t idx = 0; idx < size; idx++) {
            upsidedown_mountains(positions[idx], sdfs + idx, auxs + n_auxiliaries * idx, d_i_params, d_f_params);
        }
    }

}