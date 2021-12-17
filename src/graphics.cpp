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
#include <iostream>
#include <SFML/Graphics.hpp>
#include "graphics.h"

/**
 * @brief Construct a new Graphics Manager:: Graphics Manager object
 * It is a helper class holding all objects that can
 * be rendered on the window.
 * 
 * @param window which window is going to be used for rending.
 */
GraphicsManager::GraphicsManager(sf::RenderWindow* window) {
    this->window = window;
};

/**
 * @brief Destroy the Graphics Manager:: Graphics Manager object
 * TODO: Consider implementation of removing memeber method.
 */
GraphicsManager::~GraphicsManager() {};

/**
 * @brief High-level class drawing the line.
 * 
 * @param p1 starting point of `sf::Vector2f`.
 * @param p2 ending point of `sf::Vector2f`.
 * @param color color of each vertex.
 * @return boolean whether it was successful or not.
 */
bool GraphicsManager::drawLine(
    sf::Vector2f p1, 
    sf::Vector2f p2, 
    sf::Color color
) {
    Line line = Line(p1, p2, color);
    line.draw(window);
    return true;
};

/**
 * @brief High-level class drawing the text.
 * 
 * @param position text position of the top 
 * left corner of the bounding box.
 * @param color color of the text.
 * @param size font size in pixels.
 * @param text actual text to show.
 * @param font font representation. `SFML` does
 * not come with any default font. Preload the 
 * font before the main loop for optimal performance.
 * @return boolean whether it was successful or not. 
 */
// TODO: Implement centering text vertically and horizontally
bool GraphicsManager::drawText(
    sf::Vector2f position, 
    sf::Color color, 
    int size, 
    std::string text, 
    sf::Font* font
) {
    Text textLabel = Text(text, position, color, size, font);
    textLabel.draw(window);
    return true;
};

/**
 * @brief Construct a new Line:: Line object
 * 
 * @param p1 starting point of `sf::Vector2f`.
 * @param p2 ending point of `sf::Vector2f`.
 * @param color color of all line vertex.
 */
Line::Line(sf::Vector2f p1, sf::Vector2f p2, sf::Color color) {
    this->p1 = p1;
    this->p2 = p2;
    this->color = color;
};

/**
 * @brief Draw line member method
 * 
 * @param window to which window to draw.
 * @return boolean whether it was successful or not.
 */
bool Line::draw(sf::RenderWindow* window) {
    sf::Vertex vertices[] = {
        sf::Vertex(p1, color),
        sf::Vertex(p2, color)
    };
    window->draw(vertices, 2, sf::Lines);
    return true;
};

/**
 * @brief Construct a new Text:: Text object
 * 
 * @param string actual text to show.
 * @param position position of the text. Position
 * starts in top left corner of the bounding box.
 * @param color color of the text.
 * @param size font size on pixels.
 * @param font font representation. `SFML` does not
 * come with any default fonts, you have to load one,
 * ideally before the main loop starts.
 */
Text::Text(
    std::string string, 
    sf::Vector2f position, 
    sf::Color color, 
    int size, 
    sf::Font* font
) {
    this->string = string;
    this->position = position;
    this->color = color;
    this->size = size;
    this->font = font;
};

/**
 * @brief Main text draw memeber method
 * 
 * @param window to which window to draw.
 * @return boolean whether it was successful or not.
 */
bool Text::draw(sf::RenderWindow* window) {
    sf::Text text;
    text.setFont(*font);
    text.setString(string);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(position);
    window->draw(text);
    return true;
};

/**
 * @brief Construct a new Font:: Font object
 * 
 * @param filePath absolute/relative path to the 
 * `ttf` file. Most of the common font types are
 * supported. For details see `sf::Font` documentation
 * of `SFML`. TrueType font are recommended.
 */
Font::Font(std::string filePath) {
    this->filePath = filePath;
    initialize();
};

/**
 * @brief Initializing and loading the font
 * Font is going to be search in the same directory
 * where the executable its.
 * 
 * @return boolean whether it was successful or not.
 */
bool Font::initialize() {
    if (!this->font.loadFromFile(this->filePath)) {
        sf::err() << "Couldn't load font from" << filePath << "\n";
        return false;
    } else {
        return true;
    }
};
