#include<bits/stdc++.h>
using namespace std;
struct item
{
    float weight;
    float val;
};
bool compare(struct item m1, struct item m2){
    float r1 = m1.val/m1.weight;
    float r2 = m2.val/m2.weight;
    return (r1>r2);
}
float frac_knaapsack(struct item m,int n,float w){
    sort(m,m+n,compare);
    float current = 0;
    float total = 0;
    for(int i=0;i<n;i++)
    {
        if(current + m[i].weight <= w){
            current+= m[i].weight;
            total+= m[i].val;
        }
        else{
            total += (w - current)/m[i].weight * m[i].val;
            break;
        }
    }
    return total;
}
int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        float w;
        cin>>n;
        cin>>w;
        struct item m[n];
        for(int i=0;i<n;i++)
        {
            cin>>m[i].val;
            cin>>m[i].weight;
        }
        cout<<frac_knaapsack(m,n,w);
        endl;
        t--;
    }
}
