#include <iostream>
using namespace std;
//===============================================================  2 задание =====================================
class Ex
{
public:
    double x;
    Ex(const double& x_) :x(x_) 
    {

    }

    ~Ex() 
    {

    }
};

class Bar
{
private:
    double y;

public:
    Bar() 
    { 
        y = 0; 
    }
    ~Bar()
    {

    }
    void set(const double& a)
    {
        if (y + a <= 100)
        {
            y = a;

        }
        else throw Ex(y * a);
    }

};
// =============================================================== 3 задание =====================================================
class Robot
{
private:
    int x = 1;
    int y = 1;
public:
    Robot() 
    {

    }

    ~Robot() 
    {

    }
    void move(char command)
    {
        switch (command)
        {
        case 'u':
            if (y >= 2)
            {
                --y;
            }
            else throw "y < 0.";
            break;
        case 'd':
            if (y <= 9)
            {
                ++y;
            }
            else throw "y > 10.";
            break;
        case 'r':
            if (x <= 9)
            {
                ++x;
            }
            else throw "x > 10";
            break;
        case 'l':
            if (x >= 2)
            {
                --x;
            }
            else throw "x < 0";
            break;
        default:
            throw 100;
            break;
        }

    };

    int getX() 
    { 
        return x; 
    };
    int getY() 
    { 
        return y; 
    };
};


int main()
//================================================================================ 1 задание ================================================
{
    int first;
    int second;
    std::cout << "Enter the first integer number:" << std::endl;
    std::cin >> first;
    std::cout << "Enter the second integer number:" << std::endl;
    std::cin >> second;

    try
    {
        if (second == 0)
            throw "DivisionByZero";
        div_t divresult;
        divresult = div(first, second);
        std::cout << first << " / " << second << ".  Quotient is " << divresult.quot << ", remainder is " << divresult.rem << "." << std::endl;
    }
    catch (const char* exception)
    {
        std::cerr << "Error: " << exception << std::endl;
    }

//==============================================================================================================================================================

    Bar b;
    int x{};
    while (std::cin >> x && x != 0) {

        try
        {
            b.set(x);
        }
        catch (Ex& err)
        {
            std::cerr << "Exception: ay " << err.x << std::endl;
        }
    }

    

    Robot R2D2;
    char command{};

    while (1)
    {
        std::cout << "R2D2 is located on the cell with the coordinates x = " << R2D2.getX() << ", y = " << R2D2.getY() << "." << std::endl;
        std::cout << "Enter the command (q - quit, u - up, d - down, r - right, l - left): " << std::endl;
        std::cin >> command;
        if (command == 'q') break;

        try
        {
            R2D2.move(command);
        }
        catch (const char* n)
        {
            std::cerr << "Exeption OffTheField: " << n << "." << std::endl;

        }
        catch (int)
        {
            if (100)
                std::cerr << "Exeption IllegalCommand." << std::endl;
        }

    };

    return 0;
}
