#include <bits/stdc++.h>
using namespace std;

// Choice3 Choice2
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Choice3
void printGraph(vector<int> adj[], int V)
{
    for (int v = 1; v < V; ++v)
    {
        cout << "\n FASTEST trip you can possibly take" << v;
        for (auto x: adj[v])
           cout << " ---> " << x;
        printf("\n");
    }
}
// Choice2
void printGraph1(vector<int> adj[], int V)
{
    for (int v = 1; v < V; ++v)
    {
        cout << "\n Links with other cities " << v;
        for (auto x: adj[v])
           cout << " ---> " << x;
        printf("\n");
    }
}

struct Node {
    int val, cost;
    Node* next;
};


struct Edge {
    int src, dest, weight;
};
class Graph
{
 
 Node* getAdjListNode(int value, int weight, Node* head)
  {
    Node* newNode = new Node;
    newNode->val = value;
    newNode->cost = weight;
    newNode->next = head;

   return newNode;    
  }

  int N;  //nodes in the graph

public:
Node **head;
 Graph(Edge edges[], int n, int N)
 {
   head = new Node*[N]();
   this->N = N;

   for (int i = 0; i < N; i++)
   head[i] = nullptr;

       
   for (unsigned i = 0; i < n; i++)
   {
   int src = edges[i].src;
   int dest = edges[i].dest;
   int weight = edges[i].weight;
   Node* newNode = getAdjListNode(dest, weight, head[src]);

   head[src] = newNode;
            
   // Makes the graph undirected
   newNode = getAdjListNode(src, weight, head[dest]);
   head[dest] = newNode;
            
   }
 }
 Graph() 
 {
   for (int i = 0; i < N; i++)
     delete[] head[i];

     delete[] head;
 }
};

// Choice2
void printList(Node* ptr)
{
    while (ptr != nullptr)
    {
        cout << " ---> " << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Choice4
void printList(Node* ptr, int i)
{
 while (ptr != nullptr)
 {
   cout << "(" << i << ", " << ptr->val
        << ", " << ptr->cost << " Miles) ";

  ptr = ptr->next;
 }
    cout << endl;
}
int main()
{
  int answer,
       choice;

  cout << "     Please select an option below for your next trip!!(TO DETERMINE THE PATH FOR YOU)   " << endl;
  cout << " 1.) Trip Planner (Trip Routing)" << endl;
  cout << " 2.) Cost Effective (Quickest Path)" << endl;
  cout << " 3.) Roads (Adjacencies)" << endl;
  cout << " 4.) Map (Matrix)" << endl;
  cin >> choice;
  
  // Choice 1 if they choose
  if (choice == 1)
{
    cout << "Possible Routes " << endl << "1-->Riverside(CALIFORNIA), 2-->Moreno Valley(CALIFORNIA), 3-->Hemet(CALIFORNIA), 4--Perris(CALIFORNIA)" << endl;
    Edge edges[] =
    {
        // pair x, y
    { 1, 2 }, { 1, 3 }, { 1, 4 }, { 3, 4 },
        { 3, 2 }, { 4, 2 }
    };
    // Vertices
    int N = 5;
    int n = sizeof(edges)/sizeof(edges[2]);
    Graph graph(edges, n, N);
    for (int i = 1; i < N; i++)
    {
        cout << i;
        printList(graph.head[i]);
    }
    cin >> choice;
  }

  // Choice 2 if they choose
  if (choice == 2)
  {
   cout << "      LOCATION OF THE TOWNS:       " << endl;
    
    cout << "    1-->Riverside(STARTINGPOINT), 2-->Moreno Valley (32), 3-->Hemet (66), 4-->Perris (48)        " << endl;
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 2);
    printGraph1(adj, V);
    
    cin >> choice;
  }

  // Choice 3 if they choose
  if (choice == 3)
  {
    cout << "1-->Riverside(CALI), 2-->Moreno Valley(CALI), 3-->Hemet(CALI), 4-->Perris(CALI) " << endl; 
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 2, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 2);
    printGraph(adj, V);
    
    cin >> choice;
  }

  // Choice4
  if (choice == 4)
  {
    cout << "Cities in IE AREA(92551) that is around you:" << endl << "1-->Riverside, 2-->Moreno Valley, 3-->Hemet, 4-->Perris" << endl;
    Edge edges[] =
    {
       //(x,y,z) 
        { 1, 2, 16 }, { 1, 3, 33 }, { 1, 4, 24 }, { 2, 3, 26 },
        { 3, 4, 30 }, { 4, 2, 18 }
    };

   
    int N = 5;

  
    int n = sizeof(edges)/sizeof(edges[0]);

    Graph graph(edges, n, N);
    for (int i = 1; i < N; i++)
    {
        printList(graph.head[i], i);
    }
    cin >> choice;
  }
   return 0;
  }