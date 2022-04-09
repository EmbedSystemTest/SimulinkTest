x = "[0 1]";
y = str2num(x);
disp(y);

m = containers.Map;
if isempty(m)
    disp('==== ==== ==== ====');
end
m('abc') = 1;
m('bbd') = 2;
if isempty(m)
    disp('==== ==== ==== ====');
else
    disp('|||| |||| |||| ||||');
end
mk = keys(m);
disp(mk);
a = mk{1};
mkk = ["abc" "bbd" "bbd"];
in = ismember(mkk, 'bbd');
idxs = find(in == 1);
disp(in);
disp(idxs);
mkk(idxs) = [];
disp(mkk);
disp(keys(m));

x = [1,2,3,4];
y = num2str(x);
disp(x);
disp(y);
z = str2num(y);
disp(z);

x = "";
if ~strcmp(x, "")
    disp('111');
else
    disp('222');
end

disp('== split line ==');
vv = 0; %#ok<NASGU>
vv = eval('vv');
disp(vv);
vvv = eval('0');
disp(vvv);

disp('== test randi ==');
ri = randi(15);
disp(ri);
disp(size(ri));
disp(randperm(15));



