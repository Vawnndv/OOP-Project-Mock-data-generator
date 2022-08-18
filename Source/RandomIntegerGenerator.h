#ifndef _RANDOMINTEGERGENERATOR_H_
#define _RANDOMINTEGERGENERATOR_H_
#include <ctime>
#include <iostream>
class RandomIntegerGenerator {
public:
	// RandomIntegerGenerator() {
  // //srand(time(NULL));
  // }
  long long next();
  long long next(long long ceiling);  // [0, ceiling)
  long long next(long long left, long long right);  // [left, right]
};
#endif