#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{

private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

public:
	 
	static void ShowUpdateRateScreen()
	{

		_DrawScreenHeader("\tUpdate Rate Screen");

		cout << "\nPlease enter Currency Code? ";
		string CurrencyCode = clsString::UpperAllLetterInString(clsUtil::Trim(clsInputValidate::ReadString()));

		if (clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			if (CurrencyCode == "EUR")
			{
				vector<clsCurrency>vEuroCurrencies = clsCurrency::GetEurosList();

				for (clsCurrency C : vEuroCurrencies)
				{
					_PrintCurrency(C);
					cout << endl;
				}

				char Answer;
				cout << "\nAre you sure you want to update the rate of this currency? y/n? ";
				cin >> Answer;

				if (tolower(Answer) == 'y')
				{
					cout << "\nUpdate Currency Rate:\n";
					cout << "_____________________________\n";

					float NewRate;
					cout << "\nEnter New Rate: ";
					cin >> NewRate;

					for (clsCurrency& C : vEuroCurrencies)
					{
						C.UpdateRate(NewRate);
					}

					cout << "\nThe Currency Rate has been updated successfully :-)\n";

					for (clsCurrency C : vEuroCurrencies)
					{
						_PrintCurrency(C);
						cout << endl;
					}

				}
				else
				{
					cout << "\nThe update has been cancelled.\n";
				}

				return ;
			}

			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			_PrintCurrency(Currency);

			char Answer;
			cout << "\nAre you sure you want to update the rate of this currency? y/n? ";
			cin >> Answer;

			if (tolower(Answer) == 'y')
			{
				cout << "\nUpdate Currency Rate:\n";
				cout << "_____________________________\n";

				float NewRate;
				cout << "\nEnter New Rate: ";
				cin >> NewRate;

				Currency.UpdateRate(NewRate);

				_PrintCurrency(Currency);
			}
		}
	}

};

