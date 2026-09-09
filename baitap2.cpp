#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tuSo;
    int mauSo;

public:
    // ==============================
    // CÂU 1
    // ==============================

    // Hàm t?o không d?i
    PhanSo()
    {
        tuSo = 0;
        mauSo = 1;
    }

    // Hàm t?o có d?i
    PhanSo(int tu, int mau)
    {
        tuSo = tu;
        mauSo = mau;
    }

    // Hàm h?y
    ~PhanSo()
    {
    }

    // ==============================
    // CÂU 2
    // ==============================

    // N?p ch?ng toán t? nh?p >>
    friend istream& operator >> (istream& is, PhanSo& ps)
    {
        cout << "Nhap tu so: ";
        is >> ps.tuSo;

        do
        {
            cout << "Nhap mau so (khac 0): ";
            is >> ps.mauSo;
        }
        while (ps.mauSo == 0);

        return is;
    }

    // N?p ch?ng toán t? xu?t <<
    friend ostream& operator << (ostream& os, const PhanSo& ps)
    {
        if (ps.mauSo == 1)
            os << ps.tuSo;
        else
            os << ps.tuSo << "/" << ps.mauSo;

        return os;
    }

    // Rút g?n phân s?
    void rutGon()
    {
        int a = tuSo;
        int b = mauSo;

        if (a < 0)
            a = -a;

        if (b < 0)
            b = -b;

        // Tìm UCLN
        while (b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }

        // Chia t? và m?u cho UCLN
        tuSo = tuSo / a;
        mauSo = mauSo / a;

        // Ðua d?u âm lên t?
        if (mauSo < 0)
        {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

    // ==============================
    // CÂU 3
    // ==============================

    // Toán t? c?ng +
    PhanSo operator + (const PhanSo& ps)
    {
        PhanSo kq;

        kq.tuSo = tuSo * ps.mauSo
                + ps.tuSo * mauSo;

        kq.mauSo = mauSo * ps.mauSo;

        kq.rutGon();

        return kq;
    }

    // Toán t? tr? -
    PhanSo operator - (const PhanSo& ps)
    {
        PhanSo kq;

        kq.tuSo = tuSo * ps.mauSo
                - ps.tuSo * mauSo;

        kq.mauSo = mauSo * ps.mauSo;

        kq.rutGon();

        return kq;
    }

    // Toán t? nhân *
    PhanSo operator * (const PhanSo& ps)
    {
        PhanSo kq;

        kq.tuSo = tuSo * ps.tuSo;
        kq.mauSo = mauSo * ps.mauSo;

        kq.rutGon();

        return kq;
    }

    // Toán t? chia /
    PhanSo operator / (const PhanSo& ps)
    {
        PhanSo kq;

        kq.tuSo = tuSo * ps.mauSo;
        kq.mauSo = mauSo * ps.tuSo;

        kq.rutGon();

        return kq;
    }
};

int main()
{
    // ==============================
    // CÂU 3
    // ==============================

    PhanSo ps1, ps2;

    cout << "=== NHAP PHAN SO THU NHAT ===" << endl;
    cin >> ps1;

    cout << "\n=== NHAP PHAN SO THU HAI ===" << endl;
    cin >> ps2;

    // Rút g?n 2 phân s?
    ps1.rutGon();
    ps2.rutGon();

    cout << "\nPhan so thu nhat: " << ps1;
    cout << "\nPhan so thu hai: " << ps2;

    // C?ng
    PhanSo tong = ps1 + ps2;
    cout << "\n\nTong: " << tong;

    // Tr?
    PhanSo hieu = ps1 - ps2;
    cout << "\nHieu: " << hieu;

    // Nhân
    PhanSo tich = ps1 * ps2;
    cout << "\nTich: " << tich;

    // Chia
    PhanSo thuong = ps1 / ps2;
    cout << "\nThuong: " << thuong;

    cout << endl;

    return 0;
}
