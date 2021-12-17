/* 
 * This file is part of the Dragon Curve distribution.
 * Copyright (c) 2021-2022 Michael Tesar.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
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