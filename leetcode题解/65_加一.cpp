#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
//输入数字（会存入num数组）
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        digits[0] += 1;
        int i = 0;
        while (digits[i] == 10) {
            digits[i] = 0;
            if (i == digits.size()-1) {
                digits.push_back(1);
                break;
            }
            else digits[++i] += 1;
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

void PlusOne_65()
{
    std::vector<int> num;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    int x;
    while (iss >> x) {
        num.push_back(x);
    }
    Solution Sol;
    num = Sol.plusOne(num);
    for (auto i : num) {
        std::cout << i;
    }
    std::cout << std::endl;
}
