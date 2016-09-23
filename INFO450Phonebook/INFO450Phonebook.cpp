// INFO450Phonebook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void addEntry(char phoneBook[][2][50]);
bool validateEntry(char phoneBook[][2][50], char text[50]);
void showBook(char phoneBook[][2][50], int length);
void menu();
void errorM();

bool exitP = false;
int entry;


int main()
{
	entry = 0;
	char phoneBook[10][2][50] = { {}, {} ,{} };
	int answer;
/*
		addEntry(phoneBook);
	showBook(phoneBook, entry); */
	while (!exitP)
	{
		menu();
		cin >> answer;
		if (answer == 1)
		{
			addEntry(phoneBook);
		}
		else if (answer == 2)
		{
			showBook(phoneBook, entry);
		}
		else if (answer == 3)
		{
			exitP = true;		
		}
		else
		{
			cout << "Please Enter A valid response" << endl;
		}
	}

	return 0;
}

void addEntry(char phoneBook[][2][50])
{
	char name[50];
	char phone[50];
	cout << "Enter Name please:" << endl;
	gets_s(name);
	if (validateEntry(phoneBook, name))
	{
		strcpy_s(phoneBook[entry][0], name);
		cout << "Enter Phone # please:" << endl;
		gets_s(phone);
		strcpy_s(phoneBook[entry][1], phone);
		entry++;
	}
	else
	{
		cout << "You've already entered " << name << "'s information!" << endl;
	}
}

bool validateEntry(char phoneBook[][2][50],char text[50])
{
	bool valid = true;
	int x = 0;
	do 
	{
		if (strcmp(phoneBook[x][0], text))
		{
			valid = true;
			x++;
		}
		else
		{
			x = entry;
			valid = false;
		}
	} while(x < entry);
	return valid;
}

void showBook(char phoneBook[][2][50], int length)
{
	
	cout << "\t   Name \t\t Phone Number" << endl;
	for (int x = 0; x < length; x++)
	{
		cout << "\t" << x+1 << ". ";
		for (int y = 0; y < 2; y++)
		{
			cout << phoneBook[x][y] << "\t";

		}
		cout << endl;

		
	}
}

void menu()
{
	cout << "Please Input just the Number of the Action you would like to Perform:" << endl;
	cout << "1. Add Entry" << endl << "2. View Phone Book" << endl << "3. Quit" << endl;

}

void errorM()
{
	cout << "Please enter a Valid response" << endl;
	cout << "Example: 1 NOT 1. Now You Try:" << endl;
}