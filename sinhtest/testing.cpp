#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {
    return rd() % (r - l + 1) + l;
}

signed main() {
    
    system("g++ -g dpdigit.cpp -o dpdigit.exe");
    system("g++ -g dpdigit_.cpp -o dpdigit_.exe");

    while (1) {
        int l = Rand(1, 1e6), r = Rand(1, 1e6), k = Rand(1, 10000);
        if (l > r) swap(l, r);

        ofstream out("dpdigit.inp");
        out << l << ' ' << r << ' ' << k;

        //_______________________________
        out.close();

        system("dpdigit.exe");
        system("dpdigit_.exe");

        if (system("fc dpdigit.out dpdigit.ans") != 0) {
            cout << "WA" << endl;
            break;
        }
        else {
            cout << "AC" << endl;
        }
    }
    system("pause");
    return 0;
}