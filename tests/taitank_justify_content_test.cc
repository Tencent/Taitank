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
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 102);
  SetHeight(root, 102);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(20, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(92, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(82, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(72, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_flex_end) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetJustifyContent(root, FLEX_ALIGN_END);
  SetWidth(root, 102);
  SetHeight(root, 102);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(72, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(82, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(92, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(20, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_center) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetWidth(root, 102);
  SetHeight(root, 102);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(36, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(46, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(56, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(56, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(46, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(36, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_space_between) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetJustifyContent(root, FLEX_ALIGN_SPACE_BETWEEN);
  SetWidth(root, 102);
  SetHeight(root, 102);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(46, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(92, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(92, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(46, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_space_around) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetJustifyContent(root, FLEX_ALIGN_SPACE_AROUND);
  SetWidth(root, 102);
  SetHeight(root, 102);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(12, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(46, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(46, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(12, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_flex_start) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 102);
  SetHeight(root, 102);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, GetTop(root_child1));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(20, GetTop(root_child2));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, GetTop(root_child1));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(20, GetTop(root_child2));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_flex_end) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_END);
  SetWidth(root, 102);
  SetHeight(root, 102);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(72, GetTop(root_child0));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(82, GetTop(root_child1));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(92, GetTop(root_child2));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(72, GetTop(root_child0));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(82, GetTop(root_child1));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(92, GetTop(root_child2));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_center) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetWidth(root, 102);
  SetHeight(root, 102);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(36, GetTop(root_child0));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, GetTop(root_child1));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(56, GetTop(root_child2));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(36, GetTop(root_child0));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, GetTop(root_child1));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(56, GetTop(root_child2));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_space_between) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_SPACE_BETWEEN);
  SetWidth(root, 102);
  SetHeight(root, 102);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, GetTop(root_child1));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(92, GetTop(root_child2));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, GetTop(root_child1));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(92, GetTop(root_child2));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_space_around) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_SPACE_AROUND);
  SetWidth(root, 102);
  SetHeight(root, 102);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(12, GetTop(root_child0));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, GetTop(root_child1));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(80, GetTop(root_child2));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(12, GetTop(root_child0));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, GetTop(root_child1));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(80, GetTop(root_child2));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_min_width_and_margin) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetMargin(root, CSS_LEFT, 100);
  SetMinWidth(root, 50);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 20);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(100, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(20, GetHeight(root));

  ASSERT_FLOAT_EQ(15, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(100, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(20, GetHeight(root));

  ASSERT_FLOAT_EQ(15, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_max_width_and_margin) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetMargin(root, CSS_LEFT, 100);
  SetWidth(root, 100);
  SetMaxWidth(root, 80);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 20);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(100, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(80, GetWidth(root));
  ASSERT_FLOAT_EQ(20, GetHeight(root));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(100, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(80, GetWidth(root));
  ASSERT_FLOAT_EQ(20, GetHeight(root));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_min_height_and_margin) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetMargin(root, CSS_TOP, 100);
  SetMinHeight(root, 50);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 20);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(100, GetTop(root));
  ASSERT_FLOAT_EQ(20, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(15, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(100, GetTop(root));
  ASSERT_FLOAT_EQ(20, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(15, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_colunn_max_height_and_margin) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetMargin(root, CSS_TOP, 100);
  SetHeight(root, 100);
  SetMaxHeight(root, 80);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 20);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(100, GetTop(root));
  ASSERT_FLOAT_EQ(20, GetWidth(root));
  ASSERT_FLOAT_EQ(80, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(30, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(100, GetTop(root));
  ASSERT_FLOAT_EQ(20, GetWidth(root));
  ASSERT_FLOAT_EQ(80, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(30, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_column_space_evenly) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_SPACE_EVENLY);
  SetWidth(root, 102);
  SetHeight(root, 102);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(18, GetTop(root_child0));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, GetTop(root_child1));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(74, GetTop(root_child2));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(18, GetTop(root_child0));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, GetTop(root_child1));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(74, GetTop(root_child2));
  ASSERT_FLOAT_EQ(102, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_row_space_evenly) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetJustifyContent(root, FLEX_ALIGN_SPACE_EVENLY);
  SetWidth(root, 102);
  SetHeight(root, 102);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(26, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(51, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(77, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(102, GetWidth(root));
  ASSERT_FLOAT_EQ(102, GetHeight(root));

  ASSERT_FLOAT_EQ(77, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(51, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(26, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  NodeFreeRecursive(root);
}
