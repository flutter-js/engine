# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../")
set(SKIA_INCLUDE_DIR "${ROOT_DIR}/third_party/skia/include")

set(
        SRC_LIST
        #layers
        layers/backdrop_filter_layer.cc
        #layers/child_scene_layer.cc
        layers/clip_path_layer.cc
        layers/clip_rect_layer.cc
        layers/clip_rrect_layer.cc
        layers/color_filter_layer.cc
        layers/container_layer.cc
        layers/layer_tree.cc
        layers/layer.cc
        layers/opacity_layer.cc
        layers/performance_overlay_layer.cc
        layers/physical_shape_layer.cc
        layers/picture_layer.cc
        layers/platform_view_layer.cc
        layers/shader_mask_layer.cc
        layers/texture_layer.cc
        layers/transform_layer.cc
        ###
        compositor_context.cc
        debug_print.cc
        embedded_views.cc
        #export_node.cc
        instrumentation.cc
        matrix_decomposition.cc
        paint_utils.cc
        raster_cache_key.cc
        raster_cache.cc
        #scene_update_context.cc
        skia_gpu_object.cc
        texture.cc
)

include_directories(${ROOT_DIR})
#include_directories(${SKIA_INCLUDE_DIR})
include_directories(${SKIA_INCLUDE_DIR}/config)
include_directories(${SKIA_INCLUDE_DIR}/animator)
include_directories(${SKIA_INCLUDE_DIR}/c)
include_directories(${SKIA_INCLUDE_DIR}/codec)
include_directories(${SKIA_INCLUDE_DIR}/core)
include_directories(${SKIA_INCLUDE_DIR}/effects)
include_directories(${SKIA_INCLUDE_DIR}/gpu)
include_directories(${SKIA_INCLUDE_DIR}/images)
include_directories(${SKIA_INCLUDE_DIR}/pathops)
include_directories(${SKIA_INCLUDE_DIR}/pipe)
include_directories(${SKIA_INCLUDE_DIR}/ports)
include_directories(${SKIA_INCLUDE_DIR}/utils)

add_library( # Sets the name of the library.
        flow

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        ${SRC_LIST} )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )

