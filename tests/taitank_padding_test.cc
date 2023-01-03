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

TEST(TAITANK_TEST, padding_no_size) {
  const TaitankNodeRef root = NodeCreate();
  SetPadding(root, CSS_LEFT, 10);
  SetPadding(root, CSS_TOP, 10);
  SetPadding(root, CSS_RIGHT, 10);
  SetPadding(root, CSS_BOTTOM, 10);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(20, GetWidth(root));
  ASSERT_FLOAT_EQ(20, GetHeight(root));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(20, GetWidth(root));
  ASSERT_FLOAT_EQ(20, GetHeight(root));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, padding_container_match_child) {
  const TaitankNodeRef root = NodeCreate();
  SetPadding(root, CSS_LEFT, 10);
  SetPadding(root, CSS_TOP, 10);
  SetPadding(root, CSS_RIGHT, 10);
  SetPadding(root, CSS_BOTTOM, 10);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 10);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(30, GetWidth(root));
  ASSERT_FLOAT_EQ(30, GetHeight(root));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(30, GetWidth(root));
  ASSERT_FLOAT_EQ(30, GetHeight(root));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, padding_flex_child) {
  const TaitankNodeRef root = NodeCreate();
  SetPadding(root, CSS_LEFT, 10);
  SetPadding(root, CSS_TOP, 10);
  SetPadding(root, CSS_RIGHT, 10);
  SetPadding(root, CSS_BOTTOM, 10);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetWidth(root_child0, 10);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, padding_stretch_child) {
  const TaitankNodeRef root = NodeCreate();
  SetPadding(root, CSS_LEFT, 10);
  SetPadding(root, CSS_TOP, 10);
  SetPadding(root, CSS_RIGHT, 10);
  SetPadding(root, CSS_BOTTOM, 10);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(80, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(80, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, padding_center_child) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetPadding(root, CSS_START, 10);
  SetPadding(root, CSS_END, 20);
  SetPadding(root, CSS_BOTTOM, 20);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 10);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(35, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(35, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, child_with_padding_align_end) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_END);
  SetAlignItems(root, FLEX_ALIGN_END);
  SetWidth(root, 200);
  SetHeight(root, 200);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPadding(root_child0, CSS_LEFT, 20);
  SetPadding(root_child0, CSS_TOP, 20);
  SetPadding(root_child0, CSS_RIGHT, 20);
  SetPadding(root_child0, CSS_BOTTOM, 20);
  SetWidth(root_child0, 100);
  SetHeight(root_child0, 100);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(200, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(100, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(200, GetWidth(root));
  ASSERT_FLOAT_EQ(200, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(100, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  NodeFreeRecursive(root);
}
