function rtwmakecfg()
  rtw.addIncludePaths({ fullfile(pwd,'include'), 'C:\Users\khanh\dev\matlab\casadi-3.7.1-windows64-matlab2018b\include', 'C:\Users\khanh\dev\matlab\Ipopt\include' });
  rtw.addSourcePaths({ fullfile(pwd,'src') });
  rtw.addLibraryPaths({ 'C:\Users\khanh\dev\matlab\casadi-3.7.1-windows64-matlab2018b\lib', 'C:\Users\khanh\dev\matlab\Ipopt\lib' });
  % Library names without prefix/suffix; order matters on some systems
  rtw.addLibraries({ 'ipopt','blas','lapack' }); % add mumps/metis/etc if your Ipopt build needs them
end
