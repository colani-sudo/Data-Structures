//
//  main.cpp
//  DSW2Q1LinkedList
//
//  Created by Colani Matsenjwa on 2022/10/10.
//

/**
 * A Node class of Doublely Linked List class
 */
#include <iostream>

using namespace std;

template<class T>
class Node {
  public:

  /**
   * Construct a new Node object with no parameter
   */
  Node() {
      Node(0, NULL, NULL);
  }

  /**
   * Construct a new Node object with parameter
   * @param data: data to put in
   */
  Node(T data){
      Node(data, NULL, NULL);
  }

  /**
   * Construct a new Node object with parameters
   * @param data: data to put in
   * @param prev: pointer to the previous node
   * @param next: pointer to the next node
   */
  Node(T data, Node<T> *prev, Node<T> *next) {
      this->data = data;
      this->next = next;
      this->prev = prev;
  }

  private:
    Node<T> *prev;
    Node<T> *next;
    T data;
};

/**
 * A Doublely Linked List class
 */
template<class T>
class LinkedList {
  public:

  /**
   * Construct a new LinkedList object with no parameter
   */
  LinkedList() {
      head = new Node<T>();
      tail = head;              //just pass the reference of tail
  }

  /**
   * Add a node to the tail of the linked list
   * @param data: data to put in
   */
  void addToTail(T data) {
      Node newNode = new Node<T>(data);
      if(head == NULL){
          head = newNode;
          tail = head;
      }
      Node currNode = head;
      while(currNode != tail){
          currNode = currNode->next;
      }
      currNode->next = newNode;
      newNode->prev = currNode;
      tail = newNode;
  }

  /**
   * Add a node to the head of the linked list
   * @param data: data to put in
   */
  void addToHead(T data) {
      Node newNode = new Node<T>(data);
      if(head == NULL){
          head = newNode;
          tail = head;
      }
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
  }

  /**
   * Delete a node from the linked list with the given data from the head
   * If there are no data to be deleted, then do nothing
   * @param data: data to delete
   */
  void deleteData(T data) {
      if(head == NULL) return;
      
  }

  /**
   * Delete valid n nodes from the linked list with the given data from the head
   * If there are no more data to be deleted, then just skip
   * @param data: data to delete
   * @param n: max number of nodes to delete
   */
  void deleteData(T data, int n) {}

  /**
   * Overload the operator << to print out all the data in the linked list from the head
   * There is a \n in the end of each print
   *
   * Output example:
   * If your linked list data is 5, 4, 3, 2, 1
   * then you should print out "(5, 4, 3, 2, 1)" with the content in quotes but without the quotes
   */
  friend std::ostream &operator<<(std::ostream &out, LinkedList * n) {}

  private:
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
};

int main(){
    
    return 0;
}
