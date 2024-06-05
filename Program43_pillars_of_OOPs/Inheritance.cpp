//inheritance
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class human {
    public :
    int age ;
    string name ;
    float weight ;

public :
    int getAge(){
        return this ->   age ;
    }

    void setWeight(int w ){
        this -> weight = w ;
    }
};

class male : public human {
    public : 
    void sleep () {
        cout << "person sleeping" << endl;
    }
};

int main(){

    male object1;

    object1.setWeight(56);
    cout << object1.weight << endl;
    cout << object1.age << endl;
    cout << object1.name << endl;

    object1.sleep() ;

}