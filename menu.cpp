#include <iostream>
using namespace std;
#include "menu.h"

const int MAX_SIZE = 20;
Menu menu[MAX_SIZE] = {
	{1, "Chicken Karahi", 1200.0f},
	{2, "Seekh Kabab", 500.0f},
	{3, "Naan", 20.0f},
	{4, "Cold Drink", 10.0f},
};
int menu_size = 4; 

void display_menu_item(Menu item){
    cout << "  ID: " << item.food_id << ", ";
    cout << "  Meal: " << item.meal << ", ";
    cout << "  Price: Rs" << item.price << endl;
}

void display_menu(Menu menu[], int size) {
	cout << "MENU" << endl;
	cout << "----" << endl;
    if (size == 0) {
        cout << "  Menu is empty." << endl;
    } else {
        for(int i = 0; i < size; i++) {
			display_menu_item(menu[i]);
        }
    }
}

void add_menu(Menu menu[], int &size, const int MAX_SIZE) {
    if(size < MAX_SIZE) {
        cout << "Enter food ID: ";
        cin >> menu[size].food_id;
        cin.ignore();  // Ignore newline left in buffer
        cout << "Enter meal: ";
        getline(cin, menu[size].meal);
        cout << "Enter price: ";
        cin >> menu[size].price;
        size++;
        cout << "Menu added successfully." << endl;
    } else {
        cout << "Menu is full. Cannot add more items." << endl;
    }
}

void update_menu(Menu menu[], int size) {
    if (size == 0) {
        cout << "Menu is empty. Nothing to update." << endl;
    } else {
        int food_id;
        cout << "Enter menu item ID to update: ";
        cin >> food_id;
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (menu[i].food_id == food_id) {
                found = true;
                cout << "Enter new meal: ";
                cin.ignore();
                getline(cin, menu[i].meal);
                cout << "Enter new price: ";
                cin >> menu[i].price;
                cout << "Menu updated successfully." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Food ID not found. Please try again." << endl;
        }
    }
}

void delete_menu(Menu menu[], int &size) {
    if (size == 0) {
        cout << "Menu is empty. Nothing to delete." << endl;
    } else {
        int food_id;
        cout << "Enter food ID to delete: ";
        cin >> food_id;
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (menu[i].food_id == food_id) {
                found = true;
                for (int j = i; j < size - 1; j++) {
                    menu[j] = menu[j + 1];
                }
                size--;
                cout << "Menu deleted successfully." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Food ID not found. Please try again." << endl;
        }
    }
}

void search_menu(Menu menu[], int size) {
    if (size == 0) {
        cout << "Menu is empty." << endl;
    } else {
        int food_id;
        cout << "Enter food ID to search: ";
        cin >> food_id;
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (menu[i].food_id == food_id) {
                found = true;
				display_menu_item(menu[i]);
                break;
            }
        }
        if (!found) {
            cout << "\nFood ID not found." << endl;
        }
    }
}

int menu_crud() {
    bool exit_crud = false;
    while(!exit_crud) {
    	cout << "MENU MANAGEMENT" << endl;
    	cout << "===============" << endl;
        cout << "1. Display Menu List" << endl;
        cout << "2. Add Menu" << endl;
        cout << "3. Update Menu" << endl;
        cout << "4. Delete Menu" << endl;
        cout << "5. Search Menu by Food ID" << endl;
        cout << "0. Exit" << endl;
        cout << "\nEnter choice: ";
        int choice;
        cin >> choice;
        
        switch(choice) {
            case 1:
                display_menu(menu, menu_size);
                break;
            case 2:
                add_menu(menu, menu_size, MAX_SIZE);
                break;
            case 3:
                update_menu(menu, menu_size);
                break;
            case 4:
                delete_menu(menu, menu_size);
                break;
            case 5:
                search_menu(menu, menu_size);
                break;
            case 0:
            	exit_crud = true;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    }
    return 0;
}
