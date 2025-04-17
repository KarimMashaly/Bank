#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"Global.h"
#include"clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{

private:
	static void _Login()
	{
		bool LoginFailed = false;

		do
		{
			if (LoginFailed)
			{
				cout << "\nInvalid Username/Password!\n";
			}

			cout << "\nEnter Username: ";
			string UserName = clsInputValidate::ReadString();

			cout << "Enter Password: ";
			string Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		clsMainScreen::ShowMainMenu();
	}

public:

	static void ShowLoginScreen()
	{
		_DrawScreenHeader("\t      Login Screen");

		_Login();
	}

};

