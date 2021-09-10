//二分搜索
#include <iostream>
#include <vector>
using namespace std;

//左闭右闭的写法
class SolutionA{
    public:
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1; // [0, nums.size()-1]
            while(left <= right){
                int mid = left + ((right - left) >> 1);  // 注意加括号，因为移位操作符优先级更高
                if (target < nums[mid]){
                    right = mid - 1;
                }
                else if(target > nums[mid]){
                    left = mid + 1;
                }
                else{
                    return mid;
                }
            }
            return -1;
        }
};

//左闭右开的写法
class SolutionB{
    public:
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size();
            while(left <= right){
                int mid = left + ((right - left) >> 1);  // 注意加括号，因为移位操作符优先级更高
                if (target < nums[mid]){
                    right = mid; //[..., mid)
                }
                else if(target > nums[mid]){
                    left = mid + 1;
                }
                else{
                    return mid;
                }
            }
            return -1;
        }
};

int main(){
    vector<int> v = {2,4,7,9,12,33};
    SolutionA sa;
    cout << sa.search(v, 2) << " " << sa.search(v, 4) << " " << sa.search(v, 7) << " "
         << sa.search(v, 9) << " " << sa.search(v, 12) << " " << sa.search(v, 33) << " " 
         << sa.search(v,34) << endl;
    SolutionA sb;
    cout << sb.search(v, 2) << " " << sb.search(v, 4) << " " << sb.search(v, 7) << " "
         << sb.search(v, 9) << " " << sb.search(v, 12) << " " << sb.search(v, 33) << " " 
         << sb.search(v,34) << endl;
}