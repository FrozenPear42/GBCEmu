//
// Created by Wojciech on 11.08.2016.
//

#include "GameBoy.hpp"
#include <SFML/Window.hpp>

GameBoy::GameBoy(std::string pName) : mMemoryManager(),
                                      mWindow(sf::VideoMode(160, 144), pName),
                                      mCPU(mMemoryManager),
                                      mGPU(mMemoryManager, mWindow),
                                      mAudio(mMemoryManager) {
    mWindow.setFramerateLimit(60);
}

GameBoy::~GameBoy() {
    mWindow.close();
}

int GameBoy::tick() {
    if (!mWindow.isOpen())
        return 1;

    sf::Event event;
    while(mWindow.pollEvent(event)) {
        switch(event.type){
            case sf::Event::Closed:
                mWindow.close();
                return 1;
            default:
                break;
        }
    }

    mCPU.tick();
    mGPU.tick();
    //mCPU.log();
    return 0;
}
