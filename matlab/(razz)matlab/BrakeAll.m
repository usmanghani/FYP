function BrakeAll
%Declaring globals needed for this operation
global ppo;
global Buffer;

%First, we need to ensure the object is runnig
if(isrunning(ppo))
  %Get present port pin status
  ppoval=getvalue(ppo);
  %AND with all zeros
  Buffer = bitand(ppoval,dec2binvec(hex2dec('00'),8));
end

  %Check to see whether the resulting bits are not the same
  %as the ones currently on the port's pins.
  if(binvec2dec(bitxor(Buffer,ppoval))~=0)
  putvalue(ppo,Buffer);
  end
end