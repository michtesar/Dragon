// About DC https://www.instructables.com/Dragon-Curve-Using-Python/
#include <SFML/Graphics.hpp>
#include "graphics.h"
#include "bundle.h"
#include "fractal.h"
#include "version.h"
#include "config.h"
#include "keyboard.h"
#include "events.h"

int main(int argc, char *argv[]) {
    // Initialize bundle and fonts before opening window
    Bundle bundle = Bundle(argv[0]);
    Font fontDejaVuSans = Font(bundle.getBundleAsset(FONT_DEJAVU_SANS));
    
    // Create a main window
    sf::ContextSettings settings;
    settings.antialiasingLevel = ANTIALIASING;
    std::string version = "v" + 
        std::to_string(DRAGON_VERSION_MAJOR) + "." + 
        std::to_string(DRAGON_VERSION_MINOR) + "." + 
        std::to_string(DRAGON_VERSION_PATCH);
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGTH), 
        "Dragon Curve " + version, 
        sf::Style::Default, 
        settings
    );
    int iteration = 0;
    float compression = 1.0f;

    // Create a grpahics manager for drawing on window    
    GraphicsManager gm = GraphicsManager(&window);

    // Initialize the fractal engine
    Fractal fractal = Fractal(&gm, 15, 450, 650);
    
    // Inititalize keyboard and event system
    KeyboardProcessor keyboardProcessor;
    EventProcessor eventsProcessor;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            keyboardProcessor.process(
                &iteration, 
                &compression, 
                &fractal.compressionStep,
                &fractal.maxIteration, 
                &window
            );
            eventsProcessor.process(&event, &window);
        }

        window.clear(sf::Color(25, 25, 25, 255));

        fractal.unfoldIteration(15-iteration, 0, 0, 800, 0, compression, compression);

        gm.drawText(
            sf::Vector2f(200, 1050),
            sf::Color(255, 255, 255, 255),
            52,
            "Iteration " + std::to_string(iteration),
            &fontDejaVuSans.font
        );
        gm.drawText(
            sf::Vector2f(1000, 1050),
            sf::Color(255, 255, 255, 255),
            52,
            "Compression " + std::to_string(int(compression*100)-100),
            &fontDejaVuSans.font
        );

        window.display();
    }
    return 0;
}