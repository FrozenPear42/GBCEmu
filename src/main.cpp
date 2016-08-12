#include <iostream>
#include <chrono>
#include <iomanip>
#include "GameBoy.hpp"

using namespace std;

int main() {
//    std::chrono::time_point<std::chrono::system_clock> start, end;
//    start = std::chrono::system_clock::now();
//    end = std::chrono::system_clock::now();

    GameBoy boy("GBC");
    while (1) {


        try {
//            start = std::chrono::system_clock::now();
            if (boy.tick()) break;
//            end = std::chrono::system_clock::now();
//            std::chrono::duration<double> time = end - start;
//            std::cout << "Time: " << std::setprecision(32) << time.count() << endl;
        } catch (std::string e) {
            std::cout << "ERROR: " << e << "\n";
            break;
        }
        catch (const char* e) {
            std::cout << "ERROR: " << e << "\n";
            break;
        }
        catch (...) {
            std::cout << "ERROR" << "\n";
            break;
        }
    }
    return 0;
}