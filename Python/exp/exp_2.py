#	Author Name: Rashmi R.K.
#	Batch: CR20
#	File name: /home/rashmi/Python/exp/exp_2.py
#	Time: 03-05-18 07:54:05 PM

import random

def getAnswer(num):
	if num == 1:
		return 'It is certain'
	elif num == 2:
		return 'It is decidedly so'
	elif num == 3:
		return 'Yes'
	elif num == 4:
		return 'Reply hazy try again'
	elif num == 5:
		return 'Ask agian later'
	elif num == 6:
		return 'Concentrate and try agian'
	elif num == 7:
		return 'No'
	elif num == 8:
		return 'Outlook not soo good'
	elif num == 9:
		return 'Doubtful'



for i in range(10):
	r = random.randint(1, 9)
	print(getAnswer(r))
