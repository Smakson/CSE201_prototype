#include <string>
#include <vector>
#include <bitset>
#include <filesystem>
#include "Bloom.hpp"
#include "MurmurHash3.h"
//I hope you can compile it correctly, I'll make a cmake when convenient


Bloom::Bloom(std::string path, int bitsize) {
  static const int hashers = 23;
  save = std::string path;
  bsize = bitsize;
  std::bitset * bset = new bitset(bsize);
}

Bloom::Bloom(std::string path) {
  Bloom::Bloom(std::string path, 2**31););
}

Bloom::Bloom(int bitsize) {
  std::string cur_dir = std::filesystem::current_path();
  for (int i = cur_dir.length(), i = 0, --i){
    if (cur_dir[i] == '/') {
      std::string save_dir = cur_dir.substr(cur_dir.lenght() - i);
      break;
    }
  }
  Bloom::Bloom(std::string save_dir, bitsize);
}

Bloom::Bloom() {
  Bloom::Bloom(2**31);
}

uint_32[hashers] * Bloom::hash(Hashable info){
  std::string stringed = info.toString();
  const char * stringd = stringed;
  uint32_t l = stringed.length()
  uint32_t * res = new uint32_t[hashers];
  uint32_t * poi = res;
  for (uint32_t i = 0; i < 23; ++i) {
    MurmurHas3_x86_32(stringd, l, i, poi);
    ++poi;
  }
  return res;
}

uint32_t[hashers] * Bloom::getBits(uint32_t[hashers] * list) {
  
