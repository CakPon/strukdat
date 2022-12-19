#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;

class Graph{
	int V;
	list<int> adj[21];
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}

	void addVertex(string str, int u, int v){
	    adj[u].push_back(v);
	    places[v] = str;
	}

	void showAllVertex(){
	    for(int i = 1; i<=V;i++){
	    	cout << i << " :";
	        for(auto const &j: adj[i]){
	            cout << " " << j << " ";
	        }
	        cout << endl;
	    }
	}

	bool shortest_path(int src, int dest, int pred[], int dist[]){
	queue<int> q;
	bool visited[V] = {false};
	dist[21] = {0};
	pred[21] = {-1};
	visited[src] = true;
	dist[src] = 0;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto const &i: adj[u]){
			if(visited[i] == false){
				visited[i] = true;
				dist[i] = dist[u] + 1;
				pred[i] = u;
				cout << u << " " << i << endl;
				q.push(i);
				if(i == dest) return true;
			}
		}
	}
	return false;
    }

    void shortestDistance(int src, int dest){
	int pred[V], dist[V];
	shortest_path(src, dest, pred, dist);
	vector<int> path;
	int c = dest;
	path.push_back(c);
	while(pred[c] != 0){
		path.push_back(pred[c]);
		c = pred[c];
	}
	for(int i = path.size() - 1; i >= 0; i--){
			cout << path[i] << " " << places[path[i]] << endl;
		}
}
};
int main(){
	Graph graph(20);
	graph.addVertex("rumah", 1, 1);
	graph.addVertex("masjid", 1, 2);
	graph.addVertex("angger", 1, 4);
	graph.addVertex("masjid", 2, 2);
	graph.addVertex("ridlatama", 2, 3);
	graph.addVertex("ridlatama", 3, 3);
	graph.addVertex("angger", 3, 4);
	graph.addVertex("angger", 4, 4);
	graph.addVertex("pandugo", 4, 5);
	graph.addVertex("pandugo", 5, 5);
	graph.addVertex("wps", 5, 6);
	graph.addVertex("spbu", 5, 11);
	graph.addVertex("wps", 6, 6);
	graph.addVertex("jne", 6, 7);
	graph.addVertex("jne", 7, 7);
	graph.addVertex("indomaret", 7, 8);
	graph.addVertex("indomaret", 8, 8);
	graph.addVertex("klinik", 8, 9);
	graph.addVertex("klinik", 9, 9);
	graph.addVertex("mentari", 9, 10);
	graph.addVertex("mentari", 10, 10);
	graph.addVertex("spbu", 11, 11);
	graph.addVertex("dasyi", 11, 12);
	graph.addVertex("dasyi", 12, 12);
	graph.addVertex("sentra", 12, 13);
	graph.addVertex("sentra", 13, 13);
	graph.addVertex("rusun a", 13, 14);
	graph.addVertex("pancing", 13, 20);
	graph.addVertex("rusun a", 14, 14);
	graph.addVertex("rusun b", 14, 15);
	graph.addVertex("rusun b", 15, 15);
	graph.addVertex("rusun c", 15, 16);
	graph.addVertex("rusun c", 16, 16);
	graph.addVertex("rusun 2", 16, 17);
	graph.addVertex("rusun 2", 17, 17);
	graph.addVertex("rusun 4", 17, 18);
	graph.addVertex("rusun 4", 18, 18);
	graph.addVertex("kunang", 18, 19);
	graph.addVertex("kunang", 19, 19);
	graph.addVertex("pancing", 20, 20);

	graph.showAllVertex();
	int source, dest;
	source = 1;
	dest = 14;
//	cin >> source >> dest;
    graph.shortestDistance(source,dest);
}