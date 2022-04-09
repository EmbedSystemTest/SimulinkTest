function []=transfer_dataset_to_workspace(ds)
    element_list = getElementNames(ds);
    ele_num = length(element_list);
    for i=1:ele_num
        e_name_cell = element_list(i);
        e_name = string(e_name_cell{1});
        c_val = get(ds,e_name);
        % disp(class(c_val));
        eval(strcat(e_name,'=',num2str(c_val),';'));
    end
end