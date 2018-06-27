#	Author Name: Rashmi R.K.
#	Batch: CR20
#	File name: /home/rashmi/Python/ch_exp/unitest.py
#	Time: 03-04-18 05:28:09 PM

import unittest

for topic in dir(unittest):
	print help(eval("unittest."+topic))
	print
