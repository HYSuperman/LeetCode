/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.
*/

/* Classic Dynamic Programming Problem.

* if you think recursively:
  numTrees(1->n) = sumof(numTrees(1->k-1)*numTrees(k+1->n))

  so convert to dp:
  dp[n] = sumof(dp[k - 1]*dp[n - k])

*/


class Solution {
public:
    int numTrees(int n) {
        int dp[100] = {0};
        dp[0] = 1;

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= i;j++){
                dp[i] += dp[j - 1]*dp[i - j];
            }
        }
        
        return dp[n];
    }
};

/* Note that for a certain amount of node, there are fixed number of binary search trees.*/