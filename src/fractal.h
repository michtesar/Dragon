#ifndef FRACTAL_H
#define FRACTAL_H

#include "graphics.h"

class Fractal {
    public:
        GraphicsManager* gm;
        int maxIteration;
        int offsideX;
        int offsideY;
        float compressionStep = 0.01;

        Fractal(
            GraphicsManager* gm, 
            int maxIteration, 
            int offsideX, 
            int offsideY
        );

        void unfoldIteration(
            int iteration, 
            float x1, 
            float y1, 
            float x2, 
            float y2, 
            float compressionX, 
            float compressionY
        );
};

#endif