class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
       int  n = A.size();
        for(int i=0;i<n;i++)
            if(abs(A[i]-i)>1)   // as elements are between 0to n-1 if any number is misplaced for
                return false;// more than 1 position then there will be global inversion more than 
                                   // local
        return true;
        
    }
};
