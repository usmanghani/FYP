function MoveLeft(x)
%Declaring globals needed for this operation
global ppo;
global RIGHT_OFF;
global LEFT_ON;
global LEFT_OFF;
global Buffer;

%First, we need to ensure the object is runnig
if(isrunning(ppo))

  %Get present port pin status
  ppoval=getvalue(ppo);
  
  %AND with RIGHT_OFF to ensure that particular bit is 0
  Buffer = bitand(ppoval,dec2binvec(RIGHT_OFF,8));
  
  %Depending on input param. 'x', use LEFT_ON or LEFT_OFF
  if(x==1)
  Buffer = bitor(Buffer,dec2binvec(LEFT_ON,8));
  else if(x==0)
  Buffer = bitand(Buffer,dec2binvec(LEFT_OFF,8));
      end
  end

  %Check to see whether the resulting bits are not the same
  %as the ones currently on the port's pins.
  if(binvec2dec(bitxor(Buffer,ppoval))~=0)
  putvalue(ppo,Buffer);
  end

end