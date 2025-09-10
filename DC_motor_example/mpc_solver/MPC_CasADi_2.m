clc; clear; close all;
import casadi.*
% addpath(genpath(fullfile(pwd, '..', 'dependencies')));
qube2_param;

fprintf('GENERATING MPC FOR SIMULINK\n');

%% System setup with DISCRETIZATION
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
Npred = 20;
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
opts = struct('ipopt', struct('print_level', 0, 'sb', 'yes'), 'print_time', false);
opti.solver('ipopt', opts);

%% Generate CasADi function for Simulink
F = opti.to_function('mpc_solver', ...
    {xinit, xref}, {u(:,1)}, ...
    {'x0','xref'}, {'u_opt'});

% Generate C code
F.generate('mpc_solver_m1.c', struct('with_header', true));
fprintf('C code generated \n');

%% Test the generated function
fprintf('\nTESTING GENERATED FUNCTION\n');
xinit_test = [0; 0];
xref_test = [sin(linspace(0,2*pi,21)); zeros(1,21)];

u_result = full(F(xinit_test, xref_test));
fprintf('Test result: u = %f (should be non-zero)\n', u_result);

if abs(u_result) > 0.001
    fprintf('function works\n');
else
    fprintf('getting zero output\n');
    return;
end

%% Compile MEX file
fprintf('\nCOMPILING S-FUNCTION\n');
% try
%     % setenv('PATH', [getenv('PATH') ';C:\Ipopt\bin'])
%     setenv('PATH', [getenv('PATH') ';C:\Ipopt\bin'])
%     mex -IC:\Ipopt\include C:\Ipopt\lib\ipopt.dll.lib mpc_wrapper.c mpc_solver.c
%     fprintf('MEX compilation successful\n');
% catch ME
%     fprintf('MEX compilation failed: %s\n', ME.message);
% end

try
    % setenv('PATH', [getenv('PATH') ';C:\Ipopt\bin'])
    setenv('PATH', [getenv('PATH') ';C:\Users\khanh\dev\matlab\Ipopt\bin'])
    mex -IC:\Users\khanh\dev\matlab\Ipopt\include C:\Users\khanh\dev\matlab\Ipopt\lib\ipopt.dll.lib mpc_wrapper.c mpc_solver_m1.c
    fprintf('MEX compilation successful\n');
catch ME
    fprintf('MEX compilation failed: %s\n', ME.message);
end