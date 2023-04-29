#include <iostream>

#include "src/Chip.h"

int main() {

    auto chip = Chip8();

    std::cout << chip.randByte.max() << std::endl;
    std::cout << chip.randGen << std::endl;

    return 0;
}
