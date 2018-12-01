#include <iostream>

using namespace std;

class Variable {
private:
	string variable_name; //name of the variable 
	int storage_location_number; //position of where the information is stored (value ID)
	int value_stored; //the value stored for this variable
public:
	//constructor
	Variable() {
		variable_name = "name";
		storage_location_number = 9999;
		value_stored = 0;
	}

	//overloaded constructor
	Variable(string name, int id, int val) {
		variable_name = name;
		storage_location_number = id;
		value_stored = val;
	}

	//destructor
	~Variable();

	//mutators for variable name
	void set_variable_name(string name) { variable_name = name; }
	string get_variable_name() { return variable_name; }

	//mutators for storage number
	void set_storage_location_number(int sln) { storage_location_number = sln; }
	int get_storage_location_number() { return storage_location_number; }

	//mutators for value
	void set_value(int val) { value_stored = val; }
	int get_value() { return value_stored; }
};

Variable::~Variable() {
	variable_name = "N/A";
	storage_location_number = 9999;
	value_stored = 0;
}