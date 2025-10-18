#include "npanel.hpp"

NPanel::NPanel(iVec2D topLeft, iVec2D bottomRight)
    : _tl(topLeft), _br(bottomRight) {}

void NPanel::setTopLeft(iVec2D tl) {
  _tl = tl;
  refresh();
}

void NPanel::setTopLeft(int x, int y) {
  _tl = iVec2D(x, y);
  refresh();
}

void NPanel::setBottomRight(iVec2D br) {
  _br = br;
  refresh();
}
void NPanel::setBottomRight(int x, int y) {
  _br = iVec2D(x, y);
  refresh();
}

iVec2D NPanel::getTopLeft() { return _tl; }
iVec2D NPanel::getBottomRight() { return _br; }
