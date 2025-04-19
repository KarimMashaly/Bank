#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsListCurrenciesScreen.h"
#include"clsFindCurrencyScreen.h"
#include<iomanip>

class clsCurrencyExchangeScreen: protected clsScreen
{
private:

	enum enCurrencyMenuOptions
	{
		eListCurrencies = 1,
		eFindCurrency = 2,
		eUpdateRate = 3,
		eCurrencyCalculator = 4,
		eMainMenu = 5
	};

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nList Currencies Screen Will be here....\n";
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen will be here...\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		cout << "\nUpdate Rate Screen will be here...\n";
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		cout << "\nCurrency Calculator Screen will be here...\n";
	}

	static void _GoBackToCurrencyExchangeMenu()
	{
		cout << "\nPress any key to go back to Currency Exchange Menu...";
		system("pause>0");
		ShowCurrencyExchangeMenu();
	}

	static short _ReadCurrencyExchangeMenuOption()
	{

		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "The number is not between 1 and 5, Please enter another one: ");

		return Choice;

	}

	static void _PerformTransactionsMenuOption(enCurrencyMenuOptions CurrencyMenuOption)
	{
		switch (CurrencyMenuOption)
		{
		case enCurrencyMenuOptions::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenu();
			break;

		case enCurrencyMenuOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;

		case enCurrencyMenuOptions::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenu();
			break;

		case enCurrencyMenuOptions::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();
			break;

		case enCurrencyMenuOptions::eMainMenu:
			break;
		}
	}
	
public:

	static void ShowCurrencyExchangeMenu()
	{
		system("cls");

		_DrawScreenHeader("\tCurrency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exchange Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenuOption((enCurrencyMenuOptions)_ReadCurrencyExchangeMenuOption());

	}

};

