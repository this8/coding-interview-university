#include "CreditCard.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void testCard() {
  vector<CreditCard *> wallet(10);

  wallet[0] = new CreditCard("1234 5678 2345 7890", "Taylor Swift", 75000);
  wallet[1] = new CreditCard("7865 3123 6755 9891", "Taylor Swift", 54570);
  wallet[2] = new CreditCard("1213 4546 7778 9803", "Taylor Swift", 87500);

  for (int i = 1; i <= 16; i++) {
    wallet[0]->chargeIt(double(i));
    wallet[1]->chargeIt(2 * i);
    wallet[2]->chargeIt(double(3 * i));
  }

  cout << "Card payments:\n";
  for (int i = 0; i < 3; i++) {
    cout << *wallet[i];
    while (wallet[i]->getBalance() > 100) {
      wallet[i]->makePayment(100);
      cout << "New balance: " << wallet[i]->getBalance() << "\n";
    }
    cout << "\n";
    delete wallet[i];
  }
}

int main() {
  testCard();
  return EXIT_SUCCESS;
}