#include<bits/stdc++.h>
using namespace std;
int findUnsortedSubarray(vector<int>& nums){
    int i,j;
        int n = nums.size();
        for(i=0;i<n-1;i++){
            if(nums[i] < nums[i+1])
                break;
        }
        for(j=n-1;j> i;j--){
            if(nums[j] < nums[j-1])
                break;
        }
        return j-i;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<findUnsortedSubarray(v);
    return 0;
}