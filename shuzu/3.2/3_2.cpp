#include <iostream>
#include <vector>
#include <string>

using std::vector;

// 解决方法一针对左边闭合右边开的区间
// class Solution{
// public:
//     int search(vector<int>& nums,int target){
//         int left = 0;
//         int right = nums.size();
//         while (left < right)//已经知道该区间定义为左闭右开，故left==right时候不合法
//         {
//             int middle = left+(right-left)/2;
//             if (nums[middle] < target){
//                 left = middle + 1;
//             } 
//             else if (nums[middle] > target){//注意此时右边是开区间
//                 right = middle;
//             }
//             else if (nums[middle] == target){
//                 return middle;
//             }
//             /* code */
//         }
//         return -1;
//     }

// };

// 第二种解法针对双闭合区间
class Solution{
public:
    int search(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)//已经知道该区间定义为左闭右开，故left==right时候不合法
        {
            int middle = left+(right-left)/2;
            if (nums[middle] < target){
                left = middle + 1;
            } 
            else if (nums[middle] > target){
                right = middle-1;
            }
            else if (nums[middle] == target){
                return middle;
            }
            /* code */
        }
        return -1;
    }

};

int main(){
    vector<int> nums{-1,0,3,5,9,12};
    int target = 9;
    Solution solve;
    int jieguo = solve.search(nums,target);
    std::cout << jieguo << std::endl;
    return 0;
}
