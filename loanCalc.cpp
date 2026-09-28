/* FILE NAME: loanCalc.cpp
 * AUTHOR: Group 13
 * Loan payoff calculator, including interest
 */
#include <iostream>
using namespace std;

int main() {
    double loan;
    double interestRate;
    double interestRateC;
    double monthlyPaid;

    double interest;
    double principal;
    double totalInterest = 0.0;

    int month = 0;

    // CURRENCY FORMATTING
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    do {
        cout << "\nLoan Amount: ";

        if (!(cin >> loan)) {
            cout << "WARNING: Invalid loan amount.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            loan = -1;
        }
        else if (loan <= 0) {
            cout << "WARNING: Invalid loan amount.\n";
        }

    } while (loan <= 0);

    do {
        cout << "Interest Rate (% per year): ";

        if (!(cin >> interestRate)) {
            cout << "WARNING: Invalid interest rate.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            interestRate = -1;
        }
        else if (interestRate <= 0) {
            cout << "WARNING: Invalid interest rate.\n";
        }

    } while (interestRate <= 0);

    // GET PROPER INTEREST RATES FOR CALCULATIONS
    interestRate /= 12.0;
    interestRateC = interestRate / 100.0;

    do {
        cout << "Monthly Payments: ";

        if (!(cin >> monthlyPaid)) {
            cout << "WARNING: Invalid payment.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            monthlyPaid = -1;
        }
        else if (monthlyPaid <= 0) {
            cout << "WARNING: Invalid payment.\n";
        }
        else if (monthlyPaid <= loan * interestRateC) {
            cout << "WARNING: Payment is too small to ever pay off the loan.\n";
        }

    } while (monthlyPaid <= 0 ||
             monthlyPaid <= loan * interestRateC);

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

    return 0;
}
