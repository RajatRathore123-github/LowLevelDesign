#include<iostream>
using namespace std;


class BasePizza{
    public:
      virtual int cost() = 0;
};

class FarmHouse : public BasePizza{
    public:
      int cost(){
        return 200;
      }
};

class VegDelight : public BasePizza{
    public:
      int cost(){
        return 120;
      }
};

class Margherita : public BasePizza{
    public:
      int cost(){
        return 100;
      }
};

// decorator design pattern having "has a" and "is a" both relationship to base class

class ToppingDecorator : public BasePizza{

};

class ExtraCheese : public ToppingDecorator{
    BasePizza *basePizza;

    public:
      ExtraCheese(BasePizza *pizza){
        this->basePizza = pizza;
      }

    public:
      int cost(){
        return this->basePizza->cost() + 10;
      }  
};

class Mushroom : public ToppingDecorator{
    BasePizza *basePizza;

    public:
      Mushroom(BasePizza *pizza){
        this->basePizza = pizza;
      }

    public:
      int cost(){
        return this->basePizza->cost() + 15;
      }  
};

int main(){

}