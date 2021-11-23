#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    union{
        float input;
        int output;
    } data;

    float f;
    cin>>f;
    data.input = f;

    bitset<sizeof(float) * CHAR_BIT> bits(data.output);
    cout<<bits<<endl;

    return 0;
}
