// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_LIB_UI_SEMANTICS_SEMANTICS_NODE_H_
#define FLUTTER_LIB_UI_SEMANTICS_SEMANTICS_NODE_H_

#include <stdint.h>

#include <string>
#include <unordered_map>
#include <vector>

#include "third_party/skia/include/core/SkMatrix44.h"
#include "third_party/skia/include/core/SkRect.h"

namespace blink {

// Must match the SemanticsAction enum in semantics.dart.
enum class SemanticsAction : int32_t {
  kTap = 1 << 0,
  kLongPress = 1 << 1,
  kScrollLeft = 1 << 2,
  kScrollRight = 1 << 3,
  kScrollUp = 1 << 4,
  kScrollDown = 1 << 5,
  kIncrease = 1 << 6,
  kDecrease = 1 << 7,
  kShowOnScreen = 1 << 8,
  kMoveCursorForwardByCharacter = 1 << 9,
  kMoveCursorBackwardByCharacter = 1 << 10,
  kSetSelection = 1 << 11,
  kCopy = 1 << 12,
  kCut = 1 << 13,
  kPaste = 1 << 14,
  kDidGainAccessibilityFocus = 1 << 15,
  kDidLoseAccessibilityFocus = 1 << 16,
  kCustomAction = 1 << 17,
  kDismiss = 1 << 18,
};

const int kScrollableSemanticsActions =
    static_cast<int32_t>(SemanticsAction::kScrollLeft) |
    static_cast<int32_t>(SemanticsAction::kScrollRight) |
    static_cast<int32_t>(SemanticsAction::kScrollUp) |
    static_cast<int32_t>(SemanticsAction::kScrollDown);

// Must match the SemanticsFlags enum in semantics.dart.
enum class SemanticsFlags : int32_t {
  kHasCheckedState = 1 << 0,
  kIsChecked = 1 << 1,
  kIsSelected = 1 << 2,
  kIsButton = 1 << 3,
  kIsTextField = 1 << 4,
  kIsFocused = 1 << 5,
  kHasEnabledState = 1 << 6,
  kIsEnabled = 1 << 7,
  kIsInMutuallyExclusiveGroup = 1 << 8,
  kIsHeader = 1 << 9,
  kIsObscured = 1 << 10,
  kScopesRoute = 1 << 11,
  kNamesRoute = 1 << 12,
  kIsHidden = 1 << 13,
  kIsImage = 1 << 14,
  kIsLiveRegion = 1 << 15,
  kHasToggledState = 1 << 16,
  kIsToggled = 1 << 17,
};

struct SemanticsNode {
  SemanticsNode();

  SemanticsNode(const SemanticsNode& other);

  ~SemanticsNode();

  bool HasAction(SemanticsAction action);
  bool HasFlag(SemanticsFlags flag);

  int32_t id = 0;
  int32_t flags = 0;
  int32_t actions = 0;
  int32_t textSelectionBase = -1;
  int32_t textSelectionExtent = -1;
  int32_t scrollChildren = 0;
  int32_t scrollIndex = 0;
  double scrollPosition = std::nan("");
  double scrollExtentMax = std::nan("");
  double scrollExtentMin = std::nan("");
  std::string label;
  std::string hint;
  std::string value;
  std::string increasedValue;
  std::string decreasedValue;
  int32_t textDirection = 0;  // 0=unknown, 1=rtl, 2=ltr

  SkRect rect = SkRect::MakeEmpty();
  SkMatrix44 transform = SkMatrix44(SkMatrix44::kIdentity_Constructor);
  std::vector<int32_t> childrenInTraversalOrder;
  std::vector<int32_t> childrenInHitTestOrder;
  std::vector<int32_t> customAccessibilityActions;
};

// Contains semantic nodes that need to be updated.
//
// The keys in the map are stable node IDd, and the values contain
// semantic information for the node corresponding to the ID.
using SemanticsNodeUpdates = std::unordered_map<int32_t, SemanticsNode>;

}  // namespace blink

#endif  // FLUTTER_LIB_UI_SEMANTICS_SEMANTICS_NODE_H_
