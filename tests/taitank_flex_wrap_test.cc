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
  const TaitankNodeRef root = NodeCreate();
  SetFlexWrap(root, FLEX_WRAP);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 30);
  SetHeight(root_child0, 30);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 30);
  SetHeight(root_child1, 30);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 30);
  SetHeight(root_child2, 30);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 30);
  SetHeight(root_child3, 30);
  InsertChild(root, root_child3, 3);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(60, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(30, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(60, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child3));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(60, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(30, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(60, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child3));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_row) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 30);
  SetHeight(root_child0, 30);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 30);
  SetHeight(root_child1, 30);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 30);
  SetHeight(root_child2, 30);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 30);
  SetHeight(root_child3, 30);
  InsertChild(root, root_child3, 3);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(60, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(60, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(30, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child3));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(60, GetHeight(root));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(30, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child3));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_row_align_items_flex_end) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignItems(root, FLEX_ALIGN_END);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 30);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 30);
  SetHeight(root_child1, 20);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 30);
  SetHeight(root_child2, 30);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 30);
  SetHeight(root_child3, 30);
  InsertChild(root, root_child3, 3);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(60, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(20, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(60, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(30, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child3));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(60, GetHeight(root));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(20, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(30, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child3));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_row_align_items_center) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 30);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 30);
  SetHeight(root_child1, 20);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 30);
  SetHeight(root_child2, 30);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 30);
  SetHeight(root_child3, 30);
  InsertChild(root, root_child3, 3);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(60, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(5, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(60, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(30, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child3));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(60, GetHeight(root));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(5, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(30, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child3));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_wrap_children_with_min_main_overriding_flex_basis) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexBasis(root_child0, 50);
  SetMinWidth(root_child0, 55);
  SetHeight(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexBasis(root_child1, 50);
  SetMinWidth(root_child1, 55);
  SetHeight(root_child1, 50);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(55, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child1));
  ASSERT_FLOAT_EQ(55, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(45, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(55, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(45, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child1));
  ASSERT_FLOAT_EQ(55, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_wrap_wrap_to_child_height) {
  const TaitankNodeRef root = NodeCreate();

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexDirection(root_child0, FLEX_DIRECTION_ROW);
  SetAlignItems(root_child0, FLEX_ALIGN_START);
  SetFlexWrap(root_child0, FLEX_WRAP);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetWidth(root_child0_child0, 100);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = NodeCreate();
  SetWidth(root_child0_child0_child0, 100);
  SetHeight(root_child0_child0_child0, 100);
  InsertChild(root_child0_child0, root_child0_child0_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 100);
  SetHeight(root_child1, 100);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(200, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(200, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_wrap_align_stretch_fits_one_row) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 150);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_reverse_row_align_content_flex_start) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetFlexWrap(root, FLEX_WRAP_REVERSE);
  SetWidth(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 30);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 30);
  SetHeight(root_child1, 20);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 30);
  SetHeight(root_child2, 30);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 30);
  SetHeight(root_child3, 40);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 30);
  SetHeight(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(80, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(70, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(60, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(60, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(80, GetHeight(root));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(70, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(60, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_reverse_row_align_content_center) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_CENTER);
  SetFlexWrap(root, FLEX_WRAP_REVERSE);
  SetWidth(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 30);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 30);
  SetHeight(root_child1, 20);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 30);
  SetHeight(root_child2, 30);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 30);
  SetHeight(root_child3, 40);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 30);
  SetHeight(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(80, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(70, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(60, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(60, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(80, GetHeight(root));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(70, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(60, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_reverse_row_single_line_different_size) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetFlexWrap(root, FLEX_WRAP_REVERSE);
  SetWidth(root, 300);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 30);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 30);
  SetHeight(root_child1, 20);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 30);
  SetHeight(root_child2, 30);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 30);
  SetHeight(root_child3, 40);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 30);
  SetHeight(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(300, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(40, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(30, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(60, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(20, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(90, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(120, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(300, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(270, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(40, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(240, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(30, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(210, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(20, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(180, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(150, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_reverse_row_align_content_stretch) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_STRETCH);
  SetFlexWrap(root, FLEX_WRAP_REVERSE);
  SetWidth(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 30);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 30);
  SetHeight(root_child1, 20);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 30);
  SetHeight(root_child2, 30);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 30);
  SetHeight(root_child3, 40);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 30);
  SetHeight(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(80, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(70, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(60, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(60, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(80, GetHeight(root));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(70, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(60, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_reverse_row_align_content_space_around) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_SPACE_AROUND);
  SetFlexWrap(root, FLEX_WRAP_REVERSE);
  SetWidth(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 30);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 30);
  SetHeight(root_child1, 20);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 30);
  SetHeight(root_child2, 30);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 30);
  SetHeight(root_child3, 40);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 30);
  SetHeight(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(80, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(70, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(60, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(60, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(80, GetHeight(root));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(70, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(60, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(70, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_reverse_column_fixed_size) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetFlexWrap(root, FLEX_WRAP_REVERSE);
  SetWidth(root, 200);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 30);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 30);
  SetHeight(root_child1, 20);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 30);
  SetHeight(root_child2, 30);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 30);
  SetHeight(root_child3, 40);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 30);
  SetHeight(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(170, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(170, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(170, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(30, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(170, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(60, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(140, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, GetTop(root_child1));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(30, GetTop(root_child2));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(30, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(60, GetTop(root_child3));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(30, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrapped_row_within_align_items_center) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetWidth(root, 200);
  SetHeight(root, 200);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexDirection(root_child0, FLEX_DIRECTION_ROW);
  SetFlexWrap(root_child0, FLEX_WRAP);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetWidth(root_child0_child0, 150);
  SetHeight(root_child0_child0, 80);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = NodeCreate();
  SetWidth(root_child0_child1, 80);
  SetHeight(root_child0_child1, 80);
  InsertChild(root_child0, root_child0_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(200, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(160, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(150, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(200, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(160, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(150, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(120, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrapped_row_within_align_items_flex_start) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 200);
  SetHeight(root, 200);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexDirection(root_child0, FLEX_DIRECTION_ROW);
  SetFlexWrap(root_child0, FLEX_WRAP);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetWidth(root_child0_child0, 150);
  SetHeight(root_child0_child0, 80);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = NodeCreate();
  SetWidth(root_child0_child1, 80);
  SetHeight(root_child0_child1, 80);
  InsertChild(root_child0, root_child0_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(200, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(160, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(150, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(200, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(160, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(150, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(120, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrapped_row_within_align_items_flex_end) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_END);
  SetWidth(root, 200);
  SetHeight(root, 200);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexDirection(root_child0, FLEX_DIRECTION_ROW);
  SetFlexWrap(root_child0, FLEX_WRAP);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetWidth(root_child0_child0, 150);
  SetHeight(root_child0_child0, 80);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = NodeCreate();
  SetWidth(root_child0_child1, 80);
  SetHeight(root_child0_child1, 80);
  InsertChild(root_child0, root_child0_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(200, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(160, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(150, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(200, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(160, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(150, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(120, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrapped_column_max_height) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetAlignContent(root, FLEX_ALIGN_CENTER);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 700);
  SetHeight(root, 500);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 100);
  SetHeight(root_child0, 500);
  SetMaxHeight(root_child0, 200);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetMargin(root_child1, CSS_LEFT, 20);
  SetMargin(root_child1, CSS_TOP, 20);
  SetMargin(root_child1, CSS_RIGHT, 20);
  SetMargin(root_child1, CSS_BOTTOM, 20);
  SetWidth(root_child1, 200);
  SetHeight(root_child1, 200);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 100);
  SetHeight(root_child2, 100);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(700, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(250, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(30, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(250, GetTop(root_child1));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(420, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(200, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(700, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(350, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(30, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(300, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(250, GetTop(root_child1));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(180, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(200, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrapped_column_max_height_flex) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetAlignContent(root, FLEX_ALIGN_CENTER);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 700);
  SetHeight(root, 500);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetFlexShrink(root_child0, 1);
  SetFlexBasis(root_child0, 0);
  SetWidth(root_child0, 100);
  SetHeight(root_child0, 500);
  SetMaxHeight(root_child0, 200);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetFlexShrink(root_child1, 1);
  SetFlexBasis(root_child1, 0);
  SetMargin(root_child1, CSS_LEFT, 20);
  SetMargin(root_child1, CSS_TOP, 20);
  SetMargin(root_child1, CSS_RIGHT, 20);
  SetMargin(root_child1, CSS_BOTTOM, 20);
  SetWidth(root_child1, 200);
  SetHeight(root_child1, 200);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 100);
  SetHeight(root_child2, 100);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(700, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(300, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(180, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(250, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(200, GetTop(root_child1));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(180, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(300, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(400, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(700, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(300, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(180, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(250, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(200, GetTop(root_child1));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(180, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(300, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(400, GetTop(root_child2));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_nodes_with_content_sizing_overflowing_margin) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 500);
  SetHeight(root, 500);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexDirection(root_child0, FLEX_DIRECTION_ROW);
  SetFlexWrap(root_child0, FLEX_WRAP);
  SetWidth(root_child0, 85);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = NodeCreate();
  SetWidth(root_child0_child0_child0, 40);
  SetHeight(root_child0_child0_child0, 40);
  InsertChild(root_child0_child0, root_child0_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = NodeCreate();
  SetMargin(root_child0_child1, CSS_RIGHT, 10);
  InsertChild(root_child0, root_child0_child1, 1);

  const TaitankNodeRef root_child0_child1_child0 = NodeCreate();
  SetWidth(root_child0_child1_child0, 40);
  SetHeight(root_child0_child1_child0, 40);
  InsertChild(root_child0_child1, root_child0_child1_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(500, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(85, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(40, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child1_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(500, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(415, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(85, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(45, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child0_child0));

  ASSERT_FLOAT_EQ(35, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(40, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child1_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, wrap_nodes_with_content_sizing_margin_cross) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 500);
  SetHeight(root, 500);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexDirection(root_child0, FLEX_DIRECTION_ROW);
  SetFlexWrap(root_child0, FLEX_WRAP);
  SetWidth(root_child0, 70);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = NodeCreate();
  SetWidth(root_child0_child0_child0, 40);
  SetHeight(root_child0_child0_child0, 40);
  InsertChild(root_child0_child0, root_child0_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = NodeCreate();
  SetMargin(root_child0_child1, CSS_TOP, 10);
  InsertChild(root_child0, root_child0_child1, 1);

  const TaitankNodeRef root_child0_child1_child0 = NodeCreate();
  SetWidth(root_child0_child1_child0, 40);
  SetHeight(root_child0_child1_child0, 40);
  InsertChild(root_child0_child1, root_child0_child1_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(500, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(70, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(90, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child1_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(500, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(430, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(70, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(90, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child0_child0));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, GetWidth(root_child0_child1_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0_child1_child0));

  NodeFreeRecursive(root);
}
