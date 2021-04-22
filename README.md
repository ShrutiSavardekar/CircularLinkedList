I have implemented the following methods: 

{enum ClockDirection {ClockWise, CounterClockWise}};

1. default constructor
2. destructor
3. void push(int i, ClockDirection d): this will insert a new node containing the integer provided in the d direction from the head
4. int pop(ClockDirection d): removes the head node returns its vale and sets the head in the direction specified in d
5. int peek(): this method will return the integer in the head of the circular list
6. void rotate(unsigned int n, ClockDirection d) will rotate the head pointer n spaces in the direction specified in d
7. implemented << for class that prints the circular list in clockwise direction starting at the head: { head-value, next-value..., last value }
