#include"clsMainScreen.h"
using namespace std;

/*void ReadInfo(clsBankClient& Client)
//{
//	cout << "\nPlease enter a first name? ";
//	Client.FirstName = clsInputValidate::ReadString();
//
//	cout << "\nPlease enter a last name? ";
//	Client.LastName = clsInputValidate::ReadString();
//
//	cout << "\nPlease enter a email? ";
//	Client.Email = clsInputValidate::ReadString();
//
//	cout << "\nPlease enter a phone? ";
//	Client.Phone = clsInputValidate::ReadString();
//
//	cout << "\nPlease enter a pincode? ";
//	Client.PinCode = clsInputValidate::ReadString();
//
//	Client.AccountBalance = clsInputValidate::ReadDblNumber("\nPlease enter a account balance? ");
//
//}
//
//void UpdateClient()
//{
//	cout << "Please enter a account number? ";
//	string AccountNumber = clsInputValidate::ReadString();
//
//
//	while (!clsBankClient::IsClientExist(AccountNumber))
//	{
//		cout << "\nAccount number is not found, choose another one: ";
//		AccountNumber = clsInputValidate::ReadString();
//	}
//
//	clsBankClient Client = clsBankClient::Find(AccountNumber);
//	Client.Print();
//
//	cout << "\nUpdate Client Info: \n";
//	cout << "_______________________\n";
//
//	ReadInfo(Client);
//
//	clsBankClient::enSave SaveResult;
//	SaveResult = Client.Save();
//
//	switch(SaveResult)
//	{
//	case clsBankClient::svSucceeded:
//		cout << "\nClient Updated Successfully :-)" << endl;
//		break;
//
//	case clsBankClient::svFaildEmptyObject:
//		cout << "\nError account was not saved because it's Empty";
//		break;
//	}
//
//}
//
//void AddNewClient()
//{
//	cout << "Please enter a account number? ";
//	string AccountNumber = clsInputValidate::ReadString();
//
//	while (clsBankClient::IsClientExist(AccountNumber))
//	{
//		cout << "\nAccount number is already used, choose another one: ";
//		AccountNumber = clsInputValidate::ReadString();
//	}
//
//	cout << "\nAdd New Client: \n";
//	cout << "____________________\n";
//
//	clsBankClient NewClient = clsBankClient::GetNewClient(AccountNumber);
//
//	ReadInfo(NewClient);
//
//	clsBankClient::enSave SaveResult;
//	SaveResult = NewClient.Save();
//
//	switch (SaveResult)
//	{
//	case clsBankClient::svFaildEmptyObject:
//		cout << "\nError account was not saved because it's Empty";
//		break;
//
//	case clsBankClient::svSucceeded:
//		cout << "\nClient Added Successfully :-)\n";
//		NewClient.Print();
//		break;
//
//	case clsBankClient::svFaildAccountNumberExists:
//		cout << "\nAccount Number is already used :-(\n";
//		break;
//
//	}
//
//}
//
//void DeleteClient()
//{
//	char Answer;
//
//	cout << "Please enter a account number? ";
//	string AccountNumber = clsInputValidate::ReadString();
//
//
//	while (!clsBankClient::IsClientExist(AccountNumber))
//	{
//		cout << "\nAccount number is not found, choose another one: ";
//		AccountNumber = clsInputValidate::ReadString();
//	}
//
//	clsBankClient Client = clsBankClient::Find(AccountNumber);
//	Client.Print();
//
//	cout << "\nAre you sure you want to delete this client? y/n? ";
//	cin >> Answer;
//
//	if (tolower(Answer) == 'y')
//	{
//		if (Client.Delete())
//		{
//			cout << "\nClient deleted successfully :-)\n";
//			Client.Print();
//		}
//		else
//		{
//			cout << "\nError Client was not Deleted\n";
//		}
//	}
//}
//
//void PrintClientRecordLine(clsBankClient Client)
//{
//	cout << "| " << setw(15) << left << Client.AccountNumber;
//	cout << "| " << setw(22) << left << Client.FullName();
//	cout << "| " << setw(15) << left << Client.Phone;
//	cout << "| " << setw(22) << left << Client.Email;
//	cout << "| " << setw(10) << left << Client.PinCode;
//	cout << "| " << setw(15) << left << Client.AccountBalance;
//}
//
//void PrintClientRecordBalanceLine(clsBankClient Client)
//{
//	cout << "| " << setw(15) << left << Client.AccountNumber;
//	cout << "| " << setw(30) << left << Client.FullName();
//	cout << "| " << setw(15) << left << Client.AccountBalance;
//}
//
//void PrintTotalBalanceList()
//{
//	vector<clsBankClient>vClients = clsBankClient::GetClientsList();
//	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n";
//	cout << "_________________________________________________________________________________________________________\n\n";
//	cout << "| " << setw(15) << left << "Account Number";
//	cout << "| " << setw(30) << left << "Client Name";
//	cout << "| " << setw(15) << left << "Balance" <<endl;
//	cout << "_________________________________________________________________________________________________________\n";
//
//
//	if (vClients.size() == 0)
//	{
//		cout << "\n\n\t\t\t\tNo Clients Available in the System\n";
//	}
//	else
//	{
//		for (clsBankClient& C : vClients)
//		{
//			PrintClientRecordBalanceLine(C);
//			cout << endl;
//		}
//
//	}
//
//	double TotalBalance = clsBankClient::GetTotalBalance();
//	cout << "\n_________________________________________________________________________________________________________\n";
//	cout << "\n\t\t\t\t\tTotal Balances = " << TotalBalance << endl;
//	cout << "\t\t\t\t\t( " << clsUtil::NumberToText(TotalBalance) << " )" << endl;
//}
//
//void PrintClientsList()
//{
//	vector<clsBankClient>vClients = clsBankClient::GetClientsList();
//
//	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n";
//	cout << "_________________________________________________________________________________________________________\n\n";
//	cout << "| " << setw(15) << left << "Account Number";
//	cout << "| " << setw(22) << left << "Client Name";
//	cout << "| " << setw(15) << left << "Phone";
//	cout << "| " << setw(22) << left << "Email";
//	cout << "| " << setw(10) << left << "Pin Code";
//	cout << "| " << setw(8) << left << "Balance\n";
//	cout << "_________________________________________________________________________________________________________\n";
//
//	if (vClients.size() == 0)
//	{
//		cout << "\n\n\t\t\t\tNo Clients Available in the System\n";
//	}
//	else
//	{
//		for (clsBankClient& C : vClients)
//		{
//			PrintClientRecordLine(C);
//			cout << endl;
//		}
//
//	}
//
//	cout << "\n_________________________________________________________________________________________________________\n";
//}*/

