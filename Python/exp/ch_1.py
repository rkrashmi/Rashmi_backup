i = 0
ls = ['A' == 1,'B' == 2,'C' == 3,'D' == 4, 'E' == 5]

x = raw_input("Enter the string:")
for data in x:
	if(data == any(ls)):
		print data
	

