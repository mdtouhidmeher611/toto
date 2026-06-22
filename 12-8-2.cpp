#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool is_possible = true;
        for (int i = 0; i < k; i++) {
            int count = 0;

            for (int j = i; j < n; j += k) {
                if (s[j] == '1') {
                    count++;
                }
            }
            if (count % 2 != 0) {
                is_possible = false;
                break;
            }
        }
        if (is_possible) 
            cout << "YES\n";
        else 
        cout << "NO\n";
    }
    return 0;
}