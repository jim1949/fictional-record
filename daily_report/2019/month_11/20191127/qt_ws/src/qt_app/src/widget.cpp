#include "widget.h"
#include "ui_widget.h"



#define garage_1_x 3.02
#define garage_1_y -1.01
#define garage_1_z -0.67
#define garage_1_w 0.75

#define garage_2_x 2.73
#define garage_2_y -1.07
#define garage_2_z -0.67
#define garage_2_w 0.75

#define garage_3_x 0.09
#define garage_3_y -1.68
#define garage_3_z 0.75
#define garage_3_w 0.66

#define garage_4_x -0.21
#define garage_4_y -1.72
#define garage_4_z 0.75
#define garage_4_w 0.66

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    goal_is_null(true)
{

    QFrame *frame=new QFrame(this,Qt::Widget);//在头文件中定义frame

    frame->setObjectName("myframe");

    frame->resize(476,581);

    frame->setStyleSheet("QFrame#myframe{border-image:url(/home/ubuntu/1.jpg)}");

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // if(!goal_is_null)
    // {
    //   ac.cancelGoal();
    //   goal_is_null = false;
    // }
    // current_goal.target_pose.header.frame_id = "map";
    // current_goal.target_pose.header.stamp = ros::Time::now();
    // current_goal.target_pose.pose.position.x = garage_1_x;
    // current_goal.target_pose.pose.position.y = garage_1_y;
    // current_goal.target_pose.pose.orientation.z = garage_1_z;
    // current_goal.target_pose.pose.orientation.w = garage_1_w;


    // ROS_INFO("garage_1");
    // ac.sendGoal(current_goal);
}

void Widget::on_pushButton_2_clicked()
{

    //  if(!goal_is_null)
    // {
    //   ac.cancelGoal();
    //   goal_is_null = false;
    // }
    // current_goal.target_pose.header.frame_id = "map";
    // current_goal.target_pose.header.stamp = ros::Time::now();
    // current_goal.target_pose.pose.position.x = garage_2_x;
    // current_goal.target_pose.pose.position.y = garage_2_y;
    // current_goal.target_pose.pose.orientation.z = garage_2_z;
    // current_goal.target_pose.pose.orientation.w = garage_2_w;

    // ROS_INFO("garage_2");
    // ac.sendGoal(current_goal);
}


void Widget::on_pushButton_3_clicked()
{

    //  if(!goal_is_null)
    // {
    //   ac.cancelGoal();
    //   goal_is_null = false;
    // }
    // current_goal.target_pose.header.frame_id = "map";
    // current_goal.target_pose.header.stamp = ros::Time::now();
    // current_goal.target_pose.pose.position.x = garage_3_x;
    // current_goal.target_pose.pose.position.y = garage_3_y;
    // current_goal.target_pose.pose.orientation.z = garage_3_z;
    // current_goal.target_pose.pose.orientation.w = garage_3_w;

    // ROS_INFO("garage_3");
    // ac.sendGoal(current_goal);

}

void Widget::on_pushButton_4_clicked()
{

    //  if(!goal_is_null)
    // {
    //   ac.cancelGoal();
    //   goal_is_null = false;
    // }
    // current_goal.target_pose.header.frame_id = "map";
    // current_goal.target_pose.header.stamp = ros::Time::now();
    // current_goal.target_pose.pose.position.x = garage_4_x;
    // current_goal.target_pose.pose.position.y = garage_4_y;
    // current_goal.target_pose.pose.orientation.z = garage_4_z;
    // current_goal.target_pose.pose.orientation.w = garage_4_w;

    // ROS_INFO("garage_4");
    // ac.sendGoal(current_goal);

}
