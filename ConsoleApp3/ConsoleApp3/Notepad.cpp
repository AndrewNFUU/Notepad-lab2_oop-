#include "Notepad.h"

Notepad& Notepad::operator+(const Note& newNote)
{
	this->notes.push_back(newNote);
	return *this;
}

Notepad& Notepad::operator-(const Note& noteToRemove) {
	auto it = find(notes.begin(), notes.end(), noteToRemove);
	if (it != notes.end()) {
		notes.erase(it);
	}
	return *this;
}

void Notepad::ShowInfo()
{
	for (auto& note : notes)
	{
		note.showNote();
		cout << endl;
	}
}

// overloading () operator, for use in SearchByLastName and in SearchByBirthDate
vector<Note> Notepad::operator()(const string& lastName) const  // for ordinary datatypes
{
	vector<Note> result;
	for (const Note& note : notes)
	{
		if (note.secondName == lastName)
		{
			result.push_back(note);
		}
	}
	return result;
}

vector<Note> Notepad::operator()(const Date& birthDate) const // for Date class
{
	vector<Note> result;
	for (const Note& note : notes)
	{
		if (note.birthDate == birthDate)
		{
			result.push_back(note);
		}
	}
	return result;
}

// 1. Add note
void Notepad::AddNote() 
{
	string nName, fName, sName, pNumber;
	int day, month, year;

	cin.ignore();

	cout << " Enter note name: ";
	getline(cin, nName);

	cout << " Enter first name: ";
	getline(cin, fName);

	cout << " Enter second name: ";
	getline(cin, sName);

	cout << " Enter phone number: ";
	getline(cin, pNumber);

	cout << " Enter birth date (day month year): ";
	cin >> day >> month >> year;
	cin.ignore(); 

	try {
		Date bDate(day, month, year);
		Note newNote;
		newNote.setNote(nName, fName, sName, pNumber, bDate);
		*this = *this + newNote;
		
		/*cout << "--    --    --    --    --" << endl << endl;
		this->ShowInfo();*/
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
}

// 3. Search note by
void Notepad::SearchNote()
{
	int choice;

	cout << " --Select a Search Type--" << endl;
	cout << " 1. Search by last name " << endl;
	cout << " 2. Search by birth date " << endl << endl;
	cout << " Option: "; cin >> choice;
	cin.ignore();
	cout << " ------------------------" << endl;
	switch (choice) {
	case 1: {
		cout << " Enter last name: ";
		string lastName;
		getline(cin, lastName);
		cout << endl;
		vector<Note> searchResult = operator()(lastName);
		for (Note& note : searchResult) {
			note.showNote();
			cout << endl;
		}
		break;
	}
	case 2: {
		cout << " Enter birth date (day month year): ";
		int day, month, year;
		cin >> day >> month >> year;
		cin.ignore();
		cout << endl;
		try {
			Date searchDate(day, month, year);
			vector<Note> searchResult = operator()(searchDate);
			for (Note& note : searchResult) {
				note.showNote();
				cout << endl;
			}
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
		break;
	}
	default:
		cout << " Invalid choice." << endl;
		break;
	}
}

Note* Notepad::findNote(string noteName)
{
	for (Note& note : notes)
	{
		if (note.noteName == noteName)
		{
			return &note;
		}
	}
	return nullptr;
}

// 4. Remove note 
void Notepad::RemoveNote()
{
	cin.ignore();

	cout << " Enter name of note to delete: ";
	string noteName;
	getline(cin, noteName);

	Note* noteToRemove = findNote(noteName);
	if (noteToRemove != nullptr)
	{
		*this = *this - *noteToRemove;
		cout << " Note Deleted Successfully. " << endl;
	}
	else
	{
		cout << " Note not found.";
	}
}

//---------------------Quick Sort alg for sorting by Birth Date
// (actually, I have quite wierd task: overload == operator in sorting algorithm)
int Notepad::partition(int low, int high)
{
	Note pivot = notes[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (notes[j].birthDate == pivot.birthDate)
		{
			i++;
			swap(notes[i], notes[j]);
		}
	}
	swap(notes[i + 1], notes[high]);
	return i + 1;
}

void Notepad::QuickSort(int low, int high)
{
	if (low < high)
	{
		int sortedInd = partition(low, high);

		QuickSort(low, sortedInd - 1);
		QuickSort(sortedInd + 1, high);
	}
}

void Notepad::SortByBirthDate()
{
	int low = 0;
	int high = notes.size() - 1;
	QuickSort(low, high);
}

