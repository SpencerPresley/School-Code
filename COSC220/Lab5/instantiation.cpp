// Programmer: Spencer Presley
// instatiation.cpp, file to linke templated .cpp files; doesn't work without it.

#include "student.cpp"
#include "stack.cpp"
#include "lab5.cpp"

template class Stack<Student*>;
template class StackNode<Student*>;

template class Stack<int>;
template class StackNode<int>;
