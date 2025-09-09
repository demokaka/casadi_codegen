% casadi codegen for double integrator


%%
clear; clc; close all;

%%
% state-space model: x(k+1) = Ax(k) + Bu(k)
mu = 0.5;
A = [1 0 mu 0;
     0 1 0 mu;
     0 0 1 0;
     0 0 0 1];

B = [zeros(2); eye(2)*mu];

C = [eye(2), zeros(2)];
D = zeros(2);

% system dimension
[dx, du] = size(B);
dy = size(C,1);

% initial conditions
x0 =  [0.8, 0.2, 0, 0]';
u0 = zeros(du,1);

% constraints
umin = - 0.25;
umax = + 0.25;
delta_u_min = -0.1;
delta_u_max = +0.1;

y_min = -10;
y_max = +10;

%% parameters
Q = eye(dx)*1.0;
R = 1;
Qy = eye(dy);
[P,~,K] = dare(A,B,Q,R); % using LQR formulas 

% number of predictions and simulation steps
N_pred = 5;
N_sim = 100;


%%
solver = casadi.Opti();

X = solver.variable(dx, N_pred+1);
u = solver.variable(du, N_pred);
y = solver.variable(dy, N_pred);

xinit = solver.parameter(dx, 1);
uinit = solver.parameter(du, 1);

% define constraints
solver.subject_to(X(:,1) == xinit)
for k=1:N_pred
    solver.subject_to(X(:,k+1) == A*X(:,k) + B*u(:,k));     % dynamics
    solver.subject_to(y(:,k) == C*X(:,k) + D*u(:,k));       % output
    

    solver.subject_to(umin <= u(:,k) <= umax);      % input constraint
    solver.subject_to(y_min <= y(:,k) <= y_max);      % output constraint

    if k==1
        solver.subject_to(delta_u_min <= u(:,k) - uinit <= delta_u_max);
    else
        solver.subject_to(delta_u_min <= u(:,k) - u(:,k-1) <= delta_u_max); % input rate of change constraint
    end
    
end

% define objective
objective = 0;
for k = 1:N_pred
    objective = objective + X(:,k)' * Q * X(:,k) + u(:,k)' * R * u(:,k); % stage cost
end

% terminal cost
objective = objective + X(:,N_pred+1)' * P * X(:,N_pred+1);


solver.minimize(objective);

% define solver
options.ipopt.print_level = 0;
options.ipopt.sb = 'yes';
options.print_time = 0;
solver.solver('ipopt', options);

%% Simulation loop
usim = zeros(du, N_sim);
xsim = zeros(dx, N_sim+1);
ysim = zeros(dy, N_sim);

% initialize initial conditions
xsim(:,1) = x0;
usim_init = u0;

timer = tic;
for i = 1:N_sim
    % set parameters' values
    solver.set_value(xinit, xsim(:,i));
    if i==1
        solver.set_value(uinit, usim_init);
    else
        solver.set_value(uinit, usim(:,i-1));
    end

    % solve the optimization problem
    sol = solver.solve();
    
    usol = sol.value(u);
    usim(:,i) = usol(:,1);

    xsim(:,i+1) = A*xsim(:,i) + B*usim(:,i);
    ysim(:,i+1) = C*xsim(:,i) + D*usim(:,i);

end
time_sim = toc(timer);


%% PLotting results
% outputs
figure
stem(ysim(1,:));
hold on;
stem(ysim(2,:));
title('output y')


% control inputs
figure
stem(usim(1,:));
hold on;
stem(usim(2,:));
title('Control Inputs u');
xlabel('Time Step');
ylabel('Control Input Value');
legend('u_1', 'u_2');

% states
figure
scatter(xsim(1,:), xsim(2,:))
title('state space')
xlabel('x')
ylabel('y')
