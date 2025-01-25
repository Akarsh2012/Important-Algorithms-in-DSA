/*
1. Upcasting:
  i. Upcasting is when a derived class object is assigned to a base class pointer or reference.
  ii. This is safe and requires no explicit casting because the derived class is a specialized version of the base class.
  iii. However, only the base class methods and properties (accessible via the base class interface) are visible, unless you use virtual functions for polymorphism.


2. Downcasting:
  i. Downcasting is when a base class pointer or reference is explicitly converted back to a derived class pointer or reference.
  ii. This requires an explicit cast and is unsafe if the object is not actually of the derived class type.
  iii. To ensure safety, you can use dynamic_cast (at runtime) or static_cast (at compile time, with no checks).

*/

/*

 1. Encapsulation:
   - Definition: Wrapping of data (variables) and methods (functions) into a single unit (class) and restricting direct access.
   - Advantage: Ensures controlled access, improves code security, and allows for easy maintenance.

2. Inheritance:
   - Definition: Allows a class (derived) to acquire properties and methods of another class (base).
   - Advantage: Promotes code reuse and establishes a relationship between classes.

3. Polymorphism:
   - Definition: Ability to process objects differently based on their data type or class.
   - Types:
     i. Compile-time (Static): Achieved through function overloading or operator overloading.
     ii. Runtime (Dynamic): Achieved through virtual functions and method overriding.
   - Advantage: Enables flexibility and maintainability by allowing the same interface to have different implementations.

4. Abstraction:
   - Definition: Hiding internal implementation details and exposing only essential features.
   - Implementation: Achieved using abstract classes (pure virtual functions) and interfaces.
   - Advantage: Simplifies code, reduces complexity, and increases modularity.

5. Difference between Abstraction and Encapsulation:
   i. Abstraction focuses on **hiding implementation details** and showing only the functionality.
   ii. Encapsulation focuses on **bundling data and methods** and restricting access.
   iii. Abstraction is implemented using abstract classes/interfaces, while encapsulation uses access specifiers.

6. Diamond Problem in C++:
   - Definition: Arises when a derived class inherits from two classes that have a common base class, leading to ambiguity.
   - Solution: Use virtual inheritance to ensure only one copy of the base class is inherited.
7.Final Keyword
- Definition: Used to prevent a method from being overridden in a derived class.
- Usage: Applied to methods in a class to ensure they cannot be overridden.
- When the final keyword is applied to a class, it prevents other classes from inheriting from it.
- Example:
          
          class A final { // This class cannot be inherited
                public:
                    void display() {
                        std::cout << "This is a final class." << std::endl;
                    }
            };

8.Friend Functions
- Friend functions are functions that are allowed to access the private and protected members of a class, even though they are   not members of that class.
- They are useful when you need to grant access to certain external functions without exposing internal class details.        
- Example:

            class Box {
                    private:
                        int length;
                    public:
                        Box() : length(10) {}
                        friend void printLength(Box); // printLength can access private members
            };

            void printLength(Box b) {
                cout << "Length: " << b.length << endl;
            } 

9.What is a Static Member?
- A static member (either a data member or a member function) is a class member that belongs to the class itself rather than to any specific instance (object) of the class.

     - Static data members are shared by all objects of the class, meaning all objects have access to the same data.
     - Static member functions can be called without creating an instance of the class.
- Key Points:
     - Shared by all objects: All objects of the class use the same memory for the static members.
     - Accessed without creating an object: You can access static members even if you don't create an instance of the class.               

*/

#include <bits/stdc++.h>
using namespace std;

class Vehicle
{ // abstract class vehicle helps to implement abstraction ... abstract classes are those which cannot be instanciated

protected:
    string name;  // Encapsulation: Properties (name and model) are kept private/protected to restrict direct access.
    string model; // Encapsulation allows controlled access using functions.

public:
    Vehicle(string name, string model)
    {
        this->name = name;
        this->model = model;
    }

    virtual void start() = 0; // Abstraction: Defines a pure virtual function to be implemented by derived classes.

    virtual void stop() = 0; // Abstraction: Abstract classes provide a blueprint without exposing implementation details.
};

class Car : public Vehicle
{

public:
    Car(string name, string model) : Vehicle(name, model) {} // Inheritance: Car inherits properties and behaviors from Vehicle.

    void start() override // Polymorphism: Overriding base class methods to define specific behavior for Car.
    {
        cout << "Car-> " << this->name << " Model " << this->model << " Engine is Starting" << endl;
    }

    void stop() override // Polymorphism: Runtime polymorphism achieved through virtual functions.
    {
        cout << "Car-> " << this->name << " Model " << this->model << " Engine is stopping" << endl;
    }
};
class Bike : public Vehicle
{

public:
    Bike(string name, string model) : Vehicle(name, model) {} // Inheritance: Bike inherits Vehicle's properties and behaviors.

    void start() override // Polymorphism: Bike provides its own implementation for start.
    {
        cout << "Bike-> " << this->name << " Model " << this->model << " Engine is Starting" << endl;
    }

    void stop() override // Polymorphism: Bike provides its own implementation for stop.
    {
        cout << "Bike-> " << this->name << " Model " << this->model << " Engine is stopping" << endl;
    }
};
class Airways : public Vehicle
{

public:
    Airways(string name, string model) : Vehicle(name, model) {}

    void start() override // Polymorphism: Specific behavior for Airways is defined here.
    {
        cout << "Aeroplane-> " << this->name << " Model " << this->model << " Engine is Taking Off" << endl;
    }

    void stop() override // Polymorphism: Specific behavior for Airways is defined here.
    {
        cout << "Aeroplane-> " << this->name << " Model " << this->model << " Engine is Landing" << endl;
    }
};
int main()
{

    Vehicle *v1 = new Car("Alto", "800");            // Upcasting: A derived class object is assigned to a base class pointer.
    Vehicle *v2 = new Bike("Hero Honda", "Deluxe");  // Upcasting: Enables polymorphic behavior via base class pointers.
    Vehicle *v3 = new Airways("AirIndia", "Mx-140"); // Upcasting: Common interface to handle multiple derived classes.
    v1->start();
    v2->start();
    v3->start();
    v1->stop();
    v2->stop();
    v3->stop();

    Vehicle *v = new Car("Mercedes", "r455");
    Car *c = dynamic_cast<Car *>(v); // Downcasting: Explicitly converting a base class pointer to a derived class pointer.
    if (c)
    {
        c->start(); // If downcasting succeeds, specific behavior of the Car can be accessed.
        c->stop();
    }
    else
    {
        cout << "Downcasting failed" << endl;
    }

    return 0;
}

