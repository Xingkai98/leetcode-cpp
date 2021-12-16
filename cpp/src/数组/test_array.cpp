#include <iostream>
using namespace std;

// C++的数组在内存上是连续的
void test_array(){
    int arr_one[3] = {1,2,3};
    cout << &arr_one[0] << " " << &arr_one[1] << " " << &arr_one[2] << endl;
    int arr_two[2][3] = {
        {0, 1, 2},
        {3, 4 ,5},
    };
    cout << &arr_two[0][0] << " " << &arr_two[0][1] << " " << &arr_two[0][2] << endl;
    cout << &arr_two[1][0] << " " << &arr_two[1][1] << " " << &arr_two[1][2] << endl;
}

int main(){
    test_array();
    return 0;
}