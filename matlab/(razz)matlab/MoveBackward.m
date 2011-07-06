function MoveBackward(x)
%Declaring globals needed for this operation
global ppo;
global UP_OFF;
global DOWN_ON;
global DOWN_OFF;
global Buffer;

%First, we need to ensure the object is runnig
if(isrunning(ppo))
  
  %Get present port pin status
  ppoval=getvalue(ppo);
  
  %AND with UP_OFF to ensure that particular bit is 0
  Buffer = bitand(ppoval,dec2binvec(UP_OFF,8));
  
  %Depending on input param. 'x', use DOWN_ON or DOWN_OFF
  if(x==1)
  Buffer = bitor(Buffer,dec2binvec(DOWN_ON,8));
  else if(x==0)
  Buffer = bitand(Buffer,dec2binvec(DOWN_OFF,8));
      end
  end

  %Check to see whether the resulting bits are not the same
  %as the ones currently on the port's pins.
  if(binvec2dec(bitxor(Buffer,ppoval))~=0)
  putvalue(ppo,Buffer);
  end

end