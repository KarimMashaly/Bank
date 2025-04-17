#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"

#include<iomanip>

using namespace std;

class clsTransactionsScreen : clsScreen
{
private:
	 
	enum _enTransactionsMenuOptions
	{
		eDeposit = 1,
		eWithdraw = 2,
		eTotalBalances = 3,
		eMainMenu = 4
	};

	static void _ShowDepositScreen()
	{
		//cout << "\nDeposit Screen will be here...\n";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\nWithdraw Screen will be here...\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "\nTotal Balances Screen will be here...\n";
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _GoBackToTransactionsMenu()
	{

		cout << "\nPress any key to go back to transactions menu...";
		system("pause>0");
		ShowTransactionsMenu();

	}

	static void _PerformTransactionsMenuOption(_enTransactionsMenuOptions TransactionsMenuOption)
	{
		switch (TransactionsMenuOption)
		{
		case _enTransactionsMenuOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;

		case _enTransactionsMenuOptions::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;

		case _enTransactionsMenuOptions::eTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;

		case _enTransactionsMenuOptions::eMainMenu:
			break;
		}
	}

	static short _ReadTransactionsMenuOption()
	{

		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 4]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "The number is not between 1 and 4, Please enter another one: ");

		return Choice;

	}

public: 
	
	static void ShowTransactionsMenu()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\t  Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenuOption((_enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}

};

