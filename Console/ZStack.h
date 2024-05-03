#pragma once
#include <stack>
#include <iostream>
#include <string>


namespace Solution {
	/**
	* 有效字符串需满足：
	* 1.左括号必须用相同类型的右括号闭合。
	* 2.左括号必须以正确的顺序闭合。
	* 3.每个右括号都有一个对应的相同类型的左括号。
	* @param string 包括 '('，')'，'{'，'}'，'['，']' 的字符串 s
	* @return bool 返回字符串是否有效的bool值
	*/
	bool bracket_Is_Valid(std::string s);

}
	
namespace TestSheet{
	/**
	* 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
	* @return void
	*/
	void Test_bracket_Is_Valid(std::string s);

};

