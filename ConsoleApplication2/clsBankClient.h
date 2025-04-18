#pragma once
#include<iostream>
#include"clsPerson.h"
#include"clsDate.h"
#include<fstream>
#include"clsString.h"
#include"Global.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode { enEmptyMode = 0, enUpdateMode = 1 , enAddNewMode};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkedForDelete = false;


	static clsBankClient _ConvertLineToClientObject(string Line)
	{
		vector <string >vClient = clsString::Split(Line, "#//#");

		return clsBankClient(enMode::enUpdateMode, vClient[0], vClient[1], vClient[2], vClient[3],
			vClient[4], vClient[5], stod(vClient[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return  clsBankClient(enEmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadDataFromFile()
	{
		fstream MyFile;
		vector<clsBankClient> vClients;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while(getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;
	}

	string _ConvertClientObjectToLine(clsBankClient Client, string delim = "#//#")
	{
		string Line = "";
		Line += Client.FirstName + delim;
		Line += Client.LastName + delim;
		Line += Client.Email + delim;
		Line += Client.Phone + delim;
		Line += Client.AccountNumber + delim;
		Line += Client.PinCode + delim;
		Line += to_string(Client.AccountBalance);

		return Line;
	}

	void _SaveDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;
			
			for (clsBankClient C : vClients)
			{
				Line = _ConvertClientObjectToLine(C);
				MyFile << Line << endl;
			}
		}
	}

	void _Update()
	{
		vector<clsBankClient>vClients = _LoadDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if(C.AccountNumber == _AccountNumber)
			{
				C = *this;
				break;
			}
		}

		_SaveDataToFile(vClients);
	}

	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Clients.txt",ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;

			MyFile.close();
		}

	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _SaveClientsDataToFile(vector<clsBankClient>vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		if (MyFile.is_open())
		{
			string DataLine;

			for (clsBankClient C : vClients)
			{
				if (C.GetMarkedForDelete() == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}

	}

	string _PrepareTransferLogRecord( clsBankClient DestinationClient, double Amount, string Separator)
	{

		string TransferLogRecord = clsDate::GetSystemDateTimeString() + Separator;
		TransferLogRecord += _AccountNumber + Separator + DestinationClient.AccountNumber + Separator;
		TransferLogRecord += to_string(Amount) + Separator + to_string(_AccountBalance) + Separator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Separator;
		TransferLogRecord += CurrentUser.UserName;

		return TransferLogRecord;

	}

	void _RegisterTheOperationOfTransfer(clsBankClient DestinationClient, double Amount, string Separator = "#//#")
	{

		fstream MyFile;
		MyFile.open("Transfer Log.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			string Line = _PrepareTransferLogRecord(DestinationClient, Amount, Separator);

			MyFile << Line << endl;

			MyFile.close();
		}

	}

public:

	bool IsClientEmpty()
	{
		return (_Mode == enMode::enEmptyMode);
	}

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, double AccountBalance) : clsPerson(FirstName, LastName,
			Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	bool GetMarkedForDelete()
	{
		return _MarkedForDelete;
	}

	_declspec(property(get = GetAccountNumber)) string AccountNumber;
	_declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;
	_declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	/*void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}*/

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return(!Client.IsClientEmpty());
	}

	static enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 , svFaildAccountNumberExists};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::enEmptyMode:
			return enSaveResults::svFaildEmptyObject;

		case enMode::enUpdateMode:
			_Update();
			return enSaveResults::svSucceeded;

		case enMode::enAddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber))
				return enSaveResults::svFaildAccountNumberExists;
			else
			{
				_AddNew();
				_Mode = enMode::enUpdateMode;

				return enSaveResults::svSucceeded;
			}
		}
	}

	static clsBankClient GetAddNewClient(string AccountNumber)
	{
		return   clsBankClient(enMode::enAddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClient> vClients = _LoadDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static vector<clsBankClient>GetClientsList()
	{
		return _LoadDataFromFile();
	}
	
	static double GetTotalBalances()
	{
		vector<clsBankClient>vClients = _LoadDataFromFile();
		double TotalBalances = 0;

		for (clsBankClient& C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}

		return TotalBalances;
	}

	void Deposit(double DepositAmount)
	{
		_AccountBalance += DepositAmount;
		Save();
	}

	bool Withdraw(double WithdrawAmount)
	{

		if (WithdrawAmount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= WithdrawAmount;
			Save();

			return true;
		}

	}

	bool Transfer(double Amount, clsBankClient &DestinationClient)
	{
		if (Amount > _AccountBalance)
			return false;

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTheOperationOfTransfer(DestinationClient, Amount);
		return true;
	}

	

};

