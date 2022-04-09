function [ constant_model, branch_model ] = parse_branch_info( rinfo )
    constant_model = containers.Map;
    branch_model = containers.Map;
    rs = strsplit(rinfo, '$');
    for i=1 : length(rs)
        r = rs(1, i);
        r = char(r);
        if ~isempty(r)
%             disp(class(r));
            b_info = strsplit(r, '#');
%             disp(b_info);
            branch = char(b_info(1));
%             disp('branch');
%             disp(branch);
            bs = str2num(branch);
%             disp('bs');
%             disp(bs);
            for j=1:length(bs)
                b_j = num2str(bs(j));
%                 disp('b_j');
%                 disp(b_j);
                if length(b_info) == 2
                    if ~constant_model.isKey(b_j)
                        constant_model(b_j) = [];
                    end
                    tb_v = str2double(char(b_info(2)));
                    constant_model(b_j) = [constant_model(b_j) tb_v];
                else
                    if ~branch_model.isKey(b_j)
                        branch_model(b_j) = [];
                    end
                    v1 = str2double(char(b_info(2)));
                    v2 = str2double(char(b_info(3)));
                    branch_model(b_j) = [branch_model(b_j) {v1, v2}];
                end
            end
        end
    end
    key_set = keys(constant_model);
    for i=1:length(key_set)
        key = key_set{i};
        uniqued_consts = unique(constant_model(key));
        constant_model(key) = uniqued_consts;
    end
%     disp(pmodel('a'));
end

