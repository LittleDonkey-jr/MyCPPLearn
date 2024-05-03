#include "ZVector.h"


void print_Vector(std::vector<int>& nums)
{
	for (int num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << "\n";
}

void erase_Vector_Numbers(std::vector<int>& nums,int val)
{
	std::cout << "num wait for erase is: " << val << "\n";
	std::cout << "nums before erase: ";
	print_Vector(nums);
	nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
	std::cout << "nums after erase: ";
	print_Vector(nums);
}

void sort_Vector_Numbers(std::vector<int>& nums)
{
	std::cout << "sort greater\n";
	std::sort(nums.begin(), nums.end(), std::greater<int>());
	print_Vector(nums);
	std::cout << "sort less\n";
	std::sort(nums.begin(), nums.end(), std::less<int>());
	print_Vector(nums);
}

