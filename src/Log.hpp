//
// Created by Wojciech on 11.08.2016.
//

#ifndef GBCEMU_LOG_HPP
#define GBCEMU_LOG_HPP


#include <string>
#include <iostream>

class Log {
public:
    static void i(std::string pMessage) {
        std::cout << "[INFO] " << pMessage << "\n";
    };

    static void i(const char* pMessage) {
        std::cout << "[INFO] " << pMessage << "\n";
    };

    static void i(char* pMessage) {
        std::cout << "[INFO] " << pMessage << "\n";
    };

};


#endif //GBCEMU_LOG_HPP
