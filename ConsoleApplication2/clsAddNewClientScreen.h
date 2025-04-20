#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsAddNewClientScreen : protected clsScreen
{
private:

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

		cout << "\nPlease enter a account balance? ";
		Client.AccountBalance = clsInputValidate ::ReadNumber<double>();

	}

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

public:
	
	static void ShowAddNewClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("\t Add New Client Screen");

		cout << "Please enter an account number? ";
		string AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{

			cout << "\nAccount Number is already used, please enter another one: ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
			cout << "\nClient Added Successfully :-)\n";
			_PrintClient(NewClient);
			break;

		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "\nError Client was not saved because it is empty :-(\n";
			break;

		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
			cout << "\nError Client was not saved because account number is already used :-(\n";
			break;
		}
	}

};

