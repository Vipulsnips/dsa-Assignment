class Solution {
public:
    long long ncr(long long n ,long long r,int k){
        r=min(r,n-r);
        long long ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(n-r+i)/i;
            if(ans>=k) return k;
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        vector<int> c(26,0);
        for(char i:s) c[i-'a']++;
        char mid=' ';string ans;
        for(int i=0;i<26;i++){
            ans.append(c[i]/2,char('a'+i));
            if(c[i]&1) mid=char('a'+i);
            c[i]/=2;
        }
        int i=0,n=ans.size();string result;
        while(i<n){
            bool placedCharacter = false;
            for(int j=0;j<26;j++){
                long long sz=(n-i-1);
                if (c[j] == 0) continue;
                c[j]--;
                long long comb=1;
                for(int v=0;v<26;v++){
                    if(c[v]==0) continue;
                    comb*=ncr(sz,c[v],k);
                    if(comb>=k) break;
                    else sz-=c[v];
                }
                if(k>comb){
                    k-=comb;
                    c[j]++;
                }
                else{
                    result+=char(j+'a');
                    i++;
                    placedCharacter=true;
                    break;
                }
            }
            if(!placedCharacter) return "";
        }
        string rev = result;
        reverse(rev.begin(), rev.end());
        if(mid!= ' ') return result+mid+rev;
        return result+rev;
    }
};