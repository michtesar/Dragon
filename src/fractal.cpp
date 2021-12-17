#include "fractal.h"
#include <SFML/Graphics.hpp>

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