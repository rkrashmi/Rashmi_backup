int count_bit_clear(num,n)
{
    int i;
    int clear;
	int count;
    for(i=0;i <= (n-1);i++)
    {
        clear = ((num >> i) & 0x01);
        if(clear == 0)
        {
            count++;
        }
    }

    return count;
}

