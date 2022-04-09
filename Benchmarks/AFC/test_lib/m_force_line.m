function [ret] = m_force_line(arr, dis_idx, val)
    ret = arr;
    for i=1:length(dis_idx)
        ret(dis_idx(i),:) = val;
    end
end

