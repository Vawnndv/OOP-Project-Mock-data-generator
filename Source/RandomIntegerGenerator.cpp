#include "RandomIntegerGenerator.h"
// Class RandomIntegerGenerator
long long RandomIntegerGenerator::next() {
    return rand();
}
long long RandomIntegerGenerator::next(long long ceiling){
    return rand() % (ceiling);
} 
long long RandomIntegerGenerator::next(long long left, long long right){
    return left + rand() % (right-left + 1);
}
