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

TEST(TAITANK_TEST, start_overrides) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_START, 10);
  set_taitank_node_style_margin(root_child0, CSS_END, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_right(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_right(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, end_overrides) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_START, 20);
  set_taitank_node_style_margin(root_child0, CSS_END, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_right(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_right(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, horizontal_overridden) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_HORIZONTAL, 10);
  set_taitank_node_style_margin(root_child0, CSS_LEFT, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_right(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, vertical_overridden) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_COLUMN);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_VERTICAL, 10);
  set_taitank_node_style_margin(root_child0, CSS_TOP, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_bottom(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, horizontal_overrides_all) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_COLUMN);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_HORIZONTAL, 10);
  set_taitank_node_style_margin(root_child0, CSS_ALL, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_right(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_bottom(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, vertical_overrides_all) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_COLUMN);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_VERTICAL, 10);
  set_taitank_node_style_margin(root_child0, CSS_ALL, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_right(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_bottom(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, all_overridden) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_COLUMN);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_LEFT, 10);
  set_taitank_node_style_margin(root_child0, CSS_TOP, 10);
  set_taitank_node_style_margin(root_child0, CSS_RIGHT, 10);
  set_taitank_node_style_margin(root_child0, CSS_BOTTOM, 10);
  set_taitank_node_style_margin(root_child0, CSS_ALL, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_right(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_bottom(root_child0));

  TaitankNodeFreeRecursive(root);
}
