#if !defined(_swap_)
#define _swap_

template <class T>
void swap_(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

#endif // _swap_
