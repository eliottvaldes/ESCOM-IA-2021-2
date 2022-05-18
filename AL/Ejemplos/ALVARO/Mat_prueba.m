fprintf("Hello there\n")
A = input(prompt)
fprintf("Introduce data with form 3,1")
b = input(prompt)
Aext = [A b]
fprintf("Reduced row echeleon form\n")
rref(Aext)
