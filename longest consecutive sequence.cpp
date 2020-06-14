class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int >s;
        int i,j;
            for(i=0;i<n;i++)
                s.insert(nums[i]);
        int max_s = 0;
        for(i=0;i<n;i++)
        {
            //check if this number is starting of a sub sequence or not
           if( s.find(nums[i]-1) == s.end())
           {
               //if it is srating then increase count while there is consecutiv eelements
               int j= nums[i];
               while(s.find(j) != s.end())
                   j++;
           
            max_s = max(max_s,j-nums[i]);
           }
        }
        return max_s;
    }
};
