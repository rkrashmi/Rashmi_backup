int count_bit_set(num,n)
{
    int i;
    int set;
	int count = 0;
    for(i=0;i <= (n-1);i++)
    {
        set = ((num >> i) & 0x01);
        if(set == 1)
        {
            count++;
        }
    }

    return count;
}

