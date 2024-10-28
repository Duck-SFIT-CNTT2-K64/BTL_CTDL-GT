#include <bits/stdc++.h>
#include "./classCarList.cpp"
#include "./classCar.cpp"
#ifndef __APP__
#define __APP__

using namespace std;

class App{
    carList cars;
public:
    void menu(){
        int choice;
        do{
            cout << " --- Menu --- \n";
            cout << "1. Them o to vao danh sach" << endl;
            cout << "2. Xoa o to theo bien so" << endl;
            cout << "3. Tim o to co gia tien cao nhat" << endl;
            cout << "4. Tim o to co gia tien thap nhat" << endl;
            cout << "5. Sap xep danh sach o to theo gia tien" << endl;
            cout << "6. In danh sach o to" << endl;
            cout << "0. Thoat" << endl;
            cout << "Nhap lua chon cua ban: ";
            cin >> choice;
            while(choice < 0 || choice > 6){
                cout << "Lua chon khong hop le! Nhap lai: ";
                cin >> choice;
            }
            switch(choice){
                case 1:{
                    Car car;
                    cin >> car;
                    cars.addCar(car);
                    cout << "\nThem o to thanh cong!.\n";
                    break;
                }
                case 2:{
                    string bienso;
                    cout << "Nhap bien so cua o to can xoa: ";
                    cin >> bienso;
                    if(cars.testPlate(bienso)){
                        cars.removeCarByPlate(bienso);
                        cout << "\nXoa o to thanh cong!.\n";
                    }
                    else{
                        cout << "Khong tim thay o to co bien so nay!.\n";
                    }
                    break;
                }
                case 3:{
                    if(!cars.empty()){
                        Car maxCar = cars.findMaxPriceCar();
                        cout << "O to co gia tien cao nhat la: " << maxCar;
                    }
                    else{
                        cout << "\nDanh sach o to trong!.\n";
                    }
                    break;
                }
                case 4:{
                    if(!cars.empty()){
                        Car minCar = cars.findMinPriceCar();
                        cout << "O to co gia tien thap nhat la: " << minCar;
                    }
                    else{
                        cout << "\nDanh sach o to trong!.\n";
                    }
                    break;
                }
                case 5:{
                    cars.sortCarsByPrice();
                    cout << "Danh sach o to sau khi sap xep theo gia tien: ";
                    cars.printCars();
                    break;
                }
                case 6:{
                    if(!cars.empty()){
                        cout << "Danh sach o to: ";
                        cars.printCars();
                    }
                    else{
                        cout << "\nDanh sach o to trong!.\n";
                    }
                    break;
                }
                case 0:{
                    cout << "Ket thuc chuong trinh!";
                    break;
                }
                default:{
                    cout << "Lua chon khong hop le!";
                    break;
                }
            }
            cout << endl;
        }while(choice != 0);
    }
};
#endif