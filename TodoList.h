#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "TodoListInterface.h"

using namespace std;

class TodoList: public TodoListInterface {
    vector<string> tasks;
public:
    TodoList() {
        cout << "In constructor" << endl;

        //Open TODO and read lines into current working vector "tasks"
        string line;
        ifstream inputFile("TODO.txt");
        if (inputFile.is_open())
        {
            while (getline(inputFile, line))
            {
                tasks.push_back(line);
            }
            inputFile.close();
        }

        else cout << "Unable to open file";
    }
    virtual ~TodoList() {
        cout << "In destructor" << endl;

        ofstream outFile;
        outFile.open("TODO.txt", ofstream::out | ofstream::trunc);

        for (int i = 0; i < tasks.size(); i++) {
            outFile << tasks[i] << endl;
        }

        outFile.close();
    }

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task)
    {
        cout << "In add" << endl;
        tasks.push_back(_duedate + " - " + _task);
    }

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task)
    {
        cout << "In remove" << endl;
        
        //Searches tasks for specified string, then removes the string at the found position
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].find(_task) != std::string::npos) {
                cout << "Removing " << tasks[i] << endl;
                tasks.erase(tasks.begin() + i);
                return 1;
            }
        }

        //Outputs could not find error
        cout << "Sorry, there is no task that has that description" << endl;
        
        return 0;
    }

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList()
    {
        cout << "In print" << endl;

        for (int i = 0; i < tasks.size(); i++) {
            cout << tasks[i] << endl;
        }

    }

    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date)
    {
        cout << "In list" << endl;

        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].find(_date) != std::string::npos) {
                cout << tasks[i] << endl;
            }
        }
    }
};

#endif
