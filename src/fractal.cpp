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
#include "fractal.h"
#include <SFML/Graphics.hpp>

/**
 * @brief Construct a new Fractal:: Fractal object
 * 
 * @param gm graphics manager to perform 
 * drawing in the buffer.
 * @param maxIteration number of maximum iteration. It 
 * is recommended to use maximum 20 to prevent deep recursion. 
 * Never enter values lesser than zero.
 * @param offsideX origin for X axis.
 * @param offsideY origin for Y axis.
 */
Fractal::Fractal(
    GraphicsManager* gm, 
    int maxIteration, 
    int offsideX, 
    int offsideY
) {
    this->gm = gm;
    this->maxIteration = maxIteration;
    this->offsideX = offsideX;
    this->offsideY = offsideY;
};

/**
 * @brief Unfold and visualize the dragon curve
 * at the given iteration.
 * 
 * @param iteration number of iteration.
 * @param x1 line start X coordinate.
 * @param y1 line start Y coordinate.
 * @param x2 line end X coordinate.
 * @param y2 line end Y coordinate.
 * @param compressionX compression in X axis. Less than
 * 1.0f opens the fractal. Values more than 1.0f unfolds
 * the curve more to it's length.
 * @param compressionY compression in Y axis. Less than
 * 1.0f opens the fractal. Values more than 1.0f unfolds
 * the curve more to it's length.
 */
void Fractal::unfoldIteration(
    int iteration, 
    float x1, 
    float y1, 
    float x2, 
    float y2, 
    float compressionX, 
    float compressionY
) {
    if (iteration >= maxIteration) {
        gm->drawLine(
            sf::Vector2f(x1 + offsideX, y1 + offsideY),
            sf::Vector2f(x2 + offsideX, y2 + offsideY),
            sf::Color::Cyan
        );
    } else {
        float x3 = (x1 + x2) / 2.0 + (y2 - y1) / 2.0 / compressionX;
        float y3 = (y1 + y2) / 2.0 - (x2 - x1) / 2.0 / compressionY;
        unfoldIteration(iteration+1, x1, y1, x3, y3, compressionX, compressionY);
        unfoldIteration(iteration+1, x2, y2, x3, y3, compressionX, compressionY);
    }
};