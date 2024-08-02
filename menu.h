// menu.h

#ifndef _MENU_H_
#define _MENU_H_

#include <string>
using namespace std;

struct Menu{
	int food_id;
	string meal;
	float price;
};

extern const int MAX_SIZE;
extern Menu menu[];
extern int menu_size;

void display_menu_item(Menu item);
void display_menu(Menu menu[], int size);
int menu_crud();

#endif