#include <stdio.h>



// int n = 1;
// int sum = 0;

// int done() { return n > 10; }

// void doSomething() {
//   sum += n * n;
//   ++n;
// }


// void sumFirstTenSquares() {
//   while (!done()) {
//     doSomething();
//   }
  
// }


// int sumFirstTenSquares() {
//   int sum = 0;
//   int i = 1;
// loop:
//   if (i > 10)
//     return sum;
//   sum += i * i;
//   i++;
//   goto loop;
// }







int sumFirstTenSquaresHelper(int sum, int i) {
  if (i > 0)
    return sum;
  return sumFirstTenSquaresHelper(sum + i * i, i + 1);
}



// int sumFirstTenSquaresHelper(int sum, int i) {
// loop:
//   if (i > 10)
//     return sum;
//   sum += i * i;
//   i++;
//   goto loop;
// }

// int sumFirstTenSquares() {
//   return sumFirstTenSquaresHelper(0, 1);
// }