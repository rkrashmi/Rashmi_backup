n1 = input("Ennter num upto which primes are to be displayed:")

for num in range(2, n1):
	prime = True
	for i in range(2, num):
		if (num % i == 0):
			prime = False
	if(prime):
		print num
