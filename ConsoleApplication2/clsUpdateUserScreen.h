#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen
{

private:

	static int _ReadPermissionsToSet()
	{
		char Answer;
		int Permissions = 0;

		cout << "Do you want to give full access? y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			return -1;
		}
		else
		{

			cout << "\nDo you want to give access to: \n";

			cout << "\nShow Client List? y/n? ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Permissions += clsUser::enPermissions::pListClients;
			}

			cout << "\nAdd New Client ? y/n? ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Permissions += clsUser::enPermissions::pAddNewClient;
			}

			cout << "\nDelete Client ? y/n? ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Permissions += clsUser::enPermissions::pDeleteClient;
			}

			cout << "\nUpdate Client ? y/n? ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Permissions += clsUser::enPermissions::pUpdateClients;
			}

			cout << "\nFind Client ? y/n? ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Permissions += clsUser::enPermissions::pFindClient;
			}

			cout << "\nTransactions ? y/n? ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Permissions += clsUser::enPermissions::pTranactions;
			}

			cout << "\nManage Users ? y/n? ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Permissions += clsUser::enPermissions::pManageUsers;
			}

			return Permissions;
		}
	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter first name: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter last name: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter permissions: ";
		User.Permissions = _ReadPermissionsToSet();
	}

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

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\tUpdate User Screen");

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
		cout << "\nAre you sure you want to update this user? y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			cout << "\nUpdate User Info: ";
			cout << "\n____________________\n";

			_ReadUserInfo(User);

			clsUser::enSaveResults SaveResult = User.Save();

			switch (SaveResult)
			{
			case clsUser::enSaveResults::svSucceeded:

				cout << "\nUser has been updated successfully. :-)\n";
				_PrintUser(User);
				break;

			case clsUser::enSaveResults::svFaildEmptyObject:

				cout << "\nError User was not saved because it's Empty";
				break;


			case clsUser::enSaveResults::svFaildUserExists:

				cout << "\nError User was not saved because UserName is used!\n";
				break;
			}
		}
	}
};

