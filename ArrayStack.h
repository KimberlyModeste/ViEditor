#ifndef ARRAY_STACK_
#define ARRAY_STACK_


#include "StackInterface.h"
#include "Snapshot.h"

const int MAX_STACK = 5;

template<class TYPE>
class ArrayStack : public StackInterface<TYPE>
{
private:
	static const int DEFAULT_CAPACITY = 50;
	TYPE items[DEFAULT_CAPACITY]; // Array of stack items
	int      top;                     // Index to top of stack

public:
	ArrayStack();                    // Default constructor
	bool isEmpty() const;
	bool push(const TYPE& newEntry);
	bool pop();
	TYPE peek() const;
}; // end ArrayStack

#include "ArrayStack.inl"
#endif
