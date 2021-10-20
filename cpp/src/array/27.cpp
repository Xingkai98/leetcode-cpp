#include <iostream>
#include <vector>
using namespace std;

// 27.删除元素
// 遍历法
class SolutionA{
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){ // 发现要删除的元素，就集体移动一位
                for(int j=i+1; j<nums.size(); j++){
                    nums[j-1] = nums[j];
                }
                size--; // 集体移动后的处理
                i--;
            }
        }
        return size;
    }
};

// 双指针
class SolutionB{
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
            if(val != nums[fastIndex]){
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
                // 每次进行判断
                // 等于val，慢指针不动，快指针向前
                // 不等于val，快指针指向的数覆盖慢指针指向的数，快慢指针都向前
            }
        }
        return slowIndex;
    }
};

int main(){
    vector<int> u = {3,2,4,4,5,2,3};
    vector<int> v(u);
    SolutionA sa;
    SolutionB sb;
    cout << sa.removeElement(u, 4) << endl;
    for (int x : u){
        cout << x << " ";
    }
    cout << endl;
    cout << sb.removeElement(v, 4) << endl;
    for (int x : v){
        cout << x << " ";
    }
    cout << endl;
}