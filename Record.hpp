#ifndef RECORD_H_
#define RECORD_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Record {
  std::string name;
  double milliseconds;
};


bool record_cmp(Record &a, Record &b);

std::ostream &operator<<(std::ostream &os, Record const &r);

std::ostream &operator<<(std::ostream &os, std::vector<Record> &vet);

void sort(std::vector<Record> &records);

void write_records(std::vector<Record> &records, std::string &file_name);

int read_records(std::vector<Record> &records, std::string &file_name);

int show_records(std::vector<Record> &records, std::string &file_name);

#endif
