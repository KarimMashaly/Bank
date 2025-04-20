#pragma once
#include"clsInputValidate.h"
#include"clsString.h"
#include<fstream>
#include<vector>

class clsCurrency
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line)
	{
		vector<string>vCurrency = clsString::Split(Line, "#//#");

		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2],
			stod(vCurrency[3]));
	}

	static vector<clsCurrency>_LoadCurrencyDataFromFile()
	{
		vector<clsCurrency>vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//Read Only

		if (MyFile.is_open())
		{
			string Line;
			
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}

			MyFile.close();
		}

		return vCurrencies;
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#")
	{
		string Line = "";

		Line += Currency.Country() + Separator;
		Line += Currency.CurrencyCode() + Separator;
		Line += Currency.CurrencyName() + Separator;
		Line += to_string(Currency.Rate());

		return Line;
	}

	void _SaveCurrencyDataToFile(vector<clsCurrency>vCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);// over write

		if (MyFile.is_open())
		{
			string Line;

			for (clsCurrency C : vCurrencies)
			{
				Line = _ConvertCurrencyObjectToLine(C);
				MyFile << Line << endl;
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsCurrency>vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (C.CurrencyCode() == _CurrencyCode && C.Country() == _Country)
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(vCurrencies);

	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName,
		float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllLetterInString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//Read only

		if (MyFile.is_open())
		{
			string Line;
			
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();

	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllLetterInString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//Read only

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllLetterInString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return (!Currency.IsEmpty());
	}

	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	static vector<clsCurrency>GetEurosList()
	{
		vector<clsCurrency>vEuroCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in); // Read Only

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (Currency.CurrencyCode() == "EUR")
				{
					vEuroCurrencies.push_back(Currency);
				}
			}

			MyFile.close();
		}

		return vEuroCurrencies;
	}

	double ConvertToUSD(double Amount)
	{
		return(double)(Amount / _Rate);
	}

	double ConvertToOtherCurrency(double Amount, clsCurrency Currency2)
	{
		double AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (double)(AmountInUSD * Currency2.Rate());
	}
};

