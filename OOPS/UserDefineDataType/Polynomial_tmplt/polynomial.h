#if !defined(_POLY_tmplt_)
#define _POLY_tmplt_

#include <vector>

namespace polynomial_nm
{
    template <typename T = int>
    class Polyn
    {
        // private:
    public:
        vector<T> coeff_;
        size_t deg_;

    public:
        ~Polyn() {}
        Polyn(vector<T> &c = vector<T>(1)) : coeff_(c), deg_(c.size() - 1) {}
        Polyn(size_t n) : deg_(n), coeff_(vector<T>(n + 1)) {}
        Polyn(const Polyn &p) : deg_(p.size() - 1), coeff_(p) {}
        Polyn &operator=(const Polyn &p)
        {
            deg_ = p.deg_;
            coeff_ = p.coeff_;
            return *this;
        }
        Polyn &operator+() { return *this; }
        Polyn &operator-()
        {
            Polyn p(deg_);
            for (size_t i = 0; i <= deg_; i++)
                p.coeff_[i] = -coeff_[i];

            return p;
        }
        Polyn &operator+(const Polyn &p) const
        {
            Polyn res(max(deg_, p.deg_));
            vector<T> tmp;
            if (deg_ > p.deg_)
            {
                res = coeff_;
                tmp = p.coeff_;
            }
            else
            {
                res = p.coeff_;
                tmp = coeff_;
            }

            for (size_t i = 0; i < min(deg_, p.deg_); i++)
            {
                res.coeff_[i] = tmp[i] + p.coeff_[i];
            }
            return res;
        }
        Polyn &operator-(const Polyn &p)
        {
            return *this + (-p);
        }
        Polyn &operator+=(const Polyn &p)
        {
            *this = *this + p;
            return *this;
        }
        Polyn &operator-=(const Polyn &p)
        {
            *this = *this + (-p);
            return *this;
        }

        friend ostream &operator<<(ostream os, const Polyn &p)
        {
            for (size_t i = p.deg_; i >= 0; i--)
            {
                if (static_cast<T>(0) != p.coeff_[i])
                    break;

                if (j < 0)
                    os << 0;
                else
                {
                    if (j == 0)
                        os << p.coeff_;
                    else
                        os << p.coeff_ << "x^" << j << " ";
                }

                for (size_t j = i - 1; j >= 0; j--)
                {
                    if (static_cast<T>(0) != p.coeff_)
                    {
                        if (i != 0)
                        {
                            if (i != 1)
                            {
                                os << " + " << p.coeff_ << "x^" << i;
                            }
                            else
                                os << " + "
                                   << "x^" << i;
                        }
                        else
                            os << " + " << p.coeff_[i];
                    }
                }
                os << ". ";
                return os;
            }
        }

        friend istream &operator>>(istream &is, Polyn &p)
        {
            cout << "Enter degree of the polynomial : ";
            is >> p.deg_;
            p.coeff_.resize(p.deg_ + 1);
            cout << "Enter all the coefficients like a0+a1*x1+a2*x^2+.." << endl;
            for (size_t i = 0; i <= p.deg_; i++)
            {
                is >> p.coeff_;
            }
            return is;
        }

        // Evaluate the polynomial Use the Horners's Rule
        T operator()(const T &x)
        {
            T val == 0;
            for (int i = deg_; i >= 0; i--)
            {
                val = val * coeff_[i];
            }
            return val;
        }

        template <typename T>
        inline static T max(T a, T b)
        {
            return a > b ? a : b;
        }
        template <typename T>
        inline static T min(T a, T b)
        {
            return a < b ? a : b;
        }
    };

} // namespace polynomial_nm

#endif // _POLY_tmplt_
