#include <bits/stdc++.h>
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
    // Ham tao voi day du tham so
    Car(string bienso, string hang, int namsx, double gia){
        this->bienso = bienso;
        this->hang = hang;
        this->namsx = namsx;
        this->gia = gia;
    }
    //Nhap thong tin o to
    friend istream& operator>>(istream &is, Car &carOther) {
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
            // is >> carOther.gia;
        }
        
        return is;
    }
    //Xuat thong tin o to
    friend ostream& operator<<(ostream &os, Car &carOther) {
        os << endl;
        os << "+--------------------+------------------------+" << endl;
        os << "|      Thuoc tinh    |        Gia Tri         |" << endl;
        os << "+--------------------+------------------------+" << endl;
        os << "| Bien so            | " << setw(20) << carOther.bienso <<"   |" << endl;
        os << "| Hang xe            | " << setw(20) << carOther.hang << "   |" << endl;
        os << "| Nam san xuat       | " << setw(20) << carOther.namsx << "   |" << endl;
        os << "| Gia ca             | " << setw(20) << carOther.gia << "   |" << endl;
        os << "+--------------------+------------------------+" << endl;
        return os;
    }
    //Toan tu so sanh < theo gia ca cua o to
    bool operator<(const Car &carOther) const{
        return this->gia < carOther.gia;
    }
    //Cai dat thong tin
    void set_bienso(string bienso){
        this->bienso = bienso;
    }
    void set_hang(string hang){
        this->hang = hang;
    }
    void set_namsx(int namsx){
        this->namsx = namsx;
    }
    void set_gia(double gia){
        this->gia = gia;
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