unsigned int left_rotate_n_bits(num,n_bits,n)
{
	int i;
	int set;	
	for(i=0;i < n_bits;i++)
	{
    	set = (num >>(n-1)) & 0x01;
    	num = (((num << 0x01) ^ set) & 0xff);
	}
    return num;
}

