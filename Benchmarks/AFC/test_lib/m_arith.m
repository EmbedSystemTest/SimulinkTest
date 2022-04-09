function [ret] = m_arith(arr, dis_idx, val)
    ret = arr;
    dice = randi([0,3],1);
    for i=1:length(dis_idx)
        switch (dice)
        case {0}
            ret(dis_idx(i),:) = ret(dis_idx(i),:) * val;
        case {1}
            ret(dis_idx(i),:) = ret(dis_idx(i),:) + val;
        case {2}
            ret(dis_idx(i),:) = ret(dis_idx(i),:) * (-val);
        case {3}
            ret(dis_idx(i),:) = ret(dis_idx(i),:) - val;
        end
    end
end

