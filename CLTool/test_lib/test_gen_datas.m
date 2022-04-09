Sample_time = 1;

constant_model = containers.Map;
constant_model("1") = [4 6];
constant_model("0") = [2 3];

t_data = unifrnd (0, 0.5, 20, 1);
ret = random_set_partial_sequence( t_data, constant_model );

disp(t_data);
disp(ret);

