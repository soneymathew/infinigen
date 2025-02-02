// Copyright (c) Princeton University.
// This source code is licensed under the GPL license found in the LICENSE file in the root directory of this source tree.

// Authors: Zeyu Ma
// Date Signed: June 5 2023

#include <algorithm>
#include <cmath>
#include <assert.h>
using namespace std;
#define DEVICE_FUNC
#define CONSTANT_ARRAY const
#include "../../common/utils/vectors.h"
#include "../../common/utils/nodes_util.h"
#include "../../common/utils/blender_noise.h"
#include "../../common/utils/elements_util.h"
#include "../../common/utils/FastNoiseLite.h"
#include "../../common/utils/smooth_bool_ops.h"
#include "../../common/nodes/node_shader_tex_noise.h"
#include "../../common/nodes/node_shader_tex_voronoi.h"
#include "../../common/nodes/node_shader_mix_rgb.h"
#include "../../common/elements/caves.h"
#include "../../common/elements/landtiles.h"
#include "../../common/elements/ground.h"
#include "../../common/elements/voronoi_rocks.h"
#include "../../common/elements/warped_rocks.h"
#include "../../common/elements/upsidedown_mountains.h"
#include "../../common/elements/mountains.h"
#include "../../common/elements/waterbody.h"
#include "../../common/elements/atmosphere.h"
#include "core.cpp"