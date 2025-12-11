#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    // SFML 3.x: VideoMode expects sf::Vector2u, not two ints
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(400, 300)), "SFML + SQLite3 Demo");

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) // Place arial.ttf in the repo root or use another font
        return 1;

    // SFML 3.x: Text(font, string, size)
    sf::Text text(font, "Hello, world!", 30);
    text.setPosition(sf::Vector2f(60.f, 120.f));

    while (window.isOpen())
    {
        // SFML 3.x: pollEvent returns std::optional<Event>
        while (auto event = window.pollEvent())
        {
            // SFML 3.x event system: each event is a variant, use std::holds_alternative or pattern matching
            if (std::holds_alternative<sf::Event::Closed>(*event))
                window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }
    return 0;
}
