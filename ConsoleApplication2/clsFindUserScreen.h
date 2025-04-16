#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
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

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\tFind User Screen");

		cout << "\nPlease enter user name: ";
		string UserName = clsInputValidate::ReadString();
		      
		  

		while (!clsUser::IsUserExist(UserName))
		{

			cout << "\nUser name wasn't found, Please enter another one: ";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nThe user was found :-)\n";
			_PrintUser(User);
		}
		else
			cout << "\nThe user wasn't found :-(\n";
		//Karim 
	}
};

