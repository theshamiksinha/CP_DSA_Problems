#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";

#define MOD 1000000007;

char comp(char c){
    if(c == 'N'){
        return 'S';
    }
    if(c == 'S'){
        return 'N';
    }

    if( c == 'E'){
        return 'W';
    }
    if(c == 'W'){
        return 'E';
    }
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    int N = 0, S = 0, E = 0, W = 0;
    
    lp(0, s.size()){
        
        if(s[i] == 'N'){
            N++;
        }else if(s[i] == 'S'){
            S++;
        }else if(s[i] == 'E'){
            E++;
        }else{
            W++;
        }
    }

    if(s.size() == 2){ 
        if(s[0] == s[1]){
            cout << "RH" << endl;
        }else{
            no;
        }

    }else{
        if((N-S)%2 == 0 && (E-W)%2 == 0){

            if((N-S) == 0 && (E-W) == 0){

                char first = s[0]; 
                int oth = 1;

                lp(0, s.size()){
                    if(i == 0){
                        s[i] = 'H';
                    }else{
                        if(s[i] == comp(first) && oth == 1){
                            s[i] = 'H';
                            oth--;
                        }else{
                            s[i] = 'R';
                        }
                    }
                }

                cout << s << endl;
            
            }else{
 
                int cN = 0; int cS = 0;

                if(S != 0 && N!= 0){
                    lp(0, s.size()){
                        if(s[i] == 'S' && cS == 0){
                            s[i] = 'H';
                            S--;
                            cS++;
                        }else if(s[i] == 'N' && cN == 0){
                            s[i] = 'H';
                            N--;
                            cN++;
                        }
                        if(cN == 1 && cS == 1){
                            break;
                        }
                    }
                }
                
                int cE = 0; int cW = 0;

                if(E != 0 && W != 0){
                    lp(0, s.size()){
                        if(s[i] == 'E' && cE == 0){
                            s[i] = 'H';
                            E--;
                            cE++;
                        }else if(s[i] == 'W' && cW == 0){
                            s[i] = 'H';
                            W--;
                            cW++;
                        }
                        if(cE == 1 && cW == 1){
                            break;
                        }
                    }
                }

                cN = ceil(N/2.0);
                cS = ceil(S/2.0);
                cE = ceil(E/2.0);
                cW = ceil(W/2.0);

                lp(0, s.size()){
                    if(s[i] == 'N'){
                        if(cN > 0){
                            s[i] = 'R';
                            cN--;
                        }else{
                            s[i] = 'H';
                        }
                    }
                    if(s[i] == 'S'){
                        if(cS > 0){
                            s[i] = 'R';
                            cS--;
                        }else{
                            s[i] = 'H';
                        }
                    }
                    if(s[i] == 'E'){
                        if(cE > 0){
                            s[i] = 'R';
                            cE--;
                        }else{
                            s[i] = 'H';
                        }
                    }
                    if(s[i] == 'W'){
                        if(cW > 0){
                            s[i] = 'R';
                            cW--;
                        }else{
                            s[i] = 'H';
                        }
                    }
                }

                cout << s << endl;
            }

        }else{
            no;
        }
    }
    
    

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