#include<iostream>
#include<string>
#include<fstream>
#include "Cust.h"

using namespace std;

int FindCust(string, Cust[], int);

int main()
{
	const int NUM_CUST = 6;
	ifstream inputFile;
	Cust customers[NUM_CUST];
	string id1, id2, id3;
	string name;
	int count = 0;

	inputFile.open("Cust.txt", ios::in);

	if (inputFile)
	{
		while (count < NUM_CUST && inputFile >> id1)
		{
			getline(inputFile, name); // Using getline() so that it reads the whole line, as there is one name that has a space in between name and surname. 
			customers[count] = Cust(id1, name);
			count++;
		}
	}
	else
	{
		{
			cout << "ERROR: FILE COULD NOT BE OPEN." << endl;
		}
	}
	inputFile.close();
	
	inputFile.open("CustRel.txt", ios::in);

	if (inputFile) // File open succesffully
	{
		int custIdx1, custIdx2;
		while (inputFile >> id1)
		{		// Reads the data in the file, first the ID and then the Name. Later, it sets the value to the class. 

			inputFile >> id2;

			custIdx1 = FindCust(id1, customers, NUM_CUST);
			if (custIdx2 == -1)
			{
				cout << "Error: Value was not found. ";
				exit(0);
			}
			custIdx2 = FindCust(id2, customers, NUM_CUST);
			if (custIdx2 == -1)
			{
				cout << "Error: Value was not found. ";
				exit(0);
			}
		   customers[custIdx1].setRelated(customers[custIdx2]);
         }
	}
	else
	{
		cout << "ERROR: FILE COULD NOT BE OPEN." << endl;
	}

	for (int i = 0; i < NUM_CUST; i++)
	{
		cout << "Address of customer: " << (i + 1) << (customers + i) << endl;
		cout << "Customer's ID: " << customers[i].getId() << endl;
		cout << "Customer's Name: " << customers[i].getcustName() << endl;
		cout << "Ptr to the related customer is: " << customers[i].getRelated() << endl << endl;
	}

	system("pause");
	return 0;
}

int FindCust(string value, Cust arr[], int size)
{
	int index = 0;
	int position = -1;
	bool found = false;

	while (index < size && !found)
	{
		if (arr[index].getId() == value)
		{
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}