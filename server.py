# Hrishikesh Hiraskar
# 15CO121
# 12/3/17
import gevent
import time
import os
import threading
import shell, executer
from gevent import monkey
from gevent.pywsgi import WSGIServer
from flask import Flask, request, Response, render_template, send_from_directory

monkey.patch_all(aggressive=False)

import subprocess

app = Flask(__name__, static_folder='webapp/')

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

@app.route('/disk_scheduling/schedule', methods=['POST', 'GET'])
def disk_schedule():
	scheduling = ['fcfs', 'sstf', 'scan', 'c_scan'. 'look', 'c_look']
	inp = request.args['input']
	print inp
	out = ""
	for algo in scheduling:
		out += executer.execute('disk_scheduling/'+algo, inp)
	return out

@app.route('/disk_scheduling')
def page_disk_scheduling():
	return app.send_static_file('disk_scheduling.html')


@app.route('/process_scheduling/schedule', methods=['POST', 'GET'])
def process_schedule():
	scheduling = ['fcfs', 'rr', 'sjf', 'non_preemptive', 'srtf', 'preemptive']
	inp = request.args['input']
	out = ""
	for algo in scheduling:
		out += executer.execute('process_scheduling/'+algo, inp);
	return out

@app.route('/process_scheduling')
def page_process_scheduling():
	return app.send_static_file('process_scheduling.html')

@app.route('/<path:path>')
def static_file(path):
	return app.send_static_file(path)

if __name__ == '__main__':
	# Set server address 127.0.0.1:8000/
	app.run(host="127.0.0.1", port=8000);
	http_server = WSGIServer(app)
	http_server.serve_forever()
