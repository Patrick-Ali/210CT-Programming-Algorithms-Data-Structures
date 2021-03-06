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
  friend Graph;
  
  private:
  
  	int data;
  	std::vector<Edge*> edgeList;
  	std::vector<int> adjacencyList;
  	bool logged;
  	
  	Vertex(int value)
  	{
  	  this->data=value;
  	  this->edgeList = {};
  	  this->logged=false;
  	}
  	
  	void addEdge(int value)
  	{
  	  adjacencyList.push_back(value);
  	}
};

class Edge
{
  friend Graph;
  private:
  	int data;
  	int weight;
  	Vertex* node1;
  	Vertex* node2;
  	
  	Edge()
  	{
  	  this->weight=0;
  	  node1 = nullptr;
  	  node2 = nullptr;
  	}
  	
  	Edge(int value)
  	{
  	  this->weight=0;
  	}
  	
  	void addWeight(int value)
  	{
  	  this->weight=value;
  	}
};

class Graph
{
  
  // put each node into a stack then randomly pop from this stack untill all nodes have an edge
  // start with node 1 doubly connect to a random node from the stack  don't pop it from the stack and
  // use that node as the new node to connect to
  private:
  	
  	std::vector<Vertex*> nodeList;
  	void priv_addNode(int value)
  	{
  	  Vertex* node = new Vertex(value);
  	  nodeList.push_back(node);
  	}
  	
  	bool inEdgeList(int count, int value, int value2)
  	{
  	  Vertex* hold = nodeList[count];
  	  for(int i = 0; i < hold->edgeList.size(); i++)
  	  {
  	    Edge* temp = hold->edgeList[i];
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
  	  	
  	  	hold->edgeList.push_back(node);
    	  temp->edgeList.push_back(node);
    	  hold = nodeList[current+1];
  	  	
  	  	bool check = inEdgeList(current+1, temp->data, hold->data);
  	  	
    	 if(check == false)
    	 {
    	  	Edge* node3 = new Edge();
    	  	node3->node1 = hold;
    	  	node3->node2 = temp;
    	  	
    	  	hold->edgeList.push_back(node3);
    	  	temp->edgeList.push_back(node3);
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
  	  	hold->edgeList.push_back(node);
    	  temp->edgeList.push_back(node);
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
  	  for(int i = 0; i < hold->edgeList.size(); i++)
  	  {
  	    Edge* temp = hold->edgeList[i];
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
        temp->logged = false;
      }
    }
    
    std::vector<int> depthSearch(int count)
    {
      Vertex* hold = nodeList[count];
      std::stack<Vertex*> s;
      std::vector<int> visited = {};
      s.push(hold);
      hold->logged=true;
      visited.push_back(hold->data);
      while(!s.empty())
      {
         int size = hold->edgeList.size();
         for(int i = 0; i < size; i++)
         {
           size = hold->edgeList.size();
           
           if(i>(size-1))
           {
             i-=1;
           }
           int data = hold->edgeList[i]->node1->data;
           int data2 = hold->edgeList[i]->node2->data;
           if(hold->data == data)
           {
               
             if (hold->edgeList[i]->node2->logged != true)
             {
                 hold = hold->edgeList[i]->node2;
                 hold->logged=true;
                 s.push(hold);
                 visited.push_back(hold->data);
                 i-=1;
             }
             else if (hold->edgeList[i]->node1->logged != true)
             {
               hold = hold->edgeList[i]->node1;
               s.push(hold);
               hold->logged = true;
               visited.push_back(hold->data);
               i-=1;
             }

           }
            
           else if(hold->data == data2)
           {
             
             if (hold->edgeList[i]->node1->logged != true)
             {
                 hold = hold->edgeList[i]->node1;
                 s.push(hold);
                 hold->logged = true;
                 visited.push_back(hold->data);
                 i-=1;
             }
             else if (hold->edgeList[i]->node2->logged != true)
             {
               hold = hold->edgeList[i]->node2;
               s.push(hold);
               hold->logged = true;
               visited.push_back(hold->data);
               i-=1;
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
      hold->logged=true;
      visited.push_back(hold->data);
      Vertex* holding;
      while(!q.empty())
      {
          
         int size = hold->edgeList.size();
         for(int i = 0; i < size; i++)
         {
           size = hold->edgeList.size();

          if(i>(size-1))
           {
             i-=1;
           }
           int data = hold->edgeList[i]->node1->data;
           int data2 = hold->edgeList[i]->node2->data;
           if(hold->data == data)
           {
               
             if (hold->edgeList[i]->node2->logged != true)
             {

                 holding = hold->edgeList[i]->node2;
                 holding->logged=true;
                 q.push(holding);
                 visited.push_back(holding->data);
                 i-=1;
             }
             
             else if (hold->edgeList[i]->node1->logged != true)
             {
               holding = hold->edgeList[i]->node1;
               q.push(holding);
               holding->logged = true;
               visited.push_back(holding->data);
               i-=1;
             }

           }
            
           else if(hold->data == data2)
           {

             if (hold->edgeList[i]->node1->logged != true)
             {
 
                 holding = hold->edgeList[i]->node1;
                 q.push(holding);
                 holding->logged = true;
                 visited.push_back(holding->data);
                 i-=1;
             }
             else if (hold->edgeList[i]->node2->logged != true)
             {
               holding = hold->edgeList[i]->node2;
               q.push(holding);
               holding->logged = true;
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
  
  std::vector<int> values = {0,1,2,3,4,5};
  
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
  
  
  for(int i = 0; i < values.size(); i++)
  {
    int temp = g1.getNodeValue(i);
    std::cout << temp << " has these connections: ";
    g1.getNodeAdj(i);
    std::cout << std::endl;
  }
  std::vector<int> hold = g1.depthSearch(0);
  
  
  for(int i = 0; i < hold.size(); i++)
  {
    std::cout<<hold[i]<<", ";
  }
  
  std::cout << std::endl;
  
  std::vector<int> holder = g1.breadthSearch(0);
  
  
  for(int i = 0; i < holder.size(); i++)
  {
    std::cout<<holder[i]<<", ";
  }
  
  std::ofstream outf;
  outf.open("test.dat", std::fstream::app);
  
  if(!outf)
  {
    std::cerr << "Undable to open program terminating program"<<std::endl;
    exit(1);
  }
  
  for(const auto &e : hold)
  {
    outf << e << ", ";
  }
  
  outf << std::endl;
  
  for(const auto &e : holder)
  {
    outf << e << ", ";
  }
  
  outf << std::endl;
  
  return 0;

}