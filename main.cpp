#include <iostream>
#include <bitset>

using namespace std;

void printBinary(int number, int i) {
    unsigned guard = 1;

    for(int k=i-1; k>=0; --k) {
        /*if((number & guard) == 0) {
            //s1 = '0' + s1;
            cout<<"0";
        } else {
            //s1 = '1' + s1;
            cout<<"1";
        }
        guard = (guard << 1);*/
        if((number >> k) & guard){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
}

typedef union {
    float f;
    struct {
        unsigned mantissa : 23;
        unsigned exponent : 8;
        unsigned sign : 1;
    } raw;
} myfloat;

void printIEEE(myfloat var) {
    cout<<"sign:"<<var.raw.sign<<endl;
    cout<<"exponent:";
    printBinary(var.raw.exponent, 8);
    cout<<endl;
    cout<<"mantissa:";
    printBinary(var.raw.mantissa, 23);
    cout<<endl;
}

int main() {

    // initialize union
    myfloat var;

    float num;
    cout<<"number = ";
    cin>>num;

    var.f = num;
    printIEEE(var);

    //string sign = (num >= 0 ? "0" : "1");

    //float x = (num >= 0 ? num : -1*num);

    /*char* bits = reinterpret_cast<char*>(&x);
    for(int i=0;i<sizeof(x);++i){
        cout<<bitset<4>(bits[i]);
    }
    cout<<endl;*/

    /*unsigned guard = 1;
    string s1;
    for(int i=0;i<sizeof(int)*8;++i){
        if(((int)x & guard) == 0){
            s1 = '0' + s1;
        }else{
            s1 = '1' + s1;
        }
        guard = (guard << 1);
    }*/

    return 0;
}
