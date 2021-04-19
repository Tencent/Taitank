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

TEST(TAITANK_TEST, margin_start) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child0, CSS_START, 10);
  set_taitank_node_style_width(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_top) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child0, CSS_TOP, 10);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_end) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_END);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child0, CSS_END, 10);
  set_taitank_node_style_width(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_bottom) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_END);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child0, CSS_BOTTOM, 10);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_and_flex_row) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_LEFT, 10);
  set_taitank_node_style_margin(root_child0, CSS_RIGHT, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_and_flex_column) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_TOP, 10);
  set_taitank_node_style_margin(root_child0, CSS_BOTTOM, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_and_stretch_row) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_TOP, 10);
  set_taitank_node_style_margin(root_child0, CSS_BOTTOM, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_and_stretch_column) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_LEFT, 10);
  set_taitank_node_style_margin(root_child0, CSS_RIGHT, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_with_sibling_row) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_END, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(55, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(55, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_with_sibling_column) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_margin(root_child0, CSS_BOTTOM, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(55, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(55, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_bottom) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_BOTTOM);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_top) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_TOP);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_bottom_and_top) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_TOP);
  set_taitank_node_style_margin_auto(root_child0, CSS_BOTTOM);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_bottom_and_top_justify_center) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_TOP);
  set_taitank_node_style_margin_auto(root_child0, CSS_BOTTOM);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_mutiple_children_column) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_TOP);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child1, CSS_TOP);
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  set_taitank_node_style_height(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_mutiple_children_row) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_RIGHT);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child1, CSS_RIGHT);
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  set_taitank_node_style_height(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(125, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_left_and_right_column) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_LEFT);
  set_taitank_node_style_margin_auto(root_child0, CSS_RIGHT);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_left_and_right) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_LEFT);
  set_taitank_node_style_margin_auto(root_child0, CSS_RIGHT);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_start_and_end_column) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_LEFT);
  set_taitank_node_style_margin_auto(root_child0, CSS_RIGHT);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_start_and_end) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_LEFT);
  set_taitank_node_style_margin_auto(root_child0, CSS_RIGHT);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_left_and_right_column_and_center) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_LEFT);
  set_taitank_node_style_margin_auto(root_child0, CSS_RIGHT);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_left) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_LEFT);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_right) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_RIGHT);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_left_and_right_strech) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_LEFT);
  set_taitank_node_style_margin_auto(root_child0, CSS_RIGHT);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_top_and_bottom_strech) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_TOP);
  set_taitank_node_style_margin_auto(root_child0, CSS_BOTTOM);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_should_not_be_part_of_max_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 250);
  set_taitank_node_style_height(root, 250);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child0, CSS_TOP, 20);
  set_taitank_node_style_width(root_child0, 100);
  set_taitank_node_style_height(root_child0, 100);
  set_taitank_node_style_max_height(root_child0, 100);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_should_not_be_part_of_max_width) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 250);
  set_taitank_node_style_height(root, 250);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child0, CSS_LEFT, 20);
  set_taitank_node_style_width(root_child0, 100);
  set_taitank_node_style_max_width(root_child0, 100);
  set_taitank_node_style_height(root_child0, 100);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_left_right_child_bigger_than_parent) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 52);
  set_taitank_node_style_height(root, 52);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_LEFT);
  set_taitank_node_style_margin_auto(root_child0, CSS_RIGHT);
  set_taitank_node_style_width(root_child0, 72);
  set_taitank_node_style_height(root_child0, 72);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(-20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_left_child_bigger_than_parent) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 52);
  set_taitank_node_style_height(root, 52);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_LEFT);
  set_taitank_node_style_width(root_child0, 72);
  set_taitank_node_style_height(root_child0, 72);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(-20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_fix_left_auto_right_child_bigger_than_parent) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 52);
  set_taitank_node_style_height(root, 52);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child0, CSS_LEFT, 10);
  set_taitank_node_style_margin_auto(root_child0, CSS_RIGHT);
  set_taitank_node_style_width(root_child0, 72);
  set_taitank_node_style_height(root_child0, 72);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(-20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_left_fix_right_child_bigger_than_parent) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 52);
  set_taitank_node_style_height(root, 52);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin_auto(root_child0, CSS_LEFT);
  set_taitank_node_style_margin(root_child0, CSS_RIGHT, 10);
  set_taitank_node_style_width(root_child0, 72);
  set_taitank_node_style_height(root_child0, 72);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(-30, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_top_stretching_child) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 0);
  set_taitank_node_style_margin_auto(root_child0, CSS_TOP);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, margin_auto_left_stretching_child) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 0);
  set_taitank_node_style_margin_auto(root_child0, CSS_LEFT);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}
