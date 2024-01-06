#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_set>
#include<set>
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
vector<int> productExceptSelf(vector<int>& nums) {
	int n = nums.size();
	vector<int> result(n, 1);
	int prefix = 1;
	int postfix = 1;
	for (int i = 0; i < n; i++)
	{
		result[i] *= prefix;
		prefix *= nums[i];

		result[n-1-i] *= postfix;
		postfix *= nums[n-1-i];
	}
	return result;
}
int main6() { 

	vector<int> nums = { 1, 2, 3 };

	vector<int> result = productExceptSelf(nums);
	cout << "Original array: ";
	for (int num : nums) {
		cout << num << " ";
	}

	cout << "\nResult array: ";
	for (int res : result) {
		cout << res << " ";
	}

	return 0;
}
int longestConsecutive(vector<int>& nums) { //btw this solution's time complexity is O(nlogn) but it should be O(n), i am trying to do it in O(1)
	sort(nums.begin(), nums.end());
	int count = 1;
	int maxcount = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if ((nums[i] - nums[i-1]) == 1)
		{
			count++;
		}
		else if (nums[i] != nums[i - 1])
		{
			if (count > maxcount)
			{
				maxcount = count;
			}
			count = 1;
		}
	}
	if (count > maxcount)
	{
		maxcount = count;
	}
	return maxcount;
}
int longestConsecutive2(vector<int>& nums) { //O(n) time complexity
	if (nums.empty())
	{
		return 0;
	}
	unordered_set<int>set(nums.begin(),nums.end());	
	int maxcount = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (set.find(nums[i]-1)==set.end())// agar ye element se ek chota rest of the set me exit nai krta, 
			//agr nai krta to num[i] ek consecutive sequence ka start ha
		{
			int currentnum = nums[i];  //pichle element check hogya ha ab us se agla element se agy ka silsla check krna ha
			int count = 0;
			while (set.find(currentnum + 1)!=set.end())//mtlb usy incremented element mil gya ha
			{
				currentnum++; //agle consecutive elements ko check krne k liye iska increment kren ge
				count++;
			}
			count=max(count, maxcount);
		}
	}
	return maxcount;
}
int main7()
{
	vector<int>nums;
	nums = { 1,2,0,1 };
	int result = longestConsecutive(nums);
	cout << "\nResult="<<result;
}
