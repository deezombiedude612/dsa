#ifndef BALANCEDEXPRESSION_CPP
#define BALANCEDEXPRESSION_CPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char leftBrackets[] = {'(', '<', '[', '{'};
const char rightBrackets[] = {')', '>', ']', '}'};

/**
 * @brief Checks to see if ch is a left bracket character
 * 
 * @param ch - Character to be checked
 * @return true 
 * @return false 
 */
bool isLeftBracket(const char ch) {
	for (unsigned int i = 0; i < (sizeof(leftBrackets) / sizeof(leftBrackets[0])); ++i) {
		if (ch == leftBrackets[i]) return true;
	}

	return false;
}

/**
 * @brief Checks to see if ch is a right bracket character
 * 
 * @param ch - Character to be checked
 * @return true 
 * @return false 
 */
bool isRightBracket(const char ch) {
	for (unsigned int i = 0; i < (sizeof(rightBrackets) / sizeof(rightBrackets[0])); ++i) {
		if (ch == rightBrackets[i]) return true;
	}

	return false;
}

/**
 * @brief Checks to see if left and right brackets make a complementing pair
 * 
 * @param left - Left bracket to be compared
 * @param right - Right bracket to be compared
 * @return true 
 * @return false 
 */
bool bracketsMatch(const char left, const char right) {
	int leftIndex = -1, rightIndex = -1;

	for (unsigned int i = 0; i < (sizeof(leftBrackets) / sizeof(leftBrackets[0])); ++i) {
		if (left == leftBrackets[i]) {
			leftIndex = i;
			break;
		}
	}
	if (leftIndex < 0) return false;

	for (unsigned int i = 0; i < (sizeof(rightBrackets) / sizeof(rightBrackets[0])); ++i) {
		if (right == rightBrackets[i]) {
			rightIndex = i;
			break;
		}
	}
	if (rightIndex < 0) return false;

	if (leftIndex != rightIndex) return false;

	return true;
}

/**
 * @brief Checks to see if string is balanced brackets-wise
 * 
 * @param testString - String to be checked
 * @return true 
 * @return false 
 */
bool isBalanced(string testString) {
	vector<char> stack;

	for (auto it = testString.cbegin(); it != testString.cend(); ++it) {
		// cout << *it << " ";

		if (isLeftBracket(*it)) {
			// cout << "LEFT!\n";
			stack.push_back(*it);
		}

		if (isRightBracket(*it)) {
			// cout << "RIGHT!\n";
			if (stack.empty()) return false;

			char top = stack.back();
			if (!bracketsMatch(top, *it)) return false;
			stack.pop_back();
		}
	}
	cout << endl;

	return stack.empty();
}

int main(int argc, char **argv) {
	string testString1 = "(This is a [balanced] string)";
	string testString2 = "{This is an [unbalanced} string)";

	if (isBalanced(testString1))
		cout << "GOOD!\n";
	else
		cout << "NOT GOOD!\n";

	if (isBalanced(testString2))
		cout << "GOOD!\n";
	else
		cout << "NOT GOOD!\n";

	return 0;
}

#endif
