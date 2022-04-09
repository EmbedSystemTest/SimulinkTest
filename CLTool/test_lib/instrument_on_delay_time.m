function [is_code] = instrument_on_delay_time(code,ele_name,s_index,mode)

instrument_s_flag = evalin('base', 'instrument_s_flag');

code_ini = "coder.extrinsic('run_info_recorder','extract_specified_element');";
code_record = strcat('run_info_recorder(extract_specified_element(',ele_name,',',s_index,'),',mode,');');

codes = strsplit(code, '\n');
c_end = length(codes);
idx = -1;
for i=1:c_end
    one = codes(i);
    idxs = regexpi(char(one), '^function((\s+\S+)|(\s*[))');
    if ~isempty(idxs)
%         r_idxs = regexpi(one, '(?<=]\s*\=\s*).+');
%         disp(r_idxs);
%         disp(one(r_idxs(1):length(one)));
        idx = i;
    end
%     disp(idxs);
%     s=s+v(i);
end
is_codes = codes;
if idx > -1
    should_cide_ini_code = strtrim(codes(idx+1));
    if ~strcmp(should_cide_ini_code,code_ini)
        switch instrument_s_flag
        case 1
            is_codes = [codes(1:idx) code_ini code_record codes(idx+1:c_end)];
        case 2
            is_codes = [codes(1:idx) codes(idx+1:c_end)];
        end
    else
        switch instrument_s_flag
        case 1
            is_codes = [codes(1:idx) code_ini code_record codes(idx+3:c_end)];
        case 2
            is_codes = [codes(1:idx) codes(idx+3:c_end)];
        end
    end
end
% is_code = code;
% disp(class(code));
% disp(code);
% disp(is_codes);
% disp(char(join(is_codes,'\n')));
f_is_code = char(is_codes(1));
for i=2:length(is_codes)
    f_is_code = sprintf('%s\n%s',char(f_is_code),char(is_codes(i)));
end
% disp(f_is_code);
is_code = f_is_code;



