
a = [1 2 3 4;5 6 7 8];
disp(size(a));

b = 1.4;
rb = int32(round(b));
disp(rb);
disp(class(rb));

c = struct('cluster',[1 2]);
c(2) = struct('cluster',[1 2;3 4]);
disp(c);

ii = rand (1, 1);
if ii > 0.5
    disp(ii);
else
    disp(strcat(num2str(ii), '=='));
end

disp('==== split line ====');

d = [];
disp(isempty(d));
d = struct('a', [1 2]);
disp(isempty(d));

a = struct('a', 1, 'b', 2);
b = a;
b.('a') = 3;
b.('b') = 4;
disp(a);
disp(b);

disp('==== size of empty map ====');
m = containers.Map();
disp(size(m));
disp(isempty(m));
m('a') = [1, 2];
disp(isempty(m));

disp('====');
a = [0 0 0 1 1 1 0 0 0];
a(4:6) = 1- a(4:6);
disp(a);

A = randperm(10);
disp(A);

disp('== ==');
ss = randi([1, 3], 1);
se = randi([4, 6], 1);
B = (ss:se);
disp(B);

C = [[1 2];[3 4];[5 6];[7 8]];
disp(size(C));
% C(4,:) = [9 10];
D = m_bit_flip(C,4);
disp(D);
% disp(C(4,:));

% [NUM,TXT,RAW] = xlsread('sample');
% 
% disp(strcat('== NUM =='));
% disp(NUM);
% 
% disp(strcat('== TXT =='));
% disp(TXT);
% 
% disp(strcat('== RAW =='));
% disp(RAW);

% data = load('sample.xlsx');
% disp(data);

[aoe_tsinghua_mhi_data] = read_excel_file('sample.csv');
hd = write_excel_file(aoe_tsinghua_mhi_data,'sample_write.csv');

% disp('== mm ==');
% namelist = dir(strcat('', '*.xlsx'));
% for i = 1:length(namelist)
%     name_i = namelist(i).name;
%     disp(name_i);
% end








