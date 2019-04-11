//https://github.com/Mer2412/3350VectorNormalizer
//Modified by: Victor Merino
//Modified date: 4/11/2019
//
//Author: Gordon Griesel
//Date: April 7, 2019
//Purpose: Framework for a coding exam
//
//See instructions on assignment web page to produce a unit-test
//for the vec_length function.
//
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

//type defines
typedef double Flt;
typedef Flt Vec[3];

//prototype
Flt vec_length(Vec v);

//Array of vector values
const Flt arr[] = {
   1.0,   0.0,
   1.0,   1.0,
  -1.2,   2.5,
  99.9,  99.9,
   2.2,  -1.2,
   0.0,   0.0
};

#ifdef UTEST
void utest(float tolerance);
extern double testData[];
#endif

int main(int argc, char *argv[])
{
    #ifdef UTEST
    if(argc < 2) {
        cout << "Tolerance value is missing."<< endl;
        return 0;
    } else {
        float toleranceGiven = atof(argv[1]);
        utest(toleranceGiven);
    }
    return 0;
    #endif
    //Program to calculate vector normalization and length.
    //
    printf("                                    \n");
    printf("3350 software engineering           \n");
    printf("                                    \n");
    printf("Calculation of vector lengths:      \n");
    printf("                                    \n");
    printf("     x         y         length     \n");
    printf("     --------  --------  ---------- \n");
    //read until sentinel found.
    int i=0;
    Vec v = { arr[i*2+0], arr[i*2+1] };
    do {
        Flt ret = vec_length(v);
        printf("%3i  %8.5lf  %8.5lf  %10.5lf\n", i+1, v[0], v[1], ret);
        ++i;
        v[0] = arr[i*2+0];
        v[1] = arr[i*2+1];
    } while (!(v[0]==0.0 && v[1]==0.0));
    //
    printf("\nProgram complete.\n\n");
    return 0;
}

Flt vec_length(Vec v)
{
    //Normalize a vector.
    //Return the original length of the vector.
    //
    //input: the 2 components of a vector
    //output: the pre-normalized vector length is returned
    //        the vector argument is scaled to a length of 1.0
    //
    //A degenerate vector causes an error condition.
    //It will return a length of 0.0
    //and an arbitrary vector with length 1.0.
    //
    //calculate the vector dot product with itself...
    Flt dot = v[0]*v[0] + v[1]*v[1];
    //check for degenerate vector...
    if (dot == 0.0) {
        //set an arbitrary vector of length 1.0
        //printf("ERROR vector magnitude is zero.\n");
        v[0] = 1.0;
        v[1] = 0.0;
        return 0.0;
    }
    //vector has a magnitude so continue.
    Flt len = sqrt(dot);
    Flt oolen = 1.0 / len;
    v[0] *= oolen;
    v[1] *= oolen;
    return len;
}

#ifdef UTEST
void utest(float tolerance)
{
    cout << "                                    " << endl;
    cout << "3350 software engineering           " << endl;
    cout << "                                    " << endl;
    cout << "Unit test of vec_length() function: " << endl;
    cout << "tolerance: " << tolerance << endl << endl;
    cout << "     x         y         ";
    cout << "length         actual         " << endl;
    cout << "     --------  --------  ";
    cout << "---------- --------- " << endl;
    //read until sentinel found.
    int i=0;
    int line =1;
    int errorCounter = 0;
    Vec v = { testData[i], testData[i+1] };
    do {
        Flt ret = vec_length(v);
        
        if(abs(ret - testData[i+4]) > tolerance) {
            printf("%3i  %8.5lf  %8.5lf  %10.5lf %10.5lf <-- error\n",
                line++, testData[i], testData[i+1], testData[i+4], ret);
            errorCounter++;
        } else {
            printf("%3i  %8.5lf  %8.5lf  %10.5lf %10.5lf\n",
                line++, testData[i], testData[i+1], testData[i+4], ret);
        }
        i += 5;
        v[0] = testData[i];
        v[1] = testData[i+1];
    } while (!(v[0]==0.0 && v[1]==0.0));
    //
    cout << endl << "Unit test completed." << endl;
    cout << "errors found: " << errorCounter << endl;
}
#endif