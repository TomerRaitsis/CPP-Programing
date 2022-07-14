

#include"Date.h"


Date::Date() // Default Ctor
{
	time_t rawtime;   // Gets the Date of today
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	day = timeinfo->tm_mday; // Todays day value
	month = timeinfo->tm_mon + 1; // Todays month value
	year = timeinfo->tm_year + 1900; // todays year value


}


Date::Date(int d, int m, int y) // Ctor with values
{
	Date CurrentDate; // Create a Date object with todays date 

	if (y >= 1921) { // Checks if the year is valid
		year = y; // Using it, if its valid
	}
	else
	{
		year = CurrentDate.year; // Using the current year if the year parameter is not valid
	}
	if (m >= 1 && m <= 12) // Checks if the month is valid
	{
		month = m; // Using it, if its valid
	}
	else
	{
		month = CurrentDate.month; // Using the current month if the month parameter is not valid
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (d >= 1 && d <= 31) // Incase the month has 31 days, it checks if the day is valid
		{
			day = d; // Using it, if its valid
		}
		else
		{
			day = 1; // Using the default option if the day is not valid
		}
	}
	else if (month == 2)
	{
		if (d >= 1 && d <= 28) // Incase the month has 28 days
		{
			day = d; // Using it, if its valid
		}
		else
		{
			day = 1; // Using the default option if the day is not valid
		}
	}
	else
	{
		if (d >= 1 && d <= 30) { // Incase the month has 30 days
			day = d; // Using it, if its valid
		}
		else
		{
			day = 1; // Using the default option if the day is not valid
		}
	}

}


int Date::GetMonthDays(int month) const
{
	if (month > 12) // Checks if the month is valid (it can be bigger than a year because of the calculations in other functions
		month %= 12;

	switch (month) // the functions returns the number of days in each month
	{
	case 1: return 31;
	case 2: return 28;
	case 3: return 31;
	case 4: return 30;
	case 5: return 31;
	case 6: return 30;
	case 7: return 31;
	case 8: return 31;
	case 9: return 30;
	case 10: return 31;
	case 11: return 30;
	case 12: return 31;
	}

}


Date::Date(const Date& temp) // CCtor
{
	this->day = temp.day; // Copying the day
	this->month = temp.month; // Copying the month
	this->year = temp.year; // Copying the year
}


void Date::PrintDate() const // Prints the date 
{
	cout << day << "/" << month << "/" << year << endl;
}


