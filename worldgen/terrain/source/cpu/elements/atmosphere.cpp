// Copyright (c) Princeton University.
// This source code is licensed under the GPL license found in the LICENSE file in the root directory of this source tree.

// Authors: Zeyu Ma
// Date Signed: June 5 2023

#include "header.h"


extern "C" {
    void call(
        size_t size,
        float3_nonbuiltin *positions,
        float *sdfs
    ) {
        using namespace data;
        #pragma omp parallel for
        for (size_t idx = 0; idx < size; idx++) {
            atmosphere(
                positions[idx], sdfs + idx, meta_param,
                d_i_params, d_f_params, second_d_i_params, second_d_f_params
            );

        }
    }
}