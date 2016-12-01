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
    This class is the object vertex which will hold the vertex's data, adjacency 
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
  	Vertex* vertex1;
  	Vertex* vertex2;
  	
  	Edge()
  	{
  	   /*
  	    Constructor for the edge class when weight is not given thus setting it 
  	    to 0, sets vertex pointer 1 and 2 to nullptr.
  	  */
  	  this->weight=0;
  	  this->vertex1 = nullptr;
  	  this->vertex2 = nullptr;
  	}
  	
  	Edge(int value)
  	{
  	   /*
  	    Constructor for the edge class when weight is given, sets vertex 
  	    pointer 1 and 2 to nullptr.
  	  */
  	  this->weight = value;
  	  this->vertex1 = nullptr;
  	  this->vertex2 = nullptr;
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
        this->vertex1 = nullptr;
        this->vertex2 = nullptr;
   
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
  	
  	std::vector<Vertex*> vertexList;
  	std::vector<Edge*> edgeList;
  	
  	void priv_addVertex(int value)
  	{
  	  /*
  	    This will create a new vertex and add it to the graph vertex array so as to
  	    keep track of it.
  	  */
  	  Vertex* vertex = new Vertex(value);
  	  vertexList.push_back(vertex);
  	}
  	
  	bool inadjacencyList(int count, int value, int value2)
  	{
  	   /*
  	     This will check the vertex's adjacency array to see if the edge we want 
  	     to add is already in the array. This is done by checking each Edge's 
  	     pointers for the passed in value. If it is in the aray it will return
  	     true else it will return false indicating it is in the array.
  	  */  
  	  Vertex* hold = vertexList[count];
  	  for(int i = 0; i < hold->adjacencyList.size(); i++)
  	  {
  	    /*
  	        Loops through the adjacency array checking the pointers of the edge 
  	        for the value we passed in, this being the value we want to connect 
  	        to.
  	    */ 
  	    Edge* temp = hold->adjacencyList[i];
  	    if(value == temp->vertex1->data or value == temp->vertex2->data)
  	    {
  	      return true;
  	    }
  	  }
  	  return false;
  	}
    	
  	void priv_autoConnect()
  	{
  	   /*
  	    This will create a new edge between two vertices and add it to the graph
  	    edge array so as to keep track of it. It will then add this edge to the
  	    adjacency list for both the vertices it connects to. 
  	    This will connect all vertices togther automaticaly, so the first half the
  	    list will will connect with the top half. Then it will go up one vertex in
  	    the graph vertex array and connect it to its corresponding number in 
  	    the other half of the lsit. An example being 0 through 10, 0 and 10 will
  	    connect then 1 and 10 will connect.
  	  */
  	  int current = 0;
  	  for(int i = vertexList.size()-1; i >= (vertexList.size()/2); i--)
  	  {
  	    /*
  	       This will loop until it reaches the middle of the list as by this 
  	       point all vertices should be connected togther forming a connected graph.
  	    */ 

  	  	Vertex* hold = vertexList[current];
  	  	Vertex* temp;
  	  	Edge* vertex;
  	  	
  	  	if(current == i)//Checking to see if the vertex is trying to connect with itself
  	  	{
  	  	  temp = vertexList[i-1];
  	  	  vertex = new Edge();
  	  	  vertex->vertex1 = hold;
  	  	  vertex->vertex2 = temp;
  	  	  
  	  	}
  	  	else
  	  	{
  	  	  temp = vertexList[i];
  	  	  vertex = new Edge();
  	  	  vertex->vertex1 = hold;
  	  	  vertex->vertex2 = temp;
  	  	  
  	  	}
  	  	
  	  	//ADD A CHECK HERE
  	  	bool check = inadjacencyList(current+1, temp->data, hold->data);
  	  	if(check == false)
  	  	{
  	  	  hold->adjacencyList.push_back(vertex);
    	  temp->adjacencyList.push_back(vertex);
  	  	}
  	  	
    	hold = vertexList[current+1];
    	
  	  	check = inadjacencyList(current+1, temp->data, hold->data);
  	  	
    	 if(check == false)
    	 {
    	  	Edge* vertex3 = new Edge();
    	  	vertex3->vertex1 = hold;
    	  	vertex3->vertex2 = temp;
    	  	
    	  	hold->adjacencyList.push_back(vertex3);
    	  	temp->adjacencyList.push_back(vertex3);
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
  	        
  	        for(int i = 0; i < vertexList.size(); i++)
      	    {
      	      vertexList[i]->viewed = false;
      	      vertexList[i]->previous = nullptr;
      	      vertexList[i]->tentWeight = 999999999999999999;
      	      pq.push(vertexList[i]);
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
      	            generate the weight for each vertex in the graph
      	        */
      	        current = pq.front();
      	        pq.pop();
      	        current->viewed = true;
      	        visited.push_back(current);
      	        int size = current->adjacencyList.size();
                for(int i = 0; i < size; i++)
                {
                   /*
                      This will iterate through a given vertices adjacency list 
                      until it reaches the end. In each iteration it will check
                      if the connected vertex has been viewed, if it has it goes 
                      onto the next iteration. Otherwise it will look at the 
                      tentative weight of the previous vertex i.e. the current 
                      vertex, add this onto the connectons (edge) weight and see 
                      if the total is less than the connected vertices tentative 
                      weight.
                   */ 
                  int data = current->adjacencyList[i]->vertex1->data;
                  int data2 = current->adjacencyList[i]->vertex2->data;
                  if(current->data == data)
                  {
                       
                    if (current->adjacencyList[i]->vertex2->viewed != true)
                    {
        
                         Vertex* holding = current->adjacencyList[i]->vertex2;
                         Edge* holder = current->adjacencyList[i];
                         int weight = current->tentWeight + holder->weight;
                         if(holding->tentWeight > weight)
                         {
                             holding->tentWeight = weight;
                             holding->previous = current;
                         }

                     }
                     
                    else if (current->adjacencyList[i]->vertex1->viewed != true)
                    {
                         Vertex* holding = current->adjacencyList[i]->vertex1;
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
        
                     if (current->adjacencyList[i]->vertex1->viewed != true)
                     {
                         Vertex* holding = current->adjacencyList[i]->vertex1;
                         Edge* holder = current->adjacencyList[i];
                         int weight = current->tentWeight + holder->weight;
                         if(holding->tentWeight > weight)
                         {
                             holding->tentWeight = weight;
                             holding->previous = current;
                         }

                     }
                     else if (current->adjacencyList[i]->vertex2->viewed != true)
                     {
                         Vertex* holding = current->adjacencyList[i]->vertex2;
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
  	    This will create a new edge which connects two vertices togther. This 
  	    being the function where the user can manualy connect two vertices togther
  	  */
  	    Vertex* hold = getVertex(value1);
  	  	Vertex* temp = getVertex(value2);
  	  	Edge* vertex;
  	  	
  	  	if(value1 == value2)
  	  	{
  	  	  temp = vertexList[value2-1];
  	  	  vertex = new Edge(weight);
  	  	  vertex->vertex1 = hold;
  	  	  vertex->vertex2 = temp;
  	  	  
  	  	}
  	  	else
  	  	{
  	  	  vertex = new Edge(weight);
  	  	  vertex->vertex1 = hold;
  	  	  vertex->vertex2 = temp;
  	  	}
  	  	bool check = inadjacencyList(value1, temp->data, hold->data);
  	  	if(check == false)
  	  	{
      	  	hold->adjacencyList.push_back(vertex);
        	temp->adjacencyList.push_back(vertex);
        	edgeList.push_back(vertex);
  	  	}
  	  	else if(check == true)
  	  	{
  	  	    std::cout << "Connection already exists"<<std::endl;
  	  	    delete vertex;
  	  	    
  	  	}
  	}
  	
  	void reset()
    {
      /*
        Go through the vertex list and reset the vertices to unviewed so other
        functions work correctly.
      */
      for(int i = 0; i<vertexList.size(); i++)
      {
        Vertex* temp = vertexList[i];
        temp->viewed = false;
      }
    }
    
    std::vector<int> priv_depthSearch(int start)
    {
      /*
        This function takes in the starting point and begins traversing the 
        connections between vertex until there is no connection. Once it reaches
        that point it will go down anyother connections in the current vertex
        till all conections are visted. It will then go back a vertex and repeat
        this until all vertices have been visited. To do this it uses a stack that
        you add to as you visit each vertex so once all connections are exhausted 
        in current vertex it will be poped of the stack and the top of the stack 
        will become the current vertex. This function returns the visited list.  
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
                stack when it visits a vertex and poping when all of the vertices 
                connections are exhausted   
             */ 
             int size = hold->adjacencyList.size();
             for(int i = 0; i < size; i++)
             {
               /*
                 Iterates over a vertices adjacency list checking if the connected vertex
                 has been visited. If it has been visited it continues onto the next
                 edge otherwise it will add the connected vertex value to the value 
                 lsit. psuh the connected vertex to the stack and  mark it as viewed, 
                 change current vertex to the connected vertex and resets the iteration
                 counter to the begining of the adjacency lsit. 
               */ 
               size = hold->adjacencyList.size();
               if(i>(size-1))
               {
                 i-=1;
               }
               int data = hold->adjacencyList[i]->vertex1->data;
               int data2 = hold->adjacencyList[i]->vertex2->data;
               if(hold->data == data)
               {
                 if (hold->adjacencyList[i]->vertex2->viewed != true)
                 {
                     hold = hold->adjacencyList[i]->vertex2;
                     hold->viewed=true;
                     s.push(hold);
                     visited.push_back(hold->data);
                     i=-1;
                 }
                 else if (hold->adjacencyList[i]->vertex1->viewed != true)
                 {
                   hold = hold->adjacencyList[i]->vertex1;
                   s.push(hold);
                   hold->viewed = true;
                   visited.push_back(hold->data);
                   i=-1;
                 }
    
               }
                
               else if(hold->data == data2)
               {
                   
                 if (hold->adjacencyList[i]->vertex1->viewed != true)
                 {
                     hold = hold->adjacencyList[i]->vertex1;
                     hold->viewed = true;
                     s.push(hold);
                     visited.push_back(hold->data);
                     i=-1;
                 }
                 else if (hold->adjacencyList[i]->vertex2->viewed != true)
                 {
                   hold = hold->adjacencyList[i]->vertex2;
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
         this will take in a starting vertex and look at all the vertices connected 
         to it. As a vertex is visited it will be added to the que so that 
         once all the connected vertices of a given vertex are visited it will move 
         onto the first vertex in the que. It will repeat this activity untill 
         all vertices in the graph are visited. This function returns the visited
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
                connected vertices to the current vertex. This will go till all vertices are
                visited and the que is empty.
             */ 
             int size = hold->adjacencyList.size();
             for(int i = 0; i < size; i++)
             {
               /*
                  This will iterate through a given vertices adjacency list until it
                  reaches the end. In each iteration it will check if the connected
                  vertex has been viewed, if it has it goes onto the next iteration. 
                  Otherwise it will add it to the que, mark it as visited and add 
                  the connected vertices value to visited list.
               */ 
              
               if(i>(size-1))
               {
                 i-=1;
               }
               
               int data = hold->adjacencyList[i]->vertex1->data;
               int data2 = hold->adjacencyList[i]->vertex2->data;
               
               if(hold->data == data)
               {
                   
                 if (hold->adjacencyList[i]->vertex2->viewed != true)
                 {
    
                     holding = hold->adjacencyList[i]->vertex2;
                     holding->viewed=true;
                     q.push(holding);
                     visited.push_back(holding->data);
                 }
                 
                 else if (hold->adjacencyList[i]->vertex1->viewed != true)
                 {
                   holding = hold->adjacencyList[i]->vertex1;
                   q.push(holding);
                   holding->viewed = true;
                   visited.push_back(holding->data);
                 }
    
               }
                
               else if(hold->data == data2)
               {
    
                 if (hold->adjacencyList[i]->vertex1->viewed != true)
                 {
     
                     holding = hold->adjacencyList[i]->vertex1;
                     q.push(holding);
                     holding->viewed = true;
                     visited.push_back(holding->data);
                 }
                 
                 else if (hold->adjacencyList[i]->vertex2->viewed != true)
                 {
                   holding = hold->adjacencyList[i]->vertex2;
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
    	this->vertexList={};
    	this->edgeList={};
  	}
  	
  	Vertex* getVertex(int value)
  	{
  	    /*
  	        This will take in a value and will iterate through the current 
  	        graph's vertex list to see if it is in there. If it is it will return
  	        it otherwise it returns a null pointer. 
  	    */
  	    for(int i = 0; i < vertexList.size(); i++)
  	    {
  	        /*
  	            Iterates through the vertex list setting a temp vertex pointer so
  	            as to check to see if the vertex's data matches the value. 
  	        */
  	        Vertex* current = vertexList[i];
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
            form a path between the vertices.
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
  	        Public access for manualy connecting two vertices
  	    */
  	    priv_manualConnection(value1, value2, weight);
  	}
  	
  	void pub_addvertex(int value)
  	{
  	    /*
  	       Public access point to add a Vertex
  	    */
    	priv_addvertex(value);
  	}
  	
  	void autoConnection()
  	{
  	  /*
  	     Public access point to initiate the auto connect function
  	  */  
      priv_autoConnect();
  	}
  	
  	int getvertexValue(int count)
  	{
  	  /*
  	    Public access point to get a Vertex's data
  	  */ 
  	  if(count > vertexList.size())
  	  {
  	      std::cout << "This Numbe is out of range" << std::endl;
  	      return 9999999;
  	  }
  	  else
  	  {
  	      
  	  	  Vertex* hold = vertexList[count];
  	  	  return hold->data;
  	  }
  	  
  	}
  	 
  	void printConnections(int count)
  	{
  	  /*
  	    This will go through a vertex's adjacency list and will print out the 
  	    appropiate value based on which vertex in the edge points to it and to the
  	    connecting vertex.
  	  */
  	  Vertex* hold = vertexList[count];
  	  for(int i = 0; i < hold->adjacencyList.size(); i++)
  	  {
  	    Edge* temp = hold->adjacencyList[i];
  	    int value = hold->data;
  	    value == temp->vertex1->data ? std::cout << temp->vertex2->data:
  	    std::cout << temp->vertex1->data;
  	    if(i != hold->adjacencyList.size()-1)
        {
          std::cout<<", ";  
        }
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
  	        Graph destructor, this will delete all vertices in the vertex list first
  	        then it will delete all edges in the edge list.
  	    */
  	    for(int i = 0; i < vertexList.size(); i++)
  	    {
  	        Vertex* temp = vertexList[i];
  	        delete temp;
  	    }
  	    
  	    this->vertexList = {};
  	    
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
    g1.pub_addvertex(values[i]);
  }
  
  //Auto Connection - DON'T DELETE - DOSEN'T WORK WITH DIJKSTRA
  
  // g1.addEdge();
  
  // for(int i = 0; i < values.size(); i++)
  // {
  //   int temp = g1.getvertexValue(i);
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
  
  
  for(int i = 0; i < values.size(); i++)
  {
    int temp = g1.getvertexValue(i);
    std::cout << temp << " has these connections: ";
    g1.printConnections(i);
    std::cout << std::endl;
  }
  
  std::cout<<std::endl;
  
  int begin = 0;
  
  std::vector<int> hold = g1.depthSearch(begin);
  
  std::cout<<"Depth First Search from " << begin << ":   ";
  
  for(int i = 0; i < hold.size(); i++)
  {
    std::cout<<hold[i];
    if(i != hold.size()-1)
    {
      std::cout<<", ";  
    }
  }
  
  std::cout << std::endl;
  
  std::vector<int> holder = g1.breadthSearch(begin);
  
  std::cout<<"Breadth First Search from " << begin << ": ";
  
  for(int i = 0; i < holder.size(); i++)
  {
    std::cout<<holder[i];
    if(i != holder.size()-1)
    {
      std::cout<<", ";  
    }
  }
  
  std::cout << std::endl;
  
  std::ofstream outf;
  outf.open("graphOutPut.txt", std::fstream::app);
  
  if(!outf)
  {
    std::cerr << "Undable to open program terminating program"<<std::endl;
    exit(1);
  }
  
  outf << "Deapth First Search:  ";
  
  int fileCounter = 0;
  
  for(const auto &e : hold)
  {
    outf << e;
    fileCounter++; 
    if(fileCounter < hold.size())
    {
      outf<<", ";  
    }
  }
  
  outf << std::endl;
  
  outf << "Breadth First Search: ";
  
  fileCounter = 0;
  
  for(const auto &e : holder)
  {
    outf << e;
    fileCounter++; 
    if(fileCounter < hold.size())
    {
      outf<<", ";  
    }
  }
  
  outf << std::endl;
  
  std::cout<<std::endl;
  
  
  std::vector<Vertex*> temp = g1.dijkstra(begin);
  
  std::cout<<"The following shows the shortest path from " << begin << " to each vertex in the graph"<<std::endl;
  
  std::cout<<std::endl;
  
  g1.printDijkstra(temp);
  
  return 0;

}