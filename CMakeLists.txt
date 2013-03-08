cmake_minimum_required(VERSION 2.8.6)
project(HelloGTest CXX)
set(HGT_SOURCE_DIR ${HelloGTest_SOURCE_DIR}/src)

# We're going to fetch GoogleMock and GoogleTest externally from the intarwebs
# and install it as what CMake knows as an "ExternalProject"
# Add GoogleMock
# This is derived from this solution on StackOverflow.
# http://stackoverflow.com/questions/9689183/cmake-googletest#9695234
# There is also a related GitHub gist at
# https://gist.github.com/oneamtu/3734295
# which has some elegant changes to this answer.
include(ExternalProject)
# Set default ExternalProject root directory
SET_DIRECTORY_PROPERTIES(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/vendor)
ExternalProject_Add(
	googlemock
	# We're pinning GoogleMock and GoogleTest to 1.6.0; update the URL and
	# the SHA1 if this updates.
	URL http://googlemock.googlecode.com/files/gmock-1.6.0.zip
	URL_HASH SHA1=4702e98af194d320a915f1e6d2532a32b280819e
	TIMEOUT 30
	#
	# NOTE: The below flags don't seem to work for GoogleMock/GoogleTest
	# because it uses an older CMake policy; we'll ignore it for now. If
	# this changes, we must change target_link_libraries, too.
	#
	# Force separate output paths for debug and release builds to allow
	# easy identification of correct lib in subsequent
	# TARGET_LINK_LIBRARIES commands
	#CMAKE_ARGS -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
	# Disable install step
	INSTALL_COMMAND ""
	# Wrap download, configure and build steps in a script to log output
	LOG_DOWNLOAD ON
	LOG_CONFIGURE ON
	LOG_BUILD ON
)
# Specify include dir
ExternalProject_Get_Property(googlemock SOURCE_DIR)
# Include GoogleMock
include_directories(${SOURCE_DIR} ${SOURCE_DIR}/include)
# Include GoogleTest
include_directories(${SOURCE_DIR}/gtest ${SOURCE_DIR}/gtest/include)


enable_testing()

# Build tests

set(HGT_TEST_SOURCE_DIR ${HGT_SOURCE_DIR}/tests)
# Add the actual test executable
add_executable(runUnitTests ${HGT_TEST_SOURCE_DIR}/basic_test.cpp)

# Make the executable depend on googlemock
add_dependencies(runUnitTests googlemock)

# Specify the link libraries provided by GoogleMock and GoogleTest
# First, get the path
ExternalProject_Get_Property(googlemock BINARY_DIR)
target_link_libraries(runUnitTests
		      ${BINARY_DIR}/${CMAKE_FIND_LIBRARY_PREFIXES}gmock.a
		      ${BINARY_DIR}/${CMAKE_FIND_LIBRARY_PREFIXES}gmock_main.a
                      ${BINARY_DIR}/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a
                      ${BINARY_DIR}/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main.a
)


# Run tests
add_test(runUnitTests runUnitTests)

