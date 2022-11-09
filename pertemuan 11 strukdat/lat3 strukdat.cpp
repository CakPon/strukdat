#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Graph{
    protected:
        int x;
        list<int> adj[100];

    public:
    Graph(int pjg){
        x = pjg;
    }

    void setPjg(int pjg){
        x = pjg;
        adj[x];
    }

    void addEdge(int n, int x){
        if(adj[n].empty()) adj[n].push_back(n);
        if(adj[x].empty()) adj[x].push_back(x);
        adj[n].push_back(x);
        adj[x].push_back(n);
    }

    void show(){
        for (int i = 0; i <= x; i++)
        {
            list<int>::iterator it;
            for(it = adj[i].begin(); it != adj[i].end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};


int main(){
    Graph graf1(5);
    graf1.addEdge( 0, 1);
    graf1.addEdge( 0, 4);
    graf1.addEdge( 1, 2);
    graf1.addEdge( 1, 3);
    graf1.addEdge( 1, 4);
    graf1.addEdge( 2, 3);
    graf1.addEdge( 3, 4);
    graf1.show();
}
