class Solution {
public:
    set<string> ans;
    void solve(vector<int>&rh,vector<int>&min,int cnt,int i, int j,int hour,int mins){
        if(hour>11 || mins >59) return;
        if(cnt==0){
            string h= to_string(hour);
            string m=to_string(mins);
            if(mins<10) m='0'+m;
            ans.insert(h+':'+m);
            return;
        }
        if(i>=rh.size() && j>=min.size()) return;
        if(i>=rh.size()){
            mins+=min[j];
            solve(rh,min,cnt-1,i,j+1,hour,mins);
            return;
        }
        if(j>=min.size()){
            hour+=rh[i];
            solve(rh,min,cnt-1,i+1,j,hour,mins);
            return;
        }
        hour+=rh[i];
        solve(rh,min,cnt-1,i+1,j,hour,mins);
        hour-=rh[i];
        mins+=min[j];
        solve(rh,min,cnt-1,i,j+1,hour,mins);
        mins-=min[j];
        solve(rh,min,cnt,i+1,j,hour,mins);
        solve(rh,min,cnt,i,j+1,hour,mins);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> rh={8,4,2,1};
        vector <int> min={32,16,4,8,2,1};
        solve(rh,min,turnedOn,0,0,0,0);
        vector<string> temp;
        for(auto i:ans) temp.push_back(i);
        return temp;
    }
};