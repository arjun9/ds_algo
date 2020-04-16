#include <iostream>

using namespace std;


class AutoLoan {
    public:
    double interestRate(double price, double monthlyPayment, int loanTerm) {
        double rate = 0.0, hi = 1.0, lo = 0.0, balance = 0.0;

        while((hi - lo) > 0.0000000000001) {
            rate = (hi + lo)/2;
            balance = price;
            for(int i = 1; i <= loanTerm; i++) {
                balance = balance * (1 + rate) - monthlyPayment;
            }
            if(balance == 0.0)
                return rate * 100 * 12;
            else if(balance > 0.0)
                hi = rate;
            else 
                lo = rate;
        }

        return rate * 100 * 12;
    }
};

int main() {
    AutoLoan auto_loan;
    cout << auto_loan.interestRate(2000, 510, 4);
    return 0;
}