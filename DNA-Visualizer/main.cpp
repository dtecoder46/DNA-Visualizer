#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // All variables initialized here except color codes and num_list
  
  string num_chain; // holds the number sequence from num.txt
  string error; // file error message
  string DNA; // holds DNA sequence
  string DNA_vis = "|— — — —|\n"; // starts DNA image with a header, holds DNA image
  string RNA; // holds RNA sequence
  string RNA_vis = "|— —\n";
  int length; // length of number sequence in num.txt

  // setup of colored text variables
  
  string red = "\033[91m";
  string yellow = "\033[33m";
  string blue = "\033[94m";
  string green = "\033[92m";
  string magenta = "\033[95m";
  string blank = "\033[0m";

  error = red + "File not open or available" + blank + "\n"; // Creating the red error message
  
  ifstream myfile; // variable to set up file operations
  myfile.open("num.txt");
  
  if (myfile.is_open()) { // file must actually be open for procedure to continue
    while (getline(myfile, num_chain)) {
      cout << "Number chain input: " << num_chain << '\n' << '\n'; // outputs each line of the file
    }

    myfile.close(); // closing file for security reasons
  }
  
  else cout << error; // error if file not open

  // Main DNA strand
  
  length = num_chain.length();
  string num_list[length];
  
  for (int index = 0; index < length; index++) {
    // Adds each digit in num_chain to a string list
    // This converts the digits into string form so the if statements can compare them
    num_list[index] = num_chain[index];
  }

  cout << "DNA sequence: "; // label of DNA output
  
  for (string num : num_list) {
    // Converts each digit into the corresponding nucelotide
    // Add nucleotide pair to DNA image variable with colored text
    if (num == "1") {
      DNA += "A";
      DNA_vis += "|—" + red + "A" + blank + " — " + yellow + "T" + blank + "—|\n";
    }

    if (num == "2") {
      DNA += "T";
      DNA_vis += "|—" + yellow + "T" + blank + " — " + red + "A" + blank + "—|\n";
    }

    if (num == "3") {
      DNA += "C";
      DNA_vis += "|—" + blue + "C" + blank + " — " + green + "G" + blank + "—|\n";
    }

    if (num == "4") {
      DNA += "G";
      DNA_vis += "|—" + green + "G" + blank + " — " + blue + "C" + blank + "—|\n";
    }
  }

  cout << DNA <<"\n";

  // Closes off DNA image with a footer and prints the image
  DNA_vis += "|— — — —|\n\n";
  cout << DNA_vis;


  // Transcrption of main strand to RNA

  for (char nuc : DNA) {
    // Converts each main strand DNA nucleotide into an RNA nucelotide
     // Add nucleotide pair to RNA image variable with colored text
    
    if (nuc == 'A') {
      RNA += "U";
      RNA_vis += "|—" + magenta + "U" + blank + "\n";
    }

    if (nuc == 'T') {
      RNA += "A";
      RNA_vis += "|—" + red + "A" + blank + "\n";
    }

    if (nuc == 'C') {
      RNA += "G";
      RNA_vis += "|—" + green + "G" + blank + "\n";
    }

    if (nuc == 'G') {
      RNA += "C";
      RNA_vis += "|—" + blue + "C" + blank + "\n";
    }
  }

  cout << "RNA sequence: " << RNA << "\n";

  // Closes off DNA image with a footer and prints the image
  RNA_vis += "|— —\n\n";
  cout << RNA_vis;
  
  return 0;
}
