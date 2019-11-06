## issue 3424

### 1) node_simple_agent_2d

 Single agent received a trajectory and action task, with the goal pose at (1.8, -1.57, -1.4508)

```shell
recv tasksimplex, size = 7, id = 31, type = 11, cached = 0
I1023 11:09:30.056860 17434 node_simple_agent_2d_new.h:343] Start x = 8.4, y = -2.08, theta =-3.0216
I1023 11:09:30.056872 17434 node_simple_agent_2d_new.h:350] Dest x = 1.7956, y = -1.5707 theta = -1.4507
I1023 11:09:30.056879 17434 node_simple_agent_2d_new.h:358]  AGT idx [0] 8.4,-2.08,-3.0216.
I1023 11:09:30.056885 17434 node_simple_agent_2d_new.h:358]  AGT idx [1] 8.4,-2.08,1.6908.
I1023 11:09:30.056892 17434 node_simple_agent_2d_new.h:358]  AGT idx [2] 5.67,-1.1,-3.0216.
I1023 11:09:30.056898 17434 node_simple_agent_2d_new.h:358]  AGT idx [3] 4.38,-1.26,-3.0216.
I1023 11:09:30.056905 17434 node_simple_agent_2d_new.h:358]  AGT idx [4] 3.09,-1.42,-3.0216.
I1023 11:09:30.056910 17434 node_simple_agent_2d_new.h:358]  AGT idx [5] 1.8,-1.57,-3.0216.
I1023 11:09:30.056916 17434 node_simple_agent_2d_new.h:358]  AGT idx [6] 1.8,-1.57,-1.4508.
I1023 11:09:30.056980 17434 node_simple_agent_2d_new.h:279] recv valid Hanxin task simplex
I1023 11:09:30.056987 17434 node_simple_agent_2d_new.cpp:191] Task simplex valid
I1023 11:09:30.056990 17434 node_simple_agent_2d_new.h:307] This is Traj+(Action) task.
I1023 11:09:30.057000 17434 node_simple_agent_2d_new.h:323] continue task
I1023 11:09:30.390040 17434 node_simple_agent_2d_new.cpp:397] AGT-CAS current status:    RunTraj
I1023 11:09:30.390087 17434 node_simple_agent_2d_new.cpp:1057] AGT-PUBAT publish path points size 7
I1023 11:09:30.390092 17434 node_simple_agent_2d_new.cpp:1063] AGT-ProcTraj srv call count = 0
I1023 11:09:30.567767 17434 node_simple_agent_2d_new.cpp:1071] AGT-COM process traj confirm(1)
```

When executing the action , the single agent always received the next task from hanxin system and yugong refused, until the single agent received the task below, firstly it received a cached task with goal pose at (7.4251, -4.8201, 1.6907), then a non-cached task and refused.



```shell
recv tasksimplex, size = 4, id = 32, type = 12, cached = 1
I1023 11:10:49.723439 17434 node_simple_agent_2d_new.h:343] Start x = 1.8, y = -1.57, theta =-1.4508
I1023 11:10:49.723448 17434 node_simple_agent_2d_new.h:350] Dest x = 7.4251, y = -4.8201 theta = 1.6907
I1023 11:10:49.723451 17434 node_simple_agent_2d_new.h:358]  AGT idx [0] 1.8,-1.57,-1.4508.
I1023 11:10:49.723455 17434 node_simple_agent_2d_new.h:358]  AGT idx [1] 1.95,-2.86,-1.4508.
I1023 11:10:49.723459 17434 node_simple_agent_2d_new.h:358]  AGT idx [2] 2.11,-4.15,-1.4508.
I1023 11:10:49.723462 17434 node_simple_agent_2d_new.h:358]  AGT idx [3] 4.84,-5.13,0.12.
I1023 11:10:49.723503 17434 node_simple_agent_2d_new.h:307] This is Traj+(Action) task.
I1023 11:10:49.723510 17434 node_simple_agent_2d_new.h:313] no-continue task
I1023 11:10:49.723613 17434 node_simple_agent_2d_new.h:332] 
recv tasksimplex, size = 0, id = 32, type = 12, cached = 0
I1023 11:10:49.723618 17434 node_simple_agent_2d_new.h:350] Dest x = 7.4251, y = -4.8201 theta = 1.6907
W1023 11:10:49.723634 17434 node_simple_agent_2d_new.h:249] refuse Hanxin task simplex, because a cached task simplex is waiting in queue.
I1023 11:10:49.723655 17434 node_simple_agent_2d_new.cpp:185] Task simplex not valid
I1023 11:10:50.056710 17434 node_simple_agent_2d_new.cpp:397] AGT-CAS current status:    RunTraj
I1023 11:10:50.056722 17434 node_simple_agent_2d_new.cpp:472] cached = 1
I1023 11:10:50.056737 17434 node_simple_agent_2d_new.cpp:1057] AGT-PUBAT publish path points size 4
I1023 11:10:50.056740 17434 node_simple_agent_2d_new.cpp:1063] AGT-ProcTraj srv call count = 0
I1023 11:10:50.151363 17434 node_simple_agent_2d_new.cpp:1071] AGT-COM process traj confirm(1)
I1023 11:10:50.151376 17434 node_simple_agent_2d_new.cpp:479] cached changed to false
I1023 11:10:50.151484 17434 node_simple_agent_2d_new.h:332] 

```

