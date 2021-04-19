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

TEST(TAITANK_TEST, absolute_layout_width_height_start_top) {
  const TaitankNodeRef root = TaitankNodeCreate();

  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child0, CSS_START, 10);
  set_taitank_node_style_position(root_child0, CSS_TOP, 10);
  set_taitank_node_style_width(root_child0, 10);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_width_height_end_bottom) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child0, CSS_END, 10);
  set_taitank_node_style_position(root_child0, CSS_BOTTOM, 10);
  set_taitank_node_style_width(root_child0, 10);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_start_top_end_bottom) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child0, CSS_LEFT, 10);
  set_taitank_node_style_position(root_child0, CSS_TOP, 10);
  set_taitank_node_style_position(root_child0, CSS_RIGHT, 10);
  set_taitank_node_style_position(root_child0, CSS_BOTTOM, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_width_height_start_top_end_bottom) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child0, CSS_LEFT, 10);
  set_taitank_node_style_position(root_child0, CSS_TOP, 10);
  set_taitank_node_style_position(root_child0, CSS_RIGHT, 10);
  set_taitank_node_style_position(root_child0, CSS_BOTTOM, 10);
  set_taitank_node_style_width(root_child0, 10);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, do_not_clamp_height_of_absolute_node_to_height_of_its_overflow_hidden_parent) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_overflow(root, OVERFLOW_HIDDEN);
  set_taitank_node_style_width(root, 50);
  set_taitank_node_style_height(root, 50);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child0, CSS_START, 0);
  set_taitank_node_style_position(root_child0, CSS_TOP, 0);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child0, 100);
  set_taitank_node_style_height(root_child0_child0, 100);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(-50, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_within_border) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_margin(root, CSS_LEFT, 10);
  set_taitank_node_style_margin(root, CSS_TOP, 10);
  set_taitank_node_style_margin(root, CSS_RIGHT, 10);
  set_taitank_node_style_margin(root, CSS_BOTTOM, 10);
  set_taitank_node_style_padding(root, CSS_LEFT, 10);
  set_taitank_node_style_padding(root, CSS_TOP, 10);
  set_taitank_node_style_padding(root, CSS_RIGHT, 10);
  set_taitank_node_style_padding(root, CSS_BOTTOM, 10);
  set_taitank_node_style_border(root, CSS_LEFT, 10);
  set_taitank_node_style_border(root, CSS_TOP, 10);
  set_taitank_node_style_border(root, CSS_RIGHT, 10);
  set_taitank_node_style_border(root, CSS_BOTTOM, 10);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child0, CSS_LEFT, 0);
  set_taitank_node_style_position(root_child0, CSS_TOP, 0);
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child1, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child1, CSS_RIGHT, 0);
  set_taitank_node_style_position(root_child1, CSS_BOTTOM, 0);
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child2, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child2, CSS_LEFT, 0);
  set_taitank_node_style_position(root_child2, CSS_TOP, 0);
  set_taitank_node_style_margin(root_child2, CSS_LEFT, 10);
  set_taitank_node_style_margin(root_child2, CSS_TOP, 10);
  set_taitank_node_style_margin(root_child2, CSS_RIGHT, 10);
  set_taitank_node_style_margin(root_child2, CSS_BOTTOM, 10);
  set_taitank_node_style_width(root_child2, 50);
  set_taitank_node_style_height(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child3, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child3, CSS_RIGHT, 0);
  set_taitank_node_style_position(root_child3, CSS_BOTTOM, 0);
  set_taitank_node_style_margin(root_child3, CSS_LEFT, 10);
  set_taitank_node_style_margin(root_child3, CSS_TOP, 10);
  set_taitank_node_style_margin(root_child3, CSS_RIGHT, 10);
  set_taitank_node_style_margin(root_child3, CSS_BOTTOM, 10);
  set_taitank_node_style_width(root_child3, 50);
  set_taitank_node_style_height(root_child3, 50);
  TaitankNodeInsertChild(root, root_child3, 3);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child3));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child3));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_and_justify_content_center) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_grow(root, 1);
  set_taitank_node_style_width(root, 110);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_width(root_child0, 60);
  set_taitank_node_style_height(root_child0, 40);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_and_justify_content_flex_end) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_END);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_END);
  set_taitank_node_style_flex_grow(root, 1);
  set_taitank_node_style_width(root, 110);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_width(root_child0, 60);
  set_taitank_node_style_height(root_child0, 40);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_justify_content_center) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_grow(root, 1);
  set_taitank_node_style_width(root, 110);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_width(root_child0, 60);
  set_taitank_node_style_height(root_child0, 40);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_center) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_grow(root, 1);
  set_taitank_node_style_width(root, 110);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_width(root_child0, 60);
  set_taitank_node_style_height(root_child0, 40);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_center_on_child_only) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root, 1);
  set_taitank_node_style_width(root, 110);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_align_self(root_child0, FLEX_ALIGN_CENTER);
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_width(root_child0, 60);
  set_taitank_node_style_height(root_child0, 40);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_and_justify_content_center_and_top_position) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_grow(root, 1);
  set_taitank_node_style_width(root, 110);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child0, CSS_TOP, 10);
  set_taitank_node_style_width(root_child0, 60);
  set_taitank_node_style_height(root_child0, 40);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_and_justify_content_center_and_bottom_position) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_grow(root, 1);
  set_taitank_node_style_width(root, 110);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child0, CSS_BOTTOM, 10);
  set_taitank_node_style_width(root_child0, 60);
  set_taitank_node_style_height(root_child0, 40);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_and_justify_content_center_and_left_position) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_grow(root, 1);
  set_taitank_node_style_width(root, 110);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child0, CSS_LEFT, 5);
  set_taitank_node_style_width(root_child0, 60);
  set_taitank_node_style_height(root_child0, 40);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));
  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_and_justify_content_center_and_right_position) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_grow(root, 1);
  set_taitank_node_style_width(root, 110);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_position(root_child0, CSS_RIGHT, 5);
  set_taitank_node_style_width(root_child0, 60);
  set_taitank_node_style_height(root_child0, 40);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, position_root_with_rtl_should_position_withoutdirection) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_position(root, CSS_LEFT, 72);
  set_taitank_node_style_width(root, 52);
  set_taitank_node_style_height(root, 52);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  TaitankNodeFreeRecursive(root);
}

