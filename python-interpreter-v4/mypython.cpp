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

	int token; //gets the symbol number of token

	int storage_id = 0; 

	vector<Variable> vars;

	token = yylex(); //initializes the token search

	//while grabbing tokens determine what needs to be done
	while(token) {
		// switch case determining what we need to do
		// break up in to different header files and methods

		switch(token) {
			case 1:
				//when we have a print statement we need to
				//keep grabbing the next tokens and passing it
				//to the print function to create a string

				token = yylex(); //next token after print

				while(token) {
					if(token == 12) break;
					else if(token == 11) {
						//check the variable after the comma
						//and print out the value assigned to it

						token = yylex(); //gets the variable token

						for(int i = 0; i < vars.size(); i++) {
							if(vars[i].get_variable_name() == yytext) {
								cout << vars[i].get_value() << endl;
								break;
							}
						}
					}
					else if(token == 9) {

						for(int i = 0; i < vars.size(); i++) {
							if(vars[i].get_variable_name() == yytext) {
								cout << vars[i].get_value() << endl;
								break;
							}
						}

						token = yylex();
					}
					else {
						//print out anything thats in the string
						cout << yytext << " ";
						
						token = yylex();
					}
				}
				cout << endl;

				break;
			case 9: {
				//creates a new variable for every assignment
				//stores it into a vector of variables for
				//easier access and search
				Variable *newVar = new Variable;
				newVar->set_variable_name(yytext);
				newVar->set_storage_location_number(storage_id); storage_id++;
				token = yylex(); token = yylex();
				newVar->set_value(stoi(yytext));
				vars.push_back(*newVar);

				break;
			}
			default:
				break;
		}
		
		token = yylex(); //continue to get next token
	}

	return 0;
}