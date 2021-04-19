/*
 *
 * Tencent is pleased to support the open source community by making Taitank available. 
 * Copyright (C) 2021 THL A29 Limited, a Tencent company.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the “License”);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *    http:// www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed in writing, software
 * distributed under the License is distributed on an “AS IS” BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and limitations
 * under the License.
 *
 */

#include "taitank.h"

#include "gtest.h"

using namespace taitank;

TEST(TAITANK_TEST, computed_layout_margin) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);
  set_taitank_node_style_margin(root, CSS_START, 10);

  TaitankNodeDoLayout(root, 100, 100);

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_margin(root, CSS_LEFT));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_margin(root, CSS_RIGHT));

  TaitankNodeDoLayout(root, 100, 100, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_margin(root, CSS_LEFT));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_margin(root, CSS_RIGHT));

  TaitankNodeFreeRecursive(root);
}
