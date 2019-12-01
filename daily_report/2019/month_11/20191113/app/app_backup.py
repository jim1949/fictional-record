#!/usr/bin/env python
from flask import Flask, render_template, Response, request
import os

app = Flask(__name__)


@app.route('/')
def index():
    """Frontpage"""
    return render_template('index.html')

#robot 001
@app.route('/aIn', methods=['POST', 'GET'])
def ain():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311 && rosservice call /yg00a00019052413000n00/shelves_up_cmd_srv  1")  
    return (''),204

@app.route('/aOut', methods=['POST', 'GET'])
def aout():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311 && rosservice call /yg00a00019052413000n00/shelves_up_cmd_srv  2")  
    return (''),204

@app.route('/aStop', methods=['POST', 'GET'])
def astop():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311 && rosservice call /yg00a00019052413000n00/stop_conveying 0 0 1 0")
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311 && rosservice call /yg00a00019052413000n00/shelves_up_cmd_srv  0")  
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311 && rosservice call /yg00a00019052413000n00/stop_conveying 0 0 2 0")  
    return (''),204


# robot 002 
@app.route('/bIn', methods=['POST', 'GET'])
def bin():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311 && rosservice call /yg00a00019101413000n00/shelves_up_cmd_srv  1")
    return (''),204

@app.route('/bOut', methods=['POST', 'GET'])
def bout():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311 && rosservice call /yg00a00019101413000n00/shelves_up_cmd_srv  2")  
    return (''),204

@app.route('/bStop', methods=['POST', 'GET'])
def bstop():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311 && rosservice call /yg00a00019101413000n00/stop_conveying 0 0 1 0")  
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311 && rosservice call /yg00a00019101413000n00/shelves_up_cmd_srv  0")  
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311 && rosservice call /yg00a00019101413000n00/stop_conveying 0 0 2 0")  
    return (''),204

if __name__ == '__main__':
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311 && rosservice call /yg00a00019052413000n00/stop_conveying 0 0 1 0")
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311 && rosservice call /yg00a00019101413000n00/stop_conveying 0 0 1 0")  
    app.run(host='0.0.0.0',port=1234, debug=False, threaded=True)
