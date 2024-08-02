// order.h

#ifndef _ORDER_H_
#define _ORDER_H_

const int MAX_ORDERS = 20;
const int MAX_ITEMS_PER_ORDER = 10;

struct Order {
	int order_id;
	Menu ordered_items[MAX_ITEMS_PER_ORDER];
	int size;
};

extern Order orders[];
extern int num_of_orders;

void add_order(int order_num);
Order search_order(int order_num);
void update_order(int order_num);
void del_order(int order_num);
float order_total(Order order);
void display_order(Order order);
void display_orders();
void orders_crud();
#endif