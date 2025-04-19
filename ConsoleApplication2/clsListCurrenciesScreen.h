#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include<vector>
#include<iomanip>

class clsListCurrenciesScreen : protected clsScreen
{

private:

    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(45) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();

    }

public :

    static void ShowListCurrenciesScreen()
    {
        vector<clsCurrency>vCurrencies = clsCurrency::GetCurrenciesList();

        string Title = "\tCurrencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\n\t________________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << setw(30) << left <<"Country";
        cout << "| " << setw(8) << left << "Code";
        cout << "| " << setw(45) << left << "Name";
        cout << "| " << setw(10) << left << "Rate/(1$)";
        cout << "\n\t________________________________________________________________________________________________________\n\n";

        if (vCurrencies.size() == 0)
        {
            cout << "\t\t\t\t\tNo Currencies available in the system!!!\n";
        }
        else
        {
            for (clsCurrency C : vCurrencies)
            {
                _PrintCurrencyRecordLine(C);
                cout << endl;
            }
        }

        cout << "\n\t________________________________________________________________________________________________________\n";

    }
};

