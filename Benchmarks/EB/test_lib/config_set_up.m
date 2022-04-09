function [] = config_set_up(model)
activeConfigObj = getActiveConfigSet(model);
% disp(activeConfigObj);

% lls = fieldnames(activeConfigObj);
% lls = get_param(activeConfigObj, 'Components');
% lls = get_param(activeConfigObj, 'DialogParameters');
% lls = get(get_param(activeConfigObj,'handle'));

% for i=1:length(lls)
%     disp(lls(i));
% end

% data_io = lls(2);
% disp(data_io);
% fs = fieldnames(data_io);
% disp(fs);
Start_time = evalin('base','Start_time');
Stop_time = evalin('base','Stop_time');
Sample_time = evalin('base','Sample_time');
% disp('==== split line ====');
% disp('==== Setting up config, please wait ... ====');
% disp(properties(activeConfigObj));
% disp(isprop(activeConfigObj,'StartTime'));
% disp(fieldnames(activeConfigObj));
% disp(fieldnames(activeConfigObj));
% for i=1:length(activeConfigObj.Components)
%     disp(activeConfigObj.Components(i));
% end
% disp(fieldnames(activeConfigObj.Components(1)));
% disp(activeConfigObj.Components(1).Name);
% disp(get_param(activeConfigObj,'FixedStep'));
% disp(get_param(activeConfigObj,'Solver'));
if evalin('base','origin_config_ok')
    set_param(activeConfigObj,'StartTime',char(num2str(Start_time)));
    set_param(activeConfigObj,'StopTime',char(num2str(Stop_time)));
    set_param(activeConfigObj,'Solver','FixedStepAuto');
    set_param(activeConfigObj,'SolverType','Fixed-step');
    set_param(activeConfigObj,'FixedStep',char(num2str(Sample_time)));
end

lei = get_param(activeConfigObj, 'LoadExternalInput');
if strcmp(lei, 'off')
    set_param(activeConfigObj, 'LoadExternalInput', 'on');
end
set_param(activeConfigObj, 'ExternalInput', 'aoe_tsinghua_mhi_data');
% disp(get_param(activeConfigObj, 'ExternalInput'));

save_system(model);

% disp(lei);
% disp('==== config has been set up ====');

% lls = get_param(activeConfigObj, 'ExternalInput');

% a = instrument_s_functions(model);
end

