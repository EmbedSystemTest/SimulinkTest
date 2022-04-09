function [ one ] = random_element_from_two_sets(t_set, e_set, num)
    r_t_set = [t_set e_set];
    r_t_set_len = length(r_t_set);
    assert(num <= r_t_set_len);
%     disp(r_t_set_len);
    rp = randperm(r_t_set_len);
%     disp(rp);
    b = r_t_set(rp);
    one = b(1:num);
end

