#ifndef _glfw3cxx_h_
#define _glfw3cxx_h_

namespace glfw
{
    namespace{
        #include<GLFW/glfw3.h>
    }
    static constexpr auto True = GLFW_TRUE;
    static constexpr auto False = GLFW_FALSE;

    typedef void (*GlProc)(void);
    typedef void (*VkProc)(void);
    typedef struct GLFWMonitor Monitor;
    typedef struct GLFWwindow Window;
    typedef struct GLFWcursor Cursor;
    typedef void (*ErrorFun)(int,const char*);
    typedef void (*WindowPosFun)(Window*,int,int);
    typedef void (*WindowSizeFun)(Window*,int,int);
    typedef void (*WindowCloseFun)(Window*);
    typedef void (*WindowRefreshFun)(Window*);
    typedef void (*WindowFocusFun)(Window*,int);
    typedef void (*WindowIconifyFun)(Window*,int);
    typedef void (*WindowMaximizeFun)(Window*,int);
    typedef void (*FrameBufferSizeFun)(Window*,int,int);
    typedef void (*WindowContentScaleFun)(Window*,float,float);
    typedef void (*MouseButtonFun)(Window*,int,int,int);
    typedef void (*CursorPosFun)(Window*,double,double);
    typedef void (*CursorEnterFun)(Window*,int);
    typedef void (*ScrollFun)(Window*,double,double);
    typedef void (*KeyFun)(Window*,int,int,int,int);
    typedef void (*CharFun)(Window*,unsigned int);
    typedef void (*CharModsFun)(Window*,unsigned int,int);
    typedef void (*DropFun)(Window*,int,const char**);
    typedef void (*MonitorFun)(Monitor*,int);
    typedef void (*JoystickFun)(int,int);
    typedef struct GLFWvidmode VidMode;
    typedef struct GLFWgammaramp GammaRamp;
    typedef struct GLFWimage Image;
    typedef struct GLFWgamepadstate GamepadState;

