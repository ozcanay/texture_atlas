# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/ozcanay/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.6707.69/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ozcanay/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.6707.69/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ozcanay/CLionProjects/texture_atlas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ozcanay/CLionProjects/texture_atlas/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/texture_atlas.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/texture_atlas.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/texture_atlas.dir/flags.make

CMakeFiles/texture_atlas.dir/main.cpp.o: CMakeFiles/texture_atlas.dir/flags.make
CMakeFiles/texture_atlas.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ozcanay/CLionProjects/texture_atlas/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/texture_atlas.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/texture_atlas.dir/main.cpp.o -c /home/ozcanay/CLionProjects/texture_atlas/main.cpp

CMakeFiles/texture_atlas.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_atlas.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ozcanay/CLionProjects/texture_atlas/main.cpp > CMakeFiles/texture_atlas.dir/main.cpp.i

CMakeFiles/texture_atlas.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_atlas.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ozcanay/CLionProjects/texture_atlas/main.cpp -o CMakeFiles/texture_atlas.dir/main.cpp.s

CMakeFiles/texture_atlas.dir/ImageManager.cpp.o: CMakeFiles/texture_atlas.dir/flags.make
CMakeFiles/texture_atlas.dir/ImageManager.cpp.o: ../ImageManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ozcanay/CLionProjects/texture_atlas/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/texture_atlas.dir/ImageManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/texture_atlas.dir/ImageManager.cpp.o -c /home/ozcanay/CLionProjects/texture_atlas/ImageManager.cpp

CMakeFiles/texture_atlas.dir/ImageManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_atlas.dir/ImageManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ozcanay/CLionProjects/texture_atlas/ImageManager.cpp > CMakeFiles/texture_atlas.dir/ImageManager.cpp.i

CMakeFiles/texture_atlas.dir/ImageManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_atlas.dir/ImageManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ozcanay/CLionProjects/texture_atlas/ImageManager.cpp -o CMakeFiles/texture_atlas.dir/ImageManager.cpp.s

# Object files for target texture_atlas
texture_atlas_OBJECTS = \
"CMakeFiles/texture_atlas.dir/main.cpp.o" \
"CMakeFiles/texture_atlas.dir/ImageManager.cpp.o"

# External object files for target texture_atlas
texture_atlas_EXTERNAL_OBJECTS =

texture_atlas: CMakeFiles/texture_atlas.dir/main.cpp.o
texture_atlas: CMakeFiles/texture_atlas.dir/ImageManager.cpp.o
texture_atlas: CMakeFiles/texture_atlas.dir/build.make
texture_atlas: /usr/local/lib/libopencv_gapi.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_stitching.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_aruco.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_bgsegm.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_bioinspired.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_ccalib.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_dnn_objdetect.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_dpm.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_face.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_freetype.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_fuzzy.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_hfs.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_img_hash.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_line_descriptor.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_quality.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_reg.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_rgbd.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_saliency.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_stereo.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_structured_light.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_superres.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_surface_matching.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_tracking.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_videostab.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_xfeatures2d.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_xobjdetect.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_xphoto.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_shape.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_datasets.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_plot.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_text.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_dnn.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_highgui.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_ml.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_phase_unwrapping.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_optflow.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_ximgproc.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_video.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_videoio.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_imgcodecs.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_objdetect.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_calib3d.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_features2d.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_flann.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_photo.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_imgproc.so.4.1.0
texture_atlas: /usr/local/lib/libopencv_core.so.4.1.0
texture_atlas: CMakeFiles/texture_atlas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ozcanay/CLionProjects/texture_atlas/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable texture_atlas"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/texture_atlas.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/texture_atlas.dir/build: texture_atlas

.PHONY : CMakeFiles/texture_atlas.dir/build

CMakeFiles/texture_atlas.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/texture_atlas.dir/cmake_clean.cmake
.PHONY : CMakeFiles/texture_atlas.dir/clean

CMakeFiles/texture_atlas.dir/depend:
	cd /home/ozcanay/CLionProjects/texture_atlas/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ozcanay/CLionProjects/texture_atlas /home/ozcanay/CLionProjects/texture_atlas /home/ozcanay/CLionProjects/texture_atlas/cmake-build-debug /home/ozcanay/CLionProjects/texture_atlas/cmake-build-debug /home/ozcanay/CLionProjects/texture_atlas/cmake-build-debug/CMakeFiles/texture_atlas.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/texture_atlas.dir/depend
