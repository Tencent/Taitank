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

TEST(TAITANK_TEST, justify_content_row_flex_start) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 102);
  set_taitank_node_style_height(root, 102);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(92, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(82, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_flex_end) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_END);
  set_taitank_node_style_width(root, 102);
  set_taitank_node_style_height(root, 102);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(82, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(92, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_center) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 102);
  set_taitank_node_style_height(root, 102);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(36, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(56, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(56, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(36, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_space_between) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_SPACE_BETWEEN);
  set_taitank_node_style_width(root, 102);
  set_taitank_node_style_height(root, 102);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(92, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(92, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_space_around) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_SPACE_AROUND);
  set_taitank_node_style_width(root, 102);
  set_taitank_node_style_height(root, 102);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(12, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(12, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_flex_start) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 102);
  set_taitank_node_style_height(root, 102);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_flex_end) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_END);
  set_taitank_node_style_width(root, 102);
  set_taitank_node_style_height(root, 102);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(82, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(92, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(82, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(92, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_center) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 102);
  set_taitank_node_style_height(root, 102);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(36, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(56, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(36, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(56, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_space_between) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_SPACE_BETWEEN);
  set_taitank_node_style_width(root, 102);
  set_taitank_node_style_height(root, 102);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(92, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(92, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_space_around) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_SPACE_AROUND);
  set_taitank_node_style_width(root, 102);
  set_taitank_node_style_height(root, 102);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(12, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(12, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_min_width_and_margin) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_margin(root, CSS_LEFT, 100);
  set_taitank_node_style_min_width(root, 50);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 20);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(15, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(15, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_max_width_and_margin) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_margin(root, CSS_LEFT, 100);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_max_width(root, 80);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 20);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_min_height_and_margin) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_margin(root, CSS_TOP, 100);
  set_taitank_node_style_min_height(root, 50);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 20);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(15, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(15, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_colunn_max_height_and_margin) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_margin(root, CSS_TOP, 100);
  set_taitank_node_style_height(root, 100);
  set_taitank_node_style_max_height(root, 80);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 20);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_space_evenly) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_SPACE_EVENLY);
  set_taitank_node_style_width(root, 102);
  set_taitank_node_style_height(root, 102);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(18, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(74, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(18, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(46, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(74, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_space_evenly) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_SPACE_EVENLY);
  set_taitank_node_style_width(root, 102);
  set_taitank_node_style_height(root, 102);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(26, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(51, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(77, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(102, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(77, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(51, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(26, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}
