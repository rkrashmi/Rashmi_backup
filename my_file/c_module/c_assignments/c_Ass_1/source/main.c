//main function of all experiments//

#include"header.h"
int main(void)
{
	unsigned int num;
	int n_bits;
	int n;
	char choice;
	int exp;
	int s_pos;
	int d_pos;
	int result;	
	int snum;
	int dnum;
	int even;
	int odd;
	int set;
	int clear;
	int x;
	int y;
	int pos;
	int X;
	unsigned int n_left;
	unsigned int n_right;
	unsigned int left;
	unsigned int right;
	int count;
	char buf[100];

	printf("Enter the number of the experiment:\n");
	printf("1.swap bits in a number\n");
	printf("2.swap bits in a two different numbers\n");
	printf("3.copy n bits from one number to another\n");
	printf("4.toggling of bits\n");
	printf("5.test bit and set\n");
	printf("6.Rotation of bits\n");
	printf("7.counting the bits\n");
	printf("8.count Set and clear leading bits and Trailing bits\n");
	printf("10.Replace y with x\n");
	printf("11.nor of bits to invert\n");
	printf("12.macro function to get bits\n");
	fgets(buf,MAX,stdin);
	exp = atoi(buf);

	switch(exp)
	{
		case 1: printf("Enter the no:\n");
				fgets(buf,MAX,stdin);
				num = f_atoi(buf);
				showbits(num);

				printf("Enter the source bit position:\n");
				fgets(buf,MAX,stdin);
				s_pos = f_atoi(buf);

				printf("Enter the destination bit position:\n");
				fgets(buf,MAX,stdin);
				d_pos = f_atoi(buf);
				
				printf("Output is");
				result = swap(num,s_pos,d_pos);
				showbits( result);
				break;

		case 2: printf("Enter the snum:\n");
				fgets(buf,MAX,stdin);
				snum = f_atoi(buf);
				showbits(snum);

				printf("Enter the dnum:\n");
				fgets(buf,MAX,stdin);
				dnum =f_atoi(buf);
				showbits(dnum);

			    printf("Enter the source bit position:\n");
                fgets(buf,MAX,stdin);
                s_pos = f_atoi(buf);

                printf("Enter the destination bit position:\n");
                fgets(buf,MAX,stdin);
                d_pos = f_atoi(buf);

			    bit_swap(snum,dnum,s_pos,d_pos);
				break;

		case 3: printf("Enter the snum:\n");
                fgets(buf,MAX,stdin);
                snum = f_atoi(buf);
				showbits(snum);

                printf("Enter the dnum:\n");
                fgets(buf,MAX,stdin);
                dnum = f_atoi(buf);
				showbits(dnum);

                printf("Enter the source bit position:\n");
                fgets(buf,MAX,stdin);
                s_pos = f_atoi(buf);

                printf("Enter the destination bit position:\n");
                fgets(buf,MAX,stdin);
                d_pos = f_atoi(buf);

				printf("Enter the n bits to copy:\n");
                fgets(buf,MAX,stdin);
                n = f_atoi(buf);

				dnum = bit_copy(snum,dnum,s_pos,d_pos,n);
				printf("otput = ");
				showbits(dnum);
				break;

		case 4: printf("Enter the size of the nor:\n");
                fgets(buf,MAX,stdin);
                n = f_atoi(buf);

			    printf("Enter the nor:\n");
				fgets(buf,MAX,stdin);
				num = f_atoi(buf);
				showbits(num);

				printf("Enter bits to be toggled\n");
				printf("1.even bit toggle\n2.odd bit toggle\n");
				fgets(buf,MAX,stdin);
				choice = f_atoi(buf);
			
				switch(choice)
					{
						case 1: even = even_bit_toggle(n,num);
								printf("After toggling even bits output =");
								showbits(even);
								break;

						case 2: odd = odd_bit_toggle(n,num);
								printf("After toggling odd bits output = ");
								showbits(odd);
								break;
					}
				break;

		case 5: printf("Enter the nor:\n");
				fgets(buf,MAX,stdin);
                num = f_atoi(buf);
				showbits(num);

			    printf("Enter the bit position:\n");
                fgets(buf,MAX,stdin);
                s_pos = f_atoi(buf);		
				
				set = bit_ts(num,s_pos);
				if(set == 1)
					{ 
						set = 1 << s_pos;
						num = num ^ set;
						printf("Result is = ");
						showbits(num);
					}
				else 
					{
					printf("Result = ");
					showbits(num);
					}
				break;

		case 6: printf("Enter the size of the nor:\n");
                fgets(buf,MAX,stdin);
                n = f_atoi(buf);

				printf("Enter the number:\n");
				fgets(buf,MAX,stdin);
                num = f_atoi(buf);
				showbits(num);
				
				printf("Select the following functions:\n");
				printf("1.left rotate\n2.right rotate\n3.left rotate by n bits\n4.right rotate by n bits\n");
				fgets(buf,MAX,stdin);
                choice = f_atoi(buf);

                switch(choice)
                    {
                        case 1: left = left_rotate_bits(num,n);
                                printf("output After left rotating = ");
								showbits(left);
                                break;

                        case 2: right = right_rotate_bits(num);
                                printf("After right rotating = ");
								showbits(right);
								break;

						case 3:  printf("Enter the nor of bits to rotate:\n");
 							  	 fgets(buf,MAX,stdin);
   								 n_bits = f_atoi(buf);
                                 n_left = left_rotate_n_bits(num,n_bits,n);
                                 printf("OUtput After left rotating bits = ");
								 showbits(n_left);
                                break;

                        case 4: printf("Enter the nor of bits to rotate:\n");
   								fgets(buf,MAX,stdin);
 							 	n_bits = f_atoi(buf);
							    n_right = right_rotate_n_bits(num,n_bits,n);
                                printf("Output After right rotating bits = ");
								showbits(n_right);
								break;
					}
				break;

		case 7:  printf("Enter the size of the nor:\n");
                fgets(buf,MAX,stdin);
                n = atoi(buf);

				 printf("Enter the number:\n");
                fgets(buf,MAX,stdin);
                num = atoi(buf);
				
				printf("Enter which bit to count\n");
				printf("1.set bit\n2.clear bit\n");
				 fgets(buf,MAX,stdin);
                choice = atoi(buf);

                switch(choice)
                    {
						case 1: count = count_bit_set(num,n);
								printf("set bit count = %d\n",count);
								break;
						case 2: count = count_bit_clear(num,n);
                                printf("clear bit count = %d\n",count);
                                break;

					}
				break;

		case 8: printf("Enter the size of the nor:\n");
                fgets(buf,MAX,stdin);
                n =f_atoi(buf);

                printf("Enter the number:\n");
                fgets(buf,MAX,stdin);
                num =f_atoi(buf);
				showbits(num);
				
				printf("Select the following functions:\n");
				printf("1.Leading set bits\n2.leading clear bits\n3.Trailing clear bits\n4.Trailing set bits\n");
				fgets(buf,MAX,stdin);
                choice = f_atoi(buf);

                switch(choice)
                    {
						case 1: count = cnt_leading_set_bits(num,n);
								printf("Result = %d",count);
								break;
	
						case 2: count = cnt_leading_cleared_bits(num,n);
                                printf("Result = %d", count);
								break;

						case 3: count = cnt_trailing_cleared_bits(num,n);
                                printf("Result = %d", count);
								break;

						case 4: count = cnt_trailing_set_bits(num,n);
                                printf("Result = %d", count);
								break;
					}
				break;
		case 9: printf("Select one"\n);
				printf("1.finding Max and Min of 2 nor\n");
				printf("2.To clear right most set bit in a nor:\n");
				fgets(buf,MAX,stdin);
				choice = f_atoi(buf);
				
				switch(choice)
				{
					case 1: printf("Enter the first number:\n");
			                fgets(buf,MAX,stdin);
             			    num =f_atoi(buf);
                			//showbits(snum);

						   printf("Enter the second number:\n");
                           fgets(buf,MAX,stdin);
                           num =f_atoi(buf);
                     	  // showbits(dnum);
							
						  result = MIN(snum,dnum);
						  printf("min = %d\n",result);

						  X = MAX(snum,dnum);
						  printf("max = %d\n",X);
					
						  break;
					case 2: printf("Enter the number:\n");
                			fgets(buf,MAX,stdin);
                			num =f_atoi(buf);
    			            showbits(num);
					
							X = right_clear(num);
							printf("OUTput = ");
							showbits(X);
				}			break;
				
		case 10: printf("Enter the number x:\n");
                 fgets(buf,MAX,stdin);
                 x = f_atoi(buf);
				 showbits(x);

				 printf("Enter the number y:\n");
 				 fgets(buf,MAX,stdin);
				 y = f_atoi(buf);
				 showbits(y);

				 printf("Enter the n bits to replace:\n");
                 fgets(buf,MAX,stdin);
                 n = f_atoi(buf);

				printf("Enter the bit position:\n");
				fgets(buf,MAX,stdin);
				pos = f_atoi(buf);

				X = setbits(x,y,n,pos); 
				printf("Result = ");
				showbits(X);
				break;

		case 11: printf("Enter the nor x:");
				 fgets(buf,MAX,stdin);
				 x = f_atoi(buf);
				 showbits(x);

			    printf("Enter the bit position:\n");
                fgets(buf,MAX,stdin);
                pos = f_atoi(buf);

				printf("Enter the nor of bits to invert:");
				fgets(buf,MAX,stdin);
				n = f_atoi(buf);

				X = invert(x,pos,n);
				printf("output after inverting =");
				showbits(X);
				break;

		case 12: printf("Enter the nor x:\n");
				 fgets(buf,MAX,stdin);
                 x = f_atoi(buf);
				 showbits(x);

                printf("Enter the bit position:\n");
                fgets(buf,MAX,stdin);
                pos = f_atoi(buf);

                printf("Enter the nor of bits to get:");
                fgets(buf,MAX,stdin);
                n = atoi(buf);
				x = getbits(x,pos,n);
				printf("bits = ");
				showbits(x);
				break;

		default: break;
	};
	return 0;
} 
