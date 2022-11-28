#include <iostream>
#include <list>

using namespace std;

class Graph
{
  int numVertices;
  list<int> *adjMatrix;
  bool *visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex, int endVertex);
    void showMatrix();
};

Graph::Graph(int vertices)
{
  numVertices = vertices;
  adjMatrix = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest)
{
  adjMatrix[src].push_back(dest);
  adjMatrix[src].sort();
}

// BFS algorithm
void Graph::BFS(int startVertex, int endVertex)
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty())
  {
    int currVertex = queue.front();
    // Fungsi memberhentikan BFS
     if (currVertex == endVertex)
     {
       break;
     }
    
    cout << "(V" << currVertex << ")";
    queue.pop_front();

    for (i = adjMatrix[currVertex].begin(); i != adjMatrix[currVertex].end(); ++i)
    {
      int adjVertex = *i;
      if (!visited[adjVertex])
      {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

void Graph::showMatrix()
{
  for (int i = 0; i < numVertices; i++)
  {
    list<int>::iterator it;

    int track = 0;
    int through = 0;
    for (it = adjMatrix[i].begin(); it != adjMatrix[i].end(); ++it)
    {
      // int track = 0;
      int temp = *it;
      if (through == 0)
      {
        while (track < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      else
      {
        while ((track + 1) < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      cout << "1 ";
      through++;
    }
    while ((numVertices - through) > 0)
    {
      through++;
      cout << "0 ";
    }
    cout << endl;
  }
}

int main()
{
  Graph coba(20);

  	coba.addEdge(0, 1);
    coba.addEdge(1, 2);
    coba.addEdge(2, 3);
    coba.addEdge(0, 3);
    coba.addEdge(3, 4);
    coba.addEdge(4, 5);
    coba.addEdge(5, 6);
    coba.addEdge(6, 7);
    coba.addEdge(7, 8);
    coba.addEdge(8, 9);
    coba.addEdge(4, 10);
    coba.addEdge(10, 11);
    coba.addEdge(11, 12);
    coba.addEdge(12, 13);
    coba.addEdge(13, 14);
    coba.addEdge(14, 15);
    coba.addEdge(15, 16);
    coba.addEdge(16, 17);
    coba.addEdge(17, 18);
    coba.addEdge(12, 19);

  coba.BFS(0, 18);
  cout << endl;
  coba.showMatrix();

  return 0;
}