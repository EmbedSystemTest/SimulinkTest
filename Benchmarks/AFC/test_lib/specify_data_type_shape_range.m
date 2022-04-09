function [] = specify_data_type_shape_range(modelName, sysIns, names, specified_data_type, specified_data_dimension, specified_data_range)
    assert(~isempty(modelName));
    eval([modelName,'([],[],[],''compile'');']);
    for i=1:length(sysIns)
        in = sysIns{i};
        in_name = names{i};
        h = get_param(in,'Porthandles');
        data_type = get_param(h.Outport,'CompiledPortDataType');
%         data_type = get_param(in,'OutDataTypeStr');
%         disp(data_type);
        dimensions = get_param(h.Outport,'CompiledPortDimensions');
%         disp(fieldnames(h));
%         dimensions = get_param(in,'OutDimensionsStr');
%         disp(dimensions);
%         dimensions = 1;
        specified_data_type(in_name) = data_type;
        specified_data_dimension(in_name) = dimensions;
        % disp(data_type);
        % disp(class(data_type));
        % disp(dimensions);
        % disp(class(dimensions));
        % disp('====');
        % 
%         dialogPrms = get_param(sysIns(i), 'DialogParameters');
%         for idx = 1:numel(dialogPrms)
%             dialogPrm = dialogPrms{idx};
%             dialogPrmNames = fieldnames(dialogPrm);
%             dialogPrmName = dialogPrmNames{idx};
%             dialogPrmValue = get_param(sysIns(i), dialogPrmName);
%             disp(dialogPrmName);
%             disp(dialogPrmValue);
%         end
%         % dimensions = get_param(sysIns(i),'CompiledPortDimensions');
%         % dataTypes = get_param(sysIns(i),'CompiledPortDataTypes');
%         % disp(dimensions);
%         % disp(dataTypes);
%         disp('==== ====');
    end
%     set_param(gcs, 'SimulationCommand', 'stop');
%     set_param(modelName, 'SimulationCommand', 'stop');
    eval([modelName,'([],[],[],''term'')']);
    pause(0.5);
end


