// 螺旋矩阵
#include <iostream>
#include <vector>
using namespace std;

// 54.螺旋矩阵
// 这两道题更好的选择都是手动判断换方向
// 与螺旋矩阵2不同，这道题矩阵不一定是正方形，因此按圈来步数无法统一
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;  // 结果数组
        int rows = matrix.size();  // 行数
        int columns = matrix[0].size();  // 列数
        int x = 0, y = 0;
        int dx = 0, dy = 0;  // 下一步的移动，用来进行判断
        int step[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};  // 方向
        int i = 0;  // 方向数组下标
        int visited[11][11] = {0};  // 记录各个位置是否到过
        while(ans.size() < rows * columns){
            ans.push_back(matrix[x][y]);  // 当前格加入答案
            visited[x][y] = 1;
            dx = x + step[i][0];  // 判断是否需要换方向
            dy = y + step[i][1];
            if(dx<0 || dy<0 || dx>=rows || dy>=columns){  // 出界
                i = (i + 1) % 4;
            }
            if(dx>=0 && dy>=0 && dx<rows && dy<columns && visited[dx][dy]){  // 已经访问过
                i = (i + 1) % 4;
            }
            x += step[i][0];  // 移动
            y += step[i][1];
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v = {{1,2,3,4},{5,6,7,8},{9,10,11,-1}};
    vector<int> result = s.spiralOrder(v);
    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}