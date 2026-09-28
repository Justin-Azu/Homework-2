/* FILE NAME: loanCalc.cpp
<<<<<<< HEAD
 * AUTHOR: Group 13
=======
 * AUTHOR: Group 13, Justin Azunda, KJ Hughley
>>>>>>> 8f83e4a3f0be6761ddc9943ff604e0d29a5e2022
 * Loan payoff calculator, including interest
 */
#include <iostream>
using namespace std;

void loanCalc(double loan, double interestRate, double monthlyPaid) {
    double interestRateC;

    double interest;
    double principal;
    double totalInterest = 0.0;

    int month = 0;

    // CURRENCY FORMATTING
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // GET PROPER INTEREST RATES FOR CALCULATIONS
    interestRate /= 12.0;
    interestRateC = interestRate / 100.0;

    cout << endl;

    // AMORTIZATION TABLE
    cout << "*****************************************************************\n";
    cout << "\t\tAmortization Table\n";
    cout << "*****************************************************************\n";
    cout << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

    // LOOP TO FILL TABLE
    while (loan > 0) {
        if (month == 0) {
            cout << month++ << "\t$" << loan;

            if (loan < 1000) cout << "\t";

            cout << "\tN/A\tN/A\tN/A\t\tN/A\n";
        }

        // calculation time
        else {
            interest = loan * interestRateC;

            if (loan + interest < monthlyPaid) {
                monthlyPaid = loan + interest;
            }

            principal = monthlyPaid - interest;

            totalInterest += interest;

            loan -= principal;

            if (loan < 0)
                loan = 0;

            cout << month << "\t$" << loan;

            if (loan < 1000)
                cout << "\t";

            cout << "\t$" << monthlyPaid
                 << "\t" << interestRateC * 100 << "%"
                 << "\t$" << interest
                 << "\t\t$" << principal << endl;

            month++;
        }
    }

    cout << "*****************************************************************\n";

    cout << "\nIt takes " << month - 1
         << " months to pay off the loan.\n";

    cout << "Total interest paid is: $" << totalInterest << endl << endl;
}
