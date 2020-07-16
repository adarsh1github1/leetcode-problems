
/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
    map<int , int> m;
    queue<Node*> q;
    queue<int> dist;
    dist.push(0);
    q.push(root);
    int hd=0;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        hd = dist.front();
        dist.pop();
        m[hd] = temp->data;
        if(temp->left){
            q.push(temp->left);
            dist.push(hd-1);
        }
        if(temp->right){
            q.push(temp->right);
            dist.push(hd+1);
        }
    }
    vector<int> v;
    for(auto i = m.begin(); i!= m.end(); i++){
        v.push_back(i->second);
    }
    return v;
    
}

