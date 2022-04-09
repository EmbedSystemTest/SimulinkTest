function [ ] = run_info_recorder( info, mode )
%     coder.extrinsic('evalin','assignin','sprintf','extract_specified_element','disp');
%     coder('-sync:on','evalin','assignin');
    assignin('base','run_info',sprintf('%s%s#%f$',evalin('base','run_info'),num2str(mode),info));
end

