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

TEST(TAITANK_TEST, border_no_size) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_border(root, CSS_LEFT, 10);
  set_taitank_node_style_border(root, CSS_TOP, 10);
  set_taitank_node_style_border(root, CSS_RIGHT, 10);
  set_taitank_node_style_border(root, CSS_BOTTOM, 10);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, border_container_match_child) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_border(root, CSS_LEFT, 10);
  set_taitank_node_style_border(root, CSS_TOP, 10);
  set_taitank_node_style_border(root, CSS_RIGHT, 10);
  set_taitank_node_style_border(root, CSS_BOTTOM, 10);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 10);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, border_flex_child) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_border(root, CSS_LEFT, 10);
  set_taitank_node_style_border(root, CSS_TOP, 10);
  set_taitank_node_style_border(root, CSS_RIGHT, 10);
  set_taitank_node_style_border(root, CSS_BOTTOM, 10);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_width(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, border_stretch_child) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_border(root, CSS_LEFT, 10);
  set_taitank_node_style_border(root, CSS_TOP, 10);
  set_taitank_node_style_border(root, CSS_RIGHT, 10);
  set_taitank_node_style_border(root, CSS_BOTTOM, 10);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, border_center_child) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_border(root, CSS_START, 10);
  set_taitank_node_style_border(root, CSS_END, 20);
  set_taitank_node_style_border(root, CSS_BOTTOM, 20);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 10);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(35, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(35, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}
