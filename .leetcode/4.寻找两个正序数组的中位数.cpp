/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::iterator iter1 = nums1.begin();
        vector<int>::iterator iter2 = nums2.begin();

        vector<int> temp;
        vector<int>::iterator itertemp = temp.begin();

        int middle = ( nums1.size() + nums2.size() ) / 2 + 1;

        while (temp.size() < middle && iter1 < nums1.end() && iter2 < nums2.end())
        {
            if (*iter1 < *iter2)
                temp.push_back(*iter1++);
            else
                temp.push_back(*iter2++);
        }
        while (temp.size() < middle && iter1 < nums1.end())
            temp.push_back(*iter1++);
        while (temp.size() < middle && iter2 < nums2.end())
            temp.push_back(*iter2++);   

        if ((nums1.size()+nums2.size())%2 == 0)
            return ( temp.at(temp.size()-1) + temp.at(temp.size()-2) ) / 2.0;
        else
            return (double)temp.at(temp.size()-1);     
    }
};
// @lc code=end

