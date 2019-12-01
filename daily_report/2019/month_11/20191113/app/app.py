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
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311")  
    return (''),204

@app.route('/aOut', methods=['POST', 'GET'])
def aout():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311")  
    return (''),204

@app.route('/aStop', methods=['POST', 'GET'])
def astop():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311")
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311")  
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311")  
    return (''),204

#robot 001
@app.route('/aIn2', methods=['POST', 'GET'])
def ain2():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311")  
    return (''),204

@app.route('/aOut2', methods=['POST', 'GET'])
def aout2():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311")  
    return (''),204

@app.route('/aStop2', methods=['POST', 'GET'])
def astop2():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311")
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311")  
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311")  
    return (''),204


# robot 002 
@app.route('/bIn', methods=['POST', 'GET'])
def bin2():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311")
    return (''),204

@app.route('/bOut', methods=['POST', 'GET'])
def bout2():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311")  
    return (''),204

@app.route('/bStop', methods=['POST', 'GET'])
def bstop2():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311")  
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311")  
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311")  
    return (''),204

# robot 002 
@app.route('/bIn2', methods=['POST', 'GET'])
def bin():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311")
    return (''),204

@app.route('/bOut2', methods=['POST', 'GET'])
def bout():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311")  
    return (''),204

@app.route('/bStop2', methods=['POST', 'GET'])
def bstop():
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311")  
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311")  
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311")  
    return (''),204

if __name__ == '__main__':
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.4:11311")
    a = os.system(r"export ROS_MASTER_URI=http://192.168.3.15:11311")  
    app.run(host='0.0.0.0',port=1234, debug=False, threaded=True)
