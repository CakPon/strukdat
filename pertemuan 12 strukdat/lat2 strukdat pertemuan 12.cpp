#include <iostream>
#include <iterator>
#include <list>
#include <queue>
using namespace std;

class Graph {
    protected:
        int v;
        list<int> adj[100];
        int est[100];
        int dis[100];

    public:
        Graph(int pjg) {
            v = pjg;
        }

        void addEdge(int u, int v){
            adj[u].push_back(v);
        }

        void show(){
            for (int i = 0; i < v; i++)
            {
                list<int>::iterator it;
                cout << i << " ";
                for(it = adj[i].begin(); it != adj[i].end(); ++it){
                    cout << *it << " ";
                }
                cout << endl;
            }
        }

        void BFS(int start){
        	cout << endl;
            cout << "BFS" << endl;
            cout << endl;
            bool visited[100];
            for (int i = 0; i < v; i++)
            {
                visited[i] = false;
                est[i] = -1;
                dis[i] = -1;
            }
            
            queue<int> q;
            visited[start] = true;
            dis[start] = 0;

            list<int>::iterator it;
            q.push(start);

            while (!q.empty())
            {
                int now = q.front();
                q.pop();
                for (it = adj[now].begin(); it != adj[now].end(); it++)
                {
                    int index = *it;
                    if(!visited[index])
                    {
                        visited[index] = true;
                        q.push(index);
                        dis[index] = dis[now] + 1;
                        est[index] = now;
                    }
                }
            }
            for (int i = 0; i < v; i++)
            {
                cout << dis[i] << " " << est[i] << endl;
            }            
        }
};

int main(){
    Graph graph1(8);

    graph1.addEdge( 0, 1);
    graph1.addEdge( 0, 3);
    graph1.addEdge( 1, 2);
    graph1.addEdge( 3, 4);
    graph1.addEdge( 3, 7);
    graph1.addEdge( 4, 5);
    graph1.addEdge( 4, 6);
    graph1.addEdge( 4, 7);
    graph1.addEdge( 5, 6);
    graph1.addEdge( 6, 7);
    
    graph1.show();

    graph1.BFS(0);
}