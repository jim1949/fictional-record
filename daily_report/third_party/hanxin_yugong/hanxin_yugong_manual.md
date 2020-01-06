# yugong_hanxin manual

## 1. yugong

```shell
roslaunch memoon forklift_in_usun_factory.launch
```

```
roslaunch yugong sim_forklift_monitor.launch
```



## 2. hanxin

hanxin:

```
roslaunch hanxin node_factory_server_2d.launch
roslaunch hanxin factory_monitor.launch
```

web:

```
sudo supervisorctl restart all
cd ros_packages
sudo docker-compose restart
```

