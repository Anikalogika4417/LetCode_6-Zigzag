#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> result(numRows);
        bool is_straight = true;
        for (int i = 0; i < s.size();) {
            if (is_straight) {
                for (int j = 0; j < numRows; j++) {
                    result[j] = result[j] + s[i];
                    i++;
                    if (i == s.size())
                    {
                        break;
                    }
                }
            }
            else {
                for (int j = numRows - 2; j > 0; j--) {
                    result[j] = result[j] + s[i];
                    i++;
                    if (i == s.size())
                    {
                        break;
                    }
                }
            }
            is_straight = !is_straight;
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

