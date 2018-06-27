int cnt_trailing_cleared_bits(num,n)
{
    int clear;
    clear = (num & 0x01);
    if(clear == 1)
    {
        clear = clear & 0x00;
        num = num ^ clear;
    }
    return clear;
}

