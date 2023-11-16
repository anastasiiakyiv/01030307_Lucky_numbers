#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int findLucky(vector<int>& arr) {
		map<int, int> counter;

		for (int num : arr) {
			counter[num]++;
		}

		vector<int> luckyNumbers;

		for (auto& pair : counter) {
			if (pair.first == pair.second) {
				luckyNumbers.push_back(pair.first);
			}
		}

		if (luckyNumbers.empty()) {
			return -1;
		}
		else if (luckyNumbers.size() == 1) {
			return luckyNumbers[0];
		}
		else {
			int maxLucky = luckyNumbers[0];
			for (int i = 1; i < luckyNumbers.size(); ++i) {
				if (luckyNumbers[i] > maxLucky) {
					maxLucky = luckyNumbers[i];
				}
			}
			return maxLucky;
		}
	}
};

int main()
{
	vector<int> items;
	int item;
	string line;

	cout << "Enter the numbers: ";
	getline(cin, line);
	istringstream is(line);

	while (is >> item) {
		items.push_back(item);
	}

	Solution solution;
	cout << "Result: " << solution.findLucky(items);
	return 0;
}
