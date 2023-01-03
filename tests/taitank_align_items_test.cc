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

TEST(TAITANK_TEST, align_items_stretch) {
  const TaitankNodeRef root = NodeCreate();
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

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root));
  //  ASSERT_FLOAT_EQ(0, GetTop(root));
  //  ASSERT_FLOAT_EQ(100, GetWidth(root));
  //  ASSERT_FLOAT_EQ(100, GetHeight(root));
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  //  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_center) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_CENTER);
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

  ASSERT_FLOAT_EQ(45, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(45, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_flex_start) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
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

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root));
  //  ASSERT_FLOAT_EQ(0, GetTop(root));
  //  ASSERT_FLOAT_EQ(100, GetWidth(root));
  //  ASSERT_FLOAT_EQ(100, GetHeight(root));
  //
  //  ASSERT_FLOAT_EQ(90, GetLeft(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  //  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_flex_end) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_END);
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

  ASSERT_FLOAT_EQ(90, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root));
  //  ASSERT_FLOAT_EQ(0, GetTop(root));
  //  ASSERT_FLOAT_EQ(100, GetWidth(root));
  //  ASSERT_FLOAT_EQ(100, GetHeight(root));
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  //  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_center_child_with_margin_bigger_than_parent) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetWidth(root, 52);
  SetHeight(root, 52);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetAlignItems(root_child0, FLEX_ALIGN_CENTER);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetMargin(root_child0_child0, CSS_LEFT, 10);
  SetMargin(root_child0_child0, CSS_RIGHT, 10);
  SetWidth(root_child0_child0, 52);
  SetHeight(root_child0_child0, 52);
  InsertChild(root_child0, root_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(52, GetWidth(root));
  ASSERT_FLOAT_EQ(52, GetHeight(root));

  ASSERT_FLOAT_EQ(-10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(72, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(52, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(52, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(52, GetHeight(root_child0_child0));

  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root));
  //  ASSERT_FLOAT_EQ(0, GetTop(root));
  //  ASSERT_FLOAT_EQ(52, GetWidth(root));
  //  ASSERT_FLOAT_EQ(52, GetHeight(root));
  //
  //  ASSERT_FLOAT_EQ(-10, GetLeft(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  //  ASSERT_FLOAT_EQ(72, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(52, GetHeight(root_child0));
  //
  //  ASSERT_FLOAT_EQ(10, GetLeft(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  //  ASSERT_FLOAT_EQ(52, GetWidth(root_child0_child0));
  //  ASSERT_FLOAT_EQ(52, GetHeight(root_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_flex_end_child_with_margin_bigger_than_parent) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetWidth(root, 52);
  SetHeight(root, 52);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetAlignItems(root_child0, FLEX_ALIGN_END);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetMargin(root_child0_child0, CSS_LEFT, 10);
  SetMargin(root_child0_child0, CSS_RIGHT, 10);
  SetWidth(root_child0_child0, 52);
  SetHeight(root_child0_child0, 52);
  InsertChild(root_child0, root_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(52, GetWidth(root));
  ASSERT_FLOAT_EQ(52, GetHeight(root));

  ASSERT_FLOAT_EQ(-10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(72, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(52, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(52, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(52, GetHeight(root_child0_child0));

  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root));
  //  ASSERT_FLOAT_EQ(0, GetTop(root));
  //  ASSERT_FLOAT_EQ(52, GetWidth(root));
  //  ASSERT_FLOAT_EQ(52, GetHeight(root));
  //
  //  ASSERT_FLOAT_EQ(-10, GetLeft(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  //  ASSERT_FLOAT_EQ(72, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(52, GetHeight(root_child0));
  //
  //  ASSERT_FLOAT_EQ(10, GetLeft(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  //  ASSERT_FLOAT_EQ(52, GetWidth(root_child0_child0));
  //  ASSERT_FLOAT_EQ(52, GetHeight(root_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_center_child_without_margin_bigger_than_parent) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetWidth(root, 52);
  SetHeight(root, 52);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetAlignItems(root_child0, FLEX_ALIGN_CENTER);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetWidth(root_child0_child0, 72);
  SetHeight(root_child0_child0, 72);
  InsertChild(root_child0, root_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(52, GetWidth(root));
  ASSERT_FLOAT_EQ(52, GetHeight(root));

  ASSERT_FLOAT_EQ(-10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(-10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(72, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(72, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(72, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(72, GetHeight(root_child0_child0));

  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root));
  //  ASSERT_FLOAT_EQ(0, GetTop(root));
  //  ASSERT_FLOAT_EQ(52, GetWidth(root));
  //  ASSERT_FLOAT_EQ(52, GetHeight(root));
  //
  //  ASSERT_FLOAT_EQ(-10, GetLeft(root_child0));
  //  ASSERT_FLOAT_EQ(-10, GetTop(root_child0));
  //  ASSERT_FLOAT_EQ(72, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(72, GetHeight(root_child0));
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  //  ASSERT_FLOAT_EQ(72, GetWidth(root_child0_child0));
  //  ASSERT_FLOAT_EQ(72, GetHeight(root_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_flex_end_child_without_margin_bigger_than_parent) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetWidth(root, 52);
  SetHeight(root, 52);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetAlignItems(root_child0, FLEX_ALIGN_END);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetWidth(root_child0_child0, 72);
  SetHeight(root_child0_child0, 72);
  InsertChild(root_child0, root_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(52, GetWidth(root));
  ASSERT_FLOAT_EQ(52, GetHeight(root));

  ASSERT_FLOAT_EQ(-10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(-10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(72, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(72, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(72, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(72, GetHeight(root_child0_child0));

  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root));
  //  ASSERT_FLOAT_EQ(0, GetTop(root));
  //  ASSERT_FLOAT_EQ(52, GetWidth(root));
  //  ASSERT_FLOAT_EQ(52, GetHeight(root));
  //
  //  ASSERT_FLOAT_EQ(-10, GetLeft(root_child0));
  //  ASSERT_FLOAT_EQ(-10, GetTop(root_child0));
  //  ASSERT_FLOAT_EQ(72, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(72, GetHeight(root_child0));
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  //  ASSERT_FLOAT_EQ(72, GetWidth(root_child0_child0));
  //  ASSERT_FLOAT_EQ(72, GetHeight(root_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_center_should_size_based_on_content) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetMargin(root, CSS_TOP, 20);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetJustifyContent(root_child0, FLEX_ALIGN_CENTER);
  SetFlexShrink(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0, 1);
  SetFlexShrink(root_child0_child0, 1);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = NodeCreate();
  SetWidth(root_child0_child0_child0, 20);
  SetHeight(root_child0_child0_child0, 20);
  InsertChild(root_child0_child0, root_child0_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(20, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0_child0_child0));

  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root));
  //  ASSERT_FLOAT_EQ(20, GetTop(root));
  //  ASSERT_FLOAT_EQ(100, GetWidth(root));
  //  ASSERT_FLOAT_EQ(100, GetHeight(root));
  //
  //  ASSERT_FLOAT_EQ(40, GetLeft(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  //  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  //  ASSERT_FLOAT_EQ(20, GetWidth(root_child0_child0));
  //  ASSERT_FLOAT_EQ(20, GetHeight(root_child0_child0));
  //
  //  ASSERT_FLOAT_EQ(0,
  //  GetLeft(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  GetTop(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(20,
  //  GetWidth(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(20,
  //  GetHeight(root_child0_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_strech_should_size_based_on_parent) {
  const TaitankNodeRef root = NodeCreate();
  SetMargin(root, CSS_TOP, 20);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetJustifyContent(root_child0, FLEX_ALIGN_CENTER);
  SetFlexShrink(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0, 1);
  SetFlexShrink(root_child0_child0, 1);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = NodeCreate();
  SetWidth(root_child0_child0_child0, 20);
  SetHeight(root_child0_child0_child0, 20);
  InsertChild(root_child0_child0, root_child0_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(20, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0_child0_child0));

  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root));
  //  ASSERT_FLOAT_EQ(20, GetTop(root));
  //  ASSERT_FLOAT_EQ(100, GetWidth(root));
  //  ASSERT_FLOAT_EQ(100, GetHeight(root));
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  //  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  //  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0));
  //  ASSERT_FLOAT_EQ(20, GetHeight(root_child0_child0));
  //
  //  ASSERT_FLOAT_EQ(80,
  //  GetLeft(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  GetTop(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(20,
  //  GetWidth(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(20,
  //  GetHeight(root_child0_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_flex_start_with_shrinking_children) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 500);
  SetHeight(root, 500);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetAlignItems(root_child0, FLEX_ALIGN_START);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0, 1);
  SetFlexShrink(root_child0_child0, 1);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0_child0, 1);
  SetFlexShrink(root_child0_child0_child0, 1);
  InsertChild(root_child0_child0, root_child0_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(500, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(500, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0_child0_child0));

  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root));
  //  ASSERT_FLOAT_EQ(0, GetTop(root));
  //  ASSERT_FLOAT_EQ(500, GetWidth(root));
  //  ASSERT_FLOAT_EQ(500, GetHeight(root));
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  //  ASSERT_FLOAT_EQ(500, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));
  //
  //  ASSERT_FLOAT_EQ(500, GetLeft(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetWidth(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetHeight(root_child0_child0));
  //
  //  ASSERT_FLOAT_EQ(0,
  //  GetLeft(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  GetTop(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  GetWidth(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  GetHeight(root_child0_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_flex_start_with_stretching_children) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 500);
  SetHeight(root, 500);

  const TaitankNodeRef root_child0 = NodeCreate();
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0, 1);
  SetFlexShrink(root_child0_child0, 1);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0_child0, 1);
  SetFlexShrink(root_child0_child0_child0, 1);
  InsertChild(root_child0_child0, root_child0_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(500, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(500, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(500, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(500, GetWidth(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0_child0_child0));

  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root));
  //  ASSERT_FLOAT_EQ(0, GetTop(root));
  //  ASSERT_FLOAT_EQ(500, GetWidth(root));
  //  ASSERT_FLOAT_EQ(500, GetHeight(root));
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  //  ASSERT_FLOAT_EQ(500, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  //  ASSERT_FLOAT_EQ(500, GetWidth(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetHeight(root_child0_child0));
  //
  //  ASSERT_FLOAT_EQ(0,
  //  GetLeft(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  GetTop(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(500,
  //  GetWidth(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  GetHeight(root_child0_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_flex_start_with_shrinking_children_with_stretch) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 500);
  SetHeight(root, 500);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetAlignItems(root_child0, FLEX_ALIGN_START);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0, 1);
  SetFlexShrink(root_child0_child0, 1);
  InsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = NodeCreate();
  SetFlexGrow(root_child0_child0_child0, 1);
  SetFlexShrink(root_child0_child0_child0, 1);
  InsertChild(root_child0_child0, root_child0_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(500, GetWidth(root));
  ASSERT_FLOAT_EQ(500, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(500, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0_child0_child0));

  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root));
  //  ASSERT_FLOAT_EQ(0, GetTop(root));
  //  ASSERT_FLOAT_EQ(500, GetWidth(root));
  //  ASSERT_FLOAT_EQ(500, GetHeight(root));
  //
  //  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  //  ASSERT_FLOAT_EQ(500, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));
  //
  //  ASSERT_FLOAT_EQ(500, GetLeft(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetWidth(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, GetHeight(root_child0_child0));
  //
  //  ASSERT_FLOAT_EQ(0,
  //  GetLeft(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  GetTop(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  GetWidth(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  GetHeight(root_child0_child0_child0));

  NodeFreeRecursive(root);
}
