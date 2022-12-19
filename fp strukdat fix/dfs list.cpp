#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
using namespace std;

class Graph {
    protected:
        int v;
        vector<string> place;
        vector<list<int>> adj;
        map<pair<int,int>, int> weight;
        vector<int> dfsResult;
        int dfsWeight;
        vector<int> dijkstraRes;

    public:
        Graph(int len) {
            v = len;
            place.assign(v+1, "");
            list<int> l;
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }

        void addVertex(string i, int u, int v, int w){
            adj[u].push_back(v);
            weight.insert({make_pair(u,v), w});
            place[v] = i;
        }

        void showGraph(){
            for (int i = 1; i <= v; i++)
            {
                list<int>::iterator it;
                cout << i << " => ";
                for (it = adj[i].begin(); it != adj[i].end(); it++)
                {
                    cout << *it << "(" << weight[make_pair(i, *it)] << ") ";
                }
                cout << endl;
            }
        }

        void DFS(int start, int end){
            cout << endl;
            cout << "## Shortest path using DFS" << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );

            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << dfsResult[i] << " ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
                cout << currWeight << " ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout <<  path[i] << " ";
                }
                cout << endl;
            }
            visited[start] = true;
            path.push_back(start);
            list<int>::iterator it;
            for ( it = adj[start].begin(); it != adj[start].end(); it++)
            {
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(start, *it)];
                    solveDFS(*it, end, path, visited, wtemp);
                }
            }
        }
};

int main(){
	Graph graph(20);
	graph.addVertex("rumah", 1, 1, 1);
	graph.addVertex("masjid", 1, 2, 3);
	graph.addVertex("angger", 1, 4, 5);
	graph.addVertex("masjid", 2, 2, 3);
	graph.addVertex("ridlatama", 2, 3, 4);
	graph.addVertex("ridlatama", 3, 3, 4);
	graph.addVertex("angger", 3, 4, 5);
	graph.addVertex("angger", 4, 4, 5);
	graph.addVertex("pandugo", 4, 5, 6);
	graph.addVertex("pandugo", 5, 5, 6);
	graph.addVertex("wps", 5, 6, 7);
	graph.addVertex("spbu", 5, 11, 12);
	graph.addVertex("wps", 6, 6, 7);
	graph.addVertex("jne", 6, 7, 8);
	graph.addVertex("jne", 7, 7, 8);
	graph.addVertex("indomaret", 7, 8, 9);
	graph.addVertex("indomaret", 8, 8, 9);
	graph.addVertex("klinik", 8, 9, 10);
	graph.addVertex("klinik", 9, 9, 10);
	graph.addVertex("mentari", 9, 10, 11);
	graph.addVertex("mentari", 10, 10, 11);
	graph.addVertex("spbu", 11, 11, 12);
	graph.addVertex("dasyi", 11, 12, 13);
	graph.addVertex("dasyi", 12, 12, 13);
	graph.addVertex("sentra", 12, 13, 14);
	graph.addVertex("sentra", 13, 13, 14);
	graph.addVertex("rusun a", 13, 14, 15);
	graph.addVertex("pancing", 13, 20, 21);
	graph.addVertex("rusun a", 14, 14, 15);
	graph.addVertex("rusun b", 14, 15, 16);
	graph.addVertex("rusun b", 15, 15, 16);
	graph.addVertex("rusun c", 15, 16, 17);
	graph.addVertex("rusun c", 16, 16, 17);
	graph.addVertex("rusun 2", 16, 17, 18);
	graph.addVertex("rusun 2", 17, 17, 18);
	graph.addVertex("rusun 4", 17, 18, 19);
	graph.addVertex("rusun 4", 18, 18, 19);
	graph.addVertex("kunang", 18, 19, 20);
	graph.addVertex("kunang", 19, 19, 20);
	graph.addVertex("pancing", 20, 20, 21);
    graph.showGraph();

    int start, end;
    start = 1;
    end = 14;
//    cin >> start >> end;
    graph.DFS(start, end);


}