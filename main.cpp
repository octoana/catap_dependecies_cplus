#include <sqlite3.h>
#include <iostream>
// ... inside main()
sqlite3* DB;
if (sqlite3_open(":memory:", &DB) == SQLITE_OK)
    std::cout << "SQLite3 Ready!\n";
else
    std::cerr << "SQLite3 ERROR\n";
sqlite3_close(DB);
