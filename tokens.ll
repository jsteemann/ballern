%option reentrant
%option 8bit
%option prefix="Ballern"
%option bison-locations
%option bison-bridge
%option yylineno
%option noyywrap nounput batch

%{
namespace ballern { class Parser; }

#include "Parser.h"
#include "Token.h"
#include "grammar.hpp"

#define YY_EXTRA_TYPE ballern::Parser*

/* properly update location counters */
#define YY_USER_ACTION                                                   \
  yylloc->first_line = static_cast<int>(yylineno);                       \
  yylloc->first_column = static_cast<int>(yycolumn);                     \
  yylloc->last_column = static_cast<int>(yycolumn + yyleng - 1);         \
  yycolumn += static_cast<int>(yyleng);                                  

/* override default input */
#define YY_NO_INPUT 1

#define YY_INPUT(resultBuffer, resultState, maxBytesToRead) {            \
  size_t length = yyextra->remainingLength();                            \
  if (length > static_cast<size_t>(maxBytesToRead)) {                    \
    length = static_cast<size_t>(maxBytesToRead);                        \
  }                                                                      \
  if (length > 0) {                                                      \
    yyextra->fillBuffer(resultBuffer, length);                           \
    resultState = length;                                                \
  } else {                                                               \
    resultState = YY_NULL;                                               \
  }                                                                      \
}
%}

%%

(?i:ballern) {
  return T_BALLERN;
}

[ \t\r]+ {
  /* ignore whitespace */
}

[\n] {
  /* properly handle line number changes for LFs */
  yycolumn = 0;
}

. {
  /* everything else is returned as it is, so it is not printed */
  return static_cast<int>(yytext[0]);
}
 
%%
