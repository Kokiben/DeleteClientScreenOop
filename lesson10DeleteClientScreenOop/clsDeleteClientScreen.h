#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen:protected clsScreen
{
private:
	static void _PrintClientInfo(clsBankClient Client)
	{
		cout << "\nClient Info: ";
		cout << "\n________________________";
		cout << "\nFirstName     : " << Client.FirstName;
		cout << "\nLastName      : " << Client.LastName;
		cout << "\nFull Name     : " << Client.FullName();
		cout << "\nEmail         : " << Client.Email;
		cout << "\nPhone         : " << Client.Phone;
		cout << "\nAcc.Number    : " << Client.AccountNumber();
		cout << "\nPassword      : " << Client.PinCode;
		cout << "\nBalance       : " << Client.AccountBalance;
		cout << "\n________________________";
	}
public:
	static void ShowDeleteClientScreen()
	{
		_DrawScreenHeader("\t Delete Client Screen");
		string AccountNumber = "";

		cout << "\nPlease enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account Number is not found , choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClientInfo(Client1);

		cout << "\nAre you sure you want to delete this client y/n?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Delete())
			{
				cout << "\nClient Deleted Sucessfully :-)";
				_PrintClientInfo(Client1);

			}
			else
			{
				cout << "\nError client was not Delelted \n";
			}
		}
	}

};

