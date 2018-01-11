figure(2)
plot(120:-1:1,L,'-k')
hold on
plot(120:-1:1,R,'-b')
hold on
plot(120:-1:1,M,'-r')
hold on
plot(120:-1:1,M_F,'-g')
hold on
plot(1:1:251,M_Real,'-m')
grid on
xlabel('前向距离/cm')
ylabel('方向偏差')