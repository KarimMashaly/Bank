#include"clsLoginScreen.h"
#include"Global.h"

using namespace std;

int main()
{
	while (true)
	{

		if (!clsLoginScreen::ShowLoginScreen())
			break;

	}
	
	//system("pause>0");
	return 0;
}