    static auto Init = reinterpret_cast<int(*)(void)>(&glfwInit);
    static auto Terminate = reinterpret_cast<void(*)(void)>(&glfwTerminate);
    static auto InitHint = reinterpret_cast<void(*)(int,int)>(&glfwInitHint);
    static auto GetVersion = reinterpret_cast<void(*)(int*,int* minor, int*)>(&glfwGetVersion);
    static auto GetVersionString = reinterpret_cast<const char* (*)(void)>(&glfwGetVersionString);
    static auto GetError = reinterpret_cast<int(*)(const char**)>(&glfwGetError);
    static auto SetErrorCallback = reinterpret_cast<ErrorFun(*)(ErrorFun)>(&glfwSetErrorCallback);
    static auto GetMonitors = reinterpret_cast<Monitor**(*)(int*)>(&glfwGetMonitors);
    static auto GetPrimaryMonitor = reinterpret_cast<Monitor*(*)(void)>(&glfwGetPrimaryMonitor);
    static auto GetMonitorPos = reinterpret_cast<void(*)(Monitor*,int* xpos, int*)>(&glfwGetMonitorPos);
    static auto GetMonitorWorkarea = reinterpret_cast<void(*)(Monitor*,int* xpos, int* ypos, int* width, int*)>(&glfwGetMonitorWorkarea);
    static auto GetMonitorPhysicalSize = reinterpret_cast<void(*)(Monitor*,int* widthMM, int*)>(&glfwGetMonitorPhysicalSize);
    static auto GetMonitorContentScale = reinterpret_cast<void(*)(Monitor*,float* xscale, float*)>(&glfwGetMonitorContentScale);
    static auto GetMonitorName = reinterpret_cast<const char* (*)(Monitor*)>(&glfwGetMonitorName);
    static auto SetMonitorUserPointer = reinterpret_cast<void(*)(Monitor*,void*)>(&glfwSetMonitorUserPointer);
    static auto GetMonitorUserPointer = reinterpret_cast<void*(*)(Monitor*)>(&glfwGetMonitorUserPointer);
    static auto SetMonitorCallback = reinterpret_cast<MonitorFun(*)(MonitorFun)>(&glfwSetMonitorCallback);
    static auto GetVideoModes = reinterpret_cast<const VidMode* (*)(Monitor*,int*)>(&glfwGetVideoModes);
    static auto GetVideoMode = reinterpret_cast<const VidMode* (*)(Monitor*)>(&glfwGetVideoMode);
    static auto SetGamma = reinterpret_cast<void(*)(Monitor*,float)>(&glfwSetGamma);
    static auto GetGammaRamp = reinterpret_cast<const GammaRamp* (*)(Monitor*)>(&glfwGetGammaRamp);
    static auto SetGammaRamp = reinterpret_cast<void(*)(Monitor*,const GammaRamp*)>(&glfwSetGammaRamp);
    static auto DefaultWindowHints = reinterpret_cast<void(*)(void)>(&glfwDefaultWindowHints);
    static auto WindowHint = reinterpret_cast<void(*)(int,int)>(&glfwWindowHint);
    static auto WindowHintString = reinterpret_cast<void(*)(int,const char*)>(&glfwWindowHintString);
    static auto CreateWindow = reinterpret_cast<Window*(*)(int,int height, const char* title, Monitor* monitor, Window*)>(&glfwCreateWindow);
    static auto DestroyWindow = reinterpret_cast<void(*)(Window*)>(&glfwDestroyWindow);
    static auto WindowShouldClose = reinterpret_cast<int(*)(Window*)>(&glfwWindowShouldClose);
    static auto SetWindowShouldClose = reinterpret_cast<void(*)(Window*,int)>(&glfwSetWindowShouldClose);
    static auto SetWindowTitle = reinterpret_cast<void(*)(Window*,const char*)>(&glfwSetWindowTitle);
    static auto SetWindowIcon = reinterpret_cast<void(*)(Window*,int count, const Image*)>(&glfwSetWindowIcon);
    static auto GetWindowPos = reinterpret_cast<void(*)(Window*,int* xpos, int*)>(&glfwGetWindowPos);
    static auto SetWindowPos = reinterpret_cast<void(*)(Window*,int xpos, int)>(&glfwSetWindowPos);
    static auto GetWindowSize = reinterpret_cast<void(*)(Window*,int* width, int*)>(&glfwGetWindowSize);
    static auto SetWindowSizeLimits = reinterpret_cast<void(*)(Window*,int minwidth, int minheight, int maxwidth, int)>(&glfwSetWindowSizeLimits);
    static auto SetWindowAspectRatio = reinterpret_cast<void(*)(Window*,int numer, int)>(&glfwSetWindowAspectRatio);
    static auto SetWindowSize = reinterpret_cast<void(*)(Window*,int width, int)>(&glfwSetWindowSize);
    static auto GetFramebufferSize = reinterpret_cast<void(*)(Window*,int* width, int*)>(&glfwGetFramebufferSize);
    static auto GetWindowFrameSize = reinterpret_cast<void(*)(Window*,int* left, int* top, int* right, int*)>(&glfwGetWindowFrameSize);
    static auto GetWindowContentScale = reinterpret_cast<void(*)(Window*,float* xscale, float*)>(&glfwGetWindowContentScale);
    static auto GetWindowOpacity = reinterpret_cast<float(*)(Window*)>(&glfwGetWindowOpacity);
    static auto SetWindowOpacity = reinterpret_cast<void(*)(Window*,float)>(&glfwSetWindowOpacity);
    static auto IconifyWindow = reinterpret_cast<void(*)(Window*)>(&glfwIconifyWindow);
    static auto RestoreWindow = reinterpret_cast<void(*)(Window*)>(&glfwRestoreWindow);
    static auto MaximizeWindow = reinterpret_cast<void(*)(Window*)>(&glfwMaximizeWindow);
    static auto ShowWindow = reinterpret_cast<void(*)(Window*)>(&glfwShowWindow);
    static auto HideWindow = reinterpret_cast<void(*)(Window*)>(&glfwHideWindow);
    static auto FocusWindow = reinterpret_cast<void(*)(Window*)>(&glfwFocusWindow);
    static auto RequestWindowAttention = reinterpret_cast<void(*)(Window*)>(&glfwRequestWindowAttention);
    static auto GetWindowMonitor = reinterpret_cast<Monitor*(*)(Window*)>(&glfwGetWindowMonitor);
    static auto SetWindowMonitor = reinterpret_cast<void(*)(Window*,Monitor* monitor, int xpos, int ypos, int width, int height, int)>(&glfwSetWindowMonitor);
    static auto GetWindowAttrib = reinterpret_cast<int(*)(Window*,int)>(&glfwGetWindowAttrib);
    static auto SetWindowAttrib = reinterpret_cast<void(*)(Window*,int attrib, int)>(&glfwSetWindowAttrib);
    static auto SetWindowUserPointer = reinterpret_cast<void(*)(Window*,void*)>(&glfwSetWindowUserPointer);
    static auto GetWindowUserPointer = reinterpret_cast<void*(*)(Window*)>(&glfwGetWindowUserPointer);
    static auto SetWindowPosCallback = reinterpret_cast<WindowPosFun(*)(Window*,WindowPosFun)>(&glfwSetWindowPosCallback);
    static auto SetWindowSizeCallback = reinterpret_cast<WindowSizeFun(*)(Window*,WindowSizeFun)>(&glfwSetWindowSizeCallback);
    static auto SetWindowCloseCallback = reinterpret_cast<WindowCloseFun(*)(Window*,WindowCloseFun)>(&glfwSetWindowCloseCallback);
    static auto SetWindowRefreshCallback = reinterpret_cast<WindowRefreshFun(*)(Window*,WindowRefreshFun)>(&glfwSetWindowRefreshCallback);
    static auto SetWindowFocusCallback = reinterpret_cast<WindowFocusFun(*)(Window*,WindowFocusFun)>(&glfwSetWindowFocusCallback);
    static auto SetWindowIconifyCallback = reinterpret_cast<WindowIconifyFun(*)(Window*,WindowIconifyFun)>(&glfwSetWindowIconifyCallback);
    static auto SetWindowMaximizeCallback = reinterpret_cast<WindowMaximizeFun(*)(Window*,WindowMaximizeFun)>(&glfwSetWindowMaximizeCallback);
    static auto SetFramebufferSizeCallback = reinterpret_cast<FrameBufferSizeFun(*)(Window*,FrameBufferSizeFun)>(&glfwSetFramebufferSizeCallback);
    static auto SetWindowContentScaleCallback = reinterpret_cast<WindowContentScaleFun(*)(Window*,WindowContentScaleFun)>(&glfwSetWindowContentScaleCallback);
    static auto PollEvents = reinterpret_cast<void(*)(void)>(&glfwPollEvents);
    static auto WaitEvents = reinterpret_cast<void(*)(void)>(&glfwWaitEvents);
    static auto WaitEventsTimeout = reinterpret_cast<void(*)(double)>(&glfwWaitEventsTimeout);
    static auto PostEmptyEvent = reinterpret_cast<void(*)(void)>(&glfwPostEmptyEvent);
    static auto GetInputMode = reinterpret_cast<int(*)(Window*,int)>(&glfwGetInputMode);
    static auto SetInputMode = reinterpret_cast<void(*)(Window*,int mode, int)>(&glfwSetInputMode);
    static auto RawMouseMotionSupported = reinterpret_cast<int(*)(void)>(&glfwRawMouseMotionSupported);
    static auto GetKeyName = reinterpret_cast<const char* (*)(int,int)>(&glfwGetKeyName);
    static auto GetKeyScancode = reinterpret_cast<int(*)(int)>(&glfwGetKeyScancode);
    static auto GetKey = reinterpret_cast<int(*)(Window*,int)>(&glfwGetKey);
    static auto GetMouseButton = reinterpret_cast<int(*)(Window*,int)>(&glfwGetMouseButton);
    static auto GetCursorPos = reinterpret_cast<void(*)(Window*,double* xpos, double*)>(&glfwGetCursorPos);
    static auto SetCursorPos = reinterpret_cast<void(*)(Window*,double xpos, double)>(&glfwSetCursorPos);
    static auto CreateCursor = reinterpret_cast<Cursor*(*)(const Image*,int xhot, int)>(&glfwCreateCursor);
    static auto CreateStandardCursor = reinterpret_cast<Cursor*(*)(int)>(&glfwCreateStandardCursor);
    static auto DestroyCursor = reinterpret_cast<void(*)(Cursor*)>(&glfwDestroyCursor);
    static auto SetCursor = reinterpret_cast<void(*)(Window*,Cursor*)>(&glfwSetCursor);
    static auto SetKeyCallback = reinterpret_cast<KeyFun(*)(Window*,KeyFun)>(&glfwSetKeyCallback);
    static auto SetCharCallback = reinterpret_cast<CharFun(*)(Window*,CharFun)>(&glfwSetCharCallback);
    static auto SetCharModsCallback = reinterpret_cast<CharModsFun(*)(Window*,CharModsFun)>(&glfwSetCharModsCallback);
    static auto SetMouseButtonCallback = reinterpret_cast<MouseButtonFun(*)(Window*,MouseButtonFun)>(&glfwSetMouseButtonCallback);
    static auto SetCursorPosCallback = reinterpret_cast<CursorPosFun(*)(Window*,CursorPosFun)>(&glfwSetCursorPosCallback);
    static auto SetCursorEnterCallback = reinterpret_cast<CursorEnterFun(*)(Window*,CursorEnterFun)>(&glfwSetCursorEnterCallback);
    static auto SetScrollCallback = reinterpret_cast<ScrollFun(*)(Window*,ScrollFun)>(&glfwSetScrollCallback);
    static auto SetDropCallback = reinterpret_cast<DropFun(*)(Window*,DropFun)>(&glfwSetDropCallback);
    static auto JoystickPresent = reinterpret_cast<int(*)(int)>(&glfwJoystickPresent);
    static auto GetJoystickAxes = reinterpret_cast<const float* (*)(int,int*)>(&glfwGetJoystickAxes);
    static auto GetJoystickButtons = reinterpret_cast<const unsigned char* (*)(int,int*)>(&glfwGetJoystickButtons);
    static auto GetJoystickHats = reinterpret_cast<const unsigned char* (*)(int,int*)>(&glfwGetJoystickHats);
    static auto GetJoystickName = reinterpret_cast<const char* (*)(int)>(&glfwGetJoystickName);
    static auto GetJoystickGUID = reinterpret_cast<const char* (*)(int)>(&glfwGetJoystickGUID);
    static auto SetJoystickUserPointer = reinterpret_cast<void(*)(int,void*)>(&glfwSetJoystickUserPointer);
    static auto GetJoystickUserPointer = reinterpret_cast<void*(*)(int)>(&glfwGetJoystickUserPointer);
    static auto JoystickIsGamepad = reinterpret_cast<int(*)(int)>(&glfwJoystickIsGamepad);
    static auto SetJoystickCallback = reinterpret_cast<JoystickFun(*)(JoystickFun)>(&glfwSetJoystickCallback);
    static auto UpdateGamepadMappings = reinterpret_cast<int(*)(const char*)>(&glfwUpdateGamepadMappings);
    static auto GetGamepadName = reinterpret_cast<const char* (*)(int)>(&glfwGetGamepadName);
    static auto GetGamepadState = reinterpret_cast<int(*)(int,GamepadState*)>(&glfwGetGamepadState);
    static auto SetClipboardString = reinterpret_cast<void(*)(Window*,const char*)>(&glfwSetClipboardString);
    static auto GetClipboardString = reinterpret_cast<const char* (*)(Window*)>(&glfwGetClipboardString);
    static auto GetTime = reinterpret_cast<double(*)(void)>(&glfwGetTime);
    static auto SetTime = reinterpret_cast<void(*)(double)>(&glfwSetTime);
    static auto GetTimerValue = reinterpret_cast<uint64_t(*)(void)>(&glfwGetTimerValue);
    static auto GetTimerFrequency = reinterpret_cast<uint64_t(*)(void)>(&glfwGetTimerFrequency);
    static auto MakeContextCurrent = reinterpret_cast<void(*)(Window*)>(&glfwMakeContextCurrent);
    static auto GetCurrentContext = reinterpret_cast<Window*(*)(void)>(&glfwGetCurrentContext);
    static auto SwapBuffers = reinterpret_cast<void(*)(Window*)>(&glfwSwapBuffers);
    static auto SwapInterval = reinterpret_cast<void(*)(int)>(&glfwSwapInterval);
    static auto ExtensionSupported = reinterpret_cast<int(*)(const char*)>(&glfwExtensionSupported);
    static auto GetProcAddress = reinterpret_cast<GlProc(*)(const char*)>(&glfwGetProcAddress);
    static auto VulkanSupported = reinterpret_cast<int(*)(void)>(&glfwVulkanSupported);
    static auto GetRequiredInstanceExtensions = reinterpret_cast<const char** (*)(uint32_t*)>(&glfwGetRequiredInstanceExtensions);
    #if defined(VK_VERSION_1_0)
        static auto GetInstanceProcAddress = reinterpret_cast<VkProc(*)(VkInstance,const char*)>(&glfwGetInstanceProcAddress);
        static auto GetPhysicalDevicePresentationSupport = reinterpret_cast<int(*)(VkInstance,VkPhysicalDevice device, uint32_t)>(&glfwGetPhysicalDevicePresentationSupport);
        static auto CreateWindowSurface = reinterpret_cast<VkResult(*)(VkInstance,Window* window, const VkAllocationCallbacks* allocator, VkSurfaceKHR*)>(&glfwCreateWindowSurface);
    #endif

}
#endif
