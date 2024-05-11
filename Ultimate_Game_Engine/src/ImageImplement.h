//
// Created by Prasanga Tiwari on 5/11/24.
//

#ifndef YOURPROJECTNAME_IMAGEIMPLEMENT_H
#define YOURPROJECTNAME_IMAGEIMPLEMENT_H

namespace Ultimate{
    class ImageImplement{
    public:
        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;
        virtual int Bind() const = 0;
    };
}

#endif //YOURPROJECTNAME_IMAGEIMPLEMENT_H
