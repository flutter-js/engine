// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/flow/layers/platform_view_layer.h"

namespace flow {

PlatformViewLayer::PlatformViewLayer() = default;

PlatformViewLayer::~PlatformViewLayer() = default;

void PlatformViewLayer::Preroll(PrerollContext* context,
                                const SkMatrix& matrix) {
  set_paint_bounds(SkRect::MakeXYWH(offset_.x(), offset_.y(), size_.width(),
                                    size_.height()));

  if (context->view_embedder == nullptr) {
    FML_LOG(ERROR) << "Trying to embed a platform view but the PrerollContext "
                      "does not support embedding";
    return;
  }
  context->view_embedder->PrerollCompositeEmbeddedView(view_id_);
}

void PlatformViewLayer::Paint(PaintContext& context) const {
  if (context.view_embedder == nullptr) {
    FML_LOG(ERROR) << "Trying to embed a platform view but the PaintContext "
                      "does not support embedding";
    return;
  }
  EmbeddedViewParams params;
  SkMatrix transform = context.leaf_nodes_canvas->getTotalMatrix();
  params.offsetPixels =
      SkPoint::Make(transform.getTranslateX(), transform.getTranslateY());
  params.sizePoints = size_;

  SkCanvas* canvas =
      context.view_embedder->CompositeEmbeddedView(view_id_, params);
  context.leaf_nodes_canvas = canvas;
}
}  // namespace flow
