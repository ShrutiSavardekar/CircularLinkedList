
#include "ClockDirection.h"

class Node
{
	private:
		int data;
		Node* next;
		Node* previous;
	public:
		Node(int val)
		{
			data = val;
			next = NULL;
			previous = NULL;
		}
		int& getValue()
		{
			return data;
		}	
		void setNext(Node* ptr)
		{
			next = ptr;
		}
		void setPrevious(Node* ptr)
		{
			previous = ptr;
		}
		Node*& getNext()
		{
			return next;
		}
		Node*& getPrevious()
		{
			return previous;
		}
};

class CircularLinkedList
{
	private:
		Node* head;
	public:
		CircularLinkedList();
		~CircularLinkedList();
		
		void push(int i, ClockDirection d);
		int pop(ClockDirection d);
		int peek();
		void rotate(unsigned int n, ClockDirection d);
		friend std::ostream& operator<<(std::ostream &os, CircularLinkedList& myList);
};


