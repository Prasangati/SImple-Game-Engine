//
// Created by Prasanga Tiwari on 2/25/24.
//

#ifndef S24_PRASANGA_TIWARI_SOLUTION_UTILITY_H
#define S24_PRASANGA_TIWARI_SOLUTION_UTILITY_H

#define START_GAME(className)\
int main()\
{\
    className _game;\
    _game.Run();\
    return 0;\
}
#endif //S24_PRASANGA_TIWARI_SOLUTION_UTILITY_H

#if defined(_WIN32)
#ifdef SUN_EXPORTS
        #define SUN_API __declspec(dllexport)
    #else
        #define SUN_API __declspec(dllimport)
    #endif
#elif defined(__GNUC__) || defined(__clang__)
#ifdef SUN_EXPORTS
#define SUN_API __attribute__((visibility("default")))
#else
#define SUN_API
#endif
#else
#define SUN_API

#if SUN_DEBUG==2
    #define SUN_ERROR(x) std::cout<<x<<std::endl;
    #define SUN_LOG(x) std::cout<<x<<std::endl;
#elif SUN_DEBUG==1
    #define SUN_ERROR(x) std::cout<<x<<std::endl;
    #define SUN_LOG(x)
#else
    #define SUN_ERROR(x)
    #define SUN_LOG(x)
#endif



#endif