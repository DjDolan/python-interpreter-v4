#include <iostream>
#include <fstream>
#include <vector>
#include "variable.h"

using namespace std;

/*
* create symbol table of tokens
* create tokenizer method for scanning
* create syntax tree according to tokens
* perform actions depending on syntax
* parse the syntax through analysis
* check for delimeters and special characters
* have specific way to store info
*/

extern int yylex();
extern int yylineno;
extern char* yytext;

int main() {

	Variable var1("Charles", 123, 321);

	cout << var1.get_variable_name() << endl;

	// int token; //gets the symbol number of token

	// token = yylex(); //initializes the token search

	// //while grabbing tokens determine what needs to be done
	// while(token) {
	// 	// switch case determining what we need to do
	// 	// break up in to different header files and methods

	// 	switch(token) {
	// 		case 1:
	// 			//when we have a print statement we need to
	// 			//keep grabbing the next tokens and passing it
	// 			//to the print function to create a string

	// 			token = yylex(); //next token after print

	// 			while(token) {
	// 				if(token == 12) break;
	// 				else if(token == 11) {
	// 					//check the variable after the comma
	// 					//and print out the value assigned to it
	// 					token = yylex();
	// 				}
	// 				else {
	// 					//print out anything thats an
	// 					cout << yytext << " ";
	// 					token = yylex();
	// 				}
	// 			}
	// 			cout << endl;

	// 			break;
	// 		case 9:
	// 			cout << "Variable Declared [" << yytext << "]" << "\tStored to location [" << yylineno << "]" << endl;
	// 			break;
	// 		default:
	// 			break;
	// 	}
		
	// 	token = yylex(); //continue to get next token
	// }

	// cout << endl;

	return 0;
}