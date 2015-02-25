#include <iostream>
using namespace std;

class linkedlist
{
public: 
	linkedlist();
	void push(int item);
	int pop();
	int see();
	bool empty();

private:
	struct node
	{
		int data;
		node * next;
	};

	node * top;
};

linkedlist::linkedlist()
{
	top = NULL;
}

void linkedlist::push(int item)
{
	node *temp = new node;
	temp->data = item;
	temp->next = top;
	top = temp;
}

int linkedlist::pop()
{
	if (top == NULL)
	{
		cout << "The stack is empty";
		return 1;
	}
	else
	{
		node * temp;
		temp = top;
		top = top->next;
		return temp->data; // we are returning the deleted element
	}
}

int linkedlist::see()
{
	if (top == NULL)
	{
		cout << "The stack is empty";
		return 1;
	}
	else
	{
		return top->data; //we are returning the top value in our stack
	}
}

bool linkedlist::empty()
{
	return top == NULL;
}

int main()
{
	cout << "\n\nLinked List stack implementation - START\n\n";
	linkedlist s1;

	cout << "s1.empty() = " << s1.empty() << endl;
	
	//put somethings in it
	cout << "s1.push( " << 1 << " )\n";
	s1.push(1);
	cout << "s1.push( " << 2 << " )\n";
	s1.push(2);
	cout << "s1.push( " << 3 << " )\n";
	s1.push(3);
	cout << "s1.push( " << 4 << " )\n";
	s1.push(4);

	//verify that empty() reports it is not empty,
	//and that the right thing is at the top
	cout << "s1.empty() = " << s1.empty() << "\n";
	cout << "s1.peek() = " << s1.see() << "\n";
	
	// Empty it, and verify that empty() again reports it is empty.
	while (!s1.empty()){
		cout << "s1.pop() = " << s1.pop() << "\n";
	}
	cout << "s1.empty() = " << s1.empty() << "\n";

	cout << "\n\nLinked List stack implementation- DONE\n\n";

	return 0;
}