print "Enter two numbers:"
num1 = input("num1:")
num2 = input("num2:")

while(1):
	choice = input("1.add\n2.sub\n3.mul\n4.div\n5.go back\n")

	if(choice == 1):
		add = num1 + num2
		print "addition of ",num1,"and",num2,"is",add

	elif(choice == 2):
		sub = num1 - num2
		print "subtraction of ",num1,"and",num2,"is",sub

	elif(choice == 3):
		mul = num1 * num2
		print "multiplication of ",num1,"and",num2,"is",mul

	elif(choice == 4):
		div = num1/num2
		print "division of ",num1,"and",num2,"is",div

	else:
		print"Exit"
		break


	
