#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tuSo;
    int mauSo;

public:
    // Câu 1: Hàm tao không doi
    PhanSo()
    {
        tuSo = 0;
        mauSo = 1;
    }

    // Câu 1: Hàm tao có doi
    PhanSo(int tu, int mau)
    {
        tuSo = tu;
        mauSo = mau;
    }

    // Câu 1: Hàm huy
    ~PhanSo()
    {
    }

    // Câu 2: Nhap phân so
    void nhap()
    {
        cout << "Nhap tu so: ";
        cin >> tuSo;

        do
        {
            cout << "Nhap mau so (khac 0): ";
            cin >> mauSo;
        }
        while (mauSo == 0);
    }

    // Câu 2: Xuat phân so
    void xuat()
    {
        if (mauSo == 1)
            cout << tuSo;
        else
            cout << tuSo << "/" << mauSo;
    }

    // Câu 2: Rút gon phân so
    void rutGon()
    {
        int a = tuSo;
        int b = mauSo;

        // Ðua ve so duong de tìm UCLN
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

        // Chia ca tu và mau cho UCLN
        tuSo = tuSo / a;
        mauSo = mauSo / a;

        // Neu mau âm thì doi dau ca tu và mau
        if (mauSo < 0)
        {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

    // Câu 2: Cong hai phân so
    PhanSo cong(PhanSo ps)
    {
        PhanSo kq;

        kq.tuSo = tuSo * ps.mauSo + ps.tuSo * mauSo;
        kq.mauSo = mauSo * ps.mauSo;

        kq.rutGon();

        return kq;
    }

    // Câu 2: Tru hai phân so
    PhanSo tru(PhanSo ps)
    {
        PhanSo kq;

        kq.tuSo = tuSo * ps.mauSo - ps.tuSo * mauSo;
        kq.mauSo = mauSo * ps.mauSo;

        kq.rutGon();

        return kq;
    }

    // Câu 2: Nhân hai phân so
    PhanSo nhan(PhanSo ps)
    {
        PhanSo kq;

        kq.tuSo = tuSo * ps.tuSo;
        kq.mauSo = mauSo * ps.mauSo;

        kq.rutGon();

        return kq;
    }

    // Câu 2: Chia hai phân so
    PhanSo chia(PhanSo ps)
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
    // Câu 3: Nhap hai phân so
    PhanSo ps1, ps2;

    cout << "=== NHAP PHAN SO THU NHAT ===" << endl;
    ps1.nhap();

    cout << "\n=== NHAP PHAN SO THU HAI ===" << endl;
    ps2.nhap();

    // Rút gon hai phân so
    ps1.rutGon();
    ps2.rutGon();

    cout << "\nPhan so thu nhat: ";
    ps1.xuat();

    cout << "\nPhan so thu hai: ";
    ps2.xuat();

    // Cong
    PhanSo tong = ps1.cong(ps2);
    cout << "\n\nTong: ";
    tong.xuat();

    // Tru
    PhanSo hieu = ps1.tru(ps2);
    cout << "\nHieu: ";
    hieu.xuat();

    // Nhân
    PhanSo tich = ps1.nhan(ps2);
    cout << "\nTich: ";
    tich.xuat();

    // Chia
    PhanSo thuong = ps1.chia(ps2);
    cout << "\nThuong: ";
    thuong.xuat();

    cout << endl;

    return 0;
}
