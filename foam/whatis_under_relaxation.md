On youtube by @gerhardbekker646
https://www.youtube.com/watch?v=YXElSo3Zdzk


Let's say a temperature of T^(1) = 10 K is obtained after your first iteration (in a given cell). That temperature then changes to, say, T^(2) = 20 K after the second iteration. Now if you use an under-relaxation factor of 0.5, for example, that second computed temperature will be relaxed to T^(2) = T^(1) + {under-relaxation * [T^(2) - T^(1)]} = 10 + [0.5 * (20 - 10)] = 15 K. Or something to that effect. The point is that the under-relaxation reduces the change in cell values from iteration to iteration to facilitate stability. Else, changes might be too large and go out of control, especially early on in simulations when you are far from your solution. Therefore, it is not a bad idea to start with small under-relaxation factors (values closer to 0), and as you approach your solution, to increase the under-relaxation factors (to values closer to 1).
