#include "CreditCard.h"
#include <ostream>
#include <string>

using namespace std;

CreditCard::CreditCard(const string &num, const string &nm, int limit,
                       double balance) {
  number = num;
  name = nm;
  limit = limit;
  balance = balance;
}

bool CreditCard::chargeIt(double price) {
  if (price + balance < double(limit)) {
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