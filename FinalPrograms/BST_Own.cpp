#include <iostream>
#include <stack>
#include <vector>
#include <queue>

class BST;
void priv_Node_Match(int value);

class Node
{
    /*This class handles the iniation and destruction of a node*/
    
    friend class BST;
    
    private:
        int data;
        bool viewed;
        Node* left;
        Node* right;
        Node* parent; 
        
        Node(int value)
        {
            this->data=value;
            this->viewed=false;
            this->left=nullptr;
            this->right=nullptr;
            this->parent=nullptr;
        }
        
        ~Node()
        {
        }
};

class BST
{
    /*
        This class holds the functions to creates a binary tree,
        stores it and traverses it through in order traversal which will output 
        the contents of the tree to screen. 
    */
    private:
        Node* root;
        std::vector<Node*> nodeList;
        
        Node* priv_insert_node(Node* current, int value)
        {
            /*
                This takes in a value which it will insert into the tree 
                depending on whether it is larger or smaller than the parent.
                To do this it will go left if it is smaller or right if it is 
                bigger than the parent, in addition to this it will check 
                if the branch is empty as it will only insert when the child 
                branch is empty.
            */
            if(root == nullptr)
            {
                root = new Node(value);
            }
            else
            {
                if (current->data > value)
                {
                    if(current->left != nullptr)
                    {
                        return priv_insert_node(current->left, value);
                    }
                    else if(current->left == nullptr)
                    {   
                        Node* temp = current; 
                        current->left = new Node(value);
                        current->left->parent=current;
                        nodeList.push_back(current->left);
                        
                    }
                }
                else if(current->data < value)
                {
                    if(current->right != nullptr)
                    {
                        return priv_insert_node(current->right, value);
                    }
                    else if(current->right == nullptr)
                    {   
                        Node* temp = current;
                        current->right = new Node(value);
                        current->right->parent= current;
                        nodeList.push_back(current->right);
                        
                    }
                }
            }
        }
        void priv_in_order(Node* current )
        {
            /*
              This function will traverse the tree from a starting point 
              and will output the data in the tree in ascending order.
            */
            if(root == nullptr)
            {
                std::cout << "The tree is empty" << std::endl;
            }
            else
            {
                std::stack<Node*> s;
                std::vector<int> visited;
                s.push(current);
      
                while(!s.empty())
                {
                    /*
                        This will loop until the stack is empty. During this loop
                        it will move as far down the left until it can't then go 
                        back up and go right if it can. At each stage it will push
                        the current node onto the stack. Once a node has been added 
                        to the visited list it will be taken of the stack. 
                    */
                    while(current->left!=nullptr)
                    {
                        /*
                            This will continuely push the current node onto a stack
                            until the nodes left child is null at which point 
                            it can continue onto the next stage
                        */ 
                        current = current->left;
                        s.push(current);
                    }
      
                    current = s.top();
                    if(current->viewed!= true)
                    {
                        std::cout << current->data << " ";
                        visited.push_back(current->data);
                    }
                    current->viewed = true;
                    s.pop();
        
                    if(current->right != nullptr)
                    {
                        current = current->right;
                        s.push(current);
                    }
        
                }
            }
        }
        
        
    public:
        
        BST()
        {
            //If you initiate the tree without a value this will activate
            this->root = nullptr;
        }
        
        void diplayTree()
        {
            /*
                When calle this will print out all parents and any children they
                have, if there is no children on that side it will say so.
            */

            if(this->root == nullptr)
            {
                std::cout << "The Tree is empty" << std::endl;
            }
            else
            {
                Node* current = this->root;
                std::queue<Node*> q;
                q.push(current);
                while(!q.empty())
                {
                    std::cout << "Parent is: " << current->data << std::endl;
                    if(current->left !=nullptr)
                    {
                        std::cout << "Left child is: "<< current->left->data << std::endl;
                        q.push(current->left);
                    }
                    else if(current->left == nullptr)
                    {
                        std::cout << "Left child is Empty"<< std::endl;

                    }
                    
                    if(current->right !=nullptr)
                    {
                        std::cout << "Right child is: "<< current->right->data << std::endl;
                        q.push(current->right);
                    }
                    else if(current->right == nullptr)
                    {
                        std::cout << "Right child is Empty"<< std::endl;

                    }
                    
                    q.pop();
                    std::cout<<std::endl;
                    if(!q.empty())
                    {
                        current = q.front();
                    }
                }
            }
        }
        
        BST(int value)
        {
            //If you initiate the tree with a value this will activate
            this->root = new Node(value);

        }
        
        void pub_insert_node(int value)
        {
           // Public access for inserting a node into the tree
           priv_insert_node(this->root, value);
        }
        void pub_in_order(Node* current)
        {
            //Public access for initiating inorder sort
            priv_in_order(current);
        }
        void pub_tree_sort(std::vector<int> array)
        {
            /*
                Point where the user can add nodes to the tree and initiate the
                in order sort of the tree in the one place
            */
            for(int i = 0; i < array.size(); i++)
            {
                priv_insert_node(root,array[i]);
            }
            
            priv_in_order(root);
        }
        
        ~BST()
        {
            /*
                Destructor for the tree, it will delete every node in the tree
            */
            for(int i = 0; i < nodeList.size(); i++)
  	        {
      	        Node* temp = nodeList[i];
      	        delete temp;
  	        }
        }

};

int main()
{
    std::vector<int> array {6,10, 5, 2, 3, 4, 11, -1, 20};
    BST tree;

    tree.pub_tree_sort(array);
    
    tree.diplayTree();
    
    std::cout << std::endl;
    
    return 0;
}