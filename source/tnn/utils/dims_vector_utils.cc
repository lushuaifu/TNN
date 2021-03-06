// Tencent is pleased to support the open source community by making TNN available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#include "tnn/utils/dims_vector_utils.h"

namespace TNN_NS {

int DimsVectorUtils::Count(DimsVector dims, int start_index, int end_index) {
    if (dims.size() < start_index) {
        return 0;
    }

    if (-1 == end_index || end_index > dims.size()) {
        end_index = static_cast<int>(dims.size());
    }

    int result = 1;
    for (int index = start_index; index < end_index; ++index) {
        result *= dims[index];
    }
    return result;
}

DimsVector DimsVectorUtils::Max(DimsVector dims0, DimsVector dims1, int start_index, int end_index) {
    DimsVector max_dims;
    DimsVector small_dims;
    if (dims0.size() >= dims1.size()) {
        max_dims   = dims0;
        small_dims = dims1;
    } else {
        max_dims   = dims1;
        small_dims = dims0;
    }

    if (small_dims.size() <= start_index) {
        return small_dims;
    }

    if (-1 == end_index || end_index > small_dims.size()) {
        end_index = static_cast<int>(small_dims.size());
    }

    for (int i = start_index; i < end_index; i++) {
        max_dims[i] = std::max(max_dims[i], small_dims[i]);
    }

    return max_dims;
}

bool DimsVectorUtils::Equal(DimsVector dims0, DimsVector dims1, int start_index, int end_index) {
    if (dims0.size() <= start_index) {
        return false;
    }

    if (-1 == end_index || end_index > dims0.size()) {
        end_index = static_cast<int>(dims0.size());
    }

    if (dims0.size() != dims1.size()) {
        return false;
    }

    for (int i = start_index; i < end_index; i++) {
        if (dims0[i] != dims1[i]) {
            return false;
        }
    }
    return true;
}

}  // namespace TNN_NS
