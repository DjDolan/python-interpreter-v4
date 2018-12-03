#include <iostream>
#include <fstream>
#include <vector>
#include "variable.h"
#include "ifstatements.h"

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
	int if_counter = -1;
	int else_counter = -1;
	int storage_id = 0;

	vector<Variable> vars;

	token = yylex(); //initializes the token search

	//while grabbing tokens determine what needs to be done
	while(token) {
		// switch case determining what we need to do
		switch(token) {
			//PRINT
			case 1:
				//when we have a print statement we need to
				//keep grabbing the next tokens and passing it
				//to the print function to create a string

				token = yylex(); //next token after print

				while(token) {
					if(token == 13) break;
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
						//if its an identifier
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

				break;
			//COMMENT
			case 12:
				//if is a comment skip entire line
				token = yylex();
					
				//loops through tokens until EOL
				while(token) {
					if(token == 13) break;
					else token = yylex();
				}

				break;
			//IF STATEMENT - ELSE STATEMENT
			case 3: {
				vector<string> if_block;
				string line;

				//get initial conditon
				while(token) {
					if(token == 13) {
						if_block.push_back(line);
						line = "";
						break;
					}
					line += yytext;
					token = yylex();
				}
				token = yylex();
				//get the rest of the block
				while(token) {
					//when the instruction is nested then add to line
					if(token == 15) {
						while(token) {
							if(token == 13) {
								if_block.push_back(line);
								line = "";
								break;
							}
							line += yytext;
							token = yylex();
						}
					}
					else break;

					token = yylex();
				}

				for(int i = 0; i < if_block.size(); i++) {
					cout << if_block[i] << endl;
				}
			}
			break;
			//DEFINE FUNCTION

			//IDENTIFIER
			case 9: {
				//creates a new variable for every assignment
				//stores it into a vector of variables for
				//easier access and search
				//needs to check for arithmetic expressions

				Variable *newVar = new Variable;
				newVar->set_variable_name(yytext);
				newVar->set_storage_location_number(storage_id); storage_id++;
				
				while(token) {
					if(token == 10) {
						newVar->set_value(yytext);
						break;
					}

					token = yylex();
				}

				vars.push_back(*newVar);

				break;
			}
			//ERROR CHECKING
			default:
				break;
		}
		
		token = yylex(); //continue to get next token
	}

	for(int i = 0; i < vars.size(); i++) {
		cout << vars[i].get_variable_name() << " : ";
		cout << vars[i].get_value() << endl;
	}

	return 0;
}