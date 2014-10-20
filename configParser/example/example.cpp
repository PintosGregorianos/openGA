#include "configParser.hpp"
#include <string>
#include <iostream>

int main() {
    // Creates the parser and parse the "example.txt" file
        configParser::Parser file;
        file.parseFromFile("example.txt");

    // Read data
        bool foda  = false;
        bool ungry = false;

        unsigned int year;
        unsigned int how_many;

        float month;

        std::string name;

        file.read("they-are-foda",    foda);
        file.read("ungrys",          ungry);
        file.read("year",             year);
        file.read("how_many",     how_many);
        file.read("month",           month);
        file.read("name",             name);

    // Show parsed data on screen.
        std::cout << "they-are-foda: " << foda << std::endl;
        std::cout << "ungrys: "        << ungry << std::endl;
        std::cout << "year: "          << year << std::endl;
        std::cout << "how many: "      << how_many << std::endl;
        std::cout << "month:         " << month << std::endl;
        std::cout << "name: "          << name << std::endl;

    // modifie the year
        file.write("year", (unsigned int)2043);

    // add a new paramenter
        file.write("Silvio-Santos",std::string("MA OEEEE"));

    // write the data to a new file
        file.writeToFile("example2.txt");

    return 0;
}
