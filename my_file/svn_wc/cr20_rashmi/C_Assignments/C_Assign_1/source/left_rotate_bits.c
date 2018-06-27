unsigned int left_rotate_bits(num,n)
{
	int set;
	set = (num >> (n-1)) & 0x01;	
	num = num << 0x01;
	num = num ^ set;
	return num;
}
