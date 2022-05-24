#include <iostream>
using namespace std;

#define MAX 100

class stack
{
private:
	int top;
public:
	stack(){top = -1;}
	int arr[MAX];
	void push(int value)
	{
		if (top >= (MAX-1))
			cout<<"Stack Overflow.";
		else
			arr[++top] = value;
	}
	
	void pop()
	{
		if (top == -1)
			cout<<"Stack empty.";
		else
			arr[top--];
	}
	
	void peek()
	{
		if (top == -1)
			cout<<"Stack empty.";
		else
			cout<<arr[top];
	}
	
	bool isEmpty()
	{
		if (top < 0) return true;
		return false;
	}
	
};


int main()
{
	stack s;
	s.isEmpty();
	cout<<endl;
	s.peek();
	cout<<endl;
	s.push(10);
	s.push(20);
	s.push(30);
	s.peek();
	cout<<endl;
	s.pop();
	s.peek();
	cout<<endl;
	s.push(40);
	s.peek();
}