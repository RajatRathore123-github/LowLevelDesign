#include<iostream>
using namespace std;

class Marker {
  public:  
    string name;
    string color;
    int year;
    int price;
};

class Invoice : public Marker{
    private:
      Marker marker;
      int quantity;

    public: 
      int calculateTotal(){
        int price = ((marker.price) * this->quantity);
        return price;
      }  

    public:
      void printInvoice(){

      }   
    public:
      void saveToDB(){
        
      }  
};

// correction

class Marker {
  public:  
    string name;
    string color;
    int year;
    int price;
};

class Invoice : public Marker{
    private:
      Marker marker;
      int quantity;

    public: 
      int calculateTotal(){
        int price = ((marker.price) * this->quantity);
        return price;
      }  
};

class InvoiceDao{
    Invoice invoice;

    public:
      void saveToDB(){

      }
};


class InvoiceDao{
    Invoice invoice;

    public:
      void print(){
        
      }
};

// Open for extension but closed for modification
class InvoiceDao{
    public:
      virtual void save(Invoice invoice) = 0;
};

class DatabaseInvoiceDao : public InvoiceDao{
    public:
      void save(Invoice invoice){
        //save to db
        cout << "saved to db" << " ";
      }
};

class FileInvoiceDao : public InvoiceDao{
    public:
      void save(Invoice invoice){
        cout << "saved to file" << " ";
      }
};

//Liskov Substitution Principle

class Bike {
  public:
    virtual void turnOnEngine() = 0;
    virtual void accelerate() = 0;
};

class MotorCycle : Bike {
  private:
    bool isEngineOn;
    int speed;

  public:
    void turnOnEngine(){
      isEngineOn = true;
    }  

    void acelerate(){
      speed = speed + 10;
    }
};

// interface segmented principle
// interfaces should be such , that client should not implement unnecessary functions they do not need

class RestaurantEmployee {
  public:
    virtual void washDishes() = 0;
    virtual void serveCustomers() = 0;
    virtual void cookFood() = 0;
};

// breaks interface into chunks for proper accessibility

class WaiterInterface{
  public:
    virtual void serveCustomers() = 0;
    virtual void takeOrder() = 0;
};

class ChefInterface{
  public:
    virtual void decideMenu() = 0;
    virtual void cookFood() = 0;
};

class Waiter : WaiterInterface {
  public:
    void washDishes(){

    }
    void serveCustomers(){

    }
};

//class should depend on interfaces rather than concrete classes

class MacBook {
  private:
    WiredKeyboard keyboard;
    WiredMouse mouse;

  public:
    MacBook(){
      keyboard = new WiredKeyBoard;
      mouse = new WiredMouse;
    }  
};

//use constructor injection
// make interfaces of Keyboard , Mouse
class MacBook {
  private:
    Keyboard keyboard;
    Mouse mouse;

  public:
    MacBook(Keyboard keyboard, Mouse mouse){
      this->keyboard = keyboard;
      this->mouse = mouse;
    }  

};
