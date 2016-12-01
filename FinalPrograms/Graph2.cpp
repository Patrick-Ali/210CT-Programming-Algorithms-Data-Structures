#include <iostream>
#include <vector>
#include <stack>

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
  	
  	//vertex()
  	//{
  	  //this->data = NULL;
  	  //this->edge = NULL;
  	//}
  	
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
  	  //this->data=value;
  	  this->weight=0;
  	  node1 = nullptr;
  	  node2 = nullptr;
  	}
  	
  	Edge(int value)
  	{
  	  //this->data=value;
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
  	//Vertex* head = nullptr;
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
  	    //bool triggered = false;
  	    //std::cout << i << std::endl;
  	  	// if(current == i)
  	  	// {
  	  	//   i+=1;
  	  	//   triggered = true;
  	  	// }
  	  	Vertex* hold = nodeList[current];
  	  	Vertex* temp;
  	  	Edge* node;
  	  	if(current == i)
  	  	{
  	  	  temp = nodeList[i-1];
  	  	  node = new Edge();
  	  	  node->node1 = hold;
  	  	  node->node2 = temp;
  	  	  //triggered = true;
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
  	  	
  	  	std::cout << check << std::endl;
  	  	
    	 if(check == false)
    	 {
    	  	// //Edge* node2 = new Edge();
    	  	Edge* node3 = new Edge();
    	  	node3->node1 = hold;
    	  	node3->node2 = temp;
    	  	
    	  	hold->edgeList.push_back(node3);
    	  	temp->edgeList.push_back(node3);
  	    }
  	  	// // hold->adjacencyList.push_back(node->data);
  	  	// // temp->adjacencyList.push_back(node2->data);
  	  	// // temp->adjacencyList.push_back(node3->data);
  	  	// hold = nodeList[current-1];
  	  	// if(current != 0 or current == i or triggered == true)
  	  	// {
  	  	//   	temp = nodeList[i+1];
  	  	//   	Edge* node4 = new Edge();
  	  	//   	node4->node1 = hold;
  	  	//     node4->node2 = temp;
  	  	//   	hold->edgeList.push_back(node4);
  	  	//     temp->edgeList.push_back(node4);
  	  	// }
  	  	// // if(triggered == true)
  	  	// // {
  	  	// //   i-=1;
  	  	// //   std::cout << i << std::endl;
  	  	// //   ;
  	  	// // }
  	  	// triggered=false;
  	  	current+=1;
  	  }
  	}
  	
  	void priv_addEdge()
  	{	
      priv_connect();
  	}
  	
  public:
  	Graph()
  	{
    	nodeList={};
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
  	    std::cout << temp->node1->data <<" is connected to: "<< temp->node2->data << ", ";
  	  }
  	}
  	//static int numNodes = 0;
  
  
};

int main() 
{
  Graph g1;
  
  std::vector<int> values = {0,1,2,3,4,5,6,7,8,9,10};
  
  for(int i = 0; i < values.size(); i++)
  {
    g1.pub_addNode(values[i]);
  }
  
  g1.addEdge();
  
  //std::cout << values[(values.size()/2)] << std::endl;
  
  for(int i = 0; i < values.size(); i++)
  {
    int temp = g1.getNodeValue(i);
    //std::cout << temp << " is connected to: ";
    g1.getNodeAdj(i);
    std::cout << std::endl;
  }
  
  return 0;

}