#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

#define endl "\n"

int usage(char *arg) {
  // exit program
  cout << arg << ": Error" << endl;
  return -1;
}

int main(int argc, char *argv[]) {
  int rows, cols, size, greylevels;
  string filetype;

  // open stream in binary mode
  ifstream istr(argv[1], ios::in | ios::binary);
  if (istr.fail()) return usage(argv[1]);

  // parse header
  istr >> filetype >> rows >> cols >> greylevels;
  size = rows * cols;

  // check data
  cout << "filetype: " << filetype << endl;
  cout << "rows: " << rows << endl;
  cout << "cols: " << cols << endl;
  cout << "greylevels: " << greylevels << endl;
  cout << "size: " << size << endl;

  // parse data values
  int *data = new int[size];
  int fail_tracker = 0;  // find which pixel failing on
  for (int *ptr = data; ptr < data + size; ptr++) {
    // read in binary char
    unsigned char t_ch = istr.get();
    // convert to integer
    int t_data = static_cast<int>(t_ch);
    // check if legal pixel
    if (t_data < 0 || t_data > greylevels) {
      cout << "Failed on pixel: " << fail_tracker << endl;
      cout << "Pixel value: " << t_data << endl;
      return usage(argv[1]);
    }
    // if passes add value to data array
    *ptr = t_data;
    fail_tracker++;
  }
  // close the stream
  istr.close();

  // write a new P2 binary ascii image
  ofstream ostr("greyscale_ascii_version.pgm");
  // write header
  ostr << "P2" << endl << rows << " " << cols << endl << greylevels << endl;
  // write data
  int line_ctr = 0;
  for (int *ptr = data; ptr < data + size; ptr++) {
    // print pixel value
    ostr << *ptr << " ";
    if (++line_ctr % 1000 == 0) {
      ostr << endl;
      cout << ptr - data << "/" << size << "  " << ((ptr - data) * 100) / size
           << "%" << endl;
    }
  }
  ostr.close();

  // clean up
  delete[] data;
  return 0;
}