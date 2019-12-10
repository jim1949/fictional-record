##  bito log upload(yugong)



愚公log上传脚本

1.download  the bash file:

```bash
#!/bin/bash
# yugong bito log upload shell

# All Rights Reserved BITO Robotics, Inc.
# Authors: Jimmy Jiao, RuiYuan Tian
# Create date: 2019-12-03
# Last Edit Date: 2019-12

# ===========================================================================================
# argument 1: group nicename
    # mp motion planning group

    # TODO:
    # slam slam group
    # iot iot group
    # web web group
# argument 2: log of number of days from now
# exmaple usage: 
#      bito_logload mp 2 

logpath=~/yugong_ws/src/yugong/yugong/log
logpah=~/yugong_ws/src/yugong/yugong/kblog
logpth=~/Downloads/log_folder
logph=~/Downloads
CURRENT_DATE_TIME=`date +"%Y%m%d_%I%M%S"`
function _bito_repo_management() {
    # arg_group_name=$1
    if [[ $1 = 'mp' ]] ; then 
        mp=(
            "node_simple_agent_2d_new"
            "node_local_plan_pipe_2d_new"
            "node_trajectory_tracker_2d"
            "node_start_agent_monitor"
            "to_ib_node"
            "to_usun_node"
        )
        echo "mo"
        echo ${mp[*]}
    elif [[ $1 = 'slam' ]] ; then
        slam=(
            "node_servo_all"
        )
        echo ${slam[*]}
    fi
}

function _bito_log_cp()
{
    cd $logpath
    arg_node_name=$1
    echo "copying log of $arg_node_name"
    find ./ -mtime -$2 |xargs -i cp  -r {} $logpah
    cd $logpah
    cp -r  $1.*  $logpth
}

function _bito_zip_file()
{
    cd $logph
    tar -zcvf log_folder_$1_$CURRENT_DATE_TIME.tar.gz log_folder --remove-files
    rm -rf $logpah
}

function bito_logload()
{
    echo $1
    array=$(_bito_repo_management $1)
    mkdir -p ~/yugong_ws/src/yugong/yugong/kblog
    mkdir -p ~/Downloads/log_folder
    for i in ${array[*]};
    do
        _bito_log_cp $i $2
    done
    _bito_zip_file $1
}
```

## 2. source the environment

```shell
source ~/Downloads/bito_log_upload.bash
```

## 3.run the command

if you want to upload about motion planning(mp) issue, and it's about recent 2 days(2 could be changed) log. Please run this command.

```
bito_logload mp 2
```

You will see your log file in ~/Downloads/, for example, log_folder_mp_20191203_034647.tar.gz.

