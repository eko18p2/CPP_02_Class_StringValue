#include <iostream>
#include "StringValue.h"


using std::cout;
using std::endl;
using std::move;







int main() {

	
	StringValue name = "Vasiliy";
	StringValue surname= "Pupkin";

	StringValue fullname = name + " " + surname;
	
	cout << fullname.c_str() << endl;




	getchar();


	return 0;
}

