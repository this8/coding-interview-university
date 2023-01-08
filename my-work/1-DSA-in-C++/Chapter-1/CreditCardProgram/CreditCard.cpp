#include "CreditCard.h"
#include <ostream>
#include <string>

using namespace std;

CreditCard::CreditCard(const string &number, const string &name, int limit,
                       double balance) {
  this->number = number;
  this->name = name;
  this->limit = limit;
  this->balance = balance;
}

bool CreditCard::chargeIt(double price) {
  if (price + balance > double(limit)) {
    return false;
  }
  balance += price;
  return true;
}

void CreditCard::makePayment(double payment) { balance -= payment; }

ostream &operator<<(ostream &out, const CreditCard &creditCard) {
  out << "Number: " << creditCard.getNumber() << "\n"
      << "Name: " << creditCard.getName() << "\n"
      << "Balance: " << creditCard.getBalance() << "\n"
      << "Limit: " << creditCard.getLimit() << "\n";
  return out;
}