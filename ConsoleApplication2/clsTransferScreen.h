#pragma once
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:
	
	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card: \n";
		cout << "____________________________\n";
		cout << "\nFull Name  : " << Client.FullName() << endl;
		cout << "Acc. Number: " << Client.AccountNumber << endl;
		cout << "Balance    : " << Client.AccountBalance << endl;
		cout << "____________________________\n";

	}

	static string _ReadAccountNumber(string SpecificWord)
	{
		cout << "\nPlease enter account number to transfer " << SpecificWord << " : ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{

			cout << "The account number wasn't found, Please enter another one: ";
			AccountNumber = clsInputValidate::ReadString();

		}

		return AccountNumber;
	}

	static double _ReadTransferAmount(clsBankClient SourceClient)
	{
		cout << "\nEnter Transfer amount? ";
		double TransferAmount = clsInputValidate::ReadNumber<double>();

		while (TransferAmount > SourceClient.AccountBalance)
		{
			cout << "\nAmount exceeds the available balance, ";
			cout << "Enter another amount? ";
			TransferAmount = clsInputValidate::ReadNumber<double>();
		}

		return TransferAmount;
	}

public:

	static void ShowTransferScreen()
	{

		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("From"));
		_Print(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));
		_Print(DestinationClient);

		double TransferAmount = _ReadTransferAmount(SourceClient);

		char Answer;
		cout << "\nAre you sure you want to perform this operation? y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{

			if(SourceClient.Transfer(TransferAmount, DestinationClient))
				cout << "Transfer was done successfully :-)\n";

		}
		else
		{
			cout << "\nThis transfer has been cancelled :-(\n";
		}

		_Print(SourceClient);
		_Print(DestinationClient);
	}
};

