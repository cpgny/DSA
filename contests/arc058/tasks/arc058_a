#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define gcc ios::sync_with_stdio(false); cin.tie(nullptr);

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

const int mx = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int64_t gcd(int64_t a, int64_t b) {
    return b ? gcd(b, a%b) : a;
}

int64_t lcm(int64_t a,int64_t b) {
    return a / gcd(a, b) * b;
}
   
void sol() {
   gcc
   int n, k; cin >> n >> k;
   vector<char> dx((int) to_string(n).length());
   for(int i = 0; i < (int) to_string(n).length(); ++i) {
       dx[i] = to_string(n)[i];
   }
   vector<int> preprocess;
   int qx = 0;
   string jx;
   for(int i = 0; i < 10; ++i) {
      preprocess.pb(i);
   }
   vector<int> query;
   for(int i = 0; i < k; ++i) {
      cin >> qx, query.pb(qx);
      preprocess.erase(find(preprocess.begin(), preprocess.end(), qx));
   }
   vector<char> compress = dx;
   for(int i = 0; i < (int) dx.size(); ++i) {
       for(int j = 0; j < (int) query.size(); ++j) {
           //cerr << dx[i] << '\n';
           if(dx[i]-'0' == query[j]) {
               //cerr << "i: " << i << " j: " << j <<'\n'; 
               //cerr << "occurence: " << dx[i]-'0' << '\n';
               for(int k = 0; k < (int) preprocess.size(); ++k) {
                   //cerr << preprocess[k] << '\n';
                   if(preprocess[k] > dx[i]-'0') {
                       //cerr << "debug: " << dx[i] << '\n';
                       dx[i] = '0' + preprocess[k];
                       break;
                   }
               }
           }
       }
   }
   for(int i = 0; i < (int) dx.size(); ++i) {
       if(compress[i] != dx[i]) {
           for(int j = i + 1; j < (int) dx.size(); ++j) {
              dx[j] = '0' + preprocess[0];
              break;
           }
       }
   }
   for(const auto &c : preprocess) {
       cout << "iteration: " << c <<'\n';
   }
   for(const auto &c : dx) {
      jx += c;
   }
   cout << atoi(jx.c_str());
   return;
}
   	
int main() {
   sol();
   return 0;
}
