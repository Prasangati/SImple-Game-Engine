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
    #ifdef ULTIMATE_EXPORTS
        #define ULTIMATE_API __declspec(dllexport)
    #else
        #define ULTIMATE_API __declspec(dllimport)
    #endif
#elif defined(__GNUC__) || defined(__clang__)
    #ifdef ULTIMATE_EXPORTS
        #define ULTIMATE_API __attribute__((visibility("default")))
    #else
        #define ULTIMATE_API
    #endif
#else
    #define ULTIMATE_API // Or any default definition appropriate for other compilers
#endif





#if ULTIMATE_DEBUG==2
    #define ULTIMATE_ERROR(x) std::cout<<x<<std::endl;
    #define ULTIMATE_LOG(x) std::cout<<x<<std::endl;
#elif ULTIMATE_DEBUG==1
    #define ULTIMATE_ERROR(x) std::cout<<x<<std::endl;
    #define ULTIMATE_LOG(x)
#else
    #define ULTIMATE_ERROR(x)
    #define ULTIMATE_LOG(x)
#endif




