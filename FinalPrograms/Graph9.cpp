#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>

class Graph;
class Edge;

class Vertex
{
  /*
    This class is the object vertex which will hold the nodes data, adjacency 
    list and a boolean falg for whether it has been viewed or not.
  */    
  friend Graph;
  
  private:
  
  	int data;
  	std::vector<Edge*> adjacencyList;
  	bool viewed;
  	
  	Vertex(int value)
  	{
  	  /*
  	    Constructor for the vertex class, sets the data to given value, the
  	    adjacency list to empty and the viewed flag to false.
  	  */
  	  this->data=value;
  	  this->adjacencyList = {};
  	  this->viewed=false;
  	}
  	
};

class Edge
{
  /*
    This class is the object edge which will hold the edges weight, pointer to 
    vertex 1 and vertex 2 (for a doubly connected relationship between vertecies) 
  */ 
  friend Graph;
  
  private:
  	int data;
  	int weight;
  	Vertex* node1;
  	Vertex* node2;
  	
  	Edge()
  	{
  	   /*
  	    Constructor for the edge class when weight is not given thus setting it 
  	    to 0, sets vertex pointer 1 and 2 to nullptr.
  	  */
  	  this->weight=0;
  	  node1 = nullptr;
  	  node2 = nullptr;
  	}
  	
  	Edge(int value)
  	{
  	   /*
  	    Constructor for the edge class when weight is given, sets vertex 
  	    pointer 1 and 2 to nullptr.
  	  */
  	  this->weight = value;
  	  node1 = nullptr;
  	  node2 = nullptr;
  	}
  	
  	void addWeight(int value)
  	{
  	   /*
  	    Allows the user the ability to add or alter an edges weight.
  	  */
  	  this->weight=value;
  	}
};

class Graph
{
   /*
  	  This class creates a graph object which will create vertecies and edges
  	  to connect them togther. From there it offers a two ways to create a 
  	  connection, mannualy and aoutomaticaly. Alongside these feauters the
  	  graph offer graph traversal functions including breadth and depth search.
  */
  private:
  	
  	std::vector<Vertex*> nodeList;
  	void priv_addNode(int value)
  	{
  	  Vertex* node = new Vertex(value);
  	  nodeList.push_back(node);
  	}
  	
  	bool inadjacencyList(int count, int value, int value2)
  	{
  	  Vertex* hold = nodeList[count];
  	  for(int i = 0; i < hold->adjacencyList.size(); i++)
  	  {
  	    Edge* temp = hold->adjacencyList[i];
  	    if(value == temp->node1->data or value == temp->node2->data)
  	    {
  	      return true;
  	    }
  	  }
  	  return false;
  	}
    	
  	void priv_connect()
  	{
  	  int current = 0;
  	  for(int i = nodeList.size()-1; i >= (nodeList.size()/2); i--)
  	  {

  	  	Vertex* hold = nodeList[current];
  	  	Vertex* temp;
  	  	Edge* node;
  	  	if(current == i)
  	  	{
  	  	  temp = nodeList[i-1];
  	  	  node = new Edge();
  	  	  node->node1 = hold;
  	  	  node->node2 = temp;
  	  	  
  	  	}
  	  	else
  	  	{
  	  	  temp = nodeList[i];
  	  	  node = new Edge();
  	  	  node->node1 = hold;
  	  	  node->node2 = temp;
  	  	  
  	  	}
  	  	
  	  	hold->adjacencyList.push_back(node);
    	  temp->adjacencyList.push_back(node);
    	  hold = nodeList[current+1];
  	  	
  	  	bool check = inadjacencyList(current+1, temp->data, hold->data);
  	  	
    	 if(check == false)
    	 {
    	  	Edge* node3 = new Edge();
    	  	node3->node1 = hold;
    	  	node3->node2 = temp;
    	  	
    	  	hold->adjacencyList.push_back(node3);
    	  	temp->adjacencyList.push_back(node3);
  	    }

  	  	current+=1;
  	  }
  	}
  	
