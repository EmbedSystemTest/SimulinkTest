function [ret] = m_bit_flip(arr, dis_idx)
    ret = arr;
    for i=1:length(dis_idx)
        ret(dis_idx(i),:) = 1 - ret(dis_idx(i),:);
    end
end

