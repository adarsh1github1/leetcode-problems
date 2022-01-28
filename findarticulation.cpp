#include <bits/stdc++.h>
using namespace std;

/*check for presence of articulation point - if adjacant has a higher or equal to
 low time meaning that the neighbour or adjacant cannot reach any node before its parent meaniing it is a articulation point*/


void dfs(int node , int parent, vector<int> &time,vector<int> &low,vector<bool> &vis, vector<int> adj[], int &timer, vector<int> &articulation ){
	vis[node] = true; // mark node as visited
	time[node] = low[node] = timer++; // increase timer more than parent if not visited

	int child = 0;     //individual children
	for(auto x: adj[node]){
		if(x == parent)
			continue; 
		if(!vis[x]){
			child++;
			dfs(x,node,time,low,vis,adj,timer,articulation);
			low[node] = min(time[node] , low[x]); // update low of the node - if any adjacant has lower distance then update it to the low
			if(low[x] >= time[node])                //check for presence of bridge
				articulation[node] = 1;
		}
		else{
			low[node] = min(time[node] , low[x]); // if not a bridge update the low time by comparing it with neighbours
		}
		if(parent == -1 && child > 1)
			articulation[node] = 1;
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
	vector<int> articulation(v,0);
	vector<int> time(v,-1);
	vector<int> low(v,-1);
	vector<bool> vis(v,false);
	int timer = 0;
	for(int i=0;i<v;i++){
		if(!vis[i]){
			dfs(i,-1,time,low,vis,adj,timer,articulation);
		}
	}

	for(int i=0;i<v;i++){
		if(articulation[i] == 1){
			cout << i << " is an articulation point" << endl;
		}
	}

	return 0;

}


// test cases
/*
addEdge(adj1, 1, 0);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);
    AP(adj1, V);

 */