class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || k + maxPts <= n) return 1.0;
        vector<double> dp(n + 1, 0);
        dp[0] = 1;
        int j = 0;
        int i = 0;
        double wsum = 0, res = 0;
        while(j <= n) {
            if(j < k) wsum += dp[j++];
            else res += dp[j++];
            if(j - i > maxPts) {
                wsum -= dp[i++];
            }
            
            if(j <= n) dp[j] = wsum / maxPts;
        }
        
        return res;
    }
};
