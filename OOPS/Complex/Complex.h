#ifndef _complex_
#define _complex_

// for output details
// complex : i , re_
// (inherited above)anotherComplex : t(private), l(public) , _re

namespace complex_1
{
    using namespace std;

    class Complex
    {
    protected:
        double real;
        double imag;

    public:
        Complex(double re_ = 0, double _im = 0)
            : real(re_), imag(_im)
        {
            cout << "\nInside Constructor.(i)\n";
        }
        // copy contr. ,fucn call by value,
        Complex(const Complex &sourceObj) : real(sourceObj.real), imag(sourceObj.imag)
        {
            cout << "\nInside Copy_Constructor.(i)\n";
        }

        ~Complex()
        {
            cout << "\nInside Destructor.(i)\n";
        }

        void setComplex(double re_ = 1.0, double _im = 1)
        {
            real = re_;
            imag = _im;
        }
        void print() const
        {
            cout << "\nPrinting Complex No. (i) :    " << real << " + i" << imag << endl;
        }

        float modulus()
        {
            float mod = sqrt((real * real) + (imag * imag));
            return mod;
        }
        friend bool operator>(const Complex &c1, const Complex &c2) { return (c1.modulus() > c2.modulus()); }
        friend friend ostream &operator<<(ostream &, const Complex cx);
    };

    ostream &operator<<(ostream &os, const Complex cx)
    {
        cx.print();
        return os;
    }

    class anotherComplex : public Complex
    {
    private:
        char imagVariable; // using extra variable here

    public:
        // overload ambiguous if using default arg some
        anotherComplex(double _re, double _im)
            : Complex(_re, _im), imagVariable('d')
        {
            cout << "\nInside constructor (d) overload-1 \n";
            cout << "\nInitialize Complex No. (d) : " << real << " + " << imagVariable << imag << endl;
        }

        anotherComplex(double _re, double _im, char var)
            : Complex(_re, _im), imagVariable(var)
        {
            cout << "\nInside constructor (l->i) overload-2  \n";
            cout << "\nInitialized Complex No. (l) : " << real << " + " << imagVariable << imag << endl;
        }

        ~anotherComplex()
        {
            cout << "\n Inside Destructor. (l) \n";
        }

        void print() const
        {
            cout << "\nPrinting Complex No. (l) :    " << real << " +" << imagVariable << imag << endl;
        }
        friend ostream &operator<<(ostream &os, const anotherComplex cx);
    };

    ostream &operator<<(ostream &os, const anotherComplex cx)
    {
        cx.print();
        return os;
    }
}

#endif