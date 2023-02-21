#ifndef _FRACTION_V2_IMPL
#define _FRACTION_V2_IMPL
#include "fraction_v2_inf.h"

namespace fraction_nm
{
    // support functions
    int Fraction::gcd(int a, int b)
    {
        while (a != b)
        {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        return a;
    }
    int Fraction::lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
    Fraction &Fraction::operator*() // to reduce fraction
    {
        if (d_ == 0)
            throw "Fraction with Denominator Zero is undefined\n";
        if (d_ < 0)
        {
            n_ = -n_;
            d_ = static_cast<unsigned>(-static_cast<int>(d_));
            return *this;
        }
        if (n_ == 0)
        {
            d_ = 1;
            return *this;
        }
        unsigned int n = (n_ < 0 ? -n_ : n), g = gcd(n, d_);
        n_ /= static_cast<int>(g);
        d_ /= g;
        return *this;
    }
    // Fraction &Reduce() {}

    const Fraction Fraction::UNITY(1); // unity is datatype of type fraction equals 1
    const Fraction Fraction::ZERO(0);
    /* inline Fraction::Fraction(int n = 1, int d = 1) : n_(d < 0 ? -n : n), d_(d < 0 ? -d : d)
    {
        *(*this); // or this.Reduce(); //to reduce fraction
    }
    inline Fraction::Fraction(const Fraction &f) : n_(f.n_), d_(f.d_) {} // copy constr..
    inline Fraction &Fraction::operator=(const Fraction &f)              // assignm
    {
        n_ = f.n_;
        d_ = f.d_;
        return *this;
    }
    inline Fraction::~Fraction() {}
     */
    // operations..
    Fraction Fraction::operator+() const { return *this; }             // preserve
    Fraction Fraction::operator-() const { return Fraction(-n_, d_); } // negate
    Fraction &Fraction::operator++() { return *this += Fraction::UNITY; }
    Fraction &Fraction::operator--() { return *this -= Fraction::UNITY; }
    Fraction Fraction::operator++(int) // returns old frac
    {
        Fraction f = *this;
        ++(*this);
        return f;
    }
    Fraction Fraction::operator--(int)
    {
        Fraction f = *this;
        --(*this);
        return f;
    }

    Fraction Fraction::operator+(const Fraction &f) const // add
    {
        unsigned int d = lcm(d_, f.d_);
        int n = n_ * (d / d_) + f.n_ * (d / f.d_);
        return Fraction(n, d);
    }

    Fraction Fraction::operator-(const Fraction &f) const { return *this + (-f); }                       // substrc
    Fraction Fraction::operator*(const Fraction &f) const { return Fraction(n_ * (f.n_), d_ * (f.d_)); } // multip
    Fraction Fraction::operator/(const Fraction &f) const { return Fraction(n_ * (f.d_), d_ * (f.n_)); } // divide
    Fraction Fraction::operator%(const Fraction &f) const                                                // modulus
    {
        if (f.n_ == 0)
            throw "\nDivide by Zero is undefined! \n";
        Fraction tf = (*this) / f;
        return (*this) - Fraction(tf - Fraction(tf.n_ % tf.d_, d_)) * f;
        // as in ver_1, return (*this) - Fraction(static_cast<int>(tf.n_/tf.d_)) *f;
    }

    // advance assignment Fraction::operator
    Fraction &Fraction::operator+=(const Fraction &f) { return *this = *this + f; }
    Fraction &Fraction::operator-=(const Fraction &f) { return *this = *this - f; }
    Fraction &Fraction::operator*=(const Fraction &f) { return *this = *this * f; }
    Fraction &Fraction::operator/=(const Fraction &f) { return *this = *this / f; }
    Fraction &Fraction::operator%=(const Fraction &f) { return *this = *this % f; }

    // comparision
    bool Fraction::operator<(const Fraction &f) const { return (*this - f).n_ < 0; } // or  *this.n_ < f.n_ && this.d_ < f.d_;
    bool Fraction::operator>(const Fraction &f) const { return (*this).n_ > f.n_ && (*this).d_ > f.d_; }
    bool Fraction::operator<=(const Fraction &f) const { return (*this).n_ <= f.n_ && (*this).d_ <= f.d_; }
    bool Fraction::operator>=(const Fraction &f) const { return (*this).n_ >= f.n_ && (*this).d_ >= f.d_; }
    bool Fraction::operator==(const Fraction &f) const { return (*this).n_ == f.n_ && (*this).d_ == f.d_; }
    bool Fraction::operator!=(const Fraction &f) const { return !(*this == f); }

    // extended operations
    Fraction Fraction::operator!() const // invert
    {
        if (d_ == 0)
            throw "Divide by Zero is undefined! \n";
        return Fraction(d_, n_);
    }
    Fraction::operator double() // double
    {
        return (static_cast<double>(n_) / static_cast<double>(d_));
    }

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
    ostream &operator<<(ostream &os, const Fraction &f)
    {
        os << f.n_;
        if (f.d_ != 1 && f.n_ != 0)
        {
            os << "/" << f.d_ << " ";
        }
        return os; // suppress denomin
    }
    istream &operator>>(istream &is, Fraction &f)
    {
        is >> f.n_ >> f.d_;
        *f; // reduce fract..
        return is;
    }

} // namespace fraction_nm

#endif
