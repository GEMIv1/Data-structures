#include "DOUBLE_LINKED_LIST.h"

int main() {
	DLL<int> d;
	d.Insert(1,0);
	d.Insert(2,1);
	d.Insert(3,2);
	d.Insert(5,3);
	d.display();
	d.revDisplay();
	d.removeByPos(2);
	d.display();
	d.addLast(2);
	d.display();
	cout<<d.getSize();
}
