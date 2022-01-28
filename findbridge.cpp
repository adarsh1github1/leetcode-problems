#include <bits/stdc++.h>
using namespace std;

/*check for presence of bridge - if adjacant has a higher
 low time meaning there exits no path to it that there is no
  shorter than other than through the node to its neighbour meaning 
 passing through the node is compulsory to make it connected meaning that connection is a bridge*/


void dfs(int node , int parent, vector<int> &time,vector<int> &low,vector<bool> &vis, vector<int> adj[], int &timer){
	vis[node] = true; // mark node as visited
	time[node] = low[node] = timer++; // increase timer more than parent if not visited

	for(auto x: adj[node]){
		if(x == parent)
			continue;
		if(!vis[x]){
			dfs(x,node,time,low,vis,adj,timer);
			low[node] = min(time[node] , low[x]); // update low of the node - if any adjacant has lower distance then update it to the low
			if(low[x] > time[node])                //check for presence of bridge
				cout << node << " -> " << x << endl;
		}
		else{
			low[node] = min(time[node] , low[x]); // if not a bridge update the low time by comparing it with neighbours
		}
	}
}


int main(){
	cout << "enter the vertices and edges" << endl;
	int v; cin >> v;
	int e; cin >> e;
	vector<int> adj[v];
	for(int i=0;i<e;i++){
		int u, v;
		cout << "enter the edges" << endl;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> time(v,-1);
	vector<int> low(v,-1);
	vector<bool> vis(v,false);
	int timer = 0;
	for(int i=0;i<v;i++){
		if(!vis[i]){
			dfs(i,-1,time,low,vis,adj,timer);
		}
	}

	return 0;

}


// test cases
/*
g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);


 */