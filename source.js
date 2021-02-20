var floor=Math.floor;
var min=Math.min;
var max=Math.max;
var abs=Math.abs;

var sldebug=0;

var scale=1;

var Menu_leftSelection=0,Menu_rightSelection=40,Menu_cursorInMenu=false,Menu_penSize=2,Menu_dotLimit=0;

const WIDTH=416,HEIGHT=464

var buttonflash=0,Menu_bgMode=2,Menu_zoomLevel=0,zoomx=0,zoomy=0,Menu_copyMode=false
var copyx1=8,copyy1=8,copyx2=8,copyy2=8
var copydata=[],copymeta=[],wa=-1
var Menu_gridSize=0,Menu_paused=false,Menu_gameSpeed=0,Menu_edgeMode=0,Menu_penMode=0,penlockmode=0,penlinestartx=0,penlinestarty=0,Menu_numberMenu=false,Menu_minimapEnabled=false
var Ia=new PGImage;
var text="",customfont="",selectedfont=0,selectedfontstyle=0,selectedfontsize=0;

var Parts_MAX=40000;
const Parts_limits=[20000,30000,Parts_MAX];
const fonts=["sans-serif","serif","monospace","setFont ->"];
const fontstyles=["PLAIN","BOLD","ITALIC","BOLD&ITALIC"];
const fontsizes=[12,14,16,18,20,24,30,36,48,60,72];
const elementbuttons=38;

//elements
const Parts_POWDER=2,WATER=3,FIRE=4,SEED=5,WOOD=6,GUNPOWDER=7,FAN=8,ICE=10,SNOW=11,STEAM=12,SUPERBALL=13,CLONE=14,FIREWORKS=15,OIL=16,C4=17,STONE=19;
const MAGMA=20,VIRUS=21,NITRO=23,ANT=24,TORCH=25,GAS=26,SOAPY=27,THUNDER=28,METAL=29,BOMB=31,LASER=33,ACID=34,VINE=35,SALT=36,SALTWATER=37,GLASS=38;
const BIRD=39,MERCURY=41,SPARK=42,FUSE=43,CLOUD=44,PUMP=45;

//fake element IDs
const Parts_BLOCK=-1,Parts_BALL=-2,Parts_WHEEL=-3,Parts_BGFAN=-4,Parts_EMPTY=-5;

//save data fake elements
const Save_BALL=40;

//menu buttons
const Button_WIND=40,Button_AIR=41,M_DRAG=42,Button_BUBBLE=43,Button_WHEEL=44,Button_PLAYER=45,Button_FIGHTER=46,Button_BOX=47,Button_BALL=48,M_CREATE=49,M_BLOCK=50;
const M_ERASE=51,M_CLEAR=52,Button_COPYPASTE=53,Button_TEXT=54,Button_PEN=55,Button_PENSIZE=56,Button_SCALE=57,Button_SPEED=58,M_START=59,M_UPLOAD=60,Button_SAVE=61;
const Button_LOAD=62,Button_MINIMAP=63,Button_MENU=64,Button_SIDE=65,Button_GRID=66,Button_BG=67,Button_DOT=68,Button_RESET=69;
const Button_FAN=6,Button_LASER=26;

//bg modes
const Bg_NONE=0,Bg_AIR=1,Bg_LINE=2,Bg_BLUR=3,Bg_SHADE=4,Bg_AURA=5,Bg_LIGHT=6,Bg_TOON=7,Bg_MESH=8,Bg_GRAY=9,Bg_TRACK=10,Bg_DARK=11,Bg_TG=12,Bg_SILUET=13;

//menu button->element id
const menuelements=    [Parts_POWDER,WATER,FIRE,SEED,WOOD,GUNPOWDER,FAN,ICE ,SNOW,STEAM,SUPERBALL,CLONE,FIREWORKS,OIL,C4,STONE,MAGMA,VIRUS,NITRO,ANT,TORCH,GAS,SOAPY,THUNDER,METAL,BOMB,LASER,ACID,VINE,SALT,SALTWATER,GLASS,BIRD,MERCURY,SPARK,FUSE,CLOUD,PUMP,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
const fireworkelements=[Parts_POWDER,WATER,FIRE,SEED,0   ,GUNPOWDER,0  ,0   ,SNOW,STEAM,SUPERBALL,0    ,0        ,OIL,0 ,STONE,MAGMA,VIRUS,NITRO,ANT,0    ,GAS,SOAPY,THUNDER,0    ,BOMB,LASER,ACID,0   ,SALT,SALTWATER,0    ,BIRD,MERCURY,SPARK,0   ,CLOUD,0   ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
const playerelements=  [Parts_POWDER,WATER,FIRE,SEED,0   ,GUNPOWDER,FAN,0   ,SNOW,STEAM,SUPERBALL,0    ,FIREWORKS,OIL,0 ,STONE,MAGMA,VIRUS,NITRO,ANT,0    ,GAS,SOAPY,0      ,0    ,BOMB,LASER,ACID,0   ,SALT,SALTWATER,0    ,BIRD,MERCURY,SPARK,0   ,CLOUD,0   ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
const ballelements=    [Parts_POWDER,WATER,FIRE,SEED,WOOD,GUNPOWDER,FAN,ICE ,0   ,STEAM,0        ,CLONE,0        ,OIL,C4,STONE,MAGMA,VIRUS,NITRO,0  ,TORCH,GAS,SOAPY,THUNDER,METAL,BOMB,0    ,ACID,0   ,SALT,SALTWATER,GLASS,BIRD,0      ,0    ,FUSE,CLOUD,PUMP,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];

//element states
const State_NONE=0,State_POWDER=1,State_LIQUID=2,State_HOT=3,State_SOLID=4,State_GAS=5;

//element id->state
const states=[0,0,State_POWDER,State_LIQUID,State_HOT,State_POWDER,State_SOLID,State_POWDER,State_NONE,0,State_SOLID,State_POWDER,State_NONE,State_POWDER,State_SOLID,State_POWDER,State_LIQUID,State_SOLID,0,State_POWDER,State_HOT,State_POWDER,0,State_LIQUID,State_POWDER,State_HOT,State_GAS,State_LIQUID,State_HOT,State_SOLID,0,State_POWDER,0,State_HOT,State_LIQUID,State_SOLID,State_POWDER,State_LIQUID,State_SOLID,State_GAS,0,State_LIQUID,State_HOT,State_SOLID,State_GAS,State_SOLID];

const playervalidelements=[0,0,1,1,1,1,0,1,1,0,0,1,1,1,0,1,1,0,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,1,0,1,1,0,1,0,1,1,0,1,0];

//element id->color
var colors=[0,0x606060,0xF2BD6B,0x4040FF,0xFF4040,0x90C040,0x805020,0xB08050,0x8080FF,0xB0A090,0xD0D0FF,0xFFFFFF,0xE0E0E0,0xFF40A0,0x907010,0xFF9966,0x803020,0xFFFFCC,0xFFE0AE,0x808080,0xFF6633,0x800080,0xFFE0AE,0x447700,0xC080C0,0xFFA020,0xCC9999,0xE0E0E0,0xFFFF20,0x404040,0xFFE0AE,0x666600,0xFFE0AE,0xCC0000,0xCCFF00,0x00BB00,0xFFFFFF,0x3399FF,0x011111,0x807050,0xFFE0AE,0xAAAAAA,0xFFCC33,0x443322,0xCCCCCC,0x003333];

const Parts_TEMPERATURE=[0,0,0,0,5000,500,500,0,0,0,-1000,-500,0,0,0,0,0,0,0,0,10000,0,0,0,1500,4000,500,0,2000,0,0,0,0,5500,0,500,0,0,0,2000,0,0,3000,0,0,0];

const Parts_DISSOLVERATE=[0,0,5,40,10,5,10,10,0,0,40,10,30,10,0,10,30,100,0,20,50,10,0,100,5,10,5,30,0,10,0,10,0,5,0,10,5,40,0,10,0,20,5,50,5,0];

//entities
const Entities_FIGHTER=10,Entities_BOX=20,Entities_PLAYER=30,Entities_CREATE=40

const Of=20;

//pen modes
const P_FREE=0,P_LINE=1,P_LOCK=2,P_PAINT=3;

var Keys={
	LOWER:Array(256),
	UPPER:Array(256),
	pressed:Array(256),
	rising1:Array(256),
	rising:Array(256)
}

//bg things
var lights=Array(309*WIDTH),aura1=Array(309*WIDTH),aura2=Array(309*WIDTH);
var normalmenuimage=new PGImage;
var Ya=new PGImage,text_x,text_y,savedataarray=[],savemetaarray=[],globalusercookie="",japanese=false,publicsavedata="",savetext,globalthumbnail=Array(0x1000),globalcolorpalette
var jb=0,loaded=0,errno=0,carefullycreated=0,carefullycreated2=0;

window.GameSave=save;
function save(a){
	if(a==""||publicsavedata!=""){
		return "";
	}
	save1();
	makesavestring();
	return savetext+generatechecksum(savetext);
}
//make checksum.
function generatechecksum(savedata){
	var checksum=0;
	for(var i=0;i<savedata.length;i++){
		checksum+=savedata.charCodeAt(i)*((i&0xFF)+1);
	}
	return charadd("a",checksum&0xF)+charadd("A",checksum>>4&0xF)+charadd("0",checksum>>8&0x7);
}
function charadd(char,offset){
	return String.fromCharCode(char.charCodeAt(0)+offset);
}
//check checksum. 0=no checksum, 1=correct checksum, -1=incorrect checksum.
function checkchecksum(savedata){
	var checksum=savedata.substring(savedata.length-3)
	if(checksum[0]>="a"&&checksum[0]<="p"&&checksum[1]>="A"&&checksum[1]<="P"&&checksum[2]>="0"&&checksum[2]<="7"){
		return (generatechecksum(savedata.substring(0,savedata.length-3))==checksum)?1:-1;
	}else{
		return 0;
	}
}
var globalsavedata="";
window.GameLoad=load;
function load(savedata){
	if(savedata.length){
		var haschecksum=checkchecksum(savedata);
		if(haschecksum==0){
			console.log("no checksum detected, you dirty thief");
		}else{
			savedata=savedata.substring(0,savedata.length-3);
			if(haschecksum==1){
				console.log("checksum detected, ignoring");
			}else{
				console.log("incorrect checksum detected, ignoring");
			}
		}
		globalsavedata=savedata;
		return 0;
	}else if(globalsavedata.length){
		savetext=globalsavedata;
		globalsavedata="";
		loadsavestring();
		load1();
	}
	return -1
}

var auth=0;
function start(usercookie,language,savestring){
	if(auth==0){
		if(usercookie)
			globalusercookie=usercookie;
		if(language=="0"){
			japanese=true;
		}if(savestring){
			publicsavedata=savestring;
		}
		yb();
		k.loadimage("font.gif",8,12);
		wheelimage.loadimage("wheel.gif");
		auth++;
	}
	if(auth==1){
		readimagedata(k.image);
		readimagedata(wheelimage);
		if(imagesloaded!=0){
			setTimeout(start,Eb());
		}else{
			auth++;
		}
	}
	if(auth==2){
		if(globalusercookie.length==0){
			jb=2;
			errno=1;
		}
		if(publicsavedata.length!=0){
			jb=2;
			errno=3;
		}
		Fb.reset(0);
		copydata=Array(120000);
		copymeta=Array(120000);
		savedataarray=Array(120000);
		savemetaarray=Array(120000);
		save1();
		if(publicsavedata.length>0){
			savetext=send(publicsavedata,"");
			if(Hb==1){
				loadsavestring();
				load1();
				loaded=1;
				Menu_paused=true;
			}else{
				loaded=2;
			}
		}
		save1();
		makesavestring();
		//generate grayscale colors
		for(var i=0;i<colors.length;i++){
			var color=colors[i]
			var brightness=floor((color>>16&0xFF)*0.2989+(color>>8&0xFF)*0.5866+(color&0xFF)*0.1145);
			grays[i]=brightness<<16|brightness<<8|brightness;
		}
		rectangle(0,0,WIDTH,HEIGHT,0x404040);
		spacedtext(211,451,"(C) 2007 ha55ii",-1,0,-1);
		k.drawtext(16,311,"POWDER",0xF2BD6B,0);
		k.drawtext(16,325,"WATER",0x4040FF,0);
		k.drawtext(16,339,"FIRE",0xFF4040,0);
		k.drawtext(16,353,"SEED",0x90C040,0);
		k.drawtext(16,367,"WOOD",0x805020,0);
		spacedtext(16,381,"G-POWDER",-1,0,-2);
		spacedtext(16,381,"G-POWDER",0xB08050,-1,-2);
		k.drawtext(16,395,"FAN",0x8080FF,0);
		k.drawtext(16,409,"ICE",0xD0D0FF,0);
		k.drawtext(16,423,"SNOW",0xFFFFFF,0);
		k.drawtext(16,437,"STEAM",0xE0E0E0,0);
		
		k.drawtext(72,311,"S-BALL",0xFF40A0,0);
		k.drawtext(72,325,"CLONE",0x907010,0);
		spacedtext(72,339,"F-WORKS",0xFF9966,0,-1);
		k.drawtext(72,353,"OIL",0x803020,0);
		k.drawtext(72,367,"C-4",0xFFFFCC,0);
		k.drawtext(72,381,"STONE",0x808080,0);
		k.drawtext(72,395,"MAGMA",0xFF6633,0);
		k.drawtext(72,409,"VIRUS",0x800080,0);
		k.drawtext(72,423,"NITRO",0x447700,0);
		k.drawtext(72,437,"ANT",0xC080C0,0);
		
		k.drawtext(128,311,"TORCH",0xFFA020,0);
		k.drawtext(128,325,"GAS",0xCC9999,0);
		k.drawtext(128,339,"SOAPY",0xE0E0E0,0);
		spacedtext(128,353,"THUNDER",0xFFFF20,0,-1);
		k.drawtext(128,367,"METAL",0x404040,0);
		k.drawtext(128,381,"BOMB",0x666600,0);
		k.drawtext(128,395,"LASER",0xCC0000,0);
		k.drawtext(128,409,"ACID",0xCCFF00,0);
		k.drawtext(128,423,"VINE",0x00BB00,0);
		k.drawtext(128,437,"SALT",0xFFFFFF,0);
		
 		spacedtext(184,311,"S-WATER",0x3399FF,0,-1);
		k.drawtext(184,325,"GLASS",0x404040,0);
		k.drawtext(184,339,"BIRD",0x807050,0);
		spacedtext(184,353,"MERCURY",0xAAAAAA,0,-1);
		k.drawtext(184,367,"SPARK",0xFFCC33,0);
		k.drawtext(184,381,"FUSE",0x443322,0);
		k.drawtext(184,395,"CLOUD",0xCCCCCC,0);
		k.drawtext(184,409,"PUMP",0x003333,0);
		
		k.drawtext(240,311,"WIND",0x8080FF,0);
		k.drawtext(240,325,"AIR",0x8080FF,0);
		k.drawtext(240,339,"DRAG",0xFFFFFF,0);
		k.drawtext(240,353,"B",0xFFE0E0,0);
		k.drawtext(240,353," U",0xFFFFE0,0);
		k.drawtext(240,353,"  B",0xE0FFE0,0);
		k.drawtext(240,353,"   B",0xE0FFFF,0);
		k.drawtext(240,353,"    L",0xE0E0FF,0);
		k.drawtext(240,353,"     E",0xFFE0FF,0);
		k.drawtext(240,367,"WHEEL",0xB0A090,0);
		k.drawtext(240,381,"PLAYER",0xF2BD6B,0);
		spacedtext(240,395,"FIGHTER",0xF2BD6B,0,-1);
		k.drawtext(240,409,"BOX",0xF2BD6B,0);
		k.drawtext(240,423,"BALL",0xF2BD6B,0);
		k.drawtext(240,437,"CREATE",0x907010,0);
		k.drawtext(296,311,"BLOCK",0x808080,0);
		k.drawtext(296,325,"ERASE",0x808080,0); //rename?
		k.drawtext(296,339,"CLEAR",0xFFFFFF,0);
		spacedtext(295,353,"Copy",-1,0,-2);
		spacedtext(295,353,"Copy",0xFFFFFF,-1,-2);
		spacedtext(319,353,"Paste",-1,0,-3);
		spacedtext(319,353,"Paste",0xFFFFFF,-1,-3);
		k.drawtext(296,367,"TEXT",0xFFFFFF,0);
		spacedtext(296,381,"PEN",-1,0,-1);
		spacedtext(296,381,"PEN",0xFFFFFF,-1,-1);
		spacedtext(296,395,"PEN-S ",0xFFFFFF,0,-1);
		spacedtext(296,409,"SCALE",0xFFFFFF,0,-1);
		spacedtext(296,423,"SPEEDx",0xFFFFFF,0,-1);
		spacedtext(295,437,"Start",-1,0,-3);
		spacedtext(295,437,"Start",0xFFFFFF,-1,-3);
		spacedtext(321,437,"Stop",-1,0,-2);
		spacedtext(321,437,"Stop",0xFFFFFF,-1,-2);
		k.drawtext(352,311,"UPLOAD",0xFFA0A0,0);
		k.drawtext(352,325,"SAVE",0xFFA0A0,0);
		k.drawtext(352,339,"LOAD",0xFFA0A0,0);
		spacedtext(352,353,"MiniMap",0xFFA0A0,0,-1);
		spacedtext(352,367,"MENU-",-1,0,-2);
		spacedtext(352,367,"MENU-",0xFFFFFF,-1,-2);
		spacedtext(352,381,"SIDE-",-1,0,-3);
		spacedtext(352,381,"SIDE-",0xFFFFFF,-1,-3);
		k.drawtext(352,395,"GRID",0x800000,0);
		spacedtext(352,409,"BG-",-1,0,-2);
		spacedtext(352,409,"BG-",0xFFFFFF,-1,-2);
		k.drawtext(352,423,"DOT ",0xFFFFFF,0);
		k.drawtext(352,437,"RESET",0xFFFFFF,0);
		spacedtext(64,451,"x    y",-1,0,-1);
		spacedtext(141,451,"dot",-1,0,-1);
		setsize(normalmenuimage,WIDTH,HEIGHT-308);
		for(var a=WIDTH*308;a<WIDTH*HEIGHT;a++){
			normalmenuimage.imagedata[a-WIDTH*308]=screenbuffer[a];
		}
		screenbuffer.fill(0);
		main();
	}
}

window.fff=Ob;
function Ob(){
	save("");
	load("");
	Fb.move();
	Fb.Bg_effects();
	var a,d,b,c,e,f;
	d=mouse.old.x;
	b=mouse.old.y;
	if(b>=300&&risingmouseclick){
		Menu_cursorInMenu=true;
	}else if(b<300){
		Menu_cursorInMenu=false;
	}
	c=12;
	e=311;
	//copy normal menu image into screen buffer
	screenbuffer.set(normalmenuimage.imagedata,WIDTH*308);
	if(Menu_numberMenu){
		//clear element names (except first letter)
		rectangle(c+4+0+8,e+0,48,137,0x404040);
		rectangle(c+4+56+8,e+0,48,137,0x404040);
		rectangle(c+4+112+8,e+0,48,137,0x404040);
		rectangle(c+4+168+8,e+0,48,137,0x404040);
		rectangle(c+4+224+8,e+42,47,53,0x404040);
		rectangle(c+4+224+16,e+98,39,25,0x404040);
		rectangle(c+4+224+8,e+126,47,11,0x404040);
		rectangle(c+4+112+8-1,e+0+4+14*3,1,7,0x404040);//clear part of THUNDER
		var counts=Array(48);
		for(a=0;a<counts.length;a++){
			counts[a]=0;
		}
		for(a=0;a<Parts_used;a++){
			counts[Parts_type[a]]++;
		}
		//display counts
		spacedtext(c+4+0,e+0,"  "+counts[Parts_POWDER],0xF2BD6B,0,-1);
		spacedtext(c+4+0,e+14,"  "+counts[WATER],0x4040FF,0,-1);
		spacedtext(c+4+0,e+28,"  "+counts[FIRE],0xFF4040,0,-1);
		spacedtext(c+4+0,e+42,"  "+counts[SEED],0x90C040,0,-1);
		spacedtext(c+4+0,e+56,"  "+counts[WOOD],0x805020,0,-1);
		spacedtext(c+4+0,e+70,"  "+counts[GUNPOWDER],0xB08050,0,-1);
		spacedtext(c+4+0,e+84,"  "+counts[FAN],0x8080FF,0,-1);
		spacedtext(c+4+0,e+98,"  "+counts[ICE],0xD0D0FF,0,-1);
		spacedtext(c+4+0,e+112,"  "+counts[SNOW],0xFFFFFF,0,-1);
		spacedtext(c+4+0,e+126,"  "+counts[STEAM],0xE0E0E0,0,-1);

		spacedtext(c+4+56,e+0,"  "+counts[SUPERBALL],0xFF40A0,0,-1);
		spacedtext(c+4+56,e+14,"  "+counts[CLONE],0x907010,0,-1);
		spacedtext(c+4+56,e+28,"  "+counts[FIREWORKS],0xFF9966,0,-1);
		spacedtext(c+4+56,e+42,"  "+counts[OIL],0x803020,0,-1);
		spacedtext(c+4+56,e+56,"  "+counts[C4],0xFFFFCC,0,-1);
		spacedtext(c+4+56,e+70,"  "+counts[STONE],0x808080,0,-1);
		spacedtext(c+4+56,e+84,"  "+counts[MAGMA],0xFF6633,0,-1);
		spacedtext(c+4+56,e+98,"  "+counts[VIRUS],0x800080,0,-1);
		spacedtext(c+4+56,e+112,"  "+counts[NITRO],0x447700,0,-1);
		spacedtext(c+4+56,e+126,"  "+counts[ANT],0xC080C0,0,-1);

		spacedtext(c+4+112,e+0,"  "+counts[TORCH],0xFFA020,0,-1);
		spacedtext(c+4+112,e+14,"  "+counts[GAS],0xCC9999,0,-1);
		spacedtext(c+4+112,e+28,"  "+counts[SOAPY],0xE0E0E0,0,-1);
		spacedtext(c+4+112,e+42,"  "+counts[THUNDER],0xFFFF20,0,-1);
		spacedtext(c+4+112,e+56,"  "+counts[METAL],0x404040,0,-1);
		spacedtext(c+4+112,e+70,"  "+counts[BOMB],0x666600,0,-1);
		spacedtext(c+4+112,e+84,"  "+counts[LASER],0xCC0000,0,-1);
		spacedtext(c+4+112,e+98,"  "+counts[ACID],0xCCFF00,0,-1);
		spacedtext(c+4+112,e+112,"  "+counts[VINE],0x00BB00,0,-1);
		spacedtext(c+4+112,e+126,"  "+counts[SALT],0xFFFFFF,0,-1);

		spacedtext(c+4+168,e+0,"  "+counts[SALTWATER],0x3399FF,0,-1);
		spacedtext(c+4+168,e+14,"  "+counts[GLASS],0x404040,0,-1);
		spacedtext(c+4+168,e+28,"  "+counts[BIRD],0x807050,0,-1);
		spacedtext(c+4+168,e+42,"  "+counts[MERCURY],0xAAAAAA,0,-1);
		spacedtext(c+4+168,e+56,"  "+counts[SPARK],0xFFCC33,0,-1);
		spacedtext(c+4+168,e+70,"  "+counts[FUSE],0x443322,0,-1);
		spacedtext(c+4+168,e+84,"  "+counts[CLOUD],0xCCCCCC,0,-1);
		spacedtext(c+4+168,e+98,"  "+counts[PUMP],0x003333,0,-1);
		
		spacedtext(c+4+224,e+42,"  "+Bubbles.used,0xFFE0E0,0,-1);
		spacedtext(c+4+224,e+56,"  "+Wheels.used,0xB0A090,0,-1);
		
		counts.fill(a,0,5);
		for(a=0;a<Entities.used;a++){
			if(Entities.type[a]>=Entities_CREATE){
				counts[4]++;
			}else if(Entities.type[a]>=Entities_PLAYER){
				counts[2]++;
			}else if(Entities.type[a]>=Entities_BOX){
				counts[1]++;
			}else if(Entities.type[a]>=Entities_FIGHTER){
				counts[0]++;
			}
		}
		for(a=0;a<Balls.MAX;a++){
			if(Balls.used[a]){
				counts[3]++;
			}
		}
		spacedtext(c+4+224,e+70,"  "+counts[2],0xF2BD6B,0,-1); //player
		spacedtext(c+4+224,e+84,"  "+counts[0],0xF2BD6B,0,-1); //fighter
		spacedtext(c+4+224,e+98,"   "+counts[1],0xF2BD6B,0,-1); //box
		spacedtext(c+4+224,e+112,"   "+counts[3],0xF2BD6B,0,-1); //ball
		spacedtext(c+4+224,e+126,"  "+counts[4],0x907010,0,-1); //create
	}
	//shortcut keys
	if(risingmouseclick&&wa==0){
		//0-9 to select pen size (this was actually broken in the official JavaScript release!)
		if(Keys.rising[48]){
			Menu_penSize=0;
		}else if(Keys.rising[49]){
			Menu_penSize=1;
		}else if(Keys.rising[50]){
			Menu_penSize=2;
		}else if(Keys.rising[51]){
			Menu_penSize=3;
		}else if(Keys.rising[52]){
			Menu_penSize=4;
		}else if(Keys.rising[53]){
			Menu_penSize=5;
		}else if(Keys.rising[54]){
			Menu_penSize=6;
		}else if(Keys.rising[55]){
			Menu_penSize=7;
		}else if(Keys.rising[56]){
			Menu_penSize=8;
		}else if(Keys.rising[57]){
			Menu_penSize=9;
		//space to pause/unpause
		}else if(Keys.rising[32]){
			Menu_paused=!Menu_paused;
		//enter to advance one frame
		}else if(Keys.rising[10]||Keys.rising[13]||Keys.rising[70]||Keys.rising[102]){
			Menu_paused=true;
		//l=load (also previously broken)
		}else if(Keys.rising[108]){
			loadsavestring();
			load1();
			buttonflash=-10;
		}
	}
	if(mouseinside(c-8,e-8,391,139)&&Menu_cursorInMenu&&wa==0){
		d=floor((d-(c-8))/56);
		b=floor((b-(e-8))/14);
		a=clamp(10*d+b,0,69);
		//38 and 39 are the empty menu spaces
		switch(a){
		case Button_COPYPASTE:
			if(mouse.rising.left){
				if(Menu_leftSelection==Button_COPYPASTE){
					Menu_copyMode=!Menu_copyMode;
				}
				Menu_leftSelection=a;
			}
			if(mouse.rising.right){
				if(Menu_rightSelection==Button_COPYPASTE){
					Menu_copyMode=!Menu_copyMode;
				}
				Menu_rightSelection=a;
			}
		break;case Button_PEN:
			Menu_penMode=wrap(Menu_penMode+fallingmousedirection,3);
		break;case Button_PENSIZE:
			Menu_penSize=wrap(Menu_penSize+fallingmousedirection,9);
		break;case Button_SCALE:
			if(mouse.rising.left){
				if(Button_SCALE==Menu_leftSelection&&Menu_zoomLevel<4){
					Menu_zoomLevel++
					zoomx+=400>>Menu_zoomLevel>>1;
					zoomy+=300>>Menu_zoomLevel>>1;
				}else if(Button_SCALE==Menu_leftSelection){
					Menu_zoomLevel=0;
				}
				Menu_leftSelection=a;
			}else if(mouse.rising.right){
				if(Button_SCALE==Menu_rightSelection&&Menu_zoomLevel>0){
					zoomx-=400>>Menu_zoomLevel>>1;
					zoomy-=300>>Menu_zoomLevel>>1;
					Menu_zoomLevel--;
				}else if(Button_SCALE==Menu_rightSelection){
					Menu_zoomLevel=4;
					zoomx+=200-(400>>Menu_zoomLevel>>1);
					zoomy+=150-(300>>Menu_zoomLevel>>1);
				}
				Menu_rightSelection=a;
			}
			zoomx=clamp(zoomx,0,400-(400>>Menu_zoomLevel));
			zoomy=clamp(zoomy,0,300-[300,150,75,38,19][Menu_zoomLevel]);
		break;case Button_SPEED:
			Menu_gameSpeed=wrap(Menu_gameSpeed+fallingmousedirection,3);
		break;case M_START:
			Menu_paused=wrap((Menu_paused?1:0)+fallingmousedirection,1)==1;
		break;case M_UPLOAD:
			if(fallingmousedirection!=0){
				wa=1;
			}
		break;case Button_SAVE:
			if(mouse.rising.left||mouse.rising.right){
				save1();
				makesavestring();
				buttonflash=10;
			}
		break;case Button_LOAD:
			if(fallingmousedirection!=0){
				loadsavestring();
				load1();
				buttonflash=-10;
			}
		break;case Button_MINIMAP:
			Menu_minimapEnabled=wrap(Menu_minimapEnabled+fallingmousedirection,1);
		break;case Button_MENU:
			Menu_numberMenu=wrap(Menu_numberMenu+fallingmousedirection,1);
		break;case Button_SIDE:
			Menu_edgeMode=wrap(Menu_edgeMode+fallingmousedirection,1);
		break;case Button_GRID:
			Menu_gridSize=wrap(Menu_gridSize+fallingmousedirection,7);
		break;case Button_BG:
			Menu_bgMode=wrap(Menu_bgMode+fallingmousedirection,13)
			if(fallingmousedirection!=0){
				for(a=309*WIDTH-1;a>=0;a--){
					lights[a]=0;
					aura1[a]=0;
					aura2[a]=0;
				}
			}
		break;case Button_DOT:
			Menu_dotLimit=wrap(Menu_dotLimit+fallingmousedirection,Parts_limits.length-1);
		break;case Button_RESET:
			if(fallingmousedirection!=0){
				Fb.reset(0);
			}
		break;default:
			if(a<elementbuttons||a>=40){
				if(mouse.rising.left){
					Menu_leftSelection=a;
				}else if(mouse.rising.right){
					Menu_rightSelection=a;
				}
			}
		}
		a=c+0+56*d;
		d=e-1+14*b;
		b=56;
		f=13;
		var g,q,n;
		b=a+b>WIDTH?WIDTH:floor(a+b);
		f=d+f>HEIGHT?HEIGHT:floor(d+f);
		a=a<0?0:floor(a);
		d=d<0?0:floor(d);
		q=d*WIDTH+a;
		for(n=WIDTH-(b-a);d<f;d++,q+=n){
			for(g=a;g<b;g++,q++){
				if(screenbuffer[q]>>>0==0x404040){
					screenbuffer[q]=0x400000;
				}
			}
		}
	}
	if(Menu_numberMenu){
		line(8,308,408,308,0x660000);
	}
	if(!Menu_copyMode){
		spacedtext(c+4+280-1,e+42,"Copy",0xFF4040,-1,-2);
	}else{
		spacedtext(c+4+280+23,e+42,"Paste",0xFF4040,-1,-3);
	}
	a=["free","line","lock","paint"];
	spacedtext(c+4+280,e+70,"    "+a[Menu_penMode],-1,0,-2);
	spacedtext(c+4+280,e+70,"    "+a[Menu_penMode],0xFFFFFF,-1,-2);
	spacedtext(c+4+280-1,e+84,"      "+Menu_penSize,0xFFFFFF,0,-1);
	spacedtext(c+4+280,e+98,"      "+["x1","x2","x4","x8","16"][Menu_zoomLevel],0xFFFFFF,0,-2);
	spacedtext(c+4+280,e+112,"       "+(1<<Menu_gameSpeed),0xFFFFFF,0,-2);
	if(!Menu_paused){
		spacedtext(c+4+280-1,e+126,"Start",0xFF4040,-1,-3);
	}else{
		spacedtext(c+4+280+25,e+126,"Stop",0xFF4040,-1,-2);
	}
	if(buttonflash>0){
		buttonflash--;
		if(buttonflash>1){
			k.drawtext(c+4+336,e+14,"SAVE",0xFFFFFF,0xFF0000)
		}
		
	}
	if(buttonflash<0){
		buttonflash++
		if(buttonflash<-1){
			k.drawtext(c+4+336,e+28,"LOAD",0xFFFFFF,0xFF0000)
		}
	}
	if(Menu_minimapEnabled){
		spacedtext(c+4+336,e+42,"MiniMap",0xFFFFFF,0xFF0000,-1);
	}
	a=["str","num"];
	spacedtext(c+4+336,e+56,"     "+a[Menu_numberMenu?1:0],-1,0,-2);
	spacedtext(c+4+336,e+56,"     "+a[Menu_numberMenu?1:0],0xFFFFFF,-1,-2);
	a=["OFF","LOOP"];
	spacedtext(c+4+336+25,e+70,a[Menu_edgeMode],-1,0,-2);
	spacedtext(c+4+336+25,e+70,a[Menu_edgeMode],0xFFFFFF,-1,-2);
	k.drawtext(c+4+336,e+84,"     "+Menu_gridSize,8388608,0);
	a=["none","air","line","blur","shade","aura","light","toon","mesh","gray","track","dark","TG","siluet"];
	spacedtext(c+4+336,e+98,"   "+a[Menu_bgMode],-1,0,-2);
	spacedtext(c+4+336,e+98,"   "+a[Menu_bgMode],0xFFFFFF,-1,-2);k.drawtext(c+4+336,e+112,"    "+"SML"[Menu_dotLimit],0xFFFFFF,0);
	rectangle(c+0+56*floor(Menu_leftSelection/10),e+Menu_leftSelection%10*14,3,3,0xFF0000);
	//rectangle(c+0+56*floor(Menu_middleSelection/10),e+4+Menu_middleSelection%10*14,3,3,0x00FF00);
	rectangle(c+0+56*floor(Menu_rightSelection/10),e+8+Menu_rightSelection%10*14,3,3,0x0000FF);
	spacedtext(64,451," "+(pen_x-8),-1,0,-1);
	spacedtext(64,451,"      "+(pen_y-8),-1,0,-1);
	spacedtext(141,451,"   "+(Parts_limits[Menu_dotLimit]-Parts_used),-1,0,-1);
	k.drawtext(16,451,fps+"fps",-1,0);
	if(sldebug==1){
		k.drawtext(64,451,Sc+"sl",0xFFFFFF,0);
	}
	//draw Menu_minimapEnabled
	if(Menu_minimapEnabled){
		c=15;
		if(mouse.old.x<116&&Menu_cursorInMenu){
			c=127;
		}
		e=314;
		rectangle(c-3,e-3,106,81,0x808080);
		save1();
		a=0;
		c=WIDTH*e+c;
		for(b=0;b<300;b+=4,c+=WIDTH-100){
			for(d=0;d<400;d+=4,c++){
				e=b*400+d;
				if(savedataarray[e]==0){
					e+=401;
				}
				a=
					Menu_bgMode==Bg_DARK?
						states[savedataarray[e]]==State_HOT?
							savedataarray[e]
						:
							0
					:
						Menu_bgMode==Bg_SILUET?
							savedataarray[e]==0?
								0
							:
								1
						:
							savedataarray[e];
				
				screenbuffer[c]=
					Menu_bgMode==Bg_GRAY?
						grays[a]
					:
						Menu_bgMode==Bg_SILUET?
							a==0?
								0xFFFFFF
							:
								0
						:
							colors[a];
			}
		}
	}
	if(wa==-1){
		wa++;
	}
	if(loaded==1){
		if(japanese){
			commontext(Ia,"\u30af\u30ea\u30c3\u30af\u3067\u518d\u751f\u3001\uff2c\uff2f\uff21\uff24\u3067\u518d\u30b9\u30bf\u30fc\u30c8");
		}else{
			commontext(Ia,"Click to play, LOAD to restart.");
		}
		loaded=0;
		wa=10;
	}else if(loaded==2){
		if(japanese){
			commontext(Ia,"\u30a8\u30e9\u30fc");
		}else{
			commontext(Ia,"Error");
		}
		loaded=0;
		wa=10;
	}
	if(wa==1){
		Menu_zoomLevel=0;
		if(jb==0){
			c="/score/dust.php?a="+globalusercookie+"&b="+(japanese?"0":"1");
			send(c,"");
			if(Hb==1&&responselines[0]=="ok"){
				jb=1;
			}else{
				jb=2;
				errno=responselines[0]=="err1"?1:responselines[0]=="err2"?2:responselines[0]=="err3"?3:responselines[0]=="err4"?4:responselines[0]=="err5"?5:0;
			}
		}
		wa++;
	}
	if(wa==2){
		if(jb==1){
			if(carefullycreated<50){
				wa=3;
				if(japanese){
					commontext(Ia,"\u3082\u3046\u5c11\u3057\u4f5c\u308a\u8fbc\u3093\u3067\u4e0b\u3055\u3044\u3002");
				}else{
					commontext(Ia,"Please carefully created.");
				}
				return;
			}
			if(japanese){
				commontext(Ia,"\u30bf\u30a4\u30c8\u30eb\u3092\u8a18\u5165\u3057\u3066\uff2f\uff2b\u3092\u62bc\u3057\u3066\u4e0b\u3055\u3044");
			}else{
				commontext(Ia,"Enter the title and click OK.");
			}
			text="";
		}else if(jb==2){
			if(japanese){
				if(errno==1){
					commontext(Ia,"\u30e6\u30fc\u30b6\u30fc\u767b\u9332\u304c\u5fc5\u8981\u3067\u3059");
				}else if(errno==2){
					commontext(Ia,"1\u65e5\u306b1\u56de\u306e\u307f\u3067\u3059");
				}else if(errno==3){
					commontext(Ia,"\u30c0\u30a6\u30f3\u30ed\u30fc\u30c9\u30c7\u30fc\u30bf");
				}else if(errno==4){
					commontext(Ia,"\u904e\u53bb12\u6642\u9593\u306e\u4f5c\u54c1\u6570\u304c50\u4ef6\u306b\u9054\u3057\u305f\u70ba\uff71\uff6f\uff8c\uff9f\u51fa\u6765\u307e\u305b\u3093");
				}else if(errno==5){
					commontext(Ia,"\u8a00\u8a9e\u30a8\u30e9\u30fc");
				}else{
					commontext(Ia,"\u30a2\u30c3\u30d7\u30ed\u30fc\u30c9\u51fa\u6765\u307e\u305b\u3093");
				}
			}else if(errno==1){
				commontext(Ia,"User registration is required.");
			}else if(errno==2){
				commontext(Ia,"1 time in 1 days only.");
			}else if(errno==3){
				commontext(Ia,"Download data.");
			}else if(errno==4){
				commontext(Ia,"Reached 50 posts in 12 hours. Cannot upload.");
			}else if(errno==5){
				commontext(Ia,"Language error.");
			}else{
				commontext(Ia,"Cannot upload.");
			}
		}
		wa++;
	}else if(wa==3){
		rectangle(48,100,320,100,0x808080);
		centeredtext(208,110,"UPLOAD",0xFFA0A0);
		Xc(135);
		//if(1==jb&&50<=carefullycreated&&(rectangle(92,150,232,16,0xFFFFFF),box(91,149,234,18,0),mouseinside(84,142,232,16)&&(box(91,149,234,18,0xFF0000),mouse.falling.left&&(c=input("Text",text),null!=c&&(text=c))),commontext(Ya,text),ad(Ya,93,150,230,16,230,16,0xFF000000),c=mouseinside(150,172,16,12),k.drawtext(158,180,"OK",c?0xFF0000:0xFFFFFF,0),c&&mouse.falling.left)){}
		if(jb==1&&carefullycreated>=50){
			rectangle(92,150,232,16,0xFFFFFF);
			box(91,149,234,18,0);
			if(mouseinside(84,142,232,16)){
				box(91,149,234,18,0xFF0000);
				if(mouse.falling.left){
					text=input("Text",text)||text;
				}
			}
			commontext(Ya,text);
			ad(Ya,93,150,230,16,230,16,0xFF000000);
			var uploadokbutton=mouseinside(150,172,16,12);
			k.drawtext(158,180,"OK",uploadokbutton?0xFF0000:0xFFFFFF,0);
		}
		if(jb==1&&uploadokbutton&&mouse.falling.left){
			if(text.length<2){
				commontext(Ia,lang("The title must be at least 2 characters.","\u30bf\u30a4\u30c8\u30eb\u3092\uff12\u6587\u5b57\u4ee5\u4e0a\u8a18\u5165\u3057\u3066\u4e0b\u3055\u3044"));
			}else{
				var titlelength=0;
				for(d=0;d<text.length;d++){
					b=text.charCodeAt(d);
					if(b>=0&&b<=128){
						titlelength+=1;
					}else if(b>=65377&&b<=65439){
						titlelength+=2;
					}
				}
				if(titlelength>20){
					if(japanese){
						commontext(Ia,"\u30bf\u30a4\u30c8\u30eb\u3092\uff11\uff10\u6587\u5b57\u4ee5\u4e0b\u3067\u8a18\u5165\u3057\u3066\u4e0b\u3055\u3044");
					}else{
						commontext(Ia,"The title must be 20 characters or less.");
					}
				}else{
					wa++
				}
			}
		}
		var uploadcancelbutton=mouseinside(200,172,48,12);
		k.drawtext(208,180,"CANCEL",uploadcancelbutton?0xFF0000:0xFFFFFF,0);
		if(uploadcancelbutton&&mouse.falling.left){
			wa=5;
		}
	}else if(wa==4){
		text=encodeURIComponent(text);
		if(text.length==0){
			wa=3;
			japanese?commontext(Ia,"\u30a8\u30e9\u30fc"):commontext(Ia,"Title encoding error.");
		}else{
			save1();
			makesavestring();
			if(savetext.length==605){ //will never trigger, min is 613
				wa=3;
				japanese?commontext(Ia,"\u30a8\u30e9\u30fc"):commontext(Ia,"Empty");
			}else{
				send("/score/dust.php?a="+globalusercookie+"&b="+(japanese?"0":"1")+"&c="+text,"d="+savetext+"&e="+globalthumbnail+"&f="+globalcolorpalette+"&g="+carefullycreated2);
				jb=2;
				wa++;
			}
		}
	}else if(wa==5){
		wa=0;
	}else if(wa==10){
		rectangle(82,308,252,70,0x600000);
		rectangle(86,312,244,62,0x606060);
		centeredtext(208,322,"DOWNLOAD",0xFFA0A0);
		Xc(343);
		if(mouse.old.x<200){
			centeredtext(178,365,"START",0xFF0000);
			centeredtext(238,365,"STOP",0xFFFFFF);
		}else{
			centeredtext(178,365,"START",0xFFFFFF)
			centeredtext(238,365,"STOP",0xFF0000)
		}
		if(mouse.falling.left){
			wa=0
			Menu_paused=mouse.old.x>=200;
		}else{
			if(Keys.pressed[37]||Keys.pressed[39]){
				wa=0;
				Menu_paused=!Keys.pressed[37];
			}
		}
	}else if(wa==20){
		text="";
		wa++;
	}else if(wa==21){
		rectangle(88,309,240,99,0x808080);
		rectangle(92,317,232,16,0xFFFFFF);
		box(91,316,234,18,0);
		if(mouseinside(84,309,232,16)){
			box(91,316,234,18,0xFF0000);
			if(mouse.falling.left){
				c=input("Text",text);
				if(c!=null){
					text=c;
				}
			}
		}
		k.drawtext(93,320,text.substr(0,28),0xFFFFFF,0);
		if(selectedfont==3){
			rectangle(240,340,84,16,0xFFFFFF);
			box(239,339,86,18,0);
			if(mouseinside(232,332,84,16)){
				box(239,339,86,18,0xFF0000);
				if(mouse.falling.left){
					c=input("setFont",customfont);
					if(c!=null){
						customfont=c;
					}
				}
			}
			k.drawtext(241,343,customfont,0xFFFFFF,0);
		}
		a=-1;
		if(mouse.old.x>=80&&mouse.old.x<220&&mouse.old.y>=334&&mouse.old.y<382){
			a=floor((mouse.old.y-334)/16)
			if(a==0&&fallingmousedirection!=0){
				selectedfont=wrap(selectedfont+fallingmousedirection,3);
			}
			if(a==1&&fallingmousedirection!=0){
				selectedfontstyle=wrap(selectedfontstyle+fallingmousedirection,3);
			}
			if(a==2&&fallingmousedirection!=0){
				selectedfontsize=wrap(selectedfontsize+fallingmousedirection,10);
			}
		}
		k.drawtext(92,342,"font :"+fonts[selectedfont],a==0?0xFF0000:0xFFFFFF,0);
		k.drawtext(92,358,"style:"+fontstyles[selectedfontstyle],a==1?0xFF0000:0xFFFFFF,0);
		k.drawtext(92,374,"size :"+fontsizes[selectedfontsize],a==2?0xFF0000:0xFFFFFF,0);
		a=-1;
		if(mouse.old.x>=80&&mouse.old.x<320&&mouse.old.y>=382&&mouse.old.y<400){
			a=mouse.old.x<200?0:1;
			if(mouse.falling.left){
				if(a==0){
					wa++;
				}else{
					wa=23;
				}
			}
		}
		k.drawtext(158,392,"OK",a==0?0xFF0000:0xFFFFFF,0);
		k.drawtext(208,392,"CANCEL",a==1?0xFF0000:0xFFFFFF,0);
		c=fonts[selectedfont];
		if(selectedfont==3){
			c=customfont;
		}
		shittext(Ya,text,c,selectedfontstyle,fontsizes[selectedfontsize]);
		c=Parts_POWDER;
		if(menuelements[Menu_leftSelection]!=0){
			c=menuelements[Menu_leftSelection];
		}else if(menuelements[Menu_rightSelection]!=0){
			c=menuelements[Menu_rightSelection];
		}
		ad(Ya,text_x,text_y,Ya.g,128,Ya.g,128,colors[c]);
	}else if(wa==22){
		shittext(Ya,text, selectedfont==3?customfont:fonts[selectedfont] ,selectedfontstyle,fontsizes[selectedfontsize]);
		c=menuelements[Menu_leftSelection]||menuelements[Menu_rightSelection]||Parts_POWDER;
		for(b=0;b<128&&!(text_y+b>=308);b++){
			for(d=0;d<400&&!(text_x+d>=408);d++){
				if(Ya.imagedata[b*Ya.width+d]!=-1 && parts[(text_y+b)*WIDTH+(text_x+d)]==Parts_EMPTY){
					e=Parts_create(text_x+d,text_y+b,c);
					if(e>=0&&c==FAN){
						Parts_vel[e].x=0.1*pen_dir.x;
						Parts_vel[e].y=0.1*pen_dir.y;
						parts[(text_y+b)*WIDTH+(text_x+d)]=Parts_BGFAN;
					}
				}
			}
		}
		wa++;
	}else if(wa==23){
		wa=0;
	}
}


var G=104,kd=79,H;
Air_CELLS=G*kd;
var Air={
	vel:Array(Air_CELLS),
	pres:new Float32Array(Air_CELLS),
	vel2:Array(Air_CELLS),
	pres2:new Float32Array(Air_CELLS)
};

for(H=0;H<Air_CELLS;H++){
	Air.vel[H]=new Vector;
}
for(H=0;H<Air_CELLS;H++){
	Air.vel2[H]=new Vector;
}

var pd,qd=new Int32Array(Air_CELLS),rd=new Int32Array(Air_CELLS),blocks=new Int32Array(Air_CELLS),pen_x,pen_y,sd,td,pen_dir=new Vector;
var grays=Array(colors.length);
var Fb=new yd;
function yd(){
	//uh ok
}
function lang(en,jp){
	if(japanese){
		return jp;
	}else{
		return en;
	}
}
//some kind of saving thing
function save1(){
	var i,x,y,xy
	savedataarray.fill(0);
	savemetaarray.fill(0);
	//save blocks
	for(y=0;y<300;y++){
		for(x=0;x<400;x++){
			xy=((y>>2)+2)*G+((x>>2)+2);
			if(blocks[xy]==1){
				savedataarray[400*y+x]=1;
			}
		}
	}
	//save particles
	for(i=0;i<Parts_used;i++){
		x=floor(Parts_pos[i].x);
		y=floor(Parts_pos[i].y);
		if(onscreen(x,y)){
			x-=8;
			y-=8;
			xy=400*y+x;
			savedataarray[xy]=Parts_type[i];
			if(Parts_type[i]==FAN){
				savemetaarray[xy]=wrap(floor(64*Parts_vel[i].angle()/tau),63);
			}else if(Parts_type[i]==FIREWORKS){
				savemetaarray[xy]=Parts_meta1[i]%100;
			//fix thunder saving badly :(
			}else if(Parts_type[i]==THUNDER){ //@@
				console.log(Parts_meta1[i]);
				if((Parts_meta1[i]&0xFFFC)==6000){
					savedataarray[xy]=METAL;
				}else if(Parts_meta1[i]>=7000){
					savedataarray[xy]=GLASS;
				}else if((Parts_meta1[i]&0xFFFC)==6100){
					savedataarray[xy]=MERCURY;
				}
			}
		}
	}
	//save wheels
	for(i=0;i<Wheels.used;i++){
		xy=(Wheels.y[i]-8)*400+(Wheels.x[i]-8);
		savedataarray[xy]=9;
		savemetaarray[xy]=0;
	}
	//save entities
	for(i=0;i<Entities.used;i++){
		basepart=i*Entities.PARTS;
		if(Entities.type[i]==Entities_FIGHTER||Entities.type[i]==Entities_FIGHTER+1){
			x=floor(Entities.pos[basepart+4].x);
			y=floor(Entities.pos[basepart+4].y);
			if(onscreen(x,y)){
				x=x>>2<<2;
				y=y>>2<<2;
				xy=400*(y-8)+(x-8);
				savedataarray[xy]=18;
				savemetaarray[xy]=0;
			}
		}else if(Entities.type[i]==Entities_BOX){
			x=floor(Entities.pos[basepart].x);
			y=floor(Entities.pos[basepart].y);
			if(onscreen(x,y)){
				x=x>>2<<2; //d&=~3;
				y=y>>2<<2;
				xy=400*(y-8)+(x-8);
				savedataarray[xy]=22;
				savemetaarray[xy]=Entities.meta2[i];
			}
		}else if(Entities.type[i]==Entities_PLAYER){
			x=floor(Entities.pos[basepart+4].x);
			y=floor(Entities.pos[basepart+4].y);
			if(onscreen(x,y)){
				x=x>>2<<2;
				y=y>>2<<2;
				xy=400*(y-8)+(x-8);
				savedataarray[xy]=30;
				savemetaarray[xy]=Entities.meta2[i];
			}
		}else if(Entities.type[i]==Entities_CREATE){
			x=floor(Entities.pos[basepart].x);
			y=floor(Entities.pos[basepart].y);
			if(onscreen(x,y)){
				x=x>>2<<2;
				y=y>>2<<2;
				xy=400*(y-8)+(x-8);
				savedataarray[xy]=22;
				savemetaarray[xy]=10;
			}
		}
	}
	//save balls
	for(i=0;i<Balls.MAX;i++){
		if(Balls.used[i]){
			x=floor(Balls.pos[i].x);
			y=floor(Balls.pos[i].y);
			if(onscreen(x,y)){
				xy=(y-8)*400+(x-8);
				if(savedataarray[xy]==0){
					savedataarray[xy]=Save_BALL;
					savemetaarray[xy]=Balls.type[i];
				}
			}
		}
	}
	carefullycreated2=clamp(carefullycreated+100,0,4095);
}
function onscreen(x,y){
	return x>=8 && x<WIDTH-8 && y>=8 && y<308;
}
//ok and then this generates the thing
function makesavestring(){
	var a,d,c;d=Array(120000);
	var b=0;
	var e;
	for(a=0;a<120000;a++){
		c=savedataarray[a];
		if(c==FAN||c==FIREWORKS||c==22||c==Button_WIND){
			d[b++]=c;
			d[b++]=savemetaarray[a];
		}else if(c==30){
			d[b++]=32;
			d[b++]=savemetaarray[a];
		//particles
		}else{
			for(var e=1;a<119999&&c==savedataarray[a+1]&&e<0xFF;a++,e++);
			//store type
			d[b++]=c;
			//rle
			if(e!=1){
				//1 digit hex (1-15)
				if(e<0x10){
					d[b++]=48+e;
				//2 digit hex (16-255)
				}else{
					d[b++]=48+(e&0xF);
					d[b++]=48+(e>>4);
				}
			}
		}
	}
	e=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",".","*"];
	var f=Array(2*b),g=0;
	//magic numbers?
	f[g++]="1";
	f[g++]="0";
	//settings
	f[g++]=["0","1","2","3","4","5","6","7","8","9",":",";","A","B","C","D","E","F"][Menu_bgMode+1]; //0 (-1) is invalid
	f[g++]=""+Menu_dotLimit;
	f[g++]=""+Menu_gridSize;
	f[g++]=""+Menu_gameSpeed;
	f[g++]=""+Menu_edgeMode;
	//unused?
	f[g++]="0";
	//carefully created
	f[g++]=e[carefullycreated2&63];
	f[g++]=e[carefullycreated2>>6&63];
	//unused?
	f[g++]="0";
	f[g++]="0";
	f[g++]="0";
	f[g++]="0";
	f[g++]="0";
	f[g++]="0";
	var q=Array(0x1000);
	for(a=0;a<0x1000;a++){
		q[a]=[];
	}
	var n=1;
	for(a=0;a<b;a+=w){
		for(var r=0,w=1,y=1;y<n;y++){
			if(q[y].length==w){
				for(c=0;c<w&&q[y][c]==d[a+c];c++);
				if(c==w){
					r=y;
					w++;
					if(a+w>=b){
						break;
					}
				}
			}
		}
		f[g++]=e[r>>6];
		f[g++]=e[r&63];
		f[g++]=e[d[a+w-1]];
		if(n<0x1000){
			q[n]=Array(w);
			for(c=0;c<w;c++){
				q[n][c]=d[a+c];
			}
			n++;
		}
	}
	if(!f[g-1]){
		f[g-1]=e[0];
	}
	savetext="";
	for(var i=0;i<g;i++){
		savetext+=f[i];
	}
	a=0;
	for(var y=0;y<300;y+=4){
		for(var x=0;x<400;x+=4){
			xy=400*y+x;
			if(savedataarray[xy]==0){
				xy+=401;
			}
			if(Menu_bgMode==Bg_DARK){
				if(savedataarray[xy]==FIRE||savedataarray[xy]==MAGMA||savedataarray[xy]==TORCH||savedataarray[xy]==THUNDER||savedataarray[xy]==LASER||savedataarray[xy]==SPARK){
					globalthumbnail[a]=e[savedataarray[xy]];
				}else{
					globalthumbnail[a]="0";
				}
			}else{
				if(Menu_bgMode==Bg_SILUET){
					globalthumbnail[a]=(savedataarray[c]==0)?"0":"1";
				}else{
					globalthumbnail[a]=e[savedataarray[c]];
				}
			}
			a++;
		}
	}
	//if you use lowercase hex, fuck you
	var shitHex=["0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"];
	var palette;
	if(Menu_bgMode==Bg_GRAY){
		palette=grays;
	}else if(Menu_bgMode==Bg_SILUET){
		palette=[0xFFFFFF,0];
	}else{
		palette=Array(colors.length);
		for(var i=0;i<colors.length;i++){
			palette[i]=colors[i];
		}
	}
	globalcolorpalette="";
	for(var i=0;i<palette.length;i++){
		globalcolorpalette+=shitHex[palette[i]>>20&0xF];
		globalcolorpalette+=shitHex[palette[i]>>16&0xF];
		globalcolorpalette+=shitHex[palette[i]>>12&0xF];
		globalcolorpalette+=shitHex[palette[i]>> 8&0xF];
		globalcolorpalette+=shitHex[palette[i]>> 4&0xF];
		globalcolorpalette+=shitHex[palette[i]    &0xF];
	}
}
function loadsavestring(){
	const base64decode=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,0,0,0,62,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,0,0,0,0,0,0,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,0,0,0,0,0];
	var version=~~savetext[0];
	var bgmode=["0","1","2","3","4","5","6","7","8","9",":",";","A","B","C","D","E","F"].indexOf(savetext[2]);
	if(bgmode==0){
		Menu_bgMode=2;
	}else if(bgmode!=-1){
		Menu_bgMode=bgmode-1;
	}
	Menu_dotLimit=~~savetext[3];
	Menu_gridSize=~~savetext[4];
	Menu_gameSpeed=~~savetext[5];
	Menu_edgeMode=~~savetext[6];
	if(version==0){
		carefullycreated2=100;
	}else if(version>=1){
		carefullycreated2=base64decode[savetext.charCodeAt(8)];
		carefullycreated2+=base64decode[savetext.charCodeAt(9)]<<6;
	}
	q=Array(0x1000);
	for(var i=0;i<0x1000;i++){
		q[i]=[];
	}
	var e=Array(120000),e_index=0,q_index=1;
	//f
	for(var savetext_index= version==0 ? 8 : 16;savetext_index<savetext.length;){
		var q_read=0,q_size=1;
		q_read=base64decode[savetext.charCodeAt(savetext_index)]<<6 | base64decode[savetext.charCodeAt(savetext_index+1)];
		savetext_index+=2;
		if(q_read>0){
			//copy from (q[0]-q[i-1]) to (e[f]-e[f+i-1])
			for(var i=0;i<q[q_read].length;i++){
				e[e_index]=q[q_read][i];
				e_index++;
			}
			q_size=q[q_read].length+1;
		}
		e[e_index]=~~base64decode[savetext.charCodeAt(savetext_index)];
		e_index++;
		savetext_index++;
		if(q_index<0x1000){
			q[q_index]=Array(q_size);
			//copy from (e[f-w]-e[f-1]) to (q[0]-q[i-1])
			for(var i=0;i<q_size;i++){
				q[q_index][i]=e[e_index-q_size+i];
			}
			q_index++;
		}
	}
	e[e_index++]=0;
	e[e_index++]=0;
	a=0;
	for(var d=0;d<120000;){
		var b=e[a];
		a++;
		//22=create,box
		//40=ball
		if(b==FAN||b==FIREWORKS||b==22||b==Save_BALL){
			savedataarray[d]=b;
			savemetaarray[d]=e[a];
			d++;
			a++;
		//player
		}else if(b==32){
			savedataarray[d]=30;
			savemetaarray[d]=e[a];
			d++;
			a++;
		//normal particle/block
		}else if(e[a]<48){ //if next digit is valid element
			savedataarray[d]=b;
			d++;
		//rle encoded
		}else{
			//1 or 2 digits in hexadecimal
			w=e[a]-48; //low nibble
			a++;
			if(e[a]>=48){ //if next digit
				w+=e[a]-48<<4; //get high nibble
				a++;
			}
			savedataarray.fill(b,d,d+w); //value,start,end+1
			d+=w;
		}
	}
}

function load1(){
	var totalparts=0;
	Fb.reset(1);
	for(var y=0;y<300;y++){
		for(var x=0;x<400;x++){
			var xy=400*y+x;
			switch(savedataarray[xy]){
			case 0:
				xy=(y+8)*WIDTH+(x+8);
				parts[xy]=Parts_EMPTY;
			break;case 1:
				xy=((y>>2)+2)*G+((x>>2)+2);
				blocks[xy]=1;
				xy=(y+8)*WIDTH+(x+8);
				parts[xy]=Parts_BLOCK;
			//wheel
			break;case 9:
				Wheels.create(x+8,y+8);
			//wheel
			break;case 18:
				Entities.create(x+8,y+8,0,0);
			//box,create
			break;case 22:
				Entities.create(x+8,y+8,22,savemetaarray[xy]);
			//player
			break;case 30:
				Entities.create(x+8,y+8,32,savemetaarray[xy]);
			//ball
			break;case Save_BALL:
				Balls.create(x+8,y+8,savemetaarray[xy]);
			//make particle
			break;default:
				totalparts++;
				//update limits
				if(Menu_dotLimit<=0&&Parts_limits[0]<totalparts){
					Menu_dotLimit=1;
				}
				if(Menu_dotLimit<=1&&Parts_limits[1]<totalparts){
					Menu_dotLimit=2;
				}
				//make
				var a=Parts_create(x+8,y+8,savedataarray[xy]);
				//add metadatas
				if(savedataarray[xy]==FAN){
					Parts_vel[a].x=0.1*Math.cos(savemetaarray[xy]*pi/32);
					Parts_vel[a].y=0.1*-Math.sin(savemetaarray[xy]*pi/32);
					parts[(y+8)*WIDTH+(x+8)]=Parts_BGFAN;
				}else if(savedataarray[xy]==FIREWORKS){
					Parts_meta1[a]=savemetaarray[xy];
				}
			}
		}
	}
	//shuffle random particles around
	for(i=0;i<Parts_used;i++){
		var c=floor(Math.random()*Parts_used);
		
		Parts_pos[i].swap(Parts_pos[c]);
		
		Parts_vel[i].swap(Parts_vel[c]);
		
		var temp=Parts_type[i];
		Parts_type[i]=Parts_type[c];
		Parts_type[c]=temp;
		
		temp=Parts_meta1[i];
		Parts_meta1[i]=Parts_meta1[c];
		Parts_meta1[c]=temp;
		
		temp=Parts_pumpType[i];
		Parts_pumpType[i]=Parts_pumpType[c];
		Parts_pumpType[c]=temp;
		
		temp=Parts_pos2[i];
		Parts_pos2[i]=Parts_pos2[c];
		Parts_pos2[c]=temp;
		
		parts[Parts_pos2[i]]=Parts_type[i]==FAN?Parts_BGFAN:i;
		parts[Parts_pos2[c]]=Parts_type[c]==FAN?Parts_BGFAN:c;
	}
	carefullycreated=carefullycreated2;
}
yd.prototype.reset=function(a){
	var d,b,c;
	H=4;
	Air_CELLS=G*kd;
	for(d=0;d<Air_CELLS;d++){
		Air.vel[d].set(0,0);
		Air.vel2[d].set(0,0);
	}
	Air.pres.fill(0);
	Air.pres2.fill(0);
	blocks.fill(0);
	for(c=b=pd=0;c<kd;c++){
		for(d=0;d<G;d++,b++){
			qd[b]=d*H;
			rd[b]=c*H;
		}
	}
	if(a==0){
		for(d=0,b=2*G+2;d<G-4;d++,b++){
			blocks[b]=1;
		}
		for(d=0,b=G*(kd-3)+2;d<G-4;d++,b++){
			blocks[b]=1;
		}
		for(d=0,b=2*G+2;d<kd-4;d++,b+=G){
			blocks[b]=1;
		}
		for(d=0,b=3*G-3;d<kd-4;d++,b+=G){
			blocks[b]=1
		}
	}
	for(d=0,b=G+1;d<G-2;d++,b++){
		blocks[b]=-1;
	}
	for(d=0,b=G*(kd-2)+1;d<G-2;d++,b++){
		blocks[b]=-1;
	}
	for(d=0,b=G+1;d<kd-2;d++,b+=G){
		blocks[b]=-1;
	}
	for(d=0,b=2*G-2;d<kd-2;d++,b+=G){
		blocks[b]=-1;
	}
	for(b=d=0;d<G;d++,b++){
		blocks[b]=-1;
	}
	for(d=0,b=G*(kd-1);d<G;d++,b++){
		blocks[b]=-1;
	}
	for(b=d=0;d<kd;d++,b+=G){
		blocks[b]=-1;
	}
	for(d=0,b=G-1;d<kd;d++,b+=G){
		blocks[b]=-1;
	}
	pen_x=2*H;
	pen_y=2*H;
	sd=pen_x;
	td=pen_y;
	pen_dir.set(0,0);
	Parts_used=0;
	parts.fill(Parts_EMPTY); //-5
	Parts_held.fill(false);
	
	Wheels.used=0;
	Wheels.MAX=100;
	Bubbles.used=0;
	Bubbles.MAX=2000;
	Qd=0;
	Rd=5;
	Sd=Rd/(pi+pi)*2;
	
	Entities.used=0;
	Entities_Ud.fill(0);
	Entities.type.fill(0);
	Entities_decay.fill(0);
	Entities.held.fill(0);
	Entities.meta2.fill(0);
	Entities.meta1.fill(0);
	
	Balls.used.fill(false);
	Balls.meta.fill(0);
	Balls.held.fill(false);
	Balls.type.fill(0);
	
	if(a==0){
		for(b=8*WIDTH+8,c=8;c<308;c++,b+=16){
			for(d=8;d<408;d++,b++){
				a=(c>>2)*G+(d>>2);
				if(blocks[a]==1){
					parts[b]=Parts_BLOCK;
				}
			}
		}
	}
	lights.fill(0);
	aura1.fill(0);
	aura2.fill(0);
	carefullycreated=0;
};
function paint(xy,replace,type,meta1){
	var f=xy;
	while(1){
		if(parts[f]>=0&&Parts_type[parts[f]]==replace){
			Parts_type[parts[f]]=type;
			Parts_meta1[parts[f]]=meta1;
			Parts_pumpType[parts[f]]=0;
			f--;
		}else{
			break;
		}
	}
	f++;
	var g=xy+1;
	while(1){
		if(parts[g]>=0&&Parts_type[parts[g]]==replace){
			Parts_type[parts[g]]=type;
			Parts_meta1[parts[g]]=meta1;
			Parts_pumpType[parts[g]]=0;
			g++;
		}else{
			break;
		}
	}
	g--;
	for(var d=f;d<=g;d++){
		if(parts[d-WIDTH]>=0&&Parts_type[parts[d-WIDTH]]==replace){
			paint(d-WIDTH,replace,type,meta1);
		}
		if(parts[d+WIDTH]>=0&&Parts_type[parts[d+WIDTH]]==replace){
			paint(d+WIDTH,replace,type,meta1);
		}
	}
}
window.fff=yd.prototype.move;
yd.prototype.move=function(){
	var a,d,b,c=new Vector,e=new Vector,f=new Vector;
	if(!Menu_cursorInMenu&&wa==0){
		sd=pen_x;
		td=pen_y;
		pen_x=clamp(mouse.old.x+2*H,2*H,H*(G-2)-1);
		pen_y=clamp(mouse.old.y+2*H,2*H,H*(kd-2)-1);
		if(Menu_zoomLevel>0){
			pen_x=2*H+floor(zoomx)+(mouse.old.x>>Menu_zoomLevel);
			pen_y=2*H+floor(zoomy)+(mouse.old.y>>Menu_zoomLevel);
			pen_x=clamp(pen_x,2*H,H*(G-2)-1);
			pen_y=clamp(pen_y,2*H,H*(kd-2)-1);
		}
		if(Menu_penMode==P_LINE){
			if(mouse.rising.left||mouse.rising.right){
				penlinestartx=pen_x;
				penlinestarty=pen_y;
			}else if(mouse.falling.left||mouse.falling.right){
				sd=penlinestartx;
				td=penlinestarty;
			}
		}else if(Menu_penMode==P_LOCK){
			if(mouse.rising.left||mouse.rising.right){
				penlockmode=0;
			}else if(mouse.old.left||mouse.old.right){
				if(penlockmode==0){
					if(abs(pen_x-sd)>abs(pen_y-td)){
						penlockmode=1;
					}else if(abs(pen_x-sd)<abs(pen_y-td)){
						penlockmode=2;
					}
				}
			}else if(mouse.falling.left||mouse.falling.right){
				penlockmode=0;
			}
			if(penlockmode==1){
				pen_y=td;
			}else if(penlockmode==2){
				pen_x=sd;
			}
		}
		c.set(pen_x,pen_y);
		pen_dir.set(sd-5*pen_dir.x,td-5*pen_dir.y);
		var q=5;
		d=a=0.5;
		ee.sub2(c,pen_dir);
		q-=ee.fastnormalize();
		a*=q;
		d*=q;
		c.x+=ee.x*a;
		c.y+=ee.y*a;
		pen_dir.x-=ee.x*d;
		pen_dir.y-=ee.y*d;
		pen_dir.sub2(c,pen_dir);
		pen_dir.fastnormalize();
		mouse_stuff(0);
		mouse_stuff(1);
		if(Menu_zoomLevel!=0&&mouse.middle){
			zoomx-=(mouse.old.x-mouse.older.x)/(1<<Menu_zoomLevel);
			zoomy-=(mouse.old.y-mouse.older.y)/(1<<Menu_zoomLevel);
			zoomx=clamp(zoomx,0,400-(400>>Menu_zoomLevel));
			zoomy=clamp(zoomy,0,300-[300,150,75,38,19][Menu_zoomLevel]);
		}
		if(mouse.rising.left||mouse.rising.right){
			carefullycreated=clamp(carefullycreated+1,0,4095);
		}
	}
	g=[1,2,4,8];
	for(q=0;q<g[Menu_gameSpeed];q++){
		var opencells=0
		for(a=0;a<Air_CELLS;a++){
			if(blocks[a]==0){
				opencells++;
			}
		}
		if(opencells>0){
			pd/=opencells;
			for(a=0;a<Air_CELLS;a++){
				if(blocks[a]==0){
					Air.pres[a]+=pd;
				}
			}
			pd=0;
		}
		if(Menu_paused&&!(risingmouseclick&&wa==0&&Keys.rising[10]|Keys.rising[13])){
			break;
		}
		for(a=0;a<Air_CELLS;a++){
			Air.vel2[a].copy(Air.vel[a]);
		}
		a=2*G+2;
		for(b=2;b<kd-2;b++,a+=4){
			for(d=2;d<G-2;d++,a++){
				if(blocks[a]!=1){
					c.copy(Air.vel[a]);
					var n=c.fastnormalize();
					if(n!=0){
						var r=abs(c.x),w=abs(c.y),y=r/(r+w)*n*0.5,n=w/(r+w)*n*0.5;
						e.mul2(c,y);
						f.mul2(c,n);
						var z=c.x<0?-1:1,v=c.y<0?-G:G;
						if(r>w){
							if(blocks[a+z]<=0){
								Air.vel2[a].sub(e);
								Air.vel2[a+z].add(e);
								Air.pres[a+z]+=y;
								Air.pres[a]-=y;
							}else{
								Air.vel2[a].sub(e);
								Air.vel2[a].sub(e);
							}
							if(blocks[a+z+v]<=0){
								Air.vel2[a].sub(f);
								Air.vel2[a+z+v].add(f);
								Air.pres[a]-=n;
								Air.pres[a+z+v]+=n;
							}else{
								Air.vel2[a].sub(f);
								Air.vel2[a].sub(f);
							}
						}else{
							if(blocks[a+v]<=0){
								Air.vel2[a].sub(f);
								Air.vel2[a+v].add(f);
								Air.pres[a]-=n;
								Air.pres[a+v]+=n;
							}else{
								Air.vel2[a].sub(f);
								Air.vel2[a].sub(f);
							}
							if(blocks[a+v+z]<=0){
								Air.vel2[a].sub(e);
								Air.vel2[a+v+z].add(e);
								Air.pres[a]-=y;
								Air.pres[a+v+z]+=y;
							}else{
								Air.vel2[a].sub(e);
								Air.vel2[a].sub(e);
							}
						}
					}
				}
			}
		}
		for(a=0;a<Air_CELLS;a++){
			Air.pres2[a]=Air.pres[a];
		}
		a=2*G+2;
		r=-1-G;
		w=1-G;
		y=-1+G;
		n=1+G;
		for(b=2;b<kd-2;b++,a+=4){
			for(d=2;d<G-2;d++,a++){
				if(blocks[a]!=1){
					if(blocks[a-1]<=0){
						Air.vel2[a].x-=0.0625*(Air.pres[a]-Air.pres[a-1]);
						Air.pres2[a]-=0.0625*(Air.pres[a]-Air.pres[a-1]);
					}
					if(blocks[a+1]<=0){
						Air.vel2[a].x+=0.0625*(Air.pres[a]-Air.pres[a+1]);
						Air.pres2[a]-=0.0625*(Air.pres[a]-Air.pres[a+1]);
					}
					if(blocks[a-G]<=0){
						Air.vel2[a].y-=0.0625*(Air.pres[a]-Air.pres[a-G]);
						Air.pres2[a]-=0.0625*(Air.pres[a]-Air.pres[a-G]);
					}
					if(blocks[a+G]<=0){
						Air.vel2[a].y+=0.0625*(Air.pres[a]-Air.pres[a+G]);
						Air.pres2[a]-=0.0625*(Air.pres[a]-Air.pres[a+G]);
					}
					if(blocks[a+r]<=0){
						Air.vel2[a].x-=0.044194173*(Air.pres[a]-Air.pres[a+r]);
						Air.vel2[a].y-=0.044194173*(Air.pres[a]-Air.pres[a+r]);
						Air.pres2[a]-=0.044194173*(Air.pres[a]-Air.pres[a+r]);
					}
					if(blocks[a+w]<=0){
						Air.vel2[a].x+=0.044194173*(Air.pres[a]-Air.pres[a+w]);
						Air.vel2[a].y-=0.044194173*(Air.pres[a]-Air.pres[a+w]);
						Air.pres2[a]-=0.044194173*(Air.pres[a]-Air.pres[a+w]);
					}
					if(blocks[a+y]<=0){
						Air.vel2[a].x-=0.044194173*(Air.pres[a]-Air.pres[a+y]);
						Air.vel2[a].y+=0.044194173*(Air.pres[a]-Air.pres[a+y]);
						Air.pres2[a]-=0.044194173*(Air.pres[a]-Air.pres[a+y]);
					}
					if(blocks[a+n]<=0){
						Air.vel2[a].x+=0.044194173*(Air.pres[a]-Air.pres[a+n]);
						Air.vel2[a].y+=0.044194173*(Air.pres[a]-Air.pres[a+n]);
						Air.pres2[a]-=0.044194173*(Air.pres[a]-Air.pres[a+n]);
					}
				}
			}
		}
		for(a=0;a<Air_CELLS;a++){
			if(blocks[a]!=-1){
				Air.vel[a].copy(Air.vel2[a]);
				Air.pres[a]=Air.pres2[a];
			}else{
				Air.pres[a]=0;
				Air.vel[a].set(0,0);
			}
		}
		this.Parts_update();
		this.Wheels_update();
		this.Bubbles_update();
		this.Entities_update();
		this.Balls_update();
	}
};
function mouse_stuff(mousebutton){ //d=mouse button
	var b,c,e,f,g;
	b=new Vector;
	var q= mousebutton==0 ? Menu_leftSelection : Menu_rightSelection
	var n= mousebutton==0 ? mouse.rising.left : mouse.rising.right;
	f= mousebutton==0 ? mouse.falling.left : mouse.falling.right;
	var r= mousebutton==0 ? mouse.old.left : mouse.old.right;
	if(q<elementbuttons){
		if(Menu_penMode==P_LINE){
			r= mousebutton==0 ?mouse.falling.left : mouse.falling.right;
		}
		if(r){
			n=pen_x-sd;
			r=pen_y-td;
			
			if(Menu_penSize>1||!Menu_paused||Menu_zoomLevel>1||n!=0||r!=0||Menu_penMode==P_PAINT){
				var w=max(abs(n),abs(r),1);
				var n=floor((n<<8)/w),r=floor((r<<8)/w);
				var y=(sd<<8)+127,z=(td<<8)+127;
				for(c=0;c<=w;c++,y+=n,z+=r){
					var v=Menu_penSize+0,Y=(y>>8)-v;
					f=(z>>8)-v;
					var Ka=Y+2*v,ab=f+2*v;
					if(Y<8){
						Y=8;
					}
					if(f<8){
						f=8;
					}
					if(Ka>WIDTH-8-1){
						Ka=WIDTH-8-1;
					}
					if(ab>307){
						ab=307;
					}
					var La=f*WIDTH+Y,Ta=WIDTH-(Ka-Y+1);
					for(g=f;g<=ab;g++,La+=Ta){
						for(f=Y;f<=Ka;f++,La++){
							if(v*v+1>=(f-(y>>8))*(f-(y>>8))+(g-(z>>8))*(g-(z>>8))){
								if(Menu_penMode==P_PAINT){
									e=menuelements[q]||Parts_POWDER;
									var meta1=0;
									if(e!=FAN){
										if(e==FIREWORKS){
											meta1=fireworkelements[Menu_leftSelection]||fireworkelements[Menu_rightSelection]||Parts_POWDER;
										}else if(e==LASER){
											meta1=8*pen_dir.angle()/tau+0.5;
											if(meta1>=8){
												meta1=0;
											}
											meta1=floor(meta1)+1;
										}
										if(parts[La]>=0&&Parts_type[parts[La]]!=e){
											paint(La,Parts_type[parts[La]],e,meta1);
										}
									}
								}else if(parts[La]==Parts_EMPTY){
									var pa=menuelements[q]
									if((mousebutton==0&&mouse.old.right&&Menu_rightSelection<elementbuttons || mousebutton==1&&mouse.old.left &&Menu_leftSelection<elementbuttons)&&random(100)<50){
										pa=menuelements[mousebutton==0?Menu_rightSelection:Menu_leftSelection]
									}
									e=Parts_create(f,g,pa);
									if(e>=0){
										if(pa==FAN){
											b.mul2(pen_dir,0.1);
											Parts_vel[e].copy(b);
											parts[La]=Parts_BGFAN;
										}else if(pa==FIREWORKS){
											Parts_meta1[e]=fireworkelements[Menu_leftSelection]||fireworkelements[Menu_rightSelection]||Parts_POWDER;
										}else if(pa==LASER){
											pa=8*pen_dir.angle()/tau+0.5;
											if(pa>=8){
												pa=0;
											}
											Parts_meta1[e]=floor(pa)+1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else{
		switch(q){
		case Button_WIND:
			e=(pen_y>>2)*G+(pen_x>>2);
			b.mul2(pen_dir,10);
			if(r&&blocks[e]==0){
				Air.vel[e].add(b);
				if(Air.vel[e].fastdist()>10 && Menu_paused){
					Air.vel[e].fastnormalize();
					Air.vel[e].mul(10);
				}
			}
		break;case Button_AIR:
			e=(pen_y>>2)*G+(pen_x>>2);
			if(r){
				v=(Menu_penSize+1)**2*0.25;
				v= mousebutton==0 ? v : -v;
				if(blocks[e]==0){
					Air.pres[e]+=v;
					pd-=v;
				}
				if(blocks[e-1]==0){
					Air.pres[e-1]+=v;
					pd-=v;
				}
				if(blocks[e-G]==0){
					Air.pres[e-G]+=v;
					pd-=v;
				}
				if(blocks[e-G-1]==0){
					Air.pres[e-G-1]+=v;
					pd-=v;
				}
			};
		break;case Button_BUBBLE:
			if(Bubbles.used<=Bubbles.MAX-5){
				f=pen_x>>2<<2;
				g=pen_y>>2<<2;
				e=(pen_y>>2)*G+(pen_x>>2);
				if(blocks[e]!=0){
					Qd++;
				}else{
					if(n){
						Qd++;
					}
					if(r){
						q=0;
						for(n=Bubbles.used-1;n>=0&&Bubbles.ke[n]==Qd;n--){
							q++;
						}
						if(q<5){
							Qd++;
							Bubbles.create(f+floor(random(H)),g+floor(random(H)));
							Bubbles.create(f+floor(random(H)),g+floor(random(H)));
							Bubbles.create(f+floor(random(H)),g+floor(random(H)));
							Bubbles.create(f+floor(random(H)),g+floor(random(H)));
						}
						Bubbles.create(f+floor(random(H)),g+floor(random(H)));
					}
				}

			}
		break;case Button_WHEEL:
			if(n){
				f=clamp(pen_x,24,391);
				g=clamp(pen_y,24,291);
				q=false
				for(b=0;b<Wheels.used;b++){
					if(f==Wheels.x[b]&&g==Wheels.y[b]){
						q=true;
						break;
					}
				}
				if(!q){
					Wheels.create(f,g);
				}
			}
		break;case Button_PLAYER:case Button_FIGHTER:case Button_BOX:case M_CREATE:
			f=pen_x>>2<<2;
			g=pen_y>>2<<2;
			e=(pen_y>>2)*G+(pen_x>>2);
			if(blocks[e]==0&&n){
				if(q==Button_FIGHTER){
					Entities.create(f,g,0,0);
				}else if(q==Button_BOX){
					Entities.create(f,g,22,Menu_penSize);
				}else if(q==Button_PLAYER){
					b=playerelements[Menu_leftSelection]||playerelements[Menu_rightSelection]||0;
					Entities.create(f,g,30,b);
				}else if(q==M_CREATE){
					Entities.create(f,g,22,10);
				}
			}
		break;case Button_BALL:
			e=(pen_y>>2)*G+(pen_x>>2)
			if(blocks[e]==0&&n&&q==Button_BALL){
				b=ballelements[Menu_leftSelection]||ballelements[Menu_rightSelection];
				if(b){
					Balls.create(pen_x,pen_y,b);
				}
			}
		break;case Button_TEXT:
			text_x=pen_x;
			text_y=pen_y-14;
			if(n){
				wa=20;
			}
		break;case M_BLOCK:case M_ERASE:case M_CLEAR:
			if(Menu_penMode==P_LINE){
				r= mousebutton==0 ? mouse.falling.left : mouse.falling.right
			}
			if(r){
				n=floor(pen_x/H)-floor(sd/H);
				r=floor(pen_y/H)-floor(td/H);
				w=max(max(abs(n),abs(r)),1);
				n=floor((n<<8)/w);
				r=floor((r<<8)/w);
				y=(floor(sd/H)<<8)-127;
				z=(floor(td/H)<<8)-127;
				for(b=0;b<=w;b++,y+=n,z+=r){
					c=(y>>8)-floor(Menu_penSize/2);
					v=(z>>8)-floor(Menu_penSize/2);
					Y=c+Menu_penSize/2+0.5;
					Ka=v+Menu_penSize/2+0.5;
					for(g=v;g<=v+Menu_penSize;g++){
						for(f=c;f<=c+Menu_penSize;f++){
							if((f-Y)*(f-Y)+(g-Ka)*(g-Ka)<=Menu_penSize*Menu_penSize/4){
								e=clamp(g,2,kd-3)*G+clamp(f,2,G-3)
								if(q==M_BLOCK){
									blocks[e]=1;
									Air.vel[e].set(0,0);
									pd+=Air.pres[e];
									Air.pres[e]=0;
								}else if(q==M_ERASE){
									blocks[e]=-2;
								}else if(q==M_CLEAR&&blocks[e]==0){
									blocks[e]=-2;
									Air.vel[e].set(0,0);
									pd+=Air.pres[e];
									Air.pres[e]=0;
								}
							}
						}
					}
				}
				//clearing size 0
				if(q==M_CLEAR&&Menu_penSize==0){
					n=pen_x-sd
					r=pen_y-td
					w=max(abs(n),abs(r),1)
					n=floor((n<<8)/w)
					r=floor((r<<8)/w)
					for(y=(sd<<8)+127,z=(td<<8)+127,b=0;b<=w;b++,y+=n,z+=r){
						for(e=0;e<Parts_used;e++){
							if(y>>8==floor(Parts_pos[e].x)&&z>>8==floor(Parts_pos[e].y)){
								remove(e--);
							}
						}
					}
				}
				//clear for drawing blocks, or clearing > 0
				if(M_BLOCK==q||M_CLEAR==q){
					for(b=0;b<Parts_used;b++){
						e=(floor(Parts_pos[b].y)>>2)*G+(floor(Parts_pos[b].x)>>2);
						if(blocks[e]!=0){
							remove(b--);
						}
					}
				}
				//erasing
				if(M_ERASE==q){
					for(b=0;b<Wheels.used;b++){
						e=(floor(Wheels.y[b])>>2)*G+(floor(Wheels.x[b])>>2)
						if(blocks[e]==-2){
							f=b--;
							if(Wheels.used!=0){
								r=n=g=undefined;
								g=(Wheels.y[f]-16)*WIDTH+(Wheels.x[f]-16);
								for(r=0;r<32;r++,g+=WIDTH-32){
									for(n=0;n<32;n++,g++){
										if(parts[g]==Parts_WHEEL){
											parts[g]=Parts_EMPTY;
										}
									}
								}
								Wheels.x[f]=Wheels.x[Wheels.used-1];
								Wheels.y[f]=Wheels.y[Wheels.used-1];
								Wheels.angle[f]=Wheels.angle[Wheels.used-1];
								Wheels.vel[f]=Wheels.vel[Wheels.used-1];
								Wheels.used--;
							}
						}
					}
				}
				//removing objects to drawing blocks
				if(M_BLOCK==q||M_ERASE==q){
					for(b=0;b<Entities.used;b++){
						if(Entities.type[b]==Entities_FIGHTER||Entities.type[b]==Entities_FIGHTER+1||Entities.type[b]==Entities_PLAYER||Entities.type[b]==Entities_CREATE){
							for(c=4;c<6;c++){
								e=(floor(Entities.pos[b*Entities.PARTS+c].y)>>2)*G+(floor(Entities.pos[b*Entities.PARTS+c].x)>>2);
								if(blocks[e]!=0){
									Entities_remove(b--);
									break;
								}
							}
						}else if(Entities.type[b]==Entities_BOX){
							for(c=0;c<4;c++){
								e=(floor(Entities.pos[b*Entities.PARTS+c].y)>>2)*G+(floor(Entities.pos[b*Entities.PARTS+c].x)>>2);
								if(blocks[e]!=0){
									Entities_remove(b--);
									break;
								}
							}
						}
					}
					for(b=0;b<Balls.MAX;b++){
						if(Balls.used[b]){
							e=(floor(Balls.pos[b].y)>>2)*G+(floor(Balls.pos[b].x)>>2)
							if(blocks[e]!=0){
								e=floor(Balls.pos[b].y)*WIDTH+floor(Balls.pos[b].x);
								for(c=0;c<21;c++){
									if(parts[e+ballneighborhood[c]]==Parts_BALL){
										parts[e+ballneighborhood[c]]=Parts_EMPTY;
									}
								}
								Balls.used[b]=false;
							}
						}
					}
				}
				if(M_ERASE==q||M_CLEAR==q){
					for(b=0;b<Air_CELLS;b++){
						if(blocks[b]==-2){
							blocks[b]=0
						}
					}
				}
				e=8*WIDTH+8;
				for(g=8;g<308;g++,e+=16){
					for(f=8;f<408;f++,e++){
						La=(g>>2)*G+(f>>2);
						if(blocks[La]==0&&parts[e]==Parts_BLOCK){
							parts[e]=Parts_EMPTY;
						}else if(blocks[La]==1&&parts[e]<Parts_BLOCK){
							parts[e]=Parts_BLOCK;
						}
					}
				}
			}
		break;case Button_COPYPASTE:
			if(n){
				if(!Menu_copyMode){
					copyx1=copyx2=pen_x;
					copyy1=copyy2=pen_y;
				}else if(!Menu_paused||Menu_zoomLevel>1||copyx1!=copyx2||copyy1!=copyy2){
					if(copyx1>copyx2){
						f=copyx1;
						copyx1=copyx2;
						copyx2=f;
					}
					if(copyy1>copyy2){
						g=copyy1;
						copyy1=copyy2;
						copyy2=g;
					}
					r=pen_x-floor((copyx2-copyx1)/2)-copyx1;
					w=pen_y-floor((copyy2-copyy1)/2)-copyy1;
					for(g=copyy1-8;g<=copyy2-8;g++){
						
						if(g+w>=0&&g+w<300){
							for(f=copyx1-8;f<=copyx2-8;f++){
								if(f+r>=0&&f+r<400){
									n=400*g+f;
									if(copydata[n]!=0&&parts[(w+g+8)*WIDTH+(r+f+8)]==Parts_EMPTY){
										q=Parts_create(r+f+8,w+g+8,copydata[n]);
										if(q>=0){
											if(copydata[n]==FAN){
												Parts_vel[q].x=0.1*Math.cos(copymeta[n]*pi/32);
												Parts_vel[q].y=0.1*-Math.sin(copymeta[n]*pi/32);
												parts[(w+g+8)*WIDTH+(r+f+8)]=Parts_BGFAN;
											}else if(copydata[n]==FIREWORKS){
												Parts_meta1[q]=copymeta[n];
											}
										}
									}
								}
							}
						}
					}
				}
			}else if(f&&!Menu_copyMode){
				copydata.fill(0);
				copymeta.fill(0);
				for(q=0;q<Parts_used;q++){
					f=floor(Parts_pos[q].x);
					g=floor(Parts_pos[q].y);
					if(f>=8||f<408||g>=8||g<308){
						f-=8;
						g-=8;
						f=400*g+f;
						copydata[f]=Parts_type[q];
						if(Parts_type[q]==FAN){
							copymeta[f]=wrap(floor(64*Parts_vel[q].angle()/tau),63);
						}else if(Parts_type[q]==FIREWORKS){
							copymeta[f]=Parts_meta1[q]%100;
						}
					}
				}
			}else if(r&&!Menu_copyMode){
				copyx2=pen_x;
				copyy2=pen_y;
			}
		break;case Button_SCALE:
			if(Menu_zoomLevel!=0&&r){
				zoomx-=(mouse.old.x-mouse.older.x)/(1<<Menu_zoomLevel);
				zoomy-=(mouse.old.y-mouse.older.y)/(1<<Menu_zoomLevel);
				zoomx=clamp(zoomx,0,400-(400>>Menu_zoomLevel));
				zoomy=clamp(zoomy,0,300-[300,150,75,38,19][Menu_zoomLevel]);
			}
		}
	}
}
//bg effects handling?
window.fff=yd.prototype.Bg_effects;
yd.prototype.Bg_effects=function(){
	var a,d,b,c,e,f,g,q,n;
	e=new Vector;
	switch(Menu_bgMode){
	//normalness
	case Bg_NONE:
		for(a=308*WIDTH;a>=0;a--){
			screenbuffer[a]= parts[a]==Parts_BLOCK ? 0x606060 : 0;
		}
	//drawing pressure
	break;case Bg_AIR:case Bg_LINE:
		a=2*G+2;
		for(c=2;c<77;c++,a+=4){
			for(b=2;b<102;b++,a++){
				//draw blockd
				if(blocks[a]==1){
					rectangle(qd[a],rd[a],H,H,0x606060);
				}else{
					q=g=0
					if(Air.pres[a]>0){
						g=floor(min(48*Air.pres[a],96));
					}
					if(Air.pres[a]<0){
						q=floor(min(48*-Air.pres[a],96));
					}
					rectangle(qd[a],rd[a],H,H,g<<8|q);
					
				}
			}
		}
		//airflow lines
 		if(Menu_bgMode==Bg_LINE){
			var r;
			for(a=0;a<Air_CELLS;a++){
				if(blocks[a]==0){
					e.copy(Air.vel[a]);
					r=e.fastnormalize();
					if(r>=0.2){
						d=qd[a]+2;
						n=rd[a]+2;
						if(r>8){
							r=8;
						}
						f=floor(min(48*r,96));
						line(d+e.x*r*10,n+e.y*r*10,d,n,f<<16);
					}
				}
			}
		}
	//blur
	break;case Bg_BLUR:
		for(a=308*WIDTH;a>=3328;a--){
			if(parts[a]==Parts_BLOCK){
				screenbuffer[a]=0x606060;
			}else{
				f=230*(screenbuffer[a]>>16&0xFF)>>8;
				g=230*(screenbuffer[a]>>8&0xFF)>>8;
				q=230*(screenbuffer[a]&0xFF)>>8;
				screenbuffer[a]=f<<16|g<<8|q;
			}
		}
	//shade
	break;case Bg_SHADE:
		for(c=8;c<308;c++){
			e=c*WIDTH+8;
			for(b=8;b<407;b++,e++){
				f=(screenbuffer[e]>>16&0xFF)+(screenbuffer[e+1]>>16&0xFF)>>1;
				g=(screenbuffer[e]>>8&0xFF)+(screenbuffer[e+1]>>8&0xFF)>>1;
				q=(screenbuffer[e]&0xFF)+(screenbuffer[e+1]&0xFF)>>1;
				screenbuffer[e]=f<<16|g<<8|q;
			}
			e=c*WIDTH+407;
			for(b=407;b>8;b--,e--){
				f=(screenbuffer[e]>>16&0xFF)+(screenbuffer[e-1]>>16&0xFF)>>1;
				g=(screenbuffer[e]>>8&0xFF)+(screenbuffer[e-1]>>8&0xFF)>>1;
				q=(screenbuffer[e]&0xFF)+(screenbuffer[e-1]&0xFF)>>1;
				screenbuffer[e]=f<<16|g<<8|q;
			}
		}
		for(b=8;b<408;b++){
			e=8*WIDTH+b;
			for(c=8;c<307;c++,e+=WIDTH){
				f=(screenbuffer[e]>>16&0xFF)+(screenbuffer[e+WIDTH]>>16&0xFF)>>1;
				g=(screenbuffer[e]>>8&0xFF)+(screenbuffer[e+WIDTH]>>8&0xFF)>>1;
				q=(screenbuffer[e]&0xFF)+(screenbuffer[e+WIDTH]&0xFF)>>1;
				screenbuffer[e]=f<<16|g<<8|q;
			}
			e=307*WIDTH+b;
			for(c=307;c>8;c--,e-=WIDTH){
				f=(screenbuffer[e]>>16&0xFF)+(screenbuffer[e-WIDTH]>>16&0xFF)>>1;
				g=(screenbuffer[e]>>8&0xFF)+(screenbuffer[e-WIDTH]>>8&0xFF)>>1;
				q=(screenbuffer[e]&0xFF)+(screenbuffer[e-WIDTH]&0xFF)>>1;
				screenbuffer[e]=f<<16|g<<8|q;
			}
		}
		for(a=308*WIDTH;a>=0;a--){
			if(parts[a]==Parts_BLOCK){
				screenbuffer[a]=0x606060;
			}
		}
	//aura
	break;case Bg_AURA:
		b=309*WIDTH;
		for(a=0;a<b;a++){
			lights[a]=aura1[a]=aura2[a]=0;
		}
		f=[1,1,1,WIDTH-3,1,1,1,WIDTH-3,1,1,1,WIDTH-3,1,1,1,WIDTH-3];
		var w;
		e=2*G+2;
		for(c=2;c<kd-2;c++,e+=4){
			for(b=2;b<G-2;b++,e++){
				g=abs(Air.vel[e].x);
				a=abs(Air.vel[e].y);
				if(g!=0||a!=0){
					q=1/(g+a);
					g=floor(g*q*0xFFFF);
					q=floor(a*q*0xFFFF);
					n=d=0;
					if(Air.vel[e].x<0){
						d=-1;
					}else if(Air.vel[e].x>0){
						d=1;
					}
					if(Air.vel[e].y<0){
						n=-WIDTH;
					}else if(Air.vel[e].y>0){
						n=WIDTH;
					}
					r=(c<<2)*WIDTH+(b<<2)
					for(a=0;a<16;a++){
						w=screenbuffer[r]>>16&0xFF;
						lights[r+d]+=w*g;
						lights[r+n]+=w*q;
						w=screenbuffer[r]>>8&0xFF;
						aura1[r+d]+=w*g;
						aura1[r+n]+=w*q;
						w=screenbuffer[r]&0xFF;
						aura2[r+d]+=w*g;
						aura2[r+n]+=w*q;
						r+=f[a];
					}
				}
			}
		}
		e=8*WIDTH+8;
		for(c=8;c<308;c++,e+=16){
			for(b=8;b<408;b++,e++){
				screenbuffer[e]=
					parts[e]==Parts_BLOCK?
						0x606060
					:
						min(lights[e]>>16,0xFF)<<16|min(aura1[e]>>16,0xFF)<<8|min(aura2[e]>>16,0xFF);
			}
		}
	//light
	break;case Bg_LIGHT:
		for(a=308*WIDTH;a>=3328;a--){
			if(parts[a]==Parts_BLOCK){
				screenbuffer[a]=0x606060;
			}else{
				f=220*(screenbuffer[a]>>16&0xFF)>>8;
				g=220*(screenbuffer[a]>>8&0xFF)>>8;
				q=220*(screenbuffer[a]&0xFF)>>8;
				screenbuffer[a]=f<<16|g<<8|q;
			}
		}
	//toon
	break;case Bg_TOON:
		for(a=308*WIDTH;a>=2912;a--){
			if(parts[a]==Parts_BLOCK){
				screenbuffer[a]=0x606060;
			}else if(parts[a]==Parts_BALL){
				screenbuffer[a]=0;
			}else if(parts[a]==Parts_BGFAN){ //const -4
				screenbuffer[a]=0x8080FF;
			}else if(parts[a]==Parts_EMPTY){ //const -5
				screenbuffer[a]=parts[a+1]>=0?
					colors[Parts_type[parts[a+1]]]
				:
					parts[a-1]>=0?
						colors[Parts_type[parts[a-1]]]
					:
						parts[a+WIDTH]>=0?
							colors[Parts_type[parts[a+WIDTH]]]
						:
							parts[a-WIDTH]>=0?
								colors[Parts_type[parts[a-WIDTH]]]
							:
								parts[a+WIDTH+1]>=0?
									colors[Parts_type[parts[a+WIDTH+1]]]
								:
									parts[a+WIDTH-1]>=0?
										colors[Parts_type[parts[a+WIDTH-1]]]
									:
										parts[a-WIDTH+1]>=0?
											colors[Parts_type[parts[a-WIDTH+1]]]
										:
											parts[a-WIDTH-1]>=0?
												colors[Parts_type[parts[a-WIDTH-1]]]
											:
												0
			}else if(parts[a]>=0){
				screenbuffer[a]=colors[Parts_type[parts[a]]];
			}
		}
		for(a=308*WIDTH;a>=3328;a--){
			if(screenbuffer[a]>>>0==0){
				if(screenbuffer[a+1]>>>0!=0&&screenbuffer[a+1]>>>0!=0xEEEEEE){
					screenbuffer[a]=0xEEEEEE;
				}else if(screenbuffer[a-1]>>>0!=0&&screenbuffer[a-1]>>>0!=0xEEEEEE){
					screenbuffer[a]=0xEEEEEE;
				}else if(screenbuffer[a+WIDTH]>>>0!=0&&screenbuffer[a+WIDTH]>>>0!=0xEEEEEE){
					screenbuffer[a]=0xEEEEEE;
				}else if(screenbuffer[a-WIDTH]>>>0!=0&&screenbuffer[a-WIDTH]>>>0!=0xEEEEEE){
					screenbuffer[a]=0xEEEEEE;
				}
			}
		}
	//mesh
	break;case Bg_MESH:
		for(a=308*WIDTH;a>=0;a--){
			screenbuffer[a]= parts[a]==Parts_BLOCK ? 0x606060 : 0;
		}
		a=2*G+2;
		for(c=2;c<77;c++,a+=4){
			for(b=2;b<102;b++,a++){
				if(blocks[a]==0){
					e.copy(Air.vel[a])
					r=e.fastdist()
					if(r>=0.2){
						if(r>2){
							r=2;
						}
						g=floor(min(48*r,96));
						f=0;
						if(Air.pres[a]>0){
							f=floor(min(48*Air.pres[a]*r,96));
						}
						q=0
						if(Air.pres[a]<0){
							q=floor(min(48*-Air.pres[a]*r,96));
						}
						d=qd[a]+5*Air.vel[a].x;
						n=rd[a]+5*Air.vel[a].y;
						r=qd[a+1]+5*Air.vel[a+1].x;
						w=rd[a+1]+5*Air.vel[a+1].y;
						line(d,n,r,w,f<<16|g<<8|q);
						r=qd[a+G]+5*Air.vel[a+G].x;
						w=rd[a+G]+5*Air.vel[a+G].y;
						line(d,n,r,w,f<<16|g<<8|q);
					}
				}
			}
		}
	//gray
	break;case Bg_GRAY:
		for(a=2*G+2,c=2;c<77;c++,a+=4){
			for(b=2;b<102;b++,a++){
				if(blocks[a]==1){
					rectangle(qd[a],rd[a],H,H,0x606060);
				}else{
					f=0;
					if(Air.pres[a]>0){
						f=floor(min(48*Air.pres[a],72));
					}
					if(Air.pres[a]<0){
						f=floor(min(48*-Air.pres[a],24));
					}
					rectangle(qd[a],rd[a],H,H,f<<16|f<<8|f);
				}
			}
		}
	//track
	break;case Bg_TRACK:
		r=[0,1,2,3,WIDTH+0,WIDTH+1,WIDTH+2,WIDTH+3,2*WIDTH+0,2*WIDTH+1,2*WIDTH+2,2*WIDTH+3,3*WIDTH+0,3*WIDTH+1,3*WIDTH+2,3*WIDTH+3];
		a=2*G+2;
		for(c=2;c<77;c++,a+=4){
			for(b=2;b<102;b++,a++){
				if(blocks[a]==1){
					rectangle(qd[a],rd[a],H,H,0x606060);
				}else{
					n=256-floor(min(abs(12*Air.pres[a]),32));
					if(n!=256){
						for(e=(c<<2)*WIDTH+(b<<2),d=0;d<16;d++){
							f=(screenbuffer[e+r[d]]>>16&0xFF)*n>>8;
							g=(screenbuffer[e+r[d]]>>8&0xFF)*n>>8;
							q=(screenbuffer[e+r[d]]&0xFF)*n>>8;
							screenbuffer[e+r[d]]=f<<16|g<<8|q;
						}
					}
				}
			}
		}
	//dank
	break;case Bg_DARK:
		for(a=308*WIDTH;a>=0;a--){
			if(parts[a]<0){
				lights[a]=floor(8*lights[a]/9);
			}else if(Parts_type[parts[a]]==FIRE||Parts_type[parts[a]]==MAGMA||Parts_type[parts[a]]==LASER||Parts_type[parts[a]]==SPARK){
				lights[a]=25500;
			}else if(Parts_type[parts[a]]==TORCH||Parts_type[parts[a]]==THUNDER){
				lights[a]=255000;
			}else{
				lights[a]=floor(8*lights[a]/9);
			}
		}
		for(a=308*WIDTH;a>=0;a--){
			screenbuffer[a]= parts[a]==Parts_BLOCK ? 0x606060 : 0;
		}
	//temp
	break;case Bg_TG:
		for(a=0;a<Parts_used;a++){
			lights[Parts_pos2[a]]=Parts_TEMPERATURE[Parts_type[a]];
		}
		//spread horizontally
		for(c=8;c<308;c++){
			e=c*WIDTH+8;
			for(b=8;b<407;b++,e++){
				lights[e]=lights[e+1]=floor((lights[e]+lights[e+1])/2);
			}
			for(b=407;b>8;b--,e--){
				lights[e]=lights[e-1]=floor((lights[e]+lights[e-1])/2)
			}
		}
		//spread vertically
		for(b=8;b<408;b++){
			e=8*WIDTH+b;
			for(c=8;c<307;c++,e+=WIDTH){
				lights[e]=lights[e+WIDTH]=floor((lights[e]+lights[e+WIDTH])/2);
			}
			for(c=307;c>8;c--,e-=WIDTH){
				lights[e]=lights[e-WIDTH]=floor((lights[e]+lights[e-WIDTH])/2)
			}
		}
		for(a=308*WIDTH;a>=0;a--){
			b=lights[a];
			if(b<0){
				f=128*-b>>10;
				if(f>0xFF){
					f=0xFF;
				}
				g=0;
				q=0xFF*-b>>10;
				if(q>0xFF){
					q=0xFF;
				}
			}else if(b<0x400){
				g=f=0;
				q=0xFF*b>>10;
			}else if(b<0x800){
				f=0;
				g=0xFF*(b-1024)>>10;
				q=0xFF;
			}else if(b<0xC00){
				f=0;
				g=0xFF;
				q=0xFF-(0xFF*(b-2048)>>10);
			}else if(b<0x1000){
				f=0xFF*(b-3072)>>10;
				g=0xFF;
				q=0;
			}else if(b<0x1800){
				f=0xFF;
				g=0xFF-(0xFF*(b-0x1000)>>11);
				q=0;
			}else{
				f=0xFF;
				g=0xFF*(b-6144)>>11;
				if(g>0xFF){
					g=0xFF;
				}
				q=0xFF*(b-6144)>>11;
				if(q>0xFF){
					q=0xFF;
				}
			}
			screenbuffer[a]=f<<16|g<<8|q;
		}
		for(a=308*WIDTH;a>=0;a--){
			if(parts[a]==Parts_BLOCK){
				screenbuffer[a]=0x606060;
			}
		}
	break;case Bg_SILUET:
		for(a=308*WIDTH;a>=3328;a--){
			if(parts[a]==Parts_BLOCK){
				screenbuffer[a]=0;
			}else if(parts[a]==Parts_EMPTY){
				f=0xFF-(0xFF-(screenbuffer[a]>>16&0xFF)>>1);
				g=0xFF-(0xFF-(screenbuffer[a]>>8&0xFF)>>1);
				q=0xFF-(0xFF-(screenbuffer[a]&0xFF)>>1);
				screenbuffer[a]=f<<16|g<<8|q;
			}
		}
	}
	//draw grids
	if(Menu_gridSize>1){
		f=[0,0,100,50,25,16,8,4];
		for(a=0;a<400;a+=f[Menu_gridSize]){
			for(c=0,e=8*WIDTH+a+8;c<300;c++,e+=WIDTH){ //;c;
				if(screenbuffer[e]!=0x606060){
					screenbuffer[e]=0x404040;
				}
			}
		}
		for(a=0;a<300;a+=f[Menu_gridSize]){
			for(b=0,e=(a+8)*WIDTH+8;b<400;b++,e++){
				if(screenbuffer[e]!=0x606060){
					screenbuffer[e]=0x404040;
				}
			}
		}
	}
	//draw red + grid lines
	if(Menu_gridSize>0){
		e=8*WIDTH+208;
		for(c=0;c<300;c++){
			if(screenbuffer[e]!=0x606060){
				screenbuffer[e]=0x400000;
			}
			e+=WIDTH;
		}
		e=158*WIDTH+8;
		for(b=0;b<400;b++){
			if(screenbuffer[e]!=0x606060){
				screenbuffer[e]=0x400000;
			}
			e++;
		}
	}
	this.Parts_display();
	this.Wheels_display();
	this.Bubbles_display();
	this.Entities_display();
	this.Balls_display();
	//handle dark bg stuff
	if(Menu_bgMode==Bg_DARK){
		for(c=8;c<308;c++){
			e=c*WIDTH+8;
			for(b=8;b<407;b++,e++){
				lights[e]=lights[e]+lights[e+1]>>1;
			}
			for(b=407;b>8;b--,e--){
				lights[e]=lights[e]+lights[e-1]>>1
			}
		}
		for(b=8;b<408;b++){
			e=8*WIDTH+b;
			for(c=8;c<307;c++,e+=WIDTH){
				lights[e]=lights[e]+lights[e+WIDTH]>>1;
			}
			for(c=307;c>8;c--,e-=WIDTH){
				lights[e]=lights[e]+lights[e-WIDTH]>>1
			}
		}
		for(a=308*WIDTH;a>=0;a--){
			if(lights[a]<1){
				screenbuffer[a]=0
			}else{
				n=min(lights[a],0xFF)
				f=(screenbuffer[a]>>16&0xFF)*n>>8;
				g=(screenbuffer[a]>>8&0xFF)*n>>8;
				q=(screenbuffer[a]&0xFF)*n>>8;
				screenbuffer[a]=f<<16|g<<8|q;
			}
		}
	}
	a=new Vector;
	//draw cursor
	if(!Menu_cursorInMenu&&wa==0){
		//outline for block cursor
		if(Menu_leftSelection==M_BLOCK||Menu_leftSelection==M_ERASE||Menu_leftSelection==M_CLEAR||Menu_rightSelection==M_BLOCK||Menu_rightSelection==M_ERASE||Menu_rightSelection==M_CLEAR){
			c=(td>>2)-1-floor(Menu_penSize/2)
			var penlinepaths=[[],[1,1,1,2,2,2,3,3,3,4,4,4],[1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,4],
			[1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4],
			[1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,4,4,4,4,4,4,4,1,1,1,1,4,4,4,4],
			[1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,4,4,4,4],
			[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,4,4,4,4],
			[1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,2,2,2,2,3,3,3,3,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,4,4,4,4,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,4],
			[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,2,2,2,2,3,3,3,3,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,4,4,4,4,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,4],
			[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,2,2,2,2,3,3,3,3,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,4,4,4,4,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,4],
			[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1,4,4,4,4]]
			f=Menu_penSize
			b=((sd>>2)-1-floor(Menu_penSize/2)+[0,1,1,1,2,2,2,3,3,3,4][f])*H
			c=(c+[0,1,1,1,1,1,1,1,1,1,1][f])*H
			for(g=0;g<penlinepaths[f].length;g++){
				q=clamp(c,0,308)*WIDTH+clamp(b,0,WIDTH-1)
				screenbuffer[q]=0xC00000
				switch(penlinepaths[f][g]){
				case 1:
					b++;
				break;case 2:
					c++;
				break;case 3:
					b--;
				break;case 4:
					c--;
				}
			}
		}
		//line cursor when drawing FAN/WIND/LASER
		if(Menu_leftSelection==Button_FAN||Menu_rightSelection==Button_FAN||Menu_leftSelection==Button_WIND||Menu_rightSelection==Button_WIND||Menu_leftSelection==Button_LASER||Menu_rightSelection==Button_LASER){ //fan,wind,laser (buttons, not element ids)
			a.mul2(pen_dir,30);
			line(pen_x+a.x,pen_y+a.y,pen_x,pen_y,0xFF0000);
		}else{
			rectangle(pen_x,pen_y,1,1,screenbuffer[floor(pen_x)+floor(pen_y)*WIDTH]^0xFFFFFF); //@@
		}
		//display copy box preview
		if(Menu_leftSelection==Button_COPYPASTE||Menu_rightSelection==Button_COPYPASTE){
			if(!Menu_copyMode){
				if(Menu_leftSelection==Button_COPYPASTE&&mouse.old.left||Menu_rightSelection==Button_COPYPASTE&&mouse.old.right){
					line(copyx1,copyy1,copyx2,copyy1,0xFFC0C0);
					line(copyx1,copyy2,copyx2,copyy2,0xFFC0C0);
					line(copyx1,copyy1,copyx1,copyy2,0xFFC0C0);
					line(copyx2,copyy1,copyx2,copyy2,0xFFC0C0);
				}
			}else{
				b=pen_x-floor((copyx2-copyx1)/2);
				c=pen_y-floor((copyy2-copyy1)/2);
				a=copyx2-copyx1;
				e=copyy2-copyy1;
				line(b,c,b+a,c,0xC0C0FF);
				line(b,c+e,b+a,c+e,0xC0C0FF);
				line(b,c,b,c+e,0xC0C0FF);
				line(b+a,c,b+a,c+e,0xC0C0FF);
			}
		}
		//display text box preview
		if(Menu_leftSelection==Button_TEXT||Menu_rightSelection==Button_TEXT){
			line(text_x,text_y,text_x,text_y+13,0xC00000);
			line(text_x,text_y,text_x+200,text_y,0xC00000);
			line(text_x,text_y+13,text_x+200,text_y+13,0xC00000);
		}
		//line mode guide
		if(Menu_penMode==P_LINE&&(mouse.old.left&&(elementbuttons>Menu_leftSelection||M_BLOCK==Menu_leftSelection||M_ERASE==Menu_leftSelection||M_CLEAR==Menu_leftSelection)||mouse.old.right&&(elementbuttons>Menu_rightSelection||M_BLOCK==Menu_rightSelection||M_ERASE==Menu_rightSelection||M_CLEAR==Menu_rightSelection))){
			line(penlinestartx,penlinestarty,pen_x,pen_y,0xFF0000);
		}
	}
};

var Parts_pos=Array(Parts_MAX);
var Parts_vel=Array(Parts_MAX);
var Parts_type=new Uint8Array(Parts_MAX);

//meta2: PUMP particle mostly

var Parts_meta1=new Int32Array(Parts_MAX)
var Parts_pumpType=new Uint8Array(Parts_MAX);
var parts=new Int32Array(316*WIDTH);
var Parts_pos2=new Int32Array(Parts_MAX);
var Parts_held=new Uint8Array(Parts_MAX);

var Parts_used;
for(var i=0;i<Parts_MAX;i++){
	Parts_pos[i]=new Vector;
}
for(var i=0;i<Parts_MAX;i++){
	Parts_vel[i]=new Vector;
}

var neighbors=[1,-1,WIDTH,-WIDTH,WIDTH+1,WIDTH-1,-WIDTH+1,-WIDTH-1],ue=[1,1,0,-1,-1,-1,0,1],ve=[0,-1,-1,-1,0,1,1,1],we=[1,-WIDTH+1,-WIDTH,-WIDTH-1,-1,WIDTH-1,WIDTH,WIDTH+1];
//basically this generates a new particle, I think
function Parts_create(x,y,element){
	//check if can make particle
	if(Parts_used>=Parts_limits[Menu_dotLimit]||x<7||x>=409||y<7||y>=309){
		return -1;
	}
	Parts_pos[Parts_used].set(x,y);
	Parts_vel[Parts_used].set(0,0);
	Parts_type[Parts_used]=element;
	Parts_meta1[Parts_used]=0;
	Parts_pumpType[Parts_used]=0;
	Parts_held[Parts_used]=false;
	Parts_pos2[Parts_used]=~~y*WIDTH+~~x;
	parts[Parts_pos2[Parts_used]]=Parts_used;
	Parts_used++;
	return Parts_used-1;
}
//delete particle? I think...
function remove(part){
	if(Parts_used!=0){
		parts[Parts_pos2[part]]=Parts_EMPTY;
		Parts_used--;
		if(Parts_used!=part){
			Parts_pos[part].copy(Parts_pos[Parts_used]);
			Parts_vel[part].copy(Parts_vel[Parts_used]);
			Parts_type[part]=Parts_type[Parts_used];
			Parts_meta1[part]=Parts_meta1[Parts_used];
			Parts_pumpType[part]=Parts_pumpType[Parts_used];
			Parts_held[part]=Parts_held[Parts_used];
			Parts_pos2[part]=Parts_pos2[Parts_used];
			parts[Parts_pos2[part]]=(Parts_type[part]==FAN?Parts_BGFAN:part);
		}
	}
}
function swap(part1,part2,xy1,xy2){
	var temp;
	
	temp=Parts_pos[part1].x;
	Parts_pos[part1].x=Parts_pos[part2].x;
	Parts_pos[part2].x=temp;
	
	temp=Parts_pos[part1].y;
	Parts_pos[part1].y=Parts_pos[part2].y;
	Parts_pos[part2].y=temp;
	
	temp=parts[xy1];
	parts[xy1]=parts[xy2];
	parts[xy2]=temp;
	
	temp=Parts_pos2[part1];
	Parts_pos2[part1]=Parts_pos2[part2];
	Parts_pos2[part2]=temp;
}

function Parts_blow(part,airvel){
	airvel.mul(3.8/(airvel.fastdist()+1));
	//check x+v,y
	var b=(Parts_pos[part].y>>0)*WIDTH+(Parts_pos[part].x+airvel.x>>0);
	if(parts[b]<=Parts_BGFAN){
		Parts_pos[part].x+=airvel.x;
	}
	//check x,y+v
	b=(Parts_pos[part].y+airvel.y>>0)*WIDTH+(Parts_pos[part].x>>0);
	if(parts[b]<=Parts_BGFAN){
		Parts_pos[part].y+=airvel.y;
	}
	//move
	Parts_pos2[part]=(Parts_pos[part].y>>0)*WIDTH+(Parts_pos[part].x>>0);
	parts[Parts_pos2[part]]=part;
	return Parts_pos2[part];
}

var ze=[0,0,0.2,0,0,0.2,0.7,0.2,0,0,0.8,0.2,0.2,0,0.2,0.5,0,0.5,0,0.9,0.2,0,0,0,0.3,0,0,0,0,0.9,0,0.9,0,0,0,0.8,0.2,0,0.9,0.1,0,0.9,0.9,0.5,0,0.9]
var Ae=[0,0,0.2,0,0,0.2,0.7,0.2,0,0,1,0.2,0.2,0,0.2,0.5,0,0.5,0,0.9,0.2,0,0,0,0.3,0,0,1,0,0.9,0,0.9,0,0,0,0.2,0.2,0,0.5,0.1,0,0.9,0.9,0.5,0,0.9]

window.fff=yd.prototype.Parts_update;
yd.prototype.Parts_update=function(){
	var d=new Vector;
	for(var i=0;i<Wheels.used;i++){
		for(var xy=(Wheels.y[i]-16)*WIDTH+(Wheels.x[i]-16),y=0;y<32;y++,xy+=WIDTH-32){
			for(x=0;x<32;x++,xy++){
				if(parts[xy]==Parts_WHEEL){
					parts[xy]=Parts_EMPTY;
				}
			}
		}
	}
	for(var i=0;i<Wheels.used;i++){
		var xy=(Wheels.y[i]-16)*WIDTH+(Wheels.x[i]-16);
		var uv=32*floor(Wheels.angle[i])*wheelimage.width;
		for(var y=0;y<32;y++,xy+=WIDTH-32){
			for(var x=0;x<32;x++,xy++,uv++){
				if(wheelimage.imagedata[uv]==0&&parts[xy]<=Parts_BGFAN){
					parts[xy]=Parts_WHEEL;
				}
			}
		}
	}
	dragstart=(Menu_leftSelection==M_DRAG&&mouse.rising.left||Menu_rightSelection==M_DRAG&&mouse.rising.right);
	dragging=(Menu_leftSelection==M_DRAG&&mouse.old.left||Menu_rightSelection==M_DRAG&&mouse.old.right);
	for(var i=0;i<Parts_used;i++){
		if(!Menu_cursorInMenu&&wa==0){
			if(!Parts_held[i]){
				if(dragstart){
					if(Parts_type[i]==FAN){
						continue;
					}
					d.x=pen_x-Parts_pos[i].x;
					d.y=pen_y-Parts_pos[i].y;
					if(d.fastdist()<4*Menu_penSize){
						Parts_held[i]=true
					}
				}
			}else if(dragging){
				Parts_vel[i].x+=0.1*(pen_x-Parts_pos[i].x);
				Parts_vel[i].y+=0.1*(pen_y-Parts_pos[i].y);
			}else{
				Parts_held[i]=false;
			}
		}
		//UPDATE ELEMENTS!
		i=i-this.C(i,d);
	}
	//remove particles that go off the edge
	if(Menu_edgeMode==0){
		for(var i=0;i<Parts_used;i++){
			if(Parts_pos[i].x<8||Parts_pos[i].x>=408||Parts_pos[i].y<8||Parts_pos[i].y>=308){
				remove(i--);
			}
		}
	//wrap particles on loop edge mode
	}else if(Menu_edgeMode==1){
		for(var i=0;i<Parts_used;i++){
			if(Parts_pos[i].x<8){
				d=Parts_pos2[i]+400;
				if(parts[d]<=Parts_BGFAN&&Parts_pos[i].y>=8&&Parts_pos[i].y<308){
					parts[Parts_pos2[i]]=Parts_EMPTY;
					Parts_pos[i].x+=400;
					parts[d]=i;
					Parts_pos2[i]=d;
				}else{
					remove(i--);
				}
			}else if(Parts_pos[i].x>=408){
				d=Parts_pos2[i]-400;
				if(parts[d]<=Parts_BGFAN&&Parts_pos[i].y>=8&&Parts_pos[i].y<308){
					parts[Parts_pos2[i]]=Parts_EMPTY;
					Parts_pos[i].x-=400;
					parts[d]=i;
					Parts_pos2[i]=d;
				}else{
					remove(i--);
				}
			}else if(Parts_pos[i].y<8){
				d=Parts_pos2[i]+300*WIDTH
				if(parts[d]<=Parts_BGFAN){
					parts[Parts_pos2[i]]=Parts_EMPTY;
					Parts_pos[i].y+=300;
					parts[d]=i;
					Parts_pos2[i]=d;
				}else{
					remove(i--);
				}
			}else if(Parts_pos[i].y>=308){
				d=Parts_pos2[i]-300*WIDTH;
				if(parts[d]<=Parts_BGFAN){
					parts[Parts_pos2[i]]=Parts_EMPTY;
					Parts_pos[i].y-=300;
					parts[d]=i;
					Parts_pos2[i]=d;
				}else{
					remove(i--);
				}
			}
		}
	}
};

//ELEMENTAL UPDATES
// PART I
window.fff=yd.prototype.C;
yd.prototype.C=function(part,airvel){
	var b,d,e,c,f;
	var x,y
	var aircell=(Parts_pos[part].y>>2)*G+(Parts_pos[part].x>>2);
	var xy=Parts_pos2[part];
	if(Parts_type[part]!=FAN){
		parts[xy]=Parts_EMPTY;
	}
	airvel.copy(Air.vel[aircell]);
	switch(Parts_type[part]){
	case Parts_POWDER:
		airvel.y+=random2(0.01,0.1);
		airvel.add(Parts_vel[part]);
		Parts_vel[part].mul(0.7);
		Parts_blow(part,airvel);
	break;case WATER:
		Parts_vel[part].x+=0.2*Air.vel[aircell].x;
		Parts_vel[part].y+=0.2*Air.vel[aircell].y;
		if(parts[xy+WIDTH]!=Parts_EMPTY){
			if(parts[xy-1]==Parts_EMPTY){
				Parts_vel[part].x-=random2(0.1,0.2);
			}
			if(parts[xy+1]==Parts_EMPTY){
				Parts_vel[part].x+=random2(0.1,0.2);
			}
		}
		Parts_vel[part].x+=random2(-0.01,0.01);
		Parts_vel[part].y+=random2(0.01,0.05);
		Parts_vel[part].mul(0.9);
		airvel.add(Parts_vel[part]);
		xy=Parts_blow(part,airvel);
		c=randomint(8);
		var f;
		f= c<5 ? xy-WIDTH : c<6 ? xy-1 : c<7 ? xy+1 : xy+WIDTH;
		var g=parts[f];
		if(g>=0){
			//solids (except stone),nitro,soapy, and saltwater, diffuse through water
			if(c<7&&(states[Parts_type[g]]==State_POWDER&&Parts_type[g]!=STONE||Parts_type[g]==NITRO||Parts_type[g]==SOAPY||Parts_type[g]==SALTWATER)){
				if(random(100)<10){
					swap(part,g,xy,f);
				}
			//freeze water
			}else if(Parts_type[g]==ICE){
				if(random(100)<50){
					Parts_type[part]=ICE;
				}
			//put water into pump
			}else if(Parts_type[g]==PUMP&&Parts_pumpType[g]==0){
				Parts_meta1[g]=4|(c<5?2:c<6?1:c<7?3:0);
				Parts_pumpType[g]=WATER;
				remove(part);
				return 1;
			}
		}
	break;case FIRE:
		if(Parts_meta1[part]==2){
			Parts_vel[part].mul(0.8);
			airvel.add(Parts_vel[part]);
		}
		airvel.mul(0.2);
		if(Parts_meta1[part]==0||Parts_meta1[part]==2){
			var q=random2(-0.01,-0.05);
			Air.vel[aircell].x+=random2(-0.02,0.02);
			Air.vel[aircell].y+=q;
			Air.pres[aircell]+=-q;
			pd-=-q;
		}else if(Parts_meta1[part]==1){
			q=random2(-0.01,-0.05);
			Air.pres[aircell]+=-q;
			pd-=-q; //-=-
		}
		xy=Parts_blow(part,airvel);
		xy+=randomint(5)-2;
		xy+=(randomint(5)-2)*WIDTH;
		g=parts[xy-WIDTH];
		if(g>=0){
			switch(Parts_type[g]){
			case Parts_POWDER:case ANT:case VINE:
				Parts_type[g]=FIRE;
			break;case WATER:case SALTWATER:
				remove(part);
				return 1;
			break;case SEED:
				if(random(100)<50){
					Parts_type[g]=FIRE;
				}
			break;case SNOW:
				Parts_type[g]=WATER;
			}
		}
		c=5;
		if(Parts_meta1[part]==1){
			c=20;
		}
		//kill fire
		if(random(100)<c){
			remove(part);
			return 1;
		}
	break;case SEED:
		//normal mode, perform physics
		if(Parts_meta1[part]==0){
			airvel.y+=random2(0.01,0.09);
			airvel.add(Parts_vel[part]);
			Parts_vel[part].mul(0.8);
		//growing mode, set velocity to 0
		}else{
			airvel.set(0,0);
		}
		var xy=Parts_blow(part,airvel);
		//if not in growing mode...
		if(Parts_meta1[part]==0){
			//find part belowish
			var below=parts[xy+WIDTH];
			//if not wood/powder/vine (or not enough parts left), return
			if(below<0||(Parts_type[below]!=Parts_POWDER&&Parts_type[below]!=WOOD&&Parts_type[below]!=VINE)||Parts_limits[Menu_dotLimit]-Parts_used<1000){
				return 0;
			}
		}
		//enter grow mode
		Parts_meta1[part]=1;
		//pick point x+[-1,0,1],y+[0,0,-1]
		var x=~~Parts_pos[part].x+randomint(3)-1;
		var y=~~Parts_pos[part].y-randomint(1.5);
		var xy=y*WIDTH+x;
		//if empty
		if(parts[xy]<=Parts_BGFAN){
			//if below is empty
			if(parts[xy+WIDTH]<=Parts_BGFAN){
				//move seed
				parts[Parts_pos2[part]]=Parts_EMPTY;
				Parts_pos[part].set(x,y);
				Parts_pos2[part]=~~y*WIDTH+~~x;
				parts[Parts_pos2[part]]=part;
				//create wood
				Parts_create(x,y+1,WOOD);
			}
			//kill
			if(random(100)<5){
				remove(part);
				return 1;
			}
		}
	//wood
	break;case WOOD:
		airvel.copy(Parts_vel[part]);
		Parts_vel[part].mul(0.3);
		var xy=Parts_blow(part,airvel);
		//not burning
		if(Parts_meta1[part]==0){
			// x+[-2,-1,0,1,2]
			xy+=randomint(5)-2;
			// y+[-3,-2,-1,0,1,2,3]
			xy+=(randomint(7)-3)*WIDTH;
			var near=parts[xy];
			if(near>=0){
				switch(Parts_type[near]){
				//fire and magma burn wood
				case FIRE:case MAGMA:
					if(random(100)<50){
						Parts_meta1[part]=1;
					}
				//wood creates seed when near water
				break;case WATER:
					if(Parts_limits[Menu_dotLimit]-Parts_used<1000){
						return 0;
					}
					x=~~Parts_pos[part].x+randomint(3)-1;
					y=~~Parts_pos[part].y+randomint(3)-1;
					xy=y*WIDTH+x;
					if(parts[xy]<=Parts_BGFAN&&random(100)<10){
						Parts_create(x,y,SEED);
					}
				}
			}
		//burning
		}else if(Parts_meta1[part]==1){
			c=~~Parts_pos[part].x+randomint(3)-1;
			q=~~Parts_pos[part].y+randomint(3)-1;
			xy=q*WIDTH+c;
			g=parts[xy];
			//make fires
			if(parts[xy]<=Parts_BGFAN){
				if(random(100)<30){
					xy=Parts_create(c,q,FIRE)
					if(xy>=0){
						Parts_meta1[xy]=1;
					}
				}
			//water puts out the fire and breaks the wood into powder
			}else if(g>=0&&Parts_type[g]==WATER){
				Parts_meta1[part]=0;
				Parts_type[part]=Parts_POWDER;
			}
			//parts[xy]<=Parts_BGFAN?30>random(100)&&(xy=Parts_create(c,q,FIRE),0<=xy&&(Parts_meta1[xy]=1)):0<=g&&Parts_type[g]==WATER&&(Parts_meta1[part]=0,Parts_type[part]=Parts_POWDER)
			//generate powder sometimes
			if(random(1000)<5){
				Parts_type[part]=Parts_POWDER
			}
		}
	break;case GUNPOWDER:
		airvel.y+=random2(0.01,0.2);
		airvel.add(Parts_vel[part]);
		Parts_vel[part].mul(0.8);
		xy=Parts_blow(part,airvel);
		xy+=randomint(5)-2;
		xy+=(randomint(5)-2)*WIDTH;
		g=parts[xy];
		//don't explode
		if(g<0||states[Parts_type[g]]!=State_HOT){
			return 0;
		}
		b=10;
		var n=Parts_pos[part].x&0xFFF4,r=Parts_pos[part].y&0xFFF4,w=max(n-b,H);
		c=max(r-b,H);
		var y=min(n+b,WIDTH-H-1);
		var z=min(r+b,(kd-1)*H-1);
		for(var q=c;q<=z;q++){
			for(c=w;c<=y;c++){
				xy=(c-n)*(c-n)+(q-r)*(q-r);
				if(xy<=b*b){
					xy=q*WIDTH+c
					g=parts[xy]
					if(g>=0&&Parts_type[g]!=GUNPOWDER){
						Parts_vel[g].x+=10*(c-n);
						Parts_vel[g].y+=10*(q-r);
					}
					if((q&3)+(c&3)==0){
						xy=(q>>2)*G+(c>>2);
						if(blocks[xy]<=0){
							if(abs(c-n)>=1){
								Air.vel[xy].x+=10/(c-n);
							}
							if(abs(q-r)>=1){
								Air.vel[xy].y+=10/(q-r);
							}
						}
					}
				}
			}
		}
		Parts_type[part]=FIRE
	break;case FAN:
		Air.vel[aircell].add(Parts_vel[part]);
		if(parts[xy]==Parts_EMPTY){
			parts[xy]=Parts_BGFAN;
		}
	break;case ICE:
		//break into snow
		if(airvel.fastdist()>1&&random(100)<50){
			Parts_type[part]=SNOW;
		}
		airvel.set(0,0);
		xy=Parts_blow(part,airvel);
		xy+=randomint(9)-4;
		xy+=(randomint(9)-4)*WIDTH;
		g=parts[xy];
		//hot things melt ice into water
		if(g>=0&&states[Parts_type[g]]==State_HOT){
			Parts_type[part]=WATER;
		}
	break;case SNOW:
		airvel.y+=random2(0.01,0.08);
		airvel.add(Parts_vel[part]);
		Parts_vel[part].mul(0.7);
		xy=Parts_blow(part,airvel);
		xy+=randomint(3)-1;
		xy+=(randomint(3)-1)*WIDTH;
		g=parts[xy];
		//if touching another particle besides wood,9?,snow,clone,vine,cloud, melt into water (or freeze if touching ice)
		if(g>=0){
			if(Parts_type[g]==ICE){
				Parts_type[part]=ICE;
			}else if(Parts_type[g]!=WOOD&&Parts_type[g]!=9&&Parts_type[g]!=SNOW&&Parts_type[g]!=CLONE&&Parts_type[g]!=VINE&&Parts_type[g]!=CLOUD){
				Parts_type[part]=WATER;
			}
			
		}
		//0<=g&&6!=Parts_type[g]&&9!=Parts_type[g]&&11!=Parts_type[g]&&Parts_type[g]!=CLONE&&Parts_type[g]!=VINE&&Parts_type[g]!=CLOUD&&(Parts_type[part]=Parts_type[g]==ICE?ICE:WATER);
	break;case STEAM:
		airvel.add(Parts_vel[part]);
		Parts_vel[part].mul(0.7);
		Parts_blow(part,airvel);
		//disappear 10%
		if(random(100)<10){
			remove(part);
			return 1;
		}
	break;case SUPERBALL:
		airvel.mul(0.05);
		Parts_vel[part].add(airvel);
		Parts_vel[part].y+=0.01;
		Parts_vel[part].mul(0.999);
		airvel.copy(Parts_vel[part]);
		airvel.mul(3.8/(airvel.fastdist()+1));
		f=~~Parts_pos[part].y*WIDTH+~~(Parts_pos[part].x+airvel.x);
		//psuedo particles
		if(parts[f]<=Parts_BGFAN){
			Parts_pos[part].x+=airvel.x;
		}else if(parts[f]<=-1){
			Parts_vel[part].x*=-0.9;
			Parts_vel[part].y*=0.9;
		//real
		}else if(parts[f]>=0){
			//liquids other than mercury
			if(states[Parts_type[parts[f]]]==State_LIQUID&&Parts_type[parts[f]]!=MERCURY){
				Parts_vel[parts[f]].x-=Parts_vel[part].x;
				Parts_vel[part].x*=0.5;
				c=Parts_pos[part].x;
				Parts_pos[part].x=Parts_pos[parts[f]].x;
				Parts_pos[parts[f]].x=c;
				Parts_pos2[parts[f]]=xy;
				parts[xy]=parts[f];
			//fire
			}else if(Parts_type[parts[f]]==FIRE){
				c=Parts_pos[part].x;
				Parts_pos[part].x=Parts_pos[parts[f]].x;
				Parts_pos[parts[f]].x=c;
				Parts_pos2[parts[f]]=xy;
				parts[xy]=parts[f];
			//superball
			}else if(Parts_type[parts[f]]==SUPERBALL){
				c=0.9*Parts_vel[part].x;
				Parts_vel[part].x=0.9*Parts_vel[parts[f]].x;
				Parts_vel[parts[f]].x=c;
			//others
			}else{
				Parts_vel[part].x*=-ze[Parts_type[parts[f]]];
				Parts_vel[part].y*=Ae[Parts_type[parts[f]]];
			}
		}
		xy=~~Parts_pos[part].y*WIDTH+~~Parts_pos[part].x;
		parts[xy]=Parts_EMPTY;
		f=~~(Parts_pos[part].y+airvel.y)*WIDTH+~~Parts_pos[part].x;
		if(parts[f]<=Parts_BGFAN){
			Parts_pos[part].y+=airvel.y;
		}else if(parts[f]<=-1){
			Parts_vel[part].y*=-0.9;
			Parts_vel[part].x*=0.9;
		}else if(parts[f]>=0){
			if(states[Parts_type[parts[f]]]==State_LIQUID&&Parts_type[parts[f]]!=MERCURY){
				Parts_vel[parts[f]].y-=Parts_vel[part].y;
				Parts_vel[part].y*=0.5,q=Parts_pos[part].y;
				Parts_pos[part].y=Parts_pos[parts[f]].y;
				Parts_pos[parts[f]].y=q;
				Parts_pos2[parts[f]]=xy;
				parts[xy]=parts[f];
			}else if(Parts_type[parts[f]]==FIRE){
				q=Parts_pos[part].y;
				Parts_pos[part].y=Parts_pos[parts[f]].y;
				Parts_pos[parts[f]].y=q;
				Parts_pos2[parts[f]]=xy;
				parts[xy]=parts[f];
			}else if(Parts_type[parts[f]]==SUPERBALL){
				if(Parts_vel[part].y>0){
					c=0.45*Parts_vel[part].y;
					Parts_vel[part].y*=-0.45;
					Parts_vel[part].y+=Parts_vel[parts[f]].y;
					Parts_vel[parts[f]].y=c;
				}else{
					c=0.45*Parts_vel[parts[f]].y;
					Parts_vel[parts[f]].y*=-0.45;
					Parts_vel[parts[f]].y+=Parts_vel[part].y;
					Parts_vel[part].y=c;
				}
			}else{
				Parts_vel[part].y*=-ze[Parts_type[parts[f]]];
				Parts_vel[part].x*=Ae[Parts_type[parts[f]]];
			}
		}
		Parts_pos2[part]=~~Parts_pos[part].y*WIDTH+~~Parts_pos[part].x;
		parts[Parts_pos2[part]]=part;
	break;case CLONE:
		airvel.set(0,0)
		xy=Parts_blow(part,airvel)
		//if not cloning
		if(Parts_meta1[part]==0){
			xy+=randomint(5)-1;
			xy+=(randomint(5)-1)*WIDTH;
			g=parts[xy];
			//if there's another particle, start cloning it (or if it's clone, copy its particle Parts_type. actually pretty smart)
			if(g>=0){
				if(Parts_type[g]==CLONE){
					Parts_meta1[part]=Parts_meta1[g];
				}else{
					Parts_meta1[part]=Parts_type[g];
				}
			}
		//generate particles
		}else{
			if(Parts_limits[Menu_dotLimit]-Parts_used<1000){
				return 0;
			}
			c=~~Parts_pos[part].x+randomint(3)-1;
			q=~~Parts_pos[part].y+randomint(3)-1;
			xy=q*WIDTH+c;
			if(parts[xy]<=Parts_BGFAN&&random(100)<10){
				Parts_create(c,q,Parts_meta1[part])
			}
		}
	break;case FIREWORKS:
		Parts_vel[part].x+=0.1*Air.vel[aircell].x;
		Parts_vel[part].y+=0.1*Air.vel[aircell].y;
		airvel.y+=random2(0.1,0.2);
		Parts_vel[part].mul(0.9);
		airvel.add(Parts_vel[part]);
		xy=Parts_blow(part,airvel);
		if(Parts_meta1[part]==0){
			Parts_meta1[part]=fireworkelements[Menu_leftSelection]||fireworkelements[Menu_rightSelection]||Parts_POWDER;
		}else if(Parts_meta1[part]<100){
			xy+=randomint(3)-1;
			xy+=(randomint(3)-1)*WIDTH;
			if(parts[xy]>=0&&states[Parts_type[parts[xy]]]==State_HOT){
				Parts_vel[part].y-=0.1;
				Parts_vel[part].fastnormalize();
				Parts_vel[part].mul(50);
				Parts_meta1[part]+=100;
			}
		}else{
			if(Parts_meta1[part]<5000){
				Parts_meta1[part]+=100;
				return 0;
			}else if(random(100)>5){
				return 0;
			}else if(Parts_limits[Menu_dotLimit]-Parts_used<1000){
				remove(part);
				return 1;
			}
			for(b=0;b<512;b+=32){
				c=~~(Parts_pos[part].x+2*sincos[b][0]);
				q=~~(Parts_pos[part].y+2*sincos[b][1]);
				c=clamp(c,8,408);
				q=clamp(q,8,308);
				xy=q*WIDTH+c;
				if(parts[xy]<=Parts_BGFAN){
					
					xy=Parts_create(c,q,Parts_meta1[part]%100);
					if(xy>=0){
						Parts_vel[xy].x+=20*sincos[b][0];
						Parts_vel[xy].y+=20*sincos[b][1];
					}
				}
			}
			remove(part);
			return 1;
		}
	break;case OIL:
		Parts_vel[part].x+=0.2*Air.vel[aircell].x;
		Parts_vel[part].y+=0.2*Air.vel[aircell].y;
		if(parts[xy+WIDTH]!=Parts_EMPTY){
			if(parts[xy-1]==Parts_EMPTY){
				Parts_vel[part].x-=random2(0.1,0.2);
			}
			if(parts[xy+1]==Parts_EMPTY){
				Parts_vel[part].x+=random2(0.1,0.2);
			}
		}
		Parts_vel[part].x+=random2(-0.01,0.01);
		Parts_vel[part].y+=random2(0.01,0.05);
		Parts_vel[part].mul(0.9);
		airvel.add(Parts_vel[part]);
		xy=Parts_blow(part,airvel);
		c=randomint(8);
		f=c<5?xy-WIDTH:c<6?xy-1:c<7?xy+1:xy+WIDTH;
		g=parts[f];
		if(g>=0){
			//powders (except stone), water, nitro, saltwater
			if(c<7&&(states[Parts_type[g]]==State_POWDER&&Parts_type[g]!=STONE||Parts_type[g]==WATER||Parts_type[g]==NITRO||Parts_type[g]==SALTWATER)){
				if(random(100)<10){
					swap(part,g,xy,f);
				}
			//burn
			}else if(states[Parts_type[g]]==State_HOT){
				Parts_meta1[part]=1;
			//oil is absorbed by FUSE
			}else if(Parts_type[g]==FUSE&&Parts_meta1[g]<256){
				Parts_meta1[g]=OIL;
				remove(part);
				return 1;
			//and PUMP
			}else if(Parts_type[g]==PUMP&&Parts_pumpType[g]==0){
				Parts_meta1[g]=4|(c<5?2:c<6?1:c<7?3:0);
				Parts_pumpType[g]=OIL;
				remove(part);
				return 1;
			}
		}
		//fireyfire
		if(Parts_meta1[part]==1){
			c=~~Parts_pos[part].x+randomint(3)-1
			q=~~Parts_pos[part].y+randomint(3)-1
			f=q*WIDTH+c
			if(parts[f]<=Parts_BGFAN){
				Parts_create(c,q,FIRE);
			}
			if(random(100)<10){
				remove(part);
				return 1;
			}
		}
	break;case C4:
		airvel.set(0,0);
		xy=Parts_blow(part,airvel);
		//check explodeystate
		if(Parts_meta1[part]==0){
			xy+=randomint(3)-1;
			xy+=(randomint(3)-1)*WIDTH;
			g=parts[xy];
			//enter explodeystate
			if(g>=0&&states[Parts_type[g]]==State_HOT){
				Parts_meta1[part]=1;
			}
		}else{
			//spread explodeystate
			for(b=0;b<8;b++){
				f=xy+neighbors[b];
				g=parts[f];
				if(g>=0&&Parts_type[g]==C4){
					Parts_meta1[g]=1;
				}
			}
			b=10;
			n=Parts_pos[part].x&0xFFF4;
			r=Parts_pos[part].y&0xFFF4;
			w=max(n-b,H);
			c=max(r-b,H);
			y=min(n+b,WIDTH-H-1);
			z=min(r+b,(kd-1)*H-1);
			for(q=c;q<=z;q++){
				for(c=w;c<=y;c++){
					if((c-n)*(c-n)+(q-r)*(q-r)<=b*b){
						f=q*WIDTH+c;
						g=parts[f];
						if(g>=0){
							Parts_vel[g].x+=10*(c-n);
							Parts_vel[g].y+=10*(q-r);
						}
						if((q&3)+(c&3)==0){
							f=(q>>2)*G+(c>>2)
							if(blocks[f]<=0){
								if(abs(c-n)>=1){
									Air.vel[f].x+=1/(c-n);
								}
								if(abs(q-r)>=1){
									Air.vel[f].y+=1/(q-r);
								}
							}
						}
					}
				}
			}
			remove(part);
			return 1;
		}
	break;case STONE:
		Parts_vel[part].x+=0.05*Air.vel[aircell].x;
		Parts_vel[part].y+=0.05*Air.vel[aircell].y;
		Parts_vel[part].y+=random2(0.01,0.05);
		Parts_vel[part].mul(0.95);
		airvel.copy(Parts_vel[part]);
		if(airvel.fastdist()>10&&random(100)<50){
			Parts_type[part]=Parts_POWDER
		}
		airvel.mul(3.8/(airvel.fastdist()+1));
		f=~~Parts_pos[part].y*WIDTH+~~(Parts_pos[part].x+airvel.x);
		if(parts[f]<=Parts_BGFAN){
			Parts_pos[part].x+=airvel.x;
		}else{
			if(parts[f]>=0){
				//liquids other than magma and mercury
				if(states[Parts_type[parts[f]]]==State_LIQUID&&Parts_type[parts[f]]!=MERCURY||Parts_type[parts[f]]==MAGMA){
					Parts_vel[parts[f]].x-=Parts_vel[part].x;
					var g=Parts_pos[part].x;
					Parts_pos[part].x=Parts_pos[parts[f]].x;
					Parts_pos[parts[f]].x=g;
					Parts_pos2[parts[f]]=xy;
					parts[xy]=parts[f];
				//powder seed gunpowder fireworks ant
				}else if(Parts_type[parts[f]]==Parts_POWDER||Parts_type[parts[f]]==SEED||Parts_type[parts[f]]==GUNPOWDER||Parts_type[parts[f]]==FIREWORKS||Parts_type[parts[f]]==ANT)
					Parts_vel[parts[f]].x+=random(Parts_vel[part].x);
			}
			Parts_vel[part].x*=0.5;
		}
		xy=~~Parts_pos[part].y*WIDTH+~~Parts_pos[part].x;
		parts[xy]=Parts_EMPTY;
		f=~~(Parts_pos[part].y+airvel.y)*WIDTH+~~Parts_pos[part].x;
		if(parts[f]<=Parts_BGFAN){
			Parts_pos[part].y+=airvel.y;
		}else{
			if(parts[f]>=0){
				//liquids other than mercury and magma
				if(states[Parts_type[parts[f]]]==State_LIQUID&&Parts_type[parts[f]]!=MERCURY||Parts_type[parts[f]]==MAGMA){
					Parts_vel[parts[f]].y-=Parts_vel[part].y;
					var q=Parts_pos[part].y;
					Parts_pos[part].y=Parts_pos[parts[f]].y;
					Parts_pos[parts[f]].y=q;
					Parts_pos2[parts[f]]=xy;
					parts[xy]=parts[f]
				//powder seed gunpowder fireworks ant
				}else if(Parts_type[parts[f]]==Parts_POWDER||Parts_type[parts[f]]==SEED||Parts_type[parts[f]]==GUNPOWDER||Parts_type[parts[f]]==FIREWORKS||Parts_type[parts[f]]==ANT){
					Parts_vel[parts[f]].y+=random(Parts_vel[part].y);
				}
			}
			Parts_vel[part].y*=0.5;
		}
		Parts_pos2[part]=~~Parts_pos[part].y*WIDTH+~~Parts_pos[part].x;
		parts[Parts_pos2[part]]=part;
	break;case MAGMA:
		Parts_vel[part].x+=0.1*Air.vel[aircell].x;
		Parts_vel[part].y+=0.1*Air.vel[aircell].y;
		if(parts[xy+WIDTH]!=Parts_EMPTY){
			if(parts[xy-1]==Parts_EMPTY){
				Parts_vel[part].x-=random2(0,0.1)
			}
			if(parts[xy+1]==Parts_EMPTY){
				Parts_vel[part].x+=random2(0,0.1);
			}
		}
		Parts_vel[part].x+=random2(-0.01,0.01);
		Parts_vel[part].y+=random2(0.01,0.1);
		Parts_vel[part].mul(0.9);
		airvel.add(Parts_vel[part]);
		xy=Parts_blow(part,airvel);
		xy+=randomint(5)-2;
		xy+=(randomint(5)-2)*WIDTH;
		var n=parts[xy-WIDTH];
		if(n>=0){
			//burn powder
			switch(Parts_type[n]){
			case Parts_POWDER:case SEED:case SUPERBALL:case ANT:case VINE:
				Parts_type[n]=FIRE;
			//magma+water/soapy = stone+steam
			break;case WATER:case SOAPY:
				Parts_type[part]=STONE;
				Parts_type[n]=STEAM;
				if(random(100)<50){
					remove(part);
					return 1;
				}
			//melt stone
			break;case STONE:
				Parts_vel[n].x+=random2(-0.1,0.1);
				if(random(100)<5){
					Parts_type[n]=MAGMA;
				}
			//magma+saltwater=stone+salt (no steam, note)
			break;case SALTWATER:
				Parts_type[part]=STONE
				Parts_type[n]=SALT
				if(random(100)<50){
					remove(part);
					return 1;
				}
			//melt glass
			break;case GLASS:
				if(random(100)<50){
					Parts_type[n]=MAGMA;
				}
			//slowly melt mercury
			break;case MERCURY:
				if(random(100)<1){
					Parts_type[n]=MAGMA;
				}
			}
		}
		g=randomint(4);
		f=g<1?xy-WIDTH:g<2?xy-1:g<3?xy+1:xy+WIDTH;
		n=parts[f];
		//enter pump
		if(n>=0&&Parts_type[n]==PUMP&&Parts_pumpType[n]==0){
			Parts_meta1[n]=0b100|(g<1?0b10:g<2?0b01:g<3?0b11:0b00);
			Parts_pumpType[n]=MAGMA;
			remove(part);
			return 1;
		}
	break;case VIRUS:
		airvel.y+=random2(0,0.1);
		airvel.add(Parts_vel[part]);
		Parts_vel[part].mul(0.7);
		xy=Parts_blow(part,airvel); //examine this
		if(Parts_meta1[part]==0){
			f=xy+(randomint(3)-1);
			f+=(randomint(3)-1)*WIDTH;
			if(parts[f]>=0&&Parts_type[parts[f]]!=VIRUS){
				Parts_meta1[part]=Parts_type[parts[f]];
			}
		}else if(Parts_meta1[part]<=0x800){
			f=xy+(randomint(3)-1);
			f+=(randomint(3)-1)*WIDTH;
			if(xy!=f&&parts[f]>=0&&(Parts_type[parts[f]]!=VIRUS||Parts_meta1[parts[f]]==0)){
				Parts_type[parts[f]]=VIRUS;
				Parts_meta1[parts[f]]=Parts_meta1[part]&0xFF;
				Parts_pumpType[parts[f]]=0;
			}
			Parts_meta1[part]+=0x100;
		}else{
			Parts_meta1[part]+=0x100;
			if(Parts_meta1[part]>=0x8000){
				Parts_type[part]=Parts_meta1[part]&0xFF;
				Parts_meta1[part]=0;
				Parts_vel[part].set(0,0);
			}
		}

		//0==Parts_meta1[part]?(f=xy+(randomint(3)-1),f+=(randomint(3)-1)*WIDTH,0<=parts[f]&&Parts_type[parts[f]]!=VIRUS&&(Parts_meta1[part]=Parts_type[parts[f]])):2048>=Parts_meta1[part]?(f=xy+(randomint(3)-1),f+=(randomint(3)-1)*WIDTH,xy!=f&&0<=parts[f]&&(Parts_type[parts[f]]!=VIRUS||0==Parts_meta1[parts[f]])&&(Parts_type[parts[f]]=VIRUS,Parts_meta1[parts[f]]=Parts_meta1[part]&0xFF,Parts_pumpType[parts[f]]=0),Parts_meta1[part]+=256):(Parts_meta1[part]+=256,32768<=Parts_meta1[part]&&(Parts_type[part]=Parts_meta1[part]&0xFF,Parts_meta1[part]=0,Parts_vel[part].set(0,0)));
	break;case NITRO:
		Parts_vel[part].x+=0.2*Air.vel[aircell].x;
		Parts_vel[part].y+=0.2*Air.vel[aircell].y;
		if(parts[xy+WIDTH]!=Parts_EMPTY){
			if(parts[xy-1]==Parts_EMPTY){
				Parts_vel[part].x-=random2(0.1,0.2);
			}
			if(parts[xy+1]==Parts_EMPTY){
				Parts_vel[part].x+=random2(0.1,0.2);
			}
		}
		Parts_vel[part].x+=random2(-0.01,0.01);
		Parts_vel[part].y+=random2(0.01,0.05);
		Parts_vel[part].mul(0.9);
		airvel.add(Parts_vel[part]);
		xy=Parts_blow(part,airvel);
		g=randomint(8);
		f=g<5?xy-WIDTH:g<6?xy-1:g<7?xy+1:xy+WIDTH;
		n=parts[f];
		if(n>=0){
			//powders (except stone)
			if(g<7&&states[Parts_type[n]]==State_POWDER&&Parts_type[n]!=STONE){
				if(random(100)<10){
					swap(part,n,xy,f);
				}
			//fuse
			}else if(Parts_type[n]==FUSE&&Parts_meta1[n]<256){
				Parts_meta1[n]=NITRO;
				remove(part);
				return 1;
			//pump
			}else if(Parts_type[n]==PUMP&&Parts_pumpType[n]==0){
				Parts_meta1[n]=4|(g<5?2:g<6?1:g<7?3:0);
				Parts_pumpType[n]=NITRO;
				remove(part);
				return 1;
			}
		}
		if(Parts_vel[part].fastdist()<10){
			f=xy+(randomint(5)-2);
			f+=(randomint(5)-2)*WIDTH;
			if(parts[f]<0||states[Parts_type[parts[f]]]!=State_HOT){
				return 0;
			}
		}
		xy=10;
		b=Parts_pos[part].x&0xFFFC;
		var r=Parts_pos[part].y&0xFFFC,w=max(b-xy,H),n=max(r-xy,H),y=min(b+xy,WIDTH-H-1),z=min(r+xy,(kd-1)*H-1)
		for(var q=n;q<=z;q++){
			for(g=w;g<=y;g++){
				f=(g-b)*(g-b)+(q-r)*(q-r);
				if(f<=xy*xy){
					f=q*WIDTH+g;
					if(parts[f]>=0){
						Parts_vel[parts[f]].x+=10*(g-Parts_pos[part].x);
						Parts_vel[parts[f]].y+=10*(q-Parts_pos[part].y);
					}
					if((q&3)+(g&3)==0){
						f=(q>>2)*G+(g>>2);
						if(blocks[f]<=0){
							if(abs(g-b)>=1){
								Air.vel[f].x+=10/(g-b);
							}
							if(abs(q-r)>=1){
								Air.vel[f].y+=10/(q-r);
							}
						}
					}
				}
			}
		}
		Parts_type[part]=FIRE;
	break;case ANT:
		n=parts[xy+WIDTH];
		//build in wood/ice/c4/metal/vine/glass/fuse/pump
		if(Parts_meta1[part]==0&&n>=0&&(Parts_type[n]==WOOD||Parts_type[n]==ICE||Parts_type[n]==C4||Parts_type[n]==METAL||Parts_type[n]==VINE||Parts_type[n]==GLASS||Parts_type[n]==FUSE||Parts_type[n]==PUMP)){
			Parts_meta1[part]=Parts_type[n]<<2;
		}
		//when in powder mode, do physics, otherwise reset Parts_velocity
		if(Parts_meta1[part]==0){
			airvel.y+=random2(0.01,0.2)
			if(n!=Parts_EMPTY){
				if(parts[xy-1]==Parts_EMPTY){
					Parts_vel[part].x-=random2(0,0.1);
				}
				if(parts[xy+1]==Parts_EMPTY){
					Parts_vel[part].x+=random2(0,0.1);
				}
			}
		}else{
			airvel.set(0,0);
		}
		airvel.add(Parts_vel[part]);
		Parts_vel[part].mul(0.85);
		xy=Parts_blow(part,airvel);
		//if not in build mode, or if near dot limit, return
		if(Parts_meta1[part]==0||Parts_limits[Menu_dotLimit]-Parts_used<1000){
			return 0;
		}
		g=Parts_meta1[part]&3;
		f=xy+[1,WIDTH,-1,-WIDTH][g];
		n=parts[f];
		if(n<=Parts_BGFAN){
			Parts_meta1[part]=Parts_meta1[part]&0xFFFFFC|g+1&0b11;
			f=Parts_create(f%WIDTH,~~(f/WIDTH),ANT);
			if(f>0){
				Parts_meta1[f]=Parts_meta1[part]
			}
			Parts_type[part]=Parts_meta1[part]>>2;
			Parts_meta1[part]=0;
		}else{
			if(n>=0){
				if(Parts_type[n]==Parts_meta1[part]>>2){
					Parts_meta1[part]=Parts_meta1[part]&0xFFFFFC|g-1&0b11;
				}
				Parts_type[n]=Parts_type[part];
				Parts_meta1[n]=Parts_meta1[part];
				Parts_pumpType[n]=0;
				remove(part);
				return 1;
			}
			Parts_meta1[part]=Parts_meta1[part]&0xFFFFFC|g+1&0b11;
		}
	break;case TORCH:
		airvel.set(0,0);
		xy=Parts_blow(part,airvel);
		xy+=randomint(5)-2;
		xy+=(randomint(5)-2)*WIDTH;
		n=parts[xy];
		if(n>=0){
			switch(Parts_type[n]){
			//burn
			case Parts_POWDER:case SEED:case SUPERBALL:case ANT:case VINE:
				Parts_type[n]=FIRE;
			//be destroyed by water,soapy,saltwater
			break;case WATER:case SOAPY:case SALTWATER:
				remove(part);
				return 1;
			//turn wood into torch
			break;case WOOD:
				Parts_type[n]=TORCH;
			//melt snow
			break;case SNOW:
				Parts_type[n]=WATER;
			}
		}
	break;case GAS:
		airvel.y+=random2(0,-0.02);
		airvel.add(Parts_vel[part]);
		Parts_vel[part].mul(0.9);
		xy=Parts_blow(part,airvel);
		g=randomint(4);
		f=g<1?xy-WIDTH:g<2?xy-1:g<3?xy+1:xy+WIDTH;
		n=parts[f];
		if(n>=0){
			//do something with powders and liquids
			if(g<3&&(states[Parts_type[n]]==State_POWDER||states[Parts_type[n]]==State_LIQUID)){
				swap(part,n,xy,f);
			//diffuse
			}else if(Parts_type[n]==GAS){
				Parts_vel[part].x+=random2(-0.2,0.2);
				Parts_vel[part].y+=random2(-0.2,0.2);
			//enter pump
			}else if(Parts_type[n]==PUMP&&Parts_pumpType[n]==0){
				Parts_meta1[n]=0b100|(g<1?0b10:g<2?0b01:g<3?0b11:0b00);
				Parts_pumpType[n]=GAS;
				remove(part);
				return 1;
			}
		}
		if(Parts_meta1[part]==0){
			f=xy+(randomint(5)-2);
			f+=(randomint(5)-2)*WIDTH;
			if(parts[f]<0||states[Parts_type[parts[f]]]!=State_HOT){
				return 0;
			}
		}else if(Parts_meta1[part]<2){
			Parts_meta1[part]++;
			return 0;
		}
		xy=10;
		b=~~Parts_pos[part].x;
		r=~~Parts_pos[part].y;
		w=max(b-xy,H);
		n=max(r-xy,H);
		y=min(b+xy,WIDTH-H-1);
		z=min(r+xy,(kd-1)*H-1);
		for(q=n;q<=z;q++){
			for(g=w;g<=y;g++){
				if((g-b)*(g-b)+(q-r)*(q-r)<=xy*xy){ ///radius HAHAH!!!
					f=q*WIDTH+g
					n=parts[f]
					if(n>=0&&Parts_type[n]==GAS){
						Parts_meta1[n]=1
					}
					if(n<=Parts_BGFAN&&random(100)<1){
						Parts_create(g,q,FIRE);
					}
				}
			}
		}
		Air.pres[aircell]+=2;
		pd-=2;
		Parts_type[part]=FIRE;
		Parts_meta1[part]=0;
	break;case SOAPY:
		//if it promised to die
		if(Parts_meta1[part]==1){
			remove(part);
			return 1;
		}
		Parts_vel[part].x+=0.3*Air.vel[aircell].x;
		Parts_vel[part].y+=0.3*Air.vel[aircell].y;
		if(parts[xy+WIDTH]!=Parts_EMPTY){
			if(parts[xy-1]==Parts_EMPTY){
				Parts_vel[part].x-=random2(0.1,0.2);
			}
			if(parts[xy+1]==Parts_EMPTY){
				Parts_vel[part].x+=random2(0.1,0.2);
			}
		}
		Parts_vel[part].x+=random2(-0.01,0.01);
		Parts_vel[part].y+=random2(0.01,0.05);
		Parts_vel[part].mul(0.9);
		airvel.add(Parts_vel[part]);
		xy=Parts_blow(part,airvel);
		g=randomint(8);
		f= g<5 ? xy-WIDTH : g<6 ? xy-1 : g<7 ? xy+1 : xy+WIDTH;
		n=parts[f];
		if(n>=0){
			switch(Parts_type[n]){
			//freeze
			case ICE:
				if(random(100)<50){
					Parts_type[part]=ICE;
				}
			//dissolve oil
			break;case OIL:
				Parts_type[n]=SOAPY;
				Parts_meta1[n]=1;//both particles promise to die
				Parts_meta1[part]=1;
			//SOAP FUSE!!!
			break;case FUSE:
				if(Parts_meta1[n]<256){
					Parts_meta1[n]=SOAPY;
					remove(part);
					return 1;
				}
			//pump
			break;case PUMP:
				if(Parts_pumpType[n]==0){
					Parts_meta1[n]=4|(g<5 ? 2 : g<6 ? 1 : g<7 ? 3 : 0);
					Parts_pumpType[n]=SOAPY;
					remove(part);
					return 1;
				}
			//diffuse
			break;default:
				if(states[Parts_type[n]]==State_POWDER&&Parts_type[n]!=STONE||Parts_type[n]==NITRO||Parts_type[n]==SALTWATER){
					if(g<7&&random(100)<10){
						swap(part,n,xy,f);
					}
				}
			}
		}
		//probably some crazy stuff happens here
		if(Parts_vel[part].fastdist()>2){
			f=0;
			xy=4;
			b=~~Parts_pos[part].x;
			r=~~Parts_pos[part].y;
			w=max(b-xy,H);
			n=max(r-xy,H);
			y=min(b+xy,WIDTH-H-1);
			z=min(r+xy,(kd-1)*H-1);
			for(q=n;q<=z;q++){
				for(g=w;g<=y;g++){
					if(xy*xy>=(g-b)*(g-b)+(q-r)*(q-r)){
						n=parts[q*WIDTH+g];
						if(n>=0&&Parts_type[n]==SOAPY&&Parts_meta1[n]==0){
							Parts_meta1[n]=1;
							f++;
						}
					}
				}
			}
			f=min(max(5,f),Bubbles.MAX-Bubbles.used);
			if(f<5){
				return 0;
			}
			g=(floor(clamp(Parts_pos[part].x,8,407))>>2<<2)+2;
			q=(floor(clamp(Parts_pos[part].y,8,307))>>2<<2)+2;
			Qd++;
			for(b=0;b<f;b++){
				Bubbles.create(g+1.9*sincos[~~(512*b/f)][0],q+1.9*sincos[~~(512*b/f)][1]);
			}
			Qd++;
			remove(part);
			return 1;
		}
	break;case THUNDER:
		parts[xy]=part;
		Parts_vel[part].set(0,0)
		if(Parts_meta1[part]<0x1000){
			if(Parts_meta1[part]==0){
				Parts_meta1[part]=aircell%1000;
			}
			c=Parts_meta1[part]>>10;
			n=Parts_meta1[part]&0x3FF;
			n=73*n%955+44;
			var vx,vy
			if(c==0){
				f=n%3
				if(f==0){
					vx=-1;
					vy=0;
					c=1;
				}else if(f==1){
					vx=1;
					vy=0;
					c=3;
				}else{
					vx=0;
					vy=1;
					c=0;
				}
			}else if(c==1){
				if(n%2<=0){
					vx=-1;
					vy=0;
					c=1;
				}else{
					vx=0;
					vy=1;
					c=0;
				}
			}else{
				if(n%2<=0){
					vx=1;
					vy=0;
					c=3;
				}else{
					vx=0;
					vy=1;
					c=0;
				}
			}
			f=~~(Parts_pos[part].y+vy)*WIDTH+~~(Parts_pos[part].x+vx);
			b=c<<10|n;
			n=parts[f];
			if(n<=Parts_BGFAN){
				parts[xy]=Parts_EMPTY
				Parts_pos[part].x+=vx
				Parts_pos[part].y+=vy
				parts[f]=part
				Parts_meta1[part]=b
				Parts_pos2[part]=f;
			}else if(n>=0){
				if(Parts_type[n]!=THUNDER||Parts_meta1[n]!=b){
					if(Parts_type[n]==THUNDER){
						remove(part);
						return 1;
					//make sparks in metal and mercury
					}if(Parts_type[n]==METAL||Parts_type[n]==MERCURY){
						if(Parts_type[n]==METAL){
							Parts_meta1[n]=6000+c
						}else if(Parts_type[n]==MERCURY){
							Parts_meta1[n]=6100+c;
						}
						Parts_type[n]=THUNDER;
						remove(part);
						return 1;
					}
					//powders, liquids, magma, wood, ice, vine, glass
					if(states[Parts_type[n]]==State_POWDER||states[Parts_type[n]]==State_LIQUID||Parts_type[n]==MAGMA||Parts_type[n]==WOOD||Parts_type[n]==ICE||Parts_type[n]==VINE||Parts_type[n]==GLASS){
						Parts_meta1[part]=5000;
					//do part thing with cloud?
					}else if(Parts_type[n]==CLOUD){
						swap(part,n,xy,f);
					//otherwise just break it because whatever
					}else{
						remove(part);
						return 1;
					}
				}
			}else if(Parts_BGFAN<n){
				remove(part);
				return 1;
			}
		}else{
			//Air.vel forget
			if(Parts_meta1[part]==5000){
				xy=6;
				b=~~Parts_pos[part].x;
				r=~~Parts_pos[part].y;
				w=max(b-xy,H);
				n=max(r-xy,H);
				y=min(b+xy,WIDTH-H-1);
				z=min(r+xy,(kd-1)*H-1);
				for(q=n;q<=z;q++){
					for(g=w;g<=y;g++){
						f=(g-b)*(g-b)+(q-r)*(q-r)
						if(f<=xy*xy){
							f=q*WIDTH+g
							n=parts[f]
							if(n>=0&&Parts_type[n]!=THUNDER){
								if(Parts_type[n]==ICE){
									Parts_type[n]=SNOW;
								}else if(Parts_type[n]==FIREWORKS&&Parts_meta1[n]>0&&Parts_meta1[n]<5000){
									Parts_meta1[n]+=100;
								}
								Parts_vel[n].x-=3*(g-Parts_pos[part].x);
								Parts_vel[n].y-=3*(q-Parts_pos[part].y);
							}
						}
					}
				}
				remove(part);
				return 1;
			}
			//glass things
			if(Parts_meta1[part]>=7000){
				if(Parts_meta1[part]==7000){
					for(g=[WIDTH,-1,-WIDTH,1],b=0;b<4;b++){
						n=parts[xy+g[b]];
						//turn on glass
						if(n>=0&&Parts_type[n]==GLASS){
							Parts_type[n]=THUNDER;
							Parts_meta1[n]=7000;
						}
					}
				}
				Parts_meta1[part]++;
				//turn off glass
				if(Parts_meta1[part]>7020){
					Parts_type[part]=GLASS;
					Parts_meta1[part]=0;
				}
			//metal/mercury
			}else if(Parts_meta1[part]>=6000){
				c=Parts_meta1[part]&0b11;
				r=(Parts_meta1[part]&0xFFFC)==6000 ? METAL : MERCURY;
				g=[WIDTH,-1,-WIDTH,1];
				for(b=0;b<4;b++){
					if(b!=2){
						f=xy+g[c+b&3];
						n=parts[f];
						if(n>=0){
							if(Parts_type[n]==METAL||Parts_type[n]==MERCURY){
								swap(part,n,xy,f);
								if(Parts_type[n]==METAL){
									Parts_meta1[part]=6000+(c+b&0b11);
								}else if(Parts_type[n]==MERCURY){
									Parts_meta1[part]=6100+(c+b&0b11);
								}
								Parts_type[n]=r;
								Parts_meta1[n]=0;
								break;
							}else if(Parts_type[n]==THUNDER && Parts_meta1[n]>=6000 && Parts_meta1[n]<7000){
								Parts_type[part]=r;
								Parts_meta1[part]=0;
								break;
							}else if(Parts_type[n]==GLASS){
								Parts_type[n]=THUNDER;
								Parts_meta1[n]=7000;
							}
						}
					}
				}
				if(b==4){
					if(parts[xy+g[c]]<=Parts_BGFAN){
						g=~~Parts_pos[part].x
						q=~~Parts_pos[part].y
						if(c==0){
							Parts_create(g,q+1,THUNDER);
						}else if(c==1){
							Parts_create(g-1,q,THUNDER);
						}else if(c==2){
							Parts_create(g,q-1,THUNDER);
						}else if(c==3){
							Parts_create(g+1,q,THUNDER);
						}
					}
					Parts_type[part]=r;
					Parts_meta1[part]=0;
				}
			}
		}
	break;case METAL:
		parts[xy]=part
		Parts_vel[part].set(0,0)
		xy+=randomint(5)-2
		xy+=(randomint(5)-2)*WIDTH
		n=parts[xy]
		if(n>=0){
			switch(Parts_type[n]){
			//rust
			case WATER:
				if(random(100)<2){
					Parts_type[part]=Parts_POWDER;
				}
			//melt
			break;case MAGMA:
				if(random(100)<2){
					Parts_type[part]=MAGMA;
				}
			}
		}
	break;case BOMB:
		Parts_vel[part].y+=0.03;
		Parts_vel[part].mul(0.92);
		airvel.add(Parts_vel[part]);
		xy=Parts_blow(part,airvel);
		if(Parts_meta1[part]!=0){
			if(Parts_meta1[part]==BOMB){
				remove(part);
				return 1;
			}else if(random(100)>5){
				return 0;
			}else{
				switch(Parts_meta1[part]){
				case ICE:
					Parts_type[part]=SNOW;
					Parts_meta1[part]=0;
				break;case WOOD:case STONE:case VINE:
					Parts_type[part]=Parts_POWDER;
					Parts_meta1[part]=0;
				break;case NITRO:case TORCH:
					Parts_type[part]=FIRE;
					Parts_meta1[part]=1;
				break;case SOAPY:
					Parts_type[part]=STEAM;
					Parts_meta1[part]=0;
				break;case METAL:
					Parts_type[part]=METAL;
					Parts_meta1[part]=0;
				break;case GLASS:
					Parts_type[part]=STONE;
					Parts_meta1[part]=0;
				break;case PUMP:
					Parts_type[part]=SPARK;
					Parts_meta1[part]=0;
				break;default:
					remove(part);
					return 1;
				}
			}
			return 0;
		}
		f=xy+(randomint(3)-1);
		f+=(randomint(3)-1)*WIDTH;
		c=parts[f];
		if(c<0||Parts_type[c]==BOMB||Parts_type[c]==CLONE){
			return 0;
		}
		xy=4;
		b=~~Parts_pos[part].x;
		var g=~~Parts_pos[part].y,q=max(b-xy,H),n=max(g-xy,H),r=min(b+xy,WIDTH-H-1),w=min(g+xy,(kd-1)*H-1);
		airvel.set(0,0);
		for(var y=n;y<=w;y++){
			for(var z=q;z<=r;z++){
				if((z-b)*(z-b)+(y-g)*(y-g)<=xy*xy){
					f=y*WIDTH+z
					c=parts[f]
					if(c>=0&&Parts_type[c]!=BOMB){
						airvel.x+=Parts_pos[part].x-z;
						airvel.y+=Parts_pos[part].y-y;
					}
				}
			}
		}
		airvel.fastnormalize();
		for(y=n;y<=w;y++){
			for(z=q;z<=r;z++){
				if((z-b)*(z-b)+(y-g)*(y-g)<=xy*xy){
					f=y*WIDTH+z;
					c=parts[f];
					if(c>=0&&Parts_type[c]!=CLONE){
						Parts_vel[c].x+=airvel.x+1*(Parts_pos[part].x-z);
						Parts_vel[c].y+=airvel.y+1*(Parts_pos[part].y-y);
						if(Parts_type[c]!=BOMB||Parts_meta1[c]==0){
							Parts_pumpType[c]=0;
							Parts_meta1[c]=Parts_type[c];
							Parts_type[c]=BOMB;
						}
					}
				}
			}
		}
		remove(part);
		return 1;
	break;case LASER:
		parts[xy]=part;
		Parts_vel[part].set(0,0);
		v=Parts_meta1[part]&0xF; //...X
		yy=Parts_meta1[part]>>4&0xF; //..X.
		z=Parts_meta1[part]>>8&0xFF; //XX.. particle inside
		yy++;
		if(yy==1){
			Parts_meta1[part]=z<<8|yy<<4|v;
			return 0;
		}else if(yy>12){
			if(z==GLASS){
				Parts_type[part]=GLASS;
				Parts_meta1[part]=0;
			}else{
				remove(part);
			}
			return 1;
		}else if(yy>8){
			Parts_meta1[part]=z<<8|yy<<4|v;
			return 0;
		}else if(v==0){
			w=parts[xy+we[0]]
			if(w>=0&&Parts_type[w]==LASER){
				w=-1
			}
			c=parts[xy+we[1]]
			if(c>=0&&Parts_type[c]==LASER){
				c=-1
			}
			f=parts[xy+we[2]]
			if(f>=0&&Parts_type[f]==LASER){
				f=-1
			}
			b=parts[xy+we[3]]
			if(b>=0&&Parts_type[b]==LASER){
				b=-1
			}
			g=parts[xy+we[4]]
			if(g>=0&&Parts_type[g]==LASER){
				g=-1
			}
			q=parts[xy+we[5]]
			if(q>=0&&Parts_type[q]==LASER){
				q=-1
			}
			n=parts[xy+we[6]]
			if(n>=0&&Parts_type[n]==LASER){
				n=-1
			}
			r=parts[xy+we[7]]
			if(r>=0&&Parts_type[r]==LASER){
				r=-1
			}
			if(b>=0&&g>=0&&q>=0){
				v=1;
			}else if(q>=0&&n>=0&&r>=0){
				v=3;
			}else if(r>=0&&w>=0&&c>=0){
				v=5;
			}else if(c>=0&&f>=0&&b>=0){
				v=7;
			}else if(q>=0){
				v=2;
			}else if(r>=0){
				v=4;
			}else if(c>=0){
				v=6;
			}else if(b>=0){
				v=8;
			}else{
				Parts_meta1[part]=0xA0|v;
				return 0;
			}
		}
		v-=1;
		c=parts[xy+we[v]];
		if(c>=0){
			switch(Parts_type[c]){
			case LASER:
				for(b=2;b<=4;b++){
					c=parts[xy+we[v]*b]
					if(c>=0){
						if(Parts_type[c]!=LASER){
							break;
						}
					}else{
						if(c<=Parts_BGFAN){
							if(Parts_limits[Menu_dotLimit]-Parts_used<1000){
								break;
							}
							f=Parts_create(~~Parts_pos[part].x+ue[v]*b,~~Parts_pos[part].y+ve[v]*b,LASER);
							if(f>0){
								Parts_meta1[f]=v+1;
							}
						}
						break;
					}
				}
			break;case METAL:case MERCURY:
				c=parts[xy+we[v+1&7]];
				if(c>=0&&Parts_type[c]!=METAL&&Parts_type[c]!=MERCURY){
					c=-1;
				}
				f=parts[xy+we[v+2&7]];
				if(f>=0&&Parts_type[f]!=METAL&&Parts_type[f]!=MERCURY){
					f=-1
				}
				b=parts[xy+we[v+3&7]];
				if(b>=0&&Parts_type[b]!=METAL&&Parts_type[b]!=MERCURY){
					b=-1
				}
				g=parts[xy+we[v+4&7]];
				if(g>=0&&Parts_type[g]!=METAL&&Parts_type[g]!=MERCURY){
					g=-1
				}
				q=parts[xy+we[v+5&7]];
				if(q>=0&&Parts_type[q]!=METAL&&Parts_type[q]!=MERCURY){
					q=-1
				}
				n=parts[xy+we[v+6&7]];
				if(n>=0&&Parts_type[n]!=METAL&&Parts_type[n]!=MERCURY){
					n=-1
				}
				r=parts[xy+we[v+7&7]];
				if(r>=0&&Parts_type[r]!=METAL&&Parts_type[r]!=MERCURY){
					r=-1
				}
				w=parts[xy+we[v]+we[v+1&7]];
				if(w>=0&&Parts_type[w]!=METAL&&Parts_type[w]!=MERCURY){
					w=-1
				}
				var Y=parts[xy+we[v]+we[v+2&7]];
				if(Y>=0&&Parts_type[Y]!=METAL&&Parts_type[Y]!=MERCURY){
					Y=-1
				}
				var Ka=parts[xy+we[v]+we[v+3&7]];
				if(Ka>=0&&Parts_type[Ka]!=METAL&&Parts_type[Ka]!=MERCURY){
					Ka=-1
				}
				var ab=parts[xy+we[v]+we[v+5&7]];
				if(ab>=0&&Parts_type[ab]!=METAL&&Parts_type[ab]!=MERCURY){
					ab=-1
				}
				var La=parts[xy+we[v]+we[v+6&7]];
				if(La>=0&&Parts_type[La]!=METAL&&Parts_type[La]!=MERCURY){
					La=-1
				}
				var Ta=parts[xy+we[v]+we[v+7&7]];
				if(Ta>=0&&Parts_type[Ta]!=METAL&&Parts_type[Ta]!=MERCURY){
					Ta=-1
				}
				if((v&1)==0){
					if(q>=0&&n>=0&&c<0&&f<0){
						v=v+1&7;
					}else if(f>=0&&b>=0&&r<0&&n<0){
						v=v-1&7;
					}else if(c>=0&&n>=0&&f<0&&b<0&&q<0){
						v=v+3&7;
					}else if(w>=0&&La>=0&&Y<0&&Ka<0&&ab<0){
						v=v+3&7;
					}else if(f>=0&&r>=0&&b<0&&q<0&&n<0){
						v=v-3&7;
					}else if(Y>=0&&Ta>=0&&Ka<0&&ab<0&&La<0){
						v=v-3&7;
					}else if(n>=0&&c<0&&f<0&&q<0){
						v=v+2&7;
					}else if(f>=0&&b<0&&q<0&&n<0){
						v=v-2&7;
					}
				}else{
					var pa=parts[xy+we[v]+we[v+2&7]+we[v+3&7]];
					if(pa>=0&&Parts_type[pa]!=METAL&&Parts_type[pa]!=MERCURY){
						pa=-1
					}
					xy=parts[xy+we[v]+we[v+6&7]+we[v+5&7]];
					if(xy>=0&&Parts_type[xy]!=METAL&&Parts_type[xy]!=MERCURY){
						xy=-1
					}
					if(r>=0&&q>=0&&c<0&&g<0){
						v=v+1&7;
						}else if(c>=0&&b>=0&&g<0&&r<0){
							v=v-1&7;
						}else if(c>=0&&n>=0&&r>=0&&f<0&&q<0){
							v=v+3&7;
						}else if(w>=0&&La>=0&&Y<0&&Ka<0&&ab<0){
							v=v+3&7;
						}else if(Y>=0&&ab>=0&&Ka<0&&pa<0){
							v=v+3&7;
						}else if(c>=0&&f>=0&&r>=0&&b<0&&n<0){
							v=v-3&7;
						}else if(Y>=0&&Ta>=0&&Ka<0&&ab<0&&La<0){
							v=v-3&7;
						}else if(Ka>=0&&La>=0&&ab<0&&xy<0){
							v=v-3&7;
						}else if(r>=0&&c<0?v=v+2&7:c>=0&&r<0){
							v=v-2&7;
						}
				}
			break;case Parts_POWDER:case SEED:case WOOD:case SUPERBALL:case ANT:case VINE:
				Parts_type[c]=FIRE;
				Parts_meta1[c]=0;
			break;case WATER:case OIL:case SOAPY:case ACID:case SALTWATER:case CLOUD:
				Parts_type[c]=LASER;
				Parts_meta1[c]=v+1;
			break;case GLASS:
				Parts_type[c]=LASER;
				Parts_meta1[c]=GLASS<<8|v+1;
			}
		}else if(c<=Parts_BGFAN&&Parts_limits[Menu_dotLimit]-Parts_used>=1000){
			f=Parts_create(~~Parts_pos[part].x+ue[v],~~Parts_pos[part].y+ve[v],LASER);
			if(f>0){
				Parts_meta1[f]=v+1;
			}
		}
		Parts_meta1[part]=z<<8|yy<<4|v+1;
	break;case ACID:
		if(Parts_meta1[part]>=100){
			remove(part);
			return 1;
		}
		Parts_vel[part].x+=0.2*Air.vel[aircell].x;
		Parts_vel[part].y+=0.2*Air.vel[aircell].y;
		if(parts[xy+WIDTH]!=Parts_EMPTY){
			if(parts[xy-1]==Parts_EMPTY){
				Parts_vel[part].x-=random2(0,0.1)
			}
			if(parts[xy+1]==Parts_EMPTY){
				Parts_vel[part].x+=random2(0,0.1)
			}
		}
		Parts_vel[part].x+=random2(-0.01,0.01);
		Parts_vel[part].y+=random2(0.02,0.05);
		Parts_vel[part].mul(0.9);
		airvel.add(Parts_vel[part]);
		xy=Parts_blow(part,airvel);
		v=randomint(8);
		f=v<5?xy-WIDTH:v<6?xy-1:v<7?xy+1:xy+WIDTH;
		c=parts[f];
		if(c>=0){
			if(Parts_DISSOLVERATE[Parts_type[c]]!=0){
				if(random(200)<200-Parts_meta1[part]){
					Parts_meta1[part]=clamp(Parts_meta1[part]+Parts_DISSOLVERATE[Parts_type[c]],0,100);
					Parts_type[c]=ACID;
					Parts_meta1[c]=100;
				}
			}else if(Parts_type[c]==PUMP&&Parts_pumpType[c]==0){
				Parts_meta1[c]=4|(v<5?2:v<6?1:v<7?3:0);
				Parts_pumpType[c]=ACID;
				remove(part);
				return 1;
			}
		}
	break;case VINE:
		airvel.copy(Parts_vel[part]);
		Parts_vel[part].mul(0.3);
		xy=Parts_blow(part,airvel);
		//give up if near limit
		if(Parts_limits[Menu_dotLimit]-Parts_used<1000){
			return 0;
		}
		if(Parts_meta1[part]==0){
			z=~~Parts_pos[part].x+randomint(3)-1;
			y=~~Parts_pos[part].y-randomint(2);
			f=y*WIDTH+z;
			c=parts[f];
			if(c<=Parts_BGFAN){
				for(b=0;b<8;b++){
					c=parts[f+neighbors[b]]
					if(c>=0&&Parts_type[c]!=VINE&&Parts_type[c]!=ANT){
						if(random(100)<50){
							Parts_create(z,y,VINE);
						}
						break;
					}
				}
			}
			if(parts[xy+WIDTH]<=Parts_BGFAN&&parts[xy+2*WIDTH]<=Parts_BGFAN&&parts[xy+WIDTH-1]<=Parts_BGFAN&&parts[xy+WIDTH+1]<=Parts_BGFAN&&random(100)<8){
				f=Parts_create(~~Parts_pos[part].x,~~Parts_pos[part].y+1,VINE);
				if(f>0){
					Parts_meta1[f]=1;
				}
			}
				
		}else if(Parts_meta1[part]==1){
			if(parts[xy+WIDTH]<=Parts_BGFAN&&parts[xy+2*WIDTH]<=Parts_BGFAN&&parts[xy+WIDTH-1]<=Parts_BGFAN&&parts[xy+WIDTH+1]<=Parts_BGFAN&&random(100)<20){
				f=Parts_create(~~Parts_pos[part].x,~~Parts_pos[part].y+1,VINE);
				if(f>0){
					Parts_meta1[f]=1;
				}
			}
			if(random(100)<4){
				Parts_meta1[part]=2;
			}
		}
	break;case SALT:
		airvel.y+=random2(0.01,0.1);
		airvel.add(Parts_vel[part]);
		Parts_vel[part].mul(0.75);
		xy=Parts_blow(part,airvel);
		xy+=randomint(3)-1;
		xy+=(randomint(3)-1)*WIDTH;
		c=parts[xy];
		if(c>=0){
			//form saltwater
			if(Parts_type[c]==WATER){
				Parts_type[c]=SALTWATER;
				Parts_meta1[c]=0;
				remove(part);
				return 1;
			//destroyed by magma
			}else if(Parts_type[c]==MAGMA&&random(100)<50){
				remove(part);
				return 1;
			}
		}
	break;case SALTWATER:
		Parts_vel[part].x+=0.2*Air.vel[aircell].x;
		Parts_vel[part].y+=0.2*Air.vel[aircell].y;
		if(parts[xy+WIDTH]!=Parts_EMPTY){
			if(parts[xy-1]==Parts_EMPTY){
				Parts_vel[part].x-=random2(0.1,0.2)
			}
			if(parts[xy+1]==Parts_EMPTY){
				Parts_vel[part].x+=random2(0.1,0.2)
			}
		}
		Parts_vel[part].x+=random2(-0.01,0.01);
		Parts_vel[part].y+=random2(0.01,0.05);
		Parts_vel[part].mul(0.9);
		airvel.add(Parts_vel[part]);
		xy=Parts_blow(part,airvel);
		f=xy+(randomint(5)-2);
		f+=(randomint(5)-2)*WIDTH;
		c=parts[f];
		//dissolve seed/wood/metal
		if(c>=0&&(Parts_type[c]==SEED||Parts_type[c]==WOOD||Parts_type[c]==METAL)){
			Parts_type[c]=Parts_POWDER;
			Parts_meta1[c]=0;
		}
		v=randomint(8);
		f= v<5 ? xy-WIDTH : v<6 ? xy-1 : v<7 ? xy+1 : xy+WIDTH;
		c=parts[f];
		if(c>=0){
			if(v<7&&(states[Parts_type[c]]==State_POWDER&&Parts_type[c]!=STONE||Parts_type[c]==NITRO)){
				if(random(100)<10){
					swap(part,c,xy,f);
				}
			//kill vine
			}else if(Parts_type[c]==VINE){
				Parts_type[c]=Parts_POWDER;
				Parts_meta1[c]=0;
			//pump (why is this not handled by pump itself, I wonder...)
			}else if(Parts_type[c]==PUMP&&Parts_pumpType[c]==0){
				Parts_meta1[c]=4|(v<5?2:v<6?1:v<7?3:0);
				Parts_pumpType[c]=SALTWATER;
				remove(part);
				return 1;
			}
		}
	break;case GLASS:
		if(Parts_meta1[part]==0){
			if(Parts_vel[part].fastdist()>1){
				Parts_meta1[part]=1;
			}else{
				Parts_vel[part].set(0,0);
			}
		//breakystate, and the spreading of such things
		}else if(Parts_meta1[part]==1){
			airvel.copy(Parts_vel[part]);
			v=airvel.fastnormalize()*0.5;
			if(v<1){
				v=1;
			}
			for(b=1;b<6;b++){
				c=parts[~~(Parts_pos[part].y+0.5+airvel.y*b)*WIDTH+~~(Parts_pos[part].x+0.5+airvel.x*b)];
				if(c>=0&&Parts_type[c]==GLASS){
					Parts_meta1[c]=1;
					Parts_vel[c].x=0.98*Parts_vel[part].x;
					Parts_vel[c].y=0.98*Parts_vel[part].y;
				}else{
					break;
				}
			}
			for(b=0;b<4;b++){
				f=xy+neighbors[b];
				c=parts[f];
				if(c>=0&&Parts_type[c]==GLASS&&Parts_meta1[c]==0){
					Parts_meta1[c]=1;
					y=randomint(512);
					Parts_vel[c].x=sincos[y][0]*v;
					Parts_vel[c].y=sincos[y][1]*v;
				}
			}
			Parts_type[part]=STONE;
			Parts_meta1[part]=0;
		}
		parts[xy]=part;
	break;case BIRD:
		if(Parts_meta1[part]==0){
			Parts_meta1[part]=1;
			Parts_vel[part].x=random2(-1,1);
			Parts_vel[part].y=random2(-1,1);
		}else if(Parts_meta1[part]==2){
			if(random(100)<2){
				Parts_meta1[part]=1;
				Parts_vel[part].mul(-1);
			}else{
				parts[xy]=part;
				return 0;
			}
		}
		airvel.x+=0.5*Parts_vel[part].x;
		airvel.y+=0.5*Parts_vel[part].y;
		f=Parts_blow(part,airvel);
		if(xy==f){
			if(random(100)<50){
				Parts_vel[part].set(Parts_vel[part].y,-Parts_vel[part].x);
			}else{
				Parts_vel[part].set(-Parts_vel[part].y,Parts_vel[part].x);
			}
		}
		xy=f;
		f+=randomint(5)-2;
		v=randomint(5);
		f+=(v-2)*WIDTH;
		c=parts[f];
		if(c>=0){
			//GOSH WHAT DOES xe DO??
			if(v<3&&states[Parts_type[c]]==State_LIQUID){
				swap(part,c,xy,f);
			//eat seed and ant and... grow new birds? I guess
			}else if(Parts_type[c]==SEED||Parts_type[c]==ANT){
				Parts_type[c]=BIRD;
				Parts_vel[c].copy(Parts_vel[part]);
				Parts_meta1[c]=1;
				remove(part);
				return 1;
			//sit on wood
			}else if(Parts_type[c]==WOOD){
				Parts_meta1[part]=2;
			//burn
			}else if(states[Parts_type[c]]==State_HOT){
				Parts_type[part]=FIRE;
			}
		}
		xy=9;
		b=~~(Parts_pos[part].x+4*Parts_vel[part].x);
		g=~~(Parts_pos[part].y+4*Parts_vel[part].y);
		q=max(b-xy,H);
		n=max(g-xy,H);
		r=min(b+xy,WIDTH-H-1);
		w=min(g+xy,(kd-1)*H-1);
		airvel.set(0,0);
		La=ab=Ka=Y=0;
		for(y=n;y<=w;y++){
			for(f=y*WIDTH,z=q;z<=r;z++){
				if((z-b)*(z-b)+(y-g)*(y-g)<=xy*xy){
					c=parts[f+z];
					if(c>=0){
						if(Parts_type[c]==BIRD){
							airvel.x+=Parts_vel[c].x;
							airvel.y+=Parts_vel[c].y;
							Y++;
						}else if(Parts_type[c]!=SEED&&Parts_type[c]!=ANT&&Parts_type[c]!=WOOD){
							Ka+=z;
							ab+=y;
							La++;
						}
					}else if(Parts_BGFAN<c){
						Ka+=z;
						ab+=y;
						La++;
					}
				}
			}
		}
		if(Y>0){
			airvel.mul(1/Y);
		}
		Parts_vel[part].fastnormalize();
		Parts_vel[part].x=0.5*Parts_vel[part].x+0.5*airvel.x;
		Parts_vel[part].y=0.5*Parts_vel[part].y+0.5*airvel.y;
		Parts_vel[part].x+=random2(-0.1,0.1);
		Parts_vel[part].y+=random2(-0.1,0.1);
		if(La>0){
			Ka=~~(Ka/La)-Parts_pos[part].x;
			ab=~~(ab/La)-Parts_pos[part].y;
			if(Parts_vel[part].y*Ka-Parts_vel[part].x*ab<0){
				airvel.set(Parts_vel[part].y,-Parts_vel[part].x);
			}else{
				airvel.set(-Parts_vel[part].y,Parts_vel[part].x);
			}
			Parts_vel[part].x=0.9*Parts_vel[part].x+0.1*airvel.x;
			Parts_vel[part].y=0.9*Parts_vel[part].y+0.1*airvel.y;
		}
	break;case MERCURY:
		Parts_vel[part].x+=0.2*Air.vel[aircell].x;
		Parts_vel[part].y+=0.2*Air.vel[aircell].y;
		if(parts[xy+WIDTH]!=Parts_EMPTY){
			if(parts[xy-1]==Parts_EMPTY){
				Parts_vel[part].x-=random2(0.1,0.2);
			}
			if(parts[xy+1]==Parts_EMPTY){
				Parts_vel[part].x+=random2(0.1,0.2);
			}
		}
		Parts_vel[part].x+=random2(-0.01,0.01)
		Parts_vel[part].y+=random2(0.01,0.05)
		Parts_vel[part].mul(0.9)
		airvel.add(Parts_vel[part])
		xy=Parts_blow(part,airvel)
		v=randomint(8)
		f=v<1?xy-WIDTH:v<2?xy-1:v<3?xy+1:xy+WIDTH
		c=parts[f]
		if(c>=0){
			//powders and liquids (except mercury)
			if(v>0&&(states[Parts_type[c]]==State_POWDER||states[Parts_type[c]]==State_LIQUID&&Parts_type[c]!=MERCURY)){
				swap(part,c,xy,f);
			}else if(Parts_type[c]==PUMP&&Parts_pumpType[c]==0){
				Parts_meta1[c]=4|(v<1?2:v<2?1:v<3?3:0);
				Parts_pumpType[c]=MERCURY;
				remove(part);
				return 1;
			}
		}
	//sparkystream
	break;case SPARK:
		airvel.mul(0.05);
		Parts_vel[part].add(airvel);
		Parts_vel[part].y+=0.01;
		//right
		if(parts[xy+1]>=-3){
			Parts_vel[part].x-=random(0.5);
		}
		//left
		if(parts[xy-1]>=-3){
			Parts_vel[part].x+=random(0.5);
		}
		//down
		if(parts[xy+WIDTH]>=-3){
			Parts_vel[part].y-=random(0.5);
		}
		//up 2
		if(parts[xy+2*WIDTH]>=-3){
			Parts_vel[part].y-=random(0.5);
		}
		//up 1
		if(parts[xy-WIDTH]>=-3){
			Parts_vel[part].y+=random(0.5);
		}
		Parts_vel[part].mul(0.98);
		airvel.copy(Parts_vel[part]);
		xy=Parts_blow(part,airvel);
		xy+=randomint(5)-2;
		xy+=(randomint(5)-2)*WIDTH;
		var f=parts[xy-WIDTH];
		if(f>=0){
			switch(Parts_type[f]){
			//burn powder+ant
			case Parts_POWDER: case ANT:
				Parts_type[f]=FIRE;
				break;
			//killed by water/saltwater/soapy
			case WATER: case SALTWATER: case SOAPY:
				remove(part);
				return 1;
				break;
			//melt snow
			case SNOW:
				Parts_type[f]=WATER;
			}
		}
		//die randomly
		if(random(100)<15){
			remove(part);
			return 1;
		}
	//fuse
	break;case FUSE:
		airvel.set(0,0);
		xy=Parts_blow(part,airvel);
		//not burning
		if(Parts_meta1[part]<0x100){
			xy+=randomint(3)-1;
			xy+=(randomint(3)-1)*WIDTH;
			f=parts[xy];
			if(f>=0){
				//burn by hot elements except spark
				if(states[Parts_type[f]]==State_HOT&&Parts_type[f]!=SPARK){
					Parts_meta1[part]+=0x100;
				//dissolve by water+saltwater
				}else if(Parts_type[f]==WATER||Parts_type[f]==SALTWATER){
					Parts_type[part]=GUNPOWDER;
				}
			}
		//burning
		}else{
			Parts_meta1[part]+=0x100;
			if(Parts_meta1[part]>=0x300){
				var g;
				switch(Parts_meta1[part]&0xFF){
				case OIL:
					g=FIRE;
				break;case NITRO:
					g=NITRO;
				break;case SOAPY:
					g==STEAM;
				break;default:
					g=SPARK;
				}
				if(parts[xy+1]>=0){
					if(parts[xy-1]<=Parts_BGFAN){
						Parts_create(~~Parts_pos[part].x-1,~~Parts_pos[part].y,g);
					}
					if(parts[xy-1-WIDTH]<=Parts_BGFAN){
						Parts_create(~~Parts_pos[part].x-1,~~Parts_pos[part].y-1,g);
					}
					if(parts[xy-1+WIDTH]<=Parts_BGFAN){
						Parts_create(~~Parts_pos[part].x-1,~~Parts_pos[part].y+1,g);
					}
				}
				//the rest of these are basically the same, ok?
				0<=parts[xy-1]&&(parts[xy+1]<=Parts_BGFAN&&Parts_create(~~Parts_pos[part].x+1,~~Parts_pos[part].y,g),parts[xy+1-WIDTH]<=Parts_BGFAN&&Parts_create(~~Parts_pos[part].x+1,~~Parts_pos[part].y-1,g),parts[xy+1+WIDTH]<=Parts_BGFAN&&Parts_create(~~Parts_pos[part].x+1,~~Parts_pos[part].y+1,g));
				0<=parts[xy+WIDTH]&&(parts[xy-WIDTH]<=Parts_BGFAN&&Parts_create(~~Parts_pos[part].x,~~Parts_pos[part].y-1,g),parts[xy-1-WIDTH]<=Parts_BGFAN&&Parts_create(~~Parts_pos[part].x-1,~~Parts_pos[part].y-1,g),parts[xy+1-WIDTH]<=Parts_BGFAN&&Parts_create(~~Parts_pos[part].x+1,~~Parts_pos[part].y-1,g));
				0<=parts[xy-WIDTH]&&(parts[xy+WIDTH]<=Parts_BGFAN&&Parts_create(~~Parts_pos[part].x,~~Parts_pos[part].y+1,g),parts[xy-1+WIDTH]<=Parts_BGFAN&&Parts_create(~~Parts_pos[part].x-1,~~Parts_pos[part].y+1,g),parts[xy+1+WIDTH]<=Parts_BGFAN&&Parts_create(~~Parts_pos[part].x+1,~~Parts_pos[part].y+1,g));
				for(b=0;b<8;b++){
					c=xy+neighbors[b];
					f=parts[c];
					if(f>=0){
						//light fuse
						if(Parts_type[f]==FUSE&&Parts_meta1[f]<256){
							Parts_meta1[f]+=256;
						//light fireworks
						}else if(Parts_type[f]==FIREWORKS){
							Parts_vel[f].y-=50;
							Parts_meta1[f]+=100;
						//light oil c4 gas
						}else if(Parts_type[f]==OIL||Parts_type[f]==C4||Parts_type[f]==GAS){
							Parts_meta1[f]=1;
						//cause pressure wave to ignite nitro
						}else if(Parts_type[f]==NITRO){
							Parts_vel[f].y-=20;
						}
					}
				}
				Parts_type[part]=g;
				Parts_meta1[part]=0;
			}
		}
	//cloud
	break;case CLOUD:
		airvel.y+=random2(-0.01,-0.02);
		airvel.add(Parts_vel[part]);
		Parts_vel[part].mul(0.9);
		xy=Parts_blow(part,airvel);
		g=randomint(4);
		c= g<1 ? xy-WIDTH : g<2 ? xy-1 : g<3 ? xy+1 : xy+WIDTH;
		f=parts[c];
		if(f>=0){
			//mix with powders and liquids
			if(g<3&&(states[Parts_type[f]]==State_POWDER||states[Parts_type[f]]==State_LIQUID)){
				swap(part,f,xy,c);
			//diffuse from itself
			}else if(Parts_type[f]==CLOUD){
				Parts_vel[part].x+=random2(-0.1,0.1);
				Parts_vel[part].y+=random2(-0.1,0.1);
			//most solids->rain
			}else if(Parts_type[f]==WOOD||Parts_type[f]==C4||Parts_type[f]==TORCH||Parts_type[f]==VINE||Parts_type[f]==FUSE){
				Parts_type[part]=WATER;
			//ice->snow
			}else if(Parts_type[f]==ICE){
				Parts_type[part]=SNOW;
			//metal->thunder
			}else if(Parts_type[f]==METAL){
				Parts_type[part]=THUNDER;
			//pump
			}else if(Parts_type[f]==PUMP&&Parts_pumpType[f]==0){
				Parts_meta1[f]=0b100|(g<1 ? 0b10 : g<2 ? 0b01 : g<3 ? 0b11 : 0b00);
				Parts_pumpType[f]=WATER;
				remove(part);
				return 1;
			}
		//hit block
		}else if(f==-1){
			Parts_type[part]=WATER;
		}
	//pump
	break;case PUMP:
		airvel.set(0,0);
		xy=Parts_blow(part,airvel);
		if(Parts_pumpType[part]==0){
			return 0;
		}
		var pumpdirection=Parts_meta1[part]&0b11;
		var q=Parts_meta1[part]>>2;
		var n=[WIDTH,-1,-WIDTH,1];
		randomindex+=randomstep;
		randomindex&=0x3FF;
		var r=randomfloats[randomindex]<0.5?1:-1;
		for(b=0;b<4;b++){
			if(b!=2){
				c=xy+n[pumpdirection+b*r&3];
				f=parts[c];
				if(f>=0&&Parts_type[f]==PUMP){
					if(Parts_pumpType[f]==0){
						swap(part,f,xy,c);
						Parts_meta1[part]=q<<2|pumpdirection+b*r&3;
					}else if(Parts_pumpType[part]==Parts_pumpType[f]){
						pumpdirection=Parts_meta1[f]&0b11;
						q+=Parts_meta1[f]>>2;
						Parts_meta1[f]=q<<2|pumpdirection;
						Parts_meta1[part]=0;
						Parts_pumpType[part]=0;
					}else{
						Parts_meta1[part]=q<<2|pumpdirection+2&3;
					}
					break;
				}
			}
		}
		if(b==4){
			if(parts[xy+2*n[pumpdirection]]<=Parts_BGFAN&&Parts_limits[Menu_dotLimit]-Parts_used>=1000){
				xy=Parts_pos[part].x+0.5
				c=Parts_pos[part].y+0.5
				switch(pumpdirection){
				case 0:
					Parts_create(xy,c+2,Parts_pumpType[part])
				break;case 1:
					Parts_create(xy-2,c,Parts_pumpType[part])
				break;case 2:
					Parts_create(xy,c-2,Parts_pumpType[part])
				break;case 3:
					Parts_create(xy+2,c,Parts_pumpType[part])
				}
			}
			if(q<=1){
				Parts_meta1[part]=0;
				Parts_pumpType[part]=0;
			}else{
				Parts_meta1[part]=q-1<<2|pumpdirection;
			}
		}
	}
	return 0;
};


//bg hamdle
window.fff=yd.prototype.Parts_display;
yd.prototype.Parts_display=function(){
	var i;
	if(Menu_bgMode==Bg_LIGHT){
		for(i=0;i<Parts_used;i++){
			var color=colors[Parts_type[i]];
			if(Parts_type[i]==PUMP&&Parts_pumpType[i]!=0){
				color=colors[Parts_pumpType[i]];
			}
			var red=((color&0xFF0000)>>18)+(screenbuffer[Parts_pos2[i]]>>16&0xFF);
			if(red>0xFF){
				red=0xFF;
			}
			var green=((color&0x00FF00)>>10)+(screenbuffer[Parts_pos2[i]]>>8&0xFF);
			if(green>0xFF){
				green=0xFF;
			}
			var blue=((color&0x0000FF)>>2)+(screenbuffer[Parts_pos2[i]]&0xFF);
			if(blue>0xFF){
				blue=0xFF;
			}
			screenbuffer[Parts_pos2[i]]=red<<16|green<<8|blue
		}
	}else if(Menu_bgMode!=Bg_TOON){
		if(Menu_bgMode==Bg_GRAY){
			for(i=0;i<Parts_used;i++){
				var color=grays[Parts_type[i]];
				if(Parts_type[i]==PUMP&&Parts_pumpType[i]!=0){
					color=grays[Parts_pumpType[i]];
				}
				screenbuffer[Parts_pos2[i]]=color;
			}
		}else if(Menu_bgMode==Bg_SILUET){
			for(i=0;i<Parts_used;i++){
				var color=colors[Parts_type[i]];
				if(Parts_type[i]==PUMP&&Parts_pumpType[i]!=0){
					color=colors[Parts_pumpType[i]];
				}
				red=(screenbuffer[Parts_pos2[i]]>>16&0xFF)-(0xFF-(color>>16&0xFF)+10);
				if(red<0){
					red=0;
				}
				green=(screenbuffer[Parts_pos2[i]]>>8&0xFF)-(0xFF-(color>>8&0xFF)+10);
				if(green<0){
					green=0;
				}
				blue=(screenbuffer[Parts_pos2[i]]&0xFF)-(0xFF-(color&0xFF)+10);
				if(blue<0){
					blue=0;
				}
				screenbuffer[Parts_pos2[i]]=red<<16|green<<8|blue;
			}
		}else for(i=0;i<Parts_used;i++){
			var color=colors[Parts_type[i]];
			if(Parts_type[i]==PUMP&&Parts_pumpType[i]!=0){
				color=colors[Parts_pumpType[i]];
			}
			screenbuffer[Parts_pos2[i]]=color;
		}
	}
};
var wheelimage=new PGImage;
var Wheels={
	MAX:100
};
Wheels={
	MAX:Wheels.MAX,
	used:0,
	x:Array(Wheels.MAX),
	y:Array(Wheels.MAX),
	angle:Array(Wheels.MAX),
	vel:Array(Wheels.MAX),
	create:function(x,y){
		if(Wheels.used!=Wheels.MAX){
			Wheels.x[Wheels.used]=x;
			Wheels.y[Wheels.used]=y;
			Wheels.angle[Wheels.used]=0.5;
			Wheels.vel[Wheels.used]=0;
			Wheels.used++;
		}
	}
}

var Ge=Array(1024),He=Array(1024),Ie=Array(1024),Je=0;

window.fff=yd.prototype.Wheels_update;
//pretty sure wheel rotation etc. is handled here! (maybe?)
yd.prototype.Wheels_update=function(){
	var a,d,b,c,e,f,g,q=[0,0,1,4,-3,1,0,2,0,0,4,1,1,8,3,8,3,4,0,9,9,1,0,5,1,0,-1,4,100,9,0,10,0,0,6,1,1,5,8,0,0,20,1,4,-2,9];
	//drag wheel
	if(Menu_leftSelection==M_DRAG&&mouse.old.left||Menu_rightSelection==M_DRAG&&mouse.old.right){
		d=new Vector
		for(a=0;a<Wheels.used;a++){
			d.x=pen_x-Wheels.x[a];
			d.y=pen_y-Wheels.y[a];
			if(d.fastdist()<16){
				Wheels.vel[a]-=d.x*(pen_y-td)-d.y*(pen_x-sd);
			}
		}
	}
	for(a=0;a<Wheels.used;a++){
		d=(Wheels.y[a]-16)*WIDTH+(Wheels.x[a]-16);
		b=floor(Wheels.angle[a])*32*wheelimage.width;
		for(e=0;e<32;e++,d+=WIDTH-32){
			for(c=0;c<32;c++,d++,b++){
				if(wheelimage.imagedata[b]==0){
					f=(Wheels.y[a]+e-16>>2)*G+(Wheels.x[a]+c-16>>2);
					g=Air.vel[f].x*(e-15.5)-Air.vel[f].y*(c-15.5);
					Wheels.vel[a]+=0.0001*g;
				};
				f=parts[d];
				if(f>=0&&wheelimage.imagedata[b]==0x808080&&wheelimage.imagedata[b+wheelimage.width]==0&&e!=31){
					g=0*(e-15.5)-1*(c-15.5);
					Wheels.vel[a]+=g*q[Parts_type[f]]*0.0001;
				}
			}
		}
		Wheels.vel[a]*=0.99;
		Wheels.vel[a]=clamp(Wheels.vel[a],-2,2);
		g=floor(Wheels.angle[a]+16);
		Wheels.angle[a]+=Wheels.vel[a];
		g=floor(Wheels.angle[a]+16)-g;
		if(Wheels.angle[a]<0){
			Wheels.angle[a]+=16;
		}
		if(Wheels.angle[a]>=16){
			Wheels.angle[a]-=16;
		}
		if(g!=0){
			Je=0;
			d=(Wheels.y[a]-16)*WIDTH+(Wheels.x[a]-16);
			b=32*floor(Wheels.angle[a])*wheelimage.width;
			for(e=0;e<32;e++,d+=WIDTH-32){
				for(c=0;c<32;c++,d++,b++){
					if(wheelimage.imagedata[b]==0x808080){
						f=parts[d];
						if(f>=0){
							Ge[Je]=f;
							He[Je]=(e-15.5)*g*0.1;
							Ie[Je]=-(c-15.5)*g*0.1;
							Je++;
						}
					}
				}
			}
			for(d=0;d<Je;d++){
				parts[Parts_pos2[Ge[d]]]=Parts_EMPTY;
				f=floor(Parts_pos[Ge[d]].y)*WIDTH+floor(Parts_pos[Ge[d]].x+He[d]);
				if(parts[f]<-1){
					Parts_pos[Ge[d]].x+=He[d];
				}
				f=floor(Parts_pos[Ge[d]].y+Ie[d])*WIDTH+floor(Parts_pos[Ge[d]].x);
				if(parts[f]<-1){
					Parts_pos[Ge[d]].y+=Ie[d]
				}
				Parts_pos2[Ge[d]]=floor(Parts_pos[Ge[d]].y)*WIDTH+floor(Parts_pos[Ge[d]].x);
				parts[Parts_pos2[Ge[d]]]=Ge[d];
				//break wood into powder
				switch(Parts_type[Ge[d]]){
				case WOOD:
					if(random(100)<20){
						Parts_type[Ge[d]]=Parts_POWDER;
					}
				//break ice into snow
				break;case ICE:
					Parts_type[Ge[d]]=SNOW;
				//break fuse into gunpowder
				break;case FUSE:
					Parts_type[Ge[d]]=GUNPOWDER;
				//break pump into spark
				break;case PUMP:
					if(random(100)<10){
						Parts_type[Ge[d]]=SPARK;
						Parts_pumpType[Ge[d]]=0;
					}
				}
			}
		}
	}
};

window.fff=yd.prototype.Wheels_display;
yd.prototype.Wheels_display=function(){
	var color= Menu_bgMode==Bg_SILUET ? 0 : 0xB0A090;
	
	for(var i=0;i<Wheels.used;i++){
		var b=32*floor(Wheels.angle[i])*wheelimage.width;
		var xy=(Wheels.y[i]-16)*WIDTH+(Wheels.x[i]-16);
		for(var e=0;e<32;e++,xy+=WIDTH-32){
			for(var c=0;c<32;c++,xy++,b++){
				if(wheelimage.imagedata[b]==0){
					screenbuffer[xy]=color;
				}
			}
		}
	}
};

var Bubbles={
	MAX:2000
}
Bubbles={
	MAX:Bubbles.MAX,
	used:0,
	x:Array(Bubbles.MAX),
	y:Array(Bubbles.MAX),
	ke:Array(Bubbles.MAX),
	held:Array(Bubbles.MAX),
	create:function(x,y){
		if(Bubbles.used!=Bubbles.MAX){
			Bubbles.x[Bubbles.used]=x;
			Bubbles.y[Bubbles.used]=y;
			Bubbles.ke[Bubbles.used]=Qd;
			Bubbles.held[Bubbles.used]=false;
			Bubbles.used++;
		}
	}
}

var Qd,Rd,Sd;

function Bubblepull(bubble1,bubble2){
	var b=Rd,difference=new Vector;
	difference.x=Bubbles.x[bubble2]-Bubbles.x[bubble1];
	difference.y=Bubbles.y[bubble2]-Bubbles.y[bubble1];
	var distance=difference.fastnormalize();
	if(distance!=0){
		distance=b-distance;
		Bubbles.x[bubble1]-=difference.x*distance*0.5;
		Bubbles.y[bubble1]-=difference.y*distance*0.5;
		Bubbles.x[bubble2]+=difference.x*distance*0.5;
		Bubbles.y[bubble2]+=difference.y*distance*0.5;
	}
}

window.fff=yd.prototype.Bubbles_update;
yd.prototype.Bubbles_update=function(){
	var a,d,b=new Vector,c;
	for(a=0;a<Bubbles.used;a++){
		d=(floor(Bubbles.y[a])>>2)*G+(floor(Bubbles.x[a])>>2);
		b.copy(Air.vel[d]);
		b.mul(3.8/(b.fastdist()+1));
		Bubbles.x[a]+=b.x;
		Bubbles.y[a]+=b.y;
	}
	for(a=0;a<Bubbles.used;a++){
		if(!Bubbles.held[a]){
			if(Menu_leftSelection==M_DRAG&&mouse.rising.left||Menu_rightSelection==M_DRAG&&mouse.rising.right){
				b.x=pen_x-Bubbles.x[a];
				b.y=pen_y-Bubbles.y[a];
				if(b.fastdist()<10){
					Bubbles.held[a]=true;
				}
			}
		}else if(Menu_leftSelection==M_DRAG&&mouse.old.left||Menu_rightSelection==M_DRAG&&mouse.old.right){
			Bubbles.x[a]+=0.9*(pen_x-Bubbles.x[a]);
			Bubbles.y[a]+=0.9*(pen_y-Bubbles.y[a]);
		}else{
			Bubbles.held[a]=false;
		}
	}
	for(a=0;a<Bubbles.used-1;){
		c=Bubbles.ke[a];
		var e=0;
		for(d=a;d<Bubbles.used && Bubbles.ke[d]==c;d++,e++);
		b.set(0,0);
		for(d=a;d<a+e;d++){
			b.x+=Bubbles.x[d];
			b.y+=Bubbles.y[d];
		}
		d=b;
		c=e;
		d.x/=c;
		d.y/=c;
		for(d=a;d<a+e;d++){
			var f=new Vector;
			f.x=b.x-Bubbles.x[d];
			f.y=b.y-Bubbles.y[d];
			c=f.fastnormalize();
			if(c!=0){
				c=e*Sd-c;
				Bubbles.x[d]-=f.x*c*0.1;
				Bubbles.y[d]-=f.y*c*0.1;
			}
		}
		for(d=a;d<a+e-1;d++){
			Bubblepull(d,d+1);
		}
		Bubblepull(d,a);
		a+=e;
	}
	for(a=0;a<Bubbles.used;a++){
		d=0;
		if(Bubbles.x[a]>=0&&Bubbles.x[a]<WIDTH&&Bubbles.y[a]>=0&&Bubbles.y[a]<316){
			d=floor(Bubbles.y[a])*WIDTH+floor(Bubbles.x[a]);
			if(parts[d]<=Parts_BGFAN){
				continue;
			}
			if(parts[d]>=0 && Parts_type[parts[d]]==SOAPY){
				continue;
			}
		}
		c=Bubbles.ke[a];
		for(b=a;b>0&&c==Bubbles.ke[b-1];b--);
		for(e=b+1;e<Bubbles.used&&c==Bubbles.ke[e];e++);
		a=parts[d];a=a>=0?Parts_type[a]:STEAM;
		for(d=b;d<e-1;d++){
			Parts_line(Bubbles.x[d],Bubbles.y[d],Bubbles.x[d+1],Bubbles.y[d+1],a);
		}
		Parts_line(Bubbles.x[d],Bubbles.y[d],Bubbles.x[b],Bubbles.y[b],a);
		for(a=b-1;e<Bubbles.used;b++,e++){
			Bubbles.x[b]=Bubbles.x[e];
			Bubbles.y[b]=Bubbles.y[e];
			Bubbles.ke[b]=Bubbles.ke[e];
			Bubbles.held[b]=Bubbles.held[e];
		}
		Bubbles.used-=e-b;
	}
};
//random line drawing crap
function Parts_line(a,d,b,c,type){
	b-=a;
	c-=d;
	var f;
	if(abs(b)>=abs(c)){
		f=floor(abs(b));
		if(b!=0){
			c/=abs(b);
		}
		b= b>=0 ? 1 : -1;
	}else{
		f=floor(abs(c));
		if(c!=0){
			b/=abs(c);
		}
		c= c>=0 ? 1 : -1;
	}
	a+=0.5;
	d+=0.5;
	for(var g=0;g<=f;g++,a+=b,d+=c){
		if(onscreen(a,d)&&parts[floor(d)*WIDTH+floor(a)]<=Parts_BGFAN){
			Parts_create(floor(a),floor(d),type);
		}
	}
}

window.fff=yd.prototype.Bubbles_display;
yd.prototype.Bubbles_display=function(){
	var i,soapcolors=[0xFFE0E0,0xFFF0E0,0xFFFFE0,0xE0FFE0,0xE0FFFF,0xE0F0FF,0xE0E0FF,0xFFE0FF];
	if(Menu_bgMode==Bg_SILUET){
		soapcolors=[0,0,0,0,0,0,0,0];
	}
	var soapcolorindex=0;
	for(i=0;i<Bubbles.used-1;i++){
		var c=i;
		for(var e=Bubbles.ke[i];i<Bubbles.used-1&&e==Bubbles.ke[i+1];i++){
			line(Bubbles.x[i],Bubbles.y[i],Bubbles.x[i+1],Bubbles.y[i+1],soapcolors[soapcolorindex]);
			soapcolorindex++;
			soapcolorindex&=7;
		}
		line(Bubbles.x[i],Bubbles.y[i],Bubbles.x[c],Bubbles.y[c],soapcolors[soapcolorindex]);
		soapcolorindex++;
		soapcolorindex&=7;
	}
};

var Entities={
	MAX:50,
	PARTS:28
}
Entities={
	MAX:Entities.MAX,
	PARTS:Entities.PARTS,
	type:Array(Entities.MAX),
	meta2:Array(Entities.MAX),
	meta1:Array(Entities.MAX),
	pos:Array(Entities.MAX*Entities.PARTS),
	used:0,
	held:Array(Entities.MAX),
	create:function(x,y,type,meta2){
		if(Entities.used!=Entities.MAX){
			var e,f,totalplayers=0,q=0,n=0;
			if(type==30||type==32){
				for(e=0;e<Entities.used;e++){
					if(Entities.type[e]==Entities_PLAYER){
						totalplayers++;
						q=1-Entities.meta1[e];
						n=e;
					}
				}
				if(totalplayers>=2||meta2!=0&&playervalidelements[meta2]==0){
					return;
				}
			}
			f=Entities.used*Entities.PARTS;
			for(e=0;e<20;e++){
				Entities.pos[f+e].set(x+random(4),y+random(4))
				Entities_oldpos[f+e].copy(Entities.pos[f+e]);
			}
			for(e=0;e<Entities.PARTS;e++){
				Entities_Ud[f+e]=0;
			}
			Entities_Pe[Entities.used].set(0,0);
			Entities.type[Entities.used]=Entities_FIGHTER;
			Entities_decay[Entities.used]=0;
			Entities.held[Entities.used]=0;
			Entities.meta2[Entities.used]=meta2;
			Entities.meta1[Entities.used]=0;
			if(type==22){
				if(meta2==10){
					Entities.type[Entities.used]=Entities_CREATE;
					Entities.meta2[Entities.used]=0;
					Entities.pos[f+0].set(x,y);
					Entities_oldpos[f+0].copy(Entities.pos[f+0]);
				}else{
					Entities.type[Entities.used]=Entities_BOX;
				}
			}else if(type==30){
				Entities.type[Entities.used]=Entities_PLAYER;
				Entities.meta1[Entities.used]=q;
			}else if(type==32){
				Entities.type[Entities.used]=Entities_PLAYER;
				if(totalplayers==0){
					Entities.meta1[Entities.used]=0;
				}else{
					var b=floor(Entities.pos[n*Entities.PARTS].x)>>2<<2;
					var c=floor(Entities.pos[n*Entities.PARTS].y)>>2<<2;
					if(x<b){
						Entities.meta1[Entities.used]=1;
						Entities.meta1[n]=0;
					}else if(x>b){
						Entities.meta1[Entities.used]=0;
						Entities.meta1[n]=1;
					}else if(y<c){
						Entities.meta1[Entities.used]=1;
						Entities.meta1[n]=0;
					}else{
						Entities.meta1[Entities.used]=0;
						Entities.meta1[n]=1;
					}
				}
			}
			Entities.used++;
		}
	}
}

var Entities_oldpos=Array(Entities.MAX*Entities.PARTS),Entities_Ud=Array(Entities.MAX*Entities.PARTS);
var Entities_Pe=Array(Entities.MAX),Entities_decay=Array(Entities.MAX);
for(Entities.used=0;Entities.used<Entities.MAX*Entities.PARTS;Entities.used++){
	Entities.pos[Entities.used]=new Vector;
}
for(Entities.used=0;Entities.used<Entities.MAX*Entities.PARTS;Entities.used++){
	Entities_oldpos[Entities.used]=new Vector;
}
for(Entities.used=0;Entities.used<Entities.MAX;Entities.used++){
	Entities_Pe[Entities.used]=new Vector;
}

//kill?
function Entities_remove(entity){
	if(Entities.used!=0){
		var i,b,c;
		b=entity*Entities.PARTS;
		c=(Entities.used-1)*Entities.PARTS;
		//clear partlist
		for(i=0;i<Entities.PARTS;i++,b++,c++){
			Entities.pos[b].copy(Entities.pos[c]);
			Entities_oldpos[b].copy(Entities_oldpos[c]);
			Entities_Ud[b]=Entities_Ud[c];
		}
		Entities_Pe[entity].copy(Entities_Pe[Entities.used-1]);
		Entities.type[entity]=Entities.type[Entities.used-1];
		Entities_decay[entity]=Entities_decay[Entities.used-1];
		Entities.held[entity]=Entities.held[Entities.used-1];
		Entities.meta2[entity]=Entities.meta2[Entities.used-1];
		Entities.meta1[entity]=Entities.meta1[Entities.used-1];
		Entities.used--;
	}
}
function Entities_Re(entity,gravity,slowdown){
	var movement=new Vector;
	movement.sub2(Entities.pos[entity],Entities_oldpos[entity]);
	Entities_oldpos[entity].copy(Entities.pos[entity]);
	movement.y+=gravity;
	movement.mul(slowdown);
	Entities.pos[entity].add(movement);
}
function Entities_Se(a,d,b,c,e){
	var f=new Vector;
	f.sub2(Entities.pos[d],Entities.pos[a]);
	var g=f.fastnormalize();
	if(g!=0){
		b-=g;
		g=new Vector;
		g.mul2(f,b*c);
		Entities.pos[a].sub(g);
		g.mul2(f,b*e);
		Entities.pos[d].add(g);
	}
}
var Te=[0,0.5,0.5,0.8,1,0.5,0.5,0.5,1,0.5,1,0.5,1,0.5,0.5,0.5,0.8,0.5,0,0.5,0.5,0.5,0,0.8,0.5,0,1,1,0,0.5,0,0.5,0,0,0.8,0.5,0.5,0.8,0.9,0.1,0,1,0.5,0.5,1,0.5]
function Entities_Ue(entity,d,b,c){
	var e=new Vector;
	e.sub2(Entities.pos[entity],Entities_oldpos[entity]);
	Entities.pos[entity].copy(Entities_oldpos[entity]);
	if(d!=0){
		var f=(floor(Entities.pos[entity].y)>>2)*G+(floor(Entities.pos[entity].x)>>2);
		e.x+=Air.vel[f].x*d;
		e.y+=Air.vel[f].y*d;
	}
	if(c==0){
		f=e.fastdist()+1
		if(f>=8){
			e.mul(3.8/f);
			d=2;
		}else if(f>=4){
			e.mul(0.5);
			d=2;
		}else{
			d=1;
		}
	}else{
		d=floor(e.fastdist()/3)+1;
		e.mul(1/d);
	}
	Entities_Ud[entity]=0;
	if(b==1){
		e.mul(d);
		Entities.pos[entity].add(e);
		Entities.pos[entity].x=clamp(Entities.pos[entity].x,4,WIDTH-5);
		Entities.pos[entity].y=clamp(Entities.pos[entity].y,4,311);
	}else{
		for(c=0;c<d;c++){
			b=Entities.pos[entity].y+e.y;
			if(b<4||b>=312){
				Entities_Ud[entity]=-5;
				break;
			}
			f=floor(b)*WIDTH+floor(Entities.pos[entity].x);
			if(parts[f]<=Parts_BGFAN){
				Entities.pos[entity].y=b;
			}else if(parts[f]<=-1){
				e.x*=0.5;
				e.y=-e.y;
				Entities_Ud[entity]=parts[f];
			}else{
				e.x*=Te[Parts_type[parts[f]]]
				Entities_Ud[entity]=Parts_type[parts[f]]
				if(e.y<0){
					Entities.pos[entity].y=b;
				}else if(states[Parts_type[parts[f]]]==State_LIQUID&&Parts_type[parts[f]]!=MERCURY){
					Entities.pos[entity].y=b;
				}else{
					e.y=-e.y;
				}
			}
			b=Entities.pos[entity].x+e.x;
			if(b<4||b>=WIDTH-4){
				Entities_Ud[entity]=-5;
				break;
			}
			f=floor(Entities.pos[entity].y)*WIDTH+floor(b);
			if(parts[f]<=Parts_BGFAN){
				Entities.pos[entity].x=b;
			}else if(parts[f]<=-1){
				e.y*=0.5;
				e.x=-e.x;
				Entities_Ud[entity]=parts[f];
			}else{
				e.y*=Te[Parts_type[parts[f]]];
				e.x=-e.x;
				Entities_Ud[entity]=Parts_type[parts[f]];
				if(states[Parts_type[parts[f]]]==State_LIQUID||Parts_type[parts[f]]==WOOD){
					Entities.pos[entity].x=b;
				}
			}
		}
	}
}
function Entities_hurt(start,end){
	var b=0;
	for(var i=start;i<end;i++){
		if(Entities_Ud[i]==-5){
			return -5;
		}else if(Entities_Ud[i]<0){
			b=1;
		}else if(states[Entities_Ud[i]]==State_HOT){
			return 3;
		}else if(Entities_Ud[i]==ACID){
			return -5;
		}else if(Entities_Ud[i]!=0){
			b=1;
		}
	}
	return b;
}
function Entities_drag(entity,d,b){
	var c,e=new Vector,f,g;
	if(Entities.held[entity]==0){
		if(M_DRAG==Menu_leftSelection&&mouse.rising.left||M_DRAG==Menu_rightSelection&&mouse.rising.right){
			for(f=20,c=d;c<b;c++){
				e.x=pen_x-Entities_oldpos[c].x;
				e.y=pen_y-Entities_oldpos[c].y;
				g=e.fastdist();
				if(g<20&&g<f){
					f=g;
					Entities.held[entity]=c-d+1;
				}
			}
		}
	}else if(M_DRAG==Menu_leftSelection&&mouse.old.left||M_DRAG==Menu_rightSelection&&mouse.old.right){
		Entities.pos[d+Entities.held[entity]-1].x+=0.2*(pen_x-Entities.pos[d+Entities.held[entity]-1].x);
		Entities.pos[d+Entities.held[entity]-1].y+=0.2*(pen_y-Entities.pos[d+Entities.held[entity]-1].y);
	}else{
		Entities.held[entity]=0;
	}
}

var Xe=[0,0],Ye=[0,0],playerfacingdirection=[0,0];
//player movement!
window.fff=yd.prototype.Entities_update;
yd.prototype.Entities_update=function(){
	for(var a=0;a<Entities.used;a++){
		var d=a,b,e=new Vector,c=d*Entities.PARTS;
		if(Entities.type[d]==Entities_PLAYER){
			var f,g;
			var left=Entities.meta1[d]==0?Keys.pressed[37]:Keys.pressed[65]|Keys.pressed[97];
			var right=Entities.meta1[d]==0?Keys.pressed[39]:Keys.pressed[68]|Keys.pressed[100];
			var up=Entities.meta1[d]==0?Keys.pressed[38]:Keys.pressed[87]|Keys.pressed[119];
			var down=Entities.meta1[d]==0?Keys.pressed[40]:Keys.pressed[83]|Keys.pressed[115];
			var isplayer2=Entities.meta1[d]==0?0:1;
			Entities_decay[d]++;
			var w=parts[(floor(Entities_oldpos[c+4].y)+1)*WIDTH+floor(Entities_oldpos[c+4].x)]>Parts_BGFAN?1:0;
			var y=parts[(floor(Entities_oldpos[c+5].y)+1)*WIDTH+floor(Entities_oldpos[c+5].x)]>Parts_BGFAN?1:0;
			if(w==0){
				w=parts[floor(Entities_oldpos[c+4].y)*WIDTH+floor(Entities_oldpos[c+4].x)]>Parts_BGFAN?1:0;
			}
			if(y==0){
				y=parts[floor(Entities_oldpos[c+5].y)*WIDTH+floor(Entities_oldpos[c+5].x)]>Parts_BGFAN?1:0;
			}
[			//high jumping
			if(down&&Entities.meta2[d]==BIRD){
				for(b=0;b<6;b++){
					Entities_Re(c+b,0.01,0.997);
				}
			//normal jumped?
			}else{
				Entities_Re(c+0,-0.2,0.995);
				Entities_Re(c+1,-0.1,0.995);
				Entities_Re(c+2,0,0.995);
				Entities_Re(c+3,0,0.995);
				Entities_Re(c+4,0.3,0.995);
				Entities_Re(c+5,0.3,0.995);
			}
			Entities.pos[c].add(Entities_Pe[d]);
			Entities_Pe[d].mul(0.5);
			if(Entities_Pe[d].x!=0){
				Entities.type[d]=Entities_PLAYER+2;
			}
			if(Xe[isplayer2]>0){
				Xe[isplayer2]--;
			}
			if(Xe[isplayer2]!=0||w!=1&&y!=1){
				if(right){
					if(Entities.pos[c+1].x-Entities_oldpos[c+1].x<0){
						Entities.pos[c+1].x+=0.1;
					}
					playerfacingdirection[isplayer2]=1;
				}else if(left){
					if(Entities.pos[c+1].x-Entities_oldpos[c+1].x>0){
						Entities.pos[c+1].x-=0.1;
					}
					playerfacingdirection[isplayer2]=0;
				}
			}else{
				b=0.8;
				if(right){
					Xe[isplayer2]=15;
					if(Entities.pos[c+4].x<Entities.pos[c+5].x){
						Entities.pos[c+2].x+=4*b;
						Entities.pos[c+2].y-=3*b;
					}else{
						Entities.pos[c+3].x+=4*b;
						Entities.pos[c+3].y-=3*b;
					}
					playerfacingdirection[isplayer2]=1;
				}else if(left){
					Xe[isplayer2]=15;
					if(Entities.pos[c+4].x>Entities.pos[c+5].x){
						Entities.pos[c+2].x-=4*b;
						Entities.pos[c+2].y-=3*b;
					}else{
						Entities.pos[c+3].x-=4*b;
						Entities.pos[c+3].y-=3*b;
					}
					playerfacingdirection[isplayer2]=0;
				}
			}
			if(Ye[isplayer2]>1){
				Ye[isplayer2]--;
			}
			if(Ye[isplayer2]>0&&(w==1||y==1)){
				Ye[isplayer2]--;
			}
			if(Ye[isplayer2]==0&&up){
				Ye[isplayer2]=50;
				Entities.pos[c+4].y-=6;
				Entities.pos[c+5].y-=6;
			}
			b=0.5;
			Entities_Se(c+0,c+1,4,b,b);
			Entities_Se(c+1,c+2,4,b,b);
			Entities_Se(c+1,c+3,4,b,b);
			Entities_Se(c+2,c+4,5,b,b);
			Entities_Se(c+3,c+5,5,b,b);
			Entities_Se(c+2,c+3,5,0.1,0.1);
			w=0.1;
			for(b=0;b<4;b++){
				Entities_Ue(c+b,w,1,Entities.held[d]>0?1:0);
			}
			for(b=4;b<6;b++){
				Entities_Ue(c+b,w,0,Entities.held[d]>0?1:0);
			}
			//player get element
			for(var y=0;y<3;y++){
				for(var x=-1;x<2;x++){
					var part=parts[(floor(Entities_oldpos[c+0].y)+y)*WIDTH+(floor(Entities_oldpos[c+0].x)+x)];
					if(part==Parts_BGFAN){
						Entities.meta2[d]=FAN;
					}else if(part>=0 && playervalidelements[Parts_type[part]]==1){
						Entities.meta2[d]=Parts_type[part];
					}
				}
			}
			//shoot
			if(!(up&&(left||right))&&down&&Entities.meta2[d]!=0){
				w=floor(Entities.pos[c+0].x);
				b=floor(Entities.pos[c+0].y)+1;
				if(Entities.meta2[d]==NITRO){
					w+=playerfacingdirection[isplayer2]==0?8:-8;
					b+=12;
				}
				w=clamp(w,8,407);
				b=clamp(b,8,307);
				if(Entities.meta2[d]==FAN){
					f=(b>>2)*G+(w>>2);
					if(blocks[f]==0){
						Air.vel[f].x+=playerfacingdirection[isplayer2]==0?-1:1;
					}
				}else if(Entities.meta2[d]!=BIRD&&parts[b*WIDTH+w]==Parts_EMPTY){
					f=Parts_create(w,b,Entities.meta2[d]);
					if(f>=0){
						if(playerfacingdirection[isplayer2]==0){
							Parts_vel[f].x-=20;
						}else if(playerfacingdirection[isplayer2]==1){
							Parts_vel[f].x+=20;
						}
						Parts_vel[f].y+=random(3)-1;
						switch(Entities.meta2[d]){
						case FIRE:
							Parts_vel[f].x*=3;
							Parts_vel[f].y+=18;
							Parts_meta1[f]=2;
						break;case SUPERBALL:
							Parts_vel[f].y=20;
						break;case STONE:
							Parts_vel[f].x*=0.1;
							Parts_vel[f].y*=0.1;
						break;case LASER:
							Parts_meta1[f]=playerfacingdirection[isplayer2]==0?5:1;
						}
					}
				}
			}
			//die
			if(Entities_hurt(c,c+6)==3||Entities_hurt(c,c+6)==-5){
				Entities.type[d]=Entities_PLAYER+2;
			}
			//edge wrap
			if(Menu_edgeMode==1){
				for(r=4;r<=5;r++){
					w=b=0;
					if(Entities.pos[c+r].x<8){
						w=406;
						b=floor(Entities_oldpos[c+r].y);
					}else if(Entities.pos[c+r].x>=WIDTH-8){
						w=10;
						b=floor(Entities_oldpos[c+r].y);
					}
					if(w+b!=0){
						Entities.type[d]=Entities_PLAYER;f=b*WIDTH+w;
						if(parts[f]>Parts_BGFAN){
							if(parts[f]<=-1){
								Entities.pos[c+r].copy(Entities_oldpos[c+r]);
								continue;
							}else if(states[Parts_type[parts[f]]]!=State_LIQUID){
								Entities.pos[c+r].copy(Entities_oldpos[c+r]);
								continue;
							}
						}
						e.sub2(Entities.pos[c+r],Entities_oldpos[c+r]);
						e.fastnormalize();
						for(d=0;d<=10;d++){
							Entities.pos[c+d].x=w+e.x+random2(-0.1,0.1);
							Entities.pos[c+d].y=b+e.y+random2(-0.1,0.1);
							Entities_oldpos[c+d].set(w,b);
						}
						break;
					}
				}
			}
		//dead player
		}else if(Entities.type[d]==Entities_PLAYER+2){
			Entities.pos[c+10].copy(Entities.pos[c+5]);
			Entities_oldpos[c+10].copy(Entities_oldpos[c+5]);
			Entities.pos[c+9].copy(Entities.pos[c+4]);
			Entities_oldpos[c+9].copy(Entities_oldpos[c+4]);
			Entities.pos[c+8].copy(Entities.pos[c+3]);
			Entities_oldpos[c+8].copy(Entities_oldpos[c+3]);
			Entities.pos[c+7].copy(Entities.pos[c+3]);
			Entities_oldpos[c+7].copy(Entities_oldpos[c+3]);
			Entities.pos[c+6].copy(Entities.pos[c+2]);
			Entities_oldpos[c+6].copy(Entities_oldpos[c+2]);
			Entities.pos[c+5].copy(Entities.pos[c+2]);
			Entities_oldpos[c+5].copy(Entities_oldpos[c+2]);
			Entities.pos[c+4].copy(Entities.pos[c+1]);
			Entities_oldpos[c+4].copy(Entities_oldpos[c+1]);
			Entities.pos[c+3].copy(Entities.pos[c+1]);
			Entities_oldpos[c+3].copy(Entities_oldpos[c+1]);
			Entities.pos[c+2].copy(Entities.pos[c+1]);
			Entities_oldpos[c+2].copy(Entities_oldpos[c+1]);
			Entities.pos[c+1].copy(Entities.pos[c+0]);
			Entities_oldpos[c+1].copy(Entities_oldpos[c+0]);
			Entities.pos[c+0].copy(Entities.pos[c+0]);
			Entities_oldpos[c+0].copy(Entities_oldpos[c+0]);
			Entities_Pe[d].y-=1;
			Entities_decay[d]=0;
			Entities.type[d]=Entities_PLAYER+3;
		//even deader
		}else if(Entities.type[d]==Entities_PLAYER+3){
			Entities_decay[d]++;
			for(b=0;b<11;b++){
				Entities_Re(c+b,0.1,0.999);
				Entities.pos[c+b].add(Entities_Pe[d]);
			}
			Entities_Pe[d].mul(0.5);
			b=0.5;
			e=(150-Entities_decay[d])/150;
			Entities_Se(c+1,c+2,4*e,b,b);
			Entities_Se(c+3,c+5,4*e,b,b);
			Entities_Se(c+4,c+7,4*e,b,b);
			Entities_Se(c+6,c+9,5*e,b,b);
			Entities_Se(c+8,c+10,5*e,b,b);
			w=0.1;
			for(b=0;b<11;b++){
				Entities_Ue(c+b,w,0,0);
			}
			if(Entities_decay[d]>150){
				Entities_remove(d--);
			}
		}else if(Entities.type[d]==Entities_FIGHTER||Entities.type[d]==Entities_FIGHTER+1){
			Entities_decay[d]++;
			if(Entities.type[d]==Entities_FIGHTER){
				Entities_Re(c+0,-0.2,0.995);
				Entities_Re(c+1,-0.1,0.995);
				Entities_Re(c+2,0,0.995);
				Entities_Re(c+3,0,0.995);
				Entities_Re(c+4,0.3,0.995);
				Entities_Re(c+5,0.3,0.995);
			}else{
				Entities_Re(c+0,0.1,0.995);
				Entities_Re(c+1,0.1,0.995);
				Entities_Re(c+2,0.1,0.995);
				Entities_Re(c+3,0.1,0.995);
				Entities_Re(c+4,0.1,0.995);
				Entities_Re(c+5,0.1,0.995);
			}
			Entities_drag(d,c,c+6);
			Entities.pos[c].add(Entities_Pe[d]);
			Entities_Pe[d].mul(0.5);
			if(Entities.type[d]==Entities_FIGHTER){
				if(Entities_Ud[c+4]!=0&&Entities_Ud[c+5]!=0){
					r=floor(random(100));
					if(r<5){
						if(Entities.pos[c+4].x<Entities.pos[c+5].x){
							Entities.pos[c+4].x+=4;
							Entities.pos[c+4].y-=4;
						}else{
							Entities.pos[c+5].x+=4;
							Entities.pos[c+5].y-=4;
						}
					}else if(r<10){
						if(Entities.pos[c+4].x>Entities.pos[c+5].x){
							Entities.pos[c+4].x-=4;
							Entities.pos[c+4].y-=4;
						}else{
							Entities.pos[c+5].x-=4;
							Entities.pos[c+5].y-=4;
						}
					}
				}else{
					if(Entities_Ud[c+4]!=0){
						if(random(100)<2){
							Entities.pos[c+4].x+=random2(-4,4);
							Entities.pos[c+4].y-=4;
						}
					}else if(Entities_Ud[c+5]!=0&&random(100)<2){
						Entities.pos[c+5].x+=random2(-4,4);
						Entities.pos[c+5].y-=4;
					}
				}
				for(r=undefined,r=0;r<Entities.used;r++){
					if(d!=r&&(Entities.type[r]==Entities_FIGHTER||Entities.type[r]==Entities_FIGHTER+1||Entities.type[r]==Entities_PLAYER)){
						f=r*Entities.PARTS;
						g=abs(Entities.pos[c+4].x-Entities.pos[f].x);
						q=Entities.pos[c+4].y-Entities.pos[f].y;
						if(g<=2&&q>=0&&q<=6){
							Entities_Pe[r].x+=1*(Entities.pos[c+4].x-Entities_oldpos[c+4].x);
							Entities_Pe[r].y+=2*(Entities.pos[c+4].y-Entities_oldpos[c+4].y);
							if(Entities.type[r]==Entities_FIGHTER){
								Entities.type[r]=Entities_FIGHTER+1;
							}
							Entities_decay[r]=0;
						}
						g=abs(Entities.pos[c+5].x-Entities.pos[f].x);
						q=Entities.pos[c+5].y-Entities.pos[f].y;
						if(g<=2&&q<=0&&q<=6){
							Entities_Pe[r].x+=1*(Entities.pos[c+5].x-Entities_oldpos[c+5].x);
							Entities_Pe[r].y+=2*(Entities.pos[c+5].y-Entities_oldpos[c+5].y);
							if(Entities.type[r]==Entities_FIGHTER){
								Entities.type[r]=Entities_FIGHTER+1;
							}
							Entities_decay[r]=0;
						}
					}
				}
			}else if(Entities_decay[d]>10&&(Entities_Ud[c+4]!=0||Entities_Ud[c+5]!=0)&&random(100)<10){
				Entities.type[d]=Entities_FIGHTER;
				Entities_decay[d]=0;
			}
			b=0.5;
			Entities_Se(c+0,c+1,4,b,b);
			Entities_Se(c+1,c+2,4,b,b);
			Entities_Se(c+1,c+3,4,b,b);
			Entities_Se(c+2,c+4,5,b,b);
			Entities_Se(c+3,c+5,5,b,b);
			Entities_Se(c+2,c+3,5,0.1,0.1);
			w=0.1;
			for(b=0;b<4;b++){
				Entities_Ue(c+b,w,1,Entities.held[d]>0?1:0);
			}
			for(b=4;b<6;b++){
				Entities_Ue(c+b,w,0,Entities.held[d]>0?1:0);
			}
			if(Entities_hurt(c,c+6)==3||Entities_hurt(c,c+6)==-5){
				Entities.type[d]=Entities_FIGHTER+2;
			}
			if(Entities.type[d]==Entities_FIGHTER&&Entities_hurt(c,c+6)!=0){
				Entities_decay[d]=0;
			}else if(Entities_decay[d]>50){
				Entities.type[d]=Entities_FIGHTER+1;
			}
			if(Menu_edgeMode==1){
				for(r=4;r<=5;r++){
					w=b=0;
					if(Entities.pos[c+r].x<8){
						w=406;
						b=floor(Entities_oldpos[c+r].y);
					}else if(Entities.pos[c+r].x>=WIDTH-8){
						w=10;
						b=floor(Entities_oldpos[c+r].y);
					}
					if(w+b!=0){
						Entities.type[d]=Entities_FIGHTER;
						Entities_decay[d]=0;
						f=b*WIDTH+w;
						if(parts[f]>Parts_BGFAN){
							if(parts[f]<=-1){
								Entities.pos[c+r].copy(Entities_oldpos[c+r]);
								continue;
							}else if(states[Parts_type[parts[f]]]!=State_LIQUID){
								Entities.pos[c+r].copy(Entities_oldpos[c+r]);
								continue;
							}
						}
						e.sub2(Entities.pos[c+r],Entities_oldpos[c+r]);
						e.fastnormalize();
						for(d=0;d<=10;d++){
							Entities.pos[c+d].x=w+e.x+random2(-0.1,0.1);
							Entities.pos[c+d].y=b+e.y+random2(-0.1,0.1);
							Entities_oldpos[c+d].set(w,b);
						}
						break;
					}
				}
			}
		}else if(Entities.type[d]==Entities_FIGHTER+2){
			Entities.pos[c+10].copy(Entities.pos[c+5]);
			Entities_oldpos[c+10].copy(Entities_oldpos[c+5]);
			Entities.pos[c+9].copy(Entities.pos[c+4]);
			Entities_oldpos[c+9].copy(Entities_oldpos[c+4]);
			Entities.pos[c+8].copy(Entities.pos[c+3]);
			Entities_oldpos[c+8].copy(Entities_oldpos[c+3]);
			Entities.pos[c+7].copy(Entities.pos[c+3]);
			Entities_oldpos[c+7].copy(Entities_oldpos[c+3]);
			Entities.pos[c+6].copy(Entities.pos[c+2]);
			Entities_oldpos[c+6].copy(Entities_oldpos[c+2]);
			Entities.pos[c+5].copy(Entities.pos[c+2]);
			Entities_oldpos[c+5].copy(Entities_oldpos[c+2]);
			Entities.pos[c+4].copy(Entities.pos[c+1]);
			Entities_oldpos[c+4].copy(Entities_oldpos[c+1]);
			Entities.pos[c+3].copy(Entities.pos[c+1]);
			Entities_oldpos[c+3].copy(Entities_oldpos[c+1]);
			Entities.pos[c+2].copy(Entities.pos[c+1]);
			Entities_oldpos[c+2].copy(Entities_oldpos[c+1]);
			Entities.pos[c+1].copy(Entities.pos[c+0]);
			Entities_oldpos[c+1].copy(Entities_oldpos[c+0]);
			Entities.pos[c+0].copy(Entities.pos[c+0]);
			Entities_oldpos[c+0].copy(Entities_oldpos[c+0]);
			Entities_Pe[d].y-=1;
			Entities_decay[d]=0;
			Entities.type[d]=Entities_FIGHTER+3;
		}else if(Entities.type[d]==Entities_FIGHTER+3){
			Entities_decay[d]++;
			for(b=0;b<11;b++){
				Entities_Re(c+b,0.1,0.999);
				Entities.pos[c+b].add(Entities_Pe[d]);
			}
			Entities_Pe[d].mul(0.5);
			b=0.5;
			e=(150-Entities_decay[d])/150;
			Entities_Se(c+1,c+2,4*e,b,b);
			Entities_Se(c+3,c+5,4*e,b,b);
			Entities_Se(c+4,c+7,4*e,b,b);
			Entities_Se(c+6,c+9,5*e,b,b);
			Entities_Se(c+8,c+10,5*e,b,b);
			w=0.1;
			for(b=0;b<11;b++){
				Entities_Ue(c+b,w,0,0);
			}
			if(Entities_decay[d]>150){
				Entities_remove(d--);
			}
		}else if(Entities.type[d]==Entities_BOX){
			Entities_decay[d]++;
			for(b=0;b<4;b++){
				Entities_Re(c+b,0.1,1);
			}
			Entities_drag(d,c,c+4);
			for(b=0;b<4;b++){
				for(r=0;r<Entities.used;r++){
					if(Entities.type[r]==Entities_FIGHTER||Entities.type[r]==Entities_FIGHTER+1||Entities.type[r]==Entities_PLAYER){
						f=r*Entities.PARTS;
						g=abs(Entities.pos[f+4].x-Entities.pos[c+b].x);
						q=abs(Entities.pos[f+4].y-Entities.pos[c+b].y);
						if(g<=3&&q<=3){
							Entities.pos[c+b].x+=1*(Entities.pos[f+4].x-Entities_oldpos[f+4].x);
							Entities.pos[c+b].y+=2*(Entities.pos[f+4].y-Entities_oldpos[f+4].y);
						}
						g=abs(Entities.pos[f+5].x-Entities.pos[c+b].x);
						q=abs(Entities.pos[f+5].y-Entities.pos[c+b].y);
						if(g<=3&&q<=3){
							Entities.pos[c+b].x+=1*(Entities.pos[f+5].x-Entities_oldpos[f+5].x);
							Entities.pos[c+b].y+=2*(Entities.pos[f+5].y-Entities_oldpos[f+5].y);
						}
					}
				}
			}
			b=0.5;
			r=4*(Entities.meta2[d]+1);
			Entities_Se(c+0,c+1,r,b,b);
			Entities_Se(c+1,c+2,r,b,b);
			Entities_Se(c+2,c+3,r,b,b);
			Entities_Se(c+3,c+0,r,b,b);
			Entities_Se(c+0,c+2,1.4142135*r,b,b);
			Entities_Se(c+1,c+3,1.4142135*r,b,b);
			w=0.5;
			for(b=0;b<4;b++){
				Entities_Ue(c+b,w,0,1);
			}
			if(Entities_hurt(c,c+6)==3||Entities_hurt(c,c+6)==-5){
				Entities.type[d]=Entities_BOX+1;
			}
		}else if(Entities.type[d]==Entities_BOX+1){
			Entities.pos[c+7].copy(Entities.pos[c+0]);
			Entities_oldpos[c+7].copy(Entities_oldpos[c+0]);
			Entities.pos[c+6].copy(Entities.pos[c+3]);
			Entities_oldpos[c+6].copy(Entities_oldpos[c+3]);
			Entities.pos[c+5].copy(Entities.pos[c+3]);
			Entities_oldpos[c+5].copy(Entities_oldpos[c+3]);
			Entities.pos[c+4].copy(Entities.pos[c+2]);
			Entities_oldpos[c+4].copy(Entities_oldpos[c+2]);
			Entities.pos[c+3].copy(Entities.pos[c+2]);
			Entities_oldpos[c+3].copy(Entities_oldpos[c+2]);
			Entities.pos[c+2].copy(Entities.pos[c+1]);
			Entities_oldpos[c+2].copy(Entities_oldpos[c+1]);
			Entities.pos[c+1].copy(Entities.pos[c+1]);
			Entities_oldpos[c+1].copy(Entities_oldpos[c+1]);
			Entities.pos[c+0].copy(Entities.pos[c+0]);
			Entities_oldpos[c+0].copy(Entities_oldpos[c+0]);
			Entities.held[d]=0;
			Entities_decay[d]=0;
			Entities.type[d]= Entities_hurt(c,c+4)==-5 ? Entities_BOX+3 : Entities_BOX+2;
		}else if(Entities.type[d]==Entities_BOX+2||Entities.type[d]==Entities_BOX+3){
			Entities_decay[d]++;
			Entities_drag(d,c,c+8);
			for(b=0;b<8;b++){
				Entities_Re(c+b,0.1,0.999);
			}
			b=0.5;
			r=(150-Entities_decay[d])/150*(Entities.meta2[d]+1)*4;
			Entities_Se(c+0,c+1,r,b,b);
			Entities_Se(c+2,c+3,r,b,b);
			Entities_Se(c+4,c+5,r,b,b);
			Entities_Se(c+6,c+7,r,b,b);
			if(Entities.type[d]==Entities_BOX+2&&Parts_limits[Menu_dotLimit]-Parts_used>=1000){
				for(b=0;b<5;b+=2){
					e.sub2(Entities_oldpos[c+b+1],Entities_oldpos[c+b]);
					e.mul(random(1));
					e.add(Entities_oldpos[c+b]);
					f=floor(e.y)*WIDTH+floor(e.x);
					if(parts[f]<=Parts_BGFAN){
						Parts_create(floor(e.x),floor(e.y),4);
					}
				}
			}
			w=0.1;
			for(b=0;b<8;b++){
				Entities_Ue(c+b,w,0,0);
			}
			if(Entities_decay[d]>150){
				Entities_remove(d--);
			}
		}else if(Entities.type[d]==Entities_CREATE){
			if(Entities_Ud[c]==0){
				for(r=0;r<Entities.used;r++){
					if(Entities.pos[c].x+8>=Entities.pos[r*Entities.PARTS].x && Entities.pos[r*Entities.PARTS].x>=Entities.pos[c].x-4 && Entities.pos[c].y+8>=Entities.pos[r*Entities.PARTS].y && Entities.pos[r*Entities.PARTS].y>=Entities.pos[c].y-4){
						if(Entities.type[r]==Entities_FIGHTER||Entities.type[r]==Entities_BOX){
							Entities_Ud[c]=Entities.type[r];
							Entities.meta2[d]=Entities.meta2[r];
						}else if(Entities.type[r]==Entities_PLAYER){
							for(e=0;e<Entities.used;e++){
								if(Entities.type[e]==Entities_CREATE&&Entities_Ud[e*Entities.PARTS]==Entities_PLAYER){
									Entities_Ud[e*Entities.PARTS]=0;
								}
							}
							Entities_Ud[c]=Entities.type[r];
							Entities.meta2[d]=Entities.meta2[r];
						}
					}
				}
				for(r=0;r<Balls.MAX;r++){
					if(Balls.used[r] && Entities.pos[c].x+8>=Balls.pos[r].x && Balls.pos[r].x>=Entities.pos[c].x-4 && Entities.pos[c].y+8>=Balls.pos[r].y && Balls.pos[r].y>=Entities.pos[c].y-4){
						Entities_Ud[c]=-2;
						Entities.meta2[d]=Balls.type[r];
					}
				}
			//create I think
			}else{
				w=floor(Entities.pos[c+0].x);
				b=floor(Entities.pos[c+0].y);
				if(Entities_Ud[c]==Entities_PLAYER){
					if(random(100)<10){
						Entities.create(w,b,30,Entities.meta2[d])
					}
				}else{
					if(random(100)<1){
						if(Entities_Ud[c]==Entities_FIGHTER){
							Entities.create(w,b,0,0);
						}else if(Entities_Ud[c]==Entities_BOX){
							Entities.create(w,b,22,Entities.meta2[d]);
						}else if(Entities_Ud[c]==-2){
							Balls.create(w+2,b+2,Entities.meta2[d]);
						}
					}
				}
			}
		}
	}
};
window.fff=yd.prototype.Entities_display;
//DRAW ENTIT
yd.prototype.Entities_display=function(){
	var a,d,b,tan=0xFFE0AE,white=0xFFFFFF;
	if(Menu_bgMode==Bg_SILUET){
		white=tan=0;
	}
	for(a=0;a<Entities.used;a++){
		b=a*Entities.PARTS;
		switch(Entities.type[a]){
			//draw fighter
			case Entities_FIGHTER:
			case Entities_FIGHTER+1:
			case Entities_FIGHTER+2:
				line(Entities.pos[b+0].x,Entities.pos[b+0].y,Entities.pos[b+1].x,Entities.pos[b+1].y,tan);
				line(Entities.pos[b+1].x,Entities.pos[b+1].y,Entities.pos[b+2].x,Entities.pos[b+2].y,white);
				line(Entities.pos[b+1].x,Entities.pos[b+1].y,Entities.pos[b+3].x,Entities.pos[b+3].y,white);
				line(Entities.pos[b+2].x,Entities.pos[b+2].y,Entities.pos[b+4].x,Entities.pos[b+4].y,white);
				line(Entities.pos[b+3].x,Entities.pos[b+3].y,Entities.pos[b+5].x,Entities.pos[b+5].y,white);
				rectangle(floor(Entities.pos[b+0].x)-1,floor(Entities.pos[b+0].y)-1,3,3,tan);
				break;
			//draw dead fighter
			case Entities_FIGHTER+3:
				line(Entities.pos[b+1].x,Entities.pos[b+1].y,Entities.pos[b+2].x,Entities.pos[b+2].y,white);
				if(Entities_decay[a]>145)
					break;
				line(Entities.pos[b+3].x,Entities.pos[b+3].y,Entities.pos[b+5].x,Entities.pos[b+5].y,white);
				if(Entities_decay[a]>140)
					break;
				line(Entities.pos[b+4].x,Entities.pos[b+4].y,Entities.pos[b+7].x,Entities.pos[b+7].y,white);
				if(Entities_decay[a]>135)
					break;
				line(Entities.pos[b+6].x,Entities.pos[b+6].y,Entities.pos[b+9].x,Entities.pos[b+9].y,white);
				if(Entities_decay[a]>130)
					break;
				line(Entities.pos[b+8].x,Entities.pos[b+8].y,Entities.pos[b+10].x,Entities.pos[b+10].y,white);
				if(Entities_decay[a]>125)
					break;
				rectangle(floor(Entities.pos[b+0].x)-1,floor(Entities.pos[b+0].y)-1,2,2,tan);
				break;
			//draw box
			case Entities_BOX:
			case Entities_BOX+1:
				line(Entities.pos[b+0].x,Entities.pos[b+0].y,Entities.pos[b+1].x,Entities.pos[b+1].y,tan);
				line(Entities.pos[b+1].x,Entities.pos[b+1].y,Entities.pos[b+2].x,Entities.pos[b+2].y,tan);
				line(Entities.pos[b+2].x,Entities.pos[b+2].y,Entities.pos[b+3].x,Entities.pos[b+3].y,tan);
				line(Entities.pos[b+3].x,Entities.pos[b+3].y,Entities.pos[b+0].x,Entities.pos[b+0].y,tan);
				break;
			//draw dead box
			case Entities_BOX+2:
			case Entities_BOX+3:
				line(Entities.pos[b+0].x,Entities.pos[b+0].y,Entities.pos[b+1].x,Entities.pos[b+1].y,tan);
				if(Entities_decay[a]>145)
					break;
				line(Entities.pos[b+2].x,Entities.pos[b+2].y,Entities.pos[b+3].x,Entities.pos[b+3].y,tan);
				if(Entities_decay[a]>140)
					break;
				line(Entities.pos[b+4].x,Entities.pos[b+4].y,Entities.pos[b+5].x,Entities.pos[b+5].y,tan);
				if(Entities_decay[a]>135)
					break;
				line(Entities.pos[b+6].x,Entities.pos[b+6].y,Entities.pos[b+7].x,Entities.pos[b+7].y,tan);
				if(Entities_decay[a]>130)
					break;
				break;
			//draw player
			case Entities_PLAYER:
			case Entities_PLAYER+2:
			case Entities_PLAYER+3:
				var f,g,q,n;
				if(Entities.type[a]!=Entities_PLAYER+3){
					line(Entities.pos[b+1].x,Entities.pos[b+1].y,Entities.pos[b+2].x,Entities.pos[b+2].y,white);
					line(Entities.pos[b+1].x,Entities.pos[b+1].y,Entities.pos[b+3].x,Entities.pos[b+3].y,white);
					line(Entities.pos[b+2].x,Entities.pos[b+2].y,Entities.pos[b+4].x,Entities.pos[b+4].y,white);
					line(Entities.pos[b+3].x,Entities.pos[b+3].y,Entities.pos[b+5].x,Entities.pos[b+5].y,white);
					f=-2;
					g=2;
					q=-1;
					n=3;
				}else{
					line(Entities.pos[b+3].x,Entities.pos[b+3].y,Entities.pos[b+5].x,Entities.pos[b+5].y,white);
					if(Entities_decay[a]>140){
						break;
					}
					line(Entities.pos[b+4].x,Entities.pos[b+4].y,Entities.pos[b+7].x,Entities.pos[b+7].y,white);
					if(Entities_decay[a]>135){
						break;
					}
					line(Entities.pos[b+6].x,Entities.pos[b+6].y,Entities.pos[b+9].x,Entities.pos[b+9].y,white);
					if(Entities_decay[a]>130){
						break;
					}
					line(Entities.pos[b+8].x,Entities.pos[b+8].y,Entities.pos[b+10].x,Entities.pos[b+10].y,white);
					if(Entities_decay[a]>125){
						break;
					}
					f=-1;
					g=1;
					q=-1;
					n=1
				}
				var headcolor=colors[Entities.meta2[a]]||tan;
				if(Menu_bgMode==Bg_SILUET){
					headcolor=0x000000;
				}
				for(var r=q;r<=n;r++){
					for(var w=f;w<=g;w++){
						
						if(f+1>w || w>g-1 || q+1>r || r>n-1){
							var y=floor(Entities.pos[b].x)+w;
							z=floor(Entities.pos[b].y)+r;
							if(!(y<8||y>=408||z<8||z>=308||(Entities.meta1[a]==1&&w==f&&r==q)||(Entities.meta1[a]==1&&w==g&&r==q)||Entities.meta1[a]==1&&w==f&&r==n||Entities.meta1[a]==1&&w==g&&r==n)){
								y=z*WIDTH+y;
								screenbuffer[y]=screenbuffer[y]==headcolor?0:headcolor;
							}
						}
					}
				}
				if(Menu_bgMode==Bg_DARK){
					f=floor(clamp(Entities.pos[b+0].x,8,407));
					q=floor(clamp(Entities.pos[b+0].y,8,304));
					for(r=q-4;r<=q+4;r+=4){
						for(w=f-4;w<=f+4;w+=4){
							lights[r*WIDTH+w]=0x1FFFFFFF;
						}
					}
				}
				break;
			//draw CREATE
			case Entities_CREATE:
				//choose color (normally brown, or black with BG siluet)
				var createcolor=0x907010;
				if(Menu_bgMode==Bg_SILUET){
					createcolor=0x000000;
				}
				//fighter
				if(Entities_Ud[b]==Entities_FIGHTER){
					line(Entities.pos[b].x,Entities.pos[b].y,Entities.pos[b].x,Entities.pos[b].y+3,createcolor);
					line(Entities.pos[b].x,Entities.pos[b].y,Entities.pos[b].x+3,Entities.pos[b].y,createcolor);
					line(Entities.pos[b].x,Entities.pos[b].y+2,Entities.pos[b].x+2,Entities.pos[b].y+2,createcolor);
				//box
				}else if(Entities_Ud[b]==Entities_BOX){
					box(floor(Entities.pos[b].x),floor(Entities.pos[b].y),3,3,createcolor);
				//player
				}else if(Entities_Ud[b]==Entities_PLAYER){
					line(Entities.pos[b].x,Entities.pos[b].y,Entities.pos[b].x,Entities.pos[b].y+3,createcolor);
					line(Entities.pos[b].x,Entities.pos[b].y,Entities.pos[b].x+2,Entities.pos[b].y,createcolor);
					line(Entities.pos[b].x,Entities.pos[b].y+2,Entities.pos[b].x+2,Entities.pos[b].y+2,createcolor);
					line(Entities.pos[b].x+3,Entities.pos[b].y,Entities.pos[b].x+3,Entities.pos[b].y+2,createcolor);
				//ball
				}else if(Entities_Ud[b]==-2){
					line(Entities.pos[b].x+1,Entities.pos[b].y,Entities.pos[b].x+2,Entities.pos[b].y,createcolor);
					line(Entities.pos[b].x,Entities.pos[b].y+1,Entities.pos[b].x,Entities.pos[b].y+2,createcolor);
					line(Entities.pos[b].x+3,Entities.pos[b].y+1,Entities.pos[b].x+3,Entities.pos[b].y+2,createcolor);
					line(Entities.pos[b].x+1,Entities.pos[b].y+3,Entities.pos[b].x+2,Entities.pos[b].y+3,createcolor);
				//nothing
				}else{
					rectangle(floor(Entities.pos[b].x),floor(Entities.pos[b].y),4,4,createcolor);
				}
		}
		switch(Entities.type[a]){
			case Entities_FIGHTER:
			case Entities_FIGHTER+1:
			case Entities_FIGHTER+2:
			case Entities_FIGHTER+3:
			case Entities_PLAYER:
			case Entities_PLAYER+2:
			case Entities_PLAYER+3:
				if(Menu_bgMode==12){
					for(d=0;d<6;d++){
						f=floor(clamp(Entities.pos[b+d].x,8,407))
						q=floor(clamp(Entities.pos[b+d].y,8,304))
						lights[q*WIDTH+f]=3000
					}
				}
		}
	}
};

var Balls={
	MAX:50
}
Balls={
	MAX:Balls.MAX,
	pos:Array(Balls.MAX),
	vel:Array(Balls.MAX),
	used:Array(Balls.MAX),
	meta:Array(Balls.MAX),
	held:Array(Balls.MAX),
	type:Array(Balls.MAX),
	create:function(x,y,type){//make balled
		for(var i=0;i<Balls.MAX;i++){
			if(!Balls.used[i]){
				Balls.pos[i].set(x+0.5,y+0.5);
				Balls.vel[i].set(0,0);
				Balls.used[i]=true;
				Balls.meta[i]=0;
				Balls.held[i]=0;
				Balls.type[i]=type;
				break;
			}
		}
	}
}

var $e;
for($e=0;$e<Balls.MAX;$e++){
	Balls.pos[$e]=new Vector;
}
for($e=0;$e<Balls.MAX;$e++){
	Balls.vel[$e]=new Vector;
}

//there is nothing at the end of these lines

//  222 
// 21112 
//2100012
//2100012
//2100012
// 21112 
//  222

const ballneighborhood=[-WIDTH-1,-WIDTH,-WIDTH+1,-1,0,1,WIDTH-1,WIDTH,WIDTH+1,2*-WIDTH-1,2*-WIDTH,2*-WIDTH+1,2*WIDTH-1,2*WIDTH,2*WIDTH+1,-2-WIDTH,-2,-2+WIDTH,2-WIDTH,2,2+WIDTH,3*-WIDTH-1,3*-WIDTH,3*-WIDTH+1,3*WIDTH-1,3*WIDTH,3*WIDTH+1,-3-WIDTH,-3,-3+WIDTH,3-WIDTH,3,3+WIDTH,-2-2*WIDTH,2-2*WIDTH,-2+2*WIDTH,2+2*WIDTH];
var Balls_breakXVelocity=[-0.7,0,0.7,-1,0,1,-0.7,0,0.7,-0.44,0,0.44,-0.44,0,0.44,-0.89,-1,-0.89,0.89,1,0.89,-0.31,0,0.31,-0.31,0,0.31,-0.94,-1,-0.94,0.94,1,0.94,-0.7,0.7,-0.7,0.7]
var Balls_breakYVelocity=[-0.7,-1,-0.7,0,0,0,0.7,1,0.7,-0.89,-1,-0.89,0.89,1,0.89,-0.44,0,0.44,-0.44,0,0.44,-0.94,-1,-0.94,0.94,1,0.94,-0.31,0,0.31,-0.31,0,0.31,-0.7,-0.7,0.7,0.7];//see what did I tell you?
var Balls_breakXOffset=[-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-2,-2,-2,2,2,2,-1,0,1,-1,0,1,-3,-3,-3,3,3,3,-2,2,-2,2];
var Balls_breakYOffset=[-1,-1,-1,0,0,0,1,1,1,-2,-2,-2,2,2,2,-1,0,1,-1,0,1,-3,-3,-3,3,3,3,-1,0,1,-1,0,1,-2,-2,2,2];
var Balls_weight=[0,0,0.1,0.1,-0.03,0.1,0.1,0.1,0.1,0,0.1,0.02,0.05,0.1,0.1,0.1,0.1,0.1,0,0.1,0.1,0.1,0,0.1,0.1,0.1,-0.01,0.1,0.1,0.2,0,0.1,0,0.1,0.1,0.1,0.1,0.1,0.1,0.05,0,0.2,0.1,0.1,-0.02,0.1];
var Balls_advection=[0,0,0.5,0.4,0.5,0.5,0.4,0.4,0.9,0,0.3,0.5,0.5,0.3,0.3,0.3,0,0.2,0,0.1,0,0.5,0,0.3,0.5,0.3,0.5,0.4,0,0,0,0.1,0,0,0.4,0.4,0.5,0.4,0.2,0.5,0,0,0.5,0.2,0.5,0];

var validballs=[0,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,0,1,0,1,1,1,1,0,0,0,1,1,1];
window.fff=yd.prototype.Balls_update;
//update balls, yo
yd.prototype.Balls_update=function(){
	var d,b,c=new Vector;
	for(var i=0;i<Balls.MAX;i++){
		
		if(Balls.used[i]){
			if(!validballs[Balls.type[i]]){
				Balls.used[i]=false;
				console.log("invalid ball removed");
			}else{
				b=floor(Balls.pos[i].y)*WIDTH+floor(Balls.pos[i].x);
				for(d=0;d<21;d++){
					if(parts[b+ballneighborhood[d]]==Parts_BALL){
						parts[b+ballneighborhood[d]]=Parts_EMPTY
					}
				}
				var e=Balls_weight[Balls.type[i]];
				Balls.vel[i].y+=e;
				d=Balls_advection[Balls.type[i]];
				if(d!=0){
					b=(floor(Balls.pos[i].y)>>2)*G+(floor(Balls.pos[i].x)>>2);
					Balls.vel[i].x+=Air.vel[b].x*d;
					Balls.vel[i].y+=Air.vel[b].y*d;
					if(Air.vel[b].fastdist()>0.3){
						Balls.vel[i].mul(0.9+(1-d)/10);
					}
				}
				b=i;
				d=new Vector;
				if(!Balls.held[b]){
					if(Menu_leftSelection==M_DRAG&&mouse.rising.left||Menu_rightSelection==M_DRAG&&mouse.rising.right){
						d.x=pen_x-Balls.pos[b].x
						d.y=pen_y-Balls.pos[b].y
						if(d.fastdist()<20){
							Balls.held[b]=true;
						}
					}
				}else{
					if(Menu_leftSelection==M_DRAG&&mouse.old.left||Menu_rightSelection==M_DRAG&&mouse.old.right){
						Balls.vel[b].x+=0.05*(pen_x-Balls.pos[b].x);
						Balls.vel[b].y+=0.05*(pen_y-Balls.pos[b].y);
						Balls.vel[b].mul(0.9);
					}else{
						Balls.vel[b].mul(0.3);
						Balls.held[b]=false;
					}
				}
				for(d=0;d<Entities.used;d++){
					if(Entities.type[d]==Entities_FIGHTER||Entities.type[d]==Entities_FIGHTER+1||Entities.type[d]==Entities_PLAYER){
						b=d*Entities.PARTS;
						for(var f=4;f<=5;f++){
							var g=abs(Entities.pos[b+f].y-Balls.pos[i].y);
							if(abs(Entities.pos[b+f].x-Balls.pos[i].x)<=9&&g<=9){
								Balls.vel[i].x+=0.1*(Entities.pos[b+f].x-Entities_oldpos[b+f].x);
								Balls.vel[i].y+=0.2*(Entities.pos[b+f].y-Entities_oldpos[b+f].y);
							}
						}
					}
				}
				f=new Vector;
				f.copy(Balls.vel[i]);
				$e=0;
				var q=floor(Balls.vel[i].dist()/2)+1,n=1/q,r,w,y=0,z=new Vector;
				for(var v=g=0;v<q;v++){
					r=Balls.pos[i].x+Balls.vel[i].x*n;
					w=Balls.pos[i].y+Balls.vel[i].y*n;
					if(r<4||r>=WIDTH-4||w<4||w>=312){
						Balls.used[i]=false;
						break;
					}
					if(Menu_edgeMode==1){
						if(r<8){
							if(parts[floor(w)*WIDTH+floor(r+400)]<=Parts_BGFAN){
								Balls.pos[i].x+=400;
								Balls.vel[i].x*=0.8;
							}else{
								Balls.vel[i].x*=-0.8;
							}
							r=Balls.pos[i].x+Balls.vel[i].x*n;
						}else if(r>=408){
							if(parts[floor(w)*WIDTH+floor(r-400)]<=Parts_BGFAN){
								Balls.pos[i].x-=400;
								Balls.vel[i].x*=0.8;
							}else{
								Balls.vel[i].x*=-0.8;
							}
							r=Balls.pos[i].x+Balls.vel[i].x*n;
						}
						if(w<8){
							if(parts[floor(w+300)*WIDTH+floor(r)]<=Parts_BGFAN){
								Balls.pos[i].y+=300;
								Balls.vel[i].y*=0.8;
							}else{
								Balls.vel[i].y*=-0.8;
							}
							w=Balls.pos[i].y+Balls.vel[i].y*n
						}else if(w>=308){
							if(parts[floor(w-300)*WIDTH+floor(r)]<=Parts_BGFAN){
								Balls.pos[i].y-=300;
								Balls.vel[i].y*=0.5;
							}else{
								Balls.vel[i].y*=-0.8;
							}
							w=Balls.pos[i].y+Balls.vel[i].y*n;
						}
					}
					b=floor(w)*WIDTH+floor(r);
					y=0;
					z.set(0,0);
					for(d=0;d<37;d++){
						var Y=parts[b+ballneighborhood[d]];
						if(Y>Parts_BGFAN){
							g=Y;
							if(Y>=0){
								g=Parts_type[Y];
								if(Balls_react(i,g,Y)==1){ //return 1 to skip phyiscs update
									continue;
								}
							}
							z.x-=Balls_breakXVelocity[d];
							z.y-=Balls_breakYVelocity[d];
							y++
						}
					}
					if(y==0){
						Balls.pos[i].x=r;
						Balls.pos[i].y=w;
					}else{
						z.normalize();
						Balls.vel[i].y-=e;
						d=0.999*Balls.vel[i].dist();
						z.mul(-(z.x*Balls.vel[i].x+z.y*Balls.vel[i].y));
						Balls.vel[i].add(z);
						Balls.vel[i].mul(0.999);
						z.mul(0.1);
						Balls.vel[i].add(z);
						Balls.vel[i].normalize();
						Balls.vel[i].mul(d);
						Balls.pos[i].x+=Balls.vel[i].x*n;
						Balls.pos[i].y+=Balls.vel[i].y*n;
						Balls.vel[i].y+=e;
					}
					b=floor(Balls.pos[i].y)*WIDTH+floor(Balls.pos[i].x);
					y=0;
					z.set(0,0);
					for(d=0;d<21;d++){
						Y=parts[b+ballneighborhood[d]];
						if(Y>Parts_BGFAN){
							if(Y>=0){
								//liquid + different liquid ball
								if(states[Parts_type[Y]]==State_LIQUID&&states[Balls.type[i]]==State_LIQUID&&Balls.type[i]!=Parts_type[Y]){
									continue;
								}
								//liquid + non-liquid ball
								if(states[Parts_type[Y]]==State_LIQUID&&states[Balls.type[i]]!=State_LIQUID){
									continue;
								}
								//gas + non-gas ball
								if(states[Parts_type[Y]]==State_GAS&&states[Balls.type[i]]!=State_GAS){
									continue;
								}
								//laser + liquid ball
								if(Parts_type[Y]==LASER&&states[Balls.type[i]]==State_LIQUID){
									continue;
								}
								//fire
								if(Parts_type[Y]==FIRE){
									continue;
								}
								//thunder + thunder ball
								if(Parts_type[Y]==THUNDER&&Balls.type[i]==THUNDER){
									continue;
								}
							}
							z.x-=Balls_breakXVelocity[d];
							z.y-=Balls_breakYVelocity[d];
							y++;
						}
					}
					if(y!=0){
						z.normalize();
						Balls.pos[i].add(z);
					}
				}
				if(Balls.pos[i].x<4||Balls.pos[i].x>=WIDTH-4||Balls.pos[i].y<4||Balls.pos[i].y>=312){
					Balls.used[i]=false;
					break
				}
				b=floor(Balls.pos[i].y)*WIDTH+floor(Balls.pos[i].x);
				e=0;
				//ball breaking
				switch(Balls.type[i]){
				//powder ball
				case Parts_POWDER:
					if(g>=0){
						//destroyed by liquid
						if(states[g]==State_LIQUID){
							Balls_break(i,b,0,Parts_POWDER,0,0.5*Balls.vel[i].x,0.5*Balls.vel[i].y,0.5);
						//burn by hot elements
						}else if(states[g]==State_HOT){
							Balls_break(i,b,0,FIRE,0,0.5*Balls.vel[i].x,0.5*Balls.vel[i].y,0.5);
						}
					}
				//water ball
				break;case WATER:
					//destroyed by magma thunder acid
					if(g==MAGMA||g==THUNDER||g==ACID){
						Balls_break(i,b,0,WATER,0,0,0,0);
					}
				//ice ball
				break;case ICE:
					d=f.dist();
					//destroyed by thundewr/acid or hitting block/wheel/metal/stone/bomb with high speed
					if(g==THUNDER||g==ACID||(g==-1||g==-3||g==STONE||g==METAL||g==BOMB)&&d>5){
						Balls_break(i,b,0,11,0,f.x,f.y,d);
					}
				//saltwater ball
				break;case SALTWATER:
					//destroyed by thunder acid
					if(g==THUNDER||g==ACID){
						Balls_break(i,b,0,SALTWATER,0,0,0,0);
					}
				//salt ball
				break;case SALT:
					//destroyed by magma thunder acid
					if(g==MAGMA||g==THUNDER||g==ACID){
						Balls_break(i,b,0,SALT,0,0,0,0);
					}
				//fire ball
				break;case FIRE:
					//destroyed by water soapy saltwater acid
					if(g==WATER||g==SOAPY||g==SALTWATER||g==ACID){
						Balls_break(i,b,0,FIRE,0,0,0,0);
					}
				//seed ball
				break;case SEED:
					if(g>=0){
						//destryed by acid
						if(g==ACID){
							Balls_break(i,b,0,SEED,0,0.5*Balls.vel[i].x,0.5*Balls.vel[i].y,0.5);
						//burned by hot things other than spark
						}else if(g!=SPARK&&states[g]==State_HOT){
							Balls_break(i,b,0,FIRE,0,0.5*Balls.vel[i].x,0.5*Balls.vel[i].y,0.5);
						}
					}
				//wood ball
				break;case WOOD:
					if(g>=0){
						//turn into torch
						if(g==TORCH){
							Balls_break(i,b,0,TORCH,0,0,0,0);
						//dead
						}else if(g==ACID){
							Balls_break(i,b,0,Parts_POWDER,0,0,0,0);
						//eggsplode
						}else if(g==THUNDER){
							Balls_break(i,b,0,Parts_POWDER,0,0,0,1);
						//burn or freeze'd
						}else if(g!=SPARK){
							if(states[g]==State_HOT&&Balls.meta[i]==1){
								Balls_break(i,b,0,WOOD,1,0,0,0);
							}else if(states[g]==State_HOT){
								Balls_break(i,b,0,FIRE,0,0,0,0);
							}
						}
					}
				break;case GUNPOWDER:
					if(g>=0){
						if(states[g]==State_HOT&&Balls.meta[i]==0){
							for(d=0;d<37;d++){
								Y=parts[b+ballneighborhood[d]];
								if(Y<=Parts_BGFAN){
									e=Parts_create(floor(Balls.pos[i].x)+Balls_breakXOffset[d],floor(Balls.pos[i].y)+Balls_breakYOffset[d],FIRE)
									if(e<0){
										f=random(20);
										Parts_vel[e].x+=Balls.vel[i].x*f+Balls_breakXVelocity[d]*f/2;
										Parts_vel[e].y+=Balls.vel[i].y*f+Balls_breakYVelocity[d]*f/2;
										Parts_meta1[e]=2;
									}
								}
							}
							Balls.used[i]=false;
						}else if(g==ACID){
							Balls_break(i,b,0,GUNPOWDER,0,0,0,0);
						}
					}
				break;case OIL:
					if(g>=0){
						//burn or something
						if(states[g]==State_HOT){
							for(d=9;d<21;d++){
								Y=parts[b+ballneighborhood[d]];
								if(Y<=Parts_BGFAN&&random(100)<50){
									Parts_create(floor(Balls.pos[i].x)+Balls_breakXOffset[d],floor(Balls.pos[i].y)+Balls_breakYOffset[d],FIRE);
								}
							}
							if(random(100)<1){
								Balls_break(i,b,0,OIL,0,0,0,0);
							}
						}else if(g==ACID){
							Balls_break(i,b,0,OIL,0,0,0,0);
						}
					}
				break;case SOAPY:
					if(g==MAGMA||g==THUNDER||g==ACID){
						Balls_break(i,b,0,SOAPY,0,0,0,0);
					}
				break;case FAN:
					if(g>0){
						b=(floor(Balls.pos[i].y)>>2)*G+(floor(Balls.pos[i].x)>>2);
						Air.pres[b]+=10;
						pd-=10;
					}
				break;case CLONE:
					if(Balls.meta[i]==0 && g>0){
						Balls.meta[i]=g;
					}else if(Balls.meta[i]!=0 && Parts_limits[Menu_dotLimit]-Parts_used>=1000){
						e=floor(Balls.pos[i].x);
						b=floor(Balls.pos[i].y);
						//fly when cloning magma spark, and powders
						if(states[Balls.meta[i]]==State_POWDER||Balls.meta[i]==MAGMA||Balls.meta[i]==SPARK){
							b+=4;
						}
						d=b*WIDTH+e;
						if(parts[d]<=Parts_BGFAN){
							Parts_create(e,b,Balls.meta[i]);
						}
					}
				break;case C4:case NITRO:
					if(g>=0){
						if(states[g]==State_HOT){
							f=10;
							g=floor(Balls.pos[i].x)&0xFFFC;
							q=floor(Balls.pos[i].y)&0xFFFC;
							n=max(g-f,H);
							z=max(q-f,H);
							v=min(g+f,WIDTH-H-1);
							r=min(q+f,(kd-1)*H-1);
							for(b=z;b<=r;b++){
								for(e=n;e<=v;e++){
									if((e-g)*(e-g)+(b-q)*(b-q)<=f*f){
										d=b*WIDTH+e
										if(parts[d]>=0){
											Parts_vel[parts[d]].x+=10*(e-g);
											Parts_vel[parts[d]].y+=10*(b-q);
										}
										if(parts[d]<=Parts_BGFAN&&Balls.type[i]==NITRO){
											Parts_create(e,b,FIRE);
										}
										if((b&3)+(e&3)==0){
											d=(b>>2)*G+(e>>2);
											if(blocks[d]<=0){
												if(abs(e-g)>=1){
													Air.vel[d].x+=100/(e-g);
												}
												if(abs(b-q)>=1){
													Air.vel[d].y+=100/(b-q);
												}
											}
										}
									}
								}
							}
							Balls.used[i]=false;
						}else if(g==ACID){
							Balls_break(i,b,0,Balls.type[i],0,0,0,0);
						}
					}
				//gas
				break;case GAS:
					if(g>=0){
						//burn
						if(states[g]==State_HOT){
							Balls_break(i,b,0,GAS,0,0,0,1)
							if(Balls.meta[i]<2){
								Balls.meta[i]++;
								Balls.used[i]=true; //resurrect!
							}
						}else if(g==ACID){
							Balls_break(i,b,0,GAS,0,0,0,0)
						}
					}
				//steam clones other types once
				break;case STEAM:
					if(g>=0&&states[g]>0){
						Balls_break(i,b,0,g,0,0.5*Balls.vel[i].x,0.5*Balls.vel[i].y,0.5);
					}
				//bombd
				break;case BOMB:
					if(g>=0){
						//explode on all but bomb fire gas laser
						if(g!=BOMB&&g!=FIRE&&g!=GAS&&g!=LASER&&states[g]>0){
							f=10;
							g=floor(Balls.pos[i].x);
							q=floor(Balls.pos[i].y);
							n=max(g-f,H);
							z=max(q-f,H);
							v=min(g+f,WIDTH-H-1);
							r=min(q+f,(kd-1)*H-1);
							c.set(0,0);
							for(b=z;b<=r;b++){
								for(e=n;e<=v;e++){
									if((e-g)*(e-g)+(b-q)*(b-q)<=f*f){
										d=b*WIDTH+e;
										if(parts[d]>=0){
											c.x+=Balls.pos[i].x-e;
											c.y+=Balls.pos[i].y-b;
										}
									}
								}
							}
							c.fastnormalize();
							for(b=z;b<=r;b++){
								for(e=n;e<=v;e++){
									if((e-g)*(e-g)+(b-q)*(b-q)<=f*f){
										d=b*WIDTH+e
										if(parts[d]>=0){
											Parts_meta1[parts[d]]=Parts_type[parts[d]];
											Parts_type[parts[d]]=BOMB;
											meta2[parts[d]]=0;
											Parts_vel[parts[d]].x+=0.5*c.x+0.5*(g-e);
											Parts_vel[parts[d]].y+=0.5*c.y+0.5*(q-b);
										}
									}
								}
							}
							Balls.used[i]=false;
						}
					}
				//giant bird of death
				break;case BIRD:
					if(g>=0){
						//kill
						if(states[g]==State_HOT){
							Balls_break(i,b,0,FIRE,0,0.5*Balls.vel[i].x,0.5*Balls.vel[i].y,0.5);
						//split megabird
						}else if(g==ACID){
							Balls_break(i,b,0,BIRD,0,0,0,0);
						}
					}
				//stone
				break;case STONE:
					d=f.dist()
					//break when large Parts_velocity on bomb wall metal
					if((g==-1||g==METAL||g==BOMB)&&d>7){
						Balls.type[i]=Parts_POWDER;
					//fall apart
					}else if(g==ACID){
						Balls_break(i,b,0,STONE,0,0,0,0);
					}
				//metal
				break;case METAL:
					if(SALTWATER==g){
						Balls_break(i,b,1,Parts_POWDER,0,0,0,0);
					//perhaps gain insight into parameter 3...
					}else if(g==THUNDER){
						Balls_break(i,b,2,METAL,0,0,0,0);
					}else if(g==LASER){
						Balls_break(i,b,1,METAL,0,0,0,0);
					}else if(g==ACID){
						Balls_break(i,b,0,METAL,0,0,0,0);
					}
				//glass balld
				break;case GLASS:
					d=f.dist();
					//break on wall wheel stone metal bomb if fasted
					if((g==-1||g==-3||g==STONE||g==METAL||g==BOMB)&&d>5){
						Balls_break(i,b,0,STONE,0,0,0,0.1*d);
					}else if(g==THUNDER){
						Balls_break(i,b,1,GLASS,0,0,0,0);
					}else if(g==LASER){
						Balls_break(i,b,2,GLASS,0,0,0,0);
					}else if(g==ACID){
						Balls_break(i,b,0,GLASS,0,0,0,0);
					}
				//torch
				break;case TORCH:
					if(g==WATER||g==SOAPY||g==SALTWATER||g==ACID){
						Balls_break(i,b,0,TORCH,0,0,0,0);
					}else if(g==THUNDER){
						Balls_break(i,b,0,FIRE,0,0,0,0);
					}
				//fuse ballllll
				break;case FUSE:
					if(g>=0){
						if(states[g]==State_HOT){
							if(Balls.meta[i]==OIL){
								Balls_break(i,b,2,FIRE,0,0,0,0);
							}else if(Balls.meta[i]==NITRO){
								Balls_break(i,b,0,NITRO,0,0,0,1);
							}else if(Balls.meta[i]==SOAPY){
								Balls_break(i,b,0,STEAM,0,0,0,1);
							}else{
								Balls_break(i,b,0,SPARK,0,0,0,0); //sparkyst[r]eam
							}
						}else if(g==WATER||g==SALTWATER){
							Balls_break(i,b,0,GUNPOWDER,0,0,0,0);
						}else if(g==ACID){
							Balls_break(i,b,0,FUSE,0,0,0,0);
						}
					}
				break;case CLOUD:
					if(g==ACID){
						Balls_break(i,b,0,CLOUD,0,0,0,0);
					}
				break;case PUMP:
					if(Balls.meta[i]!=0 && Parts_limits[Menu_dotLimit]-Parts_used>=1000){
						c.copy(Balls.vel[i]);
						c.fastnormalize();
						c.mul(4);
						e=floor(Balls.pos[i].x-c.x);
						b=floor(Balls.pos[i].y-c.y);
						d=b*WIDTH+e;
						if(parts[d]<=Parts_BGFAN){
							d=Balls.meta[i]&0xFF
							f=Balls.meta[i]>>8
							if(f>0){
								Parts_create(e,b,d);
								Balls.meta[i]=f-1<<8|d;
							}
						}
					}
				}
				//TYPE SWITCH!!!
				if($e!=0){
					Balls.type[i]=$e;
					Balls.meta[i]=0;
				}
				//balld taked up spaced
				if(Balls.used[i]){
					b=floor(Balls.pos[i].y)*WIDTH+floor(Balls.pos[i].x);
					for(d=0;d<21;d++){
						if(parts[b+ballneighborhood[d]]<=Parts_BGFAN){
							parts[b+ballneighborhood[d]]=Parts_BALL;
						}
					}
				}
			}
		}
	}
};
//BALL REACTIONS!!!
function Balls_react(ball,parttype,part){
	switch(Balls.type[ball]){
	//water ball
	case WATER:
		switch(parttype){
		//remove fire
		case FIRE:
			remove(part);
			return 1;
		//turn wood into seeed
		break;case WOOD:
			Parts_type[part]=SEED;
			Parts_meta1[part]=0;
		//frozen by ice
		break;case ICE:
			$e=ICE;
		//...and snow
		break;case SNOW:
			if(++Balls.meta[ball]>=20){
				$e=ICE;
			}
		//??
		break;case MAGMA:case THUNDER:case LASER:
			return 1;
		//remove torch
		break;case TORCH:
			remove(part);
		//rust metal
		break;case METAL:
			if(random(100)<10){
				Parts_type[part]=Parts_POWDER;
				Parts_meta1[part]=0;
			}
		//salt turns ball into saltwater
		break;case SALT:
			if(++Balls.meta[ball]>=20){
				$e=SALTWATER;
			}
			remove(part);
		//break fuse
		break;case FUSE:
			Parts_type[part]=GUNPOWDER;
			Parts_meta1[part]=0;
		}
	//ice ball
	break;case ICE:
		switch(parttype){
		case WATER:
			Parts_type[part]=ICE;
			Parts_meta1[part]=0;
		break;case FIRE:case SPARK:case LASER:case TORCH:
			if(++Balls.meta[ball]>=20){
				$e=WATER;
			}
		break;case ICE:case SNOW:
			Balls.meta[ball]=0;
		break;case MAGMA:
			$e=WATER;
		break;case THUNDER:
			return 1;
		}
	break;case SALTWATER:
		switch(parttype){
		case WATER:
			Balls.meta[ball]=0;
		//fire heat'd
		break;case FIRE:
			if(++Balls.meta[ball]>=20){
				$e=SALT;
			}
			remove(part);
			return 1;
		//seed wood dissolved by also metal vines too
		break;case SEED:case WOOD:case METAL:case VINE:
			Parts_type[part]=Parts_POWDER //part
			Parts_meta1[part]=0; //meta
		//ice freez
		break;case ICE:
			$e=ICE;
		//snow heat?
		break;case SNOW:
			if(++Balls.meta[ball]>=20){
				$e=ICE;
			}
		//magma evaporate
		break;case MAGMA:
			$e=SALT;
		//torch heat metla
		break;case TORCH:case SPARK:
			if(++Balls.meta[ball]>=20){
				$e=SALT;
			}
			remove(part);
		//idk
		break;case THUNDER:
			return 1;
		//salted
		break;case LASER:
			if(++Balls.meta[ball]>=20){
				$e=SALT;
			}
			return 1;
		//eating salt
		break;case SALT:
			if(Balls.meta[ball]++<20){
				remove(part);
			}
		//dissolve fuse
		break;case FUSE:
			Parts_type[part]=GUNPOWDER;
			Parts_meta1[part]=0;
		}
	//salt ball
	break;case SALT:
		switch(parttype){
		case WATER:
			$e=SALTWATER;
		break;case MAGMA:case THUNDER:
			return 1;
		}
	//fire ball
	break;case FIRE:
		//burn fire seed wood gunpowder oil c4 nitro ant vine bird fuse
		switch(parttype){
		case Parts_POWDER:case SEED:case WOOD:case GUNPOWDER:case OIL:case C4:case NITRO:case ANT:case GAS:case VINE:case BIRD:case FUSE:
			Parts_type[part]=FIRE;
			Parts_meta1[part]=0;
		//melt ice and snow
		break;case ICE:case SNOW:
			Parts_type[part]=WATER;
			Parts_meta1[part]=0;
		//set off fireworks
		break;case FIREWORKS:
			if(Parts_type[part]==FIREWORKS && Parts_meta1[part]>0 && Parts_meta1[part]<100){
				Parts_vel[part].y-=50;
				Parts_meta1[part]+=100;
			}
		}
	//seed ball
	break;case SEED:
		//grow?
		switch(parttype){
		case Parts_POWDER:
			if(Balls.meta[ball]==1){
				$e=WOOD;
			}else{
				Parts_type[part]=SEED;
				Parts_meta1[part]=0;
			}
		//enter grow mode
		break;case WATER:
			Balls.meta[ball]=1;
		//turn vine to wood
		break;case VINE:
			Parts_type[part]=WOOD;
			Parts_meta1[part]=0;
		}
	//nice >:]
	break;case WOOD:
		//wood ball+seed = seed grows
		switch(parttype){
		case SEED:
			Parts_meta1[part]=1;
		//wood ball + oil makes wood ball burn longer!!! (wow)
		break;case OIL:
			Balls.meta[ball]=1;
		}
	//funpowder ball (typo unintentional but left in)
	break;case GUNPOWDER:
		//some elements increase/decrese explodeyness
		switch(parttype){
		case WATER:case SOAPY:case SALTWATER:
			if(Balls.meta[ball]<20){
				Balls.meta[ball]++;
			}
		break;case FIRE:case MAGMA:case TORCH:case THUNDER:case LASER:case SPARK:
			if(Balls.meta[ball]>0){
				Balls.meta[ball]--;
			}
		}
	//oil ball
	break;case OIL:
		switch(parttype){
		case MAGMA:case THUNDER:case LASER:
			return 1;
		//kill soaps
		break;case SOAPY:
			remove(part);
		//fuse absorb
		break;case FUSE:
			if(Parts_meta1[part]<256){
				Parts_meta1[part]=OIL;
			}
		}
	//soap ball
	break;case SOAPY:
		switch(parttype){
		//freeze
		case ICE:
			$e=ICE;
		//kill oils //kill torch //kill spark'd
		break;case OIL:case TORCH:case SPARK:
			remove(part);
		//burn
		break;case MAGMA:case THUNDER:case LASER:
			return 1;
		//absorb to fuse
		break;case FUSE:
			if(meta[part]<256){
				Parts_meta1[part]=SOAPY;
			}
		}
	//not a big fan of this... hehe
	//else if(Balls.type[a]!=FAN)
	//clone ball
	break;case CLONE:
		if(parttype==THUNDER||parttype==LASER){
			return 1;
		}
	//virus ball
	break;case VIRUS:
		if(parttype>0){
			if(Balls.meta[ball]==0){
				Balls.meta[ball]=parttype;
			}else if(Balls.meta[ball]!=0){
				Parts_type[part]=Balls.meta[ball];
				Parts_meta1[part]=0;
				Parts_pumpType[part]=0;
			}
		}
	//nitro ball
	break;case NITRO:
		if(parttype==FUSE&&Parts_meta1[part]<256){
			Parts_meta1[part]=NITRO;
		}
	//acid ball
	break;case ACID:
		//dissolve things (and clone)
		if(Parts_DISSOLVERATE[parttype]!=0||parttype==CLONE){
			remove(part);
		}
		if(parttype==THUNDER||parttype==LASER){
			return 1;
		}
	//bird ball
	break;case BIRD:
		switch(parttype){
		//eat seed/ant
		case SEED:case ANT:
			remove(part);
		//slow down near wood
		break;case WOOD:
			Balls.vel[ball].mul(0.9);
		}
	//thunder ball
	break;case THUNDER:
		//make thunders
		switch(parttype){
		case SALTWATER:
			Parts_type[part]=THUNDER;
			Parts_meta1[part]=0;
			return 0;
		break;case THUNDER:
			return 1;
		break;case METAL:
			Parts_type[part]=THUNDER;
			Parts_meta1[part]=6000;
		break;case MERCURY:
			Parts_type[part]=THUNDER;
			Parts_meta1[part]=6100;
			return 1;
		}
	//stone ball
	break;case STONE:
		switch(parttype){
		//cool
		case WATER:
			Balls.meta[ball]=0;
		//melt
		break;case MAGMA:
			if(++Balls.meta[ball]>=20){
				$e=MAGMA;
			}
		//stone + stone ball = spakrs
		break;case STONE:
			if(Parts_limits[Menu_dotLimit]-Parts_used>=1000 && Balls.vel[ball].x*Balls.vel[ball].x+Balls.vel[ball].y*Balls.vel[ball].y>10){
				var x=floor(Balls.pos[ball].x)+floor(random(5))-2;
				var y=floor(Balls.pos[ball].y)+floor(random(5))-2;
				var xy=y*WIDTH+x;
				if(parts[xy]<=Parts_BGFAN){
					Parts_create(x,y,SPARK);
				}
			}
		break;case SPARK:
			return 1;
		}
	//magma ball
	break;case MAGMA:
		switch(parttype){
		//cool into metal ball in water
		case WATER:
			if(++Balls.meta[ball]>=20){
				$e=METAL;
			}
			Parts_type[part]=STEAM;
			Parts_meta1[part]=0;
		//reheat
		break;case MAGMA:
			Balls.meta[ball]=0;
		//cool into glass ball with soapy
		break;case SOAPY:
			if(++Balls.meta[ball]>=20){
				$e=GLASS;
			}
			Parts_type[part]=STEAM;
			Parts_meta1[part]=0;
		//cool into stone ball with saltwater
		break;case SALTWATER:
			if(++Balls.meta[ball]>=20){
				$e=STONE;
			}
			Parts_type[part]=STEAM;
			Parts_meta1[part]=0;
		break;case Parts_POWDER:case SEED:case WOOD:case GUNPOWDER:case SUPERBALL:case OIL:case C4:case NITRO:case ANT:case GAS:case VINE:case BIRD:case FUSE:
			Parts_type[part]=FIRE
			Parts_meta1[part]=0
		break;case ICE:case SNOW:
			Parts_type[part]=WATER
			Parts_meta1[part]=0
		break;case FIREWORKS:
			if(Parts_type[part]==FIREWORKS&&Parts_meta1[part]>0&&Parts_meta1[part]<100){
				Parts_vel[part].y-=50;
				Parts_meta1[part]+=100;
			}
		}
	//metal ball
	break;case METAL:
		switch(parttype){
		//water cools metal ball
		case WATER:
			Balls.meta[ball]=0;
		//lava melts metal ball
		break;case MAGMA:
			Balls.meta[ball]++
			if(Balls.meta[ball]>=20){
				$e=MAGMA
			}
		//fast ball+metal = sparks
		break;case METAL:
			if(Parts_limits[Menu_dotLimit]-Parts_used>=1000 && Balls.vel[ball].x*Balls.vel[ball].x+Balls.vel[ball].y*Balls.vel[ball].y>10){
				var x=floor(Balls.pos[ball].x)+floor(random(5))-2;
				var y=floor(Balls.pos[ball].y)+floor(random(5))-2;
				var xy=y*WIDTH+x;
				if(parts[xy]<=Parts_BGFAN){
					Parts_create(x,y,SPARK);
				}
			}
		break;case THUNDER:case LASER:case SPARK:
			return 1;
		}
	//water balls
	break;case GLASS:
		switch(parttype){
		//water cool ball
		case WATER:
			Balls.meta[ball]=0;
		//magma heat ball
		break;case MAGMA:
			if(++Balls.meta[ball]>=20){
				$e=MAGMA;
			}
		//thunder laser fix ball in place
		break;case THUNDER:case LASER:
			return 1;
		}
	//torch ball
	break;case TORCH:
		switch(parttype){
		//burn powder, seed, gunpowder, superball, oil, c4, nitro, ant, gas, vine, bird, fuse
		case Parts_POWDER:case SEED:case GUNPOWDER:case SUPERBALL:case OIL:case C4:case NITRO:case ANT:case GAS:case VINE:case BIRD:case FUSE:
			Parts_type[part]=FIRE;
			Parts_meta1[part]=0;
		//melt ice snow cloud
		break;case ICE:case SNOW:case CLOUD:
			Parts_type[part]=WATER;
			Parts_meta1[part]=0;
		//set off fireworks
		break;case FIREWORKS:
			//make damn sure those are fireworks, really
			if(Parts_type[part]==FIREWORKS && Parts_meta1[part]>0 && Parts_meta1[part]<100){
				Parts_vel[part].y-=50;
				Parts_meta1[part]+=100;
			}
		}
	//fuse bal
	break;case FUSE:
		//soak oilnitrosoapy
		if(parttype==OIL||parttype==NITRO||parttype==SOAPY){
			Balls.meta[ball]=parttype;
		}
	//could
	break;case CLOUD:
		switch(parttype){
		//rain
		case WOOD:case C4:case FUSE:case VINE:case TORCH:
			$e=WATER;
		//snow
		break;case ICE:
			$e=ICE;
		//lightning
		break;case METAL:
			$e=THUNDER;
		//ded?
		break;case THUNDER:case LASER:
			return 1;
		}
	//pump;
	break;case PUMP:
		//set
		if(Balls.meta[ball]==0){
			if(parttype==WATER||parttype==OIL||parttype==MAGMA||parttype==NITRO||parttype==GAS||parttype==SOAPY||parttype==ACID||parttype==SALTWATER||parttype==MERCURY||parttype==CLOUD){
				Balls.meta[ball]=parttype;
			}
		//absorbd
		}else{
			var storing=Balls.meta[ball]&0xFF;
			var amount=Balls.meta[ball]>>8;
			if(parttype==storing){
				Balls.meta[ball]=amount+1<<8|storing;
				remove(part);
			}
		}
		//kil?
		if(parttype==MAGMA||parttype==THUNDER||parttype==LASER){
			return 1;
		}
	}
	return states[parttype]==State_LIQUID&&states[Balls.type[ball]]==State_LIQUID&&Balls.type[ball]!=parttype || states[parttype]==State_LIQUID&&states[Balls.type[ball]]!=State_LIQUID || states[parttype]==State_GAS&&states[Balls.type[ball]]!=State_GAS || parttype==FIRE?1:0;
}
////break ball.////
//ball: ball id to remove
//xy: position to break at
//mode: 0=replace ball pixels (if not filled) with createtype and setmeta1, also set velocity.
//      1=0 but destroy surrounding particles
//      2=1 but do the inside too
//createtype: particle type to use
//setmeta1: value to set meta1 to (mode 0 only)
//vx: base vx
//vy: base vy
//speed: velocity multiplier
function Balls_break(ball,xy,mode,createtype,setmeta1,vx,vy,speed){
	if(mode==0){
		//break normal
		for(var i=9;i<21;i++){
			var n=parts[xy+ballneighborhood[i]];
			if(n<=Parts_BGFAN){
				n=Parts_create(floor(Balls.pos[ball].x)+Balls_breakXOffset[i],floor(Balls.pos[ball].y)+Balls_breakYOffset[i],createtype);
				if(n>0){
					Parts_vel[n].x+=vx+Balls_breakXVelocity[i]*speed;
					Parts_vel[n].y+=vy+Balls_breakYVelocity[i]*speed;
					Parts_meta1[n]=setmeta1;
				}
			}
		}
		Balls.used[ball]=false;
	}else if(mode==1||mode==2){
		for(var i=mode==1?9:0;i<21;i++){
			n=parts[xy+ballneighborhood[i]];
			//create part
			if(n<=Parts_BGFAN){
				Parts_create(floor(Balls.pos[ball].x)+Balls_breakXOffset[i],floor(Balls.pos[ball].y)+Balls_breakYOffset[i],createtype);
			//replace parts
			}else if(n>=0){
				Parts_type[n]=createtype;
				Parts_meta1[n]=0;
				Parts_pumpType[n]=0;
			}
		}
		Balls.used[ball]=false;
	}
}
window.fff=yd.prototype.Balls_display;
yd.prototype.Balls_display=function(){
	for(var i=0;i<Balls.MAX;i++){
		if(Balls.used[i]){
			var pos=floor(Balls.pos[i].y)*WIDTH+floor(Balls.pos[i].x);
			var color=colors[Balls.type[i]];
			if(Menu_bgMode==Bg_SILUET){
				color=0;
			}
			for(var j=9;j<21;j++){
				screenbuffer[pos+ballneighborhood[j]]=color;
			}
			if(Balls.pos[i].y<308){
				if(Menu_bgMode==Bg_DARK){
					if(Balls.type[i]==FIRE||Balls.type[i]==MAGMA||Balls.type[i]==TORCH||Balls.type[i]==THUNDER||Balls.type[i]==LASER||Balls.type[i]==SPARK){
						lights[pos]=255000; //ps if you use lowercase hex you should stop
					}
				}else if(Menu_bgMode==Bg_TG){
					lights[pos]=2*Parts_TEMPERATURE[Balls.type[i]];
				}
			}
		}
	}
};

var mouse={
	x:0,
	y:0,
	left:false,
	right:false,
	old:{
		x:0,
		y:0,
		left:false,
		right:false
	},
	older:{
		x:0,
		y:0
	},
	rising:{
		left:false,
		right:false
	},
	falling:{
		left:false,
		right:false
	}
}

var canvas=document.createElement("canvas");
canvas.width=400;
canvas.height=456;
var c2d=canvas.getContext("2d");

var imagedata=c2d.createImageData(WIDTH,HEIGHT);
var imagebytes=new Uint8Array(imagedata.data.buffer);
window.Init=start;
var screenbuffer=new Int32Array(WIDTH*HEIGHT);

var dispcanvas=document.getElementById("cv");
var d2d=dispcanvas.getContext("2d");

window.fff=yb;
function yb(){
	console.log("DAN-BALL.jp (C) 2007 ha55ii");
	rescale(scale);
	//generate sin/cos table
	for(var i=0;i<513;i++){
		sincos[i]=new Float64Array(2);
	}
	for(i=0;i<512;i++){
		var d=360*i/512*pi/180;
		sincos[i][0]=Math.cos(d);
		sincos[i][1]=Math.sin(d);
	}
	sincos[i][0]=sincos[0][0];
	sincos[i][1]=sincos[0][1];
	//fill in a bunch of keyboard letter constants (not at all related to charcodes)
	Keys.rising.fill(false);
	Keys.rising1.fill(false);
	Keys.pressed.fill(false);
	Keys.LOWER.fill(0);
	Keys.UPPER.fill(0);
	
	for(i=0;i<10;i++){
		Keys.LOWER[48+i]=48+i;
	}
	for(i=0;i<9;i++){
		Keys.UPPER[49+i]=33+i;
	}
	for(i=0;i<4;i++){
		Keys.LOWER[37+i]=37+i;
		Keys.UPPER[37+i]=37+i;
	}
	Keys.LOWER[13]=Keys.UPPER[13]=13;
	Keys.LOWER[16]=Keys.UPPER[16]=16;
	Keys.LOWER[17]=Keys.UPPER[17]=17;
	Keys.LOWER[18]=Keys.UPPER[18]=18;
	Keys.LOWER[32]=Keys.UPPER[32]=32;
	Keys.LOWER[186]=58;
	Keys.UPPER[186]=42;
	Keys.LOWER[187]=59;
	Keys.UPPER[187]=43;
	Keys.LOWER[188]=44;
	Keys.UPPER[188]=60;
	Keys.LOWER[189]=45;
	Keys.UPPER[189]=61;
	Keys.LOWER[190]=46;
	Keys.UPPER[190]=62;
	Keys.LOWER[191]=47;
	Keys.UPPER[191]=63;
	Keys.LOWER[192]=64;
	Keys.UPPER[192]=96;
	Keys.LOWER[219]=91;
	Keys.UPPER[219]=123;
	Keys.LOWER[220]=92;
	Keys.UPPER[220]=124;
	Keys.LOWER[221]=93;
	Keys.UPPER[221]=125;
	Keys.LOWER[222]=94;
	Keys.UPPER[222]=126;
	Keys.LOWER[226]=92;
	Keys.UPPER[226]=95;
	Keys.LOWER[58]=58;
	Keys.UPPER[58]=42;
	Keys.LOWER[59]=59;
	Keys.UPPER[59]=43;
	Keys.LOWER[173]=45;
	Keys.UPPER[173]=61;
	Keys.LOWER[64]=64;
	Keys.UPPER[64]=96;
	Keys.LOWER[160]=94;
	Keys.UPPER[160]=126;
	//generate random numbers
	for(i=0;i<1024;i++){
		randomfloats[i]=i/1024;
	}
	for(i=0;i<1024;i++){
		var swapindex=floor(1024*Math.random());
		var temp=randomfloats[i];
		randomfloats[i]=randomfloats[swapindex];
		randomfloats[swapindex]=temp;
	}
	randomindex=floor(1024*Math.random())&0x3FF;
	randomstep=floor(512*Math.random())|1;
	//fill image buffer thing
	screenbuffer.fill(0);
	imagebytes.fill(0xFF);
}
function main(){
	if(request_animation_frame){
		request_animation_frame(main);
		Ef++;
		now=Date.now();
		var a=floor(60*(now-Gf)/1000+0.5);
		if(a<0||a>=60){
			Ef=0;
			fps=Hf;
			Hf=0;
			Sc=floor((2*Sc+If)/3);
			If=0;
			Gf=now;
			a=0;
		}//else if(a==Jf){
		//	return;
		//}
		Hf++;
		Jf=a;
	}
	mouse.rising.left=mouse.old.left==false&&mouse.left==true;
	mouse.falling.left=mouse.old.left==true&&mouse.left==false;
	mouse.rising.right=mouse.old.right==false&&mouse.right==true;
	mouse.falling.right=mouse.old.right==true&&mouse.right==false;
	mouse.old.left=mouse.left;
	mouse.old.right=mouse.right;
	risingmouseclick=!(mouse.falling.left|mouse.old.left|mouse.falling.right|mouse.old.right);
	fallingmousedirection=mouse.falling.left?1:mouse.falling.right?-1:0;
	mouse.older.x=mouse.old.x;
	mouse.older.y=mouse.old.y;
	mouse.old.x=mouse.x;
	mouse.old.y=mouse.y;
	//new key presses to handle
	for(a=0;a<256;a++){
		Keys.rising[a]=Keys.rising1[a];
		Keys.rising1[a]=false;
	}
	randomindex=randomindex+floor(1024*Math.random())&0x3FF;
	randomstep=floor(512*Math.random())|1;
	Ob();
	var d,b=WIDTH*HEIGHT;
	if(Menu_zoomLevel==0){
		d=a=0;
	}else{
		var x0=floor(zoomx)+8
		var y0=floor(zoomy)+8;
		for(var y=0;y<300;y++){
			d=4*((y+8)*WIDTH+8)
			a=(y0+(y>>Menu_zoomLevel))*WIDTH+(x0)
			for(var x=0;x<400;x++){
				var xy=a+(x>>Menu_zoomLevel);
				imagebytes[d++]=screenbuffer[xy]>>16&0xFF;
				imagebytes[d++]=screenbuffer[xy]>>8&0xFF;
				imagebytes[d++]=screenbuffer[xy]&0xFF;
				d++;
			}
		}
		a=308*WIDTH;
		d=4*a
	}
	//draw rest of image (entire image at scale=1)
	for(;a<b;a++){
		imagebytes[d++]=screenbuffer[a]>>16&0xFF;
		imagebytes[d++]=screenbuffer[a]>>8&0xFF;
		imagebytes[d++]=screenbuffer[a]&0xFF;
		d++;
	}
	
	if(scale==1){
		d2d.putImageData(imagedata,-8,-8,8,8,WIDTH-16,HEIGHT-8);
	}else{
		c2d.putImageData(imagedata,-8,-8,8,8,WIDTH-16,HEIGHT-8);
		d2d.drawImage(canvas,0,0);
	}
	
	if(request_animation_frame){
		If+=Date.now()-now;
	}else{
		setTimeout(main,Eb());
	}
}

function rescale(newscale){
	scale=newscale;
	dispcanvas.width=400*scale;
	dispcanvas.height=456*scale;
	d2d.setTransform(scale,0,0,scale,0,0);
	d2d.imageSmoothingEnabled=false;
	d2d.msImageSmoothingEnabled=false;
}

var request_animation_frame=window.requestAnimationFrame||window.mozRequestAnimationFrame||window.webkitRequestAnimationFrame||window.oRequestAnimationFrame||window.msRequestAnimationFrame
var Ef=0,Jf=0,Hf=0,fps=0,If=0,Sc=0
var now=Date.now(),Gf=now,Pf=now+Of,Qf=now,Rf=0;
function Eb(){
	now=Date.now();
	var a=clamp(Pf-now,5,Of);
	Hf++;
	Rf++;
	If+=a;
	Pf+=Of;
	if(now+a>=Qf||now<Gf){
		Sc=Sc+If>>1;
		If=0;
		fps=Hf;
		Hf=0;
		Pf=now+Of;
		Qf=now+1000;
	}
	Gf=now;
	return a;
}
var imagesloaded=0;
function PGImage(){
	this.image=0;
	this.file="";
	this.previous=0;
	this.c2d=0;
	this.canvas=0;
	this.g=0;
	this.canvascreated=0;
	this.imagedata=0;
	this.height=0;
	this.width=0;
}

function setsize(image,width,height){
	image.width=width;
	image.height=height;
	image.imagedata=new Int32Array(width*height);
}

PGImage.prototype.loadimage=function(filename){
	if(this.file!=filename){
		imagesloaded++;
		this.file=filename;
		this.image=new Image;
		this.image.src="./data/"+filename+"?9.2";
		delete this.imagedata;
		this.canvascreated=this.imagedata=0;
	}
};

function readimagedata(a){
	if(a.canvascreated==0&&a.image.complete){
		imagesloaded--;
		var d=a.image.width,b=a.image.height;
		if(d==0||b==0){
			delete a.image
			a.file=""
			throw "ERROR";
		}
		var c=document.createElement("canvas");
		c.width=d;
		c.height=b;
		c=c.getContext("2d");
		c.drawImage(a.image,0,0);
		c=c.getImageData(0,0,d,b).data;
		setsize(a,d,b);
		var b=c.length;
		for(var d=0;d<b;d+=4){
			a.imagedata[d>>2]=
				c[d+3]==0?
					-1
				:
					c[d+0]<<16|c[d+1]<<8|c[d+2];
		}
		delete a.image;
		a.canvascreated=1;
	}
}
function commontext(a,text){
	shittext(a,text,"sans-serif",0b00,14);
}
function shittext(a,text,font,style,size){
	if(a.canvascreated==0){
		a.canvascreated=1;
		setsize(a,WIDTH,128);
		a.canvas=document.createElement("canvas");
		a.canvas.width=a.width;
		a.canvas.height=a.height;
		a.c2d=a.canvas.getContext("2d");
	}
	var fontstyle=text+font+style+size;
	if(a.previous!=fontstyle){
		a.previous=fontstyle;
		a.c2d.fillStyle="#000000";
		a.c2d.fillRect(0,0,a.width,a.height);
		var fontstyle="";
		if(style&0b10){
			fontstyle+="italic ";
		}
		if(style&0b01){
			fontstyle+="bold ";
		}
		fontstyle+=(size+"px ")+font;
		a.c2d.font=fontstyle;
		a.c2d.fillStyle="#FFFFFF";
		a.c2d.fillText(text,0,size);
		var imagedata=a.c2d.getImageData(0,0,a.width,a.height).data;
		
		var imagedatalength=imagedata.length;
		for(var d=0;d<imagedatalength;d+=4){
			if(imagedata[d]+imagedata[d+1]+imagedata[d+2]>=64*3){
				a.imagedata[floor(d/4)]=0xFFFFFF
			}else{
				a.imagedata[floor(d/4)]=-1
			}
		}
		var b;
		d=0;
		a.g=0;
		for(b=0;b<a.height;b++){
			for(var c=0;c<a.width;c++){
				if(a.imagedata[d]==0xFFFFFF&&a.g<=c){
					a.g=c+1;
				}
				d++;
			}
		}
	}
}
const prespacing=[[0,2,0,0,1,0,0,2,2,1,1,1,2,1,2,0,0,0,0,0,0,0,0,0,0,0,2,2,0,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,1,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,3,1,0],
[0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0]]
const postspacing=[[0,1,1,0,0,0,0,2,1,2,0,0,2,1,2,0,0,0,0,0,0,0,0,0,0,0,2,2,0,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,2,1,0,2,0,0,0,0,0,0,0,0,2,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,0],[0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0]]
var k=new FontImage;
function FontImage(){
	this.image=new PGImage;
	this.j=this.m=this.p=this.h=0;
}
FontImage.prototype.loadimage=function(filename,d,b){
	this.image.loadimage(filename);
	this.h=d;
	this.p=b;
	this.j=this.m=0;
};
FontImage.prototype.drawtext=function(x,y,text,color,e){
	var n,w,z=WIDTH-this.h,v=this.image.width-this.h
	var Y=color>-1?0xFFFFFF:1
	var Ka=e>-1?0:1
	var textlength=text.length;
	for(var i=0;i<textlength;i++,x+=this.h+this.m){
		var character=text.charCodeAt(i)-32;
		if(character!=0){
			if(character>=96){ //char >=128
				character=31; //set to '?'
			}
			if(this.j!=0){
				x-=prespacing[this.j-1][character];
			}
			w=character*this.h;
			n=y*WIDTH+x;
			for(var q=0;q<this.p;q++,n+=z,w+=v){
				for(var g=0;g<this.h;g++,n++,w++){
					var yy=this.image.imagedata[w];
					if(yy==Y){
						screenbuffer[n]=color
					}else if(yy==Ka){
						screenbuffer[n]=e
					}
				}
			}
			if(this.j!=0){
				x-=postspacing[this.j-1][character]
			}
		}
	}
	this.j=0;
};
function centeredtext(x,y,text,color){
	x-=text.length*(k.h+k.m)>>1;
	y-=k.p>>1;
	k.drawtext(x,y,text,color,0);
}
function spacedtext(x,y,text,color,e,spacing){
	k.m=spacing;
	k.drawtext(x,y,text,color,e);
	k.m=0;
}
var blendmode=0;
function composite(basecolor,newcolor,alpha){
	var red=0,green=0,blue=0;
	switch(blendmode){
	case 1:
		c=basecolor>>16&0xFF;
		red=(((newcolor>>16&0xFF)-c)*alpha>>8)+c;
		c=basecolor>>8&0xFF;
		green=(((newcolor>>8&0xFF)-c)*alpha>>8)+c;
		c=basecolor&0xFF;
		blue=(((newcolor&0xFF)-c)*alpha>>8)+c;
	break;case 2:
		red=((newcolor>>16&0xFF)*alpha>>8)+(basecolor>>16&0xFF);
		if(red>0xFF){
			red=0xFF;
		}
		green=((newcolor>>8&0xFF)*alpha>>8)+(basecolor>>8&0xFF)
		if(green>0xFF){
			green=0xFF;
		}
		blue=((newcolor&0xFF)*alpha>>8)+(basecolor&0xFF)
		if(blue>0xFF){
			blue=0xFF;
		}
	break;case 3:
		red=(basecolor>>16&0xFF)-((newcolor>>16&0xFF)*alpha>>8)
		if(red<0){
			red=0;
		}
		green=(basecolor>>8&0xFF)-((newcolor>>8&0xFF)*alpha>>8)
		if(green<0){
			green=0;
		}
		blue=(basecolor&0xFF)-((newcolor&0xFF)*alpha>>8)
		if(blue<0){
			blue=0;
		}
	break;case 4:
		red=(newcolor>>16&0xFF)*(basecolor>>16&0xFF)>>8
		green=(newcolor>>8&0xFF)*(basecolor>>8&0xFF)>>8
		blue=(newcolor&0xFF)*(basecolor&0xFF)>>8
	break;case 5:
		c=basecolor>>16&0xFF
		red=c+((newcolor>>16&0xFF)*c*alpha>>16)
		if(red>0xFF){
			red=0xFF;
		}
		c=basecolor>>8&0xFF
		green=c+((newcolor>>8&0xFF)*c*alpha>>16)
		if(green>0xFF){
			green=0xFF;
		}
		c=basecolor&0xFF
		blue=c+((newcolor&0xFF)*c*alpha>>16)
		if(blue>0xFF){
			blue=0xFF;
		}
	break;case 6:
		c=basecolor>>16&0xFF
		red=c+(alpha-(2*c*alpha>>8))
		c=basecolor>>8&0xFF
		green=c+(alpha-(2*c*alpha>>8))
		c=basecolor&0xFF
		blue=c+(alpha-(2*c*alpha>>8));
	}
	return red<<16|green<<8|blue;
}
var Yf=0;

function line(x1,y1,x2,y2,color){
	x1=floor(x1);
	y1=floor(y1);
	x2-=x1;
	y2-=y1;
	var f,g;
	if(abs(x2)>=abs(y2)){
		g=floor(abs(x2));
		if(g!=0){
			y2=floor(65536*y2/g);
		}
		x2=(x2>=0)?65536:-65536;
	}else{
		g=floor(abs(y2));
		if(g!=0){
			x2=floor(65536*x2/g);
		}
		y2=(y2>=0)?65536:-65536;
	}
	x1=floor(65536*x1)+32768;
	for(y1=floor(65536*y1)+32768;g>=0;g--,x1+=x2,y1+=y2){
		if(x1>=0 && x1>>16<WIDTH && y1>=0 && y1>>16<HEIGHT){
			f=(y1>>16)*WIDTH+(x1>>16);
			screenbuffer[f]= blendmode==0 ? color : composite(screenbuffer[f],color,color>>24&0xFF);
		}
	}
}
//unfilled rectangle
function box(x,y,width,height,color){
	line(x,y,x+width-1,y,color);
	line(x,y+height-1,x+width-1,y+height-1,color);
	line(x,y,x,y+height-1,color);
	line(x+width-1,y,x+width-1,y+height-1,color);
}
//filled rectangle
function rectangle(x,y,width,height,color){
	var f;
	width=x+width>WIDTH?WIDTH:~~(x+width);
	height=y+height>HEIGHT?HEIGHT:~~(y+height);
	x=x<0?0:~~x;
	y=(y<0?0:~~y)*WIDTH+x;
	f=WIDTH-(width-x);
	width=y+width-x;
	height*=WIDTH;
	if(blendmode==0){
		for(;y<height;y+=f,width+=WIDTH){
			for(;y<width;y++){
				screenbuffer[y]=color;
			}
		}
	}else{
		for(;y<height;y+=f,width+=WIDTH){
			for(;y<width;y++){
				screenbuffer[y]=composite(screenbuffer[y],color,color>>24&0xFF);
			}
		}
	}
}
//uhhh
function ad(image,d,b,c,e,f,g,color){
	var n,r,w,y,z,v;
	if(c!=0&&e!=0){
		f=floor((f<<8)/c);
		g=floor((g<<8)/e);
		r=n=0;
		if(d<0){
			n+=f*-d
		}
		if(b<0){
			r+=g*-b;
		}
		c=(d+c>WIDTH)?WIDTH:floor(d+c);
		e=(b+e>HEIGHT)?HEIGHT:floor(b+e);
		d=(d<0)?0:floor(d);
		b=(b<0)?0:floor(b);
		var alpha=color>>24&0xFF,red=color>>16&0xFF,green=color>>8&0xFF,blue=color&0xFF,Ta,pa;
		if(Yf==0){
			for(;b<e;b++,r+=g){
				y=b*WIDTH+d;
				z=((r>>8)*image.width<<8)+n;
				for(w=d;w<c;w++,y++,z+=f){
					v=image.imagedata[z>>8]
					if(v!=-1){
						var q=red*(v>>16&0xFF)>>8;
						Ta=green*(v>>8&0xFF)>>8;
						pa=blue*(v&0xFF)>>8;
						if(blendmode==0){
							screenbuffer[y]=q<<16|Ta<<8|pa
						}else if(blendmode==1){
							v=screenbuffer[y]>>16&0xFF;
							q=((q-v)*alpha>>8)+v;
							v=screenbuffer[y]>>8&0xFF;
							Ta=((Ta-v)*alpha>>8)+v;
							v=screenbuffer[y]&0xFF;
							pa=((pa-v)*alpha>>8)+v;
							screenbuffer[y]=q<<16|Ta<<8|pa;
						}else if(blendmode==2){
							q=(q*alpha>>8)+(screenbuffer[y]>>16&0xFF);
							if(q>0xFF){
								q=0xFF;
							}
							Ta=(Ta*alpha>>8)+(screenbuffer[y]>>8&0xFF);
							if(Ta>0xFF){
								Ta=0xFF;
							}
							pa=(pa*alpha>>8)+(screenbuffer[y]&0xFF);
							if(pa>0xFF){
								pa=0xFF;
							}
							screenbuffer[y]=q<<16|Ta<<8|pa;
						}else if(blendmode==5){
							v=screenbuffer[y]>>16&0xFF;
							q=v+(q*v*alpha>>16);
							if(q>0xFF){
								q=0xFF;
							}
							v=screenbuffer[y]>>8&0xFF;
							Ta=v+(Ta*v*alpha>>16);
							if(Ta>0xFF){
								Ta=0xFF;
							}
							v=screenbuffer[y]&0xFF;
							pa=v+(pa*v*alpha>>16);
							if(pa>0xFF){
								pa=0xFF;
							}
							screenbuffer[y]=q<<16|Ta<<8|pa;
						}
					}
				}
			}
		}else if(Yf==1){
			for(;b<e;b++,r+=g){
				for(y=b*WIDTH+d,z=((r>>8)*image.width<<8)+n,w=d;w<c;w++,y++,z+=f){
					v=alpha*(image.imagedata[z>>8]&0xFF)>>8;
					if(v!=0){
						screenbuffer[y]=composite(screenbuffer[y],q,v);
					}
				}
			}
		}else if(Yf==2){
			for(;b<e;b++,r+=g){
				for(y=b*WIDTH+d,z=((r>>8)*image.width<<8)+n,w=d;w<c;w++,y++,z+=f){
					v=image.imagedata[z>>8];
					if(v!=0){
						q=v>>16&0xFF
						Ta=v>>8&0xFF
						pa=v&0xFF
						screenbuffer[y]=(q==Ta&&Ta==pa) ? (red*q>>8<<16|green*Ta>>8<<8|blue*pa>>8) : (q<<16|Ta<<8|pa)
					}
				}
			}
		}
	}
}
function Xc(a){
	var d=Ia.g;
	ad(Ia,208-(d>>1),a-8,d,16,Ia.g,16,0xFF000000);
}
var ee=new Vector,risingmouseclick=false,fallingmousedirection=0;
function mouseinside(x,y,width,height){
	return !(mouse.old.x<x||mouse.old.x>=x+width||mouse.old.y<y||mouse.old.y>=y+height);
}
function getmousepos(event){
	var canvasrect=dispcanvas.getBoundingClientRect();
	mouse.x=Math.round((event.clientX-canvasrect.left)/scale);
	mouse.y=Math.round((event.clientY-canvasrect.top)/scale);
}
document.onwheel=function(event){
	if(focused){
		return false;
	}
}

document.onmousemove=getmousepos;
document.onmousedown=function(event){
	getmousepos(event);
	focused=false;
	if(mouse.x>=0 && mouse.x<WIDTH && mouse.y>=0 && mouse.y<HEIGHT){
		focused=true;
		if(event.button==0){
			mouse.left=true;
		}
		if(event.button==1){
			mouse.middle=true;
		}
		if(event.button==2){
			mouse.right=true;
		}
		return false;
	}
};
document.onmouseup=function(event){
	getmousepos(event);
	if(event.button==0){
		mouse.left=false;
	}
	if(event.button==1){
		mouse.middle=false;
	}
	if(event.button==2){
		mouse.right=false;
	}
};
document.oncontextmenu=function(){
	if(focused){
		return false;
	}
};
function gettouchxy(event){
	var x=0,y=0;
	for(element=dispcanvas;element!==null;element=element.offsetParent){
		x+=element.offsetLeft;
		y+=element.offsetTop;
	}
	event=event.touches;
	mouse.x=floor((event[0].pageX-x)/scale);
	mouse.y=floor((event[0].pageY-y)/scale);
}
document.ontouchstart=function(event){
	gettouchxy(event);
	focused=mouse.right=mouse.left=false;
	if(mouse.x>=0 && mouse.x<WIDTH && mouse.y>=0 && mouse.y<HEIGHT){
		mouse.left=focused=true;
		if(event.touches.length>1){
			mouse.right=true;
		}
		return false;
	}
};
document.ontouchmove=function(event){
	gettouchxy(event);
	if(focused){
		return false;
	}
};
document.ontouchend=function(event){
	if(event.touches.length<1){
		mouse.left=false;
	}
	mouse.right=false;
	if(focused){
		return false;
	}
};
document.ontouchcancel=function(){
	mouse.right=mouse.left=focused=false;
};
document.onkeydown=function(event){
	var key=keytochar(event.keyCode,event.shiftKey);
	if(key>=0&&key<256){
		Keys.pressed[key]=true;
		Keys.rising1[key]=true;
	}
	if(key!=0&&focused){
		return false;
	}
};
document.onkeyup=function(event){
	var key=keytochar(event.keyCode,event.shiftKey);
	if(key>=0&&key<256){
		Keys.pressed[key]=false;
	}
	if(key!=0&&focused){
		return false;
	}
};

function keytochar(keycode,shiftkey){
	if(keycode>=65&&keycode<=90){
		if(!shiftkey){
			return keycode+32;
		}
	}else{
		return shiftkey?Keys.UPPER[keycode]:Keys.LOWER[keycode];
	}
}

var focused=false;
function input(a,d){
	var b=null;
	try{
		b=prompt(a,d);
	}catch(c){
		alert("ERROR");
	}
	return b;
}
var responselines=Array(100),Hb=0
function send(url,data){
	responselines.fill("");
	Hb=0;
	try{
		var request=new XMLHttpRequest;
		request.onload=function(){
			var matches=request.responseText.match(/^=.*?$/gm);
			for(var i=0;i<matches.length;i++){
				responselines[i]=matches[i].substring(1);
			}
			Hb=1;
		}
		request.onerror=function(){
			Hb=-1;
		}
		request.open("POST",url,false);
		request.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
		request.send(data);
		return request.responseText;
	}catch(error){
		Hb=-2;
	}
	return "";
}

function Vector(){
	this.y=0;
	this.x=0;
}
Vector.prototype.copy=function(vector){
	this.x=vector.x;
	this.y=vector.y;
	return this;
};
Vector.prototype.set=function(x,y){
	this.x=x;
	this.y=y;
}
Vector.prototype.add=function(addend){
	this.x+=addend.x;
	this.y+=addend.y;
	return this;
};
Vector.prototype.sub=function(minuend){
	this.x-=minuend.x;
	this.y-=minuend.y;
	return this;
};
Vector.prototype.sub2=function(subtrahend,minuend){
	this.x=subtrahend.x-minuend.x;
	this.y=subtrahend.y-minuend.y;
}
Vector.prototype.mul=function(multiplier){
	this.x*=multiplier;
	this.y*=multiplier;
}
Vector.prototype.mul2=function(multiplicand,multiplier){
	this.x=multiplicand.x*multiplier;
	this.y=multiplicand.y*multiplier;
}
Vector.prototype.fastdist=function(){
	return Vector.fastdist(this.x,this.y);
}
Vector.prototype.dist=function(){
	return Math.sqrt(this.x*this.x+this.y*this.y);
}
Vector.prototype.fastnormalize=function(){
	var magnitude=Vector.fastdist(this.x,this.y);
	if(magnitude==0){
		return 0;
	}
	this.x/=magnitude;
	this.y/=magnitude;
	return magnitude;
}
Vector.prototype.normalize=function(){
	var magnitude=this.dist();
	if(magnitude!=0){
		this.x/=magnitude;
		this.y/=magnitude;
	}
}
Vector.prototype.angle=function(){
	var angle=Math.acos(this.x/this.dist());
	if(this.y>0){
		angle=tau-angle;
	}
	return angle;
}
Vector.fastdist=function(x,y){
	x=abs(x);
	y=abs(y);
	if(x>=y){
		return 0.9604*x+0.3978*y;
	}else{
		return 0.9604*y+0.3978*x;
	}
}
Vector.temp=new Vector;

Vector.prototype.swap=function(vector){
	Vector.temp.copy(vector);
	vector.copy(this);
	this.copy(Vector.temp);
}

var randomfloats=new Float32Array(1024),randomindex=0,randomstep=0;
function random(a){
	randomindex+=randomstep;
	randomindex&=0x3FF;
	return randomfloats[randomindex]*a;
}
function random2(min,max){
	randomindex+=randomstep;
	randomindex&=0x3FF;
	return randomfloats[randomindex]*(max-min)+min;
}
function randomint(a){
	randomindex+=randomstep;
	randomindex&=0x3FF;
	return ~~(randomfloats[randomindex]*a);
}
var sincos=Array(513),pi=3.1415927,tau=6.2831855;
function clamp(value,min,max){
	if(value<min){
		return min;
	}else if(value>max){
		return max;
	}else{
		return value;
	}
}
function wrap(value,max){
	if(value<0){
		return max;
	}else if(value>max){
		return 0;
	}else{
		return value;
	}
}
