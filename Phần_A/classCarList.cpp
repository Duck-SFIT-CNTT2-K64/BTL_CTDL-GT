#include <bits/stdc++.h>
#include "./classCar.cpp"
#ifndef __CARLIST__
#define __CARLIST__

using namespace std;

class carList{
    list<Car> cars;
public:
    // Them o to vao danh sach
    void addCar(const Car &carOther){
        cars.push_back(carOther);
    }
    // Kiem tra danh sach o to co rong hay khong
    bool empty() const{
        return cars.empty();
    }
    // Kiem tra xem bien so co hop le hay khong, neu co thi xoa o to do
    bool testPlate(const string &bienso){
        for(auto it = cars.begin(); it != cars.end(); it++){
            if(it->get_bienso() == bienso){
                return true;
            }
        }
        return false;
    }
    void removeCarByPlate(const string &bienso){
        for(auto it = cars.begin(); it != cars.end(); it++){
            if(it->get_bienso() == bienso){
                cars.erase(it);
                break;
            }
        }
    }
    // Tim o to co gia tien cao nhat
    Car findMaxPriceCar() const{
        Car maxCar = cars.front();
        for(auto it = cars.begin(); it != cars.end(); it++){
            if(it->get_gia() > maxCar.get_gia()){
                maxCar = *it;
            }
        }
        return maxCar;
    }
    // Tim o to co gia tien thap nhat
    Car findMinPriceCar() const{
        Car minCar = cars.front();
        for(auto it = cars.begin(); it != cars.end(); it++){
            if(it->get_gia() < minCar.get_gia()){
                minCar = *it;
            }
        }
        return minCar;
    }
    // Sap xep danh sach o to theo gia tien
    void sortCarsByPrice(){
        cars.sort();
    }
    // In danh sach o to
    void printCars() const{
        for(auto car : cars){
            cout << car;
        }
    }
};
#endif