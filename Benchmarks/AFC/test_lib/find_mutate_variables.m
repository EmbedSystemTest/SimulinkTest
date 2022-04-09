function [ vars ] = find_mutate_variables( modelName,immutate_vars )
    vars = [];
    var_usages = Simulink.findVars(modelName);
    for i=1:length(var_usages)
        var_usg=var_usages(i);
        var_name = string(var_usg.Name);
%         disp(var_name);
        if ~ismember(var_name,immutate_vars)
            vars = [vars; var_name];
        end
    end
%     disp(immutate_vars);
end

