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
		eLogout = 8
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

	static void _ShowLogoutScreen()
	{
		cout << "\nLogout Screen will be here...\n";
	}

	static short _ReadMainMenuOption()
	{
		short Option;
		cout << "\t\t\t\t      Choose What do you want to de? [1 to 8]? ";
		Option = clsInputValidate::ReadShortNumberBetween(1, 8, "The number is not between 1 and 8, Please enter another one: ");

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
			ShowMainMenu();
			break;

		case enMainMenuOptions::eManageUsers:
			system("cls");
			_ShowManageUserScreen();
			ShowMainMenu();
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
		_DrawScreenHeader("\t\tMain Screen");

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
		cout << setw(37) << left << "" << "\t[8] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenuOptions((enMainMenuOptions)_ReadMainMenuOption());
	}

};

