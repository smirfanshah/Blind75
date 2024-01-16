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
int characterReplacement(string s, int k) {
	int n = s.length();
	int left = 0;
	int right = 0;
	int maxi = 0;
	unordered_map<char, int> mp;
	int result = 0;
	while (right < n)
	{
		mp[s[right]]++;
		maxi = max(maxi, mp[s[right]]);
		// If the number of replacements needed is more than 'k',
		// move the left pointer to shrink the window

		if ((right-left+1-maxi)>k)
		{
			mp[s[left]]--;
			left++;

		}
		result = max(result, right - left + 1);
		right++;
	}
	return result;
}
int main13()
{
	string s = { "AAAA" };
	int a = characterReplacement(s, 0);
	cout << "Length= " << a;
	return 0;
}
bool isValidpair(char open, char close) {
	return (open == '{' && close == '}') ||
		(open == '(' && close == ')') ||
		(open == '[' && close == ']');
}
bool isValid(string s) {
	if (s.size() % 2 != 0)
	{
		return false;
	}
	stack<char> st;
	while (!s.empty())
	{
		char cur = s.front();
		if (cur == '{' || cur == '(' || cur == '[')
		{
			st.push(cur);

		}
		else if (cur == '}' || cur == ')' || cur == ']')
		{
			if (st.empty() || !isValidpair(st.top(), cur))
			{
				return false;
			}
			st.pop();
		}
		else
		{
			return false;
		}

		s.erase(s.begin());
	}
	return st.empty();
}
int main14() {
	string s = "()";
	if (isValid(s))
	{
		cout << "true";
	}
	else
		cout << "false";

	return 0;
}
bool isValidChar(char ch, const string& t) {
	for (int i = 0; i < t.size(); i++) {
		if (ch == t[i]) {
			return true;
		}
	}
	return false;
}

bool isValidWindow(const unordered_map<char, int>& st, const unordered_map<char, int>& target) {
	for (const auto& entry : target) {
		if (st.find(entry.first) == st.end() || st.at(entry.first) < entry.second) {
			return false;
		}
	}
	return true;
}

