#prime number generation

def	gen_prime ( num ) :
	ret = []
	for num_1 in range ( 2, num + 1 ):
		if num_1 > 1:
			for ele in range( 2, num_1 ):
				if ( num_1 % ele ) == 0:
					break
			else:
				ret.append( num_1 )
	return ret

print "prime numbers"
x = input( "enter the max till which you want to generate the prime numbers" )
print gen_prime( x )


#armstrong number generation

def	is_armstrong( num ):
	i = 1
	ret = []
	while i <= num:
		temp = i
		s = 0
		while temp != 0:
			res = temp % 10
			temp = temp / 10
			s = s + ( res * res * res )
		if s == i:
			ret.append( i )
		i += 1
	
	return ret
print "generating armstrong numbers withing 500"
print is_armstrong(500)

#to find the fibonacii numbers 
def fibonacci(num):
	ret = []
	first = 0
	second = 1
	next_num = 0
	ret.append(first)
	ret.append(second)
	for ele in range(1,num + 1):
		next_num = first + second
		first = second
		second = next_num
		if next_num > num :
			break
		else:
			ret.append(next_num)
	return ret

print "fibonacii numbers"
y = input("enter the max number till you want fibonacii")
print fibonacci(y)
