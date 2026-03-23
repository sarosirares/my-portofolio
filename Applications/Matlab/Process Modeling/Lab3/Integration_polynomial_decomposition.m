syms x f0 f1 f2 h x0
q = f0+(f1 - f0)/h*(x-x0)+(f2-2*f1+f0)/(2*h^2)*(x-x0)*(x-(x0+h));
iq = int(q,x0,x0+2*h);
simplify(iq)