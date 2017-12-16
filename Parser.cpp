// ballern!
#include "Parser.h"

using namespace ballern;

ParseResult Parser::parse() {
  buffer_ = code_.data();
  remainingLength_ = code_.size();

  if (Ballernlex_init(&scanner_) != 0) {
    throw std::string("out of memory");
  }

  Ballernset_extra(this, scanner_);
  if (Ballernparse(this)) {
    // generic parse error
    Ballernlex_destroy(scanner_);
    throw std::string("parse error");
  }

  // success!
  Ballernlex_destroy(scanner_);
  return result_;
}

void Parser::addToken(Token* token) {
  result_.startToken = token;
}
  
void Parser::registerParseError(char const* message, int line, int column) {
  std::string msg("parse error: ");
  msg += message;
  msg += " in line " + std::to_string(line) + ", column: " + std::to_string(column);
  throw msg;
}
