#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PATH "C:\\Users\\compu zone\\CLionProjects\\balaha\\File.txt"
#define PATH2 "C:\\Users\\compu zone\\CLionProjects\\balaha\\TEST.txt"
int count(fstream&f){
  f.seekg(0,ios::end);
    return f.tellg()/29;
}
char m_name[20];
char ID[9];
void add(fstream &f)
{
cout<<"enter medecine name: ";
cin>>m_name;
cout<<"enter ID for "<<m_name<<" medecine";
cin>>ID;
f.write(m_name,20);
f.write(ID,9);
}
void read(fstream&f)
{
    int n=count(f);
    f.seekg(0,ios::beg);
    while(!f.eof()&&f.tellg()!=n*29)
    {
        char a[20], b[9];
        f.read(a, 20);
        f.read(b, 9);
        cout << a << '\n' << b << '\n';
    }
}
void display_top_5(fstream&f)
{
    int n=count(f);
    n=(n>5?5:n);
    f.seekg(0,ios::beg);
    int c=1;
    while(!f.eof()&&f.tellg()!=n*29)
    {
        char a[20], b[9];
        f.read(a, 20);
        f.read(b, 9);
       cout<<"medecine "<<c<<":"<<a<<"with id "<<ID<<'\n';
       c++;
    }
}
void search(fstream&f,char name[])
{
    char a[20], b[9];
    f.seekg(0,ios::beg);
    while(!f.eof())
    {
        f.read(a, 20);
        f.read(b, 9);
        int resualt=strcmp(a,name);
        if(resualt==0){
            cout<<"the medecine "<<name<<" with id--> "<<b<<'\n';return;
        }
    }
    cout<<"medecine not found \n";
}
int number(fstream&f,char name[])
{
    int c=0;
    char a[20], b[9];
    f.seekg(0,ios::beg);
    while(!f.eof())
    {
        c++;
        f.read(a, 20);
        f.read(b, 9);
        int resualt=strcmp(a,name);
        if(resualt==0){
            return c;
        }
    }
    return -1;
}
void update(fstream&f,char name[])
{
    char n[20],id[9];
    f.seekp(number(f,name)*29,ios::beg);

cout<<"new name";cin>>n;
cout<<"new id ";cin>>id;
f.write(n,20);
f.write(id,9);

}
void update2(fstream& f, char name[]) {
    char n[20], id[9];
    cout << "New name: "; cin >> n;
    cout << "New ID: "; cin >> id;

    int pos = number(f, name);
    if (pos != -1) {
        f.seekp((pos - 1) * 29, ios::beg); // Calculate the position based on record number
        f.write(n, 20);
        f.write(id, 9);
        cout << "Medicine updated successfully\n";
    } else {
        cout << "Medicine not found\n";
    }
}


int main()
{
fstream f;
f.open(PATH2,ios::in|ios::out|ios::app|ios::binary);
char aa[20]="a";
update2(f,aa);

f.close();
}