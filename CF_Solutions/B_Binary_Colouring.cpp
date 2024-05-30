#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define int long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";


void solve(){
    int x; cin >> x;
    string result = "";
    for(int i = 33; i >= 0; i--) {
        result += (x & (1LL << i)) ? '1' : '0';
    }
    reverse(result.begin(), result.end());
 
    int i = 0;
    int st = -1;
    int en = -1;
    while(i < 32){
        if(result[i] != '0' && st == -1){
            st = i; 
        }else if(result[i] != '0' && st != -1){
            en = i;
        }else if(result[i] == '0' && st != -1 && en != -1){
             
            result[st] = 'n';   
            
            for(int j = st+1; j <= en; j++) { 
                result[j] = '0'; 
            } 

            result[en+1] = '1';  

            st = -1; en = -1;
            i--;
        }else{ 
            st = -1; en = -1;
        }
        i++;
    } 

    cout << 32 << endl;
    
    lp(0, 32){
        if(result[i] == 'n'){
            cout << -1 << " ";
        }else{
            cout << result[i] << " ";
        }
    }

    cout << endl;

    cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    cin >> x;
    while(x--){
        solve();
    }
}