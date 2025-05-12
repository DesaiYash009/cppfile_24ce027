
#include<iostream>
using namespace std;

class rectangularplot
{
private:
    int length, width;

public:
    void perimeter();
    void area();
    void getdata();
    void display();
    void changeindimension();
};

void rectangularplot::getdata()
{
    cout << "\n\nEnter the length: ";
    cin >> length;
    cout << "\nEnter the width: ";
    cin >> width;
}

void rectangularplot::display()
{
    cout << "\nLength:" << length;
    cout << "\nWidth:" << width;
}

void rectangularplot::perimeter()
{
    int p;
    p = 2 * length + 2 * width;
    cout << "\nThe perimeter is: " << p;
}

void rectangularplot::area()
{
    int a;
    a = length * width;
    cout << "\nThe area is: " << a;
}

void rectangularplot::changeindimension()
{
    int answer, l, w;
    cout << "\nDo you want to change the dimensions? (Yes = 1, No = 0): ";
    cin >> answer;

    if(answer == 1)
    {
        cout << "\nEnter the new length and width: ";
        cin >> l >> w;
        length = l;
        width = w;
    }
    else
    {
        cout << "\nDimensions remain unchanged.";
    }
}

int main()
{
    rectangularplot r1, r2;

    r1.getdata();
    r1.changeindimension();
    r1.perimeter();
    r1.area();

    r2.getdata();
    r2.changeindimension();
    r2.perimeter();
    r2.area();

    cout << "\n\nDetails of the first plot: " << endl;
    r1.display();

    cout << "\n\nDetails of the second plot: " << endl;
    r2.display();

    cout<<"\n\24ce9027_Yash Desai\n";

    return 0;


}







