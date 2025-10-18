#pragma once

#include "../vector.hpp"
#include <ncurses.h>

class NPanel {
protected:
  iVec2D _tl;
  iVec2D _br;

public:
  NPanel(iVec2D topLeft, iVec2D bottomRight);
  NPanel();

  virtual void refresh() = 0;

  void setTopLeft(iVec2D tl);
  void setTopLeft(int x, int y);
  void setBottomRight(iVec2D br);
  void setBottomRight(int x, int y);

  iVec2D getTopLeft();
  iVec2D getBottomRight();
};
