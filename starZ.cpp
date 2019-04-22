// starZ.cpp 2019.04.21 Jiayi Xu create a numer of strings shows a pattern of Z
//the frist row and last row have length equal to width of stars
//the stars between the two rows shows as "/"
//all the left are blank spaces
//A demonstration of ASCII Art printing Z characters
// Compile using the command: g++ --std=c++11 starZ.cpp -o starZ
//include part at the start of program
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
//we first call the functions
void assertEquals(string expected, string actual, string message);
string starZ(int width);
void runTests(void);
// function prototypes
string stringOfNChars(int n, char c);
string stringOfKSpacesNStars(int k, int n);
string backslash(int width);
// Write starZ per specifictions at 
// https://foo.cs.ucsb.edu/16wiki/index.php/F14:Labs:lab04
// and so that internal tests pass, and submit.cs system tests pass


string starZ(int width){
    string result = "";
    // check if parameters are vaild
    if ((width <=2)){
        return result;}  // return without printing anything
    //first print the first row of stars
    for (int col=1; col<=width;col++){
        result += "*";
    }
    result += "\n";//return a new line
    //use the function defined below, we can see that the width in the function should be
    //the width of starZ-2 because we need to minus the first row and last row
    result += backslash(width-2);
    //then print the final line of stars
    for (int col=1; col<=width;col++){
        result += "*";
    }
    result += "\n";
    return result;
}

// Test-Driven Development; check expected results against actual

void runTests(void){

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they 
  // automatically get concatenated into a single string literal

  string starZ3Expected = 
    "***\n"
    " * \n"
    "***\n";
  
  assertEquals(starZ3Expected,starZ(3),"starZ(3)");

  string starZ4Expected = 
    "****\n"
    "  * \n"
    " *  \n"
    "****\n";
  
  assertEquals(starZ4Expected,starZ(4),"starZ(4)");

  assertEquals("",starZ(0),"starZ(0)");
  assertEquals("",starZ(2),"starZ(2)");
}

// Test harness

void assertEquals(string expected, string actual, string message=""){
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl << "   Expected:[\n" << expected << "] actual = [\n" << actual << "]\n" << endl;
  }
}


// Main function

int main(int argc, char *argv[]){

    //the comment is already been done so I do not need to write comments for it
    // TODO: Add check for parameters
    // and code to print usage message
    if (argc!=2) {
        cerr << "Usage: " << argv[0] << " width" << endl;
        exit(1);
    }
    
    int width = stoi(argv[1]);
    // TODO: Add code to get width from command line args
    // code that checks if it is -1; if so, call runTests()
    // then exit.
    if (width==-1) {
        runTests();
        exit(0);
    }
    
    // TODO: Add code that calls the starT function and prints
    // the result on cout (without an extra newline)
    cout << starZ(width);
    return 0;
}

string backslash(int width){
    
    int i;
    int height = width; // width is equal to height
    
    string result="";
    
    // so this for loop iterates over the rows
    //I changed the part here in order to make the stars in a reverse direction
    //all the others remain the same
    //also I put some space after the star to make them pass the test
    //the number of space after the stars should be the reverse of the space before the stars
    for (i=height; i>=1;i--) {
        // i spaces then a single star
        int space=height+1-i;
        //but we need to add the whtie space after the star
        //the number of white space after star can be represented by the height+1-i
        //and I put type in front of it to make it work
        result += stringOfKSpacesNStars(i,1)+ stringOfNChars(space, ' ')+ "\n";
        //last but not least, turn into a new line
    }
    return result; // leave this out, and bad things happen
}

//below I just copied from backslash.cpp
//these two parts are the same for backslash and forwardslash
string stringOfNChars(int n, char c){
    int i;
    string result="";
    // print a line of *
    for (i=0; i<n; i++)
        result += c;
    return result;
}

string stringOfKSpacesNStars(int k, int n)
{
    return stringOfNChars(k,' ') + stringOfNChars(n,'*');
}

