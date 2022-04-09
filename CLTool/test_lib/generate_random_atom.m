function t_data = generate_random_atom(t_data_type, t_data_shape, t_data_range)
    switch (t_data_type)
        case {"single", "double"}
            t_data = t_data_range(1) + (t_data_range(2)-t_data_range(1)) * rand(t_data_shape, t_data_type);
        case {"int8", "uint8", "int16", "uint16", "int32", "uint32", "int64", "uint64"}
            if rand() > 0.8
                t_data = randi([intmin(t_data_type),intmax(t_data_type)],t_data_shape);
            else
                t_data = randi(t_data_range,t_data_shape);
            end
        case {"boolean"}
            t_data = randi([0,1],t_data_shape);
        otherwise
            assert(0, strcat("strange error! uncognized type:", t_data_type));
    end
    if strcmp(t_data_type, 'single')
    else
        if strcmp(t_data_type, 'double')
        end
    end
end



