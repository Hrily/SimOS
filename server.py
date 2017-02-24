import gevent
import time
import os
import threading
import shell
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
def page():
	shell.init()
	return app.send_static_file('terminal.html')

@app.route('/<path:path>')
def static_file(path):
	return app.send_static_file(path)

if __name__ == '__main__':
	# Set server address 127.0.0.1:8001/
	app.run(host="127.0.0.1", port=8000);
	http_server = WSGIServer(app)
	http_server.serve_forever()
