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
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @brief Keyboard event processor
 * Process the keypresses in the curren
 * window.
 */
class KeyboardProcessor {
    public:
        void process(
            int* iteration, 
            float* compression, 
            float* compressionStep, 
            int* maxIteration, 
            sf::RenderWindow* window
        );
        void closeWindow();
};

/**
 * @brief Main keyboard processor memeber method
 * 
 * @param iteration current frame iteration.
 * @param compression current frame compression.
 * @param compressionStep compression step to be used.
 * @param maxIteration maximum number of allowed iterations.
 * @param window which window emits and reciev the events.
 */
void KeyboardProcessor::process(
    int* iteration, 
    float* compression, 
    float* compressionStep, 
    int* maxIteration, 
    sf::RenderWindow* window
) {
    // Close window
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window->close();
    }
    // Previous iteration
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (*iteration > 0) {
            *iteration -= 1;
        }
    }
    // Next iteration
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (*iteration < *maxIteration) {
            *iteration += 1;
        }
    }
    // Raise compression
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (*compression < 2.0) {
            *compression += *compressionStep;
        }
    }
    // Lower compression
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (*compression > 1.0) {
            *compression -= *compressionStep;
        }
    }
    // Reset view
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        *compression = 1.0f;
        *iteration = 0;
    }
}

#endif