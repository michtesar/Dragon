#include <iostream>
#include <SFML/Graphics.hpp>
#include "graphics.h"

GraphicsManager::GraphicsManager(sf::RenderWindow* window) {
    this->window = window;
};

GraphicsManager::~GraphicsManager() {};

bool GraphicsManager::drawLine(
    sf::Vector2f p1, 
    sf::Vector2f p2, 
    sf::Color color
) {
    Line line = Line(p1, p2, color);
    line.draw(window);
    return true;
};

bool GraphicsManager::drawText(
    sf::Vector2f position, 
    sf::Color color, 
    int size, 
    std::string text, 
    std::string fontName
) {
    Text textLabel = Text(text, position, color, size, fontName);
    textLabel.draw(window);
    return true;
};

Line::Line(sf::Vector2f p1, sf::Vector2f p2, sf::Color color) {
    this->p1 = p1;
    this->p2 = p2;
    this->color = color;
};

bool Line::draw(sf::RenderWindow* window) {
    sf::Vertex vertices[] = {
        sf::Vertex(p1, color),
        sf::Vertex(p2, color)
    };
    window->draw(vertices, 2, sf::Lines);
    return true;
};

Text::Text(
    std::string string, 
    sf::Vector2f position, 
    sf::Color color, 
    int size, 
    std::string filePath
) {
    this->string = string;
    this->position = position;
    this->color = color;
    this->size = size;
    this->font = Font(filePath).getFont();
};

bool Text::draw(sf::RenderWindow* window) {
    sf::Text text;
    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(position);
    window->draw(text);
    return true;
};

Font::Font(std::string filePath) {
    this->filePath = filePath;
    initialize();
};

bool Font::initialize() {
    if (!this->font.loadFromFile(this->filePath)) {
        sf::err() << "Couldn't load font from" << filePath << "\n";
        return false;
    } else {
        std::cout << "Font loaded from " << filePath << std::endl;
        return true;
    }
};

sf::Font Font::getFont() {
    return font;
};
