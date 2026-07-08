

class Solution {
public:
    static const long long MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefixSum(n, 0);
        vector<long long> preNonZeroNumber(n, 0);
        vector<long long> preCount(n, 0);

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            if (i > 0) {
                prefixSum[i] = prefixSum[i - 1];
                preNonZeroNumber[i] = preNonZeroNumber[i - 1];
                preCount[i] = preCount[i - 1];
            }

            if (digit != 0) {
                prefixSum[i] = (prefixSum[i] + digit) % MOD;

                preNonZeroNumber[i] =
                    (preNonZeroNumber[i] * 10 + digit) % MOD;

                preCount[i]++;
            }
        }

        int maxDigits = preCount[n - 1];

        vector<long long> power(maxDigits + 1, 1);

        for (int i = 1; i <= maxDigits; i++) {
            power[i] = (power[i - 1] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long len =
                preCount[r] - (l > 0 ? preCount[l - 1] : 0);

            long long x = preNonZeroNumber[r];

            if (l > 0) {
                x = (x -
                     (preNonZeroNumber[l - 1] * power[len]) % MOD +
                     MOD) % MOD;
            }

            long long sum =
                (prefixSum[r] -
                 (l > 0 ? prefixSum[l - 1] : 0) +
                 MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};