#pragma once

#include "npanel.hpp"

class NPadding : public NPanel {
private:
  NPanel &_panel;
  int _size;

public:
  NPadding(int size, NPanel &panel);

  virtual void refresh() override;
};
