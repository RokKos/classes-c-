#ifndef _SRC_QUEUE_HPP_
#define _SRC_QUEUE_HPP_

// System includes

// User includes

/**
 * @file queue.hpp
 * @author Rok Kos <kosrok97@gmail.com>
 * @brief Class that represent queue for generic data type.
 */

template <class T>
class Queue {
 private:
  // Declaring Node for linked list
  struct Node {
    T value;
    Node* next;
    // struct constructor
    Node(T _value) {
      value = _value;
      next = nullptr;
    }
    // struct destructor
    ~Node() {
      // delete next;
    }
  };

  int N;
  Node* first;
  Node* last;

 public:
  // Constructor
  Queue();

  // Destructor
  ~Queue();

  void push(const T item);
  T top();
  T pop();
  bool isEmpty() const;
  int size() const;
};

template <class T>
Queue<T>::Queue() {
  this->N = 0;
  this->last = new Node(T());  // T() is default value
  this->first = this->last;
}

template <class T>
Queue<T>::~Queue() {
  delete last;
}

template <class T>
void Queue<T>::push(const T item) {
  Node* newLast = new Node(T());
  last->value = item;
  this->last->next = newLast;
  if (this->isEmpty()) {
    this->first = this->last;
  }
  this->last = newLast;
  N++;
}

template <class T>
T Queue<T>::top() {
  return first->value;
}

template <class T>
T Queue<T>::pop() {
  // Can we even pop somethin out
  if (!this->isEmpty()) {
    N--;
    // Save for later to return
    T returnValue = this->top();
    // Save reference so that we can delete this node
    Node* oldFirst = this->first;
    this->first = this->first->next;
    delete oldFirst;
    return returnValue;
  }
  return T();  // return default value of type
}

template <class T>
bool Queue<T>::isEmpty() const {
  if (first->next == nullptr) {  // Its the same as cheking if N == 0
    return true;
  }
  return false;
}

template <class T>
int Queue<T>::size() const {
  return this->N;
}

#endif  // _SRC_QUEUE_HPP_