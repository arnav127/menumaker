#include <iostream>
#include "mmaker.h"
using namespace std;

void add()
{
    cout<<"Add\n";
}
void sub()
{
    cout<<"Sub\n";
}
int main()
{
    cout<<"\nHello!\n";
    menu s1;
    s1.add("Multiply", 76, "Hellu Multiply");
    s1.add("L", 412);
    s1.add("Addition");
    s1.add("Arnav Dixit 123", 3, "AAAA");
    s1.add("Multiply", 76, "Hellu Multiply");
    s1.add("L", 412);
    s1.add("Addition");
    s1.add("Arnav Dixit 123", 3, "AAAA");
    s1.add("Subtraction");
    s1.add("Subtraction");
    int x=s1.display();
    cout << endl<<endl<<x;
    getch();
    return 0;
}
