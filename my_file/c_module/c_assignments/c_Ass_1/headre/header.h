//header files and declarations //

#include<stdio.h>

#include<stdlib.h>

//define a constant MAX as 100//
#define MAX 100

//macro to test and set a bit position//
#define bit_ts(num,s_pos) ((((num >> s_pos) & 1) ==0) ? (1) : (0))

//macro to get n bits from p position//
#define getbits(x,pos,n) x=(x >> (pos-(n-1)) & ((1 << n)-1)) << (8-n)

// to convert ASCII to integer
unsigned int f_atoi(char *);

//to get input
void my_fgets(unsigned int);

//to convert decimal to binary//
void showbits(unsigned int);

//swap the bit values between s and d// 
int swap(int,int,int);

//swap bit positions in two different numbers//
void bit_swap(int,int,int,int);

//copy n digits from one nor to another nor at given position//
int bit_copy(int,int,int,int,int);

//toggle even bit positions in a given number//	
int even_bit_toggle(int,int);
	
//toggle odd bit positions in a given number// 
int odd_bit_toggle(int,int);

//left rotate the number by 1 position//
unsigned int left_rotate_bits(unsigned int,int);

//right rotate the number by 1 position//	
unsigned int right_rotate_bits(unsigned int);
	
//left rotate the number by n bit positions//
unsigned int left_rotate_n_bits(unsigned int,int,int);

//right rotate the number by n bit positions//	
unsigned int right_rotate_n_bits(unsigned int,int,int);
	
//count the nor of set bits//
int count_bit_set(int,int);

//count the nor of clear bits//
int count_bit_clear(int,int);

//
int cnt_leading_set_bits(int,int);
	
//
int cnt_leading_cleared_bits(int,int);

//
int cnt_trailing_cleared_bits(int,int);
	
//
int cnt_trailing_set_bits(int,int);
	
/*number x with the ‘n’ bits that begin at position p set to the
right most n bits of y, leaving the other bits unchanged*/
int setbits(int,int,int,int);

/*number x with n bits that begin at position p inverted, leaving
others unchanged*/	
int invert(int,int,int);

//max and min of 2 nors
#define MIN(snum, dnum) ((snum - numd) >> 31 & 1) ? snum : dnum
#define MAX(snum, dnum) ((snum - numd) >> 31 & 1) ? dnum : snum


#define right_clear(num) (num & (num-1)

#define left_clear(num,n) (num ^ (0x01 << (n-1))

#define right_set(num) (num ^ 1)

#define left_set(num) (num & 1) ? (num) : (num ^ 1) 

#define SET_BITS(s, d) (invert(0, s, s - d + 1))

#define CLEAR_BITS(s, d) (invert(~0, s, s - d + 1))

#define TOGGLE_BITS(num, s, d) (invert(num, s, s - d + 1))


