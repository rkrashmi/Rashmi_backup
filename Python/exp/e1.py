name = 'Alice'

def std1():
	print 'within func1 name is:',name

def std2():
#	global name
	name = 'bob'
	print 'within func2 name is:',name

print "within main function name is:",name
std1()
std2()
print "now global function name is:",name

#def std1():
#	print 'within func1 name is:',name
