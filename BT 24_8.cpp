
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Thu vien ho tro dinh dang in theo cot

using namespace std;

// Tao LOP Nhan Vien thay vi struct
class NhanVien {
private:
    string ten;
    int tuoi;

public:
    // 1. Constructor khong doi (Mac dinh)
    NhanVien() {
        ten = "Chua cap nhat";
        tuoi = 0;
    }

    // 2. Constructor co doi
    NhanVien(string t, int tu) {
        ten = t;
        tuoi = tu;
    }

    // Cac ham Getter de lay du lieu in ra man hinh
    string getTen() const {
        return ten;
    }

    int getTuoi() const {
        return tuoi;
    }
};

int main() {
    int n;

    cout << "Nhap so luong nhan vien (n): ";
    cin >> n;

    // Su dung CACH 3 (Vector)
    vector<NhanVien> ds;

    // Nhap du lieu
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu "
             << i + 1 << " ---" << endl;

        string tempTen;
        int tempTuoi;

        // Nhap vao cac bien tam
        cout << "Nhap ten: ";
        cin.ignore(); // Xoa bo nho dem
        getline(cin, tempTen);

        cout << "Nhap tuoi: ";
        cin >> tempTuoi;

        // 3. Su dung Constructor CO DOI de khoi tao va dua vao mang
        NhanVien nv(tempTen, tempTuoi);
        ds.push_back(nv);
    }

    // 4. Xuat du lieu nhan vien THEO COT
    cout << "\n\n================ DANH SACH NHAN VIEN ================" << endl;

    // In tieu de cot (Su dung setw de can le, left de can trai)
    cout << left << setw(10) << "STT"
         << left << setw(25) << "Ho va Ten"
         << left << setw(10) << "Tuoi" << endl;

    // In duong ke ngang
    cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;

    // In du lieu tung nhan vien
    for (int i = 0; i < ds.size(); i++) {
        cout << left << setw(10) << i + 1
             << left << setw(25) << ds[i].getTen()
             << left << setw(10) << ds[i].getTuoi() << endl;
    }

    return 0;
}
```

