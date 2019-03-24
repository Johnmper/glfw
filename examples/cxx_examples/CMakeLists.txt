

add_executable(cxx_boing WIN32 MACOSX_BUNDLE boing.cpp ${ICON} ${GLAD})
add_executable(cxx_gears WIN32 MACOSX_BUNDLE gears.cpp ${ICON} ${GLAD})
add_executable(cxx_heightmap WIN32 MACOSX_BUNDLE heightmap.cpp ${ICON} ${GLAD})
add_executable(cxx_offscreen offscreen.cpp ${ICON} ${GLAD})
add_executable(cxx_particles WIN32 MACOSX_BUNDLE particles.cpp ${ICON} ${TINYCTHREAD} ${GETOPT} ${GLAD})
add_executable(cxx_sharing WIN32 MACOSX_BUNDLE sharing.cpp ${ICON} ${GLAD})
add_executable(cxx_simple WIN32 MACOSX_BUNDLE simple.cpp ${ICON} ${GLAD})
add_executable(cxx_splitview WIN32 MACOSX_BUNDLE splitview.cpp ${ICON} ${GLAD})
add_executable(cxx_wave WIN32 MACOSX_BUNDLE wave.cpp ${ICON} ${GLAD})

target_link_libraries(cxx_particles "${CMAKE_THREAD_LIBS_INIT}")
if (RT_LIBRARY)
    target_link_libraries(cxx_particles "${RT_LIBRARY}")
endif()

set(WINDOWS_BINARIES cxx_boing cxx_gears cxx_heightmap cxx_particles cxx_sharing cxx_simple cxx_splitview cxx_wave)
set(CONSOLE_BINARIES cxx_offscreen)

set_target_properties(${WINDOWS_BINARIES} ${CONSOLE_BINARIES} PROPERTIES
                      FOLDER "GLFW3/Examples"
                      CXX_STANDARD 11
                      CXX_STANDARD_REQUIRED YES)

if (MSVC)
    # Tell MSVC to use main instead of WinMain for Windows subsystem executables
    set_target_properties(${WINDOWS_BINARIES} PROPERTIES
                          LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

if (APPLE)
    set_target_properties(cxx_boing PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Boing")
    set_target_properties(cxx_gears PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Gears")
    set_target_properties(cxx_heightmap PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Heightmap")
    set_target_properties(cxx_particles PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Particles")
    set_target_properties(cxx_sharing PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Sharing")
    set_target_properties(cxx_simple PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Simple")
    set_target_properties(cxx_splitview PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp SplitView")
    set_target_properties(cxx_wave PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Wave")

    set_target_properties(${WINDOWS_BINARIES} PROPERTIES
                          RESOURCE glfw.icns
                          MACOSX_BUNDLE_SHORT_VERSION_STRING ${GLFW_VERSION}
                          MACOSX_BUNDLE_LONG_VERSION_STRING ${GLFW_VERSION_FULL}
                          MACOSX_BUNDLE_ICON_FILE glfw.icns
                          MACOSX_BUNDLE_INFO_PLIST "${GLFW_SOURCE_DIR}/CMake/MacOSXBundleInfo.plist.in")
endif()
