// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_COMMON_ISOLATE_CONFIGURATION_H_
#define FLUTTER_SHELL_COMMON_ISOLATE_CONFIGURATION_H_

#include <future>
#include <memory>
#include <string>

#include "flutter/assets/asset_manager.h"
#include "flutter/assets/asset_resolver.h"
#include "flutter/common/settings.h"
#include "flutter/fml/macros.h"
#include "flutter/fml/mapping.h"
#include "flutter/fml/memory/weak_ptr.h"
//#include "flutter/runtime/dart_isolate.h"

namespace shell {

class IsolateConfiguration {
 public:

  IsolateConfiguration();

  virtual ~IsolateConfiguration();

 private:
  FML_DISALLOW_COPY_AND_ASSIGN(IsolateConfiguration);
};

}  // namespace shell

#endif  // FLUTTER_SHELL_COMMON_ISOLATE_CONFIGURATION_H_
