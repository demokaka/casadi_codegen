from casadi import *
import numpy as np
import matplotlib.pyplot as plt


opti = casadi.Opti()

N_pred = 10
N = 100

x = opti.variable(2, N_pred+1)  # state variable 
u = opti.variable(1, N_pred)    # input


T = opti.variable()             # final time

opti.minimize(T)

### Specify dynamics
# f = Function('f',[x, u], [x[0], u - x[0]] )
f = lambda x, u: ca.vertcat(x[1], u - x[1])

dt = T/N;                       # length of a control interval
for k in range(N):              # loop over control intervals
   # Runge-Kutta 4 integration
   k1 = f(x[:, k],         u[:, k])
   k2 = f(x[:, k]+dt/2*k1, u[:, k])
   k3 = f(x[:, k]+dt/2*k2, u[:, k])
   k4 = f(x[:, k]+dt*k3,   u[:, k])
   x_next = x[:, k] + dt/6*(k1+2*k2+2*k3+k4); 
   opti.subject_to(x[:, k+1]==x_next); # close the gaps
end



