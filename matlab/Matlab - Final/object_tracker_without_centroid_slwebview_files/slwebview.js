
// JavaScript library for the Simulink Web View

//   Copyright 1997-2005 The MathWorks, Inc.
//   $Revision: 1.1.6.1 $  $Date: 2005/12/19 07:34:00 $


// ============= Initialization and Setup ======================

function initialize(evt){
       changeSysHome(evt);       
       d = getDoc(evt); if (d){
         r = d.rootElement;if (r){
          //r.addEventListener('keypress',keyPressed,false); ASV3 has problems with keypress - move everything to keydown
          r.addEventListener('keydown',keyDown,false); 
          r.addEventListener('keyup',keyUp,false);
         }
       } 
       customizeContextMenu(evt);       
}

function getDoc(evt){
  d = window.svgDocument;
  if (!d && evt){
    t = evt.target;
    if (t){
      d = t.ownerDocument;  //mozilla
      window.svgDocument = d;
    }
  }
  return d;
}

function getKeyCode(evt){
    try {
      return evt.keyCode(); //ie
    } catch (errIE) {
      try {
        return evt.which; //mozilla
      } catch (errMOZ) {
        return false;
      }
    }
}

function getKeyChar(evt){
    kCode = getKeyCode(evt);
    //Handle numeric keypad entries
    switch (kCode){
//     case 110: return '.'; //unused
     case 109: return '-'; //numeric keypad
     case 107: return '+'; //numeric keypad
//     case 106: return '*'; //unused
//     case 111: return '/'; //unused
     case 105: return '9'; //numeric keypad
     case 104: return '8'; //numeric keypad
//     case 103: return '7'; //unused
     case 102: return '6'; //numeric keypad
     case 101: return '5'; //numeric keypad
     case 100: return '4'; //numeric keypad
     case 99:  return '3'; //numeric keypad
     case 98:  return '2'; //numeric keypad
     case 97:  return '1'; //numeric keypad
//     case 96:  return '0'; //unused
//     case 40:  return '2';  //down arrow
//     case 39:  return '6';  //right arrow
//     case 38:  return '8';  //up arrow
//     case 37:  return '4';  //left arrow
     case 27:  return '^escape';
     default:  return String.fromCharCode(kCode).toLowerCase();
    }
}

function keyDown(evt){
    keyName = getKeyChar(evt);
    if (keyName == 'p' || keyName == 'q' || keyName == '9'){addMousePanScrim(evt);} else //numeric keypad '9'
    if (keyName == 'h'){displayById(evt,'prop.navHelp');} else
    if (keyName == 'a'){displayById(evt,'prop.navAbout');} else
    if (keyName == 'f' || keyName == ' ' || keyName == '5'){ 
        if (isShiftPressed(evt)){
          fillScreenAll(evt); //shift-f zooms all to normal.  Undocumented for now.
        } else { 
          fillScreen(evt);
        }} else 
    if (keyName == '1'){ 
        if (isShiftPressed(evt)){
          zoomNormalAll(evt);  //shift-1 zooms all to normal.  Undocumented for now.
        } else { 
          zoomNormal(evt);
        }} else 
    if (keyName == 'd' || keyName == '4'){ panLeft(evt); } else
    if (keyName == 'e' || keyName == '8'){ panUp(evt); } else 
    if (keyName == 'c' || keyName == '2'){ panDown(evt); } else 
    if (keyName == 'g' || keyName == '6'){ panRight(evt); } else 
    if (keyName == 'r' || keyName == '+' || keyName == '='){ zoomIn(evt); } else 
    if (keyName == 'v' || keyName == '-'){ zoomOut(evt); } else 
    if (keyName == 'x' || keyName == '3'){ toggleExpose(evt); } else 
    if (keyName == '^escape'){ //clear state
      removeMousePanScrim(evt);
      unExposeAll(evt)
      dismissPropertyTables();
    }
    
}

function isShiftPressed(evt){
   if (evt.modifiers){ //pre-mozilla netscape
      return false; // not supported
   } else {
      return evt.shiftKey; //ie
   }
}

function keyUp(evt){
    keyName = getKeyChar(evt);
    if (keyName == 'p' || keyName == 'q' || keyName == '9'){removeMousePanScrim(evt);} else
    if (keyName == 'h'){dismissById(evt,'prop.navHelp');} else
    if (keyName == 'a'){dismissById(evt,'prop.navAbout');}
}

//function keyPressed(evt){keyName = getKeyChar(evt);}

