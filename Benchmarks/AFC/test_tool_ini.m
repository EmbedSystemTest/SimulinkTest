% parameters for testing model
model = 'AbstractFuelControl_M1';

% testing tool parameters
% instrument_s_flag: 0: not instrument file; 1: instrument file; 2: (will check and delete instrumentation of this tool); 
instrument_s_flag = 1;
s_config = {["ONDLC" "u" "2" "[0 1]"], ["OFDLC" "u" "2" "[0 1]"], ["OSHOTC" "u" "2" "[0 1]"], ["#" "#" "#" "#"]};

test_time = 360;

mutate_variable = 0;
seed_mutate_times = 2;

minimum_data = -10;
maximum_data = 10;

InitialTestCasesDirectory = "TestCases";
mutate_probability = 0.5;
simple_taint_analysis_probability = 0.5;

immutate_vars = ["Start_time","Stop_time","Sample_time"];

force_use_tool_default_setting = 0;







addpath('test_lib');

open_system(model);
origin_config_ok = 0;
try
    if force_use_tool_default_setting
        me = MException('Force:User','ForceToUseDefaultToolSetting'); %#ok<UNRCH>
        throw(me);
    end
    [Start_time_cmd,Stop_time_cmd,Sample_time_cmd] = config_load_up(model);
    %set parameters here%
    Start_time = eval(Start_time_cmd);
    Stop_time = eval(Stop_time_cmd);
    Sample_time = eval(Sample_time_cmd);
    origin_config_ok = 1;
catch exception
    disp(strcat("Some unexpected happens: ", exception.message));
    disp("Model mode must be Fixed-Step and StartTime, StopTime, FixedStep must be set properly.");
    disp("However it seems some values are not found or set propoerly, so we use the manual config in this script.");
    % please manualy config here
    Start_time = 0;
    Stop_time = 200;
    Sample_time = 1;
end

config_set_up(model);
disp("==== Configurations are set! ====");

% instrument_s_functions(model, s_config);
% disp("==== Files are instrumented! ====");

close_system(model);


