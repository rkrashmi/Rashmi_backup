#function
def div_fun(num):
	if (num % 7 == 0):
		if(num % 5 != 0):
			l.append(num)

	#else:
	#	print "NUmber",num, "not divisible by 7"

#main program


l = []
for i in range(2000,3200):
	div_fun(i)

print l
