//Macro for Windows shared library compilation

#ifdef _WIN32
    #ifdef SUPERMESH_EXPORTS
        #define SUPERMESH_API __declspec(dllexport)
    #else
        #define SUPERMESH_API __declspec(dllimport)
    #endif
#else
    #define SUPERMESH_API
#endif