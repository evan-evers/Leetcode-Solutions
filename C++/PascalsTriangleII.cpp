//Original problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
  vector<int> row(rowIndex + 1, 1);  //initialize an array with all the elements we'll need

  //i corresponds to an element in the row. since triangle is symmetric, we only calculate one half of a row to get the whole thing
  //since the vector is initialized to 1's, we don't need to calculate the edge elements, which are always 1. thus, i starts at 1
  //2 is added to row index instead of 1 to make sure that interger division works properly
  for (int i = 1; i < (rowIndex + 2)/2; i++) {    
      //calculate each element of the row using the diagonal method
      double n = 1;
      for (int j = 0; j < i; j++) {   //diagonal method
        n /= j + 1;
        n *= rowIndex - j;
        n = round(n);   //gotta put this here so leetcode doesn't throw a fit from precision errors in the division
      }

    //set element and its counterpart in the other half of the triangle
    row[i] = n;
    row[rowIndex - i] = n;
  }

  return row;  //return the row we want
}
