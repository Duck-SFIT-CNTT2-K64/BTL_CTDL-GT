#include <iostream>
#ifndef __CAR__
#define __CAR__

using namespace std;

class Car{
    string bienso, hang;
    int namsx;
    double gia;
public:
    //Ham tao
    Car(){
        bienso = "";
        hang = "";
        namsx = 0;
        gia = 0;
    }
    //Nhap thong tin o to
    friend istream& operator>>(istream &is, Car &carOther) {
        cout << "Nhap bien so: ";
        is >> carOther.bienso;
        
        cout << "Nhap hang xe: ";
        is.ignore();
        getline(is, carOther.hang);
        
        cout << "Nhap nam san xuat cua xe: ";
        while (!(is >> carOther.namsx) || carOther.namsx <= 0) {
            cout << "Vui long nhap 1 so nguyen duong cho nam san xuat: ";
            // is >> carOther.namsx;
        }

        cout << "Nhap gia ca cua xe: ";
        while (!(is >> carOther.gia) || carOther.gia < 0) {
            cout << "Vui long nhap 1 so khong am cho gia: ";
            is >> carOther.gia;
        }
        
        return is;
    }
    //Xuat thong tin o to
    friend ostream& operator<<(ostream &os, Car &carOther){
        os << endl;
        os << "Bien so: " << carOther.bienso << endl;
        os << "Hang xe: " << carOther.hang << endl;
        os << "Nam san xuat cua xe: " << carOther.namsx << endl;
        os << "Gia ca cua xe: " << carOther.gia << endl;
        return os;
    }
    //Toan tu so sanh < theo gia ca cua o to
    bool operator<(const Car &carOther) const{
        return this->gia < carOther.gia;
    }
    //Cac thong tin can lay
    string get_bienso() const{
        return this->bienso;
    }
    string get_hang() const{
        return this->hang;
    }
    int get_namsx() const{
        return this->namsx;
    }
    double get_gia() const{
        return this->gia;
    }
};
#endif 