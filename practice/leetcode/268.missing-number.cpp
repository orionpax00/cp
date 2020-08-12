/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int x : nums) ans ^= x;
        return ans;
    }
};
// @lc code=end

