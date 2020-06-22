#include<bits/stdc++.h>
using namespace std;
struct job
{
    int id;
    int deadline;
    int profit;
};
bool compare(struct job j1,struct job j2){
    return (j1.profit>j2.profit);
}
void jobscheduling(struct job j[],int n)
{
    
    sort(j,j+n,compare);
    int max_d = INT_MIN;
    for(int i=0;i<n;i++)
    {
        max_d = max(max_d,j[i].deadline);
    }
    int a[max_d] = {0};
    int count=0;
    int prof = 0;
    //int flag = 0;
    for(int i=0;i<n;i++){
        for(int k = j[i].deadline -1;k>=0;k--)
        {
            if(a[k] == 0)
            {
                a[k] = j[i].id;
                count++;
                prof+=j[i].profit;
                break;
            }
        }
    }
    cout<<count<<" "<<prof;

}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        struct job j[n];
        for(int i=0;i<n;i++)
        {
            cin>>j[i].id;
            cin>>j[i].deadline;
            cin>>j[i].profit;
        }
        jobscheduling(j,n);
        cout<<endl;
        t--;
    }
}