//The Adobe SVG plug-in provides a special field "contextMenu" which is
//a DOM document containing information about the viewer plug-in.  It
//can be customized, which we are doing here.
function customizeContextMenu(evt){
    if (!window.contextMenu){return;}
 
    menuElement = window.contextMenu.getDocumentElement();
        childEl = menuElement.getFirstChild();
        while (childEl){
            menuElement.removeChild(childEl);
            childEl = menuElement.getFirstChild();
        }

        m = window.contextMenu.createElement('Header');
        m.appendChild(window.contextMenu.createTextNode('Simulink Web Viewer'));
        menuElement.appendChild(m);
        
        jaFlag = isJapanese();
        
        menuElement.appendChild(createContextMenuItem('zoomIn(evt)','zoomIn',(jaFlag ? '\u30BA\u30FC \u30E0\u30A4\u30F3 (&R)' : 'Zoom in (&R)')));
        menuElement.appendChild(createContextMenuItem('zoomOut(evt)','zoomOut',(jaFlag ? '\u30BA\u30FC\u30E0 \u30A2\u30A6\u30C8 (&V)' : 'Zoom out (&V)')));
        menuElement.appendChild(createContextMenuItem('fillScreen(evt)','fillScreen',(jaFlag ? '\u30D5\u30EB\u30B9\u30AF\u30EA\u30FC\u30F3\u306B\u62E1\u5927 (&F)' : 'Zoom to full screen (&F)')));
        menuElement.appendChild(createContextMenuItem('toggleMousePanScrim(evt)','toggleMousePanScrim',(jaFlag ? '\u30DE\u30A6\u30B9\u3067\u56DE\u8EE2 (&P)' : 'Pan with mouse (&P)')));  
        menuElement.appendChild(createContextMenuItem('toggleExpose(evt)','toggleExpose',(jaFlag ? '\u3059\u3079\u3066\u306E\u30EC\u30A4\u30E4\u30FC\u3092\u8868\u793A (&X)' : 'Show all layers (&X)')));

        menuElement.appendChild(window.contextMenu.createElement('separator'));

        menuElement.appendChild(createContextMenuItemBuiltin('Find','Find',(jaFlag ? '\u30C6\u30AD\u30B9\u30C8\u306E\u691C\u7D22' : 'Find text')));
        menuElement.appendChild(createContextMenuItemBuiltin('Copy','Copy',(jaFlag ? '\u30C6\u30AD\u30B9\u30C8\u306E\u30B3\u30D4\u30FC' : 'Copy text')));
        
        menuElement.appendChild(window.contextMenu.createElement('separator'));

        menuElement.appendChild(createContextMenuItemBuiltin('OriginalView','OriginalView',(jaFlag ? '\u8868\u793A\u306E\u30EA\u30BB\u30C3\u30C8' : 'Reset view')));  
        menuElement.appendChild(createContextMenuItemBuiltin('About','About',(jaFlag ? '\u30D7\u30E9\u30B0\u30A4\u30F3\u306B\u3064\u3044\u3066...' : 'About plugin...'))); 

    }
    
/* Create a context menu which defines callbacks as custom javascript functions*/    
function createContextMenuItem(onActivate,id,textLabel){
        m = window.contextMenu.createElement('item');
        m.setAttributeNS(null,'onactivate',onActivate);
        m.setAttributeNS(null,'id',id);
        m.appendChild(window.contextMenu.createTextNode(textLabel));
        return m;
}    

/* Create a context menu which defines callbacks built-in functions*/    
function createContextMenuItemBuiltin(action,id,textLabel){
        m = window.contextMenu.createElement('item');
        m.setAttributeNS(null,'action',action);
        m.setAttributeNS(null,'id',id);
        m.appendChild(window.contextMenu.createTextNode(textLabel));
        return m;
}    
    
function isJapanese(){
  try {
   return (defaultFontFamily == 'MS-Gothic');
  } catch (errMsg){
   return false;
  }
  //return (navigator.language == 'ja') || (navigator.browserLanguage == 'ja') || (navigator.systemLanguage == 'ja') || (navigator.userLanguage == 'ja');
  //navigator.language (Netscape - Browser Localization)
  //navigator.browserLanguage (IE-Specific - Browser Localized Language)
  //navigator.systemLanguage (IE-Specific - Windows OS - Localized Language)
  //navigator.userLanguage (IE-Specific - Windows OS - Regional Settings)
}    

//Use this line to disable mozilla "find as you type".  It messes with key interaction.
//user_pref("accessibility.typeaheadfind.autostart", true);
//May be able to get the same effect by trapping <body onkeypress>


//=============== Show All Layers ==================================================

var isExposed = false;

