#ifndef NULL
#define NULL 0
#endif
#include <iostream>
#include<string>
//#include <expstack.cpp>
using namespace std;

template <class T>
class ExpStackNode{
  public:
    ExpStackNode(T element);
    ExpStackNode *next;
    T element;
};

template <class T>
class ExpStack{
  public:
    ExpStackNode<T> *stack_top;
    int stack_size = 0;
    ExpStack();
    T top();
    void push(T element);
    T pop();
    bool isEmpty();
    int size();
};


template <class T>
ExpStackNode<T>::ExpStackNode(T element){
  this->element = element;
  next = NULL;
}

template <class T>
ExpStack<T>::ExpStack(){
  stack_top = NULL;
}

template <class T>
T ExpStack<T>::top(){
  return stack_top->element;
}

template <class T>
void ExpStack<T>::push(T element){
  ExpStackNode<T> *new_element = new ExpStackNode<T>(element);
  new_element->next = stack_top;
  stack_top = new_element;
  ++stack_size;
}

template <class T>
T ExpStack<T>::pop(){
  if(!isEmpty()){
    ExpStackNode<T> *target = this->stack_top;
    stack_top = stack_top->next;
    --stack_size;
    return target->element;
  }
  return NULL;
}

template <class T>
bool ExpStack<T>::isEmpty(){
  return stack_size == 0 ? 1 : 0;
}

template <class T>
int ExpStack<T>::size(){
  return stack_size;
}