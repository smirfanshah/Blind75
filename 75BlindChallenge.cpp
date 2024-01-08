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
bool isPalindrome(string s) {
	int left = 0;
	int right = s.size() - 1;
	while (left < right)
	{
		while (left < right && !isalnum(s[left]))//if not legal num or alpha then leave it and move forward
		{
			left++;
		}
		while (left < right && !isalnum(s[right]))//if not legal num or alpha then leave it and move backard
		{
			right--;
		}
		char leftch = tolower(s[left]);
		char rightch = tolower(s[right]);
		if (leftch != rightch)
		{
			return false;
		}
		else
		{
			left++;
			right--;
		}
	}
	return true;
}
int main8()
{
	string s = "race a car";
	if (isPalindrome(s))
	{
		cout << "true";
	}
	else
		cout << "false";
}
vector<vector<int>> threeSum(vector<int>& nums) {

	sort(nums.begin(), nums.end());

	vector<vector<int>> result;

	for (int i = 0; i < nums.size(); i++) {
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}

		int left = i + 1;
		int right = nums.size() - 1;
		int target = -nums[i];

		while (left < right) {
			if (nums[left] + nums[right] == target) {
				result.push_back({ nums[i], nums[left], nums[right] });

				while (left < right && nums[left] == nums[left + 1]) {//if next element is same
					left++;
				}
				while (left < right && nums[right] == nums[right - 1]) {
					right--;
				}

				left++;
				right--;
			}
			else if (nums[left] + nums[right] < target) {
				left++;
			}
			else {
				right--;
			}
		}
	}

	return result;
}
int main9()
{
	vector<int>nums = { -1,0,1,2,-1,-4 };
	vector<vector<int>>ans = threeSum(nums);
	for (const auto& row : ans)
	{
		for (const auto& col : row)
		{
			cout << col<<" ";
		}
		cout << endl;
	}
	return 0;
}
int maxArea(vector<int>& height) {
	int maxi = 0;
	int left = 0;
	int right = height.size() - 1;
	while (left < right)
	{
		int width = right - left;
		int length = min(height[left], height[right]);
		int area = length * width;
		maxi = max(maxi, area);
		if (height[left] > height[right])
			right--; //agr yaha pr left++ kr deta to bri value(jo iski apni ha) miss krwa kr isne agy chle jana tha, or faida nai hona tha
		else
			left++;
	}
	return maxi;
}
int main10()
{
	vector<int>height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	int ans = maxArea(height);
	cout << "maxArea = "<<ans;
	return 0;
}
int maxProfit(vector<int>& prices) { //ek qism ka hum ne maximum diffrence nikalna ha, pehle ane wale most min ka bad me ane most max se 
	if (prices.empty())
	{
		return 0;
	}
	int min = prices[0];
	int maxi = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (min > prices[i])
		{
			min = prices[i];
		}
		else
		{
			maxi = max(maxi, prices[i] - min);
		}
	}
	return maxi;
}
int main11()
{
	vector<int>nums = { 7,1,5,3,6,4 };
	int ans = maxProfit(nums);
	cout << "maxProfit = " << ans;
	return 0;
}
int lengthOfLongestSubstring(string s) { //Using sliding Window
	int n = s.length();
	int left = 0,right = 0,count=0;
	unordered_set<char> st;
	while (right < n)
	{
		if (st.find(s[right]) == st.end())
		{
			st.insert(s[right]);
			count = max(count, right - left + 1);//subarray
			right++;
		}
		else
		{
			st.erase(s[left]);
			left++;
		}
	}
	return count;

}
int main12()
{
	string s = { "pwwkew" };
	int a = lengthOfLongestSubstring(s);
	cout << "LENGTH = " << a;
	return 0;
}
