function [TA] = MonteCarloFloatingRW(x,y,N)
boundary_temp=[204.4, 93.3, 93.3, 204.4];
T=zeros(1,N);
Lx=45;
Ly=15;

for i=1:N
    x_poz=x;
    y_poz=y;
    done=0;
    while done==0
        d_top=Ly-y_poz;
        d_bot=y_poz;
        d_left=x_poz;
        d_right=Lx-x_poz;

        [ri, boundary_index]=min([d_top, d_right, d_bot, d_left]);

        if ri==0
        T(i)=boundary_temp(boundary_index);
        done=1;
        else
        U=rand;
        omega=2*pi*U;
        x_poz=x_poz+ri*cos(omega);
        y_poz=y_poz+ri*sin(omega);
        end
    end
end
TA=mean(T);
end