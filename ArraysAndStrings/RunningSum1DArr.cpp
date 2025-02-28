#include "myincludes.h"

class Solution {
    public:
        // Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
        // Return the running sum of nums.
        vector<int> runningSum(vector<int>& nums) {
            for (int i = 1; i < nums.size(); i++) {
                nums[i] = nums[i-1]+nums[i];
            }
            return nums;
        }
        // Given an array of integers nums, you start with an initial positive value startValue.
        // In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).
        // Return the minimum positive value of startValue such that the step by step sum is never less than 1.
        int minStartValue(vector<int>& nums) {
            int min_prefix_sum = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                nums[i] += nums[i-1];
                if (nums[i] < min_prefix_sum) {
                    min_prefix_sum = nums[i];
                }
            }
            
            int StartVal = 1;
            // Solving for StartVal + Min_prefix_sum = 1, unless less than 1
            if (1 - min_prefix_sum > 1) {
                StartVal = 1 - min_prefix_sum;
            }
            return StartVal;

        }

    };

void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main () {
    Solution solution;

    // Example 1
    vector<int> nums = {1,2,3,4};
    vector<int> nums1 = nums;
    solution.runningSum(nums);
    cout << "The running sum of the array ";
    printVector(nums1);
    cout << " is: ";
    printVector(nums);
    cout << endl;

    // Example 2: Min Starting Val
    nums = {-3,2,-3,4,2};
    int minStartVal = solution.minStartValue(nums);
    cout << "The minimum starting value with the input vector ";
    printVector(nums);
    cout << " is: " << minStartVal << endl;

    return 0;
}