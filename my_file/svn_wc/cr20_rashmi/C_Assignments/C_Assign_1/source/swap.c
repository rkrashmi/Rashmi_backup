
int swap(num,source_pos,dest_pos)
{
	int bit1;
	int bit2;
	int bit3;
	int result;
	bit1 = ((num >> source_pos) & 0x01);
	bit2 = ((num >> dest_pos) & 0x01);

	bit3 = bit1 ^ bit2;
	bit3 = ((bit3 << source_pos)|(bit3 << dest_pos));
	
	result = num ^ bit3;
	
	return result;
}
