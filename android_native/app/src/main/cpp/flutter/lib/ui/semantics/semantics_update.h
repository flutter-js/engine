// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_LIB_UI_SEMANTICS_SEMANTICS_UPDATE_H_
#define FLUTTER_LIB_UI_SEMANTICS_SEMANTICS_UPDATE_H_

#include "flutter/lib/ui/dart_wrapper.h"
#include "flutter/lib/ui/semantics/custom_accessibility_action.h"
#include "flutter/lib/ui/semantics/semantics_node.h"

namespace tonic {
class DartLibraryNatives;
}  // namespace tonic

namespace blink {

class SemanticsUpdate : public RefCountedDartWrappable<SemanticsUpdate> {
  DEFINE_WRAPPERTYPEINFO();
  FML_FRIEND_MAKE_REF_COUNTED(SemanticsUpdate);

 public:
  ~SemanticsUpdate() override;
  static fml::RefPtr<SemanticsUpdate> create(
      SemanticsNodeUpdates nodes,
      CustomAccessibilityActionUpdates actions);

  SemanticsNodeUpdates takeNodes();

  CustomAccessibilityActionUpdates takeActions();

  void dispose();

  static void RegisterNatives(tonic::DartLibraryNatives* natives);

 private:
  explicit SemanticsUpdate(SemanticsNodeUpdates nodes,
                           CustomAccessibilityActionUpdates updates);

  SemanticsNodeUpdates nodes_;
  CustomAccessibilityActionUpdates actions_;
};

}  // namespace blink

#endif  // FLUTTER_LIB_UI_SEMANTICS_SEMANTICS_UPDATE_H_
