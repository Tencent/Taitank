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

TEST(TAITANK_TEST, reset_layout_when_child_removed) {
  const TaitankNodeRef root = NodeCreate();

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 100);
  SetHeight(root_child0, 100);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(0, GetLeft(root_child0));
  ASSERT_EQ(0, GetTop(root_child0));
  ASSERT_EQ(100, GetWidth(root_child0));
  ASSERT_EQ(100, GetHeight(root_child0));

  RemoveChild(root, root_child0);

  ASSERT_EQ(0, GetLeft(root_child0));
  ASSERT_EQ(0, GetTop(root_child0));
  ASSERT_TRUE(isUndefined(GetWidth(root_child0)));
  ASSERT_TRUE(isUndefined(GetHeight(root_child0)));

  NodeFreeRecursive(root);
}