Date Date::SubDate(const Date& temp) const // Finds the difference between two dates (returns a Date object)
{
	Date d; // Creates aa Date object with the current date


	if (this->year > temp.year) // Incase the year value is bigger than the parameters
	{
		if (this->month > temp.month) // Incase the month value is bigger than the parameters
		{
			if (this->day > temp.day) // Incase the day value is bigger than the parameters
			{
				d.day = this->day - temp.day;
				d.month = this->month - temp.month;
				d.year = this->year - temp.year;
			}
			else if (this->day < temp.day) // Incase the parameter day value is bigger 
			{
				d.year = this->year - temp.year;
				d.month = this->month - temp.month - 1;
				d.day = this->day + (GetMonthDays(d.month + temp.month) - temp.day);
			}
			else // this->day = temp.day
			{
				d.day = 0;
				d.month = this->month - temp.month;
				d.year = this->year - temp.year;
			}
		}
		else if (this->month < temp.month)  // Incase the parameter month value is bigger 
		{
			if (this->day > temp.day) // Incase the day value is bigger than the parameters
			{
				d.day = this->day - temp.day;
				d.month = 12 + this->month - temp.month;
				d.year = this->year - temp.year - 1;
			}
			else if (this->day < temp.day)  // Incase the parameter day value is bigger 
			{
				d.year = this->year - temp.year - 1;
				d.month = 11 + this->month - temp.month;
				d.day = this->day + (GetMonthDays(temp.month + d.month) - temp.day);
			}
			else // this->day = temp.day
			{
				d.day = 0;
				d.month = 12 + this->month - temp.month;
				d.year = this->year - temp.year - 1;
			}
		}
		else //this->month = temp.month
		{
			if (this->day > temp.day) // Incase the day value is bigger than the parameters
			{
				d.day = this->day - temp.day;
				d.month = 0;
				d.year = this->year - temp.year;
			}
			else if (this->day < temp.day)  // Incase the parameter day value is bigger 
			{
				d.year = this->year - temp.year - 1;
				d.month = 11;
				d.day = this->day + (GetMonthDays(temp.month + d.month) - temp.day);
			}
			else // this->day = temp.day
			{
				d.day = 0;
				d.month = 0;
				d.year = this->year - temp.year;
			}
		}

	}
	else if (this->year < temp.year) // Incase the year parameter is bigger 
	{

		if (this->month > temp.month) // Incase the month value is bigger than the parameters
		{
			if (this->day > temp.day) // Incase the day value is bigger than the parameters
			{
				d.year = temp.year - this->year - 1;
				d.month = 11 + temp.month - this->month;
				d.day = temp.month + (GetMonthDays(this->day + d.month) - this->day);
			}
			else if (this->day < temp.day) // Incase the parameter day value is bigger 
			{
				d.day = temp.day - this->day;
				d.month = 12 + temp.month - this->month;
				d.year = temp.year - this->year - 1;
			}
			else // this->day = temp.day
			{
				d.day = 0;
				d.month = 12 + temp.month - this->month;
				d.year = temp.year - this->year - 1;
			}
		} 
		else if (this->month < temp.month) // Incase the parameter day value is bigger 
		{
			if (this->day > temp.day) // Incase the day value is bigger than the parameters
			{
				d.year = temp.year - this->year;
				d.month = temp.month - this->month - 1;
				d.day = temp.day + GetMonthDays(this->month + d.month) - this->day;
			}
			else if (this->day < temp.day) // Incase the parameter day value is bigger 
			{
				d.day = temp.day - this->day;
				d.month = temp.month - this->month;
				d.year = temp.year - this->year;
			}
			else // this->day = temp.day
			{
				d.day = 0;
				d.month = temp.month - this->month;
				d.year = temp.year - this->year;
			}
		}
		else //this->month = temp.month
		{
			if (this->day > temp.day) // Incase the day value is bigger than the parameters
			{
				d.year = temp.year - this->year - 1;
				d.month = 11;
				d.day = temp.day + GetMonthDays(this->month + d.month) - this->day;
			}
			else if (this->day < temp.day)  // Incase the parameter day value is bigger 
			{
				d.day = temp.day - this->day;
				d.month = 0;
				d.year = temp.year - this->year;
			}
			else // this->day = temp.day
			{
				d.day = 0;
				d.month = 0;
				d.year = temp.year - this->year;
			}
		}
	}
	else // this->year = temp.year
	{
		if (this->month > temp.month) // Incase the month value is bigger than the parameters
		{
			if (this->day > temp.day)  // Incase the day value is bigger than the parameters
			{
				d.day = this->day - temp.day;
				d.month = this->month - temp.month;
				d.year = 0;
			}
			else if (this->day < temp.day)  // Incase the parameter day value is bigger 
			{
				d.year = 0;
				d.month = this->month - temp.month - 1;
				d.day = this->day + GetMonthDays(temp.month + d.month) - temp.day;
			}
			else // this->day = temp.day
			{
				d.day = 0;
				d.month = this->month - temp.month;
				d.year = 0;
			}
		}
		else if (this->month < temp.month)  // Incase the parameter month value is bigger 
		{
			if (this->day > temp.day)   // Incase the day value is bigger than the parameters
			{
				d.year = 0;
				d.month = temp.month - this->month - 1;
				d.day = temp.day + GetMonthDays(this->month + d.month) - this->day;
			}
			else if (this->day < temp.day) // Incase the parameter day value is bigger 
			{
				d.day = temp.day - this->day;
				d.month = temp.month - this->month;
				d.year = 0;
			}
			else // this->day = temp.day
			{
				d.day = 0;
				d.month = temp.month - this->month;
				d.year = 0;
			}
		}
		else //this->month = temp.month
		{
			if (this->day > temp.day)  // Incase the day value is bigger than the parameters
			{
				d.day = this->day - temp.day;
				d.month = 0;
				d.year = 0;
			}
			else if (this->day < temp.day) // Incase the parameter day value is bigger 
			{
				d.day = temp.day - this->day;
				d.month = 0;
				d.year = 0;
			}
			else // this->day = temp.day
			{
				d.day = 0;
				d.month = 0;
				d.year = 0;
			}
		}
	}

	return d;
}


Date& Date::operator=(const Date& temp) // operator =
{
	if (this != &temp) // Checks if the object and the parameter point to the same adress
	{
		day = temp.day; // Day value
		month = temp.month; // Month value
		year = temp.year; // year value
	}

	return *this;
}

