#pragma once
#include"clsBankClient.h"
#include"clsScreen.h"
#include<iomanip>

class clsTransferLogListScreen : protected clsScreen
{
private:

	static void _Print(clsBankClient::stTransferLogRecord Rec)
	{
		cout << "\t| " << setw(23) << left << Rec.Date_Time;
		cout << "| " << setw(10) << left << Rec.SourceAccountNumber;
		cout << "| " << setw(10) << left << Rec.DestinationAccountNumber;
		cout << "| " << setw(10) << left << Rec.TransferAmount;
		cout << "| " << setw(15) << left << Rec.SourceAccountBalance;
		cout << "| " << setw(15) << left << Rec.DestinationAccountBalance;
		cout << "| " << setw(10) << left << Rec.UserName;
	}

public:
	static void ShowTransferLogListScreen()
	{
		vector<clsBankClient::stTransferLogRecord> vRecords = clsBankClient::GetTransferLogList();

		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vRecords.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t____________________________________________________________________________________________________________\n";
		cout << "\n\t| " << setw(23) << left << "Date/Time";
		cout << "| " << setw(10) << left << "s.Acct";
		cout << "| " << setw(10) << left << "d.Acct";
		cout << "| " << setw(10) << left << "Amount";
		cout << "| " << setw(15) << left << "s.Balance";
		cout << "| " << setw(15) << left << "d.Balance";
		cout << "| " << setw(10) << left << "User";
		cout << "\n\t____________________________________________________________________________________________________________\n\n";

		for (clsBankClient::stTransferLogRecord R : vRecords)
		{
			_Print(R);
			cout << endl;
		}

		cout << "\n\t____________________________________________________________________________________________________________\n\n";

	}
};

