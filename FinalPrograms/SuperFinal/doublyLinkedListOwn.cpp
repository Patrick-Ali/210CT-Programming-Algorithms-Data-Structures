#include <iostream>
class List; 
class Node
{
  /*
  Creates a node object that is assigned a value when created.
 */
  friend List;
  private:
    
    Node* next;
    Node* prev;
  public:
    int value;
    Node(int val)
    {
      std::cout << "Node constructr!" << std::endl;
      this->value=val;
      this->next=nullptr;
      this->prev=nullptr;
    }
    ~Node()
    {
      std::cout << "Node destructor" << std::endl;
      std::cout << "I had the value "<<this->value << std::endl;
    }
};

class List
{
  /*
    Allows for the creation of a list object which will contain a bunch of nodes
    whihc will point to their previous and succeding nodes thus creating a doubly 
    linked list. This list is headed with a head pointer which denotes the beginning
    of the list and the end is denoted with a tail pointer.
  */
  
private:
    Node* head;
    Node* tail;
  
 
public:
  // Atributes 
    List()
    {
      /* Initialise the list wih head and tale as 0 as there is no values in the list yet*/
      std::cout << "List Constructor!" << std::endl;
      this->head=nullptr;
      this->tail=nullptr;
    }
    
    void insert(Node* prevNode, Node* newNode)
    {
      /* 
        Takes in the head of the list, if available. If there is no head the node created
        will be set to the head of the list and the previous and next pointers will be set to 0.
        Otherwise if it is the second or procceding nodes it will set the next value of the
        head to the new node(x) and then sets that node's previous to the head node. 
        It also sets the next pointer of node(x)to the previously created node 
        unless there is only the head and it. In such a case it will set the node 
        createad after the head to the tail of the list.
      */
      
      std::cout << "Hit" << std::endl;
      
      if (prevNode != nullptr)
      {
        std::cout << "Hit" << std::endl;
        newNode->next=prevNode->next;
        prevNode->next=newNode;
        newNode->prev=prevNode;
        if (newNode->next!=nullptr)
          newNode->next->prev=newNode;
      }
      
      if (this->head==nullptr)
      {
        std::cout << "Hit3" << std::endl;
        this->head=newNode;
        this->tail=newNode;
        newNode->prev=nullptr;
        newNode->next=nullptr;
      }
      else if (this->tail==prevNode)
      {
        this->tail=newNode;
      }
    }
    
    void display()
    {
      /*
        Goes through each node in the list starting at 
        the head and prints out the value of each node.
      */
      Node* i=this->head;
      std::cout << "List: " ;
      while(i!=0)
      {
        std::cout << i->value << ",";
        i=i->next;
      }
      
      std::cout << std::endl;
    }
    
    void nodeRemove(Node* n)
    {
      /*
        Takes in a node. It gives the node's next value to its previous node 
        while giving the node's previous value to the next node. In the event it
        has no previous value it is assumed it is the head thus requiring the 
        change head pointer the next node in the list. If the node has no next 
        value it is assummed to be the tail thus the previous node will be 
        changed to the tail. 
      */
      if(n->prev != 0)
      {
        n->prev->next = n->next;
      }
      else
      {
        this->head = n->next;
      }
      if(n->next != 0)
      {
        n->next->prev = n->prev;
      }
      else
      {
        this->tail = n->prev;
      }
      
      delete n;
      
    }
    
  Node* getHead()
  {
    return this->head;
  }
  
  ~List()
  {
     /*
      When the list object is either deleted or goes out of scope this will be
      called. It will delete every node in the list by starting at the head
      and deleting every node as it replaces the head until there are no nodes to
      be the head.
    */
    std::cout << "List destructor!" << std::endl;
    //std::cout << "Todo: properly delete nodes..." << std::endl;
    while(this->head != 0)
    {
      nodeRemove(this->head);
    }
  }
  
};
 
int main(int argc, char *argv[])
{      
  List* l=new List();
  Node* head = l->getHead();
  l->insert(nullptr,new Node(4));
  head = l->getHead();
  std::cout << head->value << std::endl;
  l->insert(head,new Node(6));
  l->insert(head,new Node(8));
  l->display();
  delete l;
  return 0;
}
