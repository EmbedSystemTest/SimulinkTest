
%var.signals(1).values = 0 ;  % tank1_liquid_height_m                             
%var.signals(2).values = 0 ;  % tank2_liquid_height_m                                   
%var.signals(3).values = 0 ;  % tank1_pump_initial_state
%var.signals(4).values = 0 ;  % tank1_valve_initial_state                           
%var.signals(5).values = 0 ;  % tank2_p_valve_initial_state                               
%var.signals(6).values = 0 ;  % tank2_e_valve_initial_state                             

%save var_tt.mat var;                                            
%load('var_tt.mat', 'var');

curPath=fileparts(which('twotanks.m')); 
modelpath = strrep(curPath,'SimulinkModels/10_twotank','SimulinkModels/10_twotank/');
open_system(strcat(modelpath,'basictwotanks.slx'));
cs = getActiveConfigSet('basictwotanks');
model_cs = cs.copy;
set_param(model_cs,'MaxDataPoints' ,' off',  'FixedStep', '0.1', 'LimitDataPoints', 'off', 'ReturnWorkspaceOutputs','on','SaveOutput','on', 'OutputSaveName', 'varout', 'StartTime', '0' , 'StopTime', '500');
%paramValue = get_param('model_cs/My Constant','Value')          
simOut = sim('basictwotanks.slx', model_cs);
varout=simOut.get('varout');

tank1_liquid_height_m = varout.signals(1).values;
tank2_liquid_height_m = varout.signals(2).values;

t = varout.time;

plot(t,tank1_liquid_height_m,t,tank2_liquid_height_m);
title('twotanks'); xlabel('Time'); legend('tank1 liquid height','tank2 liquid height');