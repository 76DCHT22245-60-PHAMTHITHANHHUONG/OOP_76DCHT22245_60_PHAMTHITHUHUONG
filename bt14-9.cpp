#include<iostream>
#include<string>
using namespace std;

// ================= CAU 1 =================
// Khai bao lop nguoi (lop cha)
class nguoi{
    protected: // Pham vi protected de lop con (SinhVien) co the ke thua va su dung
        string hoten;
        int nsinh;
        
    public:
        // ================= CAU 2 =================
        // Yeu cau them: tao ham tao khong doi cho lop nguoi
        nguoi()
        { 
            hoten="";
            nsinh=0;
        }
        
        // Ham tao co doi cho lop nguoi
        // Dung con tro this-> de phan biet bien cua lop va tham so truyen vao
        nguoi(string hoten, int nsinh)
        {
            this->hoten = hoten;
            this->nsinh = nsinh;
        }
        
        // Phuong thuc nhap cua lop nguoi (Giong y het code co giao)
        void nhap(){
            cout<<"Nhap hoten: ";getline(cin,hoten);
            cout<<"Nhap nsinh: ";cin>>nsinh;
            cin.ignore(); // Xoa phim Enter bi thua de khong troi lenh duoi
        }
        
        // Phuong thuc xuat cua lop nguoi
        void xuat(){
            cout << "Ho ten: " << hoten << " | Nam sinh: " << nsinh;
        }
};

// ================= CAU 1 =================
// Khai bao lop SinhVien ke thua tu lop nguoi
class SinhVien: public nguoi{
    private:
        string msv;
        float dtb;
        
    public:
        // ================= CAU 2 =================
        // Lop con sinh vien khong duoc ke thua ham tao ma phai goi lai
        // Goi lai ham tao ko doi cua nguoi
        SinhVien ():nguoi(){
        }
        
        // Goi lai ham tao co doi cua nguoi
        SinhVien(string hoten, int nsinh, string msv, float dtb): nguoi(hoten, nsinh){
            this->msv = msv;
            this->dtb = dtb;
        }
        
        // Phuong thuc nhap cua lop SinhVien
        void nhap(){
            nguoi::nhap(); // Goi nhap cua lop nguoi, sinh vien duoc ke thua nguoi
            cout<<"Nhap msv: ";getline(cin,msv);
            cout<<"Nhap dtb: ";cin>>dtb;
        }
        
        // Phuong thuc xuat cua lop SinhVien
        void xuat(){
            nguoi::xuat(); // Goi ham xuat cua lop cha de in ten va nam sinh truoc
            cout << " | Ma SV: " << msv << " | Diem TB: " << dtb << endl;
        }
        
        // Ham phu tro lay diem trung binh de lat nua so sanh sap xep
        float getDtb(){
            return dtb;
        }
};

int main()
{
    // ================= CAU 2 (Chay thu ham tao co doi) =================
    // Tao doi tuong test theo dung mau cua co giao
    SinhVien dinh("Dinh",2000,"mn01",8);
    
    // Ve nha xay dung method xuat va xuat cho ca thong tin tren
    cout << "--- THONG TIN SINH VIEN TEST ---" << endl;
    dinh.xuat(); 
    
    // ================= CAU 3 =================
    // Va lam tiep y2, 3 trong bai tap (Nhap danh sach, sap xep)
    int n;
    SinhVien ds[100]; // Khai bao mang chua toi da 100 sinh vien
    
    cout << "\n--- YEU CAU 3: NHAP DANH SACH SINH VIEN ---" << endl;
    cout << "Nhap so luong sinh vien can quan ly: ";
    cin >> n;
    cin.ignore(); // Xoa phim Enter sau khi nhap so n de khong bi loi getline o mang

    // Vong lap nhap thong tin cho n sinh vien
    for(int i = 0; i < n; i++){
        cout << "\nNhap thong tin sinh vien thu " << i+1 << ":" << endl;
        ds[i].nhap();
        cin.ignore(); // Xoa phim Enter sau khi nhap diem trung binh cua moi sinh vien
    }

    // Thuat toan sap xep noi bot (Bubble Sort) de xep giam dan theo diem trung binh
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(ds[i].getDtb() < ds[j].getDtb()){ // Neu nguoi dung truoc diem nho hon nguoi dung sau
                // Thi hoan vi (doi cho) 2 sinh vien cho nhau
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    // In danh sach sau khi da sap xep ra man hinh
    cout << "\n=== DANH SACH SINH VIEN GIAM DAN THEO DTB ===" << endl;
    for(int i = 0; i < n; i++){
        ds[i].xuat();
    }

    return 0;
}
