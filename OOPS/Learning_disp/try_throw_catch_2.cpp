#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception
{
public:
    void test()
    {
        cout << "\ntest exception\n";
    }
};
class MyClass
{
public:
    // ~MyClass() { cout << "\nDestructor class\n"; }
};

void h()
{
    MyClass h_a;
    cout << "\nIn h\n";
    // throw 2;
    // throw MyException();
    // throw exception();
    // throw MyClass();
    throw 5.7;
}

void g()
{
    MyClass g_a;
    try
    {
        cout << "\nIn g \n";
        h();
        cout << "\ncalled h()\n";
    }
    catch (int)
    {
        cout << "\ncatched int \n";
    }
    catch (...)
    {
        throw; // rethrow
    }
}

void f()
{
    MyClass f_a;
    cout << "\nIn f \n";
    try
    {
        g();
        cout << "\ncalled g()... no throw so excuted\n";
    }
    catch (MyException)
    {
        cout << "\nCatched Myexception \n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        throw;
    }
}

int main(int argc, char const *argv[])
{
    int a;

    try
    {
        f();
        cout << "\ncalled f() throug main \n";
    }
    catch (MyClass)
    {
        cout << "\nCatched MyClass\n";
    }
    catch (...)
    {
        cout << "\nUnknown...\n";
    }

    return 0;
}
