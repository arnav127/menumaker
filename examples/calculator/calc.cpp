#include <iostream>
#include "../../src/mmaker.h"

using namespace std;

void add(), sub(), mul(), div();

int main()
{
    menu obj;
    int x;
    obj.menu_head("Calculator");
    obj.add("Addition", 1, "Add two numbers");
    obj.add("Subtraction", 2, "Subtract two numbers");
    obj.add("Multiplication", 3);
    obj.add("Division", 4, "Divide");
    obj.add("Exit");
    while(true)
    {
        x=obj.display();
        switch(x)
        {
            case 1:
                add();
                break;
            case 2:
                sub();
                break;
            case 3:
                mul();
                break;
            case 4:
                div();
                break;
            case 5:
                cout << "ThankYOU!!\n";
                exit(0);
            default:
                cout << x << endl;
                break;
        }
        getch();
    }
    return 0;
}

void add()
{
    long int a, b;
    cout <<"Enter numbers to add: ";
    cin >> a >> b;
    cout << a+b<<endl;
    cin.ignore();
    return;
}
void sub()
{
    long int a, b;
    cout <<"Enter numbers to Subtract: ";
    cin >> a >> b;
    cout << a-b<<endl;
    cin.ignore();
    return;
}
void mul()
{
    long int a, b;
    cout <<"Enter numbers to Multiply: ";
    cin >> a >> b;
    cout << a*b<<endl;
    cin.ignore();
    return;
}
void div()
{
    long int a, b;
    cout <<"Enter numbers to Divide: ";
    cin >> a >> b;
    if(b!=0)
        cout << a/b<<endl;
    else
        cout << "Undefined\n";
    cin.ignore();
    return;
}
