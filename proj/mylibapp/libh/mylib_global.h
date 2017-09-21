#ifndef MYLIB_GLOBAL_H
#define MYLIB_GLOBAL_H

#ifdef WIN32
    #ifndef _MYLIB_API_
        #ifdef MYLIB_LIBRARY
            #define _MYLIB_API_ __declspec(dllexport)
        #else
            #define _MYLIB_API_ __declspec(dllimport)
        #endif
    #endif
#else
    #define _MYLIB_API_
#endif

#endif // MYLIB_GLOBAL_H
