// Copyright (c) Princeton University.
// This source code is licensed under the GPL license found in the LICENSE file in the root directory of this source tree.

// Authors: Zeyu Ma
// Date Signed: June 5 2023

#include "header.h"
#include "../../common/surfaces/snow.h"

extern "C" {

    void call(
        size_t size,
        float3_nonbuiltin *positions,
        float3_nonbuiltin *normals,
        float3_nonbuiltin *offsets
    ) {
        #pragma omp parallel for
        for (size_t idx = 0; idx < size; idx++) {
            geo_snowtexture(
                positions[idx], normals[idx],
                offsets + idx
            );
        }
    }

}