class Solution:
    def makeGood(self, s: str) -> str:
        stack = []

        # first check that the string isn't empty or only has 1 element
        if len(s) <= 1:
            return s
        
        # iterate through the string
        for char in s:
            # if the stack is empty, push the current character
            if not stack:
                stack.append(char)
            # if the stack is not empty, check if the current character is the same as the last character in the stack
            else:
                if abs(ord(char) - ord(stack[-1])) == 32:
                    stack.pop()
                else:
                    stack.append(char)
        
        # return the stack as a string
        return "".join(stack)
    
# test cases
def main():
    solution = Solution()
    print(solution.makeGood("abBcA")) # should return "acA"
    print(solution.makeGood("aA")) # should return ""
    print(solution.makeGood("aAbB")) # should return ""

if __name__ == "__main__":
    main()

