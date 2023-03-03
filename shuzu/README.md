

# 3.1、数组理论基础

数组是非常基础的数据结构

数组存储方式：**存放在连续内存空间上的相同数据类型的集合**

数组可以方便的通过下标索引方式获取下表下对应的数值

attention：**数组下表都是从零开始**

​					**数组内存空间地址都是连续的**

​					**由于数组内存空间地址是连续的所以再删除或者增添元素的时候，需要移动其他元素的地址**

数组的元素不能删除，**只能进行覆盖**

注意区分：vector和array  vector是容器 不是数组

二维数组第一索引是行  第二索引是列

数组地址连续性验证实验：

```c++
#include <iostream>
void test_arr(){
    int array[2][3] = {0, 1, 2, 3, 4, 5};
    std::cout << &array[0][0] << "  " << &array[0][1] << "  " << &array[0][2] << "  " << std::endl;
    std::cout << &array[1][0] << "  " << &array[1][1] << "  " << &array[1][2] << "  " << std::endl;

}

int main(){
    test_arr();
    return 0;

}

运行结果：
yph@yph-virtual-machine:~/code/leetcode/3.1$ ./3_1
0x7fffa30d24e0  0x7fffa30d24e4  0x7fffa30d24e8  
0x7fffa30d24ec  0x7fffa30d24f0  0x7fffa30d24f4 
    //一个int型数据占用4个字节，16位
```

# 3.2、二分查找

给定一个有序数组升序或者降序整形数组nums 给定一个目标值target  目的：写一个搜索函数寻找nums数组中的target，如果存在则返回下标，不能存在返回-1.

**二分法主要思想**：

首先确定该数组为有序数组，每次寻找整个当前数组中的中间元素，并且将该中间元素与目标值进行比较；如果该中间值不等于目标值则根据需求进行当前数组的更新；如果中间值等于目标值。即完成下标的返回。

**二分法应用条件**

首先数组有序数组  其次保证数组中没有重复元素

避免二分法中边界条件的应用错误

首先需要明确二分法的区间定义

一般去鉴定为分为两种：a、**左闭右开**  b、**左闭右闭**

**第一种方式**：

如果说定义 target 是在一个在左闭右开的区间里，也就是[left, right) 

while (left < right)，这里使用 < ,因为left == right在区间[left, right)是没有意义的

if (nums[middle] > target) right 更新为 middle，因为当前nums[middle]不等于target，去左区间继续寻找，而寻找区间是左闭右开区间，所以right更新为middle，即：下一个查询区间不会去比较nums[middle]

```c++
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
```

**第二种方式**：

**因为定义target在[left, right]区间，所以有如下两点：**

while (left <= right) 要使用 <= ，因为left == right是有意义的，所以使用 <=

if (nums[middle] > target) right 要赋值为 middle - 1，因为当前这个nums[middle]一定不是target，那么接下来要查找的左区间结束下标位置就是 middle - 1

```c++
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
```

# 3.3、移除数组元素

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并**原地**修改输入数组。

已知数组的元素在内存地址中是连续的，不能单独删除，只能覆盖

常规解题方法：需要对其进行有两层的for循环时间复杂度过高

**双指针法**（数组、链表、字符串）应用广泛

通过一个快指针和一个慢指针在一个for循环下完成两个循环的任务

快指针：寻找新数组的元素，新数组即为不含有目标元素的数组

慢指针：执行更新 指向新数组下标

```c++
class Solution{
public:
    int removeElement(vector<int>& nums,int val){
        int slowIndex = 0;
        for (int firstIndex = 0; firstIndex <nums.size(); firstIndex++){
            if (nums[firstIndex] != val){
                nums[slowIndex++] = nums[firstIndex];

            }
        }
        return slowIndex;

    }

};
```

