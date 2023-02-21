#ifndef _FRACTION_V2_
#define _FRACTION_V2_

namespace fraction_nm
{
    using namespace std;
    class Fraction
    {
    private:
        int n_;
        unsigned int d_;

        // support functions
        static int gcd(int, int);
        static int lcm(int, int);
        Fraction &operator*(); // to reduce fraction
        Fraction &Reduce();

    public:
        static const Fraction UNITY; // unity is datatype of type fraction equals 1
        static const Fraction ZERO;
        explicit Fraction(int n = 1, int d = 1) : n_(d < 0 ? -n : n), d_(d < 0 ? -d : d) {}
        Fraction(const Fraction &f) : n_(f.n_), d_(f.d_) {} // copy constr..
        Fraction &operator=(const Fraction &f)              // assignm
        {
            n_ = f.n_;
            d_ = f.d_;
            return *this;
        }
        ~Fraction() {}

        // operations..
        Fraction operator+() const; // preserve
        Fraction operator-() const; // negate
        Fraction &operator++();
        Fraction &operator--();
        Fraction operator++(int); // returns old frac
        Fraction operator--(int);

        Fraction operator+(const Fraction &) const; // add
        Fraction operator-(const Fraction &) const; // substrc
        Fraction operator*(const Fraction &) const; // multip
        Fraction operator/(const Fraction &) const; // divide
        Fraction operator%(const Fraction &) const; // modulus

        // advance assignment operator
        Fraction &operator+=(const Fraction &);
        Fraction &operator-=(const Fraction &);
        Fraction &operator*=(const Fraction &);
        Fraction &operator/=(const Fraction &);
        Fraction &operator%=(const Fraction &);

        // comparision
        bool operator<(const Fraction &) const;
        bool operator>(const Fraction &) const;
        bool operator<=(const Fraction &) const;
        bool operator>=(const Fraction &) const;
        bool operator==(const Fraction &) const;
        bool operator!=(const Fraction &) const;

        // extended operations
        Fraction operator!() const; // invert
        operator double();          // double

        /*
         Since the constructor of Fraction is explicit, an int cannot be implicitly converted to
         Fraction. So we do not expect an addition operation like i + f where int i; and Fraction.
         Hence, member function operators are okay. Otherwise, we will need friend function
         operators:
         */

        /*
        friend Fraction operator+(const Fraction &, const Fraction &) ; // add
        friend Fraction operator-(const Fraction &, const Fraction &) ; // substrc
        friend Fraction operator*(const Fraction &, const Fraction &) ; // multip
        friend Fraction operator/(const Fraction &, const Fraction &) ; // divide
        friend Fraction operator%(const Fraction &, const Fraction &) ; // modulus
         */
        // in_out
        friend ostream &operator<<(ostream &, const Fraction &);
        friend istream &operator>>(istream &, Fraction &);
    };
    // Fraction Fraction::UNITY(1);
} // namespace fraction_nm

#endif