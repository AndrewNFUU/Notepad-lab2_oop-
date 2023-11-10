#pragma once 
#include <iostream>
#include <vector>
#include "Date.h"
using namespace std;

class Note
{
public:
	string noteName = "";
	string firstName = "";
	string secondName = "";
	string phoneNumber = "";
	Date birthDate;

	Note();

	Note(string nName, string fName, string sName, string pNumber, Date bDate);

	void setNote(string nName, string fName, string sName, string pNumber, Date bDate);

	void showNote();

	Date getDate();

	void clearNoteName();

	void clearFirstName();

	void clearSecondName();

	void clearPhoneNumber();

	void clearBirthDate();

	void clearAllNote();

	bool operator==(const Note& other) const;
};
