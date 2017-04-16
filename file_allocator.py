# Hrishikesh Hiraskar
# 15CO121
# 29/3/17
from subprocess import Popen, PIPE
import time, sys

con = None
lin = None
ind = None
mvt = None
mft = None

def init(i):
	global con, lin, ind, mvt, mft
	print "Initializing file allocation program"
	if   i == 1:
		con = Popen(['./file_alloc/contiguous'], stdin=PIPE, stdout=PIPE)
	elif i == 2:
		lin = Popen(['./file_alloc/linked'], stdin=PIPE, stdout=PIPE)
	elif i == 3:
		ind = Popen(['./file_alloc/indexed'], stdin=PIPE, stdout=PIPE)
	elif i == 4:
		mvt = Popen(['./multitasking_memory_management/mvt'], stdin=PIPE, stdout=PIPE)
	elif i == 5:
		mft = Popen(['./multitasking_memory_management/mft'], stdin=PIPE, stdout=PIPE)

def execute(i, com):
	global con, lin, ind
	if   i == 1:
		return execute_com(con, com)
	elif i == 2:
		return execute_com(lin, com)
	elif i == 3:
		return execute_com(ind, com)
	elif i == 4:
		return execute_com(mvt, com)
	elif i == 5:
		return execute_com(mft, com)

def execute_com(p, com):
	p.stdin.write(com+'\n'.encode())
	p.stdin.flush()
	time.sleep(0.1)
	out = p.stdout.readline()
	p.stdout.flush();
	if len(out)>1 and out[-1]=='\n' and out[-2]=='\n':
		out = out[:-1]
	if len(out):
		return out.replace('<br>', '\n')[:-1]
	return ""