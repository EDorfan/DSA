class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []

        # split the path based on /
        path = path.split('/')
        # if the current element is . or empty, skip it
        for c in path:
            if c == "." or c == "":
                continue
            elif c == "..":
                if stack:  # Only pop if we have something to pop
                    stack.pop()
            else:
                stack.append(c) # otherwise, push the current element onto the stack

        # return the joined stack with a / as the separator
        if not stack:
            return "/"
        else:
            return "/" + "/".join(stack)
            

def main():
    solution = Solution()
    path = "/../"
    print(solution.simplifyPath(path))

if __name__ == "__main__":
    main()
