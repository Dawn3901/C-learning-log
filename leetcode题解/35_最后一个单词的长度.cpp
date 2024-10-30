#include<iostream>
#include<string>
//输入一个带空格的英文句子（末尾也可以有空格符）*（空格可能很长）
class Solution {
public:
    int lengthOfLastWord(std::string s) {
        bool b = false;
        int length = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                if (b) continue;
                else b = true;
            }
            if (s[i] != ' ') {
                if (b) {
                    length = 1;
                    b = false;
                }
                else length++;
            }
        }
        return length;
    }
};

void LengthOfLastWord_35() {
    std::string input;
    std::getline(std::cin,input);
    Solution Sol;
    std::cout << Sol.lengthOfLastWord(input) << std::endl;
}
