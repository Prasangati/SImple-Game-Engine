//
// Created by Soleil Rosado on 4/3/24.
//

#ifndef S24_PRASANGA_TIWARI_WINDOWIMPL_H
#define S24_PRASANGA_TIWARI_WINDOWIMPL_H

namespace Ultimate {

    class WindowImpl {
    public:
        virtual void Create(int width, int height) = 0;
        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;
        virtual ~WindowImpl() {};

    };

} // Ultimate

#endif //S24_PRASANGA_TIWARI_WINDOWIMPL_H
