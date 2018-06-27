#Accept a string from the user and perform the following:
#	[a] Count the number of VOWELS and CONSONANTS.
#	[b] Check if the string is a PALINDROME string or not.

def	count_vowels_and_consI(string):
	ret = []
	count_v = 0
	count_c = 0
	vowels = 'aeiou'
	const = 'bcdfghjklmnpqrstvwxyz'
	for data in string:
		if data in vowels :
			count_v += 1
		elif data in const:
			count_c += 1
	ret.append(count_v)
	ret.append(count_c)
	return ret
x = raw_input("enter the word  :  ")
print "[vowels,consonents]"
print count_vowels_and_consI(x)

#palindrome or not
def	palindrome(string):
	lst = string[::-1]

	if lst == string:
		return True
	else:
		return False

y = raw_input("enter the word  :  ")
if 1 ==  palindrome(y):
	print "is a Pal"
else:
	print "not a pal"
