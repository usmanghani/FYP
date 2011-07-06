function writeXML(filename, v)
%
% Transforms a struct or struct array into an XML file
%
% filename = name of the XML file
% v = struct variable containing fields of type char or numeric
%
% xml.tag.object ='foo'
% xml.tag.property(1) = {'foobar1'}
% xml.tag.property(2) = {'foobar2'}
% xml.tag.childrens(1).name ='Pedro'
% xml.tag.childrens(1).age ='12'
% xml.tag.childrens(2).name ='Juan'
% xml.tag.childrens(2).age ='15'
%
% writeXML(filename, xml) will generate a .xml file that contains:
%
% <tag>
%   <object>
%       foo
%   </object>
%   <property>
%       foobar1
%   </property>
%   <property>
%       foobar2
%   </property>
%   <childrens>
%      <name>
%        Pedro
%      </name>
%      <age>
%        12
%      </age>
%   </childrens>
%   <childrens>
%      <name>
%        Juan
%      </name>
%      <age>
%        15
%      </age>
%   </childrens>
% </tag>
%

xml = struct2xml(v);

% Open file
fid = fopen(filename,'w');
fprintf(fid, xml);
% Close file
fclose(fid);


