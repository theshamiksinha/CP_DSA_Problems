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

int func( bool set, int currScore1, int currScore2, int track, int pt, int ans, vector<int> &a1, vector<int> &a2){

    while(pt < 5){
        if(set){

            int rem = 5 - pt;
            currScore1 += a1[pt];
            track++;

            if(currScore1 > currScore2 + rem){
                return (min(ans, track)); 
            }

            rem = 5 - pt -1;
            currScore2 += a2[pt]; 
            track++;

            if(currScore1 > currScore2 + rem){
                return (min(ans, track)); 
            }

        }else{

            int rem = 5 - pt -1;
            currScore1 += a1[pt];
            track++;

            if(currScore2 > currScore1 + rem){
                return (min(ans, track)); 
            }

            rem = 5 - pt - 1;
            currScore2 += a2[pt]; 
            track++;

            if(currScore2 > currScore1 + rem){
                return (min(ans, track)); 
            }

        }
        pt++;
    }

    return ans;

}


void solve(){
    string a; cin >> a;
    vector<int> a1, a2, a3, a4;
    int one = 0, two = 0;
    lp(0, 10){

        
        if(i%2 == 0){
            int w;
            if(a[i] == '1'){
                w = 1;
            }else if(a[i] == '0'){
                w = 0;
            }else{
                w = 3;
            }
            a1.push_back(w);
            a3.push_back(w);
            if(w == 1){
                one++;
            }
        }else{
            
            int w;
            if(a[i] == '1'){
                w = 1;
            }else if(a[i] == '0'){
                w = 0;
            }else{
                w = 3;
            } 
            a2.push_back(w);
            a4.push_back(w);
            if(w == 1){
                two++;
            }
        }
    }
 

    bool set; 
    if(one >= two){
        set = true;
        lp(0, 5){
            if(a1[i] == 3){
                a1[i] = 1; 
            }
            if(a2[i] == 3){
                a2[i] = 0;
            }
            if(a3[i] == 3){
                a3[i] = 0; 
            }
            if(a4[i] == 3){
                a4[i] = 1;
            }
        }
    }else{
        set = false;
        lp(0, 5){
            if(a2[i] == 3){
                a2[i] = 1;
            }
            if(a1[i] == 3){
                a1[i] = 0;
            }
            if(a3[i] == 3){
                a3[i] = 1; 
            }
            if(a4[i] == 3){
                a4[i] = 0;
            }
        }
    }
    // print(a3);
    // print(a4); 
 
    int currScore1 = 0, currScore2 = 0;

    int track = 0;

    int ans = INT_MAX;
    int pt = 0;

    int ans1 = min(func(!set, currScore1, currScore2, track, pt, ans, a1, a2), func(set, currScore1, currScore2, track, pt, ans, a1, a2));

    int ans2 = min(func(!set, currScore1, currScore2, track, pt, ans, a3, a4), func(set, currScore1, currScore2, track, pt, ans, a3, a4));

    if(ans1 == INT_MAX && ans2 == INT_MAX){
        cout << 10 << endl;
        return;
    }

    cout << min(ans1, ans2) << endl; 
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