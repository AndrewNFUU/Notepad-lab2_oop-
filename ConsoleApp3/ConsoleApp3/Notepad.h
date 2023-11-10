#pragma once
#include <iostream>
#include <vector>
#include "Note.h"

using namespace std;

class Notepad
{
public: 
	vector <Note> notes;

	Notepad() {};

	Notepad& operator+(const Note& newNote);

	Notepad& operator-(const Note& noteToRemove);

	void ShowInfo();

	vector<Note> operator()(const string& lastName) const;

	vector<Note> operator()(const Date& birthDate) const;

	void AddNote();

	void SearchNote();

	Note* findNote(string noteName);

	void RemoveNote();

	void SortByBirthDate();

private:
	int partition(int low, int high);

	void QuickSort(int low, int high);
};
