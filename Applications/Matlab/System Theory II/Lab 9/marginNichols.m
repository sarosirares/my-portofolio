function [] = marginNichols(wc,pwc,m_wpi)
% make a function file such that the gain and phase
% margin to appear as separate vectors together with their values
% close all;
% wc=32.4;% cutoff frequency
% pwc=-131; % the phase evaluated for wc
% w_pi=72; % the frequency for which the phase equal -180 degrees
% m_wpi=-7.8;% the magnitude evaluated for w_pi
%
%nichols(0.05*H);axis([-270 -45 -20 20]);shg
hold on

if pwc >= -180 % stable
    % plot the phase margin
    pm=180+pwc;% phase margin
    plot([-180 pwc],[0 0],'r-',pwc,0,'r>')

    % delay margin [dm] from stability condition pm>0
    %180+pwc-dm*wc>0
    dm=pm*pi/180/wc;

    t1=['\gamma_k=',num2str(ceil(pm)),'^o, ', 'dm=',num2str(round(dm,4)),' sec'];
    text(-180+pm/2, 3,t1,'Color','r')

    % plot the gain margin
    gm=m_wpi;
    plot([-180 -180],[0 gm],'g-',-180,gm,'gv')
    t2=['m_k=',num2str(gm),' dB'];
    text(-175, gm/2, t2,'Color','g')

    hold off
else % unstable
    % plot the phase margin
    pm=180+pwc;% phase margin
    plot([-180 pwc],[0 0],'r-',pwc,0,'r<')

    % delay margin [dm] from stability condition pm>0
    %180+pwc-dm*wc>0
    dm=pm*pi/180/wc;

    t1=['\gamma_k=',num2str(ceil(pm)),'^o, ', 'dm=',num2str(round(dm,4)),' sec'];
    text(-180+pm/2,-3,t1,'Color','r')

    % plot the gain margin
    gm=m_wpi;
    plot([-180 -180],[0 gm],'g-',-180,gm,'g^')
    t2=['m_k=',num2str(gm),' dB'];
    text(-175, gm/2, t2,'Color','g')

    hold off
end

