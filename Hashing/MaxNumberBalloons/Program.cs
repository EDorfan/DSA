// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
// You can use each character in text at most once. Return the maximum number of instances that can be formed.

class Solution {
    public int MaxNumberOfBalloons(string text) {
        Dictionary<char, int> counts = new Dictionary<char, int>()
        {
            {'b', 0},
            {'a', 0},
            {'l', 0},
            {'o', 0},
            {'n', 0}
        };

        foreach (char c in text) {
            if (counts.ContainsKey(c)) {
                counts[c]++;
            }
        }

        return Math.Min(counts['b'], Math.Min(counts['a'], Math.Min(counts['l'] / 2, Math.Min(counts['o'] / 2, counts['n']))));
    }

    public int MaxNumberOfBalloons2(string text) {
        int b = 0;
        int a = 0;
        int l = 0;
        int o = 0;
        int n = 0;

        foreach (char c in text) {
            if (c == 'b') {
                b++;
            } else if (c == 'a') {
                a++;
            } else if (c == 'l') {
                l++;
            } else if (c == 'o') {
                o++;
            } else if (c == 'n') {
                n++;
            }
        }

        return Math.Min(b, Math.Min(a, Math.Min(l / 2, Math.Min(o / 2, n))));
    }
}

class Program
{
    static void Main(string[] args)
    {
        Solution solution = new Solution();
        Console.WriteLine(solution.MaxNumberOfBalloons("nlaebolko"));
        Console.WriteLine(solution.MaxNumberOfBalloons2("nlaebolko"));
    }
}