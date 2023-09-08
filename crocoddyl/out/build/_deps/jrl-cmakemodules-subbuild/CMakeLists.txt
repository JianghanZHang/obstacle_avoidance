# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.16.3)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(jrl-cmakemodules-populate NONE)

include(ExternalProject)
ExternalProject_Add(jrl-cmakemodules-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/jrl-umi3218/jrl-cmakemodules.git"
                    SOURCE_DIR          "/home/jianghan/devel/workspace/src/ur10e_obstacle_avoidance/crocoddyl/out/build/_deps/jrl-cmakemodules-src"
                    BINARY_DIR          "/home/jianghan/devel/workspace/src/ur10e_obstacle_avoidance/crocoddyl/out/build/_deps/jrl-cmakemodules-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
