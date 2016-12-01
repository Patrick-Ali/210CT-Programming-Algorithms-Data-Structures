#include <iostream>
#include <stack>
#include <vector>
 
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
  BinTreeNode* left;
  BinTreeNode* right;
 
};
 
BinTreeNode* tree_insert(BinTreeNode* tree, int item){
  if(tree==NULL)
    tree=new BinTreeNode(item);
  else
    if(item < tree->value)
      if(tree->left==NULL)
        tree->left=new BinTreeNode(item);
      else
        tree_insert(tree->left,item);
    else
      if(tree->right==NULL)
        tree->right=new BinTreeNode(item);
      else
        tree_insert(tree->right,item);
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
}

  void tree_sort(std::vector<int> array)
  {
    BinTreeNode* tree = tree_insert(0, array[0]);
    for(int i = 1; i < array.size(); i++)
    {
    tree_insert(tree,array[i]);
    }
    in_order(tree);
  }

 
int main(int argc, char *argv[])
{
  //BinTreeNode* t=tree_insert(0,6);
  std::vector<int> array {6,10, 5, 2, 3, 4, 11, -1, 20};
  // tree_insert(0,6);
  // tree_insert(t,10);
  // tree_insert(t,5);
  // tree_insert(t,2);
  // tree_insert(t,3);
  // tree_insert(t,4);
  // tree_insert(t,11);
  tree_sort(array);
  return 0;
}