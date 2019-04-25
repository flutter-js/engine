# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(FLUTTRT_DIR "${ROOT_DIR}/flutter")
set(SKIA_INCLUDE_DIR "${ROOT_DIR}/third_party/skia/include")
add_subdirectory(${ROOT_DIR}/flutter/fml fml)
add_subdirectory(${ROOT_DIR}/flutter/flow flow)
add_subdirectory(${ROOT_DIR}/flutter/assets assets)
add_subdirectory(${ROOT_DIR}/flutter/synchronization synchronization)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# build native_app_glue as a static lib
set(${CMAKE_C_FLAGS}, "${CMAKE_C_FLAGS}")
add_library(native_app_glue STATIC
        ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

# Export ANativeActivity_onCreate(),
# Refer to: https://github.com/android-ndk/ndk/issues/381.
set(CMAKE_SHARED_LINKER_FLAGS
        "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

add_library( # Sets the name of the library.
        flutterjs

        # Sets the library as a shared library.
        SHARED

        # n-api source
        ${ROOT_DIR}/libnode/include/napi/src/node_api.cc
        ${ROOT_DIR}/libnode/include/napi/src/node_internals.cc

        #flutter-dir

        #common
        ${FLUTTRT_DIR}/common/settings.cc
        ${FLUTTRT_DIR}/common/task_runners.cc

        #lib-ui
        #${FLUTTRT_DIR}/lib/ui/semantics/custom_accessibility_action.cc
        #${FLUTTRT_DIR}/lib/ui/semantics/semantics_node.cc
        #${FLUTTRT_DIR}/lib/ui/semantics/semantics_update.cc
        #${FLUTTRT_DIR}/lib/ui/semantics/semantics_update_builder.cc

        ${FLUTTRT_DIR}/lib/ui/window/platform_message.cc
        ${FLUTTRT_DIR}/lib/ui/window/platform_message_response.cc
        ${FLUTTRT_DIR}/lib/ui/window/pointer_data.cc
        ${FLUTTRT_DIR}/lib/ui/window/pointer_data_packet.cc
        ${FLUTTRT_DIR}/lib/ui/window/viewport_metrics.cc

        #runtime
        ${FLUTTRT_DIR}/runtime/javascript_runtime.cc
        ${FLUTTRT_DIR}/runtime/runtime_controller.cc
        ${FLUTTRT_DIR}/runtime/runtime_delegate.cc
        ${FLUTTRT_DIR}/runtime/service_protocol.cc
        ${FLUTTRT_DIR}/runtime/start_up.cc

        #shell
        ${FLUTTRT_DIR}/shell/common/animator.cc
        ${FLUTTRT_DIR}/shell/common/engine.cc
        ${FLUTTRT_DIR}/shell/common/io_manager.cc
        ${FLUTTRT_DIR}/shell/common/isolate_configuration.cc
        ${FLUTTRT_DIR}/shell/common/persistent_cache.cc
        ${FLUTTRT_DIR}/shell/common/platform_view.cc
        ${FLUTTRT_DIR}/shell/common/rasterizer.cc
        ${FLUTTRT_DIR}/shell/common/run_configuration.cc
        ${FLUTTRT_DIR}/shell/common/shell.cc
        ${FLUTTRT_DIR}/shell/common/skia_event_tracer_impl.cc
        ${FLUTTRT_DIR}/shell/common/surface.cc
        ${FLUTTRT_DIR}/shell/common/switches.cc
        ${FLUTTRT_DIR}/shell/common/thread_host.cc
        ${FLUTTRT_DIR}/shell/common/vsync_waiter.cc
        ${FLUTTRT_DIR}/shell/common/vsync_waiter_fallback.cc

        ${FLUTTRT_DIR}/shell/platform/embedder/embedder.cc

        # Provides a relative path to your source file(s).
        main.cpp)

target_include_directories(flutterjs PRIVATE
        ${ANDROID_NDK}/sources/android/native_app_glue)

include_directories(${ROOT_DIR})
include_directories(${ROOT_DIR}/third_party/rapidjson/include)

include_directories(${ROOT_DIR}/libnode/include/node)
include_directories(${ROOT_DIR}/libnode/include/v8)
include_directories(${ROOT_DIR}/libnode/include/uv)
include_directories(${ROOT_DIR}/libnode/include/napi)

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


find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

add_library(skia SHARED IMPORTED)
set_target_properties(skia
        PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libskia.so)

add_library(mmv8 SHARED IMPORTED)
set_target_properties(mmv8
        PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libmmv8.so)

add_library(node SHARED IMPORTED)
set_target_properties(node
        PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libnode.so)

target_link_libraries( # Specifies the target library.
        flutterjs
        -Wl,--start-group
        android
        native_app_glue
        EGL
        GLESv2
        skia
        mmv8
        node
        fml
        flow
        assets
        synchronization
        -Wl,--end-group
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib} )