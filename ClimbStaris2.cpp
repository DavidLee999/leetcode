class Solution {
public:
    // vector<int> memo(n, 0);
    int climbStairs(int n) {
		int i, j, k;
        if (1 >= n)
            return 1;
        if (2 == n)
            return 2;
        
        i = 1;
        j = 2;
        for (int m = 3; m <= n; ++m)
        {
			k = i + j;
			i = j;
			j = k;
        }
        
        return j;
    }
};
