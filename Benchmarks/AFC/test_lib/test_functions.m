% see = parse_branch_info('Last_True#1$b#3#4$a#7#8$');
% disp(random_from_set([1,2,3,4]));
clear;
clc;

origin_config_ok = 1;

run_info = '';

Start_time = 0;
Stop_time = 5;
Sample_time = 1;

model = 'test';

instrument_s_flag = 1;
s_config = {["fcn" "u" "2" "[0 1]"], ["OFDLC" "u" "2" "[0 1]"], ["OSHOTC" "u" "2" "[0 1]"], ["#" "#" "#" "#"]};

% eval([model,'([],[],[],''term'')']);
% set_param(model, 'SimulationCommand', 'stop');

open_system(model);
config_set_up(model);
instrument_s_functions(model, s_config);

t = (Start_time:Sample_time:Stop_time)';
u1 = [[1 10]; [2 20]; [3 30]; [4 40]; [5 50]; [6 60]];
% u1 = [1 10 2 20 3 30 4 40 5 50 6 60 1 10 2 20 3 30 4 40 5 50 6 60];
% u1 = reshape(u1, [6, 1, 2, 2]);
% u1 = reshape(u1, [2, 6])';
u2 = [40 40 60 60 40 40]';
% u2 = reshape(u2, [1, 6])';
u3 = [20 20 50 20 20 20]';
% disp(u2);
aoe_tsinghua_mhi_data = struct();
aoe_tsinghua_mhi_data.time = t;
aoe_tsinghua_mhi_data.signals(1).values = u1;
aoe_tsinghua_mhi_data.signals(1).dimensions = 2;
aoe_tsinghua_mhi_data.signals(2).values = u2;
aoe_tsinghua_mhi_data.signals(2).dimensions = 1;
aoe_tsinghua_mhi_data.signals(3).values = u3;
aoe_tsinghua_mhi_data.signals(3).dimensions = 1;
% disp(aoe_tsinghua_mhi_data);
% u = cell(1,3);
% u{1} = u1;
% u{2} = u2;
% u{3} = u3;
% u = [u1,u2,u3];
% disp(t);
% disp(u);
ct = cvtest(model);
% ct.settings.condition = 1;
[cvdo, simOut] = cvsim(ct);

% default_data_dimension = 1;
% specified_data_dimension = containers.Map();
% default_data_type = 'double';
% specified_data_type = containers.Map();
% default_data_range = [-10,10];
% specified_data_range = containers.Map();
% 
% [sysIns, names] = find_names_of_inports(model);
% specify_data_type_shape_range(model, sysIns, names, specified_data_type, specified_data_dimension, specified_data_range);

% close_system(model);

% a = [1 2 3 4];
% b = [a(1:2) 5 a(3:4)];
% disp(b);

% one = "function p  = fcn(u)\np = 0;\nif u(1) < 50\np = 40;\nelse\nif u(2) == 50\np = 600;\nend\np = p + 60;\nend\nend";
% two = "p  = fcn(u)\n";
% idxs = regexpi(two, '^function((\s+\S+)|(\s*[))');
% disp(idxs);

% is = regexp('fcn','#','match');
% disp(isempty(is));
% disp(is);
