#pragma once

#include <array>
#include <cstdint>

class Neander {

  // VARIABLES
private:
  uint8_t _pc; // Program counter
  uint8_t _ac; // Accumulator

  // z: b0; n: b1
  uint8_t _flags;

public:
  std::array<uint8_t, 256> memory;

  enum Instruction {
    NOP = 0x00,
    STA = 0x10,
    LDA = 0x20,
    ADD = 0x30,
    OR = 0x40,
    AND = 0x50,
    NOT = 0x60,
    JMP = 0x80,
    JN = 0x90,
    JZ = 0xA0,
    HLT = 0xF0,
  };

  struct Mnemonic {
    Instruction inst;
    uint8_t value;
  };

  // METHODS
private:
  // Updates flash based on AC
  void _updateFlags();

  // Checks if instruction needs a second value
  bool _needsValue(Instruction);

  // Reads the position pointed by PC
  uint8_t _memRead();

  // Executes given mnemonic
  void _execute(Mnemonic);

public:
  Neander();

  // Does a single step of processing
  Mnemonic step();

  // Runs until reaches HLT or end of memory
  void run();

  // Resets the PC to 0
  void reset();

  // GETTERS / SETTERS
  uint8_t getAC();
  void setAC(uint8_t);

  uint8_t getPC();
  void setPC(uint8_t);

  bool getNegative();
  bool getZero();
};
