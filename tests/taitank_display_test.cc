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

TEST(TAITANK_TEST, display_none) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetDisplay(root_child1, DISPLAY_TYPE_NONE);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1));

  SetDisplay(root_child1, DISPLAY_TYPE_FLEX);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

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

TEST(TAITANK_TEST, display_none_fixed_size) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 20);
  SetHeight(root_child1, 20);
  SetDisplay(root_child1, DISPLAY_TYPE_NONE);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, display_none_with_margin) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMargin(root_child0, CSS_LEFT, 10);
  SetMargin(root_child0, CSS_TOP, 10);
  SetMargin(root_child0, CSS_RIGHT, 10);
  SetMargin(root_child0, CSS_BOTTOM, 10);
  SetWidth(root_child0, 20);
  SetHeight(root_child0, 20);
  SetDisplay(root_child0, DISPLAY_TYPE_NONE);
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
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, display_none_with_child) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetFlexShrink(root_child0, 1);
  SetFlexBasis(root_child0, 0);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetFlexShrink(root_child1, 1);
  SetFlexBasis(root_child1, 0);
  SetDisplay(root_child1, DISPLAY_TYPE_NONE);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child1_child0 = NodeCreate();
  SetFlexGrow(root_child1_child0, 1);
  SetFlexShrink(root_child1_child0, 1);
  SetFlexBasis(root_child1_child0, 0);
  SetWidth(root_child1_child0, 20);
  SetMinWidth(root_child1_child0, 0);
  SetMinHeight(root_child1_child0, 0);
  InsertChild(root_child1, root_child1_child0, 0);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetFlexGrow(root_child2, 1);
  SetFlexShrink(root_child2, 1);
  SetFlexBasis(root_child2, 0);
  InsertChild(root, root_child2, 2);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

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
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, display_none_with_position) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetPosition(root_child1, CSS_TOP, 10);
  SetDisplay(root_child1, DISPLAY_TYPE_NONE);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1));

  NodeFreeRecursive(root);
}
