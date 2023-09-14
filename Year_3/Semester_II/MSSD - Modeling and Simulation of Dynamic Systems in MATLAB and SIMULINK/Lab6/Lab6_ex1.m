% Represent the two animated curves:
% f(t) = exp(-t) + exp(-3 * t)
% g(t) = sin(4 * t)
% t ∈ [0,10]

h1 = animatedline('Color', 'r', 'LineWidth', 1, 'LineStyle', '-');
h2 = animatedline('Color', 'b', 'LineWidth', 1, 'LineStyle', ':');

axis([0 10 -4 4]);
t = linspace(0,10, 100);
f = exp(-t) + exp(-3 * t);
g = sin(4 * t);

for i=1:length(t) 
    addpoints(h1, t(i),f(i));
    addpoints(h2, t(i), g(i));
    drawnow
end
