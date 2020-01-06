import rospy
from nav_msgs.msg import Odometry
from std_msgs.msg import Float32
import socketio
import json

sio = socketio.Client()

origin_topic_name = "/webslam/odom/filtered_test_origin"
recv_topic_name = "/webslam/odom/filtered_test_recv"
delay_name = "msg_delay"
pub_origin = rospy.Publisher(origin_topic_name, Odometry, queue_size=10)
pub_recv = rospy.Publisher(recv_topic_name, Odometry, queue_size=10)
pub_delay = rospy.Publisher(delay_name, Float32, queue_size=10)
rospy.init_node('test', anonymous=True)


def connect():
    print("I'm connected!")

@sio.event
def disconnect():
    print("I'm disconnected!")

@sio.on('odomFilteredReply')
def my_message(data):
    rate = rospy.Rate(50)
    while not rospy.is_shutdown():
        msg = json.loads(data.get("msg"))
        new_msg = Odometry()
        delay_msg = Float32()
        new_msg.header.seq = msg.get("header").get("seq")
        new_msg.header.stamp.secs = msg.get("header").get("stamp").get("secs")
        new_msg.header.stamp.nsecs = msg.get("header").get("stamp").get("nsecs")
        new_msg.header.frame_id = str(msg.get("header").get("frame_id"))
        new_msg.child_frame_id = str(msg.get("child_frame_id"))
        new_msg.pose.pose.position.x = msg.get("pose").get("pose").get("position").get("x")
        new_msg.pose.pose.position.y = msg.get("pose").get("pose").get("position").get("y")
        new_msg.pose.pose.position.z = msg.get("pose").get("pose").get("position").get("z")
        new_msg.pose.pose.orientation.x = msg.get("pose").get("pose").get("orientation").get("x")
        new_msg.pose.pose.orientation.y = msg.get("pose").get("pose").get("orientation").get("y")
        new_msg.pose.pose.orientation.z = msg.get("pose").get("pose").get("orientation").get("z")
        new_msg.pose.covariance = msg.get("pose").get("covariance")
        new_msg.twist.twist.linear.x = msg.get("twist").get("twist").get("linear").get("x")
        new_msg.twist.twist.linear.y = msg.get("twist").get("twist").get("linear").get("y")
        new_msg.twist.twist.linear.z = msg.get("twist").get("twist").get("linear").get("z")
        new_msg.twist.twist.angular.x = msg.get("twist").get("twist").get("angular").get("x")
        new_msg.twist.twist.angular.y = msg.get("twist").get("twist").get("angular").get("y")
        new_msg.twist.twist.angular.z = msg.get("twist").get("twist").get("angular").get("z")
        new_msg.twist.covariance = msg.get("twist").get("covariance")
        # print(new_msg)
        pub_origin.publish(new_msg)
        delay_msg.data = rospy.Time.now().to_sec() - new_msg.header.stamp.to_sec()
        new_msg.header.stamp = rospy.Time.now()
        pub_recv.publish(new_msg)
        pub_delay.publish(delay_msg)
        rate.sleep()

sio.connect('ws://192.168.1.71:8000')
sio.wait()

