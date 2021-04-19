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

TEST(TAITANK_TEST, rounding_flex_basis_flex_grow_row_width_of_100) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child2, 1);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(33, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(33, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(34, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(67, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(33, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(67, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(33, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(33, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(34, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(33, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_flex_basis_flex_grow_row_prime_number_width) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 113);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child2, 1);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child3, 1);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child4, 1);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(113, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(23, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(23, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(22, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(23, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(68, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(22, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(23, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(113, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(23, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(68, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(22, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(23, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(23, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(22, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(23, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_flex_basis_flex_shrink_row) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 101);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_shrink(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 100);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_basis(root_child1, 25);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_flex_basis(root_child2, 25);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(101, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(51, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(51, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(76, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(101, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(51, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_flex_basis_overrides_main_size) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 113);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 50);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child2, 1);
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(113, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(113, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_total_fractial) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 87.4f);
  set_taitank_node_style_height(root, 113.4f);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 0.7f);
  set_taitank_node_style_flex_basis(root_child0, 50.3f);
  set_taitank_node_style_height(root_child0, 20.3f);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1.6f);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child2, 1.1f);
  set_taitank_node_style_height(root_child2, 10.7f);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(113, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(59, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(59, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(113, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(59, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(59, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_total_fractial_nested) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 87.4f);
  set_taitank_node_style_height(root, 113.4f);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 0.7f);
  set_taitank_node_style_flex_basis(root_child0, 50.3f);
  set_taitank_node_style_height(root_child0, 20.3f);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0, 1);
  set_taitank_node_style_flex_basis(root_child0_child0, 0.3f);
  set_taitank_node_style_position(root_child0_child0, CSS_BOTTOM, 13.3f);
  set_taitank_node_style_height(root_child0_child0, 9.9f);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child1, 4);
  set_taitank_node_style_flex_basis(root_child0_child1, 0.3f);
  set_taitank_node_style_position(root_child0_child1, CSS_TOP, 13.3f);
  set_taitank_node_style_height(root_child0_child1, 1.1f);
  TaitankNodeInsertChild(root_child0, root_child0_child1, 1);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1.6f);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child2, 1.1f);
  set_taitank_node_style_height(root_child2, 10.7f);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(113, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(59, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(-13, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(12, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(47, get_taitank_node_layout_height(root_child0_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(59, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(113, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(59, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(-13, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(12, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(47, get_taitank_node_layout_height(root_child0_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(59, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(87, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_fractial_input_1) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 113.4f);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 50);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child2, 1);
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(113, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(113, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_fractial_input_2) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 113.6f);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 50);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child2, 1);
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(114, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(65, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(65, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(114, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(65, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(65, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_fractial_input_3) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_position(root, CSS_TOP, 0.3f);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 113.4f);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 50);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child2, 1);
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(114, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(65, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(114, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(65, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_fractial_input_4) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_position(root, CSS_TOP, 0.7f);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 113.4f);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 50);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child2, 1);
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(1, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(113, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(1, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(113, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(64, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(89, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(24, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_inner_node_controversy_horizontal) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 320);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child1_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1_child0, 1);
  set_taitank_node_style_height(root_child1_child0, 10);
  TaitankNodeInsertChild(root_child1, root_child1_child0, 0);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child2, 1);
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(320, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(107, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(107, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(106, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1_child0));
  ASSERT_FLOAT_EQ(106, get_taitank_node_layout_width(root_child1_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1_child0));

  ASSERT_FLOAT_EQ(213, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(107, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(320, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(213, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(107, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(107, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(106, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1_child0));
  ASSERT_FLOAT_EQ(106, get_taitank_node_layout_width(root_child1_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(107, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_inner_node_controversy_vertical) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_height(root, 320);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_width(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  set_taitank_node_style_width(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child1_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1_child0, 1);
  set_taitank_node_style_width(root_child1_child0, 10);
  TaitankNodeInsertChild(root_child1, root_child1_child0, 0);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child2, 1);
  set_taitank_node_style_width(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(320, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(107, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(107, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(106, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1_child0));
  ASSERT_FLOAT_EQ(106, get_taitank_node_layout_height(root_child1_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(213, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(107, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(320, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(107, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(107, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(106, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child1_child0));
  ASSERT_FLOAT_EQ(106, get_taitank_node_layout_height(root_child1_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(213, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(107, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}
