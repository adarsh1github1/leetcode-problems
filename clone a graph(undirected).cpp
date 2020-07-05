// bfs approach
class Solution {
public:
    Node* cloneGraph(Node* node) {
    	if(node == NULL)
    		return node;
    	// a hashmap to store all the nodes and its neighbours
    unordered_map<Node* , Node*> duplicate;
    queue<Node* > q;
    q.push(node);
    //enter the first element to start dfs
    duplicate[node] = new Node(node->val);
    while(!q.empty()){
    	Node* copies = q.front();
    	q.pop();
    	// iterate through all the neighbours of node which havent veen visted 
    	for(auto neighbor: copies->neighbors){
    		if(duplicate.count(neighbor) == 0){
    			q.push(neighbor);  // push in queue the neighbour
    			duplicate[neighbor] = new Node(neighbor->val); // adding that neightbour to our map
    		}
    		// attaching all neighbours to the node
    		duplicate[copies]->neighbors.push_back(duplicate[neighbor]);
    	}
    }
    // returning the first node will do the work   
    return duplicate[node];
    }
};