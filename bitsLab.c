
/* 
 * CS:APP Data Lab 
 * 
 * <Wjdan Alharthi + Saakshi Verma  walharth+saakv08>
 * <Wjdan Alharthi walharth>
 * <Saakshi Verma saakv08>

 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
// Rating: 1
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
    /* Simply negate both numbers then negate their OR */
    return ~(~x | ~y);
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
 /* To check if a 32-bit number can be represented as a 16-bit number, we only need to care about the first 16 bits.
  * So we right shift x by 15 first, and then right shift it again by 16. Finally check if the results of the two 
  * right shifts are equal (XOR then Bang)
  */
  int allShifted = x >> 16;
  int allButOneShifted = x >> 15; 
  return !((allShifted)^(allButOneShifted));
}
// Rating: 2
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */

int divpwr2(int x, int n) {
  /* Dividing by a power of 2 is basically right shifting by the power (n).
   * Then we are supposed to round by adding 1 ONLY if we lose a high bit when we shift. 
   * So we mask the lost bits in lostOne and check for a high bit. 
   * We also check if x is negative in msb by getting the most sig bit (shift by 31) 
   * Finally we check if the power (n) is zero in divBy1.
   */ 
  int shiftBypwr = x >> n;
  int lostBits = !!((~0x0 + (0x1 << n)) & x); //check if we lost a high bit by masking the bits that fall by shifti
  int msb = (x>>31);
  int divBy1 = !!(n^0x0);  
  return shiftBypwr + (lostBits & msb & divBy1);
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  /* This code is based on some observations on the relatioship between a number and its negative
   * (flip and add one). If you get the negative of x then AND it with itself, you will always return
   * a power of 2. Also, we know the fact that any power of 2 has exaclty one high bit, which is luckly the
   * position of the bit position we want
   */ 
  int negX = ~x + 1; 
  return (negX & x );
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /* First we need the mask 0xff that is all ones in the first byte.
   * Then we use the fact that n has only the values 0, 1, 2, and 3. Because when you shifted any of them by 
   * 3, you will get the multiple of 8 which is the number of bits in one byte. Thus we shift n by 3
   * and we shift the 8 bits we need in x by (n<<3). Now we have the wanted byte as the first byte in 
   * wantedByteShifted. Finally AND it with mask to zero everythigs except the first byte. 
   */
  int mask = 0xff;
  int wantedByteShifted = x >> (n << 3); 
  return mask & wantedByteShifted;
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
  /* This code is extremely basic and simple. 
   * Since we are working with a 32-bit machine, we have 4 bytes (each has 8 bits). We use the mask 
   * 0x55 which is 0101, so it has high bits in its even-numbered positions. We simply and and the mask with 
   * all the bytes and then or the results to get 1 if ANY of them has s hight in the even-numbered position
   * and just not it twice to get either 1 or 0 
   */  
  int firstByte = x & 0x55;
  int secondByte = x & (0x55 << 8);
  int thirdByte = x & (0x55 << 16);
  int fourthByte = x & (0x55 << 24); 
  return !!( firstByte | secondByte | thirdByte | fourthByte);
}
// Rating: 3
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit){
  /* The mask is all ones. First we left shift the mask by lowbit to get the zeros on the right (var leftshited) 
   * Second, we left shift 0x1 by highbit (another mask), and left shift that by 1 (to avoid the rotated shift).
   * Third, add the results from steps 1 and 2 to get the number we need. 
   * Then we check if highbit < lowbit by doing the following: 
   * 1- negate lowbit (flip and add 1)       2- add it to highbit       3- check the most sig bit of their addition 
   * if the result of adding them is negative (msb is 1), that means lowbit is greater than highbit 
   * AND them so that if highbit < lowbit, we will AND our number with zero
   */ 
  int mask = ~0x0;
  int zerosOnRight = mask << lowbit;
  int zerosOnLeft = (0x1 << highbit) << 1;  
  int negLowbit = (~lowbit) + 1;
  int DiffMsb = ((highbit + negLowbit) >> 31);  
  return (zerosOnRight + zerosOnLeft) & (~DiffMsb); 
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /* This was the most complicated of all. We had to find a pattren that identifies the illegal hex numbers. 
   * First we checked if all bytes except the last one is equal to 3 using the mask and comparing it with 0x3.  
   * Second we created two tests to check for two things: 
   * 1- if the fourth bit from the right is 1 (1***)- we AND x with 0x8 
   * 2- if the second and third bits from right contain a 1 (*11* OR (*01*) OR (*10*)- we AND x with 0x6
   * If these two things are true at the same time (1 & 2 == True), then we return 0
   * else, we return 1. Then we AND them.
   */  
  int mask = ~0x0 << 4;
  int isThree = !(((mask&x) >> 4) ^ 0x3);
  int mask2 = 0x6;
  int mask3 = 0x8; 
  int mid2Bits = !!(mask2 & x);
  int fourthBit = !!(mask3 & x); 
  return isThree & !(mid2Bits & fourthBit);
} 
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */

int isPositive(int x) {
  /* This simple code basically checks for the most significant bit. If it's one then it's negative (return 0)
   * if it is zero then it's positive (return 1) 
   * HOWEVER, we have to make a case when x is zero. Simply by comparing it with 0x0 using XOR and
   * logical negation (bang)
   */
  int msbIsZero = !((x>>31));
  int xIsZero = !!(x^0x0);
  return msbIsZero & xIsZero;
}
//Rating: 4
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  /* This function uses 2 very interesting obsevations about powers of 2 which are: 
   * 1- powers of 2 contain EXACTLY 1 highbit 
   * 2- the AND of a power of 2 with the number less than it (by one) is zero 
   * So we first check if it has exactly 1 hight bit by ANDing it with the number less than it. 
   * Then we check if the x is negative and if the number is zero 
   */ 
  int numLessThanX = x + ~0x0; 
  int hasExactly1One = !(x & numLessThanX);
  int isNeg = !((x>>31) & 0x1);
  int isZero = !!x; 
  return isZero & hasExactly1One & isNeg; 
}