function exposeAll(evt){
  isExposed = true;
  currCanvas = findCurrSysElement(evt);
  if (currCanvas){
      dismissPropertyTables(currCanvas);
      removeMousePanScrim(evt);
  }
  svgElements = findCanvasAll(evt);
  canvasCount = svgElements.length;
  wWidth  = parseFloat(window.innerWidth);
  wHeight = parseFloat(window.innerHeight)-30;
  canvasEdge = Math.sqrt(wWidth*wHeight/canvasCount); //upper bound
  rowCount = Math.ceil(wHeight/canvasEdge);
  colCount = Math.ceil(wWidth/canvasEdge);
  canvasEdge = Math.min(wHeight/rowCount,wWidth/colCount);

  squareX = 0;
  squareY = 0;
  

  for (i=0; i<canvasCount;i++){
      thisItem = svgElements.item(i);
      thisID = thisItem.getAttributeNS(null,'id').substring(7);
      vbPrev = thisItem.getAttributeNS(null,'viewBox');
      hPrev  = thisItem.getAttributeNS(null,'height');
      wPrev  = thisItem.getAttributeNS(null,'width');
      vbFull = thisItem.getAttributeNS(null,'original_viewBox');
      vbArray = new Array();vbArray = vbFull.split(' ');
      vbArray[3] = parseFloat(vbArray[3]);
      vbArray[2] = parseFloat(vbArray[2]);
      vbArray[1] = parseFloat(vbArray[1]);
      vbArray[0] = parseFloat(vbArray[0]);
      
      thisItem.setAttributeNS(null,'viewBox',vbFull);
      thisItem.setAttributeNS(null,'prev_viewBox',vbPrev);
      thisItem.setAttributeNS(null,'prev_height',hPrev);
      thisItem.setAttributeNS(null,'prev_width',wPrev);
      thisItem.setAttributeNS(null,'display','inline');
      thisItem.setAttributeNS(null,'height',canvasEdge);
      thisItem.setAttributeNS(null,'width',canvasEdge);
      thisItem.setAttributeNS(null,'x',squareX*canvasEdge);
      thisItem.setAttributeNS(null,'y',squareY*canvasEdge);

      scrim = findScrimElement(thisItem,thisID);
      //Set a tight scrim
      scrim.setAttributeNS(null,'x',vbArray[0]);
      scrim.setAttributeNS(null,'y',vbArray[1]);
      scrim.setAttributeNS(null,'width',vbArray[2]);
      scrim.setAttributeNS(null,'height',vbArray[3]);
      
      scrim.setAttributeNS(null,'fill','rgb(0%,255%,255%)');
      scrim.setAttributeNS(null,'fill-opacity','0');
      scrim.setAttributeNS(null,'onclick','unExposeAll(evt,"' + thisID + '")');
      scrim.setAttributeNS(null,'onmouseover','scrimHighlight(evt)');
      scrim.setAttributeNS(null,'onmouseout','scrimUnhighlight(evt)');
      scrim.setAttributeNS(null,'cursor','pointer');
      scrim.setAttributeNS(null,'onmousedown','');
      scrim.setAttributeNS(null,'onmouseup','');
      scrim.setAttributeNS(null,'pointer-events','all');
      scrim.setAttributeNS(null,'display','inline');
      thisItem.appendChild(scrim);

      if (squareX == colCount-1){
        squareX = 0;
        squareY++;
      } else {
        squareX++;
      }
      
      setTitleText('Show all layers. Select a layer or press "X" to cancel.','\u3059\u3079\u3066\u306E\u30EC\u30A4\u30E4\u30FC\u3092\u8868\u793A. Select a layer or press "X" to cancel.',evt);  //*JA*
  }
}

function unExposeAll(evt,sysName){
  if (!isExposed){return;}
  isExposed = false;
  svgElements = findCanvasAll(evt);
  canvasCount = svgElements.length;
  squareSize = Math.ceil(Math.sqrt(canvasCount-1));
  for (i=0; i<canvasCount;i++){
      thisItem = svgElements.item(i);
      thisID = thisItem.getAttributeNS(null,'id').substring(7);
      thisItem.setAttributeNS(null,'display','none');
      
      vbPrev = thisItem.getAttributeNS(null,'prev_viewBox');
      thisItem.setAttributeNS(null,'viewBox',vbPrev);
      
      hPrev = thisItem.getAttributeNS(null,'prev_height');
      thisItem.setAttributeNS(null,'height',hPrev);
      
      wPrev = thisItem.getAttributeNS(null,'prev_width');
      thisItem.setAttributeNS(null,'width',wPrev);
      
      thisItem.setAttributeNS(null,'x','0');
      thisItem.setAttributeNS(null,'y','0');

      scrim = findScrimElement(thisItem,thisID);
      if (scrim){
         //scrim.parentNode.removeChild(scrim);
         scrim.setAttributeNS(null,'display','none');
         scrim.setAttributeNS(null,'pointer-events','none');
      }
  }

  if (!sysName){
     sysName = currSys;
     addToPrevStack = false;
  } else {
     addToPrevStack = (sysName != currSys);
  }
  changeSysByName(evt,sysName,addToPrevStack);
}

function toggleExpose(evt){
  if (isExposed){unExposeAll(evt);} 
  else {exposeAll(evt);}
}

function scrimHighlight(evt){
  evt.target.setAttributeNS(null,'fill-opacity','.1');
  updateTitle(evt.target.parentNode,evt);
}

function scrimUnhighlight(evt){
  evt.target.setAttributeNS(null,'fill-opacity','0');
}

//================ Zooming  ====================================
var ZF_HEIGHT = '95%'; //Zoom full height
var ZF_WIDTH  = '100%'; //Zoom full width

function fillScreenByLayer(thisCanvas){ 
   if (thisCanvas && !isExposed){
      vbOrig = thisCanvas.getAttributeNS(null,'original_viewBox');
      if (vbOrig){
          dismissPropertyTables(thisCanvas);
          thisCanvas.setAttributeNS(null,'viewBox',vbOrig);
          thisCanvas.setAttributeNS(null,'height',ZF_HEIGHT);
          thisCanvas.setAttributeNS(null,'width',ZF_WIDTH);
      }
   }
}
function fillScreen(evt){
  fillScreenByLayer(findCurrSysElement(evt));
//  setTitleText("Zoom to full screen","\u30D5\u30EB\u30B9\u30AF\u30EA\u30FC\u30F3\u306B\u62E1\u5927",evt);
}
function fillScreenAll(evt){
  //currCanvas = findCurrSysElement(evt);
  //currCanvas.setAttributeNS(null,'display','none');
  svgElements = findCanvasAll(evt);canvasCount = svgElements.length;
  for (canvasIdx=0; canvasIdx<canvasCount;canvasIdx++){
      thisCanvas = svgElements.item(canvasIdx);
      //thisCanvas.setAttributeNS(null,'display','inline');
      fillScreenByLayer(thisCanvas);
      //window.setTimeout("",0);
      //thisCanvas.setAttributeNS(null,'display','none');
  }
  //currCanvas.setAttributeNS(null,'display','inline');
  setTitleText("Zoom to full screen (all layers)","\u30D5\u30EB\u30B9\u30AF\u30EA\u30FC\u30F3\u306B\u62E1\u5927 (all layers)",evt); //*JA*
}

  
var ZN_PAD = 1024;  //Zoom normal padding

