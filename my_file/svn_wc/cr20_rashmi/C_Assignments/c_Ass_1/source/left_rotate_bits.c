unsigned int left_rotate_bits(num,n)
{
	int set;
	set = (num >> (n-1)) & 0x01;	
	num = (((num << 0x01) ^ set) & 0xffff);
	return num;
}
