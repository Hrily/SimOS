# Hrishikesh Hiraskar
# 15CO121
# 29/3/17
from subprocess import Popen, PIPE
import time, sys

p = None

def init(i):
	global p
	print "Initializing file allocation program"
	if i == 1:
		p = Popen(['./file_alloc/contiguous'], stdin=PIPE, stdout=PIPE)
	else:
		p = Popen(['./file_alloc/contiguous'], stdin=PIPE, stdout=PIPE)

def execute(com):
	global p
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