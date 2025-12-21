#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
class disjointset {
private:
    vector<int> parents;
    vector<int> sizes;
    vector<int> ranks;

public:
    disjointset(int n) { // n= number of nodes 0 based 
        parents.resize(n);
        sizes.assign(n, 1); // All sizes start as 1
        ranks.assign(n, 0); // All ranks start as 0

        for (int i = 0; i < n; i++) {
            parents[i] = i; // Each node is its own parent
        }
    }

    // @return the representative of x with path compression 
    int findparent(int x) {
        return parents[x] == x ? x : (parents[x] = findparent(parents[x]));
    }

    // Union by rank 
    bool unionbyrank(int x, int y) {
        int x_root = findparent(x);
        int y_root = findparent(y);
        if (x_root == y_root) return false;

        if (ranks[x_root] < ranks[y_root]) {
            parents[x_root] = y_root;
        } else if (ranks[x_root] > ranks[y_root]) {
            parents[y_root] = x_root;
        } else {
            parents[y_root] = x_root;
            ranks[x_root]++;
        }
        return true;
    }

    // Union by size 
    bool unionbysize(int x, int y) {
        int x_root = findparent(x);
        int y_root = findparent(y);
        if (x_root == y_root) return false;

        if (sizes[x_root] < sizes[y_root]) {
            parents[x_root] = y_root;
            sizes[y_root] += sizes[x_root];
        }
        else{
            parents[y_root] = x_root;
            sizes[x_root] += sizes[y_root];
        }
        
        return true;
    }

    // @return whether x and y are in the same set 
    bool isconnected(int x, int y) {
        return findparent(x) == findparent(y);
    }
};

 
void solve()
{
 
    vector<vector<int>> pts;
    int x,y,z;
    char comma;
    while(cin>>x>>comma>>y>>comma>>z){
        pts.push_back({x,y,z});
    }
    vector<array<int,3>> edges;
    for(int i=0;i<pts.size();i++){
        for(int j=i+1;j<pts.size();j++){
            int dx=pts[i][0]-pts[j][0];
            int dy=pts[i][1]-pts[j][1];
            int dz=pts[i][2]-pts[j][2];
            int dist=dx*dx+dy*dy+dz*dz;
            edges.push_back({i,j,dist});
        }
    }
    sort(edges.begin(),edges.end(),[&](auto &a,auto &b){
        return a[2]<b[2];
    });
    /* PART 1*/
    // disjointset dsu(pts.size());
    // int used=0;
    // for(auto &e:edges){
    //     if(used==1000) break;
    //     dsu.unionbysize(e[0],e[1]);
    //     used++;
    // }

    // unordered_map<int,int> mpp;
    // for(int i=0;i<pts.size();i++){
    //     mpp[dsu.findparent(i)]++;
    // }
    // vector<int> ans;
    // for(auto &[key,val]:mpp){
    //     ans.push_back(val);
    // }
    // sort(ans.begin(),ans.end(),greater<int>());
    
    // cout<<ans[0]*ans[1]*ans[2]<<endl;

    
    /*   PART  2*/
    disjointset dsu(pts.size());
    int components=pts.size();
    for(auto &e:edges){
        if(!dsu.isconnected(e[0],e[1])){
            dsu.unionbysize(e[0],e[1]);
            components--;
            if(components==1){
                int ans=pts[e[0]][0]*pts[e[1]][0];
                cout<<ans<<endl;
                break;
            }
        }
    }

 
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