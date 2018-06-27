def fact_num(num):
	if(num == 0):
		return 1
	return num * fact_num(num -1) 

#main program

num = int(raw_input("Enter the norto find factorial of nor:"))
result = fact_num(num)
print "Factorial of a",num,"is",result

