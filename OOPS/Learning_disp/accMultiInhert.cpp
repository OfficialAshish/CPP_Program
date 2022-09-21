#include <iostream>
using namespace std;

class Base
{
protected:
    int dataBase;

public:
    Base(int i = 0) : dataBase(i) { cout << "\nConstructor... Base\n"; }
    ~Base() { cout << "\nDestructor... Base\n"; }
    int set(int i)
    {
        dataBase = i;
    }
    void display()
    {
        cout << "\nvalue at base: " << dataBase << endl;
    }
};

class A : virtual public Base
{
protected:
    int dataA;

public:
    A(int i = 1) : dataA(i) { cout << "\nConstructor... A\n"; }
    ~A() { cout << "\nDestructor... A\n"; }
    int set(int i)
    {
        dataA = i;
    }
    void display() // override base
    {
        cout << "\nOverriding base value at A: " << dataA << endl;
    }
};

class B : virtual public Base
{
protected:
    int dataB;

public:
    B(int i = 2) : dataB(i) { cout << "\nConstructor... B\n"; }
    ~B() { cout << "\nDestructor... B\n"; }
    int set(int i)
    {
        dataB = i;
    }

    void disp()
    {
        cout << "\nValue is B:" << dataB;
        cout << "\nValue is Base:" << dataBase << endl;
    }
    /* void display() // override base and clashing class A & B
    {
        cout << "\nOverriding base value at B: " << dataB << endl;
    } */
};

class C : public A, public B
{
protected:
    int dataC;

public:
    C(int i = 5) : dataC(i) { cout << "\nConstructor... derived_C\n"; }
    ~C() { cout << "\nDestructor... derived_C\n"; }
    // using A::display();

    int set(int i)
    {
        dataC = i;
    }
    void disp()
    {
        cout << "\nValue is C:" << dataC;
        cout << "\nValue is A:" << dataA;
        cout << "\nValue is B:" << dataB;
        cout << "\nValue is Base:" << dataBase << endl;
    }
};
// virtual makes it easy to avoid ambiguity and clashes btw dataof only BASE CLASS of A & B

int main(int argc, char const *argv[])
{
    C objC(7);
    objC.disp();
    objC.display();
    objC.Base::display();
    return 0;
}
