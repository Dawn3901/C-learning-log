#include<iostream>
//输入楼梯台阶数n
class Solution {
public:
    //O(1),O(1)
    int climbStairs_1(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int first = 1, second = 2, current;
        for (int i = 3; i <= n; i++) {
            current = first + second;
            first = second;
            second = current;
        }
        return current;
    }
    //O(1),O(n)
    int climbStairs_2(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int dp[46];
        dp[0] = 1, dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
    //O(2^n)
    int climbStairs_3(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        else return climbStairs_3(n - 1) + climbStairs_3(n - 2);
    }
};

void ClimbStairs_70()
{
    int n;
    std::cin >> n;
    Solution Sol;
    std::cout << Sol.climbStairs_1(n) << std::endl;
}
