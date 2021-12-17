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
        bool drawText(sf::Vector2f position, sf::Color color, int size, std::string text, std::string font);
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
        sf::Font font;
    public:
        Text(std::string string, sf::Vector2f position, sf::Color color, int size, std::string filePath);
        bool draw(sf::RenderWindow* window);
};

class Font {
    private:
        sf::Font font;
        std::string filePath;
    public:
        Font(std::string filePath);
        bool initialize();
        sf::Font getFont();
};

#endif