 //Tutorial 13 :- 1d arrays and 2d arrays
#include <iostream>
#include <algorithm> // for sorting
#include <string>
using namespace std;
int main()
{
    string str = "adityadev";
    cout<<str<<endl;

    string name ;
    cin>>name;
    cout<<name<<endl;

    string n1(5,'a');
    cout<<n1<<endl;

    cout << "enter a sentence;\n";
    string str1;
    getline(cin, str1);
    cout << str1 << endl;

    string s1 = "fam", s2 = "ily";
    // s1.append(s2);
    cout << s1 + s2 << endl;
    cout << s1[1] << endl;

    string str2  = "wfvbwfwufwefg fbw";
    str2.clear();
    cout<<str2; 

    string str3 = "abc";
    string str4 = "abc";
    if(str4.compare(str3));
    cout<<"strings are equal   ";
    cout<<str4.compare(str3)<<endl;

    string str5 = "aditya";
    cout<<str5<<endl;
    str5.clear();
    if(str5.empty())
    cout<<"strings are empty";

    string s = "tonystarkironman";

    s.erase(4,5); //(4th index se lekar 5 words erase kr do)
    cout<<s<<endl;

    cout<<s.find("tony")<<endl; //1st letter ka index return krta  h;

    s.insert(4,"stark"); //(4th index pr stark insert kr do)
    cout<<s<<endl;

    cout<<s.size()<<endl; //cout<<s.length()<<endl;

    for(int i=0; i<s.length(); i++){  //(kisi ith index ka letter print kro)
        cout<<s[i]<<endl; 
    }

    string s1x = s.substr(4,5); //(4th index se lekar 5 words print kr do)
    cout<<s1x<<endl;


    string ss = "786";
    int x = stoi(ss);
    cout<<x+2<<endl; 

    string sxs = s.substr(s.length()-3);//last se 3 digit ka substring bna lega
    cout<<sxs<<endl;

    int y = 786;
    cout<<to_string(y) + "2"<<endl;

    string sss = "wfhiwerheig";
    sort(sss.begin(), sss.end());
    cout<<sss<<endl;


//count length of string without using lib function;
cout<<endl;
    string sx;
    int count =0;
    cout<<"enter s\n";
    getline(cin,sx);
    for ( int i = 0; sx[i] != '\0'; i++)
    {
        count ++;
    }
    cout<<count;

   return 0;
}

