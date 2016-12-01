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
    double tentWeight;
    Vertex* previous;
  	std::vector<Edge*> adjacencyList;
  	bool viewed;
  	
  	Vertex(int value)
  	{
  	  /*
  	    Constructor for the vertex class, sets the data to given value, the
  	    adjacency list to empty and the viewed flag to false. This is in the 
  	    private area as we only want the graph to be able to create a new 
  	    vertex.
  	  */
  	  this->data=value;
  	  this->adjacencyList = {};
  	  this->viewed=false;
  	  this->tentWeight = 999999999999999999;
  	  this->previous = nullptr;
  	}
  	
  public:
    
  	~Vertex()
  	{
  	    /*
  	        This is the destructor for the Vertex class. In this it perfroms 
  	        the 'clean up' operations for the class, this means reseting the 
  	        adjacency list as we don't want pointers to unkown memory locations 
  	    */
  	    this->adjacencyList = {};
  	}
  	
};


class Edge
{
  /*
    This class is the object edge which will hold the edges weight, pointer to 
    vertex 1 and vertex 2 (for a doubly connected relationship 
    between vertecies) 
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
  	  this->node1 = nullptr;
  	  this->node2 = nullptr;
  	}
  	
  	Edge(int value)
  	{
  	   /*
  	    Constructor for the edge class when weight is given, sets vertex 
  	    pointer 1 and 2 to nullptr.
  	  */
  	  this->weight = value;
  	  this->node1 = nullptr;
  	  this->node2 = nullptr;
  	}
  	
  	void addWeight(int value)
  	{
  	   /*
  	    Allows the user the ability to add or alter an edges weight.
  	  */
  	  this->weight=value;
  	}
  	
 public:
    ~Edge()
    {
        this->node1 = nullptr;
        this->node2 = nullptr;
   
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
  	std::vector<Edge*> edgeList;
  	
  	void priv_addNode(int value)
  	{
  	  /*
  	    This will create a new node and add it to the graph node array so as to
  	    keep track of it.
  	  */
  	  Vertex* node = new Vertex(value);
  	  nodeList.push_back(node);
  	}
  	
  	bool inadjacencyList(int count, int value, int value2)
  	{
  	   /*
  	     This will check the nodes adjacency array to see if the edge we want 
  	     to add is already in the array. This is done by checking each Edge's 
  	     pointers for the passed in value. If it is in the aray it will return
  	     true else it will return false indicating it is in the array.
  	  */  
  	  Vertex* hold = nodeList[count];
  	  for(int i = 0; i < hold->adjacencyList.size(); i++)
  	  {
  	    /*
  	        Loops through the adjacency array checking the pointers of the edge 
  	        for the value we passed in, this being the value we want to connect 
  	        to.
  	    */ 
  	    Edge* temp = hold->adjacencyList[i];
  	    if(value == temp->node1->data or value == temp->node2->data)
  	    {
  	      return true;
  	    }
  	  }
  	  return false;
  	}
    	
  	void priv_autoConnect()
  	{
  	   /*
  	    This will create a new edge between two nodes and add it to the graph
  	    edge array so as to keep track of it. It will then add this edge to the
  	    adjacency list for both the nodes it connects to. 
  	    This will connect all nodes togther automaticaly, so the first half the
  	    list will will connect with the top half. Then it will go up one node in
  	    the graph node array and connect it to its corresponding number in 
  	    the other half of the lsit. An example being 0 through 10, 0 and 10 will
  	    connect then 1 and 10 will connect.
  	  */
  	  int current = 0;
  	  for(int i = nodeList.size()-1; i >= (nodeList.size()/2); i--)
  	  {
  	    /*
  	       This will loop until it reaches the middle of the list as by this 
  	       point all nodes should be connected togther forming a connected graph.
  	    */ 

  	  	Vertex* hold = nodeList[current];
  	  	Vertex* temp;
  	  	Edge* node;
  	  	
  	  	if(current == i)//Checking to see if the node is trying to connect with itself
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
  	  	
  	  	//ADD A CHECK HERE
  	  	bool check = inadjacencyList(current+1, temp->data, hold->data);
  	  	if(check == false)
  	  	{
  	  	  hold->adjacencyList.push_back(node);
    	  temp->adjacencyList.push_back(node);
  	  	}
  	  	
    	hold = nodeList[current+1];
    	
  	  	check = inadjacencyList(current+1, temp->data, hold->data);
  	  	
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
  	
  	std::vector<Vertex*> bubbleSort(std::vector<Vertex*> hold)
  	{
  	    /*
  	        This will sort a given list so that the lowest value is first going 
  	        through until the largest value.
  	    */
  	 if(!hold.empty())
     {
  	    for(int i = 0; i < hold.size()-1; i++)
        {
            /*
                First stage of the sorting so as to make sure the whole list is 
                sorted
            */


                for(int j = 0; j < hold.size()-1; j++)
                {
                    /*
                        Second Stage of the sort which will swap pairs if the
                        current value is smaller than the next
                    */
                    
                    if(hold[j]->tentWeight > hold[j+1]->tentWeight)
                    {
                        Vertex* temp = hold[j];
                        hold[j] = hold[j+1];
                        hold[j+1] = temp;
                    }
                }
        }
      }
        
        return hold;
  	}
  	
  	std::vector<Vertex*> priv_dijkstra(int start)
  	{
  	    /*
  	        This fucntion will map the graph by starting at a given point and 
  	        assigning a weight to each connected vertex in the graph based on 
  	        its distance from the start vertex.
  	    */
  	    std::vector<Vertex*> visited;
  	    std::vector<Vertex*> hold;
  	    std::queue<Vertex*> pq;
  	    Vertex* current = getVertex(start);
  	    if(current == nullptr)
  	    {
  	        return visited;
  	    }
  	    else
  	    {
  	        
  	        for(int i = 0; i < nodeList.size(); i++)
      	    {
      	      nodeList[i]->viewed = false;
      	      nodeList[i]->previous = nullptr;
      	      nodeList[i]->tentWeight = 999999999999999999;
      	      pq.push(nodeList[i]);
      	    }
      	    
      	  current->tentWeight = 0;  
      	    
      	   while(!pq.empty())
           {
             /*
                This will empty the que putting it into a list for sorting.
             */  
             hold.push_back(pq.front());
             pq.pop();
           }
            
            hold = bubbleSort(hold);//Sort the list from smallest to largest

            for(int i = 0; i < hold.size(); i++)
            {
                /*
                  Refil the list based upon the sorted list so that the vertex 
                  with the lowest weight is now at the front.
                */
                pq.push(hold[i]);
            }
                  	
            hold = {};
      	    
      	    while(!pq.empty())
      	    {
      	        /*
      	            While the que is not empty it should take the first vertex
      	            in the que and perform a breadth search onit so as to
      	            generate the weight for each node in the graph
      	        */
      	        current = pq.front();
      	        pq.pop();
      	        current->viewed = true;
      	        visited.push_back(current);
      	        int size = current->adjacencyList.size();
                for(int i = 0; i < size; i++)
                {
                   /*
                      This will iterate through a given nodes adjacency list 
                      until it reaches the end. In each iteration it will check
                      if the connected node has been viewed, if it has it goes 
                      onto the next iteration. Otherwise it will look at the 
                      tentative weight of the previous node i.e. the current 
                      node, add this onto the connectons (edge) weight and see 
                      if the total is less than the connected vertexs tentative 
                      weight.
                   */ 
                  int data = current->adjacencyList[i]->node1->data;
                  int data2 = current->adjacencyList[i]->node2->data;
                  if(current->data == data)
                  {
                       
                    if (current->adjacencyList[i]->node2->viewed != true)
                    {
        
                         Vertex* holding = current->adjacencyList[i]->node2;
                         Edge* holder = current->adjacencyList[i];
                         int weight = current->tentWeight + holder->weight;
                         if(holding->tentWeight > weight)
                         {
                             holding->tentWeight = weight;
                             holding->previous = current;
                         }

                     }
                     
                    else if (current->adjacencyList[i]->node1->viewed != true)
                    {
                         Vertex* holding = current->adjacencyList[i]->node1;
                         Edge* holder = current->adjacencyList[i];
                         int weight = current->tentWeight + holder->weight;
                         if(holding->tentWeight > weight)
                         {
                             holding->tentWeight = weight;
                             holding->previous = current;
                         }
                    }
        
                   }
                    
                  else if(current->data == data2)
                   {
        
                     if (current->adjacencyList[i]->node1->viewed != true)
                     {
                         Vertex* holding = current->adjacencyList[i]->node1;
                         Edge* holder = current->adjacencyList[i];
                         int weight = current->tentWeight + holder->weight;
                         if(holding->tentWeight > weight)
                         {
                             holding->tentWeight = weight;
                             holding->previous = current;
                         }

                     }
                     else if (current->adjacencyList[i]->node2->viewed != true)
                     {
                         Vertex* holding = current->adjacencyList[i]->node2;
                         Edge* holder = current->adjacencyList[i];
                         int weight = current->tentWeight + holder->weight;
                         if(holding->tentWeight > weight)
                         {
                             holding->tentWeight = weight;
                             holding->previous = current;
                         }
                     }
        
                   }
      	    }
      	        if(!pq.empty())
      	        {
                  while(!pq.empty())
                  {
                     /*
                        This will empty the que putting it into a list for sorting.
                     */  
                     hold.push_back(pq.front());
                     pq.pop();
                  }
            
                 hold = bubbleSort(hold);//Sort the list from smallest to largest

                 for(int i = 0; i < hold.size(); i++)
                 {
                    /*
                      Refil the list based upon the sorted list so that the vertex 
                      with the lowest weight is now at the front.
                    */
                    pq.push(hold[i]);
                 }
                  	
                  	hold = {};
      	        }
  	    }
  	    

  	     return visited;
  	    
  	  }
  	 
  	}
  	
  	void priv_manualConnection(int value1, int value2, int weight)
  	{
  	   /*
  	    This will create a new edge which connects two nodes togther. This 
  	    being the function where the user can manualy connect two nodes togther
  	  */
  	    Vertex* hold = getVertex(value1);
  	  	Vertex* temp = getVertex(value2);
  	  	Edge* node;
  	  	
  	  	if(value1 == value2)
  	  	{
  	  	  temp = nodeList[value2-1];
  	  	  node = new Edge(weight);
  	  	  node->node1 = hold;
  	  	  node->node2 = temp;
  	  	  
  	  	}
  	  	else
  	  	{
  	  	  node = new Edge(weight);
  	  	  node->node1 = hold;
  	  	  node->node2 = temp;
  	  	}
  	  	bool check = inadjacencyList(value1, temp->data, hold->data);
  	  	if(check == false)
  	  	{
      	  	hold->adjacencyList.push_back(node);
        	temp->adjacencyList.push_back(node);
        	edgeList.push_back(node);
  	  	}
  	  	else if(check == true)
  	  	{
  	  	    std::cout << "Connection already exists"<<std::endl;
  	  	    delete node;
  	  	    
  	  	}
  	}
  	
  	void reset()
    {
      /*
        Go through the node list and reset the nodes to unviewed so other
        functions work correctly.
      */
      for(int i = 0; i<nodeList.size(); i++)
      {
        Vertex* temp = nodeList[i];
        temp->viewed = false;
      }
    }
    
    std::vector<int> priv_depthSearch(int start)
    {
      /*
        This function takes in the starting point and begins traversing the 
        connections between node until there is no connection. Once it reaches
        that point it will go down anyother connections in the current node
        till all conections are visted. It will then go back a node and repeat
        this until all nodes have been visited. To do this it uses a stack that
        you add to as you visit each node so once all connections are exhausted 
        in current node it will be poped of the stack and the top of the stack 
        will become the current node. This function returns the visited list.  
      */
      Vertex* hold = getVertex(start);
      std::stack<Vertex*> s;
      std::vector<int> visited = {};
      s.push(hold);
      hold->viewed=true;
      visited.push_back(hold->data);
      if(hold == nullptr)
      {
          std::cout << "This start point is out of bounds" << std::endl;
      }
      else
      {
          while(!s.empty())
          {
             /*
                While the stack is not empty it will traverse the graph by going as 
                far as it can, e.g. until there is no connection. Adding to the 
                stack when it visits a node and poping when all of the nodes 
                connections are exhausted   
             */ 
             int size = hold->adjacencyList.size();
             for(int i = 0; i < size; i++)
             {
               /*
                 Iterates over a nodes adjacency list checking if the connected node
                 has been visited. If it has been visited it continues onto the next
                 edge otherwise it will add the connected node value to the value 
                 lsit. psuh the connected node to the stack and  mark it as viewed, 
                 change current node to the connected node and resets the iteration
                 counter to the begining of the adjacency lsit. 
               */ 
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
      }
      reset();
      return visited;
      
    }
    
    std::vector<int> priv_breadthSearch(int start)
    {
      /*
         This implements a Breadth First Search traversal of the graph
         this will take in a starting node and look at all the nodes connected 
         to it. As a node is visited it will be added to the que so that 
         once all the connected nodes of a given node are visited it will move 
         onto the first node in the que. It will repeat this activity untill 
         all nodes in the graph are visited. This function returns the visited
         list.
      */    
      Vertex* hold = getVertex(start);
      std::queue<Vertex*> q;
      std::vector<int> visited = {};
      q.push(hold);
      hold->viewed=true;
      visited.push_back(hold->data);
      Vertex* holding;
      if(hold == nullptr)
      {
          std::cout << "This start point is out of bounds" << std::endl;
      }
      else
      {
          while(!q.empty())
          {
             /*
                While the que still has something in it, it will look at all 
                connected nodes to the current node. This will go till all nodes are
                visited and the que is empty.
             */ 
             int size = hold->adjacencyList.size();
             for(int i = 0; i < size; i++)
             {
               /*
                  This will iterate through a given nodes adjacency list until it
                  reaches the end. In each iteration it will check if the connected
                  node has been viewed, if it has it goes onto the next iteration. 
                  Otherwise it will add it to the que, mark it as visited and add 
                  the connected nodes value to visited list.
               */ 
              
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
                 }
                 
                 else if (hold->adjacencyList[i]->node1->viewed != true)
                 {
                   holding = hold->adjacencyList[i]->node1;
                   q.push(holding);
                   holding->viewed = true;
                   visited.push_back(holding->data);
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
                 }
                 
                 else if (hold->adjacencyList[i]->node2->viewed != true)
                 {
                   holding = hold->adjacencyList[i]->node2;
                   q.push(holding);
                   holding->viewed = true;
                   visited.push_back(holding->data);
                 }
    
               }
             }
            
            q.pop();
            
            if(!q.empty())
            {
               hold = q.front();
            }
           
        }
      }
      reset();
      return visited;
      
    }
  	
  public:
  	Graph()
  	{
  	    /*
  	        This is the constructor for the graph and will set the lists as 
  	        empty.
  	    */
    	this->nodeList={};
    	this->edgeList={};
  	}
  	
  	Vertex* getVertex(int value)
  	{
  	    /*
  	        This will take in a value and will iterate through the current 
  	        graph's node list to see if it is in there. If it is it will return
  	        it otherwise it returns a null pointer. 
  	    */
  	    for(int i = 0; i < nodeList.size(); i++)
  	    {
  	        /*
  	            Iterates through the node list setting a temp vertex pointer so
  	            as to check to see if the vertex's data matches the value. 
  	        */
  	        Vertex* current = nodeList[i];
  	        if(current->data == value)
  	        {
  	            return current;
  	        }
  	        
  	    }
  	    return nullptr;
  	}
  	
  	void printDijkstra(std::vector<Vertex*> hold)
  	{
  	    /*
  	        The ability to print the shortest path from a vertex to all other 
  	        vertexes in the graph to screen
  	    */
  	    for(int i = 0; i < hold.size(); i++)
        {
          /*
            Goes trhough the gaphs Vertex list printing out the distance between
            them and the start vertex along with the previoius vetex so you can 
            form a path between the vertexs.
          */    
          Vertex* current = hold[i];
          std::cout <<"Vertex: " << current->data <<" Weight: "<< current->tentWeight << " ";
          current->previous == nullptr ? std::cout<< "Start" << std::endl : 
          std::cout<< "Previous: "<< current->previous->data<< std::endl;
        }
  
  	}
  	
  	std::vector<Vertex*> dijkstra(int start)
    {
        /*
           Public access to initiate the depth search
        */
        std::vector<Vertex*> temp = priv_dijkstra(start);
        return temp;
    }
  	
  	void manualConnection(int value1, int value2, int weight)
  	{
  	    /*
  	        Public access for manualy connecting two vertexs
  	    */
  	    priv_manualConnection(value1, value2, weight);
  	}
  	
  	void pub_addNode(int value)
  	{
  	    /*
  	       Public access point to add a Vertex
  	    */
    	priv_addNode(value);
  	}
  	
  	void autoConnection()
  	{
  	  /*
  	     Public access point to initiate the auto connect function
  	  */  
      priv_autoConnect();
  	}
  	
  	int getNodeValue(int count)
  	{
  	  /*
  	    Public access point to get a Vertex's data
  	  */ 
  	  if(count > nodeList.size())
  	  {
  	      std::cout << "This Numbe is out of range" << std::endl;
  	      return 9999999;
  	  }
  	  else
  	  {
  	      
  	  	  Vertex* hold = nodeList[count];
  	  	  return hold->data;
  	  }
  	  
  	}
  	 
  	void printConnections(int count)
  	{
  	  /*
  	    This will go through a nodes adjacency list and will print out the 
  	    appropiate value based on which node in the edge points to it and to the
  	    connecting node.
  	  */
  	  Vertex* hold = nodeList[count];
  	  for(int i = 0; i < hold->adjacencyList.size(); i++)
  	  {
  	    Edge* temp = hold->adjacencyList[i];
  	    int value = hold->data;
  	    value == temp->node1->data ? std::cout << temp->node2->data << ", " :
  	    std::cout << temp->node1->data << ", ";
  	  }
  	}
    
    std::vector<int> depthSearch(int start)
    {
        /*
           Public access to initiate the depth search
        */
        std::vector<int> temp = priv_depthSearch(start);
        return temp;
    }
    
    std::vector<int> breadthSearch(int start)
    {
        /*
           Public access to initiate the breadth search
        */
        std::vector<int> temp = priv_breadthSearch(start);
        return temp;
    }
    
    ~Graph()
  	{
  	    /*
  	        Graph destructor, this will delete all nodes in the node list first
  	        then it will delete all edges in the edge list.
  	    */
  	    for(int i = 0; i < nodeList.size(); i++)
  	    {
  	        Vertex* temp = nodeList[i];
  	        delete temp;
  	    }
  	    
  	    this->nodeList = {};
  	    
  	    for(int i = 0; i < edgeList.size(); i++)
  	    {
  	        Edge* temp = edgeList[i];
  	        delete temp;
  	    }
  	    
  	    this->edgeList = {};
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
  
  //Auto Connection - DON'T DELETE - DOSEN'T WORK WITH DIJKSTRA
  
  // g1.addEdge();
  
  // for(int i = 0; i < values.size(); i++)
  // {
  //   int temp = g1.getNodeValue(i);
  // }

  //Manual Connection:
  
  g1.manualConnection(0,2,2);
  g1.manualConnection(1,2,1);
  g1.manualConnection(0,3,3);
  g1.manualConnection(3,4,4);
  g1.manualConnection(2,4,4);
  g1.manualConnection(4,5,4);
  g1.manualConnection(1,5,5);
  g1.manualConnection(5,7,7);
  g1.manualConnection(4,6,6);
  g1.manualConnection(7,8,8);
  g1.manualConnection(6,8,8);
  g1.manualConnection(8,9,8);
  g1.manualConnection(9,10,9);
  g1.manualConnection(7,10,10);
  g1.manualConnection(6,10,10);
  g1.manualConnection(0,2,2);
  
  
  for(int i = 0; i < values.size(); i++)
  {
    int temp = g1.getNodeValue(i);
    std::cout << temp << " has these connections: ";
    g1.printConnections(i);
    std::cout << std::endl;
  }
  std::vector<int> hold = g1.depthSearch(0);
  
  std::cout<<"Depth First Search:   ";
  
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
  
  std::cout << std::endl;
  
  std::ofstream outf;
  outf.open("test2.txt", std::fstream::app);
  
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
  
  std::cout<<std::endl;
  
  //int start = 2;
  
  std::vector<Vertex*> temp = g1.dijkstra(0);
  
  g1.printDijkstra(temp);
  
  return 0;

}