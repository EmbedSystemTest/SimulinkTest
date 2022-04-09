function [func_name] = extract_function_name(scpt)
% disp(scpt);
func_name = "";
codes = strsplit(scpt, '\n');
c_end = length(codes);
for i=1:c_end
    one = strtrim(codes(i));
%     disp(strcat(one, "===="));
    idxs = regexpi(char(one), '^function((\s+\S+)|(\s*[))');
    if ~isempty(idxs)
        r_cnts = regexp(char(one), '(?<=\s*\=\s*)\S+(?=\s*\(.+)', 'match');
%         disp(r_cnts);
%         disp(length(r_cnts));
        assert(length(r_cnts) == 1);
        func_name = r_cnts(1);
    end
end
% disp(strcat(func_name, "====func_name"));
assert(~strcmp(func_name,""));
% one = "function [func_name] = extract_function_name(scpt)";
% % regexpi(one,'(?<=floor_num":2).*?(?=floor_num":3)','match');
% r_idxs = regexpi(one, '(?<=]\s*\=\s*)\S+\((?=.+)');
% % disp(r_idxs);
% % disp(r_idxs(1));
% % disp(strlength(one));
% ocs = char(one);
% two = ocs(r_idxs(1):strlength(one));
% disp(two);
end

