#include <iostream>
#include <stdexcept>
using namespace std;


template<typename D>
struct Node {
  D data;
  Node* nextPtr;
};


template<typename D>
class Queue {
private:
  Node<D>* headPtr;
  Node<D>* tailPtr;
  int num_items;

public:
    Queue();
    //~Queue();
    void push(D data);
    D pop();
    D front();
    int size();
    bool empty();
    void print();
    void move_to_rear();
    void insertion_sort();
};





template<typename D>
Queue<D>::Queue() {
  headPtr = nullptr;
  tailPtr = nullptr;
  num_items = 0;
}


/*template<typename D>
Queue<D>::~Queue(){
  for (Node<D>* tempNode = headPtr; tempNode != nullptr; tempNode = tempNode->nextPtr){
    delete tempNode;
  }
}
*/


//Checks for empty queue
template<typename D>
bool Queue<D>::empty() {
  return (headPtr == nullptr);
}




//Add new node to end of queue
template<typename D>
void Queue<D>::push(D data) {
  //Create new node
  Node<D>* newNode = new Node<D>;
  newNode->data = data;
  newNode->nextPtr = nullptr;

  //add to empty list
  if (empty()) {
  headPtr = newNode;
  tailPtr = newNode;
  }
  //add to end of list
  else {
    tailPtr->nextPtr = newNode;
    tailPtr = newNode;
  }
  num_items++;
}




//Remove node from front of queue, returns data
template<typename D>
D Queue<D>::pop() {
  //code this
  D tempData;
  if (!empty()){
    tempData = headPtr->data;
    Node<D>* tempNode = headPtr;
    headPtr = headPtr->nextPtr;
    delete tempNode;
    tempNode = nullptr;
    num_items--;
    return tempData;
    }
  else {
    throw runtime_error("Queue is empty");
  }

}



//Return data from front of queue
template<typename D>
D Queue<D>::front(){
  if (!empty()){
    return headPtr->data;
  }
  else {
    throw runtime_error("Queue is empty");
  }
}




//Returns number of items in queue
template<typename D>
int Queue<D>::size(){
  return num_items;
}





template<typename D>
void Queue<D>::print(){
  if (empty()){
    cout << "Queue is empty";
    return;
  }
  else {
    for (Node<D>* tempNode = headPtr; tempNode != nullptr; tempNode = tempNode->nextPtr){
      cout << tempNode->data << " ";
    }
  }

}


//Checks if queue is empty, if not, moves front node to end of queue, moves second node to front
template<typename D>
void Queue<D>::move_to_rear() {
  if (empty()){
    return;
  }
  else {
    D tempData = pop();
    push(tempData);
    return;
  }
  
}




template <typename D>
void Queue<D>::insertion_sort(){
  int key;
  bool insertionNeeded = false;

  for (Node<D>* tempPtr = headPtr; tempPtr != nullptr; tempPtr = tempPtr->nextPtr){
    key = tempPtr->data;
    insertionNeeded = false;

  for (Node<D>* i = tempPtr->nextPtr; i != nullptr; i = tempPtr->nextPtr){
    if (key < i->data) {
      insertionNeeded = true;
    }


  if (insertionNeeded){
    move_to_rear();
  }
  
  }

}
}


