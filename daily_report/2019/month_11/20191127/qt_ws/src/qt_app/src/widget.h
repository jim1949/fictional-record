#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>

#include <ros/ros.h>
#include <tf/transform_datatypes.h>
#include <boost/thread.hpp>



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    bool goal_is_null;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    
    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
