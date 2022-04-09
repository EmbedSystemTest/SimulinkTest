function [ret] = test_func()
    a.b = [1.0 2.0 3.0 4.0];
    eval_cmd = strcat('int8', '(a.b)');
    ret = eval(eval_cmd);
    disp(ret);
end

