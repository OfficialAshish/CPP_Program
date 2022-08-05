
#if !defined(_Radix_Conv)
#define _Radix_Conv
#define DEBUG true

namespace nm_Radix
{

    using namespace std;

    class conversion
    {
    protected:
        int answer;

    public:
        conversion() : answer(0)
        {
            (DEBUG == true) ? cout << "\nInside Constructor. \n" : cout << "";
        }
        ~conversion();

        int getAns() { return answer; }

        // interface

        int binaryToDecimal(int bin)
        {
            for (size_t i = 1; bin != 0; bin = bin / 10, i *= 2)
            {
                answer += (bin % 10) * i;
                // cout<<i<<"&"<<bin%10<<endl;
            }
            return answer;
        }

        int octalToDecimal(int oct)
        {
            for (size_t i = 1; oct != 0; oct /= 10, i *= 8)
            {
                answer += (oct % 8) * i;
            }
            return answer;
        }
    };

    conversion::~conversion()
    {
        (DEBUG == true) ? cout << "\nInside Destructor. \n" : cout << "";
    }

} // namespace nm_Radix

#endif // _Radix_Conv