function zoomAbsoluteByLayer(currCanvas,zoomFactor){ 
   if (currCanvas && !isExposed){
      vbOrig = currCanvas.getAttributeNS(null,'original_viewBox');if (vbOrig){
          //currCanvas.setAttributeNS(null,'viewBox',vbOrig);
          vbArray = new Array();vbArray = vbOrig.split(' ');
          vbArray[3] = parseFloat(vbArray[3]);
          vbArray[2] = parseFloat(vbArray[2]);
          vbArray[1] = parseFloat(vbArray[1]);
          vbArray[0] = parseFloat(vbArray[0]);
          
          currCanvas.setAttributeNS(null,'width' ,(vbArray[2]-vbArray[0])*zoomFactor+ZN_PAD);
          currCanvas.setAttributeNS(null,'height',(vbArray[3]-vbArray[1])*zoomFactor+ZN_PAD);
          vbArray[3] = vbArray[3]+ZN_PAD/zoomFactor;
          vbArray[2] = vbArray[2]+ZN_PAD/zoomFactor;
          
          currCanvas.setAttributeNS(null,'viewBox',vbArray.join(' '));
      }
   }
}
function zoomNormal(evt){
  zoomAbsoluteByLayer(findCurrSysElement(evt),1);
//  setTitleText("Zoom to 100%","100% \u306B\u62E1\u5927",evt); 
}
function zoomNormalAll(evt){
  svgElements = findCanvasAll(evt);
  for (i=0; i<svgElements.length;i++){
      zoomAbsoluteByLayer(svgElements.item(i),1);
  }
  setTitleText("Zoom to 100% (all layers)","100% \u306B\u62E1\u5927 (all layers)",evt); //*JA*
}
 
function zoomRelative(evt,zoomFactor){ 
   currCanvas = findCurrSysElement(evt);
   if (currCanvas && !isExposed){
      dismissPropertyTables(currCanvas);
      vbCurr = currCanvas.getAttributeNS(null,'viewBox');
      if (!vbCurr){vbCurr = currCanvas.getAttributeNS(null,'original_viewBox');}
      vbCurrArray = new Array();vbCurrArray = vbCurr.split(' ');
      vbCurrArray[3] = parseFloat(vbCurrArray[3]);
      vbCurrArray[2] = parseFloat(vbCurrArray[2]);
      vbCurrArray[1] = parseFloat(vbCurrArray[1]);
      vbCurrArray[0] = parseFloat(vbCurrArray[0]);
      
      w = currCanvas.getAttributeNS(null,'width');
      if (w && w != ZF_WIDTH){
         vbOrig = currCanvas.getAttributeNS(null,'original_viewBox');      
         vbOrigArray = new Array();vbOrigArray = vbOrig.split(' ');
         vbOrigArray[3] = parseFloat(vbOrigArray[3]);
         vbOrigArray[2] = parseFloat(vbOrigArray[2]);
//         vbOrigArray[1] = parseFloat(vbOrigArray[1]);
//         vbOrigArray[0] = parseFloat(vbOrigArray[0]);
         vbCurrArray[3] = (vbCurrArray[3]-vbOrigArray[3])/zoomFactor + vbOrigArray[3];
         vbCurrArray[2] = (vbCurrArray[2]-vbOrigArray[2])/zoomFactor + vbOrigArray[2];
      
         currCanvas.setAttributeNS(null,'width',(parseFloat(w)-ZN_PAD)*zoomFactor+ZN_PAD);
         h = currCanvas.getAttributeNS(null,'height');if (h && h != ZF_HEIGHT){
         currCanvas.setAttributeNS(null,'height',(parseFloat(h)-ZN_PAD)*zoomFactor+ZN_PAD);}
      } else {
         vbCurrArray[3] = vbCurrArray[3]/zoomFactor;
         vbCurrArray[2] = vbCurrArray[2]/zoomFactor;
      }
      currCanvas.setAttributeNS(null,'viewBox',vbCurrArray.join(' '));
   }
} 

function zoomIn(evt){zoomRelative(evt,10/9);}
function zoomOut(evt){zoomRelative(evt,9/10);}
 

//====================== Panning =========================== 

/** 
 * vbIdx can be 0 or 1.  When 0, operate on vb[0] and vb[2] (horizontal)
 * direction can be -1 or 1.  When positive, shift away from origin.
 */
