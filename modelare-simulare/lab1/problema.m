lambda = 10;
u = zeros(1000);
x = zeros(1000);

for i = 1:1000
   u(i) = rand();
   x(i) = - log(1 - u(i)) / lambda;
end

rectangle('Position',[0 0 1 5/lambda]);
hold on
rectangle('Position',[0 0 1 1/lambda]);

plot(u, x, "k");
hold();