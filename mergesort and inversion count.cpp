#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> A,int temp[],int l,int mid, int high)
 {
 	int inv_count=0;
 	int i,j,k;
 	i=l;
 	j=mid;
 	k=l;
 	while(i <= mid-1 && j <= high)
 	{
 		if(A[i] <= A[j])
 		{
 			temp[k++] = A[i++];
 		}
 		else
 		{
 			temp[k++] = A[j++];
            inv_count+= mid-i;
 		}	
 	}
 	while(i<=mid-1)
 		temp[k++] = A[i++];
 	while(j<=high)
 		temp[k++] = A[j++];
 	for(i=l;i<=high;i++)
 		A[i] = temp[i];
 	return inv_count;
 }
 int _mergesort(vector<int> A,int temp[],int l,int h)
 {
 	int count=0,mid;
 	if(l<h)
 	{
 	mid = (l+h)/2;
 	count+=_mergesort(A,temp, l,mid);
 	count+=_mergesort(A,temp,mid+1,h);
 	count+=merge(A,temp,l,mid,h);
    }
    return count;
}
 int mergesort(vector<int> A)
 {
 	int n = A.size();
	int* temp = (int*)malloc(sizeof(int) * A.size());
 	return _mergesort(A,temp,0,n-1);
 }
int main()
{
	vector<int> A;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
	    cin>>x;
	    A.push_back(x);
	}
	cout<<mergesort(A);
	return 0;
}
