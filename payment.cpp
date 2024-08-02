#include <iostream>
using namespace std;

int showPaymentMenu() {
	int choice;
    cout << "Payment Method" << endl;
    cout << "1. Pay by Cash" << endl;
    cout << "2. Pay by Card" << endl;
    cout << "3. View Payment Total" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    return choice;
}

void make_payment(float order_amount) {
    double cashTotal = 0.0;
    double cardTotal = 0.0;
	double payment_method = 0;
    double amount;

	cout << "Your bill is Rs " << order_amount << endl;
    
	payment_method = showPaymentMenu();
	
    if (payment_method == 1) {
        cout << "Enter cash amount: ";
        cin >> amount;
        cashTotal += amount;
        cout << "Cash payment of Rs" << amount << " received." << endl;
    } else if (payment_method == 2) {
        cout << "Enter card amount: ";
        cin >> amount;
        cardTotal += amount;
        cout << "Card payment of Rs" << amount << " received." << endl;
    } else if (payment_method == 3) {
        cout << "Total payment received: Rs" << cashTotal + cardTotal << endl;
    } else if (payment_method == 0) {
        return;
    } else {
        cout << "Invalid choice. Please try again." << endl;
    }

}

