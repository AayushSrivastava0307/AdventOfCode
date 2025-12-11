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
 
    int curr=50;
    int zc=0;
    int cloud=1e5; // enough
    while(cloud--){
        string s;cin>>s; char mov=s[0];
        if(mov=='L'){
            string num=s.substr(1);
            int numero=stoi(num);
            
            int need = curr%100;     //min req to go left
            if(need == 0){
                zc += numero / 100;         
            } else if(numero >= need){
                zc += 1 + (numero - need) / 100;
            }

            curr=(curr-numero%100)%100;
            curr=(curr+100)%100;
            // if(curr==0) zc+=1; comment out need block for part 1 
        }
        if(mov=='R'){
            string num=s.substr(1);
            int numero=stoi(num);

            int need = (100-curr)%100;   //min req to go right
            if(need == 0){
                zc += numero / 100;         
            } else if(numero >= need){
                zc += 1 + (numero - need) / 100;
            }

            curr=(curr+numero%100)%100;
            curr=(curr+100)%100;
            // if(curr==0) zc+=1;  comment out need block for part 1 
        }

    }
    cout<<zc<<endl;
 
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