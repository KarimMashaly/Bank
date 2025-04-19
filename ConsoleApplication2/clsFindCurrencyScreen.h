#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
{

private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static void _ShowResult(clsCurrency Currency)
	{

		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency was found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency wasn't found :-(";
		}

	}

public:

	static void ShowFindCurrencyScreen()
	{

		_DrawScreenHeader("\tFind Currency Screen");

		int Answer;
		cout << "\nFind By: [1] Code or [2] Country? ";
		Answer = clsInputValidate::ReadIntNumberBetween(1, 2, "The number is not between 1 and 2, Please enter another one: ");

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease enter the Currency Code? ";
			CurrencyCode = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			_ShowResult(Currency);
		}
		else if (Answer == 2)
		{
			string Country;
			cout << "\nPlease enter the Country name? ";
			Country = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(Country);

			_ShowResult(Currency);
		}

	}

};

