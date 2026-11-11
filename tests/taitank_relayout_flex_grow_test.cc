/*
 *
 * Tencent is pleased to support the open source community by making Taitank available.
 * Copyright (C) 2021 THL A29 Limited, a Tencent company.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http:// www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed in writing, software
 * distributed under the License is distributed on an “AS IS” BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and limitations
 * under the License.
 *
 */

#include "gtest/gtest.h"
#include "taitank.h"

using namespace taitank;

class TAITANK_TEST_RELAYOUT : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
};

// 容器尺寸变化触发重新布局时，弹性子节点必须重新参与弹性分配。
// 旧实现在第二次 LAYOUT 直接命中 layout cache 返回，跳过了子节点重排，
// 于是 width 停留在 measure 阶段的中间结果 0。
// see https://github.com/Tencent/Taitank/issues/23
TEST_F(TAITANK_TEST_RELAYOUT, flex_grow_child_keeps_width_after_relayout) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 640);
  SetHeight(root, 480);

  const TaitankNodeRef parent = NodeCreate();
  SetFlexDirection(parent, FLEX_DIRECTION_ROW);
  InsertChild(root, parent, 0);

  const TaitankNodeRef child1 = NodeCreate();
  SetHeight(child1, 20);
  SetFlexGrow(child1, 1);
  InsertChild(parent, child1, 0);

  const TaitankNodeRef child2 = NodeCreate();
  SetWidth(child2, 50);
  SetHeight(child2, 20);
  InsertChild(parent, child2, 1);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  const float w1 = GetWidth(child1);

  SetHeight(root, 490);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  const float w2 = GetWidth(child1);

  // 容器高度变化不影响 row 方向的主轴尺寸
  EXPECT_FLOAT_EQ(w1, w2);
  EXPECT_FLOAT_EQ(590.0f, w1);
  EXPECT_FLOAT_EQ(590.0f, w2);

  NodeFreeRecursive(root);
}
