// Given an integer array nums, return the largest integer that only occurs once. If no integer occurs once, return -1.
using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    /// Finds the largest number in the array that appears exactly once.
    public int LargestUniqueNumber(int[] nums)
    {
        // Dictionary to store count of each number
        Dictionary<int, int> counts = new Dictionary<int, int>();
        // Track largest number that appears once, initialized to -1 if none found
        int largestUnique = -1;

        // Count frequency of each number in the array
        foreach (int num in nums)
        {
            if (!counts.ContainsKey(num))
            {
                counts[num] = 1;
            }
            else
            {
                counts[num]++;
            }
        }

        // Find the largest number that appears exactly once
        foreach (var key in counts.Keys)
        {
            if (counts[key] == 1)
            {
                largestUnique = key > largestUnique ? key : largestUnique;
            }
        }

        return largestUnique;
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Solution solution = new Solution();
        int[] nums = { 5, 7, 3, 9, 4, 9, 8, 3, 1 };
        Console.WriteLine(solution.LargestUniqueNumber(nums));
    }
}