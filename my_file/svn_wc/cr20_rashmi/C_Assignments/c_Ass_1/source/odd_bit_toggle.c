int odd_bit_toggle(int n,int num)
{
    int i;
    int x;
	int odd;
    for(i=1;i<=n-1;i+=2)
    {
        x = 1 << i;
        num = num ^ x;
    }
	odd=num;
    return odd;
}
