
class Solution {
public:
    int bs(vector<int>& num, int target, int ind) {
        int low = 0;
        int high = num.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid == ind) {
                if (mid + 1 <= high &&
                    num[mid + 1] + num[ind] == target) {
                    return mid + 1;
                }
                if (mid - 1 >= low &&
                    num[mid - 1] + num[ind] == target) {
                    return mid - 1;
                }
            }

            int sum = num[mid] + num[ind];

            if (sum == target && mid != ind) {
                return mid;
            }

            if (sum < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return INT_MIN;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for (int i = 0; i < n; i++) {
            int n1 = bs(numbers, target, i);

            if (n1 != INT_MIN && n1 != i) {
                return {i + 1, n1 + 1};
            }
        }

        return {};
    }
};
