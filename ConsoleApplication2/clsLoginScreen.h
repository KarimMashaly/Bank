#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"Global.h"
#include"clsMainScreen.h"


class clsLoginScreen : protected clsScreen
{

private:
	static bool _Login()
	{
		bool LoginFailed = false;
		int FailedLoginCount = 0;

		do
		{
			if (LoginFailed)
			{
				FailedLoginCount++;

				cout << "\nInvalid Username/Password!\n";
				printf("You have %d trial(s) to login\n", (3-FailedLoginCount));//2//1

				if(FailedLoginCount == 3)
				{
					cout << "\nYou are locked after 3 failed trials\n";
					return false;
				}
			}

			cout << "\nEnter Username: ";
			string UserName = clsInputValidate::ReadString();

			cout << "Enter Password: ";
			string Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();

		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("\t      Login Screen");

		return _Login();
	}

};

