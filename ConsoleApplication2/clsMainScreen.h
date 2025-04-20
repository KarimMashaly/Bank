#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientsListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUserScreen.h"
#include"clsLoginScreen.h"
#include"clsLoginRegistersScreen.h"
#include"clsCurrencyExchangeScreen.h"

class clsMainScreen : protected clsScreen
{
private: 

	enum enMainMenuOptions
	{
		eShowClientList = 1,
		eAddNewClient = 2,
		eDeleteClient = 3,
		eUpdateClientInfo = 4,
		eFindClient = 5,
		eTransactions = 6,
		eManageUsers = 7,
		eLoginRegister = 8,
		eCurrencyExchange = 9,
		eLogout = 10
	};

	static void _ShowAllClientsScreen()
	{
	//	cout << "\nClient list screen will be here....\n";

		clsClientsListScreen::ShowClientsList();

	}

	static void _ShowAddNewClientScreen()
	{
	//	cout << "\nAdd New Client Screen will be here...\n";

		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "\nDelete Client Screen will be here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screen will be here...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen will be here...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsScreen()
	{

		//cout << "\nTransactions Screen will be here...\n";
		clsTransactionsScreen::ShowTransactionsMenu();

	}

	static void _ShowManageUserScreen()
	{
		//cout << "\nManage User Screen will be here...\n";
		clsManageUsersScreen::ShowManageUsersMenu();
	}

	static void _ShowLoginRegisterScreen()
	{
		//Login Register Screen will be here....
		clsLoginRegistersScreen::ShowListLoginScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrencyExchangeMenu();
	}

	static void _ShowLogoutScreen()
	{
		//cout << "\nLogout Screen will be here...\n";

		CurrentUser = clsUser::Find("", "");

		//clsLoginScreen::ShowLoginScreen(); This approach is not suitable in terms of stack usage
		// or program design.
		 
		// The Login Screen calls the Main Menu Screen inside the "_Login" method.
	
		// The Main Menu Screen will run and the Login Screen will be paused, waiting for it to finish.
		
		// Once the Main Menu finishes, control returns to the Login Screen to continue executing
		// the remaining code.
		
		// This call chain can lead to deep nesting and potentional stack overflow issues
		// if repeated multiple times
	}

	static short _ReadMainMenuOption()
	{
		short Option;
		cout << "\t\t\t\t      Choose What do you want to de? [1 to 10]? ";
		Option = clsInputValidate::ReadNumberBetween<short>(1, 10, "The number is not between 1 and 10, Please enter another one: ");

		return Option;
	}

	static void _GoBackToMainMenu()
	{
		cout << "\nPress any key to go back to Main Menu...";
		system("pause>0");
		ShowMainMenu();
	}

	static void _PerformMainMenuOptions(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenuOptions::eShowClientList:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eUpdateClientInfo:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eTransactions:
			system("cls");
			_ShowTransactionsScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eManageUsers:
			system("cls");
			_ShowManageUserScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
			
		case enMainMenuOptions::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eLogout:
			system("cls");
			_ShowLogoutScreen();
			break;

		}
	}

public:

	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t      Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenuOptions((enMainMenuOptions)_ReadMainMenuOption());
	}

};

