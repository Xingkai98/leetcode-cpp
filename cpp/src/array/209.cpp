#include <iostream>
#include <vector>
using namespace std;

// 209.长度最小的子数组
// 滑动窗口
class Solution{
public:
    int minSubArrayLen(int s, vector<int>& nums){
        int result = INT32_MAX;
        int len = 0;  // 当前长度
        int sum = 0;  // 当前数字和
        int i = 0; // 慢指针，滑动窗口的左侧
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            len++;
            while(sum >= s){  // 缩小窗口
                result = min(len, result);
                sum -= nums[i];
                i++;
                len--;
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main(){
    vector<int> v = {2,3,1,2,4,3,1,2,4};
    Solution s;
    int result = s.minSubArrayLen(9, v);
    cout << result << endl;
}

//  0     
//  1 2 3 
//  0     
//  