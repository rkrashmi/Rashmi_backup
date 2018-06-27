str_ = raw_input("enter the string:")
str_count = 0
digit_count = 0

for i in range(len(str_)):
	if (str_[i] >= 'a' and str_[i] <= 'z') or (str_[i] >= 'A' and str_[i] <= 'Z'):
		str_count += 1

	elif (str_[i] >= '0' and str_[i] <= '9'):
		digit_count += 1

print "number of alphabets:",str_count
print "number of digits:",digit_count	
	
