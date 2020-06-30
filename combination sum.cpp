class Solution {
public:
    
    void helperfunction(vector<int>& candidates,int target,vector<vector<int> >& results,vector<int> &x, int i){
        if(target<0)
            return;
        if(target == 0){
            results.push_back(x);
            return;   
        }
        while(i<candidates.size() && target - candidates[i] >= 0){
            x.push_back(candidates[i]);
            helperfunction(candidates,target-candidates[i],results,x,i);
            i++;
            // backtracking
            x.pop_back();
            
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > results;
        if(candidates.size() == 0)
            return results;
        vector<int> x;
        sort(candidates.begin(),candidates.end());
        helperfunction(candidates,target,results,x,0);
        return results;
    }
    
};
// write necessary main function to call functions if required