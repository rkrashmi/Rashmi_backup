original = raw_input("Enter the string to check palindrome")
temp = reversed(original)
reverse_d = list(temp)

i = 0
while(i < len(original)):
	if(original[i] == reverse_d[i]):
		i += 1
	else:
		print "string is not a palindrome"
		break
if(i == len(original)):
	print"string is a palindrome"
