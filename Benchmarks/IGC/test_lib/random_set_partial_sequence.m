function [ ret ] = random_set_partial_sequence( t_data, constant_model )
    ret = t_data;
    if isempty(constant_model)
%         disp('== partial set not executed! ==');
        return;
    end
    
    cks = keys(constant_model);
    to_skip = 0;
    if length(cks) == 1
        to_skip = 1;
    end
    Sample_time = evalin('base', 'Sample_time');
    td_len = size(t_data);
    td_len = td_len(1);
    start = 1;
    while 1
%         m = rem(i, 2);
%         if m == 0
%             s = int32(random_element_from_two_sets(f_set, randi([1, 5]), 1)/Sample_time);
%         else
%             s = int32(random_element_from_two_sets(t_set, randi([1, 5]), 1)/Sample_time);
%         end
        ck = random_element_from_set(cks, 1);
        ck = ck{1};
%         disp('== ==');
%         disp(cks);
%         disp('|| ||');
%         disp(class(ck));
%         disp(ck);
%         disp(class(ck{1}));
%         disp(ck{1});
        s = int32(random_element_from_two_sets(constant_model(ck), randi([1, td_len]), 1)/Sample_time);
        e_end = start + s - 1;
        if e_end >= td_len
            e_end = td_len;
        end
        ret(start : e_end, :) = str2num(ck);
        start = e_end + 1;
        if to_skip
            start = start + randi([1,(td_len-start)/2],1);
        end
        if start > td_len
            break;
        end
    end
%     ll = length(t_data);
%     sf_l = ll - f_l;
%     t_l_satisfied = 0;
%     if t_l > 0 
%         if t_l <= sf_l
%             t_end = sf_l - t_l;
%             start = randi([1,t_end],1,1);
%             t_data(start:start+t_l-1) = 1;
%             t_l_satisfied = 1;
%         else
%             t_l_satisfied = 2;
%         end
%     end
%     if t_l_satisfied == 1
%         if f_l > 0
%             f_start = start+t_l-1;
%             st = randi([f_start,sf_l],1,1);
%             t_data(st:st+f_l-1) = 0; %#ok<NASGU>
%         end
%     else
%         if t_l_satisfied == 2
%             if f_l > 0
%                 if t_1 > 0
%                     % randomly satisfy t_l or f_l
%                     
%                 else
%                     % satisfy f_l
%                     
%                 end
%             else
%                 % satisfy t_l
%                 
%             end
%         end
%     end
end

