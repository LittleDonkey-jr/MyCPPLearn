#include "ZUnorderedMap.h"

void print_Unordered_Map(const std::unordered_map<int, int>& map)
{
	for (const auto& pair : map) {
		std::cout << "Key: " << pair.first << ", Value: " << pair.second << "\n";
	}
}

void count_Unordered_Map_Numbers(const std::vector<int>& nums)
{
	std::unordered_map<int, int> map;
	for (const int& num : nums)
	{
		++map[num];
	}
	print_Unordered_Map(map);
}

void erase_Unordered_Map_Numbers(std::vector<int>& nums,int val)
{
	std::unordered_map<int, int> map;
	for (const int& num : nums)
	{
		++map[num];
	}

	auto it = map.find(val);
	if (it != map.end())
	{
		it->second -= 1;
		std::cout << "find "<< val <<" and decrese it\n";
	}
	else
	{
		std::cout << "not such key compare with "<< val <<" !\n";
	}

	print_Unordered_Map(map);

}