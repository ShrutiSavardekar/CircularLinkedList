I have implemented the following methods: 

{enum ClockDirection {ClockWise, CounterClockWise}};

default constructor
destructor
void push(int i, ClockDirection d): this will insert a new node containing the integer provided in the d direction from the head
int pop(ClockDirection d): removes the head node returns its vale and sets the head in the direction specified in d
int peek(): this method will return the integer in the head of the circular list
void rotate(unsigned int n, ClockDirection d) will rotate the head pointer n spaces in the direction specified in d
implemented << for class that prints the circular list in clockwise direction starting at the head: { head-value, next-value..., last value }
