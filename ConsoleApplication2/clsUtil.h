#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;
#include<cstdlib>

class clsUtil
{
public:

	enum enType {
		CapitalLetter = 1, SmallLetter = 2, Digit = 3,
		SpecialCharacter = 4, MixChars = 5
	};

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

	static char GetRandomCharacter(enType Type)
	{

		if (Type == MixChars)
		{
			Type = (enType)RandomNumber(1, 4);
		}


		switch (Type)
		{
		case enType::CapitalLetter:
			return char(RandomNumber(65, 90));
			break;

		case enType::SmallLetter:
			return char(RandomNumber(97, 122));
			break;

		case enType::Digit:
			return char(RandomNumber(48, 57));
			break;

		case enType::SpecialCharacter:
			return char(RandomNumber(33, 47));

			/*case enType::MixChars:
				return GetRandomCharacter((enType)RandomNumber(1, 3));*/
		}
	}

	static string GenerateWord(enType Type, int Length = 4)
	{
		string Word = "";

		for (int i = 1; i <= Length;i++)
		{
			Word += GetRandomCharacter(Type);
		}

		return Word;
	}

	static string GenerateKey(enType Type)
	{
		string Word = "";

		Word += GenerateWord(Type) + "-";
		Word += GenerateWord(Type) + "-";
		Word += GenerateWord(Type) + "-";
		Word += GenerateWord(Type);

		return Word;
	}

	static void GenerateKeys(int NumberOfKeys, enType Type)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			printf("Key [%d] : %s\n", i, GenerateKey(Type).c_str());
		}
	}

	static void Swap(int& x, int& y)
	{
		int Temp;

		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(double& x, double& y)
	{
		double Temp;

		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(bool& x, bool& y)
	{
		bool Temp;

		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(char& x, char& y)
	{
		char Temp;

		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(string& x, string& y)
	{
		string Temp;

		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;

		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	static void ShuffleArray(int arr[100], int arr_Length)
	{
		for (int i = 0; i < arr_Length; i++)
		{
			Swap(arr[RandomNumber(1, arr_Length) - 1], arr[RandomNumber(1, arr_Length) - 1]);
		}
	}

	static void ShuffleArray(string arr[100], int arr_Length)
	{
		for (int i = 0; i < arr_Length; i++)
		{
			Swap(arr[RandomNumber(1, arr_Length) - 1], arr[RandomNumber(1, arr_Length) - 1]);
		}
	}

	static void FillArrayWithRandomNumber(int arr[100], int arr_Length, int From, int To)
	{
		for (int i = 0; i < arr_Length; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithRandomWords(string arr[100], int arr_Length, enType Type, int LengthOfWord)
	{
		for (int i = 0; i < arr_Length; i++)
		{
			arr[i] = GenerateWord(Type, LengthOfWord);
		}
	}

	static void FillArrayWithRandomKeys(string arr[100], int arr_Length, enType Type)
	{
		for (int i = 0; i < arr_Length; i++)
		{
			arr[0] = GenerateKey(Type);
		}
	}

	static string Tabs(int NumberOfTabs)
	{
		string Tab = "";

		for (int i = 1; i <= NumberOfTabs; i++)
		{
			Tab += "\t";
		}

		return Tab;
	}

	static string EncryptText(string S1, int Key)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = char((int)S1[i] + Key);
		}

		return S1;
	}

	static string DecryptText(string S1, int Key)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = char((int)S1[i] - Key);
		}

		return S1;
	}

	static string NumberToText(long long Number)
	{
		if (Number == 0)
			return "";

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
			"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

			return arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 999)
		{
			return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 999999999999)
		{
			return NumberToText(Number / 1000000000) + " Billion " + NumberToText(Number % 1000000000);
		}
	}
};

