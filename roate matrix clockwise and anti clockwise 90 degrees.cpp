class Solution {
public:
    // method 1 --- transpose and reverse
	void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        if(N==0)
            return;
        
		// Transpose of Matrix , it is inplace.
        for(int i=0; i<N; i++) 
        {
            for(int j=0; j<i; j++) 
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // Reverse the Matrix Row-wise
        for(int i=0; i<N; i++) 
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
        return;
    }
    // method 2 -- divide in cylces - N/2 cycles -- divide in groups - N- 2*i groups
    void rotate90Clockwise(int a[N][N]) 
{ 
  
    // Traverse each cycle 
    for (int i = 0; i < N / 2; i++) { 
        for (int j = i; j < N - i - 1; j++) { 
  
            // Swap elements of each cycle 
            // in clockwise direction 
            int temp = a[i][j]; 
            a[i][j] = a[N - 1 - j][i]; 
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j]; 
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i]; 
            a[j][N - 1 - i] = temp; 
        } 
    } 
} 
// rotate 90. anti clockwise
 void rotateMatrix(int mat[][N]) 
{ 
    // Consider all squares one by one 
    for (int x = 0; x < N / 2; x++) { 
        // Consider elements in group 
        // of 4 in current square 
        for (int y = x; y < N - x - 1; y++) { 
            // Store current cell in 
            // temp variable 
            int temp = mat[x][y]; 
  
            // Move values from right to top 
            mat[x][y] = mat[y][N - 1 - x]; 
  
            // Move values from bottom to right 
            mat[y][N - 1 - x] 
                = mat[N - 1 - x][N - 1 - y]; 
  
            // Move values from left to bottom 
            mat[N - 1 - x][N - 1 - y] 
                = mat[N - 1 - y][x]; 
  
            // Assign temp to left 
            mat[N - 1 - y][x] = temp; 
        } 
    } 
} 
  
};
