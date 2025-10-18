#pragma once

class iVec2D {
public:
  int x;
  int y;

public:
  iVec2D() : x(0), y(0) {}
  iVec2D(int x_, int y_) : x(x_), y(y_) {}

  friend iVec2D operator+(const iVec2D &lhs, int rhs) {
    return iVec2D(lhs.x + rhs, lhs.y + rhs);
  }
  friend iVec2D operator+(int lhs, const iVec2D &rhs) { return rhs + lhs; }

  friend iVec2D operator-(const iVec2D &lhs, int rhs) {
    return iVec2D(lhs.x - rhs, lhs.y - rhs);
  }
};
