function [VA] = MonteCarloFixedRW(x,y,N)
boundary_potentials=[100, 0, 0, 0];
grid_size=4;
V=zeros(1,N);

for i=1:N
    x_poz=x;
    y_poz=y;
    done=0;
    while done==0
        U=rand;
        if U>0 && U<0.25
            x_poz=x_poz+1;
        elseif U>0.25 && U<0.5
            x_poz=x_poz-1;
        elseif U>0.5 && U<0.75
            y_poz=y_poz+1;
        else
            y_poz=y_poz-1;
        end
        if x_poz==1
           V(i)=boundary_potentials(1);
           done=1;
        elseif x_poz==grid_size
            V(i)=boundary_potentials(3);
            done=1;
        elseif y_poz==1
            V(i)=boundary_potentials(4);
            done=1;
        elseif y_poz==grid_size
            V(i)=boundary_potentials(2);
            done=1;
        end
    end
end
VA=mean(V);
end