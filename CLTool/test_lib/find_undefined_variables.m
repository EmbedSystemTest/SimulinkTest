function undefinedVars = find_undefined_variables(modelName)
    undefinedVars = [];
    stillErrors = 1;
    while stillErrors
        try
            Simulink.findVars(modelName);
            stillErrors = 0;
        catch err
            leaf_err = track_to_leaf_err(err);
            if ~isempty(leaf_err) && (strcmp(leaf_err.identifier,'SLDD:sldd:VarMissingBase') || strcmp(leaf_err.identifier,'SLDD:sldd:VarDeletedBaseWithoutValueRecorded'))
                varName = regexp(leaf_err.message,'Variable ''(\w+)''','tokens');
                if ~isempty(varName)
                    undefinedVars = [undefinedVars string(varName{1}{1})];
                    evalin('base',[varName{1}{1},'=1;']);
                end
            else
                rethrow(err);
            end
        end
    end
end

function leaf_err = track_to_leaf_err(err)
    leaf_err = err;
    while ~isempty(leaf_err.cause)
        leaf_err = leaf_err.cause{1};
    end
end

