#include <iostream>
#include <vector>
#include <stack>
 
class BinTreeNode{
public:
  BinTreeNode(int value){
    this->value=value;
    this->logged=false;
    this->left=NULL;
    this->right=NULL;
  }
  int value;
  bool logged;
  BinTreeNode* parent;
  BinTreeNode* left;
  BinTreeNode* right;
 
};
 
BinTreeNode* tree_insert(BinTreeNode* tree, int item){
  if(tree==NULL)
  {
    tree=new BinTreeNode(item);
    }
  else
  {
    if(item < tree->value)
    {
      if(tree->left==NULL){
        tree->left=new BinTreeNode(item);
        tree->left->parent = tree;
        }
      	else
      	{
        tree_insert(tree->left,item);
       }
     }
    else
    {
      if(tree->right==NULL)
      {
        tree->right=new BinTreeNode(item);
        tree->right->parent = tree;
       }
      else
      {
        tree_insert(tree->right,item);
        }
     }
    }
  return tree;
 
}
 
void postorder(BinTreeNode* tree){
  if(tree->left!=NULL)
    postorder(tree->left);
  if(tree->right!=NULL)
    postorder(tree->right);
  std::cout << tree->value << std::endl;
 
}
 
void in_order(BinTreeNode* tree)
{
  BinTreeNode* current;
  std::stack<BinTreeNode*> s;
  //BinTreeNode *root = tree;
  current = tree;
  s.push(current);
  
  while(!s.empty())
  {
    while(current->left!=NULL)
    {
      current = current->left;
      s.push(current);
    }
  
    current = s.top();
    if(current->logged!= true)
    {
      std::cout << current->value << " ";
    }
    current->logged = true;
    s.pop();
    
    if(current->right != NULL)
    {
      //std::cout<<"Working 1";
      current = current->right;
      s.push(current);
    }
    
  }
  
  // current = tree;
  // s.push(current);
  // while(!s.empty())
  // {
  //   BinTreeNode* top = s.top();
  //   if(top != NULL)
  //   {
  //     if(!top->logged)
  //     {
  //     s.push(top->left);
  //     }
  //     else
  //     {
  //       std::cout << top->value << " ";
  //       s.pop();
  //       s.push(top->right);
  //     }
  //   }
  //   else
  //   {
  //     s.pop();
  //     if(!s.empty())
  //     {
  //       top->logged = true;
  //     }
  //   }
  // }

}

int main(int argc, char *argv[])
{
  BinTreeNode* t=tree_insert(0,6);
  tree_insert(t,10);
  tree_insert(t,5);
  tree_insert(t,2);
  tree_insert(t,8);
  tree_insert(t,1);
  tree_insert(t,3);
  tree_insert(t,4);
  tree_insert(t,7);
  tree_insert(t,11);
  tree_insert(t,9);
  in_order(t);
  return 0;
}