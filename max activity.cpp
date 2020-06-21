#include<bits/stdc++.h>
using namespace std;
struct activity{
    int start;
    int end;
};
bool compare(struct activity a, struct activity b){
    return (a.end < b.end);
}
int max_activity(int a[],int b[],int n){
    struct activity m[n];
    for(int i=0;i<n;i++)
    {
        m[i].start = a[i];
        m[i].end = b[i];
    }
    sort(m,m+n,compare);
    int time_limit = m[0].end;
    int count =1;
    for(int i=1;i<n;i++)
    {
        if(m[i].start >= time_limit)
        {
            count++;
            time_limit = m[i].end;
        }
    }
    return count;
}
int main()
 {int t;
 cin>>t;
 while(t>0){
 int n;
 cin>>n;
 int a[n],b[n];
 for(int i=0;i<n;i++)
 {
     cin>>a[i];
 }
 for(int i=0;i<n;i++)
 cin>>b[i];
 cout<<max_activity(a,b,n);
 cout<<endl;
 t--;
 }
    return 0;
}
