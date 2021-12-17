#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>

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