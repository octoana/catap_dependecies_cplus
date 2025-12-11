#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(400, 300)), "SFML + SQLite3 Demo");
    sf::Font font;

    if (font.openFromFile("arial.ttf")) { // SFML 3.x uses openFromFile
        sf::Text text(font, "Hello, world!", 30); // SFML 3.x constructor requires font
        text.setPosition(sf::Vector2f(60.f, 120.f)); // SFML 3.x requires Vector2f

        while (window.isOpen()) {
            while (auto event = window.pollEvent()) {
                if (event->getType() == sf::Event::Closed)
                    window.close();
            }
    
            window.clear();
            window.draw(text);
            window.display();
        }
    }
    return 0;
}
