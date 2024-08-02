#include <iostream>
#include "menu.h"
#include "order.h"
#include "payment.h"

using namespace std;

int main(int argc, char** argv)
{
	int order_num;
	Order order;
	float order_amount;
	
	while(true){
		cout << "MAIN MENU" << endl;
		cout << "=========" << endl;
	    cout << "1. Manage Orders " << endl;
	    cout << "2. Make Payemnt" << endl;
	    cout << "3. Menu Management" << endl;
	    cout << "0. Exit" << endl;
	    
	    int choice;
	    cout << "Enter your choice:";
	    cin  >> choice;
	    
	    switch (choice)
	    {
	    	case 1:
	    		orders_crud();
	    	break;
	    	case 2:
	    		cout << "Enter the order number you want to pay: ";
	    		cin >> order_num;
	    		order = search_order(order_num);
	    		order_amount = order_total(order);
	    		make_payment(order_amount);
	    		break;
	    	case 3:
	    		menu_crud();
	    	break;
	    	case 0:
	    		exit(0);
	    	break;
	    	default:
	 		   	cout << "Invalid choice, try again" << endl; 	
		}
		
	}
}