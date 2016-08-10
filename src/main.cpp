#include <iostream>
#include "CPU.hpp"

using namespace std;

int main() {
    CPU cpu;
    while(1)
    {
        //if(cin.get() == 'a') break;
        try {
            cpu.tick();
        } catch(std::string e) {
            std::cout << "ERROR: " << e << "\n";
            break;
        }
        catch(const char* e) {
            std::cout << "ERROR: " << e << "\n";
            break;
        }
        catch(...) {
            std::cout << "ERROR" << "\n";
            break;
        }
        cpu.log();
    }
    return 0;
}