//void ReadClientInfo(clsBankClient& Client)
//{
//	cout << "\nPlease enter a first name? ";
//	Client.FirstName = clsInputValidate::ReadString();
//
//	cout << "\nPlease enter a last name? ";
//	Client.LastName = clsInputValidate::ReadString();
//
//	cout << "\nPlease enter a email? ";
//	Client.Email = clsInputValidate::ReadString();
//
//	cout << "\nPlease enter a phone? ";
//	Client.Phone = clsInputValidate::ReadString();
//
//	cout << "\nPlease enter a pincode? ";
//	Client.PinCode = clsInputValidate::ReadString();
//
//	Client.AccountBalance = clsInputValidate::ReadDblNumber("\nPlease enter a account balance? ");
//}
//
//void AddNewClient()
//{
//	string AccountNumber;
//	cout << "\nPlease enter Client Account Number: ";
//	AccountNumber = clsInputValidate::ReadString();
//
//	while (clsBankClient::IsClientExist(AccountNumber))
//	{
//		cout << "\nAccount Number is already used, Choose another one: ";
//		AccountNumber = clsInputValidate::ReadString();
//	}
//
//	clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);
//
//	ReadClientInfo(NewClient);
//
//	clsBankClient::enSaveResults SaveResult;
//	SaveResult = NewClient.Save();
//
//	switch (SaveResult)
//	{
//	case clsBankClient::enSaveResults::svSucceeded:
//		cout << "\nAccount added successfully :-)\n";
//		NewClient.Print();
//		break;
//
//	case clsBankClient::enSaveResults::svFaildEmptyObject:
//		cout << "\nError account was not saved because it is Empty :-(\n";
//		break;
//
//	case clsBankClient::enSaveResults::svFaildAccountNumberExists:
//		cout << "\nError account was not saved because it is used :-(\n";
//		break;
//
//	}
//}
//
//void UpdateClient()
//{
//	cout << "Please enter Client Account Number: ";
//	string AccountNumber = clsInputValidate::ReadString();
//
//	while (!clsBankClient::IsClientExist(AccountNumber))
//	{
//		cout << "\nAccount Number is not found, Please enter another one: ";
//		AccountNumber = clsInputValidate::ReadString();
//	}
//	
//	clsBankClient Client = clsBankClient::Find(AccountNumber);
//	Client.Print();
//
//	cout << "\n\nUpdate Client Info\n";
//	cout << "_________________________\n";
//	ReadClientInfo(Client);
//
//
//	clsBankClient::enSaveResults SaveResult;
//
//	SaveResult = Client.Save();
//
//	switch (SaveResult)
//	{
//	case clsBankClient::enSaveResults::svSucceeded:
//		cout << "\nAccount Updated Successfully :-)\n";
//		Client.Print();
//	
//
//	case clsBankClient::enSaveResults::svFaildEmptyObject:
//		cout << "\nError account was not saved because it is Empty :-(\n";
//	}
//
//}
//
//void DeleteClient()
//{
//	cout << "Please enter Client Account Number: ";
//	string AccountNumber = clsInputValidate::ReadString();
//
//	while (!clsBankClient::IsClientExist(AccountNumber))
//	{
//		cout << "\nAccount Number is not found, Please enter another one: ";
//		AccountNumber = clsInputValidate::ReadString();
//	}
//
//	clsBankClient ClientToDelete = clsBankClient::Find(AccountNumber);
//	ClientToDelete.Print();
//
//	char Answer;
//	cout << "\nAre you sure you want to delete this Client? y/n? ";
//	cin >> Answer;
//
//	if (tolower(Answer) == 'y')
//	{
//		if (ClientToDelete.Delete())
//		{
//			cout << "\nClient deleted Successfully :-)\n";
//			ClientToDelete.Print();
//		}
//		else
//		{
//			cout << "\nError Client was not Deleted :-( \n";
//		}
//	}
//}
//
//void PrintClientRecordLine(clsBankClient Client)
//{
//
//	cout << "| " << setw(15) << left << Client.AccountNumber;
//	cout << "| " << setw(20) << left << Client.FullName();
//	cout << "| " << setw(12) << left << Client.Phone;
//	cout << "| " << setw(20) << left << Client.Email;
//	cout << "| " << setw(10) << left << Client.PinCode;
//	cout << "| " << setw(12) << left << Client.AccountBalance;
//
//}
//
//void ShowClientsList()
//{
//	vector<clsBankClient>vClients = clsBankClient::GetClientsList();
//
//	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//
//	cout << "| " << left << setw(15) << "Accout Number";
//	cout << "| " << left << setw(20) << "Client Name";
//	cout << "| " << left << setw(12) << "Phone";
//	cout << "| " << left << setw(20) << "Email";
//	cout << "| " << left << setw(10) << "Pin Code";
//	cout << "| " << left << setw(12) << "Balance";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//
//	if (vClients.size() == 0)
//	{
//
//		cout << "\t\t\t\tNo Clients available in the system!!!\n";
//
//	}
//	else
//	{
//
//		for (clsBankClient C : vClients)
//		{
//
//			PrintClientRecordLine(C);
//			cout << endl;
//
//		}
//
//	}
//
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//
//}
//
//void PrintClientRecordBalanceLine(clsBankClient Client)
//{
//
//	cout << "| " << setw(15) << left << Client.AccountNumber;
//	cout << "| " << setw(40) << left << Client.FullName();
//	cout << "| " << setw(12) << left << Client.AccountBalance;
//
//}
//
//void ShowTotalBalances()
//{
//	vector<clsBankClient> vClients = clsBankClient::GetClientsList();
//
//	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//
//	cout << "| " << left << setw(15) << "Accout Number";
//	cout << "| " << left << setw(40) << "Client Name";
//	cout << "| " << left << setw(12) << "Balance";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//
//	if (vClients.size() == 0)
//		cout << "\t\t\t\tNo Clients Available In the System!";
//	else
//	{
//
//		for (clsBankClient Client : vClients)
//		{
//			PrintClientRecordBalanceLine(Client);
//			cout << endl;
//		}
//	}
//
//	double TotalBalances = clsBankClient::GetTotalBalances();
//
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//	cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
//	cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
//}

int main()
{
	clsMainScreen::ShowMainMenu();


	system("pause>0");
	return 0;
}