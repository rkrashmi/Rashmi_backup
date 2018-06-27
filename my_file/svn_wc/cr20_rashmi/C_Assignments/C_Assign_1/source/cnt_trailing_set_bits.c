int cnt_trailing_set_bits(num,n)
{
    int set;
    set = (num & 0x01);
    if(set == 0)
    {
        set = set ^ 0x01;
        set = num ^ set;
    }
    return set;
}


