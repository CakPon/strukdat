#include <iostream>
#include <list>
#include <iterator>
#include <queue>
using namespace std;

class Graph
{
protected:
    int vertex;
    list<int> adj[100];

public:
    Graph(int v)
    {
        vertex = v;
    }

    void addVertex(int v1, int v2)
    {
        adj[v1].push_back(v2);
    }

    void showVertex()
    {
        for (int i = 1; i <= vertex; i++)
        {
            cout << i << " --> ";
            list<int>::iterator it; // iterator for list
            for (it = adj[i].begin(); it != adj[i].end(); it++)
            {
                cout << *it << " "; // *it is the value of the node/ngeakses pointer nya
            }
            cout << endl;
        }
    }

    void BFS(int start)
    {
        bool visited[100];
        // initialize all nodes as not visited
        for (int i = 1; i <= vertex; i++)
        {
            visited[i] = false;
        }

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int front = q.front(); // get the front element
            list<int>::iterator it;
            for (it = adj[q.front()].begin(); it != adj[q.front()].end(); it++) // iterate through the list
            {
                if (!visited[*it]) // if the node is not visited
                {
                    q.push(*it);         // push the node to the queue
                    visited[*it] = true; // mark the node as visited
                }
                q.pop(); // remove the front element
            }
        }
    }
};

int main()
{
    Graph graph1(19);
    graph1.addVertex(1, 2);
    graph1.addVertex(2, 3);
    graph1.addVertex(3, 4);
    graph1.addVertex(1, 4);
    graph1.addVertex(4, 5);
    graph1.addVertex(5, 6);
    graph1.addVertex(6, 7);
    graph1.addVertex(7, 8);
    graph1.addVertex(8, 9);
    graph1.addVertex(9, 10);
    graph1.addVertex(5, 11);
    graph1.addVertex(11, 12);
    graph1.addVertex(12, 13);
    graph1.addVertex(13, 14);
    graph1.addVertex(14, 15);
    graph1.addVertex(15, 16);
    graph1.addVertex(16, 17);
    graph1.addVertex(17, 18);
    graph1.addVertex(18, 19);
    graph1.addVertex(13, 20);

    graph1.showVertex();
    graph1.BFS(1);
}