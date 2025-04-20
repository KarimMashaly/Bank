#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsUtil.h"
#include<sstream>
using namespace std;

 class clsInputValidate
{
public:

	template <typename T>
	static bool IsNumberBetween(T Number, T Start, T End)
	{
		return (Number >= Start && Number <= End);
	}

	static bool IsDateBetween(clsDate Date, clsDate StartDate, clsDate EndDate)
	{

		if (!(clsDate::IsDateBeforeDate2(StartDate, EndDate)))
			clsUtil::Swap(StartDate, EndDate);

		return !(clsDate::IsDateBeforeDate2(Date, StartDate) || clsDate::IsDateBeforeDate2(EndDate, Date));

	}

	template <typename T>
	static T ReadNumber( string ErrorMessage = "Invalid Number, Please enter a valid one: ")
	{
		T Number = 0;
		bool IsValid = true;

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
				stringstream ss(Input);
				ss >> Number;
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

	template <typename T>
	static T ReadNumberBetween(T Start, T End, string Message)
	{
		T Number = 0;

		Number =ReadNumber <T> ("Invalid number, Enter again: ");
		while (!IsNumberBetween(Number, Start, End))
		{
			cout << Message;
			Number = ReadNumber <T> ("Invalid number, Enter again: ");
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



