#include <sqlite3.h>
#include <SFML/Graphics.hpp>
#include <openssl/ssl.h>
#include <openssl/err.h>
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

    // Test OpenSSL
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    std::cout << "OpenSSL version: " << OpenSSL_version(OPENSSL_VERSION) << "\n";

    // Test SFML 3.0
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML + SQLite3 + OpenSSL Test");
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
