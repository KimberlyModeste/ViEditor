#include <cassert>       // For assert
#include "ArrayStack.h"  // Header file

template<class TYPE>
ArrayStack<TYPE>::ArrayStack() : top(-1)
{
}  // end default constructor

// Copy constructor and destructor are supplied by the compiler

template<class TYPE>
bool ArrayStack<TYPE>::isEmpty() const
{
	return top < 0;
}  // end isEmpty

template<class TYPE>
bool ArrayStack<TYPE>::push(const TYPE& newEntry)
{
	bool result = false;
	if (top < DEFAULT_CAPACITY - 1)  // Does stack have room for newEntry?
	{
		top++;
		items[top] = newEntry;
		result = true;
	}  // end if

	return result;
}  // end push

template<class TYPE>
bool ArrayStack<TYPE>::pop()
{
	bool result = false;
	if (!isEmpty())
	{
		top--;
		result = true;
	}  // end if

	return result;
}  // end pop

template<class TYPE>
TYPE ArrayStack<TYPE>::peek() const
{
	assert(!isEmpty());  // Enforce precondition during debugging

	// Stack is not empty; return top
	return items[top];
}  // end peek
// End of implementation file.
