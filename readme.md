# Computation Theory Project
This repository contains the files elaborated for the purposes of the computation theory project

## Run
* Open a terminal and navigate to the project folder 
* Run the following commands
  -> bison -d -v -r all project_parser.y
  -> flex project_lexer.l
  -> gcc -o project_compiler lex.yy.c project_parser.tab.c cgen.c -lfl
* To parse a FL code file run: ./project_compiler < filename.fl

## Contents
* project_lexer.l -> flex file
* project_parser.y -> bison file
* project_compiler -> compiler executable file
* test.fl, test1.fl -> example FL files
* test.c, test1.c -> output C files

