#pragma once
#include <vector>
#include <iostream>
#include <algorithm>


/**
* 打印容器里的所有数据
* @param nums 待打印数据的Vector容器
* @throws NullPointerException 如果 `nums` 参数为 null。
* @return void
*/
void print_Vector(std::vector<int>& nums);


/**
* 删除Vector容器里的指定数据
* @param nums 待删除的数据的Vector容器
* @param val 准备删除的数据
* @throws NullPointerException 如果 `nums` 参数为 null。
* @return void
*/
void erase_Vector_Numbers(std::vector<int>& nums, int val);

/**
* 对Vector容器内的数据进行排序
* @param nums 待排序数据的Vector容器
* @throws NullPointerException 如果 `nums` 参数为 null。
* @return void
*/
void sort_Vector_Numbers(std::vector<int>& nums);

