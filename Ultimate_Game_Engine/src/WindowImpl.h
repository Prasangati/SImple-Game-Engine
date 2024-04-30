//
// Created by Prasanga Tiwari on 4/3/24.
//

#ifndef S24_PRASANGA_TIWARI_WINDOWIMPL_H
#define S24_PRASANGA_TIWARI_WINDOWIMPL_H

namespace Ultimate {

    class WindowImpl {
    public:
        virtual void Create(int width, int height) = 0;
        virtual void SwapBuffers()=0;
        virtual void PollEvents()=0;

        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;
        virtual bool IsValid()const = 0;
        virtual void glfeveninfo() const = 0;
        virtual ~WindowImpl() {};

    };

} // Ultimate

#endif //S24_PRASANGA_TIWARI_WINDOWIMPL_H
