class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j;
        int n= matrix.size();
        int m = matrix[0].size();
        bool cflag = false;;
        bool rflag = false;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(i==0 && matrix[i][j] == 0)
                    rflag = true;
                if(j==0 && matrix[i][j] == 0)
                    cflag = true;
                
                if(matrix[i][j] == 0){
                    matrix[0][j] =0;
                    matrix[i][0] =0;
                }
            }
        }
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(matrix[0][j] ==0 || matrix[i][0] == 0)
                  matrix[i][j] = 0;
            }
        }
        if(rflag == true )
            for(i=0;i<m;i++)
                matrix[0][i] = 0;
        if(cflag == true)
            for(i=0;i<n;i++)
                matrix[i][0] = 0;
        
    }
};
