// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
public class Solution
{
    public int FindMaxLength(int[] nums)
    {
        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = -1;
            }
        }

        Dictionary<int, int> firstPrefixSumOccurence = new Dictionary<int, int>();
        firstPrefixSumOccurence[0] = -1;
        int maxLength = 0;
        int currentSum = 0;

        for (int i = 0; i < nums.Length; i++)
        {
            currentSum += nums[i];
            if (firstPrefixSumOccurence.ContainsKey(currentSum))
            {
                maxLength = Math.Max(maxLength, i - firstPrefixSumOccurence[currentSum]);
            }
            else
            {
                firstPrefixSumOccurence[currentSum] = i;
            }
        }

        return maxLength;
    }

}

public class Program
{
    static void Main(string[] args)
    {
        Solution solution = new Solution();
        Console.WriteLine(solution.FindMaxLength(new int[] { 0, 1, 0, 1 }));
    }
}