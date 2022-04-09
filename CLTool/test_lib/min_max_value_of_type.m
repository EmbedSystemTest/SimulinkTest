function [mi,ma] = min_max_value_of_type(tp)
    switch (tp)
    case {"single", "double"}
        mi = realmin(tp);
        ma = realmax(tp);
    case {"int8", "uint8", "int16", "uint16", "int32", "uint32", "int64", "uint64"}
        mi = intmin(tp);
        ma = intmax(tp);
    case {"boolean"}
        mi = 0;
        ma = 1;
    otherwise
        assert(0, strcat("strange error! uncognized type:", t_data_type));
    end
end

