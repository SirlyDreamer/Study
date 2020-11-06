/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:

    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        if (x >= 0 && x < 10)
            return true;

        stack<short int> stack;
        short int digit = (short int)log10(x) + 1;
        int index(0);

        if ( digit%2 == 0 )
        {
            while(x != 0)
            {
                if (index < digit/2)
                {
                    stack.push((short int)(x%10));
                }
                else
                {
                    if (x%10 == stack.top())
                        stack.pop();
                }
                x /= 10;
                index++;
            }
            if (stack.empty())
                return true;
            else
                return false;
        }
        else
        {
            while(x != 0)
            {
                if (index < digit/2)
                {
                    stack.push((short int)(x%10));
                }
                else
                {
                    if (x%10 == stack.top() && index != digit/2)
                        stack.pop();
                }
                x /= 10;
                index++;
            }
            if (stack.empty())
                return true;
            else
                return false;
        }
    }
};
// @lc code=end