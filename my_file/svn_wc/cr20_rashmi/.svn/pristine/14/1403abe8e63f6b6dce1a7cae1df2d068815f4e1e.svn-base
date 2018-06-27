int cnt_leading_cleared_bits(num,n)
{
    int clear;
    clear = ((num >> (n-1)) & 0x01);
    if(clear == 1)
    {
        clear =  !clear;
        num = num ^ (clear << (n-1));
    }
    return clear;
}

                                                                                                                                               
                                                                                                                                               
       