string minWindow(const string& s, const string& t) {
	unordered_map<char, int> st;
	unordered_map<char, int> target;

	for (char ch : t) {
		target[ch]++;
	}

	int right = 0;
	int left = 0;
	int mini = s.size() + 1;
	int start = 0;

	while (right < s.size()) {
		if (isValidChar(s[right], t)) {
			st[s[right]]++;
			while (isValidWindow(st, target)) {
				if (right - left + 1 < mini) {
					mini = right - left + 1;
					start = left;
				}
				if (isValidChar(s[left], t)) {
					st[s[left]]--;
				}
				left++;
			}
		}
		right++;
	}

	return (mini == s.size() + 1) ? "" : s.substr(start, mini);
}
int main15() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string result = minWindow(s, t);
    cout << "Minimum window: " << result << endl;

    return 0;
}
int findMin(vector<int>& nums) {
	int res = nums[0];
	int l=0, r = nums.size()-1;
	while (l <= r)
	{
		if (nums[l] < nums[r])
		{
			res = min(res, nums[l]);
			break;
		}
		int mid = (l + r) / 2;
		res = min(res,nums[mid]);
		if (nums[mid] >= nums[l])
		{
			l = mid+1;
		}
		else
		{
			r = mid-1;
		}
	}
	return res;
}
int main16()
{
	vector<int>nums = { 2,1};
	int a=findMin(nums);
	cout << "Min =" << a;
}
int search(vector<int>& nums, int target) {
	int right = nums.size() - 1, left = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		
		if (nums[mid] == target)
		{
			return mid;
		}
		//checking whether i am in left sorted portion or right portion
		if (nums[mid] > nums[left] )
		{
			if (nums[left] > target || target>nums[mid])
			{
				left = mid + 1;
			}
			else 
			{
				right = mid - 1;
			}

		}
		else 
		{
			if (nums[mid] > target || target>nums[right])
			{
				right = mid - 1;
			}
			else 
			{
				left = mid + 1;
			}

		}
	}
	return -1;
}
int main17()
{
	vector<int>nums = { 4,5,6,-1,0,1,2 };
	int a = search(nums, 0);
	cout << "index =" << a;
}
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* reverseList(ListNode* head)
{
	ListNode* prev = NULL;
	ListNode* curr = head;
	while (curr!= nullptr)
	{
		ListNode* forward = curr->next;
		curr->next = prev;
		prev = curr;
		curr = forward;

	}
	return prev;

}
void printList(ListNode* head) {
	while (head != nullptr) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
int main18()
{
	ListNode* node = new ListNode(1);
	node->next = new ListNode(2);
	printList(node);
	node= reverseList(node);
	printList(node);
	// Clean up the memory (deallocate the linked list)
	while (node != nullptr) {
		ListNode* temp = node;
		node = node->next;
		delete temp;
	}

}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode* result = new ListNode();
	ListNode* temp = result;

	while (list1 != nullptr && list2!=nullptr)
	{
		if (list1->val <= list2->val)
		{
			temp->next = list1;
			list1=list1->next;
		}
		else
		{
			temp->next = list2;
			list2 = list2->next;
		}
		temp=temp->next;
	}
	if (list1 != nullptr) //remaing part copied 
	{
		temp->next = list1;
	}
	else
	{
		temp->next = list2;
	}
	return result->next;
}
int main19()
{
	ListNode* node = new ListNode(1);
	node->next = new ListNode(2);
	node->next->next = new ListNode(4);
	ListNode* node1 = new ListNode(1);
	node1->next = new ListNode(3);
	node1->next->next = new ListNode(4);
	printList(node);
	printList(node1);
	node = mergeTwoLists(node, node1);
	printList(node);
	// Clean up the memory (deallocate the linked list)
	while (node != nullptr) {
		ListNode* temp = node;
		node = node->next;
		delete temp;
	}
	return 0;

}
//1 2 3 4 5 
ListNode* reorderList(ListNode* head) {
	if (head->next == nullptr||head==nullptr)
	{
		return head;
	}
	ListNode* slow = head; //1
	ListNode* fast= head;//1
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow =slow->next;
		fast =fast->next->next;
	}
	ListNode* remhalf = slow->next;//4 5
	remhalf=reverseList(remhalf);//5 4
	ListNode* current = head;//1
	ListNode* remhalfptr = remhalf;
	while (remhalfptr != nullptr)
	{
		ListNode* newNode = current->next; //2->3
		current->next = remhalfptr; //1->5->2->3
		remhalfptr = remhalfptr->next;//4
		current->next->next = newNode;
		current = newNode;
	}
	// Setting the last node's next to nullptr
	if (current != nullptr)
	{
		current->next = nullptr;
	}
	return head;
}
int main20()
{
	ListNode* node = new ListNode(1);
	node->next = new ListNode(2);
	node->next->next = new ListNode(3);
	node->next->next->next = new ListNode(4);
//	node->next->next->next->next = new ListNode(5);
	/*stack<int>S=reorderList(node);
	while (!S.empty())
	{
		cout << S.top()<<" ";
		S.pop();
	}*/
	printList(node);
	node = reorderList(node);
	printList(node);
	return 0;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head == nullptr)
	{
		return head;
	}
	int count = 0;
	ListNode* temp = head;
	while (temp!= nullptr)
	{
		count++;
		temp = temp->next;
	}
	int index = count - n;
	if (index == 0) {
		ListNode* newHead = head->next;
		delete head; // Deallocate memory for the old head
		return newHead; // Update head pointer
	}
	ListNode* temp1 = head;
	while (index > 1) {
		temp1 = temp1->next;
		index--;
	}

	//ListNode* nodeToRemove = temp1->next;
	temp1->next = temp1->next->next;

	//delete nodeToRemove; // Deallocate memory for the removed node

	return head;

}
ListNode* removeNthFromEnd2(ListNode* head, int n) {
	if (head == nullptr) {
		return nullptr;
	}

	int count = 0;
	ListNode* temp = head;
	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}

	int index = count - n;

	// Check if removing the head
	if (index == 0) {
		ListNode* newHead = head->next;
		delete head; // Deallocate memory for the old head
		return newHead; // Update head pointer
	}

	ListNode* temp1 = head;
	while (index > 1) {
		temp1 = temp1->next;
		index--;
	}

	ListNode* nodeToRemove = temp1->next;
	temp1->next = temp1->next->next;

	delete nodeToRemove; // Deallocate memory for the removed node

	return head;
}

int main21()
{
	ListNode* node = new ListNode(1);
	node->next = new ListNode(2);
	//node->next->next = new ListNode(3);
	//node->next->next->next = new ListNode(4);
	printList(node);
	node = removeNthFromEnd(node, 1);
	printList(node);
}
