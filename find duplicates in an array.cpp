#include <bits/stdc++.h>
using namespace std;
// method 1  --- print the duplicate elements multiple times
void countduplis_a(int arr[],int n){
	for(int i=0;i<n;i++){
		if(arr[abs(arr[i])]>=0){
			arr[abs(arr[i])] = -arr[abs(arr[i])];
		}
		else
			cout<<abs(arr[i])<<" ";
	}
}
// method 2  --- print the duplicate elements once
void countduplis_b(int arr[],int n){
	for (int i = 0; i < n; i++)
	{
		arr[arr[i]%n] = arr[arr[i]%n] +n;
	}
	for (int i = 0; i < n; i++)
	{
		if(arr[i] >= n*2)
			cout<<i<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	countduplis_a(a,n);
	cout<<endl;
	//countduplis_b(a,n);
	return 0;
}