// TEST(TAITANK_TEST, absolute_layout_percentage_bottom_based_on_parent_height)
// {
//
//
//  const TaitankNodeRef root = TaitankNodeCreate();
//  set_taitank_node_style_width(root, 100);
//  set_taitank_node_style_height(root, 200);
//
//  const TaitankNodeRef root_child0 = TaitankNodeCreate();
//  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
//  set_taitank_node_style_positionPercent(root_child0, CSS_TOP, 50);
//  set_taitank_node_style_width(root_child0, 10);
//  set_taitank_node_style_height(root_child0, 10);
//  TaitankNodeInsertChild(root, root_child0, 0);
//
//  const TaitankNodeRef root_child1 = TaitankNodeCreate();
//  set_taitank_node_style_position_type(root_child1, POSITION_TYPE_ABSOLUTE);
//  set_taitank_node_style_positionPercent(root_child1, CSS_BOTTOM, 50);
//  set_taitank_node_style_width(root_child1, 10);
//  set_taitank_node_style_height(root_child1, 10);
//  TaitankNodeInsertChild(root, root_child1, 1);
//
//  const TaitankNodeRef root_child2 = TaitankNodeCreate();
//  set_taitank_node_style_position_type(root_child2, POSITION_TYPE_ABSOLUTE);
//  set_taitank_node_style_positionPercent(root_child2, CSS_TOP, 10);
//  set_taitank_node_style_positionPercent(root_child2, CSS_BOTTOM, 10);
//  set_taitank_node_style_width(root_child2, 10);
//  TaitankNodeInsertChild(root, root_child2, 2);
//   TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
//  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
//  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
//  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root_child0));
//  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
//  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
//  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_top(root_child1));
//  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
//  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
//  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child2));
//  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
//  ASSERT_FLOAT_EQ(160, get_taitank_node_layout_height(root_child2));
//
//  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,);
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
//  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
//  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));
//
//  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child0));
//  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root_child0));
//  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
//  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));
//
//  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child1));
//  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_top(root_child1));
//  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
//  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));
//
//  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child2));
//  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child2));
//  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
//  ASSERT_FLOAT_EQ(160, get_taitank_node_layout_height(root_child2));
//
//  TaitankNodeFreeRecursive(root);
//
//
//}

TEST(TAITANK_TEST, absolute_layout_in_wrap_reverse_column_container) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP_REVERSE);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_width(root_child0, 20);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_in_wrap_reverse_row_container) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP_REVERSE);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_width(root_child0, 20);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_in_wrap_reverse_column_container_flex_end) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP_REVERSE);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_align_self(root_child0, FLEX_ALIGN_END);
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_width(root_child0, 20);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_in_wrap_reverse_row_container_flex_end) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP_REVERSE);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_align_self(root_child0, FLEX_ALIGN_END);
  set_taitank_node_style_position_type(root_child0, POSITION_TYPE_ABSOLUTE);
  set_taitank_node_style_width(root_child0, 20);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}
