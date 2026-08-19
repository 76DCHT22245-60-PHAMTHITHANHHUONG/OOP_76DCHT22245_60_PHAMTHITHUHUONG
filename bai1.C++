#include<iostream>
using namespace std;
#include<string>
struct nhanvien{
    string MANV;
    string TENNV;
    double luongcoban;
    double heso ;
};
typedef nhanvien nv ;
void nhapvao(nv*x){
    cout<<"nhap vao ma nhan vien:";
    cin>>x->MANV;
    cin.ignore();
    cout<<"nnhap vao ho va ten:";
    
    getline(cin,x->TENNV);
    cout<<"nhap vao luong co ban:";
    cin>>x->luongcoban;
    cout<<"nhap vao heso:";
    cin>>x->heso;
}

void inra(nv*x){
    cout<<"ma sinh vien la:"<<x->MANV<<"\n";
    cout<<"hovaten:"<<x->TENNV<<"\n";
    cout<<"LUONG CO BAN:"<<x->luongcoban<<"\n";
    cout<<"HE SO:"<<x->heso<<"\n";
    
}
int main (){
    int n;
    cout<<"nhap so nhan vien:";
    cin>>n;
    nv dsnv[n];
    for(int i =0 ;i<n;i++){
       nhapvao(&dsnv[i]);
    }
    for(int i=0;i<n;i++){
        inra(&dsnv[i]);
    }
}