Then hanxin system received a pure action task, this action task didn't have any trajectory points, and the task will be replaced immediately and it has to execute the hanxin task with goal at （7.4251，-4.8201, 1.6907), which caused the issue that performer executed a task which is far away from the current pose. (1.8, -1.57, -1.4508)

```shell
...

recv tasksimplex, size = 0, id = 32, type = 12, cached = 0
I1023 11:10:50.151489 17434 node_simple_agent_2d_new.h:350] Dest x = 7.4251, y = -4.8201 theta = 1.6907
I1023 11:10:50.151525 17434 node_simple_agent_2d_new.h:279] recv valid Hanxin task simplex
I1023 11:10:50.151530 17434 node_simple_agent_2d_new.cpp:191] Task simplex valid
I1023 11:10:50.151532 17434 node_simple_agent_2d_new.h:290] This is Action task, type(12)
I1023 11:10:50.151547 17434 node_simple_agent_2d_new.h:378] process Event
I1023 11:10:50.390041 17434 node_simple_agent_2d_new.cpp:408] AGT-CAS current status:  RunAction
I1023 11:10:50.546156 17434 node_simple_agent_2d_new.cpp:498]  AGT call node local plan pipe reset srv successfully
I1023 11:10:50.546191 17434 node_simple_agent_2d_new.cpp:741] AGT-Proc Action()
I1023 11:10:50.549167 17434 node_simple_agent_2d_new.cpp:908] AGT-Proc fork lift
I1023 11:10:50.549180 17434 node_simple_agent_2d_new.cpp:1002] AGT-Proc Lift height = 0
I1023 11:10:50.549188 17434 node_simple_agent_2d_new.cpp:1012] AGT-Proc srv call count = 0 obj type(deepsea-P-001)
I1023 11:10:50.617691 17434 node_simple_agent_2d_new.cpp:1022] AGT-COM process action connected(1)
I1023 11:10:50.617700 17434 node_simple_agent_2d_new.cpp:1029] AGT-COM process action confirm(1)
I1023 11:10:50.617704 17434 node_simple_agent_2d_new.cpp:1035] AGT-Proc Action robot_pose xytheta: 7.4251 -4.8201 1.6907
I1023 11:10:50.617717 17434 node_simple_agent_2d_new.cpp:1037] AGT-Proc Action object_pose: 7.64041 -6.60718 1.6907
I1023 11:10:50.617722 17434 node_simple_agent_2d_new.cpp:1039] AGT-Proc Action object type(deepsea-P-001), pallet_called(1)
I1023 11:10:50.617727 17434 node_simple_agent_2d_new.cpp:512] AGT-PUBAT ASID_RunAction: Lift or Charge
I1023 11:10:50.617784 17434 node_simple_agent_2d_new.cpp:214] AGT-CTrajFb : pause state changed
I1023 11:10:50.617795 17434 node_simple_agent_2d_new.cpp:219] AGT-CTrajFb : paused 
I1023 11:10:50.617853 17434 node_simple_agent_2d_new.cpp:219] AGT-CTrajFb : paused 
I1023 11:10:50.723376 17434 node_simple_agent_2d_new.cpp:408] AGT-CAS current status:  RunAction
I1023 11:10:50.723418 17434 node_simple_agent_2d_new.cpp:219] AGT-CTrajFb : paused 
I1023 11:10:50.723443 17434 node_simple_agent_2d_new.cpp:219] AGT-CTrajFb : paused 
I1023 11:10:51.056706 17434 node_simple_agent_2d_new.cpp:408] AGT-CAS current status:  RunAction
I1023 11:10:51.056764 17434 node_simple_agent_2d_new.cpp:214] AGT-CTrajFb : pause state changed
I1023 11:10:51.390046 17434 node_simple_agent_2d_new.cpp:408] AGT-CAS current status:  RunAction

...

I1023 11:20:16.056715 17434 node_simple_agent_2d_new.cpp:408] AGT-CAS current status:  RunAction
I1023 11:20:16.056825 17434 node_simple_agent_2d_new.cpp:108] reset srv called.
I1023 11:20:16.056836 17434 node_simple_agent_2d_new.cpp:308] AGT-RESET reset
```

### 2) Conclusion

Please check why the hanxin system sent a pure action task to the single agent even if the single agent is in RunTaskTraj state.

