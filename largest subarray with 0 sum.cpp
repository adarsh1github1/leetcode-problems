#include<bits/stdc++.h>
using namespace std;
int longarray(int a[],int n)
{
	unordered_map<int,int> m;
	int i,sum=0,max_len=0;
	for (i = 0; i < n; ++i)
	{
		sum+=a[i];
		if(a[i] == 0 && max_len == 0)
			max_len=1;
		if(sum==0)
		{
			max_len = i+1;
		}
		if (m.find(sum) != m.end())
		{
			max_len = max(max_len,i-m[sum]);
		}
		else
		m[sum] = i;
	}
	return max_len;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<longarray(a,n);
	return 0;
}
