function plotsol(sol, cds, costo)

n = numel(sol);

hold on;
for(i=1:n-1)
	plot(cds(1, sol([i, i+1]) ), cds(2, sol([i, i+1])), ...
		'k-o',...
        'MarkerSize',10,...
        'MarkerFaceColor','y',...
        'LineWidth',2.5);
    
end

plot(cds(1, sol([1, n]) ), cds(2, sol([1, n])), ...
        'k-o',...
        'MarkerSize',13,...
        'MarkerFaceColor','r',...
        'LineWidth',2.5);

hold off;

	xlabel('x');
    ylabel('y');
    title('funxion');
    
   % axis equal;
    grid on;

% plot(ciudades(1,:), ciudades(2,:), '*b');