%Declare our global variables
global ppo;
global LEFT_ON;
global LEFT_OFF;
global RIGHT_ON;
global RIGHT_OFF;
global UP_ON;
global UP_OFF;
global DOWN_ON;
global DOWN_OFF;
global Buffer;

%Set constants
%LEFT_ON = [0 0 0 0 1 0 0 0];
LEFT_ON=hex2dec('08');
%LEFT_OFF = [1 1 1 1 0 1 1 1];
LEFT_OFF=hex2dec('F7');
%RIGHT_ON = [0 0 0 0 0 1 0 0];
RIGHT_ON=hex2dec('04');
%RIGHT_OFF = [1 1 1 1  1 0 1 1];
RIGHT_OFF = hex2dec('FB');
%UP_ON = [0 0 0 0 0 0 0 1];
UP_ON = hex2dec('01');
%UP_OFF = [1 1 1 1 1 1 1 0];
UP_OFF=hex2dec('FE');
%DOWN_ON = [0 0 0 0 0 0 1 0];
DOWN_ON=hex2dec('02');
%DOWN_OFF = [1 1 1 1 1 1 0 1];
DOWN_OFF=hex2dec('FD');
Buffer=hex2dec('00');

%Instantiate our digitalio device object
ppo = digitalio('parallel','LPT1');

%Add output lines and start
ppolines = addline(ppo,0:7,0,'out');
start(ppo);

%Sending all zeros to the port at first
putvalue(ppo.Line(1:8),dec2binvec(Buffer,8));