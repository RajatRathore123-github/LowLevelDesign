#include<iostream>
using namespace std;


// creating strategy patterns

class DriveStrategy {
    public:
      virtual void drive() = 0;
};

class NormalDriveStrategy : public DriveStrategy {
    public:
      void drive(){
        cout << "normal drive strategy" << " ";
      }
};

class SportsDriveStrategy : public DriveStrategy {
    public:
      void drive(){
        cout << "sports drive strategy" << " ";
      }
};

class Vehicle {
    DriveStrategy* obj = nullptr;
    public:
      Vehicle(DriveStrategy* service) : obj(service){
        if(obj == nullptr){
            throw invalid_argument("service must not be null");
        }
      }

};

