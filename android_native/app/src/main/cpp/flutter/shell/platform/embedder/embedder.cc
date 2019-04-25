// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


#include "flutter/shell/platform/embedder/embedder.h"

FlutterResult FlutterEngineRun(size_t version,
                               const void* config,
                               const void* args,
                               void* user_data,
                               FlutterEngine* engine_out){
  // Step 0: Figure out arguments for shell creation.
  if (version != FLUTTER_ENGINE_VERSION) {
    return kInvalidLibraryVersion;
  }

  if (engine_out == nullptr) {
    return kInvalidArguments;
  }

  // TODO:

  return kSuccess;
}

FlutterResult FlutterEngineShutdown(FlutterEngine engine) {
  if (engine == nullptr) {
    return kInvalidArguments;
  }

  // TODO:

  return kSuccess;
}