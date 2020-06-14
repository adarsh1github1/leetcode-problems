#include <bits/stdc++.h>
using namespace std;
void sortfun(int a[],int n)
{
   int low=0,mid=0,high = n-1;
   while(mid<=high){
   	switch(a[mid]){
   		case 0: 
   		    swap(a[low++],a[mid++]);
   		    break;
   		case 1:
   		    mid++;
   		    break;
   		 case 2:
   		    swap(a[mid],a[high--]);
   		    break; 
   	}
   } 
}
void sortfun_easy(int a[],int n){
	int c1=0,c2=0,c3=0;
	for(int i=0;i<n;i++){
		switch(a[i]){
			case 0:
				c1++;
				break;
			case 1:
				c2++;
				break;
			case 2:
				c3++;
				break;
		}
	}
	//cout<<c1<<" "<<c2<<" "<<c3;
	int j=0;
	while(c1>0){
	a[j++] = 0;
	c1--;
	}
	while(c2>0){
	a[j++] = 1;
	c2--;
}
	while(c3>0){
	a[j++] = 2;
	c3--;
}
}
void printl(int arr[],int n){
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	//sortfun(a,n);
	sortfun_easy(a,n);
	printl(a,n);
	return 0;
}
