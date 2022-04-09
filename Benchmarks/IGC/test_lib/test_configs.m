open_system('test');
[Start_time_cmd,Stop_time_cmd,Sample_time_cmd] = config_load_up('test');
close_system('test');

Start_time = eval(Start_time_cmd);
Stop_time = eval(Stop_time_cmd);
Sample_time = eval(Sample_time_cmd);

disp('== ==');
disp(Start_time);
disp(class(Start_time));
disp(Stop_time);
disp(class(Stop_time));
disp(Sample_time);
disp(class(Sample_time));

