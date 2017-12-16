// ballern!
#pragma once

#include <string>

namespace ballern {

struct ParseResult {
};

class Parser {
 public: 
  Parser(std::string const& code) : code_(code) {}
  Parser(std::string&& code) : code_(std::move(code)) {}
  ~Parser() {}

  ParseResult parse();

 private:
  std::string const code_; 
};

}
