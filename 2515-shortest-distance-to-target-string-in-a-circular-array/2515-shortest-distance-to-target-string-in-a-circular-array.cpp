class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(count(words.begin(),words.end(),target)==0) return -1;
        int i= find(words.begin(),words.end(),target) -words.begin();
        int ans=INT_MAX,n=words.size();
        for(int i=0;i<n;i++){
            if(words[i]==target){
                int d=abs(i-startIndex);
                ans=min(ans,min(d,n-d));
            }
        }
        return ans;
    }
};