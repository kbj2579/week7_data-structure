#include "linked_list.h"

#include <iostream>
using namespace std;
// TODO: LinkedList 클래스 구현 작성

  LinkedList::LinkedList():head_(NULL),size_(0){};
  
  LinkedList::~LinkedList(){
    Node* cur = head_;
    while(cur != NULL){
        Node *next_ = cur->next_;
        delete cur;
        cur = next_;
    }
  }
  void LinkedList::print(){
    for(int i = 0; i < size_; i++){
        cout << get(i) << " ";
    }
    cout << endl;
    
  }

  void LinkedList::insert(int index, int value){
    Node* newNode = new Node(value);
    Node* cur = head_;
    Node* pre = head_;
    
    // index 위치까지 cur,pre 노드 이동
    for(int i = 0; i < index; i++){
        if(cur != head_){
            pre = pre->next_;
        }
        cur = cur->next_;
    }
    
    // index 가 0번째인경우
    if(cur == head_){
        newNode->next_ = head_;
        head_ = newNode;
    }
    else{ // index가 1이상인 경우
        if(cur == NULL){
            pre->next_ = newNode;
        }
        else{
            pre->next_ = newNode;
            newNode->next_ = cur;
        }
    }
    size_++;
    return;
  }
  int LinkedList::get(int index){
    Node* newNode = head_;
    for(int i = 0; i < index; i++){
        newNode = newNode->next_;
    }
    return newNode->value_;
  }
  void LinkedList::remove(int index){
    Node* cur = head_; // 삭제할 노드
    Node* pre = nullptr; // 삭제할 노드의 이전노드

    // index 위치까지 cur, pre 노드 이동
    for (int i = 0; i < index; i++) {
        pre = cur;
        cur = cur->next_;
    }

    if (pre == nullptr) {
        // head를 삭제하는 경우
        head_ = cur->next_;
    } else {
        // index가 1이상인 경우
        pre->next_ = cur->next_;
    }

    delete cur;
    size_--;
  }