function [aoe_tsinghua_mhi_data] = read_excel_file(t_meta, csv_file)
%     [NUM,TXT,~] = xlsread(excel_file);
    
    fid = fopen(csv_file);
    f_str = fgetl(fid);
    fclose(fid);
    TXT = strsplit(f_str, ',');
    NUM = csvread(csv_file, 1, 0);
      
    aoe_tsinghua_mhi_data = struct();
    aoe_tsinghua_mhi_data.time = NUM(:,1);
    
%     disp('== NUM Begin ==');
%     disp(size(NUM(:,1)));
%     disp(size(NUM(:,1)'));
%     disp('== NUM End ==');
    
    real_index = 0;
    ns = size(NUM);
%     disp(strcat('ns:',num2str(ns)));
    col_size = ns(2);
    i = 2;
    while i <= col_size
        i_head = TXT(i);
        dims = 1;
        for j=i+1:col_size
            if strcmp(TXT(j),i_head)
                dims = dims + 1;
            else
                break;
            end
        end
        real_index = real_index + 1;
        t_data = NUM(:,i:i+dims-1); %#ok<NASGU>
        i = i + dims;
        t_data_type = t_meta(real_index,1);
        t_data_type = t_data_type{1};
        eval_cmd = strcat(t_data_type, '(t_data)');
        type_parsed = eval(eval_cmd);
        aoe_tsinghua_mhi_data.signals(real_index).values = type_parsed;
%         disp('== == ==');
%         disp(NUM(:,i:i+dims-1));
%         disp(strcat('== NUM Begin ==', num2str(i), num2str(i+dims-1)));
%         disp(size(NUM(:,1)));
%         disp(size(NUM(:,1)'));
%         disp(strcat('== NUM End ==', num2str(i), num2str(i+dims-1)));
        aoe_tsinghua_mhi_data.signals(real_index).dimensions = dims;
    end
%     disp(length(aoe_tsinghua_mhi_data.signals));
end

