#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int,int> intPair;

class Graph{
	int V;
	int adjM[21][21] ={
          {0, 0},
          {0, 0}
    };
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}

	void addVertex(string str, int u, int v, int w){
	    adjM[u][v] = w;
	    places[v] = str;
	}

	void showAllVertex(){
	    for(int i = 1; i<=V;i++){
	        for(int j = 1; j<=V;j++){
	            if(adjM[i][j] == 0) cout << ".  ";
	            else if (adjM[i][j] < 10) cout << adjM[i][j] << "  ";
	            else cout << adjM[i][j] << " ";
	        }
	        cout <<  endl;
	    }
	}

	void djikstra(int src){
		priority_queue<intPair, vector<intPair>, greater<intPair> >
        q;
		q.push(make_pair(1, src));
		int dist[V];
		for(int i = 1; i<=V; i++){
		    dist[i] = 1000;
		}
		dist[src] = 1;

		while(!q.empty()){
			int u = q.top().second;
			q.pop();
			for(int i = 1; i <= V; i++){
				int v = i;
				int w = adjM[u][i];
				if(dist[v] > dist[u] + w && w != 0){
					dist[v] = dist[u] + w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		printf("Vertex Distance from Source\n");
    	for (int i = 1; i <= V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
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
	graph.showAllVertex();
	int src;
//	src = 1;
	cin >> src;
    graph.djikstra(src);
}