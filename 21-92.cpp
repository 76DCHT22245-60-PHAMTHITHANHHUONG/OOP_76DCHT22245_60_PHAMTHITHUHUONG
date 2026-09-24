#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class SP1 {
protected:
    float sothuc, soao;
public:
    SP1(float a=0, float b=0) {
        sothuc = a;
        soao = b;
    }
    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> sothuc;
        cout << "Nhap phan ao: ";
        cin >> soao;
    }
    void xuat() {
        cout << sothuc;
        if (soao >= 0) cout << "+";
        cout << soao << "i" << endl;
    }
    double module() const {
        return sqrt(sothuc * sothuc + soao * soao);
    }
};

class SP2 : public SP1 {
public:
    SP2(float a=0, float b=0) : SP1(a,b) {}
    SP2& operator=(const SP2 &p) {
        sothuc = p.sothuc;
        soao   = p.soao;
        return *this;
    }
    friend bool operator>(const SP2 &x, const SP2 &p) {
        return x.module() > p.module();
    }
};

int main() {
    int n;
    cout << "Nhap so luong so phuc (toi da 10): ";
    cin >> n;
    if (n > 10) n = 10;

    vector<SP2> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap so phuc thu " << i+1 << ":\n";
        ds[i].nhap();
    }

    sort(ds.begin(), ds.end(), [](const SP2 &a, const SP2 &b) {
        return a.module() > b.module();
    });

    cout << "\nDanh sach sau khi sap xep giam dan theo module:\n";
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
        cout << "Module = " << ds[i].module() << endl;
    }

    return 0;
}
