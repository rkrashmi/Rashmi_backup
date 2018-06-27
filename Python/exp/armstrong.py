#To find Armstrong number

for num in range(1, 500):
	su_m = 0
	digit = 0
	n1 = num
	check = num
	while(num):
		num = num / 10
		digit += 1
		#print "digit",digit

	while(n1):
		rem = n1 % 10
		n1 = n1 / 10
		su_m = su_m + (rem ** digit)
		#print su_m

	if(check == su_m):
		print "Armstorong number:",check

