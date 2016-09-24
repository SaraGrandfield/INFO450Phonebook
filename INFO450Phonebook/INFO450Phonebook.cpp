// INFO450Phonebook.cpp : Simple c++ address book program for INFO 450 at VCU, has a menu that allows a user to add a name and phone number
// also has duplication checking and the ability to print the phonebook to the console
// Sara A. Grandfield 9/23/16

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void addEntry(char phoneBook[][2][50]);
bool validateEntry(char phoneBook[][2][50], char text[50]);
void showBook(char phoneBook[][2][50], int length);

bool exitP = false;
bool invalid = true;
/*Counts how many entrys have been put in so far*/
int entry;
string errorM = "Please enter a Valid response \n Example: A \n Now You Try:";
string menu = "Please Input just the Action you would like to Perform : \n 1. Add Entry \n 2. View Phone Book \n 3. Quit";


int main()
{
	entry = 0;
	char phoneBook[10][2][50] = { {}, {} ,{} };

	//Main menu powered by cases and a while loop, DOES NOT perfectly catch errors breaks if user types a char or string instead of a number
	int choice;
	while (invalid != false) 
	{
		cout << menu << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (entry < 10){addEntry(phoneBook); }
			else { cout << "Your book is full" << endl; }
			break;
		case 2:
			showBook(phoneBook, entry);
			break;
		case 3:
			cout << "End of Program.\n";
			invalid = false;
			break;
		default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			cin >> choice;
			break;
		}

	}
	return 0;
}

//adds and entry to the phone book array, calls the validation method
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

//Checks to be sure an entry hasn't already been made for a specific person
bool validateEntry(char phoneBook[][2][50],char text[50])
{
	bool valid = true;
	int x = 0;
	//do while loop that iterates through the array to check each location until it finds a match
	do 
	{
	//Checks if text entered by user and passed to function is the same as a specific entry in the array
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

//Displays the contents of the phone book array
void showBook(char phoneBook[][2][50], int length)
{
	
	cout << "\t   Name \t\t Phone Number" << endl;
	for (int x = 0; x < length; x++)
	{
		cout << "\t" << x+1 << ". ";
		for (int y = 0; y < 2; y++)
		{
			//Displays a specific entry
			cout << phoneBook[x][y] << "\t";
		}
		cout << endl;

		
	}
}
