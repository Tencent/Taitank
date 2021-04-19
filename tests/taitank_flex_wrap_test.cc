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

TEST(TAITANK_TEST, wrap_column) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 30);
  set_taitank_node_style_height(root_child0, 30);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 30);
  set_taitank_node_style_height(root_child1, 30);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 30);
  set_taitank_node_style_height(root_child2, 30);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 30);
  set_taitank_node_style_height(root_child3, 30);
  TaitankNodeInsertChild(root, root_child3, 3);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child3));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child3));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_row) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 30);
  set_taitank_node_style_height(root_child0, 30);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 30);
  set_taitank_node_style_height(root_child1, 30);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 30);
  set_taitank_node_style_height(root_child2, 30);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 30);
  set_taitank_node_style_height(root_child3, 30);
  TaitankNodeInsertChild(root, root_child3, 3);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child3));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child3));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_row_align_items_flex_end) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_END);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 30);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 30);
  set_taitank_node_style_height(root_child1, 20);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 30);
  set_taitank_node_style_height(root_child2, 30);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 30);
  set_taitank_node_style_height(root_child3, 30);
  TaitankNodeInsertChild(root, root_child3, 3);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child3));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child3));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_row_align_items_center) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 30);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 30);
  set_taitank_node_style_height(root_child1, 20);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 30);
  set_taitank_node_style_height(root_child2, 30);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 30);
  set_taitank_node_style_height(root_child3, 30);
  TaitankNodeInsertChild(root, root_child3, 3);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child3));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child3));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_wrap_children_with_min_main_overriding_flex_basis) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_basis(root_child0, 50);
  set_taitank_node_style_min_width(root_child0, 55);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_basis(root_child1, 50);
  set_taitank_node_style_min_width(root_child1, 55);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(55, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(55, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(55, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(55, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_wrap_wrap_to_child_height) {
  const TaitankNodeRef root = TaitankNodeCreate();

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_items(root_child0, FLEX_ALIGN_START);
  set_taitank_node_style_flex_wrap(root_child0, FLEX_WRAP);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child0, 100);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child0_child0, 100);
  set_taitank_node_style_height(root_child0_child0_child0, 100);
  TaitankNodeInsertChild(root_child0_child0, root_child0_child0_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 100);
  set_taitank_node_style_height(root_child1, 100);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_wrap_align_stretch_fits_one_row) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 150);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_reverse_row_align_content_flex_start) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP_REVERSE);
  set_taitank_node_style_width(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 30);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 30);
  set_taitank_node_style_height(root_child1, 20);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 30);
  set_taitank_node_style_height(root_child2, 30);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 30);
  set_taitank_node_style_height(root_child3, 40);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 30);
  set_taitank_node_style_height(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_reverse_row_align_content_center) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP_REVERSE);
  set_taitank_node_style_width(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 30);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 30);
  set_taitank_node_style_height(root_child1, 20);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 30);
  set_taitank_node_style_height(root_child2, 30);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 30);
  set_taitank_node_style_height(root_child3, 40);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 30);
  set_taitank_node_style_height(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_reverse_row_single_line_different_size) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP_REVERSE);
  set_taitank_node_style_width(root, 300);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 30);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 30);
  set_taitank_node_style_height(root_child1, 20);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 30);
  set_taitank_node_style_height(root_child2, 30);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 30);
  set_taitank_node_style_height(root_child3, 40);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 30);
  set_taitank_node_style_height(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(120, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(270, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(240, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(210, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(180, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_reverse_row_align_content_stretch) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP_REVERSE);
  set_taitank_node_style_width(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 30);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 30);
  set_taitank_node_style_height(root_child1, 20);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 30);
  set_taitank_node_style_height(root_child2, 30);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 30);
  set_taitank_node_style_height(root_child3, 40);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 30);
  set_taitank_node_style_height(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_reverse_row_align_content_space_around) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_SPACE_AROUND);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP_REVERSE);
  set_taitank_node_style_width(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 30);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 30);
  set_taitank_node_style_height(root_child1, 20);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 30);
  set_taitank_node_style_height(root_child2, 30);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 30);
  set_taitank_node_style_height(root_child3, 40);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 30);
  set_taitank_node_style_height(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_reverse_column_fixed_size) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP_REVERSE);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 30);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 30);
  set_taitank_node_style_height(root_child1, 20);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 30);
  set_taitank_node_style_height(root_child2, 30);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 30);
  set_taitank_node_style_height(root_child3, 40);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 30);
  set_taitank_node_style_height(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(170, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(170, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(170, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(170, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(140, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrapped_row_within_align_items_center) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root_child0, FLEX_WRAP);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child0, 150);
  set_taitank_node_style_height(root_child0_child0, 80);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child1, 80);
  set_taitank_node_style_height(root_child0_child1, 80);
  TaitankNodeInsertChild(root_child0, root_child0_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(160, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(160, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(120, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrapped_row_within_align_items_flex_start) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root_child0, FLEX_WRAP);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child0, 150);
  set_taitank_node_style_height(root_child0_child0, 80);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child1, 80);
  set_taitank_node_style_height(root_child0_child1, 80);
  TaitankNodeInsertChild(root_child0, root_child0_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(160, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(160, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(120, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrapped_row_within_align_items_flex_end) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_END);
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root_child0, FLEX_WRAP);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child0, 150);
  set_taitank_node_style_height(root_child0_child0, 80);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child1, 80);
  set_taitank_node_style_height(root_child0_child1, 80);
  TaitankNodeInsertChild(root_child0, root_child0_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(160, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(160, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(120, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrapped_column_max_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 700);
  set_taitank_node_style_height(root, 500);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 100);
  set_taitank_node_style_height(root_child0, 500);
  set_taitank_node_style_max_height(root_child0, 200);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child1, CSS_LEFT, 20);
  set_taitank_node_style_margin(root_child1, CSS_TOP, 20);
  set_taitank_node_style_margin(root_child1, CSS_RIGHT, 20);
  set_taitank_node_style_margin(root_child1, CSS_BOTTOM, 20);
  set_taitank_node_style_width(root_child1, 200);
  set_taitank_node_style_height(root_child1, 200);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 100);
  set_taitank_node_style_height(root_child2, 100);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(700, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(420, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(700, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(350, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(180, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrapped_column_max_height_flex) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 700);
  set_taitank_node_style_height(root, 500);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 0);
  set_taitank_node_style_width(root_child0, 100);
  set_taitank_node_style_height(root_child0, 500);
  set_taitank_node_style_max_height(root_child0, 200);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  set_taitank_node_style_flex_shrink(root_child1, 1);
  set_taitank_node_style_flex_basis(root_child1, 0);
  set_taitank_node_style_margin(root_child1, CSS_LEFT, 20);
  set_taitank_node_style_margin(root_child1, CSS_TOP, 20);
  set_taitank_node_style_margin(root_child1, CSS_RIGHT, 20);
  set_taitank_node_style_margin(root_child1, CSS_BOTTOM, 20);
  set_taitank_node_style_width(root_child1, 200);
  set_taitank_node_style_height(root_child1, 200);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 100);
  set_taitank_node_style_height(root_child2, 100);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(700, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(180, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(180, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(400, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(700, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(180, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(250, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(180, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(400, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_nodes_with_content_sizing_overflowing_margin) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 500);
  set_taitank_node_style_height(root, 500);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root_child0, FLEX_WRAP);
  set_taitank_node_style_width(root_child0, 85);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child0_child0, 40);
  set_taitank_node_style_height(root_child0_child0_child0, 40);
  TaitankNodeInsertChild(root_child0_child0, root_child0_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child0_child1, CSS_RIGHT, 10);
  TaitankNodeInsertChild(root_child0, root_child0_child1, 1);

  const TaitankNodeRef root_child0_child1_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child1_child0, 40);
  set_taitank_node_style_height(root_child0_child1_child0, 40);
  TaitankNodeInsertChild(root_child0_child1, root_child0_child1_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(85, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child1_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(415, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(85, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child0_child0));

  ASSERT_FLOAT_EQ(35, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child1_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_nodes_with_content_sizing_margin_cross) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 500);
  set_taitank_node_style_height(root, 500);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root_child0, FLEX_WRAP);
  set_taitank_node_style_width(root_child0, 70);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child0_child0, 40);
  set_taitank_node_style_height(root_child0_child0_child0, 40);
  TaitankNodeInsertChild(root_child0_child0, root_child0_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child0_child1, CSS_TOP, 10);
  TaitankNodeInsertChild(root_child0, root_child0_child1, 1);

  const TaitankNodeRef root_child0_child1_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child1_child0, 40);
  set_taitank_node_style_height(root_child0_child1_child0, 40);
  TaitankNodeInsertChild(root_child0_child1, root_child0_child1_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child1_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(430, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(70, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child0_child0));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_width(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0_child1_child0));

  TaitankNodeFreeRecursive(root);
}
