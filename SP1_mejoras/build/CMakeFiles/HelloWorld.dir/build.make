# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pablini27/Documents/SP1_mejoras

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pablini27/Documents/SP1_mejoras/build

# Include any dependencies generated for this target.
include CMakeFiles/HelloWorld.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HelloWorld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HelloWorld.dir/flags.make

CMakeFiles/HelloWorld.dir/src/main.cpp.o: CMakeFiles/HelloWorld.dir/flags.make
CMakeFiles/HelloWorld.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pablini27/Documents/SP1_mejoras/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/HelloWorld.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/HelloWorld.dir/src/main.cpp.o -c /home/pablini27/Documents/SP1_mejoras/src/main.cpp

CMakeFiles/HelloWorld.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloWorld.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pablini27/Documents/SP1_mejoras/src/main.cpp > CMakeFiles/HelloWorld.dir/src/main.cpp.i

CMakeFiles/HelloWorld.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloWorld.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pablini27/Documents/SP1_mejoras/src/main.cpp -o CMakeFiles/HelloWorld.dir/src/main.cpp.s

CMakeFiles/HelloWorld.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/HelloWorld.dir/src/main.cpp.o.requires

CMakeFiles/HelloWorld.dir/src/main.cpp.o.provides: CMakeFiles/HelloWorld.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/HelloWorld.dir/build.make CMakeFiles/HelloWorld.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/HelloWorld.dir/src/main.cpp.o.provides

CMakeFiles/HelloWorld.dir/src/main.cpp.o.provides.build: CMakeFiles/HelloWorld.dir/src/main.cpp.o

# Object files for target HelloWorld
HelloWorld_OBJECTS = \
"CMakeFiles/HelloWorld.dir/src/main.cpp.o"

# External object files for target HelloWorld
HelloWorld_EXTERNAL_OBJECTS =

HelloWorld: CMakeFiles/HelloWorld.dir/src/main.cpp.o
HelloWorld: CMakeFiles/HelloWorld.dir/build.make
HelloWorld: /usr/local/lib/libopencv_viz.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_videostab.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_videoio.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_video.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_superres.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_stitching.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_shape.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_photo.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_objdetect.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_ml.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_imgproc.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_highgui.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_flann.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_features2d.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudev.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudawarping.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudastereo.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudaoptflow.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudaobjdetect.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudalegacy.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudaimgproc.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudafilters.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudafeatures2d.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudacodec.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudabgsegm.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudaarithm.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_core.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_calib3d.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudawarping.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_objdetect.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudafilters.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudaarithm.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_features2d.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_ml.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_highgui.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_videoio.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_flann.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_video.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_imgproc.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_core.so.3.1.0
HelloWorld: /usr/local/lib/libopencv_cudev.so.3.1.0
HelloWorld: CMakeFiles/HelloWorld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable HelloWorld"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HelloWorld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HelloWorld.dir/build: HelloWorld
.PHONY : CMakeFiles/HelloWorld.dir/build

CMakeFiles/HelloWorld.dir/requires: CMakeFiles/HelloWorld.dir/src/main.cpp.o.requires
.PHONY : CMakeFiles/HelloWorld.dir/requires

CMakeFiles/HelloWorld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HelloWorld.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HelloWorld.dir/clean

CMakeFiles/HelloWorld.dir/depend:
	cd /home/pablini27/Documents/SP1_mejoras/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pablini27/Documents/SP1_mejoras /home/pablini27/Documents/SP1_mejoras /home/pablini27/Documents/SP1_mejoras/build /home/pablini27/Documents/SP1_mejoras/build /home/pablini27/Documents/SP1_mejoras/build/CMakeFiles/HelloWorld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HelloWorld.dir/depend