function panRelative(evt, vbIdx, direction){ 
   currCanvas = findCurrSysElement(evt);
   if (currCanvas && !isExposed){
      vbCurr = currCanvas.getAttributeNS(null,'viewBox');
      if (!vbCurr){vbCurr = currCanvas.getAttributeNS(null,'original_viewBox');}  
      if (vbCurr){
          dismissPropertyTables(currCanvas);
          vbArray = new Array();vbArray = vbCurr.split(' ');
          if (currCanvas.getAttributeNS(null,'height') != ZF_HEIGHT){
            vbOrig = currCanvas.getAttributeNS(null,'original_viewBox');      
            vbOrigArray = new Array();vbOrigArray = vbOrig.split(' ');
            shiftBase = parseFloat(vbOrigArray[2+vbIdx]);
          } else {
            shiftBase = parseFloat(vbArray[2+vbIdx]);
          }
          vbArray[0+vbIdx] = parseFloat(vbArray[0+vbIdx]) + direction*(shiftBase/10);
          currCanvas.setAttributeNS(null,'viewBox',vbArray.join(' '));
      }
   }
}

function panUp(evt){panRelative(evt,1,-1);}
function panDown(evt){panRelative(evt,1,1);}
function panLeft(evt){panRelative(evt,0,-1);}
function panRight(evt){panRelative(evt,0,1);}

var dragMode = false;
var dragStartY = 0;
var dragStartX = 0;
var dragStartViewBox = 0;
var dragStartWidth = 0;
var dragStartHeight = 0;


function toggleMousePanScrim(evt){
  if (dragMode){
    removeMousePanScrim(evt);
  } else {
    addMousePanScrim(evt,'Pan with mouse.  Press "P" to resume normal viewing.','\u30DE\u30A6\u30B9\u3067\u56DE\u8EE2  Press "P" to resume normal viewing.');
  }
}

function addMousePanScrim(evt,engStatus,jaStatus){
   if (dragMode || isExposed){return;}
   dragMode = true;
   d = getDoc(evt);
   currCanvas = findCurrSysElement(evt);
   if (currCanvas){
      dismissPropertyTables(currCanvas);
      
      vbOrig = currCanvas.getAttributeNS(null,'original_viewBox');
      vbArray = new Array();
      if (vbOrig){
          vbArray = vbOrig.split(' ');
          vbArray[3] = parseFloat(vbArray[3]);
          vbArray[2] = parseFloat(vbArray[2]);
          vbArray[1] = parseFloat(vbArray[1]);
          vbArray[0] = parseFloat(vbArray[0]);
      } else {
          vbArray[3] = 800;
          vbArray[2] = 600;
          vbArray[1] = 0;
          vbArray[0] = 0;
      }

      scrim = findScrimElement(currCanvas,currSys);
      
      scrim.setAttributeNS(null,'x',vbArray[0]-4096-10);
      scrim.setAttributeNS(null,'y',vbArray[1]-4096-10);
      scrim.setAttributeNS(null,'width',vbArray[2]-vbArray[0]+2*4096+2*10);
      scrim.setAttributeNS(null,'height',vbArray[3]-vbArray[1]+2*4096+2*10);
      
      scrim.setAttributeNS(null,'fill','rgb(0%,0%,0%)'); 
      scrim.setAttributeNS(null,'fill-opacity','.04'); 
      scrim.setAttributeNS(null,'onmousedown','startMousePan(evt)');
      scrim.setAttributeNS(null,'onmouseup','endMousePan(evt)');
      scrim.setAttributeNS(null,'onmouseout','endMousePan(evt)');
      scrim.setAttributeNS(null,'onmouseover','');
      scrim.setAttributeNS(null,'cursor','move');
      scrim.setAttributeNS(null,'pointer-events','all');
      scrim.setAttributeNS(null,'display','inline');
      currCanvas.appendChild(scrim);
      
      if (!engStatus){engStatus='Pan with mouse.  Release key to resume normal viewing.';};
      if (!jaStatus){jaStatus = '\u30DE\u30A6\u30B9\u3067\u56DE\u8EE2  Release key to resume normal viewing.';}

      setTitleText(engStatus,jaStatus);
   }
}

function removeMousePanScrim(evt){
   scrim = findScrimElement(findCurrSysElement(evt),currSys);
   if (scrim){
      scrim.setAttributeNS(null,'display','none');
      scrim.setAttributeNS(null,'pointer-events','none');
   }
   updateTitle(0,evt);
   dragMode = false;
}



function startMousePan(evt){
   dragStartY = evt.clientY;
   dragStartX = evt.clientX;

   evt.target.setAttributeNS(null,'onmousemove','doMousePan(evt)');

   currCanvas = findCurrSysElement(evt);
   if (currCanvas && !isExposed){
      vbCurr = currCanvas.getAttributeNS(null,'viewBox');
      if (!vbCurr){vbCurr = currCanvas.getAttributeNS(null,'original_viewBox');}
      dragStartViewBox = new Array();dragStartViewBox = vbCurr.split(' ');
      dragStartViewBox[0] = parseFloat(dragStartViewBox[0]);
      dragStartViewBox[1] = parseFloat(dragStartViewBox[1]);
      dragStartViewBox[2] = parseFloat(dragStartViewBox[2]);
      dragStartViewBox[3] = parseFloat(dragStartViewBox[3]);
      
      /* Get size of the canvas so we can translate screen
         units to the local coordinate system */
      correctAspectRatio = false;
      dragStartWidth = currCanvas.getAttributeNS(null,'width');
      if (dragStartWidth == ZF_WIDTH){
        correctAspectRatio = true;
        dragStartWidth = parseFloat(window.innerWidth);
      } else {
        dragStartWidth = parseFloat(dragStartWidth);
      }
      
      dragStartHeight = currCanvas.getAttributeNS(null,'height');
      if (dragStartHeight == ZF_HEIGHT){
        correctAspectRatio = true;
        dragStartHeight = parseFloat(window.innerHeight)*.95;
      } else {
        dragStartHeight = parseFloat(dragStartHeight);
      }
      
      if (correctAspectRatio){
        if (dragStartHeight > dragStartWidth){
           dragStartHeight = dragStartWidth*dragStartViewBox[3]/dragStartViewBox[2];
        } else {
           dragStartWidth = dragStartHeight*dragStartViewBox[2]/dragStartViewBox[3];
        }
      }
      
   }
}

