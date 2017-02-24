from subprocess import Popen, PIPE
import time, sys

p = None

def init():
	global p
	print "Initializing shell"
	p = Popen(['./file_system/file_system'], stdin=PIPE, stdout=PIPE)

def execute(com):
	global p
	p.stdin.write(com+'\n'.encode())
	p.stdin.flush()
	time.sleep(0.1)
	out = p.stdout.readline()
	p.stdout.flush();
	if len(out)>0 and out[-1]=='\n':
		out = out[:-1]
	if len(out):
		return out.replace('<br>', '\n')[:-1]
	return ""