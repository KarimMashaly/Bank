#pragma once
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{

private:

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\tDelete User Screen");

		cout << "\nPlease enter user name: ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{

			cout << "\nUser name wasn't found, Please enter another one: ";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		char Answer;
		cout << "\nAre you sure you want to delete this user? y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{

			if (User.Delete())
			{

				cout << "\nUser was deleted successfully.\n";
				_PrintUser(User);

			}
			else
			{
				
				cout << "\nError, User wasn't deleted.\n";

			}
	
		}
	}

};

