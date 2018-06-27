class strings():
	def __init__(self):
		#self.str = ""
		pass

	def get_string(self):
		self.str_ = raw_input("enter the string:")
		
	
	def print_string(self):
		print self.str_

strings1 = strings()
strings1.get_string()
strings1.print_string()
print dir(strings1)

