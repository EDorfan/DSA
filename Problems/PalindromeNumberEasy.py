# Given an integer x, return true if x is a palindrome, and false otherwise.

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        i = 0
        j = len(str(x)) - 1

        while i < j:
            if str(x)[i] != str(x)[j]:
                return False
            i += 1
            j -= 1
        return True

def main():
    x = 123
    solution = Solution()
    print(solution.isPalindrome(x))

if __name__ == "__main__":
    main()