function endMousePan(evt){
   evt.target.setAttributeNS(null,'onmousemove','');
   dragStartViewBox = 0;
   var dragStartY = 0;
   var dragStartX = 0;
}

function doMousePan(evt){
   var posY = evt.clientY;
   var posX = evt.clientX;
   
   currCanvas = findCurrSysElement(evt);
   if (currCanvas && !isExposed){
      newXo = dragStartViewBox[0] - (posX - dragStartX)*dragStartViewBox[2]/dragStartWidth;   
      newYo = dragStartViewBox[1] - (posY - dragStartY)*dragStartViewBox[3]/dragStartHeight;
      
      currCanvas.setAttributeNS(null,'viewBox', newXo + ' ' + newYo + ' ' + dragStartViewBox[2] + ' ' + dragStartViewBox[3]);
   }
}

//================= Inter-Layer Navigation ==============================

var prevSys = new Array();
var currSys = '';
var currSysElement = false;


function changeSysHome(evt){
  changeSysByName(evt,homeSys,false);
}

function changeSysPrev(evt){
  if (prevSys.length>0){
    prevSysName = prevSys[prevSys.length-1];
    prevSys.length = prevSys.length-1;
    changeSysByName(evt,prevSysName,false);
  }
}

function changeSysByName(evt,newSys,addToPrevStack){
  removeMousePanScrim(evt);  //turn off panning, if it is activated
  unExposeAll(evt);
  newSysGroup = findCanvasById(newSys,evt);
  if (newSysGroup){ 
   currSysGroup = findCurrSysElement(evt);
   if (currSysGroup){ 
    currSysGroup.setAttributeNS(null,'display','none');
   }
   newSysGroup.setAttributeNS(null,'display','inline');
   if (addToPrevStack){ 
    prevSys[prevSys.length] = currSys; 
   } 
   currSys = newSys;
   currSysElement = newSysGroup;

   updateTitle(newSysGroup,evt);

   notHome = (currSys != homeSys);
   enableNavHome(notHome,evt);
   enableNavPrev(notHome && prevSys.length > 0,evt);
   
  } 
}

var buttonNavHome = false;
function enableNavHome(isEnabled,evt){
   if (!buttonNavHome){buttonNavHome = getDoc(evt).getElementById('navHome');}
   enableNavBtn(isEnabled,buttonNavHome);
}

var buttonNavPrev = false;
function enableNavPrev(isEnabled,evt){
   if (!buttonNavPrev){buttonNavPrev = getDoc(evt).getElementById('navPrev');}
   enableNavBtn(isEnabled,buttonNavPrev);
}
function enableNavBtn(isEnabled, navBtn){
  if (navBtn){
     if (isEnabled){
        navBtn.setAttributeNS(null,'pointer-events','all');
        navBtn.setAttributeNS(null,'onmouseover','showProp(evt);highlight(evt,1)');
        navBtn.setAttributeNS(null,'onmouseout','hideProp(evt);unhighlight(evt,1)');        
        navBtn.setAttributeNS(null,'stroke','rgb(0,0,0)');        
        navBtn.setAttributeNS(null,'cursor','pointer');        
     } else {
        navBtn.setAttributeNS(null,'pointer-events','none');
        navBtn.setAttributeNS(null,'onmouseover','showProp(evt)');
        navBtn.setAttributeNS(null,'onmouseout','hideProp(evt);unhighlight(evt,1)');        
        //navBtn.setAttributeNS(null,'onmouseout','hideProp(evt);');        
        navBtn.setAttributeNS(null,'stroke','rgb(75%,75%,75%)');        
        navBtn.setAttributeNS(null,'cursor','auto');        
     }
  }
}

function changeSys(evt){
  changeSysByName(evt,getCurrentTargetId(evt),true);
}

//==================== Title Handling =====================
function updateTitle(sysGroup,evt){
   if (!sysGroup){
       thisID = currSys;
       sysGroup = findCurrSysElement(evt);
   } else {
       thisID = sysGroup.getAttributeNS(null,'id');
       if (thisID.substr(0,7)=='canvas.'){
         thisID = thisID.substring(7);
       }
   }

   if (sysGroup){
     sysTitle = findChildById(sysGroup,'title.' + thisID);
     if (sysTitle){
        titleTextNode = sysTitle.firstChild;
        if (titleTextNode){
          titleText = titleTextNode.data;
          //titleText = titleTextNode.getData();
          setTitleText(titleText,titleText,evt);
        }
     }
   }
}

var titleTextNodeEn = false;
var titleTextNodeJa = false;

