#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> str_to_intarr(string F){
    vector<int> arr;
    for (char i : F) {
        if (i >= 'A') arr.push_back(int(i) - 55);
        else arr.push_back(int(i) - 48);
    }
    return arr;
}

int get_min_base(const vector<int>& F){
    int minBase = 1;
    if (F.size() > 1) {
        for (int i : F) {
            if (i > minBase){
                minBase = i;
            }
        }
    } else if (F[0] == 0) {}
    else {
        minBase = F[0];
    }
    return minBase+1;
}

int to_dec_base(const vector<int>& originalnumber, int base){
    int newnumber = 0;
    int size = originalnumber.size() - 1;
    for (int i : originalnumber){
        newnumber += i*pow(base,size);
        --size;
    }
    return newnumber;
}

void get_equals(const vector<int>& numA, const vector<int>& numB, int baseofA, int baseofB, const string& A, const string& B){
    int baseA = baseofA;
    int baseB = baseofB;
    while(baseA < 37){
        while(baseB < 37){
            if (to_dec_base(numA,baseA) == to_dec_base(numB,baseB)){
                cout << A << " (base " << baseA << ") = " << B << " (base " << baseB << ")" << endl;
                return;
            }
            ++baseB;
        }
        baseB = baseofB;
        ++baseA;
    }
    baseA = baseofA;
    baseB = baseofB;
    while(baseB < 37){
        while(baseA < 37){
            if (to_dec_base(numA,baseA) == to_dec_base(numB,baseB)){
                cout << A << " (base " << baseA << ") = " << B << " (base " << baseB << ")" << endl;
                return;
            }
            ++baseA;
        }
        baseA = baseofA;
        ++baseB;
    }
    cout << A << " is not equal to " << B << " in any base 2..36" << endl;
}


int main() {
    string X, Y;
    while(cin >> X >> Y) {
        auto Xarr = str_to_intarr(X);
        auto Yarr = str_to_intarr(Y);
        int optbaseX = get_min_base(Xarr);
        int optbaseY = get_min_base(Yarr);
        get_equals(Xarr, Yarr, optbaseX, optbaseY, X, Y);

    }
    return 0;
}
