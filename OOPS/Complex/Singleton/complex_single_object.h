
#ifndef _complex_singleton_
#define _complex_singleton_

using namespace std;

// for output details
// complex : i , re_
// (inherited above)anotherComplex : t(private), l(public) , _re

namespace complex_singleton
{
    class Complex
    {
    protected:
        double real;
        double imag;

    public:
        Complex(double re_ = 0, double im_ = 0)
            : real(re_), imag(im_)
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

        void setComplex(double re_ = 1.0, double im_ = 1.0)
        {
            real = re_;
            imag = im_;
        }
        void print() const
        {
            cout << "\nPrinting Complex No. (i) :    " << real << " + i" << imag << endl;
        }

        int modulus()
        {
            int mod = sqrt(pow(real, 2) + pow(imag, 2));
            return mod;
        }
        friend ostream &operator<<(ostream &, const Complex);
    };

    class anotherComplex : public Complex
    {
    private:
        char imagVariable; // using extra variable here
        anotherComplex(double _re = 0, double _im = 0, char var = 't')
            : Complex(_re, _im), imagVariable(var)
        {
            cout << "\nInside constructor (t) \n";
            // this->print();
        }
        static anotherComplex *objPointer;
        // private constructor ,testing meyer's singleton

    public:
        static anotherComplex &genObj(double re_ = 0, double im_ = 0, char var = 'd')
        {
            if (!objPointer)
            {
                objPointer = new anotherComplex(re_, im_, var);
            }
            return *objPointer;
        }

    public:
        ~anotherComplex()
        {
            cout << "\nInside Destructor. (l) \n";
            // delete objPointer;//infinite loop, it agains call to ~anotherComplex()
        }

        void print() const
        {
            cout << "\nPrinting Complex No. (l) :    " << real << " + " << imagVariable << imag << endl;
        }
        friend ostream &operator<<(ostream &os, const anotherComplex cx);
    };


    anotherComplex *anotherComplex::objPointer = 0; // defination

    ostream &operator<<(ostream &os, const Complex cx)
    {
        cx.print();
        return os;
    }

    ostream &operator<<(ostream &os, const anotherComplex cx)
    {
        cx.print();
        return os;
    }

}

#endif