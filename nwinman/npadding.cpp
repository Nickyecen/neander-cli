#include "npadding.hpp"

NPadding::NPadding(int size, NPanel &panel) : _size(size), _panel(panel) {
  refresh();
}

void NPadding::refresh() {
  _panel.setTopLeft(_tl + _size);
  _panel.setBottomRight(_br - _size);
  _panel.refresh();
}
