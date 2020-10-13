function t = genExpM(lambda)
    xy = 0;
    u = rand();
    y = 1 / lambda * u;
    while xy <= y
        xy = genExp(lambda);
    end
    t = xy - y;
end