#include "StackLinkedListClass.h"

using namespace std;

int main()
{
	LinkedList linkedList;
	cout << "Is list empty ? : " << linkedList.isEmpty() << endl;
	linkedList.push(5);
	linkedList.push(4);
	linkedList.push(3);
	linkedList.push(2);
	linkedList.push(1);
	linkedList.display();
	cout << "Element at index 3 is : " << linkedList.peek(3) << endl;
	cout << "Element at top of the stack is : " << linkedList.stackTop() << endl;
	cout << linkedList.pop() << endl;
	cout << linkedList.pop() << endl;
	cout << linkedList.pop() << endl;
	cout << linkedList.pop() << endl;
	cout << linkedList.pop() << endl;
	cout << "Is list empty ? : " << linkedList.isEmpty() << endl;
	return 0;
}