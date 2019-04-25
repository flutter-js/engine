# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.


set(
        SRC_LIST
        unique_fd.cc
        thread_local.cc
        thread.cc
        task_runner.cc
        string_view.cc
        paths.cc
        message_loop_impl.cc
        message_loop.cc
        message.cc
        mapping.cc
        logging.cc
        log_settings_state.cc
        log_settings.cc
        file.cc
        command_line.cc
        base32.cc
        memory/weak_ptr_internal.cc
        synchronization/count_down_latch.cc
        synchronization/shared_mutex_std.cc
        synchronization/waitable_event.cc
        time/time_point.cc
        platform/android/jni_util.cc
        platform/android/jni_weak_ref.cc
        platform/android/message_loop_android.cc
        platform/android/paths_android.cc
        platform/android/scoped_java_ref.cc
        platform/linux/timerfd.cc
        platform/posix/file_posix.cc
        platform/posix/mapping_posix.cc
        trace_event.cc
)

include_directories(${ROOT_DIR})

add_library( # Sets the name of the library.
        fml

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

