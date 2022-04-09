function test_ds = generate_random_constant(names, specified_data_type, default_data_type, specified_data_shape, default_data_shape, specified_data_range, default_data_range)
    test_ds = Simulink.SimulationData.Dataset();
    n = length(names);
    for i=1:n
        name = names(i);
        [t_data_type, t_data_shape, t_data_range] = choose_data_type_shape_range(name, specified_data_type, default_data_type, specified_data_shape, default_data_shape, specified_data_range, default_data_range);
        t_data = generate_random_atom(t_data_type, t_data_shape, t_data_range);
        % rand(t_data_shape);
        % disp(class(name));
        test_ds = test_ds.addElement(t_data, name);
        % disp(name);
    end
end
