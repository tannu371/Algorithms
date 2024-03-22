#include<iostream>
#include<math.h>        // abs, max
#include<algorithm>     // sort. fill
#include<vector>
#include<set>
#include<map>
#include<utility>       // std::pair
#include<queue>         // bfs
#include<deque>

using namespace std;

#define ll long long
#define INF 999999
#define for1(n1, n2)  for(int i=n1; i<=n2; i++) 
#define for2(n1, n2) for(int j=n1; j<=n2; j++)

void solve() {
    int n, m;
    cin >> n >> m;
    string s;

    vector<int> nz;

    int strlen = 0;
    int k;
    int count;

    for1(0, n - 1) {
        cin >> s;

        k = s.length();
        strlen += k;

        if (s[k - 1] == 0) {
            count = 0;
            k--;
            while (s[k] == '0') {
                count++;
                k--;
            }
            nz.push_back(count);
        }
    }

    sort(nz.begin(), nz.end());

    // Anna could eliminate
    int cnz = 0;
    for (int i = nz.size() - 1; i >= 0; i -= 2) {
        cnz += nz[i];
    }

    strlen -= cnz;

    if (strlen > m) cout << "Sasha" << endl;
    else cout << "Anna" << endl;

}

int main() {
    int t;
    cin >> t;

    while (t--) solve();


}