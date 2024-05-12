#include "stack.h"
// TODO: Stack 클래스 구현 작성
    Stack::Stack(){};

    void Stack::push(int data){
        LinkedList::insert(0, data);
    }
    int Stack::pop(){
        int getValue = peek();
        LinkedList::remove(0);
        return getValue;
    }
    int Stack::peek(){
        return LinkedList::get(0);
    }
    Stack& Stack::operator+=(int data) {
        push(data);
        return *this;
    }