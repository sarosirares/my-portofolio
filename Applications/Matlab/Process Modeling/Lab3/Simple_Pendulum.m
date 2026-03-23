syms u w l g;
uw = dsolve('Du = w', 'Dw = -0.05*w-g/l*u', 'u(0)=pi/6', 'w(0)=0')
theta = subs(uw.u, {l,g}, {4, 9.8})
omega = subs(uw.w, {l,g}, {4, 9.8})
hold on
fplot(real(theta), [0,30], 'LineWidth', 2, 'Color', 'b')
fplot(real(omega), [0,30], 'LineWidth', 2, 'Color', 'r')
legend('\theta', '\omega')