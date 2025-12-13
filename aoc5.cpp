#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
 
void solve()
{
 /*PART 1 */
    // vector<pair<int,int>> ranges;
    // string line;
    // while(getline(cin, line)){
    //     if(line.empty()) break;
    //     int l,r;
    //     char dash;
    //     stringstream ss(line);
    //     ss>>l>>dash>>r;
    //     ranges.push_back({l,r});
    // }
    // int x;
    // int cnt=0;
    // while(cin>>x){
    //     for(auto &[l,r]:ranges){
    //         if(l<=x && x<=r) {
    //             cnt++;
    //             // cout<<x<<" "<<cnt<<endl;
    //             break;
    //         }
    //     }

    // }
    // cout<<cnt<<endl;
    



    vector<pair<int,int>> ranges;
    string line;
    while(getline(cin,line)){
        if(line.empty()) break;
        int l,r;
        char dash;
        stringstream ss(line); ss>>l>>dash>>r;
        ranges.emplace_back(l,r);
    }
    //boot the rest dont care 
    sort(ranges.begin(),ranges.end()); //merging
    vector<pair<int,int>> merged;
    for(auto &[l,r]:ranges){
        if(merged.empty() || merged.back().second<l-1) merged.emplace_back(l,r);
        else merged.back().second=max(merged.back().second,r);
    }
    int ans=0;    
    for(auto &[l,r]:merged){
        ans+=r-l+1;
    }
    cout<<ans<<endl;
    
}
 
 
 
signed main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tc=1;
    // cin>>tc;
 
    while(tc--)
    {
        solve();
    }
    return 0;
}