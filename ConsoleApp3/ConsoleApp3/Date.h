#pragma once
#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:

	Date();

	Date(int newDay, int newMonth, int newYear);
	
	void ShowBirthDate();

	void DeleteDate();

	string GetMonthName() const;

	string FormatDate();

	enum Month
	{
		empty,
		January,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};

	bool operator==(const Date& other) const;

};