  public:
  	Graph()
  	{
    	nodeList={};
  	}
  	
  	void manualConnection(int value1, int value2)
  	{
  	    Vertex* hold = nodeList[value1];
  	  	Vertex* temp = nodeList[value2];
  	  	Edge* node;
  	  	
  	  	if(value1 == value2)
  	  	{
  	  	  temp = nodeList[value2-1];
  	  	  node = new Edge();
  	  	  node->node1 = hold;
  	  	  node->node2 = temp;
  	  	  
  	  	}
  	  	else
  	  	{
  	  	  node = new Edge();
  	  	  node->node1 = hold;
  	  	  node->node2 = temp;
  	  	}
  	  	hold->adjacencyList.push_back(node);
    	  temp->adjacencyList.push_back(node);
  	}
  	
  	void pub_addNode(int value)
  	{
    	priv_addNode(value);
  	}
  	void addEdge()
  	{	
      priv_connect();
  	}
  	int getNodeValue(int count)
  	{
  	  Vertex* hold = nodeList[count];
  	  return hold->data;
  	}
  	 
  	int getNodeAdj(int count)
  	{
  	  Vertex* hold = nodeList[count];
  	  for(int i = 0; i < hold->adjacencyList.size(); i++)
  	  {
  	    Edge* temp = hold->adjacencyList[i];
  	    int value = hold->data;
  	    value == temp->node1->data ? std::cout << temp->node2->data << ", " :
  	    std::cout << temp->node1->data << ", ";
  	  }
  	}
  	
    void reset()
    {
      for(int i = 0; i<nodeList.size(); i++)
      {
        Vertex* temp = nodeList[i];
        temp->viewed = false;
      }
    }
    
    std::vector<int> depthSearch(int count)
    {
      Vertex* hold = nodeList[count];
      std::stack<Vertex*> s;
      std::vector<int> visited = {};
      s.push(hold);
      hold->viewed=true;
      visited.push_back(hold->data);
      while(!s.empty())
      {
         int size = hold->adjacencyList.size();
         for(int i = 0; i < size; i++)
         {
           size = hold->adjacencyList.size();
           if(i>(size-1))
           {
             i-=1;
           }
           int data = hold->adjacencyList[i]->node1->data;
           int data2 = hold->adjacencyList[i]->node2->data;
           if(hold->data == data)
           {
             if (hold->adjacencyList[i]->node2->viewed != true)
             {
                 hold = hold->adjacencyList[i]->node2;
                 hold->viewed=true;
                 s.push(hold);
                 visited.push_back(hold->data);
                 i=-1;
             }
             else if (hold->adjacencyList[i]->node1->viewed != true)
             {
               hold = hold->adjacencyList[i]->node1;
               s.push(hold);
               hold->viewed = true;
               visited.push_back(hold->data);
               i=-1;
             }

           }
            
           else if(hold->data == data2)
           {
               
             if (hold->adjacencyList[i]->node1->viewed != true)
             {
                 hold = hold->adjacencyList[i]->node1;
                 hold->viewed = true;
                 s.push(hold);
                 visited.push_back(hold->data);
                 i=-1;
             }
             else if (hold->adjacencyList[i]->node2->viewed != true)
             {
               hold = hold->adjacencyList[i]->node2;
               s.push(hold);
               hold->viewed = true;
               visited.push_back(hold->data);
               i=-1;
             }
           }
         }
        
        s.pop();
        if(!s.empty())
        {
           hold = s.top();
        }
       
      }
      reset();
      return visited;
      
    }
    
