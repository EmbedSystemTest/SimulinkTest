function y = ONDLC(u, old, set)
    if (u == 10)
        if old < set 
            y(1) = false;
            y(2) = old + 1;
        else
            y(1) = true;
            y(2) = old;
        end
    else
        y(1) = false;
        y(2) = 0;
    end
end
