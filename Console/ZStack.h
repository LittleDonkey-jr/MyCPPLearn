#pragma once
#include <stack>
#include <iostream>
#include <string>


namespace Solution {
	/**
	* ��Ч�ַ��������㣺
	* 1.�����ű�������ͬ���͵������űպϡ�
	* 2.�����ű�������ȷ��˳��պϡ�
	* 3.ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
	* @param string ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s
	* @return bool �����ַ����Ƿ���Ч��boolֵ
	*/
	bool bracket_Is_Valid(std::string s);

}
	
namespace TestSheet{
	/**
	* ����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
	* @return void
	*/
	void Test_bracket_Is_Valid(std::string s);

};

