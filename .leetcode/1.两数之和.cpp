/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for (int i(0);i < nums.size()-1;i++)
    {
        for (int j = i;j < nums.size();j++)
        {
            if(i != j && nums.at(i)+nums.at(j) == target)
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}
};
// @lc code=end

