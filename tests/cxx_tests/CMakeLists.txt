
add_executable(cxx_clipboard clipboard.cpp ${GETOPT} ${GLAD})
add_executable(cxx_events events.cpp ${GETOPT} ${GLAD})
add_executable(cxx_msaa msaa.cpp ${GETOPT} ${GLAD})
add_executable(cxx_glfwinfo glfwinfo.cpp ${GETOPT} ${GLAD})
add_executable(cxx_iconify iconify.cpp ${GETOPT} ${GLAD})
add_executable(cxx_monitors monitors.cpp ${GETOPT} ${GLAD})
add_executable(cxx_reopen reopen.cpp ${GLAD})
add_executable(cxx_cursor cursor.cpp ${GLAD})

add_executable(cxx_empty WIN32 MACOSX_BUNDLE empty.cpp ${TINYCTHREAD} ${GLAD})
add_executable(cxx_gamma WIN32 MACOSX_BUNDLE gamma.cpp ${GLAD})
add_executable(cxx_icon WIN32 MACOSX_BUNDLE icon.cpp ${GLAD})
add_executable(cxx_inputlag WIN32 MACOSX_BUNDLE inputlag.cpp ${GETOPT} ${GLAD})
add_executable(cxx_joysticks WIN32 MACOSX_BUNDLE joysticks.cpp ${GLAD})
add_executable(cxx_opacity WIN32 MACOSX_BUNDLE opacity.cpp ${GLAD})
add_executable(cxx_tearing WIN32 MACOSX_BUNDLE tearing.cpp ${GETOPT} ${GLAD})
add_executable(cxx_threads WIN32 MACOSX_BUNDLE threads.cpp ${TINYCTHREAD} ${GLAD})
add_executable(cxx_timeout WIN32 MACOSX_BUNDLE timeout.cpp ${GLAD})
add_executable(cxx_title WIN32 MACOSX_BUNDLE title.cpp ${GLAD})
add_executable(cxx_windows WIN32 MACOSX_BUNDLE windows.cpp ${GETOPT} ${GLAD})

target_link_libraries(cxx_empty "${CMAKE_THREAD_LIBS_INIT}")
target_link_libraries(cxx_threads "${CMAKE_THREAD_LIBS_INIT}")
if (RT_LIBRARY)
    target_link_libraries(cxx_empty "${RT_LIBRARY}")
    target_link_libraries(cxx_threads "${RT_LIBRARY}")
endif()

set(CXX_WINDOWS_BINARIES cxx_empty cxx_gamma cxx_icon cxx_inputlag cxx_joysticks cxx_opacity cxx_tearing
                         cxx_threads cxx_timeout cxx_title cxx_windows)
set(CXX_CONSOLE_BINARIES cxx_clipboard cxx_events cxx_msaa cxx_glfwinfo cxx_iconify cxx_monitors cxx_reopen
                         cxx_cursor)

if (VULKAN_FOUND)
    add_executable(cxx_vulkan WIN32 vulkan.cpp ${ICON})
    target_include_directories(cxx_vulkan PRIVATE "${VULKAN_INCLUDE_DIR}")
    if (GLFW_VULKAN_STATIC)
        target_link_libraries(cxx_vulkan "${VULKAN_STATIC_LIBRARY}")
    else()
        target_link_libraries(cxx_vulkan "${VULKAN_LIBRARY}")
    endif()
    list(APPEND CXX_WINDOWS_BINARIES cxx_vulkan)
endif()

set_target_properties(${CXX_WINDOWS_BINARIES} ${CXX_CONSOLE_BINARIES} PROPERTIES
                          FOLDER "GLFW3/Tests"
                          CXX_STANDARD 11
                          CXX_STANDARD_REQUIRED YES)

if (MSVC)
    # Tell MSVC to use main instead of WinMain for Windows subsystem executables
    set_target_properties(${CXX_WINDOWS_BINARIES} ${CXX_CONSOLE_BINARIES} PROPERTIES
                          LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

if (APPLE)
    set_target_properties(cxx_empty PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Empty Event" )
    set_target_properties(cxx_gamma PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Gamma")
    set_target_properties(cxx_inputlag PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Input Lag")
    set_target_properties(cxx_joysticks PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Joysticks")
    set_target_properties(cxx_opacity PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Opacity")
    set_target_properties(cxx_tearing PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Tearing")
    set_target_properties(cxx_threads PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Threads")
    set_target_properties(cxx_timeout PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Timeout")
    set_target_properties(cxx_title PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Title")
    set_target_properties(cxx_windows PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Cpp Windows")

    set_target_properties(${CXX_WINDOWS_BINARIES} ${CXX_CONSOLE_BINARIES} PROPERTIES
                          MACOSX_BUNDLE_SHORT_VERSION_STRING ${GLFW_VERSION}
                          MACOSX_BUNDLE_LONG_VERSION_STRING ${GLFW_VERSION_FULL}
                          MACOSX_BUNDLE_INFO_PLIST "${GLFW_SOURCE_DIR}/CMake/MacOSXBundleInfo.plist.in")
endif()
