#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ==========================================
// BÀI 6
// ==========================================
class SinhVienBai6 {
private:
    string hoTen;
    int namSinh;
    float diem[5]; // Ði?m 5 môn h?c

public:
    void nhap() {
        cin.ignore();
        cout << "  Ho ten: ";
        getline(cin, hoTen);
        cout << "  Nam sinh: ";
        cin >> namSinh;
        cout << "  Nhap diem 5 mon: ";
        for (int i = 0; i < 5; i++) {
            cin >> diem[i];
        }
    }

    float tinhDTB() const {
        float sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += diem[i];
        }
        return sum / 5.0f;
    }

    void xuat() const {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh << " | DTB: " << fixed << setprecision(2) << tinhDTB() << endl;
    }

    // In cac mon phai thi lai (diem < 5)
    void inMonThiLai() const {
        bool coThiLai = false;
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5.0f) {
                if (!coThiLai) {
                    cout << "- Sinh vien: " << hoTen << " (Nam sinh: " << namSinh << ")\n";
                    coThiLai = true;
                }
                cout << "  + Mon " << (i + 1) << ": " << diem[i] << " diem\n";
            }
        }
    }
};

void giaiBai6() {
    int n;
    cout << "=== BÀI 6 ===\n";
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    vector<SinhVienBai6> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "\nNhap sinh vien thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    cout << "\n--- DANH SÁCH MON THI L?I C?A CÁC SINH VIÊN (DI?M < 5) ---\n";
    for (int i = 0; i < n; i++) {
        ds[i].inMonThiLai();
    }
}


// ==========================================
// BÀI 7
// ==========================================
class SinhVienBai7 {
private:
    string hoTen;
    int namSinh;
    float diem[4]; // Ði?m 4 môn h?c

public:
    void nhap() {
        cin.ignore();
        cout << "  Ho ten: ";
        getline(cin, hoTen);
        cout << "  Nam sinh: ";
        cin >> namSinh;
        cout << "  Nhap diem 4 mon: ";
        for (int i = 0; i < 4; i++) {
            cin >> diem[i];
        }
    }

    float tinhDTB() const {
        float sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += diem[i];
        }
        return sum / 4.0f;
    }

    // Tiêu chu?n thi t?t nghi?p: DTB < 7 VÀ không có môn nào du?i 5
    bool duDieuKienThiTotNghiep() const {
        if (tinhDTB() >= 7.0f) return false;
        for (int i = 0; i < 4; i++) {
            if (diem[i] < 5.0f) return false;
        }
        return true;
    }

    void xuat() const {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh << " | DTB: " << fixed << setprecision(2) << tinhDTB() << endl;
    }
};

void giaiBai7() {
    int n;
    cout << "\n=== BÀI 7 ===\n";
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    vector<SinhVienBai7> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "\nNhap sinh vien thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    cout << "\n--- DANH SÁCH SINH VIÊN PH?I THI T?T NGHI?P (DTB < 7 VÀ KHÔNG MÔN NÀO < 5) ---\n";
    bool coSV = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].duDieuKienThiTotNghiep()) {
            ds[i].xuat();
            coSV = true;
        }
    }
    if (!coSV) {
        cout << "Khong co sinh vien nao thoa man dieu kien thi tot nghiep.\n";
    }
}

int main() {
    int luaChon;
    cout << "Chon bai muon chay (6 hoac 7): ";
    cin >> luaChon;

    if (luaChon == 6) giaiBai6();
    else if (luaChon == 7) giaiBai7();
    else cout << "Lua chon khong hop le!";

    return 0;
}
