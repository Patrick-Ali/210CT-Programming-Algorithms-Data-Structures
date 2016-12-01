#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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
  	
  	std::vector<Vertex*> priv_shuffle(std::vector<Vertex*> list)
    {
      /*
        Takes in a vector shuffles it and ouputs the shuffled vector
      */
      
      int numberOfSwaps = (rand()%10)+11; /* This will determine the number of times we swap pairs, 
      in this case it has a mxaimum of 20 swaps, this being an arbitrary number */
      
      for(int i = 1; i <= numberOfSwaps; i++)//loops until we reach the number of swamps
      {
          int num1 = (rand()%9);
          
          int num2 =  (rand()%9);
          
          while(num2 == num1) // making sure not to swap the same item
          {
             num2 = (rand()%9);
             
          }
          
          Vertex* hold = list[num1];
          //std::cout << list[num1]->data;
          list[num1] = list[num2];
          //std::cout << list[num1]->data << std::endl;
          list[num2] = hold;
          
      }
     
     return list; 
      
    }
    void priv_connectRandom()
  	{
  	  std::vector<Vertex*> shuffleList = priv_shuffle(nodeList);
  	  for(int i = 0; i < shuffleList.size(); i++)
  	  {
  	    std::cout << shuffleList[i]->data << std::endl;
  	  }
  	  //int current = 0;
  	 for(int i = 0; i < shuffleList.size(); i++)
  	 {

  	  	Vertex* hold = nodeList[i];
  	  	Vertex* temp = shuffleList[i];
  	  	Edge* node;
  	  	if(hold->data == temp->data)
  	  	 {
  	  	   if(i!=0)
  	  	   {
  	  	     temp = shuffleList[i-1];
  	  	   }
  	  	   else
  	  	   {
  	  	     temp = shuffleList[i+1];
  	  	   }
  	  	   node = new Edge();
  	  	   node->node1 = hold;
  	  	   node->node2 = temp;
  	  	 }
  	     else
        {
  	 // 	bool check = inEdgeList(i, temp->data, hold->data);
  	 // 	if(check==false)
  	 // 	{
  	 // 	  //std::cout << "Hit" << std::endl;
  	  	  //temp = shuffleList[i];
  	  	  node = new Edge();
  	  	  node->node1 = hold;
  	  	  node->node2 = temp;
  	  	  //std::cout << node->node1->data <<" is connection to: "<< node->node2->data << ", ";
  	  	  //std::cout << std::endl;
  	    	}
  	  	
  	  	hold->edgeList.push_back(node);
     	  temp->edgeList.push_back(node);
    // 	  if(i != nodeList.size()-1)
    // 	  {
    // 	    hold = nodeList[i+1];
    // 	    check = inEdgeList(i+1, temp->data, hold->data);
  	  	
  	 // 	  // std::cout << check << std::endl;
  	  	
    //     	 if(check == false)
    //     	 {
    
    //     	  	Edge* node3 = new Edge();
    //     	  	node3->node1 = hold;
    //     	  	node3->node2 = temp;
        	  	
    //     	  	hold->edgeList.push_back(node3);
    //     	  	temp->edgeList.push_back(node3);
    //   	   }
    // 	  }
  	  	


  	 // 	 //current+=1;
  	  }
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
  	  	
  	  	//std::cout << check << std::endl;
  	  	
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
  	    int value = hold->data;
  	    value == temp->node1->data ? std::cout << temp->node2->data << ", " :
  	    std::cout << temp->node1->data << ", ";
  	    //std::cout << temp->node1->data <<" is connected to: "<< temp->node2->data << ", ";
  	  }
  	}
  	
    void randomEdge()
    {
      priv_connectRandom();
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
      Vertex* start = nodeList[count];
      std::stack<Vertex*> s;
      std::vector<int> visited = {};
      s.push(start);
      start->logged=true;
      Vertex* hold = s.top();
      visited.push_back(hold->data);
      while(!s.empty())
      {
         int size = hold->edgeList.size();
         for(int i = 0; i < size; i++)
         {
           size = hold->edgeList.size();
           std::cout << "Starting: "<<hold->data << std::endl;
           std::cout << "Visited: "<<hold->logged << std::endl;
          // if(i<(size-1))
          // {
          //   i+=1
          // }
          // else 
          if(i>(size-1))
           {
             i-=1;
           }
           int data = hold->edgeList[i]->node1->data;
           std::cout << "data: "<<data<< std::endl;
           int data2 = hold->edgeList[i]->node2->data;
           std::cout << "data2: "<<data2 << std::endl;
           if(hold->data == data)
           {
               
             if (hold->edgeList[i]->node2->logged != true)
             {
                 std::cout << "Hold is: "<<hold->edgeList[i]->node2->data << std::endl;
                 hold = hold->edgeList[i]->node2;
                 hold->logged=true;
        //       //std::cout << "Hit" << std::endl;
                 s.push(hold);
        //       hold->logged=true;
        //       std::cout << hold->edgeList[i]->node2->data << std::endl;
        //       hold->edgeList[i]->node2->logged == true;
                 visited.push_back(hold->data);
                 i-=1;
        //       hold = hold->edgeList[i]->node2;
             }
             else if (hold->edgeList[i]->node1->logged != true)
             {
               std::cout << "Hold is3: " <<hold->edgeList[i]->node1->data << std::endl;
               hold = hold->edgeList[i]->node1;
               s.push(hold);
               hold->logged = true;
               visited.push_back(hold->data);
               i-=1;
             }
        //     //std::cout << hold->data << std::endl;
           }
            
           else if(hold->data == data2)
           {
             std::cout<< "Triggered " << std::endl;
             if (hold->edgeList[i]->node1->logged != true)
             {
                 std::cout << "Hold is2: " <<hold->edgeList[i]->node1->data << std::endl;
                 hold = hold->edgeList[i]->node1;
                 s.push(hold);
                 hold->logged = true;
        //       std::cout << hold->edgeList[i]->node2->data << std::endl;
        //       hold->edgeList[i]->node1->logged == true;
                 visited.push_back(hold->data);
        //       hold = hold->edgeList[i]->node1;
                 i-=1;
             }
             else if (hold->edgeList[i]->node2->logged != true)
             {
               std::cout << "Hold is3: " <<hold->edgeList[i]->node2->data << std::endl;
               hold = hold->edgeList[i]->node2;
               s.push(hold);
               hold->logged = true;
               visited.push_back(hold->data);
               i-=1;
             }
        //     //std::cout << hold->data << std::endl;
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
  	//static int numNodes = 0;
  
  
};

int main() 
{
  srand(static_cast<int>(time(0)));
  Graph g1;
  
  std::vector<int> values = {0,1,2,3,4,5,6,7,8,9,10};
  
  for(int i = 0; i < values.size(); i++)
  {
    g1.pub_addNode(values[i]);
  }
  
  g1.addEdge();
  //g1.shuffle();
  for(int i = 0; i < values.size(); i++)
  {
    int temp = g1.getNodeValue(i);
    //std::cout << temp << " ";
    // g1.getNodeAdj(i);
    //std::cout << std::endl;
  }
  //g1.randomEdge();
  
  //std::cout << values[(values.size()/2)] << std::endl;
  
  for(int i = 0; i < values.size(); i++)
  {
    int temp = g1.getNodeValue(i);
    std::cout << temp << " has these connections: ";
    g1.getNodeAdj(i);
    std::cout << std::endl;
  }
  std::vector<int> hold = g1.depthSearch(0);
  //hold.push_back(1);
  
  for(int i = 0; i < hold.size(); i++)
  {
    std::cout<<hold[i]<<", ";
  }
  
  return 0;

}