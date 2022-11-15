#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Vertex{
    protected:
        list<int> adj;
    
    public:
        void addEdge(int u, int v){
            if(adj.empty()) adj.push_back(u);
            adj.push_back(v);
        }

        void showList(){
            list<int>::iterator it;
            for(it = adj.begin(); it != adj.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
        }
};

class Graph{
    protected:
        int pjg;
        Vertex vertex[100];

    public:
        Graph(int _pjg){
            pjg = _pjg;
        }

        AddEdgetoVertex(int u, int v){
            vertex[u].addEdge(u,v);
            vertex[v].addEdge(v,u);
        }

        showVertex(){
            for (int i = 0; i < pjg; i++)
            {
                vertex[i].showList();
            }
            
        }
};

int main(){
    Graph graf1(5);

    graf1.AddEdgetoVertex( 0, 1);
    graf1.AddEdgetoVertex( 0, 4);
    graf1.AddEdgetoVertex( 1, 2);
    graf1.AddEdgetoVertex( 1, 3);
    graf1.AddEdgetoVertex( 1, 4);
    graf1.AddEdgetoVertex( 2, 3);
    graf1.AddEdgetoVertex( 3, 4);

    graf1.showVertex();
}