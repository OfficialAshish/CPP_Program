
#if !defined(_stack_tmplt_nop_)
#define _stack_tmplt_nop_

namespace nm_stack_tmplt_nop_
{

    template <class T>
    class stack_nop_
    {
        T data_[100];
        T top_;

    public:
        stack_nop_() : top_(-1) {}
        ~stack_nop_() {}

        void push(const T &item)
        {
            data_[++top_] = item;
        }
        const T &top()
        {
            return data_[top_];
        }
        T pop()
        {
            T tmp = data_[top_];
            top_--;
            return tmp;
        }

        bool empty() const
        {
            return top_ == -1;
        }
    };

} // namespace nm_stack_tmplt_nop_

#endif // _stack_tmplt_nop_
