#include <iostream>
#include "GameBoy.hpp"

using namespace std;

int main() {
    GameBoy boy;
    while(1)
    {
        //if(cin.get() == 'a') break;
        try {
            boy.tick();
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
    }
    return 0;
}