
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		vector<int> L, R; L = R = vector<int>(prices.size(), 0);
		int min_a = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			L[i] = max(L[i - 1], prices[i] - min_a);
			min_a = min(min_a, prices[i]);
		}

		int max_a = prices.back();
		for (int i = prices.size() - 2; i >= 0; i--) {
			R[i] = max(R[i + 1], max_a - prices[i]);
			max_a = max(max_a, prices[i]);
		}

		int ans = R[0];
		for (int i = 1; i + 1 < prices.size(); i++)
			ans = max(ans, L[i] + R[i + 1]);
		return ans;	
    }
};