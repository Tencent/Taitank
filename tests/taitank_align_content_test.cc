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

TEST(TAITANK_TEST, align_content_flex_start) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 130);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 50);
  SetHeight(root_child3, 10);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  SetHeight(root_child4, 10);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(130, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(10, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(20, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_flex_start_without_height_on_children) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 50);
  SetHeight(root_child3, 10);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(10, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(20, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child4));

  NodeFreeRecursive(root);
}
//
// TEST(TAITANK_TEST, align_content_flex_start_with_flex) {
//
//
//  const TaitankNodeRef root = NodeCreate();
//  SetFlexWrap(root, FLEX_WRAP);
//  SetWidth(root, 100);
//  SetHeight(root, 120);
//
//  const TaitankNodeRef root_child0 = NodeCreate();
//  SetFlexGrow(root_child0, 1);
//  SetFlexBasis_percent(root_child0, 0);
//  SetWidth(root_child0, 50);
//  InsertChild(root, root_child0, 0);
//
//  const TaitankNodeRef root_child1 = NodeCreate();
//  SetFlexGrow(root_child1, 1);
//  SetFlexBasis_percent(root_child1, 0);
//  SetWidth(root_child1, 50);
//  SetHeight(root_child1, 10);
//  InsertChild(root, root_child1, 1);
//
//  const TaitankNodeRef root_child2 = NodeCreate();
//  SetWidth(root_child2, 50);
//  InsertChild(root, root_child2, 2);
//
//  const TaitankNodeRef root_child3 = NodeCreate();
//  SetFlexGrow(root_child3, 1);
//  SetFlexShrink(root_child3, 1);
//  SetFlexBasis_percent(root_child3, 0);
//  SetWidth(root_child3, 50);
//  InsertChild(root, root_child3, 3);
//
//  const TaitankNodeRef root_child4 = NodeCreate();
//  SetWidth(root_child4, 50);
//  InsertChild(root, root_child4, 4);
//   DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root));
//  ASSERT_FLOAT_EQ(0, GetTop(root));
//  ASSERT_FLOAT_EQ(100, GetWidth(root));
//  ASSERT_FLOAT_EQ(120, GetHeight(root));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
//  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
//  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
//  ASSERT_FLOAT_EQ(40, GetTop(root_child1));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
//  ASSERT_FLOAT_EQ(40, GetHeight(root_child1));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
//  ASSERT_FLOAT_EQ(80, GetTop(root_child2));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
//  ASSERT_FLOAT_EQ(0, GetHeight(root_child2));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
//  ASSERT_FLOAT_EQ(80, GetTop(root_child3));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
//  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child4));
//  ASSERT_FLOAT_EQ(120, GetTop(root_child4));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
//  ASSERT_FLOAT_EQ(0, GetHeight(root_child4));
//
//  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root));
//  ASSERT_FLOAT_EQ(0, GetTop(root));
//  ASSERT_FLOAT_EQ(100, GetWidth(root));
//  ASSERT_FLOAT_EQ(120, GetHeight(root));
//
//  ASSERT_FLOAT_EQ(50, GetLeft(root_child0));
//  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
//  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));
//
//  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
//  ASSERT_FLOAT_EQ(40, GetTop(root_child1));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
//  ASSERT_FLOAT_EQ(40, GetHeight(root_child1));
//
//  ASSERT_FLOAT_EQ(50, GetLeft(root_child2));
//  ASSERT_FLOAT_EQ(80, GetTop(root_child2));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
//  ASSERT_FLOAT_EQ(0, GetHeight(root_child2));
//
//  ASSERT_FLOAT_EQ(50, GetLeft(root_child3));
//  ASSERT_FLOAT_EQ(80, GetTop(root_child3));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
//  ASSERT_FLOAT_EQ(40, GetHeight(root_child3));
//
//  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
//  ASSERT_FLOAT_EQ(120, GetTop(root_child4));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
//  ASSERT_FLOAT_EQ(0, GetHeight(root_child4));
//
//  NodeFreeRecursive(root);
//
//
//}

