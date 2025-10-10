class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mp = {'(': ')', '[': ']', '{': '}'}

        for c in s:
            # if it's an opening bracket, push
            if c in mp:
                stack.append(c)
            # if it's a closing bracket, check match
            else:
                if not stack or mp[stack[-1]] != c:
                    return False
                stack.pop()
        
        return not stack
