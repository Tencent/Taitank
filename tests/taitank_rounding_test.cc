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
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexGrow(root_child2, 1);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(33, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(33, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(34, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(67, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(33, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(67, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(33, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(33, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(34, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(33, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_flex_basis_flex_grow_row_prime_number_width) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 113);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexGrow(root_child2, 1);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetFlexGrow(root_child3, 1);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetFlexGrow(root_child4, 1);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(113, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(23, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(23, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(22, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(45, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(23, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(68, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, GetTop(root_child3));
  ASSERT_FLOAT_EQ(22, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(90, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(23, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(113, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(90, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(23, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(68, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(22, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(45, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(23, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(23, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, GetTop(root_child3));
  ASSERT_FLOAT_EQ(22, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(23, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_flex_basis_flex_shrink_row) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 101);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexShrink(root_child0, 1);
  SetFlexBasis(root_child0, 100);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexBasis(root_child1, 25);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexBasis(root_child2, 25);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(101, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(51, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(51, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(25, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(76, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(25, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(101, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(51, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(25, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(25, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_flex_basis_overrides_main_size) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetHeight(root, 113);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetFlexBasis(root_child0, 50);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexGrow(root_child2, 1);
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(113, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(64, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(64, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(25, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(113, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(64, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(64, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(25, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_total_fractial) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 87.4f);
  SetHeight(root, 113.4f);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 0.7f);
  SetFlexBasis(root_child0, 50.3f);
  SetHeight(root_child0, 20.3f);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1.6f);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexGrow(root_child2, 1.1f);
  SetHeight(root_child2, 10.7f);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(87, GetWidth(root));
  ASSERT_FLOAT_EQ(113, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(59, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(59, GetTop(root_child1));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(87, GetWidth(root));
  ASSERT_FLOAT_EQ(113, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(59, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(59, GetTop(root_child1));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_total_fractial_nested) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 87.4f);
  SetHeight(root, 113.4f);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 0.7f);
  SetFlexBasis(root_child0, 50.3f);
  SetHeight(root_child0, 20.3f);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0, 1);
  SetFlexBasis(root_child0_child0, 0.3f);
  SetPosition(root_child0_child0, CSS_BOTTOM, 13.3f);
  SetHeight(root_child0_child0, 9.9f);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = NodeCreate();
  SetFlexGrow(root_child0_child1, 4);
  SetFlexBasis(root_child0_child1, 0.3f);
  SetPosition(root_child0_child1, CSS_TOP, 13.3f);
  SetHeight(root_child0_child1, 1.1f);
  InsertChild(root_child0, root_child0_child1, 1);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1.6f);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexGrow(root_child2, 1.1f);
  SetHeight(root_child2, 10.7f);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(87, GetWidth(root));
  ASSERT_FLOAT_EQ(113, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(59, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(-13, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(12, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(25, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(47, GetHeight(root_child0_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(59, GetTop(root_child1));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(87, GetWidth(root));
  ASSERT_FLOAT_EQ(113, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(59, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(-13, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(12, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(25, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(47, GetHeight(root_child0_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(59, GetTop(root_child1));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(87, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_fractial_input_1) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetHeight(root, 113.4f);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetFlexBasis(root_child0, 50);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexGrow(root_child2, 1);
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(113, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(64, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(64, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(25, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(113, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(64, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(64, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(25, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_fractial_input_2) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetHeight(root, 113.6f);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetFlexBasis(root_child0, 50);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexGrow(root_child2, 1);
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(114, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(65, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(65, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(25, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(114, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(65, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(65, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(25, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_fractial_input_3) {
  const TaitankNodeRef root = NodeCreate();
  SetPosition(root, CSS_TOP, 0.3f);
  SetWidth(root, 100);
  SetHeight(root, 113.4f);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetFlexBasis(root_child0, 50);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexGrow(root_child2, 1);
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(114, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(65, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(64, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(25, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(114, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(65, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(64, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(25, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_fractial_input_4) {
  const TaitankNodeRef root = NodeCreate();
  SetPosition(root, CSS_TOP, 0.7f);
  SetWidth(root, 100);
  SetHeight(root, 113.4f);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetFlexBasis(root_child0, 50);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexGrow(root_child2, 1);
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(1, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(113, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(64, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(64, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(25, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(1, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(113, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(64, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(64, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(25, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(89, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(24, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_inner_node_controversy_horizontal) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 320);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child1_child0 = NodeCreate();
  SetFlexGrow(root_child1_child0, 1);
  SetHeight(root_child1_child0, 10);
  InsertChild(root_child1, root_child1_child0, 0);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexGrow(root_child2, 1);
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(320, GetWidth(root));
  ASSERT_FLOAT_EQ(10, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(107, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(107, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(106, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1_child0));
  ASSERT_FLOAT_EQ(106, GetWidth(root_child1_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1_child0));

  ASSERT_FLOAT_EQ(213, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(107, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(320, GetWidth(root));
  ASSERT_FLOAT_EQ(10, GetHeight(root));

  ASSERT_FLOAT_EQ(213, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(107, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(107, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(106, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1_child0));
  ASSERT_FLOAT_EQ(106, GetWidth(root_child1_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(107, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_inner_node_controversy_vertical) {
  const TaitankNodeRef root = NodeCreate();
  SetHeight(root, 320);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetWidth(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetWidth(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child1_child0 = NodeCreate();
  SetFlexGrow(root_child1_child0, 1);
  SetWidth(root_child1_child0, 10);
  InsertChild(root_child1, root_child1_child0, 0);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexGrow(root_child2, 1);
  SetWidth(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(10, GetWidth(root));
  ASSERT_FLOAT_EQ(320, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(107, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(107, GetTop(root_child1));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(106, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1_child0));
  ASSERT_FLOAT_EQ(106, GetHeight(root_child1_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(213, GetTop(root_child2));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(107, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(10, GetWidth(root));
  ASSERT_FLOAT_EQ(320, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(107, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(107, GetTop(root_child1));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(106, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1_child0));
  ASSERT_FLOAT_EQ(106, GetHeight(root_child1_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(213, GetTop(root_child2));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(107, GetHeight(root_child2));

  NodeFreeRecursive(root);
}
