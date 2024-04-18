class Solution {
public:
    int numDistinct(string s, string t) {
        // Call the private dfs function with initial parameters and return its result
        return dfs(s, t, 0, 0);
    }
private:
    // Define a memoization map to store computed results
    map<pair<int, int>, int> memory;
    
    // Define a private recursive function to perform depth-first search
    int dfs(string& s, string& t, int i, int j) {
        // Base cases:
        // If j reaches the end of t, we found a valid subsequence, return 1
        if (j == t.size()) {
            return 1;
        }
        // If i reaches the end of s but j hasn't reached the end of t,
        // it's not possible to form the subsequence, return 0
        if (i == s.size()) {
            return 0;
        }
        // If the result for current (i, j) pair is already computed,
        // return it from the memory map
        if (memory.find({i, j}) != memory.end()) {
            return memory[{i, j}];
        }
        
        // If s[i] equals t[j], we have two choices:
        if (s[i] == t[j]) {
            // Include s[i] in the subsequence and recursively explore the next characters
            // by calling dfs with incremented i and j, and add it with excluding s[i]
            memory[{i, j}] = dfs(s, t, i + 1, j + 1) + dfs(s, t, i + 1, j);
        } else {
            // If s[i] doesn't equal t[j], exclude s[i] from the subsequence
            // and only move forward in s
            memory[{i, j}] = dfs(s, t, i + 1, j);
        }
        // Return the computed result for current (i, j) pair
        return memory[{i, j}];
    }
};