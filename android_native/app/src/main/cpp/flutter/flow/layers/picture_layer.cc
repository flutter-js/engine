// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/flow/layers/picture_layer.h"

#include "flutter/fml/logging.h"

namespace flow {

PictureLayer::PictureLayer() = default;

PictureLayer::~PictureLayer() = default;

void PictureLayer::Preroll(PrerollContext* context, const SkMatrix& matrix) {
  SkPicture* sk_picture = picture();

  if (auto* cache = context->raster_cache) {
    SkMatrix ctm = matrix;
    ctm.postTranslate(offset_.x(), offset_.y());
#ifndef SUPPORT_FRACTIONAL_TRANSLATION
    ctm = RasterCache::GetIntegralTransCTM(ctm);
#endif
    cache->Prepare(context->gr_context, sk_picture, ctm,
                   context->dst_color_space, is_complex_, will_change_);
  }

  SkRect bounds = sk_picture->cullRect().makeOffset(offset_.x(), offset_.y());
  set_paint_bounds(bounds);
}

void PictureLayer::Paint(PaintContext& context) const {
  TRACE_EVENT0("flutter", "PictureLayer::Paint");
  FML_DCHECK(picture_.get());
  FML_DCHECK(needs_painting());

  SkAutoCanvasRestore save(context.leaf_nodes_canvas, true);
  context.leaf_nodes_canvas->translate(offset_.x(), offset_.y());
#ifndef SUPPORT_FRACTIONAL_TRANSLATION
  context.leaf_nodes_canvas->setMatrix(RasterCache::GetIntegralTransCTM(
      context.leaf_nodes_canvas->getTotalMatrix()));
#endif

  if (context.raster_cache) {
    const SkMatrix& ctm = context.leaf_nodes_canvas->getTotalMatrix();
    RasterCacheResult result = context.raster_cache->Get(*picture(), ctm);
    if (result.is_valid()) {
      result.draw(*context.leaf_nodes_canvas);
      return;
    }
  }
  context.leaf_nodes_canvas->drawPicture(picture());
}

}  // namespace flow
