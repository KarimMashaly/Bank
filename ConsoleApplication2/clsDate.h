#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<ctime>
//#include<vector>
#include<string>
#include<iomanip>
#include"clsString.h"
using namespace std;
class clsDate
{
private:


	int _Day;
	int _Month;
	int _Year;

public:


	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string Date)
	{
		vector<string> vDate = clsString::Split(Date, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(int Day, int Month, int Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(int Days, int Year)
	{
		clsDate Date = CalculateDateFromTheBeginningOfTheYear(Days, Year);
		_Day = Date.Day;
		_Month = Date.Month;
		_Year = Date.Year;
	}

	static bool IsLeapYear(int Year)
	{
		return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static int NumberOfDaysInMonth(int Month, int Year)
	{
		int arr[] = { 31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];
	}

	int NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static clsDate CalculateDateFromTheBeginningOfTheYear(int Days, int Year)
	{
		int RemainingDay = Days;
		clsDate Date;
		Date.Month = 1;
		Date.Year = Year;
		int MonDays = NumberOfDaysInMonth(Date.Month, Year);

		while (RemainingDay > MonDays)
		{
			RemainingDay -= MonDays;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}

			MonDays = NumberOfDaysInMonth(Date.Month, Year);
		}

		Date.Day = RemainingDay;

		return Date;
	}

	void setDay(int Day)
	{
		_Day = Day;
	}

	int GetDay()
	{
		return _Day;
	}

	_declspec(property(get = GetDay, put = setDay))int Day;

	void setMonth(int Month)
	{
		_Month = Month;
	}

	int GetMonth()
	{
		return _Month;
	}

	_declspec(property(get = GetMonth, put = setMonth))int Month;

	void setYear(int Year)
	{
		_Year = Year;
	}

	int GetYear()
	{
		return _Year;
	}

	_declspec(property(get = GetYear, put = setYear))int Year;

	void Print()
	{
		printf("%d/%d/%d\n", _Day, _Month, _Year);
	}

	static string GetTheNameOfMonth(int Month)
	{
		string arr[] = { "", "Jan" , "Feb", "Mar","Apr", "May", "Jun", "Jul",
			"Agu", "Sep" , "Oct", "Nov", "Dec" };

		return arr[Month];
	}

	string GetTheNameOfMonth()
	{
		return GetTheNameOfMonth(_Month);
	}

	static short DayOrder(short Month, short Year, short Day = 1)
	{
		short a, y, m;
		short d;

		a = floor((14 - Month) / 12);
		y = Year - a;
		m = Month + 12 * a - 2;

		d = (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
		d = d % 7;

		return d;
	}

	short DayOrder()
	{
		return DayOrder(_Month, _Year, _Day);
	}

	static void PrintMonthCalendar(clsDate Date)
	{
		cout << "  _________________" << GetTheNameOfMonth(Date.Month) << "_________________" << endl;
		cout << "  Sun  Mon  Tue  Wed  Thr  Fri  Sat\n" << endl;

		int MonDays = NumberOfDaysInMonth(Date.Month, Date.Year);
		int Counter = 0;
		short DayOfWeekOrder = DayOrder(Date.Month, Date.Year);

		for (int i = 0; i < DayOfWeekOrder; i++)
		{
			cout << "     ";
			Counter++;
		}

		for (int i = 1; i <= MonDays; i++)
		{
			cout << setw(5) << i;
			Counter++;

			if (Counter == 7)
			{
				cout << endl;
				Counter = 0;
			}
		}

		cout << endl;
	}

	void PrintMonthCalendar()
	{
		PrintMonthCalendar(*this);
	}

	static void PrintYearCalendars(clsDate Date)
	{
		for (int i = 1; i <= 12; i++)
		{
			cout << endl;
			Date._Month = i;
			PrintMonthCalendar(Date);
			cout << endl;
		}
	}

	void PrintYearCalendars()
	{
		PrintYearCalendars(*this);
	}

	static bool IsValid(clsDate Date)
	{
		return !(Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year) || Date.Month > 12);
	}

	bool IsValid()
	{
		return IsValid(clsDate(_Day, _Month, _Year));
	}

	static bool IsDateBeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date2.Year > Date1.Year ? true : (Date1.Year == Date2.Year ? (Date2.Month > Date1.Month ? true :
			(Date1.Month == Date2.Month ? (Date2.Day > Date1.Day ? true : false) : false)) : false));
	}

	bool IsDateBeforeDate2(clsDate Date2)
	{
		return IsDateBeforeDate2(*this, Date2);
	}

	static bool IsLastMonthInYear(int Month)
	{
		return Month == 12;
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static clsDate AddDateByOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			Date.Day = 1;

			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}

	void AddDateByOneDay()
	{
		AddDateByOneDay(*this);
	}

	static int CalculateMyAgeInDays(clsDate Date)
	{
		int Days = 0;
		clsDate NowDate;
		while (IsDateBeforeDate2(Date, NowDate))
		{
			Date = AddDateByOneDay(Date);
			Days++;
		}

		return Days;
	}

	int CalculateMyAgeInDays()
	{
		return CalculateMyAgeInDays(*this);
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}
};

