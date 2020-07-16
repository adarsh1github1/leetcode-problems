
//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    struct Node* temp = root;
    if(root == NULL){
        return;
    }
    map<int , int> m;
    queue<struct Node*> q;
    queue<int> hd;
    hd.push(0);
    q.push(temp);
    int h = 0;
    m[h] = temp->data;
    while(!q.empty()){
        struct Node* x = q.front();
        q.pop();
        h = hd.front();
        if(m.count(h) == 0)
        m[h] = x->data;
        hd.pop();
        if(x->left){
            q.push(x->left);
            hd.push(h-1);
        }
        if(x->right){
            q.push(x->right);
            hd.push(h+1);
        }
    }
    for(auto i = m.begin(); i!= m.end(); i++){
        cout<<i->second<<" ";
    }
}