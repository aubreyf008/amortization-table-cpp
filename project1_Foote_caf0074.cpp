//Aubrey Foote
//caf0074
//project1_Foote_caf0074.cpp
//To compile the code in AU Linux server, first enter the yearly interest rate, then enter the loan amount,
//and finally enter the monthly payment. 
//I used youtube to learn c++ libraries, for and while loops, and how to shorten my code
//Used chatgpt to learn how to manipulate the output to where I can print out the amortization table 
//according to the project guidelines

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
int main(){
    double rate, loan_amount, monthly_payment;

    cout << "What is your interst rate? (% per year)"; 
    cin >> rate; // yearly interest rate
    if(rate < 0) {
        cout << "Interest rate cannot be below zero. Please Try again.\n";
        return 0;
    }
    cout << "What was the loan amount?";
    cin >> loan_amount;
    if(loan_amount <= 0){
        cout << "Loan amount should be greater than zero. Please enter a proper amount.";
        return 0;
    }
    cout << "What will your monthly payment be?";
    cin >> monthly_payment;
    if(monthly_payment <= 0){
        cout << "Monthly payment should be greater than zero. Please enter a proper amount";
        return 0;
    }
    

    int months = 0;
    // converts the annual interest rate into a smaller montlhy interest rate
    double monthly_rate = (rate / 100) / 12;
    double total_interest_paid = 0.0;

    cout << "Loan Amount: $" << loan_amount << "\n"
         << "Interest Rate (% per year): " << 18 << "%\n"
         << "Monthly Payments: $" << monthly_payment << "\n";

    // Start to construct our amoritization table
    cout << "************************************************************\n";
    cout << " Amortization Table  \n";
    cout << "************************************************************\n";
    // sets the width of each of our important values on the amortization table
    cout << left << setw(6) << "Month"
                 << setw(10) << "Balance"
                 << setw(10) << "Payment"
                 << setw(6) << "Rate"
                 << setw(10) << "Interest"
                 << setw(10) << "Principal" << "\n";

    // now to set the inital values starting at month 0
    cout << setw(6) << "0"
         << setw(10) << fixed << setprecision(2) << loan_amount
         << setw(10) << "N/A"
         << setw(6) << "N/A"
         << setw(10) << "N/A"
         << setw(10) << "N/A" << "\n";

    // Loop until the loan is paid off

    while (loan_amount > 0){
        months++;
        double interest = loan_amount * monthly_rate; // calculates the interest to be paid
        double principal = monthly_payment - interest; // principal is amount that is actually paid

        if(interest > monthly_payment){
            cout << "The interest is larger than the monthly payment.\n"
                 << "You must increase your monthly payment in order to pay off this loan\n";
            break;
        }

        if (principal > loan_amount) {
            principal = loan_amount;
            monthly_payment = principal + interest;


        }
        loan_amount = loan_amount - principal; // loan amount decreases with each principal payment made
        total_interest_paid = total_interest_paid + interest; //total interest is kept track of

        // print current row
        cout << setw(6) << months
             << "$" << setw(9) << loan_amount
             << "$" << setw(9) << monthly_payment
             << setw(6) << fixed << setprecision(2) << (monthly_rate * 100)
             << "$" << setw(9) << interest
             << "$" << setw(9) << principal << "\n";


    }
    if(total_interest_paid == 0.00){
        return 0;

    }
    else {
        cout << "************************************************************\n";
        cout << "It takes " << months << " months to pay off the loan.\n";
        cout << "Total interest paid is: $" << fixed << setprecision(2) << total_interest_paid << "\n";
    }
    return 0;

}
