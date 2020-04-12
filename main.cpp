// Copyright 2020 Adam Tremblay

#include <iostream>
#include <string>
#include <SFML/System.hpp>
#include "ED.hpp"

int main() {
    sf::Clock clock;
    sf::Time t;

    std::string s1;
    std::string s2;
    std::string alignment;

    std::cin >> s1;
    std::cin >> s2;

    ED ed(s1, s2);
    std::cout << "Edit distance = " << ed.optDistance() << std::endl;
    alignment = ed.alignment();

    std::cout << alignment << std::endl;

    t = clock.getElapsedTime();
    std::cout << "Execution time is ";
    std::cout << t.asSeconds() << " seconds \n" << std::endl;

    return 0;
}
