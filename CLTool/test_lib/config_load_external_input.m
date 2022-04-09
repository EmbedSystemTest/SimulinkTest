function [] = config_load_external_input(model)
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

% disp('==== split line ====');
disp('==== setting up external input config, please wait ... ====');
lei = get_param(activeConfigObj, 'LoadExternalInput');
if strcmp(lei, 'off')
    set_param(activeConfigObj, 'LoadExternalInput', 'on');
    save_system(model);
end
% disp(lei);
disp('==== config external input set up ====');

% lls = get_param(activeConfigObj, 'ExternalInput');

% a = instrument_s_functions(model);
end

