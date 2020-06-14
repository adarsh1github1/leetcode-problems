class Solution {
public:
    int titleToNumber(string s) {
        int n =s.length();   
        int i,j,sum=0;
        j=0;
            for(i=n-1;i>=0;i--){
                sum += (s[i]-64) * pow(26,j);
                j++;
            }
        return sum;
    }
    // method - 2 very easy
    int titleToNumb(string s) {
	int res = 0;
	for (char c : s)
		res = 26 * res + (c - 'A' + 1);
	return res;
}
};
