// ballern!
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "Parser.h"

using namespace ballern;
  
static std::string readInputFile(char const* filename) {
  std::ifstream ifs(filename, std::ifstream::in);
  
  if (!ifs.is_open()) {
    throw std::string("cannot read input file '") + filename + "'";
  }
  
  std::string result;
  char buffer[32768];
  result.reserve(sizeof(buffer));

  while (ifs.good()) {
    ifs.read(&buffer[0], sizeof(buffer));
    result.append(buffer, ifs.gcount());
  }
  ifs.close();
 
  return result;
}

int main(int argc, char* argv[]) {
  try {
    if (argc < 2) {
      throw std::string("usage: ") + argv[0] + " <filename>";
    }

    char const* infile = argv[1];
    if (::strcmp(infile, "-") == 0) {
      // read from pipe hack
      infile = "/proc/self/fd/0";
    }

    std::string code = readInputFile(infile);
    std::cout << "gotta parse this code soon: " << code << std::endl;
    Parser p(std::move(code));
    p.parse();
  } catch (std::string const& ex) {
    std::cerr << ex << std::endl;
    return 1;
  }
}
