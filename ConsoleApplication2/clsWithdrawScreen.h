#pragma once
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
{
private:

	static string _ReadAccountNumber()
	{

		string AccountNumber;
		cout << "\nPlease enter Account Number? ";
		AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;

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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\tWithdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{

			printf("\nClient with [%s] doesn't exist\n", AccountNumber.c_str());
			AccountNumber = _ReadAccountNumber();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nPlease enter Withdraw amount? ";
		double WithdrawAmount = clsInputValidate::ReadNumber<double>();

		char Answer;
		cout << "\nAre you sure you want to perform this transaction? y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			if (Client.Withdraw(WithdrawAmount))
			{

				cout << "\nThe amount has been Withdrawn Successfully.\n";
				printf("\nNew Balance is: %0f\n", Client.AccountBalance);

			}
			else
			{

				cout << "\nCannot Withdraw, Insufficient Balance!\n";
				cout << "Amount to Withdraw is: " << WithdrawAmount << endl;
				cout << "Your Balance is: " << Client.AccountBalance << endl;

			}
		}
		else
			cout << "\nThis operation was cancelled.\n";
	}
};

