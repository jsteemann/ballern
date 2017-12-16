// ballern!
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " <filename>" << std::endl;
    std::exit(1);
  }
}
