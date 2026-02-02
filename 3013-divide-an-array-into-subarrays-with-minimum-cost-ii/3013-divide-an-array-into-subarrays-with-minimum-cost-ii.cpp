#define ll long long
class Solution {
public:
    typedef pair<ll,ll> p;
    long long minimumCost(vector<int>& a, int k, int dist) {

        int n = a.size();
        k--; 
        set<p> main, rem;
        ll ans = 0;
        ll result = LLONG_MAX;
        int i = 1;

        // build first window
        while(i < n && i < dist+1 ){
            p temp = {a[i], i};
            main.insert(temp);
            ans += a[i];
            if(main.size() > k){
                p move = *main.rbegin();
                rem.insert(move);
                main.erase(move);
                ans -= move.first;
            }
            i++;
        }

        while(i < n){
            p add = {a[i], i};
            main.insert(add);
            ans += a[i];
            if(main.size() > k){
                p move = *main.rbegin();
                rem.insert(move);
                main.erase(move);
                ans -= move.first;
            }
            result = min(result, ans);
            int idx = i - dist;
            p remove = {a[idx], idx};
            if(main.count(remove)){
                main.erase(remove);
                ans -= remove.first;
                if(!rem.empty()){
                    p move = *rem.begin();
                    main.insert(move);
                    ans += move.first;
                    rem.erase(move);
                }
            } else {
                rem.erase(remove);
            }
            i++;
        }

        return result + a[0];
    }
};
