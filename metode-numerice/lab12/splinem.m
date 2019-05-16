function output = splinen(x,y,xx)
%
% splinen:	NATURAL Cubic spline data interpolation.
%
%	Given data vectors X and Y, and a new abscissa vector XI, the
%	function YI = SPLINE(X,Y,XI) uses NATURAL cubic spline
%	INTERPOLATION to find a vector YI corresponding to XI.
%
%	Here's an example that generates a coarse sine curve, then
%	interpolates over a finer abscissa:
%
%		x = 0:10;  y = sin(x);
%		xi = 0:.25:10;
%		yi = splinen(x,y,xi);
%		plot(x,y,'o',xi,yi)
%
%	PP = splinen(x,y) returns the pp-form of the cubic spline interpolant
%	instead, for later use with  ppval, etc.
%
%

n=length(x);[xi,ind]=sort(x);xi=xi(:);
output=[];
if n<4,
   fprintf('\nThere should be at least FOUR data points !\n')
elseif all(diff(xi))==0,
   fprintf('\nThe data abscissae should be distinct !\n')
elseif n~=length(y),
   fprintf('\nAbscissa and ordinate vector should be of the same length !\n')
else   
   yi=y(ind);yi=yi(:);
% set up the linear system for solving for the slopes at  xi .
      dx=diff(xi);divdif=diff(yi)./dx;
      c =diag(dx(2:n-2),-1)+diag(dx(2:n-2),1)+...
         diag(2*dx(1:n-2),0)+diag(2*dx(2:n-1),0);
      d_divdif=diff(divdif);
      b=6*d_divdif;
% solve for the slopes and convert to pp form
      s=c\b;
      ss=[0; s; 0]; dif_ss=diff(ss);
      c4=(1/6)*dif_ss./dx;
      c3=(1/2)*[0; s];
      c2=divdif-(1/6)*(dx.*(ss(2:n)+2*ss(1:n-1)));
      c1=yi(1:n-1);
      pp=mkpp(xi',[c4 c3 c2 c1]);
   end
   if nargin==2,
      output=pp;
   else
      output=ppval(pp,xx);
   end
end
%
% end ..... splinen.
