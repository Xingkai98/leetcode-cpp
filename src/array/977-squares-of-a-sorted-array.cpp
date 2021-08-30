// 有序数组的平方（双指针法）
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int t = nums.size()-1;
        int l = 0, r = nums.size()-1;
        while(t >= 0){
            if(nums[l] * nums[l] <= nums[r] * nums[r]){
                result[t] = nums[r] * nums[r];
                r--;
            }
            else{
                result[t] = nums[l] * nums[l];
                l++;
            }
            t--;
        }
        return result;      
    }
};

int main(){
    vector<int> v = {-4,-3,-1,0,2,3,5};
    Solution s;
    vector<int> result = s.sortedSquares(v);
    for (int x : result){
        cout << x << " ";
    }
    cout << endl;
}