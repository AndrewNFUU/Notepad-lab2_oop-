#include "Note.h"


Note::Note()
{
}

Note::Note(string nName, string fName, string sName, string pNumber, Date bDate) :
	noteName(nName), firstName(fName), secondName(sName), phoneNumber(pNumber), birthDate(bDate) {}

void Note::setNote(string nName, string fName, string sName, string pNumber, Date bDate)
{
	noteName = nName;
	firstName = fName;
	secondName = sName;
	phoneNumber = pNumber;
	birthDate = Date();
}

void Note::showNote()
{
	cout << " ____Note___: " << noteName << endl;
	cout << " first name: " << firstName << endl;
	cout << " last name: " << secondName << endl;
	cout << " phone number: " << phoneNumber << endl;
	birthDate.ShowBirthDate();
	cout << " ------------------------------" << endl;
}

void Note::clearNoteName()
{
	noteName = "";
}

void Note::clearFirstName()
{
	firstName = "";
}

void Note::clearSecondName()
{
	secondName = "";
}

void Note::clearPhoneNumber()
{
	phoneNumber = "";
}

void Note::clearBirthDate()
{
	birthDate.DeleteDate();
}

void Note::clearAllNote()
{
	noteName = "";
	firstName = "";
	secondName = "";
	phoneNumber = "";
	birthDate.DeleteDate();
}

/*-------------------Overloading AND Other---------------------*/
bool Note::operator==(const Note& other) const //overload == to use in comparison in Notepad class**
{
	return (noteName == other.noteName &&
		firstName == other.firstName &&
		secondName == other.secondName &&
		phoneNumber == other.phoneNumber &&
		birthDate == other.birthDate);
}

/*Date Note::getDate() {
	return Note::birthDate;
}*/