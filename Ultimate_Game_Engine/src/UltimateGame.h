//
// Created by Prasanga Tiwari on 3/3/24.
//

#ifndef S24_PRASANGA_TIWARI_SUNAPPLICATION_H
#define S24_PRASANGA_TIWARI_SUNAPPLICATION_H
#include "utility.h"
namespace Ultimate {
    class  UltimateGame {
    public:
        virtual void Initialize();
        virtual void OnUpdate();
        virtual void ShutDown();
        void Run();
    private:

    };


}



#endif //S24_PRASANGA_TIWARI_SUNAPPLICATION_H
