/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n+1);
        dp[1] = "1";
        for(int i = 2; i <= n ; i++){
            string v = dp[i-1];
            for(int j = 0 ; j < v.length();){
                int count = 1;
                while(j + 1 < v.length() && v[j+1] == v[j]){
                    j++;
                    count++;
                }
                dp[i] += to_string(count) + v[j];
                j++;
            }
        }
        return dp[n];
    }
};
// @lc code=end

