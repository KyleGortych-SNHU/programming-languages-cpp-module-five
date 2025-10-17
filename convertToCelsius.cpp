/**
 * File: convertToCelsius.cpp
 *
 *
 * Author: Kyle Gortych
 * Date: 2025-10-02
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// function to convert units
// (F - 32) * (5/9) = C
int convertToCelsius(int fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

bool fileOperations() {
  //files to open
  ifstream inputFile("FahrenheitTemperature.txt");
  ofstream outputFile("CelsiusTemperature.txt");
  
  // vars
  string place;
  int value;

  // Checks if either input or output file can't be accessed
  if(!inputFile) {
    cout << "Error: can't open input file." << endl;
    return false;
  } else if(!outputFile) {
    cout << "Error: can't open output file." << endl;
    return false;
  }

  // Exits when at end of file
  // Assuming precondition of input file format
  while(inputFile >> place >> value) {
    int celsius = convertToCelsius(value);
    outputFile << place << " " << celsius << endl;
  }
  
  inputFile.close();
  outputFile.close();

  cout << "Conversion to celsius complete." << endl;
  return true;
}

int main () {
  // function call checks return bool 
  if(!fileOperations()) {
    return 1;
  }

  return 0;
}
