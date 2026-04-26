class Solution {
public:
    string sortVowels(string s) {
        vector<pair<char,int>> vp;
        vector<char> c = {'a','e','i','o','u'};
        for(auto i:s){
            int flg=0;
            for(int j:c){
                if(j==i){
                    flg=1;
                    break;
                }
            }
            if(flg){
                int cnt=0;
                for(int j=0;j<vp.size();j++){
                    if(vp[j].first == i){
                        vp[j].second++;
                        cnt=1;
                        break;
                    }
                }
                if(!cnt){
                    vp.push_back({i,1});
                }
            }
        }
        int curr=-1;
        for(auto &i:s){
            int flg=0;
            for(int j:c){
                if(j==i){
                    flg=1;
                    break;
                }
            }
            if(flg){
                if(curr==-1 || vp[curr].second==0){
                    int maxm=0;
                    for(int j=0;j<vp.size();j++){
                        if(vp[j].second > maxm){
                            maxm=vp[j].second;
                            curr=j;
                        }
                    }
                }
                i=vp[curr].first;
                vp[curr].second--;
            }
        }
        return s;
    }
};