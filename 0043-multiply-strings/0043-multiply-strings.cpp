#include<bits/stdc++.h>
class Solution {
public:
    string multiply(string num1, string num2) {
        string final="";
        vector<string>s;
        for(int i=num1.size()-1; i>=0; i--){
            string ans="";
            int carry=0;
            for(int j=num2.size()-1; j>=0; j--){
                int num=(num1[i]-'0')*(num2[j]-'0')+carry;
                ans+=to_string(num%10);
                carry=num/10;
            }
            if(carry){ans+=to_string(carry);}
            int l=num1.size()-i-1;
            while(l){
                ans.insert(ans.begin(), '0');
                l--;
            }
            reverse(ans.begin(), ans.end());
            s.push_back(ans);
        }
        if(s.size()==1){
            if(count(s[0].begin(), s[0].end(), '0')==s[0].size()){return "0";}
            return s[0];
        }
        for(int i=0; i<s.size(); i++){
            cout<<s[i]<<endl;
        }
        for(int i=0; i<s.size()-1; i++){
            string s1=s[i], s2=s[i+1];
            reverse(s1.begin(), s1.end());
            reverse(s2.begin(), s2.end());
            int carry=0;
            string fi="";
            if(s1.size()>s2.size()){
                for(int j=0; j<s2.size(); j++){
                    int num=(s1[j]-'0')+(s2[j]-'0')+carry;
                    carry=num/10;
                    fi+=to_string(num%10);
                }
                for(int j=s2.size(); j<s1.size(); j++){
                    int num=(s1[j]-'0')+carry;
                    carry=num/10;
                    fi+=to_string(num%10);
                }
                if(carry){
                    fi+=to_string(carry);
                }
                reverse(fi.begin(), fi.end());
            }
            else{
                cout<<"here"<<endl;
                for(int j=0; j<s1.size(); j++){
                    int num=(s1[j]-'0')+(s2[j]-'0')+carry;
                    carry=num/10;
                    fi+=to_string(num%10);
                }
                cout<<fi<<endl;
                for(int j=s1.size(); j<s2.size(); j++){
                    int num=(s2[j]-'0')+carry;
                    carry=num/10;
                    fi+=to_string(num%10);
                }
                if(carry){
                    fi+=to_string(carry);
                }
                reverse(fi.begin(), fi.end());
            }
            cout<<s[i]<<" "<<s[i+1]<<" "<<fi<<endl;
            final=fi;
            s[i+1]=fi;
        }
        cout<<final<<" "<<count(final.begin(), final.end(), '0')<<" "<<final.size()<<endl;
        if(count(final.begin(), final.end(), '0')==final.size()){return "0";}
        return final;
    }
};