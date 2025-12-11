#include <sqlite3.h>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Test SQLite3
    sqlite3* DB;
    if (sqlite3_open(":memory:", &DB) == SQLITE_OK) {
        std::cout << "SQLite3 Ready!\n";
    } else {
        std::cerr << "SQLite3 ERROR\n";
        return 1;
    }
    sqlite3_close(DB);

    // Test SFML 3.0
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML + SQLite3 Test");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    std::cout << "SFML window created successfully!\n";

    while (window.isOpen()) {
        // SFML 3.0 uses std::optional for event polling
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
