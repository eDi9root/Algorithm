class Solution {
public:
    int n;
    set<vector<int>> st;
    vector<int> ans1;
    void f(int mask,vector<int>& v){
        //If all the elements are fitted in the array ans1
        if(mask==(1<<n)-1){
            //then we store ans1 vector in the set (why set ? because it will prune the duplicate vectors) 
            st.insert(ans1);
            return;
        }
        for(int i=0;i<n;i++){
            //checking if ith number in the array is not used in the permutation
            if((mask&(1<<i))==0){
                //pick
                ans1.push_back(v[i]);
                f(mask^(1<<i),v);
                //drop (pick and drop are part of backtracking)
                ans1.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        f(0,nums);
        vector<vector<int>> ans;
        //storing all the elements of the set in the ans vector of vector since return type is vector of vector
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};