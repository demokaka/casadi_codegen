% https://web.casadi.org/blog/s-function/
% CasADi codegen and S-Functions


%%
clc; clear; close all;
import casadi.*
qube2_param;            % import parameters of DC motor model

%% Parameter settings
% Continuous system
A_cont = [0 1; 0 -(km*kt)/(Rm*Jeq)];
B_cont = [0; kt/(Rm*Jeq)];

% Discretize the system
Ts = 0.02;
sys_cont = ss(A_cont, B_cont, eye(2), zeros(2,1));
sys_disc = c2d(sys_cont, Ts, 'zoh');
A = sys_disc.A;  % discretized matrices
B = sys_disc.B;

fprintf('Discretized system matrices (Ts=%f):\n', Ts);
fprintf('A = \n'); disp(A);
fprintf('B = \n'); disp(B);


% MPC parameters
n = 2; m = 1;
Npred = 5;
Q = diag([500,1]);
R = 1;
P = 10*Q;

%% CasADi MPC setup
opti = Opti();
x = opti.variable(n, Npred+1);
u = opti.variable(m, Npred);
xinit = opti.parameter(n, 1);
xref = opti.parameter(n, Npred+1);

% Constraints
opti.subject_to(x(:,1) == xinit);
umin = -10; umax = 10;
for k=1:Npred
    opti.subject_to(x(:,k+1) == A*x(:,k) + B*u(:,k));  % discretized system
    opti.subject_to(umin <= u(:,k));
    opti.subject_to(u(:,k) <= umax);
end

% Objective
obj = 0;
for k=1:Npred
    obj = obj + (x(:,k)-xref(:,k))'*Q*(x(:,k)-xref(:,k)) + u(:,k)'*R*u(:,k);
end
obj = obj + (x(:,Npred+1)-xref(:,Npred+1))'*P*(x(:,Npred+1)-xref(:,Npred+1));
opti.minimize(obj);

% Solver options
opts = struct('qpsol','osqp', 'print_time', false);
opti.solver('sqpmethod', opts);


%% Generate CasADi function for Simulink
F = opti.to_function('solver_01', ...
    {xinit, xref}, {u(:,1)}, ...
    {'x0','xref'}, {'u_opt'});

% Generate C code
% F.generate('mpc_solver.c', struct('with_header', true));
cg_options = struct;
cg_options.casadi_real = 'real_T';
cg_options.casadi_int = 'int_T';
cg_options.with_header = true;
cg = CodeGenerator('solver_01',cg_options);
cg.add_include('simstruc.h');
cg.add(F);
cg.generate();
fprintf('C code generated \n');

