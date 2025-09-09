%%
clear; clc; close all;

%%
import casadi.*

x = MX.sym('x',2);
y = MX.sym('y');

w = dot(x,y*x);
z = sin(x)+y+w;

% CasADi function with two inputs and two outputs
% f = Function('f',{x,y},{w,z+res.x});
f = Function('f',{x,y},{w,z});


%% generate basic function using casadi codegen
f.generate('f.c')

%% generate basic function using casadi codegen and optional settings
% Use the numeric types from simulink to codegenerate
cg_options = struct;
cg_options.casadi_real = 'real_T';
cg_options.real_min    = num2str(realmin); % Needed if you code-generate sqpmethod method  
cg_options.casadi_int  = 'int_T';
cg_options.with_header = true;
cg = CodeGenerator('f_with_header',cg_options);
cg.add_include('simstruc.h');
cg.add(f);
cg.generate();

disp('CasADi codegen completed: created f_with_header.c')