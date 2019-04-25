// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/runtime/javascript_runtime.h"

extern "C" void mmv8_init();

namespace blink {

static JavaScriptRuntime* s_JSRuntime = nullptr;

JavaScriptRuntime* JavaScriptRuntime::Current(){
  if(s_JSRuntime == nullptr){
    s_JSRuntime = new JavaScriptRuntime();
  }
  return s_JSRuntime;
}

JavaScriptRuntime::JavaScriptRuntime() = default;

JavaScriptRuntime::~JavaScriptRuntime() = default;

void JavaScriptRuntime::InitJSRuntime(std::string script_file_path)
{
  mmv8_init();
}

void JavaScriptRuntime::TearJSRuntime()
{

}

void JavaScriptRuntime::SetUILibraryWindow()
{

}

void* JavaScriptRuntime::GetUILibraryWindow()
{
  return nullptr;
}

}  // namespace blink