#include <iostream>
#include "CPU.hpp"

using namespace std;

int main() {
    CPU cpu;
    while(1)
    {
        if(cin.get() == 'a') break;
        cpu.tick();
        cpu.log();
    }
    return 0;
}