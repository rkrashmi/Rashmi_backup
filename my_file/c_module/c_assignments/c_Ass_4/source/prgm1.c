// program to print size of the structure

#include<stdio.h>
#pragma pack(1)
struct A {
	int GFC:4;
	int VPI:8;
	int VCI:16;
	int PTI:3;
	int CLP:1;
	int HEC:8;
};

struct B {
	int source_port : 16;
	int destination_port : 16;
	int sequence_Number : 32;
	int Ack_number : 32;
	int Header_Length : 4;
	int reserved : 6;
	int Code_bit : 6;
	int window : 16;
	int check_sum : 16;
	int urgent : 16;
};

struct C {
	int version : 4;
	int Header_length : 4;
	int service_type : 8;
	int total_length : 16;
	int identification : 16;
	int flags : 3;
	int frag_offset : 12;
	int TTl : 7;
	int protocol : 9;
	int header_checksum : 16;
	int source_ip;
	int dest_ip;
};	
	 
int main(void)
{
	struct A size_0;
	struct B size_1;
	struct C size_2;
	printf("Size of structure is %d bytes\n",sizeof(size_0));
	printf("Size of structure is %d bytes\n",sizeof(size_1));
	printf("Size of structure is %d bytes\n",sizeof(size_2));

	return 0;
	
}	
