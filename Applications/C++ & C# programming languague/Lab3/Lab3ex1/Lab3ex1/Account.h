#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <iostream>

using namespace std;

class Account
{
public:
	double balance;
	string name;
	void deposit(double amount);
	void withdraw(double amount);
	Account();
	~Account();
};

#endif // _ACCOUNT_H_

