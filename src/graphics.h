#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GraphicsManager {
    private:
        sf::RenderWindow* window;
    public:
        GraphicsManager(sf::RenderWindow* window);
        ~GraphicsManager();
        bool drawLine(sf::Vector2f p1, sf::Vector2f p2, sf::Color color);
        bool drawText(sf::Vector2f position, sf::Color color, int size, std::string text, sf::Font* font);
};

class Line {
    private:
        sf::Vector2f p1;
        sf::Vector2f p2;
        sf::Color color;
    public:
        Line(sf::Vector2f p1, sf::Vector2f p2, sf::Color color);
        bool draw(sf::RenderWindow* window);
};

class Text {
    private:
        sf::Vector2f position;
        sf::Color color;
        int size;
        std::string string;
        sf::Font* font;
    public:
        Text(std::string string, sf::Vector2f position, sf::Color color, int size, sf::Font* font);
        bool draw(sf::RenderWindow* window);
};

class Font {
    private:
        std::string filePath;
    public:
        sf::Font font;
        Font(std::string filePath);
        bool initialize();
};

#endif