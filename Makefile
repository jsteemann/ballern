all:
	flex -L -otokens.cpp tokens.ll
	bison -d -ra --warnings=deprecated,other,error=conflicts-sr,error=conflicts-rr -o grammar.cpp grammar.y
	$(CXX) -g -Wall -Wextra -std=c++17 tokens.cpp grammar.cpp Parser.cpp ballern.cpp
