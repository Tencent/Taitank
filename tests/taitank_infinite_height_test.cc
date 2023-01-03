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

// This test isn't correct from the Flexbox standard standpoint,
// because percentages are calculated with parent constraints.
// However, we need to make sure we fail gracefully in this case, not returning NaN
TEST(TAITANK_TEST, percent_absolute_position_infinite_height) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 300);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 300);
  SetHeight(root_child0, 300);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetPositionType(root_child1, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child1, CSS_LEFT, 60);
  SetPosition(root_child1, CSS_TOP, 0);
  SetWidth(root_child1, 60);
  //  SetHeight(root_child1, 0);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(300, GetWidth(root));
  ASSERT_FLOAT_EQ(300, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(300, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(300, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(60, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child1));

  NodeFreeRecursive(root);
}
