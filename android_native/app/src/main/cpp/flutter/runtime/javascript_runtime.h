// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_RUNTIME_JAVASCRIPT_RUNTIME_H_
#define FLUTTER_RUNTIME_JAVASCRIPT_RUNTIME_H_

#include <string>
#include "flutter/common/settings.h"

namespace blink {

class JavaScriptRuntime {
public:
  static JavaScriptRuntime* Current();
  
  JavaScriptRuntime();
  ~JavaScriptRuntime();

  void InitJSRuntime(std::string script_file_path);
  void TearJSRuntime();

  void SetUILibraryWindow();
  void* GetUILibraryWindow();

};


}

#endif