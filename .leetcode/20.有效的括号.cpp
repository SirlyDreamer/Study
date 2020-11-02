/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
   bool match(char left,char right)
{
    if (left == '(' && right == ')')
        return true;
    if (left == '[' && right == ']')
        return true;
    if (left == '{' && right == '}')
        return true;
    return false;
}

bool isValid(string s)
{
    if (s.size() == 0)
        return true;

    stack<char> stack;

    for (string::iterator iter = s.begin() ; iter != s.end() ; iter++)
    {
        if (stack.empty() == true || !match(stack.top(),*iter))
            stack.push(*iter);
        else
            stack.pop();
    }

    if (stack.empty() == true)
        return true;
    else
        return false;
}
};
// @lc code=end

