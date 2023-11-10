#include "Date.h"

Date::Date() : day(0), month(0), year(0) {};

Date::Date(int newDay, int newMonth, int newYear)
{
	if (newDay > 0 && newDay <= 31) {
		this->day = newDay;
	}
	else {
		throw "Incorrect day input.";
	}

	if (newMonth > 0 && newMonth <= 12) {
		this->month = newMonth;
	}
	else {
		throw "Incorrect month input.";
	}

	if (newYear > 1950 && newYear <= 2023) {
		this->year = newYear;
	}
	else {
		throw "Incorrect year input.";
	}
}

void Date::ShowBirthDate()
{
	string formattedDate = FormatDate();
	cout << " date of birth: " << formattedDate << endl;
}

void Date::DeleteDate()
{
	day = 0;
	month = 0;
	year = 0;
}

string Date::GetMonthName() const
{
	static const string monthNames[] = { "Invalid Month", "January", "February", "March", 
		"April", "May", "June", "July", "August", "September", "October", "November", "December" };
	if (month >= 1 && month <= 12)
	{
		return monthNames[month];
	}
	else
	{
		return monthNames[0];
	}
}

string Date::FormatDate() {
	string monthName = GetMonthName();
	return to_string(day) + "." + monthName + "." + to_string(year);
}


bool Date::operator==(const Date& other) const  //overload == to use in comparison in Note class, and also for sorting notes by date*
{
	return (day == other.day && month == other.month && year == other.year);
}


