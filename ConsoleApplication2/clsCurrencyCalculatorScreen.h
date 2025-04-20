#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{

private:

	static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{

		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry       : " << Currency.Country();
		cout << "\nCode          : " << Currency.CurrencyCode();
		cout << "\nName          : " << Currency.CurrencyName();
		cout << "\nRate(1$) =    : " << Currency.Rate();
		cout << "\n_____________________________\n\n";

	}

	static clsCurrency _GetCurrency(string Message)
	{

		cout << Message;
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{

			cout << "\nThe Currency Code wasn't found, Please enter another one: ";
			CurrencyCode = clsInputValidate::ReadString();

		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static double _ReadAmount()
	{
		cout << "\nEnter amount to Exchange : ";
		double Amount = clsInputValidate::ReadNumber<double>();

		return Amount;
	}

public:
	
	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'n';

		do
		{
			system("cls");

			_DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency Currency1 = _GetCurrency("\nPlease enter Currency1 Code: ");
			clsCurrency Currency2 = _GetCurrency("\nPlease enter Currency2 Code : ");

			double Amount = _ReadAmount();

			_PrintCurrencyCard(Currency1, "Convert From: ");

			double AmountInUSD = Currency1.ConvertToUSD(Amount);

			cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD\n";

			if (Currency2.CurrencyCode() != "USD")
			{
				_PrintCurrencyCard(Currency2, "Converting From USD to: \n\nTo:");

				double AmountInCurrency2 = AmountInUSD * Currency2.Rate();

				cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " ";
				cout << Currency2.CurrencyCode() << endl;
			}

			cout << "\nDo you want to perform another calculation? y/n? ";
			cin >> Answer;

		} while (tolower(Answer) == 'y');

	}
};

