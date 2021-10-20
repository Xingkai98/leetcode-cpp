#include <iostream>
#include <vector>
using namespace std;

// 59.螺旋矩阵II
// 思路是转圈，每圈走四趟，走一趟换一次方向，走完一圈后移动到下一圈的开始位置
// 奇数时的中心情况单独处理
// 注意，这道题转圈的思路只适用于正方形矩阵
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int x = 0, y = 0;  // 位置
        int current = 1;  // 当前数字
        int loop = n / 2;  // 要转多少圈，奇数时中间单独处理
        int step = n - 1;  // 每圈走四分之一的步数
        int direction[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};  // 方向
        int index = 0;  // 方向数组下标
        while(loop--){
            int i, j = 0;
            for(i=0;i<4;i++){
                for(j=0;j<step;j++){
                    ans[x][y] = current;
                    current++;
                    x += direction[index][0];
                    y += direction[index][1]; 
                }
                index = (index + 1) % 4;  // 换方向
            }
            x++;
            y++;
            step -= 2;
        }
        if(n % 2 == 1){
            ans[x][y] = n * n;
        }
        return ans;
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<vector<int>> v = s.generateMatrix(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}