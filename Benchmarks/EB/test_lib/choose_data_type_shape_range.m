function [t_data_type, t_data_shape, t_data_range] = choose_data_type_shape_range(name, specified_data_type, default_data_type, specified_data_shape, default_data_shape, specified_data_range, default_data_range)
    t_data_type = choose_one_data_type_shape_range(name, specified_data_type, default_data_type);
    t_data_shape = choose_one_data_type_shape_range(name, specified_data_shape, default_data_shape);
    t_data_range = choose_one_data_type_shape_range(name, specified_data_range, default_data_range);
end

function t_d = choose_one_data_type_shape_range(name, specified_d, default_d)
    t_d = default_d;
    if isKey(specified_d, name)
        t_d = specified_d(name);
    end
end





