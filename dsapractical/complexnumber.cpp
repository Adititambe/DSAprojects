#include<iostream>
using namespace std;
class complex{
private:
    float real;
    float imag;
public:
    complex(){
        real=0;
        imag=0;
    }
    complex(float r,float i){
        real=r;
        imag=i;
    }
    ~complex(){

    }
    void display(){
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
    complex operator+(complex c){
        return complex(real+c.real,imag+c.imag);
    }
    complex operator-(complex c){
        return complex(real-c.real,imag-c.imag);
    }
    complex operator*(complex c){
        float r=real*c.real-imag*c.imag;
        float i=real*c.real+imag*c.real;
        return complex(r,i);

    }


};
int main(){
    complex c1(4,5),c2(2,3);
    cout<<"first complex number:";
    c1.display();
    cout<<"second complex number:";
    c2.display();
    complex sum=c1+c2;
    cout<<"sum";
    sum.display();

    complex diff=c1-c2;
    cout<<"differance";
    diff.display();

    complex prod=c1*c2;
    cout<<"product";
    prod.display();
    return 0;
    
}

/*output
PS D:\aditi252> g++ complexnumber.cpp -o complexnumber
PS D:\aditi252> ./complexnumber
first complex number:4+5i
second complex number:2+3i
sum6+8i
differance2+2i
product-7+18i
*/