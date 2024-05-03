#pragma once
#include <unordered_map>
#include <vector>
#include <iostream>

/**
* ʹ�ù�ϣ������ݸ�������ͳ��
* @param nums ��ͳ�Ƶ�����
* @throws NullPointerException ��� `nums` ����Ϊ null��
* @return void
*/
void count_Unordered_Map_Numbers(const std::vector<int>& nums);

/**
* ʹ�ù�ϣ��Թ�ϣ���е�ĳ������ֵ���м�һ����
* @param nums �����ĵ�����
* @throws NullPointerException ��� `nums` ����Ϊ null��
* @return void
*/
void erase_Unordered_Map_Numbers(std::vector<int>& nums,int val);

/**
* ��ӡ��ϣ������м�ֵ
* @param map ����ӡ�Ĺ�ϣ��
* @throws NullPointerException ��� `map` ����Ϊ null��
* @return void
*/
void print_Unordered_Map(const std::unordered_map<int, int>& map);