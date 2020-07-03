#include <bits/stdc++.h>
using namespace std;
class Graph{
private:
	int v;
	list<int> *adj;
public:
	Graph(int v);
	void addEdge(int v,int w);
	void dfs();
	void dfs_helper(int x, vector<bool>& visited);
};
Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v];
}
void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}
void Graph::dfs_helper(int x, vector<bool>& visited){
	stack<int> s;
	s.push(x);
	while(!s.empty()){
		x = s.top();
		s.pop();
		cout<<x<<" ";
		visited[x] = true;
		for(auto it=adj[x].begin();it!= adj[x].end();it++){
			if(!visited[*it]){
			s.push(*it);
			visited[*it] = true;
		    }
		}

    }
}
void Graph::dfs(){
	std::vector<bool> visited(v,false);
	for(int it=0;it<v;it++){
		if(!visited[it]){
			dfs_helper(it,visited);
		}
	}
}

int main(){
	int v;
	cin>>v;
	Graph g(v);
	g.addEdge(1,0);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(0,3);
	g.addEdge(1,4);
	g.dfs();
	return 0;
}