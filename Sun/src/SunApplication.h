//
// Created by Prasanga Tiwari on 3/3/24.
//

#ifndef S24_PRASANGA_TIWARI_SUNAPPLICATION_H
#define S24_PRASANGA_TIWARI_SUNAPPLICATION_H
#include "utility.h"
namespace Sun {
    class SUN_API SunApplication {
    public:
        virtual void initialize();
        virtual void OnUpdate();
        virtual void ShutDown();

        void Run();
    private:

    };


}



#endif //S24_PRASANGA_TIWARI_SUNAPPLICATION_H
