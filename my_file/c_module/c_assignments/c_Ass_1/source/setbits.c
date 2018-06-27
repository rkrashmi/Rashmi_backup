int setbits(x,y,n,pos)
{
	int X;
	X =((x >> (pos-(n-1)) & ((1 << n) - 0x01)) | y);
	return X;
} 
	 
