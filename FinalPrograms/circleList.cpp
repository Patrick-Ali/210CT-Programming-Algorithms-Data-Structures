#include <iostream>
#include <string>
 
//Nodes and lists use public data members for convenience
//This may make some software engineers froth at the mouth
 
class Node
{
public:
  std::string value; //This could really be any type
  Node* next;
  Node* prev;
  Node* linkHead;
  Node(std::string val){
    std::cout << "Node constructr!" << std::endl;
    this->value=val;
    this->next=(Node*)nullptr;
    this->prev=(Node*)nullptr;
    this->linkHead=(Node*)nullptr;
  }
  ~Node(){
    std::cout << "Node destructor" << std::endl;
    std::cout << "I had the value "<<this->value << std::endl;
  }
};
class List
{
 
public:
  // Atributes 
  Node* head;
  Node* tail;
 
  List(){
    std::cout << "List Constructor!" << std::endl;
    this->head=nullptr;
    this->tail=nullptr;
  }
  
  void insert( Node* x){
    //Not actually perfect: how do we prepend to an existing list?
    if (head != nullptr){
      x->next=head->next;
      head->next=x;
      x->prev=head;
      if (x->next!=nullptr)
        x->next->prev=x;
    }
    if (this->head==nullptr){
      this->head=x;
      this->tail=x;
      x->prev=nullptr;
      x->next=nullptr;
    }else if (this->tail==head){
      this->tail=x;
      x->linkHead = this->head;
    }
  }
  void display(){
    Node* i=this->head;
    std::cout << "List: " ;
    while(i!=0){
      std::cout << i->value << ",";
      i=i->next;
    }
    std::cout << std::endl;
  }
  
  void removeValue(Node *n)
  {
  
    while(this->head != this->tail)
    {
      if(n->linkHead != nullptr and n->next == nullptr)
      {
        nodeRemove(n->linkHead);
      }
      else{
        Node* current = n->next->next;
        nodeRemove(current);
      }
    }
    
    std::cout << this->tail->value << std::endl;
  }
  
  void nodeRemove(Node* n)
  {
    if(n->prev != nullptr)
    {
      n->prev->next = n->next;
    }
    else
    {
      this->head = n->next;
    }
    if(n->next != nullptr)
    {
      n->next->prev = n->prev;
    }
    else
    {
      this->tail = n->prev;
      //if(n->prev != this->head)
     // {
       // n->prev->linkHead = this->head;
      //}
    }
    
    delete n;
    
  }
  
  ~List(){
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
  l->insert(new Node("Diana"));
  l->insert(new Node("Michael"));
  l->insert(new Node("David"));
  l->display();
  l->removeValue(l->head);
  //delete l;
  return 0;
}
