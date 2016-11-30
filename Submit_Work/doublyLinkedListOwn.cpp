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
    int value;
    Node(int val)
    {
      std::cout << "Node constructr!" << std::endl;
      this->value=val;
      this->next=nullptr;
      this->prev=nullptr;
    }
    
  public:
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
    which will point to their previous and succeeding thus creating a doubly 
    linked list. This list is headed with a head pointer which denotes the beginning
    of the list and the end is denoted with a tail pointer.
  */
  
private:
    Node* head;
    Node* tail;
    
    Node* priv_getNode(int value)
    {
      /*
        This will take in a value and search the list for it, if found it will
        return that node else it will return a nullptr as it could not find it.
      */
      if(this->head == nullptr)
      {
        std::cout << "This list is empty" << std::endl;
        return nullptr;
      }
      else
      {
        Node* hold = this->head;
        while(hold != nullptr)
        {
          if(hold->value == value)
          {
            return hold;
          }
          else
          {
            hold = hold->next;
          }
        }
        return nullptr;
      }
    }
    
    void priv_insertNode(int value1, int value2)
    {
      /* 
        Takes in 2 values, the first it will use to find the previous node in the list and the second
        will be used to make a new node that will be inserted after the previous node. From there it 
        will set the new node’s previous pointer to the previous node (prevNode) and the next pointer
        to the previous node's next. In the case where there is only it and the previous it will be set 
        as the lists tail and the next node will be left as a nullptr.

      */
      Node* prevNode = priv_getNode(value1); 
      Node* newNode = new Node(value2);
      
      if (prevNode != nullptr)
      {
        newNode->next=prevNode->next;
        prevNode->next=newNode;
        newNode->prev=prevNode;
        if (newNode->next!=nullptr)
          newNode->next->prev=newNode;
      }
      

      if (this->tail==prevNode)
      {
        this->tail=newNode;
      }
    }
    
    void priv_insertHead(int value)
    {
      /*
        This function takes a value to make a new node and change the head
        and tale of the doubly linked list to this new node. This function 
        allows the user to insert a node as the head of the list when they begin
        building the doubly linked list. This should only be used when the list
        is empty.
      */
        this->head=new Node (value);
        this->tail=new Node (value);
    }
    
    void priv_nodeRemove(Node* n)
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
 
public:
  // Atributes 
    List()
    {
      /* Initialise the list with head and tail as 0 as there is no values in the list yet*/
      std::cout << "List Constructor!" << std::endl;
      this->head=nullptr;
      this->tail=nullptr;
    }
    
    void insertNode(int prevValue, int newValue)
    {
      priv_insertNode(prevValue, newValue);
    }
    
    void insertHead( int newValue)
    {
      priv_insertHead(newValue);
    }
    
    void display()
    {
      /*
        Goes through each node in the list starting at 
        the head and prints out the value of each node.
      */
      Node* temp = this->head;
      std::cout << "List: " ;
      while(temp != nullptr)
      {
        std::cout << temp->value; 
        temp = temp->next;
        if(temp != nullptr)
        {
         std::cout<<", "; 
        }
      }
      
      std::cout << std::endl;
    }
    
    void removeNode(Node* n)
    {
      priv_nodeRemove(n);
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
    while(this->head != 0)
    {
      removeNode(this->head);
    }
  }
  
};
 
int main(int argc, char *argv[])
{      
  List* l = new List();
  l->insertHead(4);
  l->insertNode(4, 6);
  l->insertNode(4, 8);
  l->display();
  delete l;
  return 0;
}
