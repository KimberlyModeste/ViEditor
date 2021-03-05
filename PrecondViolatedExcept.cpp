/** @file PrecondViolatedExcep.cpp */
#include "PrecondViolatedExcept.h"
using namespace std;
PrecondViolatedExcept::PrecondViolatedExcept(const string& message) :
	logic_error("Precondition Violated Exception: " + message)
{
} // end constructor