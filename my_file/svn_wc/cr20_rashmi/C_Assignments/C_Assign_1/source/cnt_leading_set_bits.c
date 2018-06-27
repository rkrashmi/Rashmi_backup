int cnt_leading_set_bits(num,n)
{
    int set;
    set  = ((num >> (n-1)) & 0x01);
    if(set == 0)
    {
        set = !set;
        num = (num ^ set <<(n-1));
    }
    return set;
}

                                                                                                                                           
                                                                                                                                                      
