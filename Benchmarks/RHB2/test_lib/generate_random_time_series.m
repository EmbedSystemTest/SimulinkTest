function test_sig = generate_random_time_series(t_data_type, t_data_shape, t_data_range, start_t, gap_t, end_t, constant_model)
    % test_ds = Simulink.SimulationData.Dataset();
    % out_t_data = [];
    % n = length(names);
    % for i=1:n
    % name = names(i);
%     t_data_size = floor((end_t-start_t)/gap_t)+1;
    t_data_size = length((start_t:gap_t:end_t));
    t_data = [];
    for j=1:t_data_size
        t_data = [t_data; generate_random_atom(t_data_type, t_data_shape, t_data_range)];
        % rand(t_data_shape);
    end
    
%     switch (t_data_type)
%         case {"single", "double"}
%             fft with an bn A0 randomly setting;
%             if dice < 0.2
%                 to_partial_set = 1;
%             end
%         case {"int8", "uint8", "int16", "uint16", "int32", "uint32", "int64", "uint64"}
%             fft with an bn A0 randomly setting;
%             if dice < 0.2
%                 to_partial_set = 1;
%             end
%         case {"boolean"}
%             t_set = [];
%             if isKey(constant_model, 'Last_True')
%                 t_set = constant_model('Last_True');
%             end
%             f_set = [];
%             if isKey(constant_model, 'Last_False')
%                 f_set = constant_model('Last_False');
%             end
%             t_data = random_set_partial_sequence(t_data, t_set, f_set);
%             assert(~isempty(t_data));
%         otherwise
%             assert(0, strcat("strange error! uncognized type:", t_data_type));
%     end
    
    dice = rand();
    simple_ta_prob = evalin('base', 'simple_taint_analysis_probability');
    if dice < simple_ta_prob
        t_data = random_set_partial_sequence(t_data, constant_model);
        assert(~isempty(t_data));
    end
    
    eval_cmd = strcat(t_data_type, '(t_data)');
    % disp(eval_cmd);
    type_parsed = eval(eval_cmd);
    test_sig = type_parsed;
%     test_sig = timeseries(type_parsed, start_t:gap_t:end_t);
    % out_t_data = test_sig;
    % test_ds = test_ds.addElement(pos_data, name);
    % disp(name);
    % end
end