TEST(TAITANK_TEST, align_content_flex_end) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignContent(root, FLEX_ALIGN_END);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 50);
  SetHeight(root_child3, 10);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  SetHeight(root_child4, 10);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(20, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(30, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(40, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(20, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(30, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(40, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignContent(root, FLEX_ALIGN_STRETCH);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 150);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 50);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_spacebetween) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_SPACE_BETWEEN);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 130);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 50);
  SetHeight(root_child3, 10);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  SetHeight(root_child4, 10);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(130, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(45, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(45, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(90, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(130, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(45, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(45, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(90, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_spacearound) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_SPACE_AROUND);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 140);
  SetHeight(root, 120);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  SetHeight(root_child1, 10);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  SetHeight(root_child2, 10);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 50);
  SetHeight(root_child3, 10);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  SetHeight(root_child4, 10);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(140, GetWidth(root));
  ASSERT_FLOAT_EQ(120, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(15, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(15, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(55, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(55, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(95, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(140, GetWidth(root));
  ASSERT_FLOAT_EQ(120, GetHeight(root));

  ASSERT_FLOAT_EQ(90, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(15, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(15, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(90, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(55, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(55, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(90, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(95, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_STRETCH);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 150);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 50);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(50, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(50, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(50, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(50, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  NodeFreeRecursive(root);
}
//
// TEST(TAITANK_TEST, align_content_stretch_row_with_children) {
//
//
//  const TaitankNodeRef root = NodeCreate();
//  SetFlexDirection(root, FLEX_DIRECTION_ROW);
//  SetAlignContent(root, FLEX_ALIGN_STRETCH);
//  SetFlexWrap(root, FLEX_WRAP);
//  SetWidth(root, 150);
//  SetHeight(root, 100);
//
//  const TaitankNodeRef root_child0 = NodeCreate();
//  SetWidth(root_child0, 50);
//  InsertChild(root, root_child0, 0);
//
//  const TaitankNodeRef root_child0_child0 = NodeCreate();
//  SetFlexGrow(root_child0_child0, 1);
//  SetFlexShrink(root_child0_child0, 1);
//  SetFlexBasis_percent(root_child0_child0, 0);
//  InsertChild(root_child0, root_child0_child0, 0);
//
//  const TaitankNodeRef root_child1 = NodeCreate();
//  SetWidth(root_child1, 50);
//  InsertChild(root, root_child1, 1);
//
//  const TaitankNodeRef root_child2 = NodeCreate();
//  SetWidth(root_child2, 50);
//  InsertChild(root, root_child2, 2);
//
//  const TaitankNodeRef root_child3 = NodeCreate();
//  SetWidth(root_child3, 50);
//  InsertChild(root, root_child3, 3);
//
//  const TaitankNodeRef root_child4 = NodeCreate();
//  SetWidth(root_child4, 50);
//  InsertChild(root, root_child4, 4);
//   DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root));
//  ASSERT_FLOAT_EQ(0, GetTop(root));
//  ASSERT_FLOAT_EQ(150, GetWidth(root));
//  ASSERT_FLOAT_EQ(100, GetHeight(root));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
//  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
//  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
//  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child0_child0));
//  ASSERT_FLOAT_EQ(50, GetHeight(root_child0_child0));
//
//  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
//  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
//  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));
//
//  ASSERT_FLOAT_EQ(100, GetLeft(root_child2));
//  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
//  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
//  ASSERT_FLOAT_EQ(50, GetTop(root_child3));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
//  ASSERT_FLOAT_EQ(50, GetHeight(root_child3));
//
//  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
//  ASSERT_FLOAT_EQ(50, GetTop(root_child4));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
//  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));
//
//  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root));
//  ASSERT_FLOAT_EQ(0, GetTop(root));
//  ASSERT_FLOAT_EQ(150, GetWidth(root));
//  ASSERT_FLOAT_EQ(100, GetHeight(root));
//
//  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
//  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
//  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
//  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child0_child0));
//  ASSERT_FLOAT_EQ(50, GetHeight(root_child0_child0));
//
//  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
//  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
//  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
//  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
//  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));
//
//  ASSERT_FLOAT_EQ(100, GetLeft(root_child3));
//  ASSERT_FLOAT_EQ(50, GetTop(root_child3));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
//  ASSERT_FLOAT_EQ(50, GetHeight(root_child3));
//
//  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
//  ASSERT_FLOAT_EQ(50, GetTop(root_child4));
//  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
//  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));
//
//  NodeFreeRecursive(root);
//
//
//}

TEST(TAITANK_TEST, align_content_stretch_row_with_flex) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_STRETCH);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 150);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetFlexShrink(root_child1, 1);
  //  SetFlexBasis_percent(root_child1, 0);
  SetFlexBasis(root_child1, 0);
  SetWidth(root_child1, 50);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetFlexGrow(root_child3, 1);
  SetFlexShrink(root_child3, 1);
  //  SetFlexBasis_percent(root_child3, 0);
  SetFlexBasis(root_child3, 0);
  SetWidth(root_child3, 50);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  InsertChild(root, root_child4, 4);
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
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, GetTop(root_child3));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, GetTop(root_child3));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_flex_no_shrink) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_STRETCH);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 150);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetFlexShrink(root_child1, 1);
  // SetFlexBasis_percent(root_child1, 0);
  SetFlexBasis(root_child1, 0);
  SetWidth(root_child1, 50);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetFlexGrow(root_child3, 1);
  // SetFlexBasis_percent(root_child3, 0);
  SetFlexBasis(root_child3, 0);
  SetWidth(root_child3, 50);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  InsertChild(root, root_child4, 4);
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
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, GetTop(root_child3));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, GetTop(root_child3));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_margin) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_STRETCH);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 150);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetMargin(root_child1, CSS_LEFT, 10);
  SetMargin(root_child1, CSS_TOP, 10);
  SetMargin(root_child1, CSS_RIGHT, 10);
  SetMargin(root_child1, CSS_BOTTOM, 10);
  SetWidth(root_child1, 50);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetMargin(root_child3, CSS_LEFT, 10);
  SetMargin(root_child3, CSS_TOP, 10);
  SetMargin(root_child3, CSS_RIGHT, 10);
  SetMargin(root_child3, CSS_BOTTOM, 10);
  SetWidth(root_child3, 50);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(60, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(40, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(60, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(50, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(80, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(40, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(50, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(80, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_padding) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_STRETCH);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 150);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetPadding(root_child1, CSS_LEFT, 10);
  SetPadding(root_child1, CSS_TOP, 10);
  SetPadding(root_child1, CSS_RIGHT, 10);
  SetPadding(root_child1, CSS_BOTTOM, 10);
  SetWidth(root_child1, 50);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetPadding(root_child3, CSS_LEFT, 10);
  SetPadding(root_child3, CSS_TOP, 10);
  SetPadding(root_child3, CSS_RIGHT, 10);
  SetPadding(root_child3, CSS_BOTTOM, 10);
  SetWidth(root_child3, 50);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(50, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(50, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(50, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(50, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_single_row) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_STRETCH);
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

TEST(TAITANK_TEST, align_content_stretch_row_with_fixed_height) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_STRETCH);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 150);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  SetHeight(root_child1, 60);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 50);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(60, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(80, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(80, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(60, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(80, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(80, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_max_height) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_STRETCH);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 150);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  SetMaxHeight(root_child1, 20);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 50);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(50, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(50, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(50, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(50, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_min_height) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignContent(root, FLEX_ALIGN_STRETCH);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 150);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  SetMinHeight(root_child1, 80);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetWidth(root_child2, 50);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetWidth(root_child3, 50);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetWidth(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(90, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(90, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(90, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(90, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(150, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(90, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(90, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(90, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(90, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_column) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignContent(root, FLEX_ALIGN_STRETCH);
  SetFlexWrap(root, FLEX_WRAP);
  SetWidth(root, 100);
  SetHeight(root, 150);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetHeight(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0, 1);
  SetFlexShrink(root_child0_child0, 1);
  // SetFlexBasis_percent(root_child0_child0, 0);
  SetFlexBasis(root_child0_child0, 0);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetFlexGrow(root_child1, 1);
  SetFlexShrink(root_child1, 1);
  // SetFlexBasis_percent(root_child1, 0);
  SetFlexBasis(root_child1, 0);
  SetHeight(root_child1, 50);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetHeight(root_child2, 50);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetHeight(root_child3, 50);
  InsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = NodeCreate();
  SetHeight(root_child4, 50);
  InsertChild(root, root_child4, 4);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(150, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(150, GetHeight(root));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, GetTop(root_child4));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child4));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_is_not_overriding_align_items) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignContent(root, FLEX_ALIGN_STRETCH);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexDirection(root_child0, FLEX_DIRECTION_ROW);
  SetAlignContent(root_child0, FLEX_ALIGN_STRETCH);
  SetAlignItems(root_child0, FLEX_ALIGN_CENTER);
  SetWidth(root_child0, 100);
  SetHeight(root_child0, 100);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetAlignContent(root_child0_child0, FLEX_ALIGN_STRETCH);
  SetWidth(root_child0_child0, 10);
  SetHeight(root_child0_child0, 10);
  InsertChild(root_child0, root_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(45, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(90, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(45, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0_child0));

  NodeFreeRecursive(root);
}
