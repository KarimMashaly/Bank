#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include"clsDate.h"
#include"clsUtil.h"
#include<vector>
#include<fstream>

class clsUser : public clsPerson
{
private:

	struct stLoginRegister;

	enum enMode
	{
		enEmptyMode = 0,
		eUpdateMode = 1,
		eAddNewMode = 2
	};

	static const int _Key = 3;
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permission;
	bool _MarkedForDelete = false;

	static clsUser _ConvertLineToUserObject(string Line)
	{

		vector<string>vUserData = clsString::Split(Line, "#//#");

		return clsUser(enMode::eUpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5], _Key),
			stoi(vUserData[6]));

	}

	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector<clsUser>vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//Read Only

		if (MyFile.is_open())
		{
			string Line;
			
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}

			MyFile.close();
		}

		return vUsers;
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::enEmptyMode, "", "", "", "", "", "", 0);
	}

	string _ConvertUserObjectToLine(clsUser User, string Separator = "#//#")
	{
		string UserRecord = "";
		UserRecord += User.FirstName + Separator;
		UserRecord += User.LastName + Separator;
		UserRecord += User.Email + Separator;
		UserRecord += User.Phone + Separator;
		UserRecord += User.UserName + Separator;
		UserRecord += clsUtil::EncryptText(User.Password, _Key) + Separator;
		UserRecord += to_string(User.Permissions);

		return UserRecord;
	}

	void _SaveDataUserToFile(vector<clsUser>vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//Overwrite

		if (MyFile.is_open())
		{
			string Line;

			for (clsUser User : vUsers)
			{
				if (User._MarkedForDelete == false)
				{
					Line = _ConvertUserObjectToLine(User);
					MyFile << Line << endl;
				}
			}

			MyFile.close();
		}

	}

	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << Line << endl;

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& User : vUsers)
		{
			if (User.UserName == _UserName)
			{
				User = *this;
				break;
			}
		}

		_SaveDataUserToFile(vUsers);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	string _PrepareLoginRecord(string Separator = "#//#")
	{
		
		string Line = clsDate::GetSystemDateTimeString() + Separator
			+ UserName + Separator + clsUtil::EncryptText( Password, _Key) + Separator +to_string(Permissions);

		return Line;
	}

	static stLoginRegister _ConvertLoginRegisterLineToStruct(string Line)
	{
		stLoginRegister LoginRegister;

		vector<string> vLogin = clsString::Split(Line, "#//#");

		vLogin[2] = clsUtil::DecryptText(vLogin[2], _Key);

		LoginRegister.Date_Time = vLogin[0];
		LoginRegister.UserName = vLogin[1];
		LoginRegister.Password = vLogin[2];
		LoginRegister.Permissions = stoi(vLogin[3]);

		return LoginRegister;
	}

public:

	 bool IsEmpty()
	{
		return (_Mode == enMode::enEmptyMode);
	}

	 struct stLoginRegister
	 {
		 string Date_Time;
		 string UserName;
		 string Password;
		 int Permissions;
	 };

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64,
		eLoginRegister = 128
	};
	
	clsUser(enMode Mode,  string FirstName,string LastName, string Email, string Phone,
		string UserName, string Password, int Permission) 
		: clsPerson(FirstName, LastName, Email, Phone)
	{

		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permission = Permission;

	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	_declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	_declspec(property(get = GetPassword, put = SetPassword))string Password;

	void SetPermissions(int Permission)
	{
		_Permission = Permission;
	}

	int GetPermissions()
	{
		return _Permission;
	}

	_declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();
		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();
		}

		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);

		return (!User.IsEmpty());
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::eAddNewMode, "", "", "", "", UserName, "", 0);
	}

	static enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::enEmptyMode:
			return enSaveResults::svFaildEmptyObject;
			break;

		case enMode::eUpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
			break;

		case enMode::eAddNewMode:
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::eUpdateMode;
				return enSaveResults::svSucceeded;
				break;
			}
		 }
	}

	bool Delete()
	{
		vector<clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& User : vUsers)
		{
			if (User.UserName == _UserName)
			{
				User._MarkedForDelete = true;
				break;
			}
		}

		_SaveDataUserToFile(vUsers);
		
		*this = _GetEmptyUserObject();

		return true;
	}

	bool CheckAccessPermissions(enPermissions Permissions)
	{
		if (this->Permissions == enPermissions::eAll)
		{
			return true;
		}

		if ((Permissions & this->Permissions) == Permissions)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void RegisterLogin()
	{
		string stDataLine = _PrepareLoginRecord();

		fstream MyFile;
		MyFile.open("Login Registers.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}

	}

	static vector<stLoginRegister>GetLoginRegisterList()
	{
		vector<stLoginRegister>vLogins;

		fstream MyFile;
		MyFile.open("Login Registers.txt", ios::in);//Read Only

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				stLoginRegister Login = _ConvertLoginRegisterLineToStruct(Line);
				vLogins.push_back(Login);
			}

			MyFile.close();
		}

		return vLogins;
	}
};

