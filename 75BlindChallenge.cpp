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
int main1()
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
//Part 5
vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> frequent;
	vector<int>top;
	
	for (const auto& c : nums)
	{
		frequent[c]++;	
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>  pq;
	for (const auto& c : frequent)
	{
		pq.push({ c.second, c.first });
		if (pq.size() > k)
		{
			pq.pop();
		}
	}
	vector<int>result;
	while (!pq.empty())
	{
		result.push_back(pq.top().second);
		pq.pop();
	}
	return result;
}
int main5() {
	vector<int> nums = { 4,1,-1,2,-1,2,3 };
	int k = 2;

	vector<int> result = topKFrequent(nums, k);

	cout << "Top " << k << " frequent elements: ";
	for (const auto& num : result) {
		cout << num << " ";
	}

	return 0;
}
