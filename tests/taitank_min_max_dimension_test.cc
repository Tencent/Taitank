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

TEST(TAITANK_TEST, max_width) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMaxWidth(root_child0, 50);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, max_height) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 10);
  SetMaxHeight(root_child0, 50);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(90, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, min_height) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetMinHeight(root_child0, 60);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(80, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(80, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, min_width) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetMinWidth(root_child0, 60);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(80, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(20, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(80, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_min_max) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetWidth(root, 100);
  SetMinHeight(root, 100);
  SetMaxHeight(root, 200);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 60);
  SetHeight(root_child0, 60);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(20, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(60, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(20, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(60, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_min_max) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetMinWidth(root, 100);
  SetMaxWidth(root, 200);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 60);
  SetHeight(root_child0, 60);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(20, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(60, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(20, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(60, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_overflow_min_max) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetMinHeight(root, 100);
  SetMaxHeight(root, 110);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  SetHeight(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  SetHeight(root_child1, 50);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  SetHeight(root_child2, 50);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(110, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(-20, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(30, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(80, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(110, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(-20, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(30, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(80, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_to_min) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetMinHeight(root, 100);
  SetMaxHeight(root, 500);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetFlexShrink(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetHeight(root_child1, 50);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_in_at_most_container) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexDirection(root_child0, FLEX_DIRECTION_ROW);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0, 1);
  SetFlexBasis(root_child0_child0, 0);
  InsertChild(root_child0, root_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_child) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetFlexBasis(root_child0, 0);
  SetHeight(root_child0, 100);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(0, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(0, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_constrained_min_max_column) {
  const TaitankNodeRef root = NodeCreate();
  SetMinHeight(root, 100);
  SetMaxHeight(root, 200);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetHeight(root_child1, 50);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(0, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(0, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_max_width) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 200);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexDirection(root_child0, FLEX_DIRECTION_ROW);
  SetMaxWidth(root_child0, 100);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0, 1);
  SetHeight(root_child0_child0, 20);
  InsertChild(root_child0, root_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_constrained_max_width) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 200);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexDirection(root_child0, FLEX_DIRECTION_ROW);
  SetMaxWidth(root_child0, 300);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0, 1);
  SetHeight(root_child0_child0, 20);
  InsertChild(root_child0, root_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(200, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_root_ignored) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexGrow(root, 1);
  SetWidth(root, 100);
  SetMinHeight(root, 100);
  SetMaxHeight(root, 500);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetFlexBasis(root_child0, 200);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetHeight(root_child1, 100);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(300, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(200, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(300, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(200, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_root_minimized) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetMinHeight(root, 100);
  SetMaxHeight(root, 500);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetMinHeight(root_child0, 100);
  SetMaxHeight(root_child0, 500);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0, 1);
  SetFlexBasis(root_child0_child0, 200);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = NodeCreate();
  SetHeight(root_child0_child1, 100);
  InsertChild(root_child0, root_child0_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(300, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(300, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(200, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(200, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(300, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(300, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(200, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(200, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_height_maximized) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetHeight(root, 500);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetMinHeight(root_child0, 100);
  SetMaxHeight(root_child0, 500);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0, 1);
  SetFlexBasis(root_child0_child0, 200);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = NodeCreate();
  SetHeight(root_child0_child1, 100);
  InsertChild(root_child0, root_child0_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(500, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(400, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(400, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(500, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(400, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(400, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_constrained_min_row) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetMinWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
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
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_constrained_min_column) {
  const TaitankNodeRef root = NodeCreate();
  SetMinHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetHeight(root_child1, 50);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(0, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(0, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_constrained_max_row) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 200);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexDirection(root_child0, FLEX_DIRECTION_ROW);
  SetMaxWidth(root_child0, 100);
  SetHeight(root_child0, 100);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexShrink(root_child0_child0, 1);
  SetFlexBasis(root_child0_child0, 100);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = NodeCreate();
  SetWidth(root_child0_child1, 50);
  InsertChild(root_child0, root_child0_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_constrained_max_column) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetMaxHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexShrink(root_child0, 1);
  SetFlexBasis(root_child0, 100);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetHeight(root_child1, 50);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, child_min_max_width_flexing) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 120);
  SetHeight(root, 50);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetFlexBasis(root_child0, 0);
  SetMinWidth(root_child0, 60);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetFlexBasis(root_child1, 60);
  SetMaxWidth(root_child1, 20);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(120, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(120, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(20, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, min_width_overrides_width) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 50);
  SetMinWidth(root, 100);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(0, GetHeight(root));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(0, GetHeight(root));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, max_width_overrides_width) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 200);
  SetMaxWidth(root, 100);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(0, GetHeight(root));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(0, GetHeight(root));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, min_height_overrides_height) {
  const TaitankNodeRef root = NodeCreate();
  SetHeight(root, 50);
  SetMinHeight(root, 100);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(0, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(0, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, max_height_overrides_height) {
  const TaitankNodeRef root = NodeCreate();
  SetHeight(root, 200);
  SetMaxHeight(root, 100);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(0, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(0, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, min_max_percent_no_width_height) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMinWidth(root_child0, 10);
  SetMaxWidth(root_child0, 10);
  SetMinHeight(root_child0, 10);
  SetMaxHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(90, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}
