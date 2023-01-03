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
using namespace ::testing;

class TAITANK_TEST_HAD_OVERFLOW : public Test {
 protected:
  TAITANK_TEST_HAD_OVERFLOW() {
    root = NodeCreate();
    SetWidth(root, 200);
    SetHeight(root, 100);
    SetFlexDirection(root, FLEX_DIRECTION_COLUMN);
    SetFlexWrap(root, FLEX_NO_WRAP);
  }

  ~TAITANK_TEST_HAD_OVERFLOW() { NodeFreeRecursive(root); }

  TaitankNodeRef root;
};

TEST_F(TAITANK_TEST_HAD_OVERFLOW, children_overflow_no_wrap_and_no_flex_children) {
  const TaitankNodeRef child0 = NodeCreate();
  SetWidth(child0, 80);
  SetHeight(child0, 40);
  SetMargin(child0, CSS_TOP, 10);
  SetMargin(child0, CSS_BOTTOM, 15);
  InsertChild(root, child0, 0);
  const TaitankNodeRef child1 = NodeCreate();
  SetWidth(child1, 80);
  SetHeight(child1, 40);
  SetMargin(child1, CSS_BOTTOM, 5);
  InsertChild(root, child1, 1);

  DoLayout(root, 200, 100);

  ASSERT_TRUE(GetHadOverflow(root));
}

TEST_F(TAITANK_TEST_HAD_OVERFLOW, spacing_overflow_no_wrap_and_no_flex_children) {
  const TaitankNodeRef child0 = NodeCreate();
  SetWidth(child0, 80);
  SetHeight(child0, 40);
  SetMargin(child0, CSS_TOP, 10);
  SetMargin(child0, CSS_BOTTOM, 10);
  InsertChild(root, child0, 0);
  const TaitankNodeRef child1 = NodeCreate();
  SetWidth(child1, 80);
  SetHeight(child1, 40);
  SetMargin(child1, CSS_BOTTOM, 5);
  InsertChild(root, child1, 1);

  DoLayout(root, 200, 100);

  ASSERT_TRUE(GetHadOverflow(root));
}

TEST_F(TAITANK_TEST_HAD_OVERFLOW, no_overflow_no_wrap_and_flex_children) {
  const TaitankNodeRef child0 = NodeCreate();
  SetWidth(child0, 80);
  SetHeight(child0, 40);
  SetMargin(child0, CSS_TOP, 10);
  SetMargin(child0, CSS_BOTTOM, 10);
  InsertChild(root, child0, 0);
  const TaitankNodeRef child1 = NodeCreate();
  SetWidth(child1, 80);
  SetHeight(child1, 40);
  SetMargin(child1, CSS_BOTTOM, 5);
  SetFlexShrink(child1, 1);
  InsertChild(root, child1, 1);

  DoLayout(root, 200, 100);

  ASSERT_FALSE(GetHadOverflow(root));
}

TEST_F(TAITANK_TEST_HAD_OVERFLOW, hadOverflow_gets_reset_if_not_logger_valid) {
  const TaitankNodeRef child0 = NodeCreate();
  SetWidth(child0, 80);
  SetHeight(child0, 40);
  SetMargin(child0, CSS_TOP, 10);
  SetMargin(child0, CSS_BOTTOM, 10);
  InsertChild(root, child0, 0);
  const TaitankNodeRef child1 = NodeCreate();
  SetWidth(child1, 80);
  SetHeight(child1, 40);
  SetMargin(child1, CSS_BOTTOM, 5);
  InsertChild(root, child1, 1);

  DoLayout(root, 200, 100);

  ASSERT_TRUE(GetHadOverflow(root));

  SetFlexShrink(child1, 1);

  DoLayout(root, 200, 100);
  ASSERT_FALSE(GetHadOverflow(root));
}

TEST_F(TAITANK_TEST_HAD_OVERFLOW, spacing_overflow_in_nested_nodes) {
  const TaitankNodeRef child0 = NodeCreate();
  SetWidth(child0, 80);
  SetHeight(child0, 40);
  SetMargin(child0, CSS_TOP, 10);
  SetMargin(child0, CSS_BOTTOM, 10);
  InsertChild(root, child0, 0);
  const TaitankNodeRef child1 = NodeCreate();
  SetWidth(child1, 80);
  SetHeight(child1, 40);
  InsertChild(root, child1, 1);
  const TaitankNodeRef child1_1 = NodeCreate();
  SetWidth(child1_1, 80);
  SetHeight(child1_1, 40);
  SetMargin(child1_1, CSS_BOTTOM, 5);
  InsertChild(child1, child1_1, 0);

  DoLayout(root, 200, 100);

  ASSERT_TRUE(GetHadOverflow(root));
}
