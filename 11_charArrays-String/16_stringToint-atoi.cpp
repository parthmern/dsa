#include <iostream>
#include <climits> // For INT_MAX and INT_MIN
#include <string>

int myAtoi(std::string s) {
    int num = 0, i = 0, sign = 1; // Initialize the number, index, and sign

    // Skip leading whitespaces
    while (s[i] == ' ') {
        i++;
    }

    // Check for sign
    if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
        sign = s[i] == '+' ? 1 : -1;
        i++;
    }

    // Convert characters to integer
    while (i < s.size() && isdigit(s[i])) {
        // Check for overflow
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }

        num = num * 10 + (s[i] - '0'); // Update the number
        i++;
    }

    return num * sign; // Return the final result
}

int main() {
    std::string input = "1337c0d3";
    int result = myAtoi(input);
    std::cout << "Output: " << result << std::endl; // Output: 1337

    return 0;
}
