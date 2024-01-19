class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int sign = 1;
        long long result = 0;

        // Skip leading whitespaces
        while (i < s.size() && std::isspace(s[i])) {
            i++;
        }

        // Check for sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        // Process digits
        while (i < s.size() && std::isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');

            // Check for integer overflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            } else if (result * sign < INT_MIN) {
                return INT_MIN;
            }
        }

        return result * sign;
    }
};