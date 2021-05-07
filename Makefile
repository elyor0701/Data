All: data.exe
data.exe: main.o date.o database.o node.o condition_parser.o condition_parser_test.o token.o
	g++ -g main.o date.o database.o node.o condition_parser.o condition_parser_test.o token.o -Wall -Wextra -o data.exe
main.o: main.cpp
	g++ -c main.cpp -ggdb
date.o: date.cpp
	g++ -c date.cpp -ggdb
database.o: database.cpp
	g++ -c database.cpp -ggdb
node.o: node.cpp
	g++ -c node.cpp -ggdb
condition_parser.o: condition_parser.cpp
	g++ -c condition_parser.cpp -ggdb
condition_parser_test.o: condition_parser_test.cpp
	g++ -c condition_parser_test.cpp -ggdb
token.o: token.cpp
	g++ -c token.cpp -ggdb
