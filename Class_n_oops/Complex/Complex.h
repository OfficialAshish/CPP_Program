
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double re_ = 0, double im_ = 0) : real(re_), imag(im_)
    {
        cout << "\nInside Constructor.\n";
    }
    Complex(const Complex &sourceObj) : real(sourceObj.real), imag(sourceObj.imag)
    {
        cout << "\nInside C_cons\n";
    }

    ~Complex()
    {
        cout << "\nInside Destructor.\n";
    }

    void setComplex(double re_ = 1.0, double im_ = 1)
    {
        real = re_;
        imag = im_;
    }
    void print()
    {
        cout << "\n Complex NO. : " << real << " + j" << imag << endl;
    }

    int modulus()
    {
        int mod = sqrt(pow(real, 2) + pow(imag, 2));
        return mod;
    }
};