function setTitleText(enString,jaString,evt){
   
   if (!titleTextNodeEn || !titleTextNodeJa){
    //If we haven't cached the title text nodes, find them now
    d = getDoc(evt);
    titleElement = d.getElementById('navTitle');
    if (titleElement){
       textElements = titleElement.getElementsByTagName('text');
       for (i=0;i<textElements.length;i++){
          thisText = textElements.item(i);
          thisLang = thisText.getAttribute('systemLanguage');
          cdataNode = thisText.firstChild;  //getFirstChild()
          if (!cdataNode){
            cdataNode = d.createTextNode();
            thisText.appendChild(cdataNode);
          }
          
          if (thisLang == 'ja'){
             titleTextNodeJa = cdataNode;
          } else {
             titleTextNodeEn = cdataNode;
//             cdataNode.data = enString; //setData(enString);
          }
       }
     }
   }
   
   if (titleTextNodeEn){
     titleTextNodeEn.data = enString;
   }
   if (titleTextNodeJa){
     if (jaString){
       titleTextNodeJa.data = jaString;
     } else {
       titleTextNodeJa.data = enString;
     }
   }
}

//=================== Mouse Interaction ===============================

function getCurrentTargetId(evt){
  t = evt.currentTarget;
  if (t){
     return t.getAttributeNS(null,'id');
  } else {
     return '';
  }
}

function showPropAndHighlight(evt){
  id = getCurrentTargetId(evt);
  updateTitle(evt.currentTarget,evt);
  showProp(evt,id);
  highlight(evt,id);
}
function hidePropAndUnhighlight(evt){
  id = getCurrentTargetId(evt);
  hideProp(evt,id);
  updateTitle(false,evt);
  unhighlight(evt,id);
}

//  ===== Property Tables ========
function getPropGroup(evt,id){
   if (!id){id = getCurrentTargetId(evt);}
   return findSiblingByIdReverse(evt.currentTarget,'prop.' + id);
}

var i_showPropertyTables = true;
function toggleShowPropertyTables(){i_showPropertyTables = !i_showPropertyTables;}


function showProp(evt,id){
   if (i_showPropertyTables){
     displayByElement(getPropGroup(evt,id));
   }
}
function hideProp(evt,id){dismissByElement(getPropGroup(evt,id));}


function displayByElement(targetElement){
  if (targetElement){
    p = targetElement.parentNode;
    if (p){
      p.appendChild(targetElement);
      positionPropTable(targetElement,p);
    }
    targetElement.setAttributeNS(null,'display','inline');
  }
}
function displayById(evt,targetId){displayByElement(getDoc(evt).getElementById(targetId));}
function displayTarget(evt){evt.currentTarget.setAttributeNS(null,'display','inline');}

function dismissByElement(targetElement){
  if (targetElement){
   targetElement.setAttributeNS(null,'display','none');
  }
}
function dismissById(evt,targetId){dismissByElement(getDoc(evt).getElementById(targetId));}
function dismissTarget(evt){dismissByElement(evt.currentTarget);}

function positionPropTable(targetElement,p){
  vbParent = p.getAttributeNS(null,'viewBox');if (!vbParent){return;}
      vbArray = new Array();vbArray = vbParent.split(' ');
      vbArray[3] = parseFloat(vbArray[3]); //height
      vbArray[2] = parseFloat(vbArray[2]); //width
      vbArray[1] = parseFloat(vbArray[1]); //top edge
      vbArray[0] = parseFloat(vbArray[0]); //left edge
  
  wParent  = p.getAttributeNS(null,'width');  if (!wParent){return;}
  hParent  = p.getAttributeNS(null,'height'); if (!hParent){return;}
  
  hThis = targetElement.getAttributeNS(null,'extent_Height');if (!hThis){return;}else{hThis=parseFloat(hThis);}
  wThis = targetElement.getAttributeNS(null,'extent_Width');if (!wThis){return;}else{wThis=parseFloat(wThis);}
  xThis = targetElement.getAttributeNS(null,'preferred_X');if (!xThis){return;}else{xThis=parseFloat(xThis);}
  yThis = targetElement.getAttributeNS(null,'preferred_Y');if (!yThis){return;}else{yThis=parseFloat(yThis);}
  wWindow  = parseFloat(window.innerWidth);
  hWindow  = parseFloat(window.innerHeight)-30;
  
  if (wParent == ZF_WIDTH){
    //viewbox is at least entirely visible on screen
    //There is also some extra room in the direction unconstrained by aspect ratio.
    //We can increase the actual vbArray [2] or [3] to compensate
    arWindow = hWindow/wWindow;
    if (arWindow>vbArray[3]/vbArray[2]){ //width-constrained, increase vbHeight
       vbArray[3] = arWindow*vbArray[2];
    } else { //height-constrained, increase vbWidth
       vbArray[2] = vbArray[3]/arWindow;    
    }
  } else {
    wParent=parseFloat(wParent);
    hParent=parseFloat(hParent);
    //When in fixed scaling, the viewbox always runs an extra ZN_PAD pixels
    //Adjust to get the actual visible size
    vbArray[2] = vbArray[2]*wWindow/wParent;
    vbArray[3] = vbArray[3]*(hWindow-30)/hParent;
  }
  rightEdge = vbArray[2]+vbArray[0];
  bottomEdge = vbArray[3]+vbArray[1];
  
  if (hThis > .95*vbArray[3]){
    yThis = vbArray[1]+.01*vbArray[3];
    yscale = vbArray[3]/hThis*.95;
  } else {
    yscale = 1;
    if (yThis+hThis > bottomEdge){
      yThis = Math.max(bottomEdge-1.01*hThis,vbArray[1]+.01*vbArray[3]);
    }
  }
  
  if (wThis > .95*vbArray[2]){
    xThis = vbArray[0]+.01*vbArray[2];
    xscale = vbArray[2]/wThis*.95;
  } else {
    xscale = 1;
    if (xThis+wThis > rightEdge){
      xThis = Math.max(rightEdge-1.01*wThis,vbArray[0]+.01*vbArray[2]);
    }
  }
  
  scale = Math.min(xscale,yscale);
  if (scale < 1){
    targetElement.setAttributeNS(null,'transform','translate('+ xThis +','+ yThis + ') scale(' + scale + ')');  
  } else {
    targetElement.setAttributeNS(null,'transform','translate('+ xThis +','+ yThis + ')');  
  }
  
  


}



