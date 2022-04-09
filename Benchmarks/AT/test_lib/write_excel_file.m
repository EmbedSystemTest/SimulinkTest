function [hd] = write_excel_file(aoe_tsinghua_mhi_data,csv_file)
    t = aoe_tsinghua_mhi_data.time;
    rows = size(t);
    rows = rows(1);
    
    cols = 0;
    sig_len = length(aoe_tsinghua_mhi_data.signals);
    for i=1:sig_len
        for j=1:aoe_tsinghua_mhi_data.signals(i).dimensions
            cols = cols + 1;
        end
    end
    
    hd = cell(rows+1, cols+1);
    
    hd{1,1} = "time";
    
    t_len = length(t);
    for i=1:t_len
        hd{i+1,1} = t(i);
    end
    
%     disp('== i ==');
    cols = 0;
    for i=1:sig_len
%         disp(i);
        i_str = num2str(i);
        dims = aoe_tsinghua_mhi_data.signals(i).dimensions;
%         disp(strcat(i_str, '#', num2str(dims)));
%         disp(dims);
%         disp(i);
        p = 0;
        while p < dims
            cols = cols + 1;
            sig = strcat("sig",i_str);
%             disp(sig);
            hd{1,cols+1} = sig;
            p = p + 1;
        end
    end
    
    for i=1:rows
        cols = 0;
        for j=1:sig_len
            for k=1:aoe_tsinghua_mhi_data.signals(j).dimensions
                cols = cols + 1;
                hd{i+1,cols+1} = double(aoe_tsinghua_mhi_data.signals(j).values(i,k));
            end
        end
    end
    
%     disp('== hd ==');
%     disp(hd);

%     hd = {"Time", "Temp"; 12 98; 13 99; 14 97};
%     xlswrite(excel_file, hd);
    cell2csv(csv_file, hd, ',', 0, '.');
end

