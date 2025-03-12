// You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

// Return a list answer of size 2 where:
    // answer[0] is a list of all players that have not lost any matches.
    // answer[1] is a list of all players that have lost exactly one match.

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public IList<IList<int>> FindWinners(int[][] matches) {
        Dictionary<int, int> losses = new Dictionary<int, int>();

        // winner = match[0]
        // loser = match[1]
        foreach (var match in matches) {
            if (!losses.ContainsKey(match[0])) {
                losses[match[0]] = 0;
            }

            if (!losses.ContainsKey(match[1])) {
                losses[match[1]] = 1;
            } else {
                losses[match[1]]++;
            }
        }

        List<int> noLosses = new List<int>();
        List<int> oneLoss = new List<int>();

        foreach (var player in losses.Keys) {
            if (losses[player] == 0) {
                noLosses.Add(player);
                continue;
            } 
            if (losses[player] == 1) {
                oneLoss.Add(player);
            }
        }
        noLosses.Sort();
        oneLoss.Sort();
        return new List<IList<int>> { noLosses, oneLoss };
    }
}

public class Program {
    static void Main(string[] args) {
        Solution solution = new Solution();
        int[][] matches = new int[][] {
            new int[] {1, 3},
            new int[] {2, 3},
            new int[] {3, 6},
            new int[] {5, 6},
            new int[] {5, 7},
        };
        var result = solution.FindWinners(matches);
        // Type IList<IList<int>> so print the members each list and say lost 0 times or 1 time
        Console.WriteLine("No losses: " + string.Join(", ", result[0]));
        Console.WriteLine("One loss: " + string.Join(", ", result[1]));
    }
}