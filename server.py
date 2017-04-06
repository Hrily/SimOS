# Hrishikesh Hiraskar
# 15CO121
# 12/3/17
import gevent
import time
import os
import threading
import shell, executer, file_allocator, banker
from gevent import monkey
from gevent.pywsgi import WSGIServer
from flask import Flask, request, Response, render_template, send_from_directory

monkey.patch_all(aggressive=False)

import subprocess

app = Flask(__name__, static_folder='webapp/')

# Terminal
@app.route('/terminal/shellcommand', methods=['POST', 'GET'])
def shell_command():
	com = request.args['command']
	print com
	out = shell.execute(com)
	print out
	return out

@app.route('/terminal')
def page_terminal():
	shell.init()
	return app.send_static_file('terminal.html')

# Disk Scheduling
@app.route('/disk_scheduling/schedule', methods=['POST', 'GET'])
def disk_schedule():
	scheduling = ['fcfs', 'sstf', 'scan', 'c_scan', 'look', 'c_look']
	inp = request.args['input']
	print inp
	out = ""
	for algo in scheduling:
		out += executer.execute('disk_scheduling/'+algo, inp)
	return out

@app.route('/disk_scheduling')
def page_disk_scheduling():
	return app.send_static_file('disk_scheduling.html')

# Process Scheduling
@app.route('/process_scheduling/schedule', methods=['POST', 'GET'])
def process_schedule():
	scheduling = ['fcfs', 'rr', 'sjf', 'non_preemptive', 'srtf', 'preemptive']
	inp = request.args['input']
	out = ""
	for algo in scheduling:
		out += executer.execute('process_scheduling/'+algo, inp)
	return out

@app.route('/process_scheduling')
def page_process_scheduling():
	return app.send_static_file('process_scheduling.html')

# File Alloction
@app.route('/file_allocation/execute', methods=['POST', 'GET'])
def file_allocation():
	inp = request.args['input']
	out = file_allocator.execute(inp)
	return out

@app.route('/contigous_file_allocation')
def page_contigous_file_allocation():
	file_allocator.init(1)
	return app.send_static_file('file_allocation.html')

@app.route('/file_allocation', methods=['POST', 'GET'])
def page_file_allocation():
	inp = request.args['input']
	if inp == 'contigous':
		inp = 1
	else:
		inp = 0
	file_allocator.init(inp)
	return app.send_static_file('file_allocation.html')

# Bankers
@app.route('/banker/execute', methods=['POST', 'GET'])
def deadlock():
	inp = request.args['input']
	out = banker.execute(inp)
	return out

@app.route('/banker')
def page_deadlock():
	banker.init()
	return app.send_static_file('deadlock.html')

# Dining Philosopher
@app.route('/dining/execute', methods=['POST', 'GET'])
def dining():
	inp = request.args['input']
	out = executer.execute('process_sync/dining', inp)
	return out

@app.route('/dining')
def page_dining():
	shell.init()
	return app.send_static_file('dining.html')


@app.route('/<path:path>')
def static_file(path):
	return app.send_static_file(path)

if __name__ == '__main__':
	# Set server address 127.0.0.1:8000/
	app.run(host="127.0.0.1", port=8000);
	http_server = WSGIServer(app)
	http_server.serve_forever()