/** Clears property tables AND removes filter effects **/
function dismissPropertyTables(svgElement){
  if (!svgElement){svgElement = findCurrSysElement();}
  gElements = svgElement.getElementsByTagName('g');
  for (i=0;i<gElements.length;i++){
     gThis = gElements.item(i);
     if (gThis.getAttributeNS(null,'id').substr(0,5) == 'prop.' && gThis.getAttributeNS(null,'display') == 'inline'){
       gThis.setAttributeNS(null,'display','none');
     } else if (gThis.getAttributeNS(null,'filter') == 'url(#highlight)'){
       gThis.setAttributeNS(null,'filter','none');
     }
  }
}


//====== Highlighting ===============
/**
 * highlight(evt) will highlight only if a corresponding canvas exists
 * highlight(evt,1) will always highlight
 */
function highlight(evt,id){
  if (!id){id = getCurrentTargetId(evt);}
  t = evt.currentTarget;
  tCursor = t.getAttributeNS(null,'cursor');
  if (!tCursor){ //check to see if the object is linkable (once per session)
     if (id==1 || findCanvasById(id,evt)){
        tCursor = 'pointer';
     } else {
        tCursor = 'auto';
     } 
     t.setAttributeNS(null,'cursor',tCursor);
  }
  if (tCursor == 'pointer'){ 
    evt.currentTarget.setAttributeNS(null,'filter','url(#highlight)');
  }
}

function unhighlight(evt,id){
    evt.currentTarget.setAttributeNS(null,'filter','none');
}

function highlightHelpKey(evt,whichKey){
    keyRect = findChildById(evt.currentTarget,'helpkey.' + whichKey);
    if (keyRect){
       keyRect.setAttributeNS(null,'filter','url(#highlight)');
       keyRect.setAttributeNS(null,'cursor','pointer');
    }
    t = evt.currentTarget;
    if (t){
      helpRect = t.parentNode;
      if (helpRect){helpRect.setAttributeNS(null,'display','inline');}
    }
}
function unhighlightHelpKey(evt,whichKey){
    keyRect = findChildById(evt.currentTarget,'helpkey.' + whichKey);
    if (keyRect){keyRect.setAttributeNS(null,'filter','none');}
}

//=============== General Purpose ==================
function findChildById(thisNode,id){
  if (!thisNode){return false;}
  childNode = thisNode.firstChild;
  while (childNode){
     if (childNode.nodeType == 1){ //element
        if (childNode.getAttributeNS(null,'id') == id){
          return childNode;
        }
     }
     childNode = childNode.nextSibling;
  }
  return false;
}

function findChildByIdReverse(thisNode,id){
  if (!thisNode){return false;}
  childNode = thisNode.lastChild;
  while (childNode){
     if (childNode.nodeType == 1){ //element
        if (childNode.getAttributeNS(null,'id') == id){
          return childNode;
        }
     }
     childNode = childNode.previousSibling;
  }
  return false;
}

function findSiblingById(thisNode,id){
   if (!thisNode){return false;}
   return findChildById(thisNode.parentNode,id);
}

function findSiblingByIdReverse(thisNode,id){
   if (!thisNode){return false;}
   return findChildByIdReverse(thisNode.parentNode,id);
}


/**
 *  Finds the scrim for the given canvas <svg> element.  Creates
 *  one if necessary.
 *
 *  Note that this does not add the scrim as the node's child.  That
 *  is the responsibility of the caller.
 * 
 *  To find the scrim for the current canvas:
 *  scrim = findScrimElement(findCurrSysElement(evt),currSys);
 */
function findScrimElement(currCanvas,id){
  scrim = findChildByIdReverse(currCanvas,'scrim.' + id);
  if (!scrim && currCanvas){
    //SvgDocument also has more-specific createRectElement methods.  use these?
    scrim = currCanvas.ownerDocument.createElement('rect');
    scrim.setAttributeNS(null,'id','scrim.' + thisID);
  }
  return scrim;
}


var i_canvasGroup = false;
function findCanvasGroup(evt){
  if (!i_canvasGroup){
     i_canvasGroup = getDoc(evt).getElementById('group.canvas');
  }
  return i_canvasGroup;
}

function findCanvasById(id,evt){
  return findChildById(findCanvasGroup(evt),'canvas.' + id);
}

function findCanvasAll(evt){
  return findCanvasGroup(evt).getElementsByTagName('svg')
}

function findCurrSysElement(evt){
   if (!currSysElement){
      if (currSys){
         currSysElement = findCanvasById(currSys,evt);
      }
   }
   return currSysElement;
}

