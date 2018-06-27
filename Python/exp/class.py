#	Author Name: Rashmi R.K.
#	Batch: CR20
#	File name: /home/rashmi/Python/exp/class.py
#	Time: 10-04-18 12:31:41 PM


#str first 
#str last
class Employee:
	def __init__(self, first, last, pay):
		self.first = first
		self.last = last
		self.pay = pay
		self.email = first + '.' + last + '@company.com'


#emp_1 = Employee('rashmi','kale',50000)
#emp_2 = Employee('rohit', 'kale', '75000')

#print "email :",emp_1.email
#print "Name : ",emp_1.first + "." + emp_1.last,"\n" "Payment :", emp_1.pay
#print emp_2.email


print "Number of employees to be entered :  " 
num = input()

for i in range(0, num):
	first = raw_input("Enter first name of employee: ")
	last = raw_input("Enter last name of employee: ")
	pay = input("Enter payment: ")
	print "Email:", first + '.' + last + "@company.com"
	print "Name: ", first + '.' + last
	print "Pay: ",pay



	

