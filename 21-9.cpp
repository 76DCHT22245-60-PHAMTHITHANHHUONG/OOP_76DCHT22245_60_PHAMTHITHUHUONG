#include <iostream>
#include <vector>
using namespace std;

class PS1 {
protected:
    int ts;
    int ms;
public:
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> ts;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> ms;
        } while (ms == 0);
    }

    void toigian() {
        int a = abs(ts), b = abs(ms);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        int uc = a;
        ts /= uc;
        ms /= uc;
    }

    void in() {
        toigian();
        if (ms < 0) {
            ts = -ts;
            ms = -ms;
        }
        cout << ts << "/" << ms << endl;
    }

    double value() const {
        return (double)ts / ms;
    }

    friend class PS2;
};

class PS2 : public PS1 {
public:
    PS2& operator=(const PS2& other) {
        if (this != &other) {
            ts = other.ts;
            ms = other.ms;
        }
        return *this;
    }

    bool operator>(const PS2& other) const {
        return ts * other.ms > ms * other.ts;
    }
};

int main() {
    int n;
    cout << "Nhap so phan so n: ";
    cin >> n;
    if (n > 10) n = 10;

    vector<PS2> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "Phan so thu " << i+1 << ":\n";
        ds[i].nhap();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!(ds[i] > ds[j])) {
                swap(ds[i], ds[j]);
            }
        }
    }

    cout << "\nDanh sach phan so sau khi sap xep giam dan:\n";
    for (int i = 0; i < n; i++) {
        ds[i].in();
    }

    return 0;
}