    std::vector<int> breadthSearch(int count)
    {
      Vertex* hold = nodeList[count];
      std::queue<Vertex*> q;
      std::vector<int> visited = {};
      q.push(hold);
      hold->viewed=true;
      visited.push_back(hold->data);
      Vertex* holding;
      while(!q.empty())
      {
          
         int size = hold->adjacencyList.size();
         for(int i = 0; i < size; i++)
         {
           size = hold->adjacencyList.size();

          if(i>(size-1))
           {
             i-=1;
           }
           int data = hold->adjacencyList[i]->node1->data;
           int data2 = hold->adjacencyList[i]->node2->data;
           if(hold->data == data)
           {
               
             if (hold->adjacencyList[i]->node2->viewed != true)
             {

                 holding = hold->adjacencyList[i]->node2;
                 holding->viewed=true;
                 q.push(holding);
                 visited.push_back(holding->data);
                 i-=1;
             }
             
             else if (hold->adjacencyList[i]->node1->viewed != true)
             {
               holding = hold->adjacencyList[i]->node1;
               q.push(holding);
               holding->viewed = true;
               visited.push_back(holding->data);
               i-=1;
             }

           }
            
           else if(hold->data == data2)
           {

             if (hold->adjacencyList[i]->node1->viewed != true)
             {
 
                 holding = hold->adjacencyList[i]->node1;
                 q.push(holding);
                 holding->viewed = true;
                 visited.push_back(holding->data);
                 i-=1;
             }
             else if (hold->adjacencyList[i]->node2->viewed != true)
             {
               holding = hold->adjacencyList[i]->node2;
               q.push(holding);
               holding->viewed = true;
               visited.push_back(holding->data);
               i-=1;
             }

           }
         }
        
        q.pop();
        
        if(!q.empty())
        {
           hold = q.front();
        }
       
      }
      reset();
      return visited;
      
    }
  	
};

int main() 
{
  
  Graph g1;
  
  std::vector<int> values = {0,1,2,3,4,5,6,7,8,9,10};
  
  for(int i = 0; i < values.size(); i++)
  {
    g1.pub_addNode(values[i]);
  }
  
  //Auto Connection - DON'T DELETE
  
  // g1.addEdge();
  
  // for(int i = 0; i < values.size(); i++)
  // {
  //   int temp = g1.getNodeValue(i);
  // }

  //Manual Connection:
  
  g1.manualConnection(0,2);
  g1.manualConnection(1,2);
  g1.manualConnection(0,3);
  g1.manualConnection(3,4);
  g1.manualConnection(2,4);
  g1.manualConnection(4,5);
  g1.manualConnection(1,5);
  g1.manualConnection(5,7);
  g1.manualConnection(4,6);
  g1.manualConnection(7,8);
  g1.manualConnection(6,8);
  g1.manualConnection(8,9);
  g1.manualConnection(9,10);
  g1.manualConnection(7,10);
  g1.manualConnection(6,10);
  
  
  for(int i = 0; i < values.size(); i++)
  {
    int temp = g1.getNodeValue(i);
    std::cout << temp << " has these connections: ";
    g1.getNodeAdj(i);
    std::cout << std::endl;
  }
  std::vector<int> hold = g1.depthSearch(0);
  
  std::cout<<"Depth First Search: ";
  
  for(int i = 0; i < hold.size(); i++)
  {
    std::cout<<hold[i]<<", ";
  }
  
  std::cout << std::endl;
  
  std::vector<int> holder = g1.breadthSearch(0);
  
  std::cout<<"Breadth First Search: ";
  
  for(int i = 0; i < holder.size(); i++)
  {
    std::cout<<holder[i]<<", ";
  }
  
  std::ofstream outf;
  outf.open("test2.dat", std::fstream::app);
  
  if(!outf)
  {
    std::cerr << "Undable to open program terminating program"<<std::endl;
    exit(1);
  }
  
  outf << "Deapth First Search:  ";
  
  for(const auto &e : hold)
  {
    outf << e << ", ";
  }
  
  outf << std::endl;
  
  outf << "Breadth First Search: ";
  
  for(const auto &e : holder)
  {
    outf << e << ", ";
  }
  
  outf << std::endl;
  
  return 0;

}