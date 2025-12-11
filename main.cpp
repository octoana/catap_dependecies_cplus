#include <SFML/Graphics.hpp>
#include <sqlite3.h>
#include <iostream>

int main() {
    // 1. SFML: Simple window
    sf::RenderWindow window(sf::VideoMode(400, 300), "SFML + SQLite3 Demo");
    sf::Font font;
    sf::Text text;

    // Can try to load a default font (on Linux use /usr/share/fonts)
    if (font.loadFromFile("arial.ttf")) {
        text.setFont(font);
        text.setString("SFML + SQLite3!");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(60, 120);
    }

    // 2. SQLite3: Simple in-memory query
    sqlite3 *db = nullptr;
    char *errmsg = nullptr;
    if (sqlite3_open(":memory:", &db) == SQLITE_OK) {
        std::cout << "SQLite3 (memory DB) opened successfully.\n";
        const char *sql = "CREATE TABLE test(val TEXT); INSERT INTO test(val) VALUES('Hello, SQLite3!');";
        if (sqlite3_exec(db, sql, 0, 0, &errmsg) == SQLITE_OK) {
            std::cout << "Table created and value inserted.\n";
        }

        sqlite3_stmt *stmt;
        if (sqlite3_prepare_v2(db, "SELECT val FROM test;", -1, &stmt, 0) == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                const char *val = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
                std::cout << "Database value: " << val << std::endl;
            }
            sqlite3_finalize(stmt);
        }
        sqlite3_close(db);
    } else {
        std::cerr << "Failed to open SQLite3 DB: " << sqlite3_errmsg(db) << std::endl;
    }

    // SFML window loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        if (font.getInfo().family != "") window.draw(text);
        window.display();
    }

    return 0;
}
