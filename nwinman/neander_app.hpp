#pragma once
#include "../neander.hpp"
#include <ncurses.h>

WINDOW *makeFooter();
WINDOW *makeAddressList(Neander &neander);
void run(Neander &neander);
