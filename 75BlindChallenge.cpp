#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector < vector<string>>store;
	map<string, vector<string>> Anagrams;
	for (string elem : strs)
	{
		string temp = elem;
		sort(temp.begin(), temp.end());
		Anagrams[temp].push_back(elem);
	}
	for (const auto& a : Anagrams)
	{
		store.push_back(a.second);
	}
	return store;
}
int main()
{
	vector<string>str = { "eat","tea","tan","ate","nat","bat" };
	vector<vector<string>> output = groupAnagrams(str);
	for (const auto& row : output) {
		for (const std::string& element : row) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}