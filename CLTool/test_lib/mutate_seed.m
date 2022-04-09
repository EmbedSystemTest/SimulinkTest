function [aoe_tsinghua_mhi_data] = mutate_seed(seed_meta, care_seed, care_seed_mutate_times)

aoe_tsinghua_mhi_data = care_seed;

s_len = length(aoe_tsinghua_mhi_data.signals);
rp = randperm(s_len);
% disp(rp);
% disp(size(aoe_tsinghua_mhi_data.signals));
b = aoe_tsinghua_mhi_data.signals(rp);
% disp(size(b));
c = seed_meta(rp,:);
r_num = randi(s_len);
eles = b(1:r_num);
eles_meta = c(1:r_num,:);
% disp(size(seed_meta));
% disp(size(eles_meta));

for i=1:length(eles)
    ele = eles(i);
    t_meta_i = eles_meta(i,:);
	type = t_meta_i{1};
%     disp(class(type));
%     disp(type);
	shape = t_meta_i{2};
%     disp(class(shape));
%     disp(shape);
	range = t_meta_i{3};
%     disp(class(range));
%     disp(range);
    % mutate ele.values based on ele.dimensions
    % boolean bit flip (random sequential range, random non-sequential range)    
    % all types, 1. force line (random, zero, minimum, maximum); 2. range +1, +2, ...; 
    
    sz = size(ele.values);
    sz1 = sz(1);
    seq_start = randi([1,sz1-1],1);
    seq_end = randi([seq_start+1,sz1],1);
    seq_discrete = (seq_start:seq_end);
    discrete = randperm(sz1);
    dis_size = randi([1,sz1],1);
    discrete = discrete(1:dis_size);
    
    dice = rand(1, 1);
    [mi, ma] = min_max_value_of_type(type);
    switch (type)
    case {"single", "double", "int8", "uint8", "int16", "uint16", "int32", "uint32", "int64", "uint64"}
        if dice < 0.25
            % sequential force line
            ele.values = m_force_line(ele.values, seq_discrete, random_element_from_two_sets([mi, ma, 0], range, 1));
        else
            if dice < 0.5
                % non-sequential force line
                ele.values = m_force_line(ele.values, discrete, random_element_from_two_sets([mi, ma, 0], range, 1));
            else
                if dice < 0.75
                    % sequential arith
                    ele.values = m_arith(ele.values, seq_discrete, rand()*range(2));
                else
                    % non-sequential arith
                    ele.values = m_arith(ele.values, discrete, rand()*range(2));
                end
            end
        end
    case {"boolean"}
        if dice < 0.25
            % sequential bit flip
            ele.values = m_bit_flip(ele.values, seq_discrete);
        else
            if dice < 0.5
                % non-sequential bit flip
                ele.values = m_bit_flip(ele.values, discrete);
            else
                if dice < 0.75
                    % sequential force line
                    ele.values = m_force_line(ele.values, seq_discrete, randi([0,1],shape));
                else
                    % non-sequential force line
                    ele.values = m_force_line(ele.values, discrete, randi([0,1],shape));
                end
            end
        end
    otherwise
        assert(0, strcat("strange error! uncognized type:", type));
    end
    % ensure the type of ele.values
    eval_cmd = strcat(type, '(ele.values)');
    ele.values = eval(eval_cmd);
end

% code waiting to be merged

end

