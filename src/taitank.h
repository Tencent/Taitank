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

#pragma once

#include "taitank_node.h"
#include "taitank_config.h"

namespace taitank {

TaitankNodeRef NodeCreate();
TaitankNodeRef NodeCreateWithConfig(TaitankConfigRef config);
void NodeFree(TaitankNodeRef node);
void NodeFreeRecursive(TaitankNodeRef node);

bool SetMeasureFunction(TaitankNodeRef node, TaitankMeasureFunction measure_function);
void SetDirection(TaitankNodeRef node, TaitankDirection direction);
void SetWidth(TaitankNodeRef node, float width);
void SetHeight(TaitankNodeRef node, float height);
void SetFlex(TaitankNodeRef node, float flex);
void SetFlexGrow(TaitankNodeRef node, float flex_grow);
void SetFlexShrink(TaitankNodeRef node, float flex_shrink);
void SetFlexBasis(TaitankNodeRef node, float flex_basis);
void SetFlexDirection(TaitankNodeRef node, FlexDirection direction);
void SetPositionType(TaitankNodeRef node, PositionType position_type);
void SetPosition(TaitankNodeRef node, CSSDirection dir, float value);
void SetMargin(TaitankNodeRef node, CSSDirection dir, float value);
void SetMarginAuto(TaitankNodeRef node, CSSDirection dir);
void SetPadding(TaitankNodeRef node, CSSDirection dir, float value);
void SetBorder(TaitankNodeRef node, CSSDirection dir, float value);

void SetFlexWrap(TaitankNodeRef node, FlexWrapMode wrap_mode);
void SetJustifyContent(TaitankNodeRef node, FlexAlign justify);
void SetAlignContent(TaitankNodeRef node, FlexAlign align);
void SetAlignItems(TaitankNodeRef node, FlexAlign align);
void SetAlignSelf(TaitankNodeRef node, FlexAlign align);
void SetDisplay(TaitankNodeRef node, DisplayType display_type);
void SetMaxWidth(TaitankNodeRef node, float value);
void SetMaxHeight(TaitankNodeRef node, float value);
void SetMinWidth(TaitankNodeRef node, float value);
void SetMinHeight(TaitankNodeRef node, float value);
void SetOverflow(TaitankNodeRef node, OverflowType overflow_type);
void SetNodeType(TaitankNodeRef node, NodeType nodeType);

float GetLeft(TaitankNodeRef node);
float GetTop(TaitankNodeRef node);
float GetRight(TaitankNodeRef node);
float GetBottom(TaitankNodeRef node);
float GetWidth(TaitankNodeRef node);
float GetHeight(TaitankNodeRef node);
float GetMaxWidth(TaitankNodeRef node);
float GetMaxHeight(TaitankNodeRef node);
float GetMinWidth(TaitankNodeRef node);
float GetMinHeight(TaitankNodeRef node);
float GetMargin(TaitankNodeRef node, CSSDirection dir);
float GetPadding(TaitankNodeRef node, CSSDirection dir);
float GetBorder(TaitankNodeRef node, CSSDirection dir);
float GetFlexGrow(TaitankNodeRef node);
float GetFlexShrink(TaitankNodeRef node);
DisplayType GetDisplay(TaitankNodeRef node);
float GetFlexBasis(TaitankNodeRef node);
FlexDirection GetFlexDirection(TaitankNodeRef node);
FlexAlign GetJustifyContent(TaitankNodeRef node);
FlexAlign GetAlignSelf(TaitankNodeRef node);
FlexAlign GetAlignItems(TaitankNodeRef node);
PositionType GetPositionType(TaitankNodeRef node);
FlexWrapMode GetFlexWrap(TaitankNodeRef node);
OverflowType GetOverflow(TaitankNodeRef node);
bool GetHadOverflow(TaitankNodeRef node);

void SetConfig(TaitankNodeRef node, TaitankConfigRef config);
void ConfigFree(TaitankConfigRef);
TaitankConfigRef ConfigGetDefault();

void SetContext(TaitankNodeRef node, void *context);
void *GetContext(TaitankNodeRef node);

bool InsertChild(TaitankNodeRef node, TaitankNodeRef child, uint32_t index);
bool RemoveChild(TaitankNodeRef node, TaitankNodeRef child);
uint32_t ChildCount(TaitankNodeRef node);
TaitankNodeRef GetChild(TaitankNodeRef node, uint32_t index);
bool GetHasNewLayout(TaitankNodeRef node);
void SetHasNewLayout(TaitankNodeRef node, bool has_new_layout);

void MarkDirty(TaitankNodeRef node);
bool IsDirty(TaitankNodeRef node);
void DoLayout(TaitankNodeRef node, float parent_width, float parent_height,
                         TaitankDirection direction = DIRECTION_LTR,
                         void* layout_context = nullptr);
void Print(TaitankNodeRef node);
bool Reset(TaitankNodeRef node);
}  // namespace taitank
