#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int A = 0b101101;
    int B = 0b110011;
    int C= A & B;
    cout << C << endl;
    cout << bitset<8>(A + B);
}
