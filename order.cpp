//Here we perform crud operation for Customer Order module
// with the help of Arrays and Functions
#include <iostream>
#include "menu.h"
#include "order.h"

using namespace std;

Order orders[MAX_ORDERS];
int num_of_orders = 0;


void add_order(int order_num)
{
	Order added_order = orders[order_num];
	added_order.order_id = num_of_orders + 1;
	// Get ordered items from user
	for(int i=0; i<MAX_ITEMS_PER_ORDER; i++){
		int choice = 0;
		display_menu(menu, menu_size);
		cout << "Enter your choice: ";
		cin >> choice;
		added_order.ordered_items[i] = menu[choice-1];	
		added_order.size++;
		// store into the array
		orders[order_num] = added_order;
		
		cout << "Do you want to order another item [y/n]? ";
		char yes_no;
		cin >> yes_no;
		if(yes_no == 'n')
			break;
	}
	
	display_order(orders[num_of_orders]);
	
	num_of_orders++;
}

Order search_order(int order_num)
{
	Order ord;
	ord.order_id = -1; // placeholder for not found order
	
	if(order_num < num_of_orders){
	   for (char j = 0; j < order_num; j++)
	   {
	   		if(order_num==orders[j].order_id)
	   		{
	   			return orders[j];
	    	}
	   }		
	}
	
	return ord;	
}

void update_order(int order_num)
{
	Order added_order = orders[order_num];
	// Get new order items from user
	for(int i=0; i<MAX_ITEMS_PER_ORDER; i++){
		int choice = 0;
		display_menu(menu, menu_size);
		cout << "Enter your choice: ";
		cin >> choice;
		added_order.ordered_items[i] = menu[choice-1];	
		added_order.size++;
		// store into the array
		orders[order_num] = added_order;

		cout << "Do you want to order another item [y/n]? ";
		char yes_no;
		cin >> yes_no;
		if(yes_no == 'n')
			break;
	}
	
	display_order(orders[num_of_orders]);
}

void del_order (int order_num)
{
	for (char k = order_num; k < num_of_orders; k++)
	{
    	orders[k] = orders[k + 1];
	}
	num_of_orders--;
}

float order_total(Order order){
	float total = 0.0f;
	for(int i=0; i < order.size; i++){
		total += order.ordered_items[i].price;
	}
	return total;
}

void display_order(Order order)
{	
	cout << "Order ID: " << order.order_id << endl;
	for(int j = 0; j < order.size; j++)
	{
		display_menu_item(order.ordered_items[j]);
	}
	cout << "----------------------------------------" << endl;
	cout << "Total: \t" << order_total(order) << endl;
	cout << "----------------------------------------" << endl << endl;
}

void display_orders(){
	for(int i=0; i<num_of_orders; i++){
		display_order(orders[i]);
	}
}

void orders_crud()
{
	int choice;
	int order_num;
	Order order;
	bool exit_crud = false;
	
	while(!exit_crud){
		cout << "ORDER MANAGEMENT" << endl;
		cout << "----------------" << endl;
	    cout<<"1. Add order" << endl;
	    cout<<"2. Search order" << endl;
	    cout<<"3. Delete order" << endl;
	    cout<<"4. Update order" << endl;
	    cout<<"5. Show order" << endl;
	    cout <<"6. Show All Orders" << endl;
	    cout<<"0. Exit" << endl;
	    
	    cout << "Enter your choice:";
	    cin  >> choice;
	    
	    switch (choice)
	    {
	    	case 1:
	    		add_order(num_of_orders);
	    	break;
	    	case 2:
	    		cout << "Enter order number to search: ";
	    		cin >> order_num;
	    		order = search_order(order_num);
	    		display_order(order);
	    	break;
	    	case 3:
	    		cout << "Enter order number to delete: ";
	    		cin >> order_num;
	    		del_order(order_num);
	    	break;
	    	case 4:
	    		cout << "Enter order number to update: ";
	    		cin >> order_num;
	    		update_order(order_num);
	    	break;
	    	case 5:
	    		cout << "Enter order number: ";
	    		cin >> order_num;
	    		order = search_order(order_num);
	    		display_order(order);
	    	break;
	    	case 6:
	    		display_orders();
	    		break;
	    	case 0:
	    		exit_crud = true;
	    	break;
	    	default:
	 		   	cout << "Invalid value...try again" << endl; 	
		}
		
	}
}