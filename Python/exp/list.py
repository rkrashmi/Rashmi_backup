count = 0
ls =[]
def ins_beg(nm):
	ls.insert(0,nm)
	return ls

while(1):
	
	ch = input("1.print list\n2.print ele of list one by one\n3.insert an ele at beginning\n4.inserta an ele at given pos\n5.insert at end\n6.delete at given position\n7.delete element by value\n8.print the lenth of list\n")

	if(ch == 1):
		count += 1
		if count == 1:
			print "list is empty"
		else:
			print ls

	elif(ch == 2):
		for i in range(0,len(ls)):
			print ls[i]
	
	elif(ch == 3):
		print ins_beg(input("insert:"))			

	elif(ch == 4):
		print"enter the pos and number:"
		pos = input("pos:")
		num = input("num:")

		ls.insert(pos,num)

	elif(ch == 5):
		num = input("enter the number:")
		ls.append(num)

	elif(ch == 6):
		print "Enter the pos:"
		pos = input("pos:")
		ls.pop(pos)

	elif(ch == 7):
		print" Enter the value"
		val = input("val:")
		ls.remove(val)

	elif(ch == 8):
		print"length of the list is:"
		print len(ls)

	else:
		print"Invalid input"

