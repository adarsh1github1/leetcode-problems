class Solution {
public:
	// method 1- using power
    int trailingZeroes(long long n) {
        long long x =5;
        long long i=2;
        long long zero =0;
        while(x<=n){
            zero+=n/x;
            x=pow(5,i++);
        }
        return  zero;
    }
    // mehod -2 using multiplication better soln
int trailingZeroes(int n) {
        long long int count=0,i=5;
        while(n/i>=1)
        {
            count+=n/i;
            i*=5;
        }
        return count;
}
};

