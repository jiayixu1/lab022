// starT.cpp 2019.04.21 Jiayi Xu create a numer of strings shows a pattern of T
//the first row has length equal to width of stars
//the middle column has one star
//the left part are all blank spaces
//A demonstration of ASCII Art printing T characters
// Compile using the command: g++ --std=c++11 starT.cpp -o starT
//include part at the start of program
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starT(int width, int height);
void runTests(void);

// Write starT per specifictions in the lab writeup
// so that internal tests pass, and submit.cs system tests pass

string starT(int width, int height)
{
  string result="";
    // check if parameters are vaild
    if ((width<2) || (height < 2)||(width%2==0)){
        return result;}  // return without printing anything
    // first print the first row of stars
    for (int col=1; col<=width;col++){
        result += "*";
    }
    result += "\n";
    //then print the middle line of star with height
    //first draw the white space
    //then only draw the star for the middle column
    //then finally draw the space for the lest part then go into a new line
    for (int row=2; row<=height;row++){
        for (int col=1;col<=(width-1)/2;col++){
            result += " ";}
        for (int col=(width-1)/2+1;col<=(width-1)/2+1;col++){
            result += "*";}
        for (int col=(width-1)/2+2; col<=width;col++){
            result += " ";
        }
        //trun into a new line to draw stars
        result += "\n";
        }
  return result;
}

// Test-Driven Development; check expected results against actual

void runTests(void) {

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they 
  // automatically get concatenated into a single string literal

  string starT34Expected = 
    "***\n"
    " * \n"
    " * \n"
    " * \n" ;
  
  assertEquals(starT34Expected,starT(3,4),"starT(3,4)");

  string starT53Expected =     
    "*****\n"
    "  *  \n"
    "  *  \n" ;
  
  assertEquals(starT53Expected,starT(5,3),"starT(5,3)");

  string starT72Expected =     
    "*******\n"
    "   *   \n";
  
  assertEquals(starT72Expected,starT(7,2),"starT(7,2)");

  assertEquals("",starT(1,2),"starT(1,2)");
  assertEquals("",starT(5,1),"starT(5,1)");
  assertEquals("",starT(4,2),"starT(4,2)");
  assertEquals("",starT(6,2),"starT(6,2)");
}

// Test harness

void assertEquals(string expected, string actual, string message="") {
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl << "   Expected:[\n" << expected << "] actual = [\n" << actual << "]\n" << endl;
  }
}


// Main function

int main(int argc, char *argv[])
{
    //the comment is already been done so I do not need to write comments for it
  // TODO: Add check for parameters
  // and code to print usage message
    if (argc!=3) {
        cerr << "Usage: " << argv[0] << " width height" << endl;
        exit(1);
    }
    
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
  // TODO: Add code to get width and height from command line args
  // code that checks if they are both -1; if so, call runTests()
  // then exit.
    if (width==-1 && height==-1) {
        runTests();
        exit(0);
    }

  // TODO: Add code that calls the starT function and prints
  // the result on cout (without an extra newline)
    cout << starT(width,height);
  return 0;
}

