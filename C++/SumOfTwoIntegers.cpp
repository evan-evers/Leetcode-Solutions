//Original problem: https://leetcode.com/problems/sum-of-two-integers/

#include <iostream>
#include <string>
using namespace std;

int getSum(int a, int b) {
    //both integers are assumed to be in two's compliment form
    //algorythm loops through each binary digit in a and b and adds them arithmetic-style with a carry
    int i = 0, carry = 0, temp = 0; //i is for iterating, carry stores the carry digit, temp is returned at end of function
    while (i < sizeof(a)*8) //while within the bounds of the integer (in bits)
    {
        if (a & 1)  //if the current binary digit of a is 1
        {
            if (b & 1)   //if the current binary digit of b is 1
            {
                if (carry == 1) //a = 1, b = 1, c = 1
                {
                    temp |= (1 << i);
                    carry = 1;
                }
                else    //a = 1, b = 1, c = 0
                {
                    //no change in this digit of temp
                    carry = 1;
                }
            }
            else
            {
                if (carry == 1) //a = 1, b = 0, c = 1
                {
                    //no change in this digit of temp
                    carry = 1;
                }
                else    //a = 1, b = 0, c = 0
                {
                    temp |= (1 << i);
                    carry = 0;
                }
            }
        }
        else
        {
            if (b & 1)
            {
                if (carry == 1) //a = 0, b = 1, c = 1
                {
                    //no change in this digit of temp
                    carry = 1;
                }
                else    //a = 0, b = 1, c = 0
                {
                    temp |= (1 << i);
                    carry = 0;
                }
            }
            else
            {
                if (carry == 1) //a = 0, b = 0, c = 1
                {
                    temp |= (1 << i);
                    carry = 0;
                }
                else    //a = 0, b = 0, c = 0
                {
                    //no change in this digit of temp
                    carry = 0;
                }
            }
        }

        //right shift both variables to get to the next bit
        a = a >> 1;
        b = b >> 1;
        i++;
    }

    return temp;
}
