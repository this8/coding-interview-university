#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H

#include <ostream>
#include <string>

class CreditCard {
public:
  CreditCard(const std::string &number, const std::string &name, int limit,
             double balance = 0);
  std::string getNumber() const { return number; }
  std::string getName() const { return name; }
  int getLimit() const { return limit; }
  double getBalance() const { return balance; }
  bool chargeIt(double price);
  void makePayment(double payment);

private:
  std::string number;
  std::string name;
  int limit;
  double balance;
};

std::ostream &operator<<(std::ostream &out, const CreditCard &creditCard);

#endif