#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define rng ios::sync_with_stdio(false); cin.tie(nullptr);
typedef pair<int64_t, int64_t> PLL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}
template<class T> bool cmin(T &a, const T &b) {
    if(b < a) {
       a = b;
       return 1;
    }
    return 0;
}
void mxc(intmax_t &a, intmax_t b) {
    a = min(a, b);
}
void mxh(intmax_t &a, intmax_t b) {
    a = max(a, b);        
}

constexpr int64_t mod = 1e9 + 7;
const int mx = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int64_t gcd(int64_t a, int64_t b) {
    return b ? gcd(b, a%b) : a;
}

int64_t lcm(int64_t a,int64_t b) {
    return a / gcd(a, b) * b;
}

//O(N^2)
vector<int> perm(vector<int> items, int k) {
    vector<int> rest;
    int rem = 0;
    if((int) items.size() % 2 == 0) {
       rem = items[(items.size()/2)-1];
    }
    if((int) items.size() % 2 != 0) {
       rem = items[items.size()/2];
    }
    if(k == 1 || (int) items.size() == 0) {
      return items;
    }
    int jx = 0, jy = 0, px = 0;
    while((int) rest.size() < (int) items.size() - 1) {
       ++jx, ++jy;
       if(jx == k) {
          jx = 0;
       }
       if(items[jy] == -1) {
          px = jx - 1;
          jx = px;
       }
       if(jy > (int) items.size() - 1) {
          jy = 0;
       }
       if((jx + 1) % k == 0 && items[jy] != -1) {
          rest.pb(items[jy]);
          items[jy] = -1;
       }
    }
    rest.pb(rem);
    return rest;
}

void sol(vector<int> items, int k) {
    rng
    vector<int> permut = perm(items, k); 
    for(const auto &c : permut)
       cout << c <<'\n';
    return;
}

int main() {
    int k;
    read(k);
    int n;
    read(n);
    vector<int> items(n);
    for(int i = 0; i < n; ++i) 
       read(items[i]);
    sol(items, k);
    return 0;
}
