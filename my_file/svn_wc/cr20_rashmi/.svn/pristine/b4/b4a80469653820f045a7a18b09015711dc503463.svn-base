int invert(x,pos,n)
{
	int X;
	X = ((x >> (pos - (n-1))) & ((1 << n) - 1)) ^ ((1 << n) - 1);
	X = (X << (pos - (n - 1))) ^ x;
	return X;
}
