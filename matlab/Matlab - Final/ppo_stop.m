function ppo_stop
global ppo;
BrakeAll;
stop(ppo);
delete(ppo);
clear ppo