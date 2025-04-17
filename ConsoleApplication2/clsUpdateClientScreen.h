#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber;
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static void _ReadClientInfo(clsBankClient& Client)
	{

		cout << "\nPlease enter a first name? ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nPlease enter a last name? ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nPlease enter a email? ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nPlease enter a phone? ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nPlease enter a pinCode? ";
		Client.PinCode = clsInputValidate::ReadString();

		Client.AccountBalance = clsInputValidate::ReadDblNumber("\nPlease enter a account balance? ");

	}

public:

	static void ShowUpdateClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}

		_DrawScreenHeader("\tUpdate Client Screen");

		cout << "\nPlease enter an Account Number? ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{

			cout << "\nAccount Number was not found, Please enter another one? ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char Answer;
		cout << "\nAre you sure you want to update this Client? y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			cout << "\nUpdate Client Info: ";
			cout << "\n______________________\n";

			_ReadClientInfo(Client);

			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client.Save();
			switch (SaveResult)
			{

			case clsBankClient::enSaveResults::svSucceeded:
				cout << "\nClient Updated Successfully :-)\n";
				_PrintClient(Client);
				break;

			case clsBankClient::enSaveResults::svFaildEmptyObject:
				cout << "\nError Client was not Updated because it is Empty :-(\n";
			}
		}
	}
};

