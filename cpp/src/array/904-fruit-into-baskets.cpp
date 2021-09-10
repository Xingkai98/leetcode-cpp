#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 滑动窗口
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int ans = 0, len = 0;
        int i = 0;
        for(int j=0; j<fruits.size(); j++){
            basket[fruits[j]] += 1;
            len++;
            while(basket.size() > 2){
                basket[fruits[i]] -= 1;
                len--;
                if(basket[fruits[i]] == 0){
                    basket.erase(fruits[i]);
                }
                i++;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> fruits({1,2,3,2,3,2,1,3,2,2,3});
    cout << s.totalFruit(fruits) << endl;
}