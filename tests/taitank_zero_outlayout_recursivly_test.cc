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

TEST(TAITANK_TEST, zero_out_layout) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef child = TaitankNodeCreate();
  TaitankNodeInsertChild(root, child, 0);
  set_taitank_node_style_width(child, 100);
  set_taitank_node_style_height(child, 100);
  set_taitank_node_style_margin(child, CSS_TOP, 10);
  set_taitank_node_style_padding(child, CSS_TOP, 10);

  TaitankNodeDoLayout(root, 100, 100);

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_margin(child, CSS_TOP));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_padding(child, CSS_TOP));

  set_taitank_node_style_display(child, DISPLAY_TYPE_NONE);

  TaitankNodeDoLayout(root, 100, 100);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_margin(child, CSS_TOP));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_padding(child, CSS_TOP));

  TaitankNodeFreeRecursive(root);
}
