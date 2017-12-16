// ballern!
#pragma once

#include <string>
#include <cstring>

namespace ballern {
struct Token;

struct ParseResult {
  Token* startToken;
};

class Parser {
 public: 
  Parser(std::string const& code) : code_(code), scanner_(nullptr), buffer_(nullptr), remainingLength_(0) {}
  Parser(std::string&& code) : code_(std::move(code)), scanner_(nullptr), buffer_(nullptr), remainingLength_(0) {}
  ~Parser() {}

  ParseResult parse();
  
  void* scanner() const { return scanner_; }
  size_t remainingLength() const { return remainingLength_; }
  
  void addToken(Token* token);
  
  void fillBuffer(char* result, size_t length) {
    memcpy(result, buffer_, length);
    buffer_ += length;
    remainingLength_ -= length;
  }

  void registerParseError(char const* message, int line, int column);

 private:
  std::string const code_; 
  
  void* scanner_;
  
  char const* buffer_;
  
  size_t remainingLength_;

  ParseResult result_;
};

}

// forward for the parse function provided by the parser (.y)
int Ballernparse(ballern::Parser*);

// forward for the init function provided by the lexer (.l)
int Ballernlex_init(void**);

// forward for the shutdown function provided by the lexer (.l)
int Ballernlex_destroy(void*);

// forward for the context function provided by the lexer (.l)
void Ballernset_extra(ballern::Parser*, void*);
