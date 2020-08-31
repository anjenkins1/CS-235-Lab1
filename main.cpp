#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TodoList.h"

int main(int argc, char *argv[0])
{
	TodoList test1;

	for (int i = 0; i < argc; i++) {
		cout << "argv[" << i << "]=" << argv[i] << endl;
	}

	string firstarg = argv[1];
	if (firstarg.compare("add") == 0) {
		string date = argv[2];
		string task = argv[3];
		cout << "date " << date << " task " << task << endl;
		test1.add(date, task);
	}
	else if (firstarg.compare("remove") == 0) {
		string task = argv[2];

		cout << "task to remove: " << task << endl;
		test1.remove(task);
	}

}