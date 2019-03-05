e = 2.718281828459;

rel = 1;

while(rel == 1)
   x = input('x = ');
   sum = 1;
   trm = 1;
   n = 0;
   fract = abs(x - fix(x));
   m = fix(abs(x));
   olds = sum;
   n = n + 1;
   trm = trm * fract / n;
   sum = sum + trm;
   while(sum ~= olds)
      olds = sum;
      n = n + 1;
      trm = trm * fract / n;
      sum = sum + trm;
   end
   if(x >= 0)
      f = sum * e ^ m;
   else
       f = 1 / (sum * e ^ m);
   end
   fprintf('nr.iter = %g, f = %g\n', n, f);
   fx = exp(x);
   fprintf('fx = %g\n', fx);
   fprintf('1 = reluare; 0 = nu\n');
   rel = input('rel = ');
end