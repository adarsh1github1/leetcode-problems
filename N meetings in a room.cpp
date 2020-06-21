#include<bits/stdc++.h>
using namespace std;
struct meeting{
   int start;
   int end;
   int pos;
};
bool compare(struct meeting m1, struct meeting m2){
    return (m1.end<m2.end);
}
void nmeetings(int a[],int b[],int n){
    struct meeting m[n];
    for(int i=0;i<n;i++)
 {
    m[i].start = a[i];
    m[i].end = b[i];
    m[i].pos = i+1;
 }
 sort(m,m+n,compare);
 std::vector<int> v;
 int timelimit = m[0].end;
 v.push_back(m[0].pos);
   for(int i=1;i<n;i++)
    {
    if(m[i].start >= timelimit)
    {
        v.push_back(m[i].pos);
        timelimit = m[i].end;
    }
    }
   for(int i=0;i<v.size();i++)
   cout<<v[i]<<" "; 
}
int main()
 {
 int t;
 cin>>t;
 while(t>0){
 int n;
 cin>>n;
 int a[n];
 int b[n];
 for(int i=0;i<n;i++)
 cin>>a[i];
 for(int i=0;i<n;i++)
 cin>>b[i];
 nmeetings(a,b,n);
  t--;
 }
    return 0;
}
