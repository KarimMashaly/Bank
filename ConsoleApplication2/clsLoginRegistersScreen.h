#pragma once
#include "clsScreen.h"
#include"clsUser.h"
#include"clsString.h"
#include<fstream>
#include<iomanip>

class clsLoginRegistersScreen : protected clsScreen
{
private:

	static void _Print(clsUser::stLoginRegister Login)
	{

		cout << "\t| " << setw(40) << left << Login.Date_Time;
		cout << "| " << setw(20) << left << Login.UserName;
		cout << "| " << setw(15) << left << Login.Password;
		cout << "| " << setw(7) << left << Login.Permissions;

	}

public:

	static void ShowListLoginScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::eLoginRegister))
		{
			return;
		}

		vector<clsUser::stLoginRegister>vLogins = clsUser::GetLoginRegisterList();

		string Title = "\tLogin Register List Screen";
		string SubTitle = "\t   (" + to_string(vLogins.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n\n\t__________________________________________________________________________________________________\n";
		cout << "\n\t| " << setw(40) << left << "Date/Time";
		cout << "| " << setw(20) << left << "UserName";
		cout << "| " << setw(15) << left << "Password";
		cout << "| " << setw(10) << left << "Permissions";
		cout << "\n\t__________________________________________________________________________________________________\n";

		for (clsUser::stLoginRegister L : vLogins)
		{
			_Print(L);
			cout << endl;
		}

		cout << "\n\t__________________________________________________________________________________________________\n";

	}
};

