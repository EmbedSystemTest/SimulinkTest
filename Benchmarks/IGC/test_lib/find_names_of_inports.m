function [sysIns, names] = find_names_of_inports(modelName)
    sysIns = find_system(modelName, 'SearchDepth', 1, 'BlockType', 'Inport');
    n = length(sysIns);
    names = strings(n);
    for i=1:n
        inport = sysIns{i};
        pos = strfind(inport,'/');
        name = inport(pos+1:strlength(inport));
        names(i) = string(name);
    end
end
