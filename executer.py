# Hrishikesh Hiraskar
# 15CO121
# 12/3/17
import os

def execute(command, input):
	fin = open('in', 'w')
	fin.write(input)
	fin.close()
	os.system('./' + command + ' < in > out')
	fout = open('out', 'r')
	out = fout.read()
	os.system('rm in')
	os.system('rm out')
	return out