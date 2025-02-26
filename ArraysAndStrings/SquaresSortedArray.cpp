// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
#include "myincludes.h"

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int left = 0;
            int right = nums.size()-1;
            int index = nums.size()-1;
            vector<int> tmp(nums.size());
                    
            while(left <= right) {
                if (abs(nums[left]) < abs(nums[right])){
                    tmp[index] = nums[right]*nums[right];
                    right--;
                    index--;
                } else {
                    tmp[index] = nums[left]*nums[left];
                    index--;
                    left++;
                }
            }
            
            return tmp; 
                
        }
    };

int main() {
    // Input array sorted in non-decreasing order
    std::vector<int> nums = {-4, -1, 0, 3, 10};

    // Create an instance of the Solution class
    Solution solution;

    // Call the sortedSquares method and get the result
    std::vector<int> result = solution.sortedSquares(nums);

    // Print the result
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}