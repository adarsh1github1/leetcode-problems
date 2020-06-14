#include <bits/stdc++.h>
using namespace std;
void missingrepeat(int arr[],int n){
	for(int i=0;i<n;i++){
		arr[arr[i] %(n+1) - 1] = arr[arr[i] %(n+1) -1] + n+1; 
	}
	for(int i=0;i<n;i++){
		if(arr[i] >= 2*(n+1))
			cout<<"Repeating is "<<i+1<<endl;
		if(arr[i]<n+1)
			cout<<"Missing is "<<i+1<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	missingrepeat(a,n);
	return 0;
}
