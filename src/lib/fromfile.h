#ifndef FROMFILE_H
#define FROMFILE_H

#include <fstream>
#include <string>

template <typename T> class FromFile {
protected:
  std::string filename;

public:
  FromFile(std::string fname) : filename(fname){};
  virtual ~FromFile(){};

  virtual T parse() = 0;
};

#endif