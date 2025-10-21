#include "neander_app.hpp"
#include <chrono>
#include <iomanip>
#include <ncurses.h>
#include <sstream>
#include <string>
#include <thread>

const int FOOTER_HEIGHT = 3;
bool hex = false;

void run(Neander &neander) {
  initscr();

  WINDOW *footer = makeFooter();
  WINDOW *addressList = makeAddressList(neander);

  std::this_thread::sleep_for(std::chrono::milliseconds(5000));

  endwin();
}

WINDOW *makeAddressList(Neander &neander) {
  const int WIDTH = 18;
  WINDOW *addressList = newwin(LINES - FOOTER_HEIGHT, WIDTH, 0, 0);
  box(addressList, 0, 0);

  // Address list header
  if (hex)
    mvwprintw(addressList, 1, 1, " pc|addr|value ");
  else
    mvwprintw(addressList, 1, 1, " pc|addre|value ");

  // Prints all lines that fit
  // -FOOTER_HEIGHT to account for the footer
  // -3 to account for header, bottom edge and footer edge
  for (int i = 0; i < LINES - FOOTER_HEIGHT - 3; i++) {
    // Makes indicator for the program counter
    std::string line = "";
    if (i == neander.getPC()) {
      line.append("  *| ");
    } else {
      line.append("   | ");
    }

    // Adds the address 3 chars long
    std::ostringstream address;
    address << std::right << std::setfill('0') << std::setw(3);
    if (hex)
      address << std::hex << std::uppercase << std::setw(2);
    address << i;
    line.append(address.str());

    line.append(" | ");

    // Adds the value 3 chars long
    std::ostringstream value;
    value << std::right << std::setfill('0') << std::setw(3);
    if (hex)
      value << std::hex << std::uppercase << std::setw(2);
    value << int(neander.memory[i]);
    line.append(value.str());

    // Prints the line built
    mvwprintw(addressList, i + 2, 1, line.c_str());
  }

  wrefresh(addressList);
  return addressList;
}

WINDOW *makeFooter() {
  WINDOW *footer = newwin(FOOTER_HEIGHT, COLS, LINES - FOOTER_HEIGHT, 0);
  box(footer, 0, 0);

  mvwprintw(footer, 1, 1,
            "F8: Step    F9: Run    F10: Clear PC  |  ^A: Set Accumulator    "
            "^P: Set PC  |  ga: Goto Address    gd: "
            "Goto Data  |  h: help");

  wrefresh(footer);
  return footer;
}
