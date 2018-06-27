st = raw_input("Enter string:")
st_up = st.upper()

count_v = 0
count_c = 0
i = 0

while( i <  len(st_up) ):
	
	ch = [st_up[i] == 'A', st_up[i] == 'E', st_up[i] == 'I', st_up[i] =='O', st_up[i] == 'U']
	
	check = any(ch)
	if check:
		count_v += 1
	else:
		count_c += 1	
	i += 1

print "total number of vovels are",count_v
print "total number of consonants are",count_c
