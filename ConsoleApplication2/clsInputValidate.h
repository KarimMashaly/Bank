#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsUtil.h"
using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(int Number, int Start, int End)
	{
		return (Number >= Start && Number <= End);
	}

	static bool IsNumberBetween(short Number, short Start, short End)
	{
		return (Number >= Start && Number <= End);
	}

	static bool IsNumberBetween(float Number, float Start, float End)
	{
		return (Number >= Start && Number <= End);
	}

	static bool IsNumberBetween(double Number, double Start, double End)
	{
		return (Number >= Start && Number <= End);
	}

	static bool IsDateBetween(clsDate Date, clsDate StartDate, clsDate EndDate)
	{

		if (!(clsDate::IsDateBeforeDate2(StartDate, EndDate)))
			clsUtil::Swap(StartDate, EndDate);

		return !(clsDate::IsDateBeforeDate2(Date, StartDate) || clsDate::IsDateBeforeDate2(EndDate, Date));

	}

	static int ReadIntNumber(string Message)
	{
		int Number = 0;
		bool IsValid = true;

		do
		{

			IsValid = true;

			string Input;
			cin >> Input;

			for (char ch : Input)//1234
			{
				if (!isdigit(ch))
				{
					IsValid = false;
					break;
				}
			}

			if (IsValid)
			{
				Number = stoi(Input);
				return Number;
			}
			else
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << Message;
			}

		} while (!IsValid);

		return Number;
	}

	static short ReadShortNumber(string Message)
	{
		short Number = 0;
		bool IsValid = true;

		do
		{

			IsValid = true;

			string Input;
			cin >> Input;

			for (char ch : Input)//1234
			{
				if (!isdigit(ch))
				{
					IsValid = false;
					break;
				}
			}

			if (IsValid)
			{
				Number = stoi(Input);
				return Number;
			}
			else
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << Message;
			}

		} while (!IsValid);

		return Number;
	}

	static double ReadDblNumber(string Message, string ErrorMessage = "Invalid Number, Please enter a valid one: ")
	{
		double Number = 0;
		bool IsValid = true;

		cout << Message;
		do
		{
			IsValid = true;
			string Input;
			cin >> Input;

			for (char ch : Input)
			{
				if (!isdigit(ch))
				{
					IsValid = false;
					break;
				}
			}

			if (IsValid)
			{
				Number = stoi(Input);
				return Number;
			}
			else
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << ErrorMessage;
			}

		} while (IsValid == false);

		return Number;
	}

	static int ReadIntNumberBetween(int Start, int End, string Message)
	{
		int Number = 0;

		Number = ReadIntNumber("Invalid number, Enter again: ");
		while (!IsNumberBetween(Number, Start, End))
		{
			cout << Message;
			Number = ReadIntNumber("Invalid number, Enter again: ");
		}

		return Number;
	}

	static int ReadShortNumberBetween(short Start, short End, string Message)
	{
		short Number = 0;

		Number = ReadIntNumber("Invalid number, Enter again: ");
		while (!IsNumberBetween(Number, Start, End))
		{
			cout << Message;
			Number = ReadShortNumber("Invalid number, Enter again: ");
		}

		return Number;
	}

	static double ReadDblNumberBetween(double Start, double End, string Message)
	{
		double Number = 0;
		Number = ReadDblNumber("Invalid number, Enter again: ");

		while (!IsNumberBetween(Number, Start, End))
		{
			cout << Message;
			Number = ReadDblNumber("Invalid number, Enter again: ");
		}

		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValid(Date);
	}

	static string ReadString()
	{
		string S1;

		getline(cin >> ws, S1);

		return S1;
	}
};



