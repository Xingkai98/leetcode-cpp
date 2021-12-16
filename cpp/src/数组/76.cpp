#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 76.最小覆盖子串
// 滑动窗口，用hashmap存储t各字符的个数和当前i-j子串中各字符的个数
class Solution {
public:
    unordered_map<char, int> basket, count;

    bool check(){
        for(auto it=count.begin(); it!=count.end(); it++){
            if(basket[it->first] < it->second){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(s.length() < t.length()){
            return "";
        }
        string ans = "";
        int min_len = INT32_MAX;
        int i = 0;
        for(char ch: t){
            count[ch] += 1;
        }
        for(int j=0; j<s.length(); j++){
            basket[s[j]] += 1;
            while(check()){
                basket[s[i]] -= 1;
                if(basket[s[i]] == 0){
                    basket.erase(s[i]);
                }
                if(j-i+1 < min_len){
                    ans = s.substr(i, j-i+1);
                    min_len = j-i+1;
                }
                i += 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    string s = "AA";
    string t = "AA";
    string ans = solution.minWindow(s, t);
    cout << ans << endl;
    return 0;
}