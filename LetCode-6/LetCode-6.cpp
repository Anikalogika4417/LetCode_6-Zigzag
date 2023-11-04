#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> result(numRows);
        bool is_straight = true;
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            result[index] = result[index] + s[i];
            index = is_straight ? index+1 : index-1;

            if (i == 0) continue;
            if (index <= 0 || index >= numRows) {
                index = is_straight ? numRows - 2 : 0;
                is_straight = !is_straight;
                if (numRows == 2) {
                    is_straight = !is_straight;
                }
            }
        }
        string res;
        for (auto i : result) res = res + i;
        return  res;
    }
};

int main()
{
    Solution test;
    cout << test.convert("ABCD", 2);
}

