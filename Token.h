// ballern!
#pragma once

#include <iostream>

namespace ballern {

struct Token {
 protected:
  Token() {}
  virtual ~Token() {}

 public:
  virtual void execute() = 0;
};

struct BallernToken : public Token {
  BallernToken() {}

  void execute() override {
    std::cout << "BALLERN!" << std::endl;
  }
};

}
