/*
Isabella Felaco, isf4rjk
1-27-22
bankAccount.h
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


class bankAccount{
 public:
  // default constructor
  bankAccount();

  // overloaded constructor
  bankAccount(double amount);

  // destructor
  ~bankAccount();

  double withdraw(double amount);

  double deposit(double amount);

  double getBalance();
 private:
  double balance;
};

#endif
