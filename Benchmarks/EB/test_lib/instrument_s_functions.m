function [] = instrument_s_functions(model, s_config)

% bcs = Simulink.findBlocks(model,'Name','ONDLC');
% disp(getfullname(bcs));

s_funcs = Simulink.findBlocksOfType(model,'S-Function');
% disp(getfullname(s_funcs));
sf = sfroot();
for i = 1:length(s_funcs)
    s_fun = s_funcs(i);
%     disp(get_param(s_fun, 'Name'));
    a = getfullname(s_fun);
    % disp(a);
    % 'simeventslib/Attributes/Attribute Function/MATLAB Function/ SFunction '
    sysAF = find_system(a,'LookUnderMasks','all');
    AFsFcn = get(cell2mat(get_param(sysAF,'handle')));
%     disp(AFsFcn.Path);
    to_instruct = 0;
    ele_name = "";
    s_index = "";
    mode = "";
%     disp(length(s_config));
    HsFcn = sf.find('Path',AFsFcn.Path,'-isa','Stateflow.EMChart');
    func_name = extract_function_name(HsFcn.Script);
    for j = 1:length(s_config)
        o_conf = s_config(j);
        o_conf = o_conf{1};
        name_reg = o_conf(1);
%         disp(AFsFcn.Path);
%         disp(name_reg);
%         disp(func_name);
        if ~isempty(regexp(char(func_name),char(name_reg),'match'))
            assert(to_instruct == 0, ['Wrong!' ' ' 'more than one match!',' func_name:',char(func_name),' name_reg:',char(name_reg)]);
            to_instruct = 1;
            ele_name = o_conf(2);
%             ele_name = ele_name{1};
            s_index = o_conf(3);
%             s_index = s_index{1};
            mode = o_conf(4);
        end
    end
    if to_instruct
        disp(strcat("Discover and Handle m function: ", AFsFcn.Path, '/', char(func_name)));
        HsFcn.Script = instrument_on_delay_time(HsFcn.Script, ele_name, s_index, mode);
    end
%     disp(HsFcn);
%     HsFcn.Script = strcat(HsFcn.Script, 'hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh');
end

save_system(model);

% see 
% a = bcs(3);

% disp(getfullname(a));
% 
% dialogPrms = get_param(a, 'ObjectParameters');
% dialogPrmNames = fieldnames(dialogPrms);
% disp(dialogPrmNames);
% 
% for idx = 1:numel(dialogPrmNames)
%    dialogPrmValue = get_param(a, dialogPrmNames{idx});
%    disp(dialogPrmNames{idx});
%    disp(dialogPrmValue);
% end

% p_n = get_param(a,'FunctionName');
% disp(p_n);

end

