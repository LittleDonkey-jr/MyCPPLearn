#pragma once
#include <vector>
#include <iostream>
#include <algorithm>


/**
* ��ӡ���������������
* @param nums ����ӡ���ݵ�Vector����
* @throws NullPointerException ��� `nums` ����Ϊ null��
* @return void
*/
void print_Vector(std::vector<int>& nums);


/**
* ɾ��Vector�������ָ������
* @param nums ��ɾ�������ݵ�Vector����
* @param val ׼��ɾ��������
* @throws NullPointerException ��� `nums` ����Ϊ null��
* @return void
*/
void erase_Vector_Numbers(std::vector<int>& nums, int val);

/**
* ��Vector�����ڵ����ݽ�������
* @param nums ���������ݵ�Vector����
* @throws NullPointerException ��� `nums` ����Ϊ null��
* @return void
*/
void sort_Vector_Numbers(std::vector<int>& nums);

