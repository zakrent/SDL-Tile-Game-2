//
// Created by zakrent on 4/18/17.
//

#ifndef SDL_TILE_2_RANDOM_H
#define SDL_TILE_2_RANDOM_H

#include <random>

namespace Random{
    std::random_device generator;

    int randomInt(int _min, int _max){
        int min = _min;
        int max = _max;
        std::uniform_int_distribution<int> intDistribution(min,max);
        return intDistribution(generator);
    }


}


#endif //SDL_TILE_2_RANDOM_H
