// Two sums - Return exactly one index pair from a list that adds up to that target !

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

// Time complexity = O(n^2)
std::vector<int> evaluateTwoSumsBruteForce(std::vector<int>& nums, int target)
{
	int count = nums.size();
    std::vector<int> answer;
    for(int i=0; i<count; i++)
    {
        for(int j=0; j<count; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                answer.push_back(i);
                answer.push_back(j);
            }
        }
    }
    return answer;
}

// Time complexity: O(nlogn) {sorting} + O(n) {two pointers} + O(n) {index finder} = O(nlogn)
std::vector<int> evaluateTwoSumsTwoPointers(std::vector<int>& nums, int target)
{
    std::vector<int> answer;
    std::vector<int> copyArr = nums;
    // Sorting first is crucial so that the smaller numbers are at left and larger at right !
    std::sort(nums.begin(), nums.end());
    // Two pointers left and right traversing from opposite polar ends.
    // Use a small number and a large number to add up to that target !
    int l = 0;
    int n = nums.size();
    int r = n - 1;
    while(l <= r)
    {
    	int sum = nums[l] + nums[r];
    	if(sum == target)
		{
			break;			
		}
		else if(sum < target)
		{
			l += 1;
		}
		else
		{
			r -= 1;
		}
	}
	// Index finder
	for(int k = 0; k<n; k++)
	{
		if(copyArr[k] == nums[l] || copyArr[k] == nums[r])
		{
			answer.push_back(k);
		}
	}
	
    return answer;
}

// Time complexity: O(n)
std::vector<int> evaluateTwoSumsHashMap(std::vector<int>& nums, int target)
{
    std::vector<int> answer;
    std::unordered_map<int, int> hashMap;
    
    for(int i=0; i<nums.size(); i++)
    {
    	int findValue = target - nums[i];
    	if(hashMap.find(findValue) != hashMap.end())
    	{
    		answer.push_back(hashMap.at(findValue));
    		answer.push_back(i);
    		break;
		}
		hashMap.insert({nums[i], i});
	}
	
    return answer;
}

int main(int argc, char *argv[])
{
	std::vector<int> nums = {1, 4, 2, 0, 5};
	std::vector<int> answer = evaluateTwoSumsBruteForce(nums, 7);
	std::cout << "Bruteforce: [" << answer[0] << "," << answer[1] << "]" << std::endl ;
	std::vector<int> copyNums = nums;
	answer = evaluateTwoSumsTwoPointers(nums, 7);
	std::cout << "Two pointers: [" << answer[0] << "," << answer[1] << "]" << std::endl ;
	// The reason I pass copy array here is because the functions are getting value by reference 
        // which is getting sorted at reference in solution 2 [Easy solution is to pass by value !]
	answer = evaluateTwoSumsHashMap(copyNums, 7);
	std::cout << "Hash Map: [" << answer[0] << "," << answer[1] << "]" ;
	return 0 ;
}
