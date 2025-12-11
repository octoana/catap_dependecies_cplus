#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    // SFML 3.x: VideoMode expects sf::Vector2u, not two integers
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(400, 300)), "SFML + SQLite3 Demo");

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) // openFromFile replaces loadFromFile
        return 1;

    // SFML 3.x: Text must be constructed with a font
    sf::Text text("Hello, world!", font, 30);
    text.setPosition(sf::Vector2f(60.f, 120.f)); // must use Vector2f

    while (window.isOpen())
    {
        // SFML 3.x: pollEvent() returns std::optional<sf::Event>
        while (auto event = window.pollEvent())
        {
            // SFML 3.x: event is a value, has 'type' member (NOT getType())
            if (event->type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }
    return 0;
}
