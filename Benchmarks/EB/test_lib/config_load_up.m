function [Start_time,Stop_time,Sample_time] = config_load_up(model)
activeConfigObj = getActiveConfigSet(model);

Start_time = get_param(activeConfigObj,'StartTime');
Stop_time = get_param(activeConfigObj,'StopTime');

solver = get_param(activeConfigObj,'Solver');
solver_type = get_param(activeConfigObj,'SolverType');

if (~strcmp(solver, "FixedStepDiscrete") && ~strcmp(solver, "FixedStepAuto")) || ~strcmp(solver_type, "Fixed-step")
    throw(MException('SolverUnSat:MustFixedStep', 'Not Fixed-Step mode! Please change to Fixed-Step mode!'));
end

Sample_time = get_param(activeConfigObj,'FixedStep');

% disp(Start_time);
% disp(Stop_time);
% disp(Sample_time);
% disp(solver);
% disp(solver_type);

end

