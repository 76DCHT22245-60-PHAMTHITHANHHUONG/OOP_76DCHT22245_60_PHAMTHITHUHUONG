#include <iostream>
#include <string>
using namespace std;

// ================= CÂU 1 =================

// Khai bao lop Nguoi
class Nguoi
{
protected:
    string hoten;
    int nsinh;

public:
    void nhap();
    void xuat();
};

// Khai bao lop SinhVien ke thua lop Nguoi
class SinhVien : public Nguoi
{
private:
    string masinhvien;
    float diemtrungbinh;

public:
    void nhap();
    void xuat();

    string getmsv();
    string gethoten();
};


// ================= CÂU 2 =================

// Phuong thuc nhap cua lop Nguoi
void Nguoi::nhap()
{
    cout << "Nhap ho ten: ";
    getline(cin, hoten);

    cout << "Nhap nam sinh: ";
    cin >> nsinh;
    cin.ignore();
}

// Phuong thuc xuat cua lop Nguoi
void Nguoi::xuat()
{
    cout << "Ho ten: " << hoten
         << " | Nam sinh: " << nsinh;
}


// Phuong thuc nhap cua lop SinhVien
void SinhVien::nhap()
{
    Nguoi::nhap();

    cout << "Nhap ma sinh vien: ";
    getline(cin, masinhvien);

    cout << "Nhap diem trung binh: ";
    cin >> diemtrungbinh;
    cin.ignore();
}

// Phuong thuc xuat cua lop SinhVien
void SinhVien::xuat()
{
    Nguoi::xuat();

    cout << " | Ma SV: " << masinhvien
         << " | Diem TB: " << diemtrungbinh << endl;
}

// Ham lay ma sinh vien
string SinhVien::getmsv()
{
    return masinhvien;
}

// Ham lay ho ten
string SinhVien::gethoten()
{
    return hoten;
}


// ================= CÂU 3 =================

int main()
{
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    SinhVien ds[100];

    // Nhap danh sach sinh vien
    cout << "\n===== NHAP DANH SACH SINH VIEN =====\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Sinh vien thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }

    // Nhap thong tin tim kiem
    string tuKhoa;

    cout << "\n===== TIM KIEM SINH VIEN =====\n";
    cout << "Nhap ma sinh vien hoac ho ten can tim: ";
    getline(cin, tuKhoa);

    bool timThay = false;

    // Tim kiem theo ma sinh vien hoac ho ten
    for (int i = 0; i < n; i++)
    {
        if (ds[i].getmsv() == tuKhoa ||
            ds[i].gethoten() == tuKhoa)
        {
            cout << "\n===== THONG TIN SINH VIEN TIM THAY =====\n";
            ds[i].xuat();

            timThay = true;
        }
    }

    // Neu khong tim thay
    if (!timThay)
    {
        cout << "\nKhong tim thay sinh vien!\n";
    }

    return 0;
}
