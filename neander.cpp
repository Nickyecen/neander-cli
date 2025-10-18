#include "neander.hpp"
#include <cstdint>

Neander::Neander() : _pc(0), _ac(0), _bp(255) {
  memory.fill(0);
  _updateFlags();
}

void Neander::_updateFlags() {
  _flags = 0;
  _flags |= _ac == 0;            // 00000001
  _flags |= ((_ac & 0x80) >> 6); // 00000010
}

bool Neander::_needsValue(Neander::Instruction inst) {
  switch (inst) {
  case NOP:
  case NOT:
  case HLT:
    return false;

  default:
    return true;
  }
}

uint8_t Neander::_memRead() { return memory[_pc++]; }

void Neander::_execute(Neander::Mnemonic mn) {
  switch (mn.inst) {
  case STA:
    memory[mn.value] = _ac;
    break;
  case LDA:
    setAC(memory[mn.value]);
    break;
  case ADD:

    setAC(_ac + memory[mn.value]);
    break;
  case OR:
    setAC(_ac | memory[mn.value]);
    break;
  case AND:
    setAC(_ac & memory[mn.value]);
    break;
  case NOT:
    setAC(~_ac);
    break;
  case JMP:
    _pc = mn.value;
    break;
  case JN:
    if (getNegative())
      _pc = mn.value;
    break;
  case JZ:
    if (getZero())
      _pc = mn.value;
    break;
  case HLT:
  case NOP:
    break;
  }
}

void Neander::run() {
  Mnemonic mn = {NOP, 0};
  while (_pc < _bp && mn.inst != HLT) {
    mn = step();
  }
}

void Neander::reset() { setPC(0); }

Neander::Mnemonic Neander::step() {
  Instruction inst = Instruction(_memRead() & 0xF0); // Gets first 4 bits
  uint8_t value;

  if (_needsValue(inst)) {
    value = _memRead();
  }

  Mnemonic mn = {inst, value};

  // Executes mnemonic
  _execute(mn);

  return mn;
}

// GETTERS / SETTERS
uint8_t Neander::getAC() { return _ac; }
void Neander::setAC(uint8_t byte) {
  _ac = byte;
  _updateFlags();
}

uint8_t Neander::getPC() { return _pc; }
void Neander::setPC(uint8_t byte) { _pc = byte; }

uint8_t Neander::getBP() { return _bp; }
void Neander::setBP(uint8_t byte) { _bp = byte; }

bool Neander::getZero() { return (_flags & 0x01); }
bool Neander::getNegative() { return (_flags & 0x02); }
