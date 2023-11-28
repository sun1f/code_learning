N = [10, 20, 50, 100, 200, 500]

rmse_euroc = [2.5, 1.4, 0.51, 0.26, 0.21, 0.21]
rmse_kitti = [10.77, 8.97, 7.85, 6.56, 5.88, 5.88]

plot(N, rmse_euroc, 'LineWidth', 1.5, 'LineStyle', '-', 'Color', [0.49, 0.18, 0.56], 'Marker', '^', 'MarkerEdgeColor', '[0.49, 0.18, 0.56]', 'MarkerFaceColor', '[0.49, 0.18, 0.56]', 'MarkerSize', 6);
hold on;
plot(N, rmse_kitti, 'LineWidth', 1.5, 'LineStyle', '-', 'Color', [0.36, 0.62, 0.68], 'Marker', '^', 'MarkerEdgeColor', '[0.36, 0.62, 0.68]', 'MarkerFaceColor', '[0.36, 0.62, 0.68]', 'MarkerSize', 6);

% \itN是斜体N，\rmN是正体N
xlabel('本地地图规模（关键帧数量\itN\rm）')
% xlabel('（）')
% ylabel('\itRSE（m）')
ylabel('RMSE\rm（\itm\rm）')

% 坐标轴范围
xlim([0, 550])
ylim([0, 11.5])

% 刻度
set(gca, 'xtick', [20 50 100 200 300 400 500])
set(gca, 'ytick', [0, 2, 4, 6, 8, 10, 11])

% 坐标轴字体
set(gca,'FontSize',12)
% set(gca,'FontWeight','bold');

% 题注
lg1=legend('EuRoC MH02', 'KITTI 05')

title('本地地图规模对子端独立定位精度的影响')

box off



