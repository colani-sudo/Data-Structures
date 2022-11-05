//  DSW2Q1LinkedList
//  Created by Colani Matsenjwa on 2022/10/10.

#include <iostream>

using namespace std;

template<class T>
class Node {

    
  public:

  /**
   * Construct a new Node object with no parameter
   */
    Node() : Node(-1, NULL, NULL){}

  /**
   * Construct a new Node object with parameter
   * @param d data to put in
   */
Node(T d): Node(d, NULL, NULL){}

  /**
   * Construct a new Node object with parameters
   * @param d : data to put in
   * @param p : pointer to the previous node
   * @param n : pointer to the next node
   */
Node(T d, Node<T> *p, Node<T> *n) {
    data = d;
    next = n;
    prev = p;
}

Node<T> *getNext(){ return next;}
Node<T> *getPrev(){ return prev;}
void setNext(Node<T> *next) { this->next = next;}
void setPrev(Node<T> *prev) { this->prev = prev;}
T getData(){ return data;}
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
      head = NULL;
      tail = head;              //just pass the reference of tail
  }
    Node<T> *getHead() { return head;}
    Node<T> *getTail() { return tail;}
  /**
   * Add a node to the tail of the linked list
   * @param data data to put in
   */
  
  void addToTail(T data) {
      Node<T> *newNode = new Node<T>(data);
      if(head == NULL){
          head = newNode;
          tail = head;
      }
      Node<T> *currNode = head;
      while(currNode != tail){
          currNode = currNode->getNext();
      }
      currNode->setNext(newNode);
      newNode->setPrev(currNode);
      tail = newNode;
  }

  /**
   * Add a node to the head of the linked list
   * @param data data to put in
   */
  void addToHead(T data) {
    Node<T> *newNode = new Node<T>(data);
    if(!head)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }
}

  /**
   * Delete a node from the linked list with the given data from the head
   * If there are no data to be deleted, then do nothing
   * @param data data to delete
   */
void deleteData(T data) {
    Node<T> *tempNode, *tempNode2;
    if(head == nullptr)
    {
        cout << "List is empty.";
        return;
    }
    else if(head->getData() == data)
    {
        tempNode = head;
        if(head->getNext() != nullptr)
        {
            head = head->getNext();
            head->setPrev(nullptr);
            delete tempNode;
            tempNode = nullptr;
        }
        else{
            delete head;
            head = nullptr;
            delete tempNode;
            tempNode = nullptr;
            return;
        }
    }
    tempNode2 = head;
    while(tempNode->getNext()->getNext() != nullptr)
    {
        if(tempNode2->getNext()->getData() == data)
        {
            tempNode = tempNode2->getNext();
            tempNode2->setNext(tempNode->getNext());
            tempNode->getNext()->setPrev(tempNode2);
            delete tempNode;
            tempNode = nullptr;
            return;
        }
        tempNode2 = tempNode2->getNext();
    }

    if(tempNode2->getNext()->getData() == data)
    {
        tempNode = tempNode2->getNext();
        delete tempNode;
        tempNode = nullptr;
        tempNode2->setNext(nullptr);
        return;
    }
    cout << "Element not found" << endl;
  }

  /**
   * Delete valid n nodes from the linked list with the given data from the head
   * If there are no more data to be deleted, then just skip
   * @param data data to delete
   * @param n max number of nodes to delete
   */
  void deleteData(T data, int n) {
      if(head == NULL){
          return;
      }
      Node<T> *prevNode = NULL;
      while(n > 0){
          if(head==tail && head->getData() == data){
              free(head);
              tail = head = NULL;
              n--;
          }else{
              Node<T> *currNode = head;
              
              Node<T> *tempNode = currNode;
              if(currNode->getData() == data){
                  if(currNode == tail){
                      tail->setPrev(prevNode);
                      tail = prevNode;
                      delete tempNode;
                      n--;
                  }else{
                      head = currNode->getPrev();
                      head->setPrev(currNode->getNext()->getNext());
                      delete tempNode;
                      n--;
                  }
              }
              prevNode = currNode;
              currNode = currNode->getNext();
          }
      }
      delete prevNode;
      return;
  }

  /**
   * Overload the operator << to print out all the data in the linked list from the head
   * There is a \n in the end of each print
   *
   * Output example:
   * If your linked list data is 5, 4, 3, 2, 1
   * then you should print out "(5, 4, 3, 2, 1)" with the content in quotes but without the quotes
   */
  friend std::ostream &operator<<(std::ostream &out, LinkedList<T> *n) {
      if(n != NULL){
        
        Node<T> *currNode = n->getHead();
          out << "(";
        while(currNode->getNext() != NULL){
            out << currNode->getData() << ", ";
            currNode = currNode->getNext();
        }
          
        out << currNode->getData()<< ")\n";
      }
      return out;
  }

  private:
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
};

int main(){
    
    LinkedList<int> *n = new LinkedList<int>();
    n->addToHead(1);
    n->addToHead(2);
    n->addToHead(3);
    n->addToHead(4);
    n->addToHead(5);
    cout << n;
    
    return 0;
}
