#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Record.hpp"

bool record_cmp(Record &a, Record &b) {
  return a.milliseconds < b.milliseconds;
}

std::ostream &operator<<(std::ostream &os, Record const &r) {
  return os << '{' << r.name << ',' << r.milliseconds / 1000.0 << '}';
}

std::ostream &operator<<(std::ostream &os, std::vector<Record> &vet) {
  os << '<' << std::endl << '\t';
  if (vet.size() > 0) {
    os << vet[0];
  }
  for (int i = 1; i < vet.size(); i++) {
    os << ',' << std::endl << '\t' << vet[i];
  }
  os << std::endl << '>';
  return os;
}

void sort(std::vector<Record> &records) {
  std::sort(records.begin(), records.end(), record_cmp);
}

void write_records(std::vector<Record> &records, std::string &file_name) {
  int cont = 0;
  std::ofstream file;
  file.open(file_name.c_str());
  if (file.is_open()) {
    if (records.size() > 11) {
      file << 11 << std::endl;
    } else {
      file << records.size() << std::endl;
    }
    for (Record rec : records) {
      if (cont < 10) {
        file << rec.name << std::endl;
        file << rec.milliseconds << std::endl;
      } else {
        records.pop_back();
      }
      cont++;
    }
    file.close();
  }
}

int read_records(std::vector<Record> &records, std::string &file_name) {
  int size;
  std::ifstream file;
  file.open(file_name.c_str());
  if (file.is_open()) {
    records.clear();
    file >> size;
    file.ignore();
    for (int i = 0; i < size; i++) {
      Record rec;
      std::getline(file, rec.name);
      file >> rec.milliseconds;
      file.ignore();
      records.push_back(rec);
    }
    file.close();
  }
  return size + 1;
}

int show_records(std::vector<Record> &records, std::string &file_name) {
  int size;
  std::ifstream file;
  file.open(file_name.c_str());
  if (file.is_open()) {
    records.clear();
    file >> size;
    file.ignore();
    for (int i = 0; i < size; i++) {
        Record rec;
        std::getline(file, rec.name);
        file >> rec.milliseconds;
        file.ignore();
        records.push_back(rec);
    }
    if(size>10){
      records.pop_back();
    }
    file.close();
  }
  return size + 1;
}
