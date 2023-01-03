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

TEST(TAITANK_TEST, zero_out_layout) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 200);
  SetHeight(root, 200);

  const TaitankNodeRef child = NodeCreate();
  InsertChild(root, child, 0);
  SetWidth(child, 100);
  SetHeight(child, 100);
  SetMargin(child, CSS_TOP, 10);
  SetPadding(child, CSS_TOP, 10);

  DoLayout(root, 100, 100);

  ASSERT_FLOAT_EQ(10, GetMargin(child, CSS_TOP));
  ASSERT_FLOAT_EQ(10, GetPadding(child, CSS_TOP));

  SetDisplay(child, DISPLAY_TYPE_NONE);

  DoLayout(root, 100, 100);

  ASSERT_FLOAT_EQ(0, GetMargin(child, CSS_TOP));
  ASSERT_FLOAT_EQ(0, GetPadding(child, CSS_TOP));

  NodeFreeRecursive(root);
}
