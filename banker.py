# Hrishikesh Hiraskar
# 15CO121
# 3/4/17
from subprocess import Popen, PIPE
import time, sys

p = None

def init():
	global p
	print "Initializing Banker program"
	p = Popen(['./banker/banker'], stdin=PIPE, stdout=PIPE)

def execute(com):
	global p
	p.stdin.write(com+'\n'.encode())
	p.stdin.flush()
	time.sleep(0.1)
	out = p.stdout.readline()
	print out
	p.stdout.flush();
	if len(out)>1 and out[-1]=='\n' and out[-2]=='\n':
		out = out[:-1]
	if len(out):
		return out.replace('<br>', '\n')[:-1]
	return ""