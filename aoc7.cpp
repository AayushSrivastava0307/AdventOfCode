#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 





int fun(int row, int col, vector<string> &grid,vector<vector<int>> &dp){
    if(row==grid.size()-1) return 1;

    if(dp[row][col]!=-1) return dp[row][col];
    int ans=0;
    if (grid[row+1][col]=='^'){
        ans+=  (col+1<grid[0].size())?fun(row+1,col+1,grid,dp):0;
        ans+=  (col-1>=0)?fun(row+1,col-1,grid,dp):0;
    }
    else ans+=fun(row+1,col,grid,dp);

    return dp[row][col]=ans;
}

 
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
    int Sposn=find(begin(grid[0]),  end(grid[0]),  'S')-begin(grid[0]);
    grid[0][Sposn]='|';
    vector<vector<int>> dp(rows,vector<int>(cols,-1));
    cout<<fun(0,Sposn,grid,dp)<<endl;

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