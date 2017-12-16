%define api.pure
%name-prefix "Ballern"
%locations 
%defines
%parse-param { ballern::Parser* parser }
%lex-param { void* scanner } 
%error-verbose

%{
#include "Parser.h"
#include "Token.h"
%}

%union {
ballern::Token* token;
}

%{

using namespace ballern;

#define scanner parser->scanner()

// forward
int Ballernlex(YYSTYPE*, YYLTYPE*, void*);

// error callback
void Ballernerror(YYLTYPE* locp, ballern::Parser* parser, char const* message) {
  parser->registerParseError(message, locp->first_line, locp->first_column);
}

%}

%token T_BALLERN "BALLERN!"

%token T_END 0 "end of script"

/* start token */
%start script

%%

script:
    T_BALLERN {
      parser->addToken(new BallernToken());
    }
  ;
