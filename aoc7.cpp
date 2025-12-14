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
     /*     PART 1       */
    // string line;
    // vector<string> grid;
    // while(getline(cin,line)){
    //     if(line.empty()) break;
    //     grid.push_back(line);
    // }
    // int rows=grid.size();
    // int cols=grid[0].size();

    // int Sposn=find(begin(grid[0]),  end(grid[0]),  'S')-begin(grid[0]);
    // grid[0][Sposn]='|';
    // int ans=0;
    // for(int r=1;r<rows;r++){
    //     for(int c=0;c<cols;c++){
    //         if(grid[r][c]=='^' && grid[r-1][c]=='|'){
    //             ans++;
    //             if(c-1>=0) grid[r][c-1]='|';
    //             if(c+1<cols) grid[r][c+1]='|';
    //         }
    //         else if(grid[r][c]=='.' && grid[r-1][c]=='|') grid[r][c]='|';

    //     }
    // }
    // cout<<ans<<endl;







    string line;
    vector<string> grid;
    while(getline(cin,line)){
        if(line.empty()) break;
        grid.push_back(line);
    }
    int rows=grid.size();
    int cols=grid[0].size();
 
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