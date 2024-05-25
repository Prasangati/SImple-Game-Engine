//
// Created by Prasanga Tiwari on 5/24/24.
//

#ifndef YOURPROJECTNAME_UNIT_H
#define YOURPROJECTNAME_UNIT_H




#include "utility.h"
#include "Image.h"
#include "Renderer.h"
namespace Ultimate {
    class ULTIMATE_API Unit {
            public:
            Unit(const std::string& image, int x, int y);
            Unit(std::string&& image, int x, int y);

            int GetWidth() const;
            int GetHeight() const;

            int GetXCoord() const;
            int GetYCoord() const;
            void SetCoords(int x, int y);
            void UpdateXCoord(int amount);
            void UpdateYCoord(int amount);

            private:
            Image mImage;
            int mXPosition;
            int mYPosition;

            friend ULTIMATE_API bool UnitsOverlap(const Unit& a, const Unit& b);
            friend class Renderer;
    };

    ULTIMATE_API bool UnitsOverlap(const Unit& a, const Unit& b);
}
#endif //YOURPROJECTNAME_UNIT_H
