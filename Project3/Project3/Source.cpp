//Michael Ditullio 10/17/21 project 3 returns a list of words and their frequencies in different ways.
#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;

void pythonCall() {
	PyObject* pName = PyUnicode_FromString("PythonCode");
	PyObject* pModule = PyImport_Import(pName);
	PyObject* pDict = PyModule_GetDict(pModule);
	PyObject* pFunc = PyDict_GetItemString(pDict, "word_frequency");
	PyObject_CallObject(pFunc, NULL);
}
/*Description: This function named menu does the following:
1. First, it displays the menu options to the user.
2. Then, it prompts the user to enter a choice.
3. Then, it checks the user's choice and displays the appropriate message.
4. If the user enters an invalid choice, it displays an error message.
5. If the user enters the choice to exit the program, it displays a message and exits the program.
*/






/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}
void menu()
{
	string in;
	string in2;
	int choice = 0;
	
	cout << "*********************************************************" << endl;
	cout << "**" << endl;
	cout << "\033[1;34m";
	cout << "1. Press 1 to print the amount of times words appear in the text.\n";
	cout << "2. Count the number of times one specific item appears\n";
	cout << "3. Create a file with the frequencies displayed as a text based histogram\n";
	cout << "4. Exit the program.\n";
	cout << "Enter your choice: \n";
	cout << "\033[0m";
	cout << "**" << endl;
	cout << "*********************************************************" << endl;
	
	//switch statement
	cin >> choice;
	switch (choice)
	{
	case 1:
		CallProcedure("word_frequency");
		break;
	case 2:
	{
		cout << "Pick an item\n";
		cin >> in;
		int x = callIntFunc("word_frequency_one", in);
		cout << endl;
		cout << in << ": "<< x;
	}

	break;
	case 3:
		CallProcedure("word_frequency_proportional");
		break;
	case 4:
		cout << "Exiting the program.\n";
		break;
	default:
		cout << "Invalid choice.\n";
	}
}

void main()
{
	menu();

	
}