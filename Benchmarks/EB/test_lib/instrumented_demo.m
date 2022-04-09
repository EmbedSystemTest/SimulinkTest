function [outputArg1,outputArg2] = instrumented_demo(inputArg1,u)
    assignin('base','run_info',sprintf('%sOND#%f$',evalin('base','run_info'),u(2)));
    outputArg1 = inputArg1;
    outputArg2 = u;
end

