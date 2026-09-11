#include <iostream>
#include <cmath>

using namespace std;

class SoPhuc
{
private:
    double thuc;
    double ao;

public:
    // Ham tao khong doi
    SoPhuc()
    {
        thuc = 0;
        ao = 0;
    }

    // Ham tao co doi
    SoPhuc(double thuc, double ao)
    {
        this->thuc = thuc;
        this->ao = ao;
    }

    // Ham huy
    ~SoPhuc()
    {
    }

    // Toan tu nhap >>
    friend istream& operator>>(istream& is, SoPhuc& sp)
    {
        cout << "Nhap phan thuc: ";
        is >> sp.thuc;

        cout << "Nhap phan ao: ";
        is >> sp.ao;

        return is;
    }

    // Toan tu xuat <<
    friend ostream& operator<<(ostream& os, const SoPhuc& sp)
    {
        if (sp.ao >= 0)
        {
            os << sp.thuc << "+" << sp.ao << "i";
        }
        else
        {
            os << sp.thuc << sp.ao << "i";
        }

        return os;
    }

    // Toan tu +
    SoPhuc operator+(const SoPhuc& sp)
    {
        return SoPhuc(
            this->thuc + sp.thuc,
            this->ao + sp.ao
        );
    }

    // Toan tu -
    SoPhuc operator-(const SoPhuc& sp)
    {
        return SoPhuc(
            this->thuc - sp.thuc,
            this->ao - sp.ao
        );
    }

    // Toan tu *
    SoPhuc operator*(const SoPhuc& sp)
    {
        double thucMoi =
            this->thuc * sp.thuc
            - this->ao * sp.ao;

        double aoMoi =
            this->thuc * sp.ao
            + this->ao * sp.thuc;

        return SoPhuc(thucMoi, aoMoi);
    }

    // Toan tu /
    SoPhuc operator/(const SoPhuc& sp)
    {
        double mau =
            sp.thuc * sp.thuc
            + sp.ao * sp.ao;

        double thucMoi =
            (this->thuc * sp.thuc
            + this->ao * sp.ao) / mau;

        double aoMoi =
            (this->ao * sp.thuc
            - this->thuc * sp.ao) / mau;

        return SoPhuc(thucMoi, aoMoi);
    }
};

int main()
{
    SoPhuc a, b;

    // Nhap so phuc a
    cout << "Nhap so phuc a:" << endl;
    cin >> a;

    // Nhap so phuc b
    cout << "\nNhap so phuc b:" << endl;
    cin >> b;

    // Xuat 2 so phuc
    cout << "\nSo phuc a: " << a << endl;
    cout << "So phuc b: " << b << endl;

    // Cong
    cout << "\nTong: " << a + b << endl;

    // Tru
    cout << "Hieu: " << a - b << endl;

    // Nhan
    cout << "Tich: " << a * b << endl;

    // Chia
    cout << "Thuong: " << a / b << endl;

    return 0;
}
