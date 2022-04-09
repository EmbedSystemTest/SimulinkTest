function [ one ] = random_from_set(t_set)
    r_t_set = [t_set; randi([1, 5])];
    r_t_set_len = length(r_t_set);
%     disp(r_t_set_len);
    rp = randperm(r_t_set_len);
%     disp(rp);
    b = r_t_set(rp);
    one = b(1:1);
end

