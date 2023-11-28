N = [10, 20, 50, 100, 200, 500]
c1_tracking_euroc = [22.3, 25.3, 26.4, 27.4, 28.2, 30.3]
c1_mapping_euroc = [76.2, 183.6, 243.7, 312.6, 353.4, 398.6]
c1_comm_euroc = [0.23, 0.30, 0.42, 0.51, 0.54, 0.61]

c1_tracking_kitti = [23.2, 25.5, 27.1, 28.0, 29.2, 31.6]
c1_mapping_kitti = [79.3, 190.2, 252.7, 332.6, 366.4, 409.3]
c1_comm_kitti = [0.24, 0.31, 0.42, 0.52, 0.55, 0.60]

c2_tracking_euroc = [27.3, 30.4, 32.9, 37.2, 40.6, 44.1]
c2_mapping_euroc = [107.5, 254.2, 353.3, 421.6, 478.4, 521.7]
c2_comm_euroc = [0.33, 0.42, 0.50, 0.60, 0.67, 0.73]

c2_tracking_kitti = [28.1, 29.9, 34.0, 38.5, 42.1, 44.7]
c2_mapping_kitti = [112.5, 266.2, 367.4, 441.2, 500.7, 541.1]
c2_comm_kitti = [0.35, 0.43, 0.50, 0.59, 0.68, 0.72]

plot(N, c1_comm_euroc, 'LineWidth', 2, 'LineStyle', '-', 'Color', [0.00, 0.45, 0.74], 'Marker', 'o', 'MarkerEdgeColor', '[0.00, 0.45, 0.74]', 'MarkerFaceColor', '[0.00, 0.45, 0.74]', 'MarkerSize', 6);
hold on;
plot(N, c2_comm_euroc, 'LineWidth', 2, 'LineStyle', '-', 'Color', [0.85, 0.33, 0.10], 'Marker', 'o', 'MarkerEdgeColor', '[0.85, 0.33, 0.10]', 'MarkerFaceColor', '[0.85, 0.33, 0.10]', 'MarkerSize', 6);

% \itN是斜体N，\rmN是正体N
xlabel('本地地图规模（关键帧数量\itN\rm）')
% ylabel('\itRSE（m）')
ylabel('单次迭代时间（\itms\rm）')

% 坐标轴范围
xlim([0, 550])
ylim([0.2, 0.9])

% 刻度
set(gca, 'xtick', [20 50 100 200 300 400 500])
set(gca, 'ytick', [0.2 : 0.2 : 0.9])

% 坐标轴字体
set(gca,'FontSize',12)
% set(gca,'FontWeight','bold');

% 题注
lg1=legend('子端1', '子端2')

title('通信（EuRoC MH02）')

box off



