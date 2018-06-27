num = input("Enter the number upto which u want fibo series:")
first = 0
second = 1
if (num == 1):
	print first
elif (num == 2):
	print first
	print second
else:
	print first
	print second
	while(first + second) < num:
		fibo = first + second

		print fibo
		first = second
		second = fibo
 
