#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include "func.h"
using namespace std;

class item
{
    public:
        string name, desc;
        int ret;
        int y;
        item()
        {
            name = " ";
            desc = " ";
            y = 0;
            ret = 0;
        }
        item(string s1, int a, string s2)
        {
            name = s1;
            desc = s2;
            ret = a;
        }
        void display();
        void disp_selected();
};
void item::display()
{
   cout.width(y + (name.size()));
   cout<<name<<endl;
}

void item::disp_selected()
{
    for(int i=1;i<y;i++)
        cout<<' ';
    cout<<"-)" << name <<endl;

}

class menu
{
    item head;
    vector<item> entries;
    int num;
    public:
    menu()
    {
        num=0;
    };
    void add(string,int,string);
    int display();
    void readfromfile(string);
};


void menu::add(string s, int r = 0, string d = " ")
{
    num++;
    if(r==0)
        r = num;
    entries.push_back(item(s, r, d));
}

int menu::display()
{
    int selected = 0;
    while(true)
    {
        int max_y = getmax_y(), i;
        for(item &a : entries)
        {
            a.y = (max_y - a.name.size())/2;
        }
        int max_x = getmax_x();
        int x = (max_x - num)/2 - 2;
        system("clear");
        for(i =0; i<x; i++)
            cout<<endl;
        head.display();
        for(i=0;i<(int)entries.size();i++)
        {
            if ( i == selected)
                entries[i].disp_selected();
            else
                entries[i].display();
        }
        cout << "\n\n\n\n";
        cout << entries[selected].desc;
        cout<<'\n';
        int opt;
        opt = getch();
        if (opt == 10)
            return entries[selected].ret;
        switch(opt)
        {
            case 66:
                selected++;
                break;
            case 65:
                selected--;
                break;
        }
        if(selected == num)
            selected = 0;
        if(selected == -1)
            selected = num -1;
    }
}

void menumaker()
{
    string objn, input;
    cout<<"Enter name of object to create: ";
    cin>> objn;
    item a;
    vector<item> m_entry;
    int num=0;
    ofstream fentry;
    fentry.open(objn);
    while(true)
    {
        cout<<"Enter menu entry name(NIL for exiting): ";
        cin>> a.name;
        if(a.name=="NIL")
            break;
        fentry<<a.name<<' ';
        num++;
        cout<<"Enter description(NIL to skip): ";
        cin>>a.desc;
        if(a.desc == "NIL")
            a.desc = " ";
        fentry<<a.desc<<' ';
        cout<<"Enter return value(0 for default): ";
        cin>>a.ret;
        if(a.ret == 0)
            a.ret = num;
        fentry<<a.ret<<' '<<endl;
        m_entry.push_back(a);
    }
    fentry.close();
    ofstream outf;
    outf.open("temp");
        {
            outf<<objn;
            outf<<".readfromfile(\"";
            outf<<objn;
            outf<<"\");";
            outf<<"\nwhile(true)\n{\n\tint x=";
            outf<<objn;
            outf<<".display();\n\tswitch(x)\n\t{\n";
            for(int i=0;i<num;i++)
            {
                outf<<"\t\tcase ";
                outf<<m_entry[i].ret;
                outf<<":\t//menu item ";
                outf<<m_entry[i].name;
                outf<<"\n\n\t\t\tbreak;\n";
            }
            outf<<"\t\tdefault:\n\t\tbreak;\n\t}\n}";
        }

    cout<<"Please copy code from file temp and place in the appropriate place\n";
    outf.close();
}


void menu::readfromfile(string s)
{
    item temp;
    ifstream file;
    file.open(s);
    while(file.good())
    {
        file>>temp.name;
        file>>temp.desc;
        file>>temp.ret;
        entries.push_back(temp);
    }
    file.close();
}
