// Sytem Header
#include <chrono>
#include <cstring>
#include <fstream>
#include <ios>
#include <random>
#include <sys/types.h>

// Project Header
#include "Chip.h"

//-----------------------------------------------------------------------------
Chip8::Chip8()
    : randGen(std::chrono::system_clock::now().time_since_epoch().count()) {
  pc = START_ADDRESS;

  for (uint i = 0; i < FONTSET_SIZE; ++i) {
    memory[FONTSET_START_ADDRESS + i] = fontset[i];
  }


  // Initialize RNG
  randByte = std::uniform_int_distribution<uint8_t>(0, 255U);
}

//-----------------------------------------------------------------------------
void Chip8::loadROM(char const *filename) {
  std::ifstream file(filename, std::ios::binary | std::ios::ate);

  if (file.is_open()) {
    // Get size of file and allocate a buffer to hold contents
    std::streampos size = file.tellg();
    char *buffer = new char[size];

    // Go back to the beginning of the file and fill the buffer
    file.seekg(0, std::ios::beg);
    file.read(buffer, size);
    file.close();

    // Load the ROM contents into the Chip8's memory, starting at 0x200
    for (long i = 0; i < size; ++i) {
      memory[START_ADDRESS + i] = buffer[i];
    }

    delete[] buffer;
  }
}

//-----------------------------------------------------------------------------
void Chip8::OP_00E0()
{
    memset(video, 0, sizeof(video));
}

//-----------------------------------------------------------------------------
void Chip8::OP_00EE()
{
    --sp;
    pc = stack[sp];
}


//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------









