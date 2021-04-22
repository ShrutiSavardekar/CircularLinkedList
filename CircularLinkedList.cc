#include<iostream>
#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList()
{
	head = NULL;
}

CircularLinkedList::~CircularLinkedList()
{
	if(head != NULL)
	{
		Node* temp, *current;
		current = head->getNext();
		while(current != head)
		{
			temp = current->getNext();
			delete current;
			current = temp;
		}
		delete head;
		head = NULL;
	}
}

void CircularLinkedList::push(int i, ClockDirection d)
{
	Node* newNode = NULL;
	Node* temp = NULL;
	int nodeNo;
	Node* start = NULL;
	Node* last = NULL;
	
	newNode = new Node(i);
	if(head == NULL)
	{
		newNode->setNext(newNode);
		newNode->setPrevious(newNode);
		head = newNode;
		start = newNode;
		last = newNode;
	}
	else
	{
		
		temp = head;
		
		if(temp == NULL)
		{
			throw std::out_of_range("Node not available");
		}
		else
		{
			if(temp->getNext() == temp && temp->getPrevious() == temp)
			{
				temp->setNext(newNode);
				temp->setPrevious(newNode);
				newNode->setNext(temp);
				newNode->setPrevious(temp);
				head = newNode;
				
			}
			else
			{
				if(d == ClockWise)
				{
					newNode->setNext(temp->getNext());
					temp->setNext(newNode);
					newNode->setPrevious(temp);
					head = newNode;
				}
				else if(d == CounterClockWise)
				{
					(temp->getPrevious())->setNext(newNode);
					newNode->setPrevious(temp->getPrevious());
					temp->setPrevious(newNode);
					newNode->setNext(temp);
					
					head = newNode;
				}
			}
			
				
		}
	}
	
	
		
			
}

int CircularLinkedList::pop(ClockDirection d)
{
	int value = head->getValue();
	Node* temp = NULL;
	
	if(head == NULL)
	{
		throw std::out_of_range("Linked List is empty");
	}
	else
	{
		
		if(d == ClockWise)
		{
			temp = head;
			head = head->getNext();
			(temp->getPrevious())->setNext(head);
			head->setPrevious(temp->getPrevious());
			delete temp;
			
		}
		else if(d == CounterClockWise)
		{
			temp = head;
			head = head->getPrevious();
			(temp->getNext())->setPrevious(head);
			head->setNext(temp->getNext());
			delete temp;
		}
		
	}
	
	return value;
}

int CircularLinkedList::peek()
{
	int value = 0;
	if(head == NULL)
	{
		throw std::out_of_range("Linked List is empty");
	}
	else
	{
		value = head->getValue();
	}
	return value;
}

void CircularLinkedList::rotate(unsigned int n, ClockDirection d)
{
	if(head == NULL)
	{
		throw std::out_of_range("Linked List is empty");
	}
	else
	{
		if(d == ClockWise)
		{
			for(int i = 0; i < n; ++i)
			{
				head = head->getNext();
			}
		}
		if(d == CounterClockWise)
		{
			for(int i = 0; i < n; ++i)
			{
				head = head->getPrevious();
			}
		}
	}
}


std::ostream& operator<< (std::ostream &os, CircularLinkedList& myList)
{
	if(myList.head == NULL)
	{
		throw std::out_of_range("List is empty");
	}
	else
	{
		Node* temp = myList.head;
		while(temp->getNext() != myList.head)
		{
			os<<temp->getValue()<<", ";
			temp = temp->getNext();
		}
		os<<temp->getValue()<<std::endl;
		
	}
	return os;
}
