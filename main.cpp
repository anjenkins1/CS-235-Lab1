#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TodoList.h"

int main(int argc, char *argv[0])
{
	TodoList test1;

/* Debugging Code
	for (int i = 0; i < argc; i++) {
		cout << "argv[" << i << "]=" << argv[i] << endl;
	}
*/
	string firstarg = argv[1];
	if (firstarg.compare("add") == 0) {
		string date = argv[2];
		string task = argv[3];
    test1.add(date, task);
	}

	else if (firstarg.compare("remove") == 0) {
		string task = argv[2];
		test1.remove(task);
	}

  else if (firstarg.compare("printList") == 0) {
    test1.printTodoList();
	}

  else if (firstarg.compare("printDay") == 0) {
		string date = argv[2];
    test1.printDaysTasks(date);
	}

}