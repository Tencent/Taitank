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

static TaitankSize _measureFloor(TaitankNodeRef node, float width, MeasureMode widthMeasureMode,
                                 float height, MeasureMode heightMeasureMode, void *layoutContext) {
  return TaitankSize{
      width = 10.2f,
      height = 10.2f,
  };
}

static TaitankSize _measureCeil(TaitankNodeRef node, float width, MeasureMode widthMode,
                                float height, MeasureMode heightMode, void *layoutContext) {
  return TaitankSize{
      width = 10.5f,
      height = 10.5f,
  };
}

static TaitankSize _measureFractial(TaitankNodeRef node, float width, MeasureMode widthMode,
                                    float height, MeasureMode heightMode, void *layoutContext) {
  return TaitankSize{
      width = 0.5f,
      height = 0.5f,
  };
}

TEST(TAITANK_TEST, rounding_feature_with_custom_measure_func_floor) {
  const TaitankNodeRef root = NodeCreate();

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMeasureFunction(root_child0, _measureFloor);
  //  root_child0->setMeasureFunc(_measureFloor);
  InsertChild(root, root_child0, 0);

  //  YGConfigSetPointScaleFactor(config, 0.0f);
  //
  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(10.2, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(10.2, GetHeight(root_child0));

  //  YGConfigSetPointScaleFactor(config, 1.0f);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(11, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(11, GetHeight(root_child0));

  //  YGConfigSetPointScaleFactor(config, 2.0f);
  //
  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(10.5, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(10.5, GetHeight(root_child0));
  //
  //  YGConfigSetPointScaleFactor(config, 4.0f);
  //
  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  //
  //  ASSERT_FLOAT_EQ(10.25, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(10.25, GetHeight(root_child0));
  //
  //  YGConfigSetPointScaleFactor(config, 1.0f / 3.0f);
  //
  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(12.0, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(12.0, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_feature_with_custom_measure_func_ceil) {
  const TaitankNodeRef root = NodeCreate();

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMeasureFunction(root_child0, _measureCeil);
  //  root_child0->setMeasureFunc(_measureCeil);
  InsertChild(root, root_child0, 0);

  //  YGConfigSetPointScaleFactor(config, 1.0f);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(11, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(11, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, rounding_feature_with_custom_measure_and_fractial_matching_scale) {
  const TaitankNodeRef root = NodeCreate();

  //  const TaitankNodeRef root_child0 = NodeCreate();
  //  SetPosition(root_child0, CSS_LEFT, 73.625);
  //  root_child0->setMeasureFunc(_measureFractial);
  //  InsertChild(root, root_child0, 0);
  //
  //  YGConfigSetPointScaleFactor(config, 2.0f);
  //
  //  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  //
  //  ASSERT_FLOAT_EQ(0.5, GetWidth(root_child0));
  //  ASSERT_FLOAT_EQ(0.5, GetHeight(root_child0));
  //  ASSERT_FLOAT_EQ(73.5, GetLeft(root_child0));

  NodeFreeRecursive(root);
}
