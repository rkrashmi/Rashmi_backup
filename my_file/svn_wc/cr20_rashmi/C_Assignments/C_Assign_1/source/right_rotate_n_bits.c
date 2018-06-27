unsigned int right_rotate_n_bits(num,n_bits,n)
{
    int i;
	int set;
    for(i=0;i<= n_bits;i++)
	{
    	set = num & 0x01;
    	num = num >> 0x01;
    	num = num ^ (set << (n-1));
	}
    return num;
}

