#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Câu 1: Khai báo lop môn hoc
class MonHoc {
protected:
    string tenMon; //
    float CC, KT, DT; //[cite: 1]
};

// Câu 1: Khai báo lop sinh viên ke thua tu lop môn hoc[cite: 1]
class SinhVien : public MonHoc {
private:
    string hoTen, lop, maSV; //[cite: 1]

public:
    // Câu 2: Phuong thuc nhap thông tin sinh viên[cite: 1]
    void nhap() {
        cout << "Nhap ho ten SV: "; cin.ignore(); getline(cin, hoTen);
        cout << "Nhap lop: "; getline(cin, lop);
        cout << "Nhap ma SV: "; cin >> maSV;
        cout << "Nhap ten mon hoc: "; cin.ignore(); getline(cin, tenMon);
        cout << "Nhap diem CC, KT, DT: "; cin >> CC >> KT >> DT;
    }

    // Câu 2: Phuong thuc tính diem hoc phan[cite: 1]
    float tinhDiemHP() {
        return CC * 0.1 + KT * 0.3 + DT * 0.6;
    }

    // Câu 2: Phuong thuc xuat thông tin sinh viên[cite: 1]
    void xuat() {
        cout << "\nMa SV: " << maSV << " | Ho ten: " << hoTen << " | Lop: " << lop;
        cout << " | Mon: " << tenMon << " | CC: " << CC << " | KT: " << KT << " | DT: " << DT;
        cout << " | Diem HP: " << tinhDiemHP();
    }

    // Kiem tra sinh viên có bi cam thi không[cite: 1]
    bool biCamThi() {
        return (CC < 5 || KT == 0); //[cite: 1]
    }
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien n: ";
    cin >> n;

    vector<SinhVien> ds(n);

    // Câu 3: Nhap vào n sinh viên[cite: 1]
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap sinh vien thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }

    // Câu 3: In danh sách sinh viên bi cam thi[cite: 1]
    cout << "\n\n=== DANH SÁCH SINH VIÊN Bi CaM THI ===";
    bool coCamThi = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].biCamThi()) {
            ds[i].xuat();
            coCamThi = true;
        }
    }

    if (!coCamThi) {
        cout << "\nKhong co sinh vien nao bi cam thi.";
    }

    return 0;
}
