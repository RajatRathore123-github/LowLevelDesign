#include<iostream>
using namespace std;

class Shape{
    public:
      virtual void draw() = 0;
};

class Rectangle : public Shape{
    public:
      void draw(){
        cout << "rectangle" << endl;
      }
};

class Circle : public Shape{
    public:
      void draw(){
        cout << "circle" << endl;
      }
};

class Square : public Shape{
    public:
      void draw(){
        cout << "square" << endl;
      }
};


class ShapeFactory{
public:
    enum Input { CIRCLE, SQUARE, RECTANGLE };

    Shape *getShape(Input input){
        switch(input){
            case CIRCLE:
               return new Circle();
            case SQUARE:
               return new Square();
            case RECTANGLE:
               return new Rectangle();   
            default:
               return NULL;   
        }
    }
};

int main(){
    ShapeFactory *shapeFactoryObj = new ShapeFactory();
    enum ShapeFactory::Input { CIRCLE, SQUARE, RECTANGLE };
    ShapeFactory::Input s = ShapeFactory::Input::CIRCLE;
    Shape *shapeObj = shapeFactoryObj->getShape(s);
    shapeObj->draw();
}