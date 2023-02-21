#include <iostream>

using namespace std;

class Printer
{
private:
    bool blackAndWhite, bothSided_;

    Printer(bool bw = false, bool bs = false) : blackAndWhite(bw), bothSided_(bs)
    {
        cout << "Printer constructed" << endl;
    } // Private Printer cannot be constructed!

    static Printer *myPrinter_;

    // Pointer to the Instance of the Singleton Printer

public:
    ~Printer() { cout << "Printer destructed" << endl; }//isn't implicit this time

    static const Printer &printer(bool bw = false, bool bs = false)
    { // Access the Printer

        if (!myPrinter_)
            myPrinter_ = new Printer(bw, bs);

        return *myPrinter_;

        // Constructed for first call

        // Reused from next time
    }

    void print(int nP) const { cout << "Printing " << nP << "pages" << endl; }
};

Printer *Printer::myPrinter_ = 0;

int main()
{
    Printer::printer().print(10);
    Printer::printer().print(20);

    delete &Printer::printer();
    return 0;
}