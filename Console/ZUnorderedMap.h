#pragma once
#include <unordered_map>
#include <vector>
#include <iostream>

/**
* 使用哈希表对数据个数进行统计
* @param nums 待统计的数据
* @throws NullPointerException 如果 `nums` 参数为 null。
* @return void
*/
void count_Unordered_Map_Numbers(const std::vector<int>& nums);

/**
* 使用哈希表对哈希表中的某个键的值进行减一操作
* @param nums 待更改的数据
* @throws NullPointerException 如果 `nums` 参数为 null。
* @return void
*/
void erase_Unordered_Map_Numbers(std::vector<int>& nums,int val);

/**
* 打印哈希表的所有键值
* @param map 待打印的哈希表
* @throws NullPointerException 如果 `map` 参数为 null。
* @return void
*/
void print_Unordered_Map(const std::unordered_map<int, int>& map);