#include<bits/stdc++.h>
class Solution {
public:
    void swap(int *a,int *b){
        int temp =  *a;
        *a = *b;
        *b = temp;
    }
    void nextPermutation(vector<int>& nums) {
     int n = nums.size();
        int i,j;
        for(i=n-1;i>0;i--)
            if(nums[i]>nums[i-1])
                break;
    
        if(i==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        else{
            int x = nums[i-1];
            int small =i;
            for(j=i+1;j<n;j++){
                if(nums[j]>x && nums[j]<nums[small]){
                    small = j;
                }
            }
            swap(&nums[small],&nums[i-1]);
            sort(nums.begin() + i, nums.end());
        }
        }
        };
    
        
       
