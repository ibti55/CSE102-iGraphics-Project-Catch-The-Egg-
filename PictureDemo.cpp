   /*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
# include <time.h>
# include <Windows.h>
# include <iostream>
# include <MMSystem.h>

using namespace std;

int n,m,s=0,tim=500,upper=1250,lower=60,pop_up_text=0,ti=0,sorry=0,resume=0,play=0,mm=1,t=0,pur=0,gol=1,w=1,p=0,fall=40,slowfall=0,slowtime=10,ins=0;
char score[80],ti1[80],data[80];

struct coordinate{
    float x;
    float y;
}golden_egg,blue_egg,white_egg,pic,time1,poop,murgi1,murgi2,eggfall,timeover;

/*
	function iDraw() is called again and again by the system.
*/
void goldegg(){
        iFilledEllipse(golden_egg.x ,golden_egg.y , 15,30);
}

void blueegg()
{
        iFilledEllipse(blue_egg.x ,blue_egg.y , 15,30);
}

void whiteegg()
{
        iFilledEllipse(white_egg.x ,white_egg.y , 15,30);
}


void iDraw()
{
	//place your drawing codes here
    iClear();
    if(mm)
        iShowBMP(0, 0, "mm1.bmp");

    if(ins)
        iShowBMP(0, 0, "Instructions.bmp");

    if(ti)
        iShowBMP(0, 0, "duration.bmp");

    if(sorry)
        iShowBMP(0, 0, "sorry.bmp");

    if(play)
    {
        iShowBMP(0, 0, "farm.bmp");
        iSetColor(0,0,0);
        iLine(0,890,1300,890);
        iLine(0,810,1300,810);
        if(gol)
            iShowBMP2(murgi1.x-45, 880, "chicken.bmp",0xFFFFFF);
        iSetColor(255, 215, 0);
        goldegg();
        if(pur)
            iShowBMP2(murgi1.x-45, 880, "chicken.bmp",0xFFFFFF);
        iSetColor(0, 0, 255);
        blueegg();
        if(w)
            iShowBMP2(murgi2.x-45, 800, "chicken.bmp",0xFFFFFF);
        iSetColor(255, 255, 255);
        whiteegg();
        if(p)
            iShowBMP2(murgi2.x-45, 800, "chicken.bmp",0xFFFFFF);
        iShowBMP2(poop.x, poop.y, "Shit.bmp",0xFFFFFF);

        iShowBMP2(time1.x, time1.y, "stopwatch.bmp",0xFFFFFF);
        iShowBMP2(eggfall.x, eggfall.y, "stopwatch2.bmp",0xFFFFFF);
        iShowBMP2(timeover.x, timeover.y, "timeover.bmp",0xFFFFFF);
        iShowBMP2(pic.x, pic.y, "b1.bmp",0xFFFFFF);

        if((pic.x<=golden_egg.x&&(pic.x+90)>=golden_egg.x)&&(pic.y<=golden_egg.y&&(pic.y+97)>=golden_egg.y)){
            s+=10;
            golden_egg.y=0;
        }
        if((pic.x<=blue_egg.x&&(pic.x+90)>=blue_egg.x)&&(pic.y<=blue_egg.y&&(pic.y+97)>=blue_egg.y)){
            s+=5;
            blue_egg.y=0;
        }
        if((pic.x<=white_egg.x&&(pic.x+90)>=white_egg.x)&&(pic.y<=white_egg.y&&(pic.y+97)>=white_egg.y)){
            s+=1;
            white_egg.y=0;
        }
        if((pic.x<=time1.x&&(pic.x+90)>=time1.x)&&(pic.y<=time1.y&&(pic.y+97)>=time1.y)){
            tim+=10;
            time1.y=0;
        }
        if((pic.x<=poop.x&&(pic.x+90)>=poop.x)&&(pic.y<=poop.y&&(pic.y+97)>=poop.y)){
            s-=10;
            poop.y=0;
        }
        if((pic.x<=eggfall.x&&(pic.x+90)>=eggfall.x)&&(pic.y<=eggfall.y&&(pic.y+97)>=eggfall.y)){
            slowfall=1;
            eggfall.y=0;
        }
        if((pic.x<=timeover.x&&(pic.x+90)>=timeover.x)&&(pic.y<=timeover.y&&(pic.y+97)>=timeover.y)){
            tim=0;
        }
        sprintf(score,"Score:%d",s);
        iSetColor(255, 0, 255);
        iText(650, 1040, score,GLUT_BITMAP_TIMES_ROMAN_24);
        sprintf(ti1,"Time:%d",tim);
        iSetColor(255, 0, 255);
        iText(650, 1070, ti1,GLUT_BITMAP_TIMES_ROMAN_24);

        if(pop_up_text)
        {
            iSetColor(255, 255, 255);
            iFilledRectangle(500,500,270,100);
            iSetColor(0, 0, 0);
            iText(505,565,"DO YOU WANT TO SAVE YOUR SCORE?");
            iText(570,535,"YES(a)");
            iText(670,535,"NO(x)");
        }
    }

    if(resume)
        iShowBMP(0, 0, "resume1.bmp");

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	if(mx>0&&mx<1300)
            pic.x=mx;
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 's')
	{
	    if(mm)
        {
            mm=0;
            ti=1;
            play=0;
            resume=0;
            ins=0;
            sorry=0;
            iResumeTimer(0);
            iResumeTimer(1);
            iResumeTimer(2);
            iResumeTimer(3);
            iResumeTimer(4);
            iResumeTimer(5);
            iResumeTimer(6);
            iResumeTimer(7);
        }
	}
    if(key == 'l')
	{
	    if(mm)
        {
            FILE * fptr;
            fptr=fopen("file1.txt","r");
            fscanf(fptr,"%d %d",&s,&tim);
            fclose(fptr);
            if(!tim)
            {
                sorry=1;
                mm=0;
                ti=0;
                play=0;
                resume=0;
                ins=0;
            }
            else
            {
                sorry=0;
                mm=0;
                ti=0;
                play=1;
                resume=0;
                ins=0;
                iResumeTimer(0);
                iResumeTimer(1);
                iResumeTimer(2);
                iResumeTimer(3);
                iResumeTimer(4);
                iResumeTimer(5);
                iResumeTimer(6);
                iResumeTimer(7);
            }

        }

	}
	if(key == 'e')
	{
		if(resume)
        {
            mm=0;
            ti=0;
            play=1;
            resume=0;
            ins=0;
            sorry=0;
            iResumeTimer(0);
            iResumeTimer(1);
            iResumeTimer(2);
            iResumeTimer(3);
            iResumeTimer(4);
            iResumeTimer(5);
            iResumeTimer(6);
            iResumeTimer(7);
        }
	}
	if(key == 'a')
	{
	    if(resume||pop_up_text)
        {
            FILE * fptr;
            fptr=fopen("file1.txt","w");
            fprintf(fptr,"%d %d",s,tim);
            fclose(fptr);
            exit(0);
        }
	}
	if(key == 'p')
	{
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		iPauseTimer(3);
		iPauseTimer(4);
		iPauseTimer(5);
		iPauseTimer(6);
		iPauseTimer(7);
		if(play==1&&!pop_up_text)
        {
            mm=0;
            ti=0;
            play=0;
            resume=1;
            ins=0;
            sorry=0;
        }
	}

	if(key == 'x')
    {
        if(mm||resume||pop_up_text)
        {
            tim=0;
            FILE * fptr;
            fptr=fopen("file1.txt","w");
            fprintf(fptr,"%d %d",s,tim);
            fclose(fptr);
            exit(0);
        }
    }
	if(key == 'm')
	{   if(!play)
        {
            mm=1;
            ti=0;
            play=0;
            resume=0;
            s=0;
            ins=0;
            sorry=0;
        }
	}
	if(key == 'i')
	{
       if(mm)
       {
            mm=0;
            ti=0;
            play=0;
            resume=0;
            ins=1;
       }
	}
	if(key == '1')
    {
       if(ti)
        {
            tim=60;
            mm=0;
            ti=0;
            play=1;
            resume=0;
            ins=0;
            s=0;
            sorry=0;
        }
    }
    if(key == '2')
    {
       if(ti)
        {
            tim=120;
            mm=0;
            ti=0;
            play=1;
            resume=0;
            ins=0;
            s=0;
            sorry=0;
        }
    }

	if(key == '3')
    {
       if(ti)
        {
            tim=180;
            mm=0;
            ti=0;
            play=1;
            resume=0;
            ins=0;
            s=0;
            sorry=0;
        }
    }

    if(key == '4')
    {
        if(ti)
        {
            tim=240;
            mm=0;
            ti=0;
            play=1;
            resume=0;
            ins=0;
            s=0;
            sorry=0;
        }
    }

    if(key == '5')
    {
        if(ti)
        {
            tim=300;
            mm=0;
            ti=0;
            play=1;
            resume=0;
            ins=0;
            s=0;
            sorry=0;
        }
    }
		//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		//exit(0);
	}
	if(key == GLUT_KEY_LEFT)
	{
	    if(pic.x>0)
            pic.x-=45;
	}
	if(key == GLUT_KEY_RIGHT)
	{
	    if(pic.x<1300)
            pic.x+=45;
	}
	if(key == GLUT_KEY_UP)
	{
		//pic.y+=40;
	}
	if(key == GLUT_KEY_DOWN)
	{
		//pic.y-=40;
	}
	//place your codes for other keys here
}

void golden_egg_change()
{
    if(golden_egg.y<=0&&golden_egg.y>=-60)
    {
        pur=1;
        gol=0;
        golden_egg.x=(rand() % (upper - lower + 1)) + lower;
        murgi1.x=blue_egg.x;
        blue_egg.y=880;
    }
    if(tim<=285&&tim>=275)
        golden_egg.x-=4;
    if(tim<=265&&tim>=255)
        golden_egg.x+=4;
    if(tim<=225&&tim>=215)
        golden_egg.x-=4;
    if(tim<=205&&tim>=195)
        golden_egg.x+=4;
    if(tim<=165&&tim>=155)
        golden_egg.x-=4;
    if(tim<=145&&tim>=135)
        golden_egg.x+=4;
    if(tim<=105&&tim>=95)
        golden_egg.x-=4;
    if(tim<=85&&tim>=75)
        golden_egg.x+=4;
    if(tim<=45&&tim>=35)
        golden_egg.x-=4;
    if(tim<=25&&tim>=15)
        golden_egg.x+=4;
    if(pur)
        golden_egg.y=-400;
    golden_egg.y-=fall;
}

void blue_egg_change()
{

    if(blue_egg.y<=0&&blue_egg.y>=-60){
        pur=0;
        gol=1;
        blue_egg.x=(rand() % (upper - lower + 1)) + lower;
        murgi1.x=golden_egg.x;
        golden_egg.y=880;
    }
    if(tim<=285&&tim>=275)
        blue_egg.x-=4;
    if(tim<=265&&tim>=255)
        blue_egg.x+=4;
    if(tim<=225&&tim>=215)
        blue_egg.x-=4;
    if(tim<=205&&tim>=195)
        blue_egg.x+=4;
    if(tim<=165&&tim>=155)
        blue_egg.x-=4;
    if(tim<=145&&tim>=135)
        blue_egg.x+=4;
    if(tim<=105&&tim>=95)
        blue_egg.x-=4;
    if(tim<=85&&tim>=75)
        blue_egg.x+=4;
    if(tim<=45&&tim>=35)
        blue_egg.x-=4;
    if(tim<=25&&tim>=15)
        blue_egg.x+=4;
    if(gol)
        blue_egg.y=-400;
    blue_egg.y-=fall;
}

void white_egg_change()
{
    if(white_egg.y<=0&&white_egg.y>=-60){
        w=0;
        p=1;
        white_egg.x=(rand() % (upper - lower + 1)) + lower;
        murgi2.x=poop.x;
        poop.y=800;
    }
    if(tim<=285&&tim>=275)
        white_egg.x-=4;
    if(tim<=265&&tim>=255)
        white_egg.x+=4;
    if(tim<=225&&tim>=215)
        white_egg.x-=4;
    if(tim<=205&&tim>=195)
        white_egg.x+=4;
    if(tim<=165&&tim>=155)
        white_egg.x-=4;
    if(tim<=145&&tim>=135)
        white_egg.x+=4;
    if(tim<=105&&tim>=95)
        white_egg.x-=4;
    if(tim<=85&&tim>=75)
        white_egg.x+=4;
    if(tim<=45&&tim>=35)
        white_egg.x-=4;
    if(tim<=25&&tim>=15)
        white_egg.x+=4;
    if(p)
        white_egg.y=-400;
    white_egg.y-=fall;
}

void poop_change()
{
    if(poop.y<=0&&poop.y>=-60){
        w=1;
        p=0;
        poop.x=(rand() % (upper - lower + 1)) + lower;
        murgi2.x=white_egg.x;
        white_egg.y=800;
    }
    if(tim<=285&&tim>=275)
        poop.x-=4;
    if(tim<=265&&tim>=255)
        poop.x+=4;
    if(tim<=225&&tim>=215)
        poop.x-=4;
    if(tim<=205&&tim>=195)
        poop.x+=4;
    if(tim<=165&&tim>=155)
        poop.x-=4;
    if(tim<=145&&tim>=135)
        poop.x+=4;
    if(tim<=105&&tim>=95)
        poop.x-=4;
    if(tim<=85&&tim>=75)
        poop.x+=4;
    if(tim<=45&&tim>=35)
        poop.x-=4;
    if(tim<=25&&tim>=15)
        poop.x+=4;
    if(w)
        poop.y=-400;
    poop.y-=fall;
}

void time_change()
{
    if(time1.y<=0){
        time1.x=(rand() % (upper - lower + 1)) + lower;
        time1.y=3040;
    }
    if(tim<=285&&tim>=275)
        time1.x-=4;
    if(tim<=265&&tim>=255)
        time1.x+=4;
    if(tim<=225&&tim>=215)
        time1.x-=4;
    if(tim<=205&&tim>=195)
        time1.x+=4;
    if(tim<=165&&tim>=155)
        time1.x-=4;
    if(tim<=145&&tim>=135)
        time1.x+=4;
    if(tim<=105&&tim>=95)
        time1.x-=4;
    if(tim<=85&&tim>=75)
        time1.x+=4;
    if(tim<=45&&tim>=35)
        time1.x-=4;
    if(tim<=25&&tim>=15)
        time1.x+=4;
    time1.y-=40;
}

void timeover_change()
{
    if(timeover.y<=0){
        timeover.x=(rand() % (upper - lower + 1)) + lower;
        timeover.y=6080;
    }
    if(tim<=285&&tim>=275)
        timeover.x-=4;
    if(tim<=265&&tim>=255)
        timeover.x+=4;
    if(tim<=225&&tim>=215)
        timeover.x-=4;
    if(tim<=205&&tim>=195)
        timeover.x+=4;
    if(tim<=165&&tim>=155)
        timeover.x-=4;
    if(tim<=145&&tim>=135)
        timeover.x+=4;
    if(tim<=105&&tim>=95)
        timeover.x-=4;
    if(tim<=85&&tim>=75)
        timeover.x+=4;
    if(tim<=45&&tim>=35)
        timeover.x-=4;
    if(tim<=25&&tim>=15)
        timeover.x+=4;
    timeover.y-=40;
}

void eggfall_change()
{
    if(eggfall.y<=0){
        eggfall.x=(rand() % (upper - lower + 1)) + lower;
        eggfall.y=4560;
    }
    if(tim<=285&&tim>=275)
        eggfall.x-=4;
    if(tim<=265&&tim>=255)
        eggfall.x+=4;
    if(tim<=225&&tim>=215)
        eggfall.x-=4;
    if(tim<=205&&tim>=195)
        eggfall.x+=4;
    if(tim<=165&&tim>=155)
        eggfall.x-=4;
    if(tim<=145&&tim>=135)
        eggfall.x+=4;
    if(tim<=105&&tim>=95)
        eggfall.x-=4;
    if(tim<=85&&tim>=75)
        eggfall.x+=4;
    if(tim<=45&&tim>=35)
        eggfall.x-=4;
    if(tim<=25&&tim>=15)
        eggfall.x+=4;
    eggfall.y-=40;
}



void t1()
{
    if(slowfall)
    {
        fall=20;
        slowtime--;
        if(!slowtime)
        {
            fall=40;
            slowfall=0;
            slowtime=10;
        }
    }
    if(tim>0)
        tim--;
    if(!tim&&play)
        {
            iPauseTimer(0);
            iPauseTimer(1);
            iPauseTimer(2);
            iPauseTimer(3);
            iPauseTimer(4);
            iPauseTimer(5);
            iPauseTimer(6);
            iPauseTimer(7);
            pop_up_text=1;
        }
}
int main()
{

	pic.y = 1;
	golden_egg.x=murgi1.x=700;
	blue_egg.x=1200;
	white_egg.x=murgi2.x=350;
	time1.x=120;
	timeover.x=850;
	poop.x=1030;
	eggfall.x=520;
	golden_egg.y=blue_egg.y=890;
	white_egg.y=poop.y=810;
	time1.y=3040;
	eggfall.y=4560;
	timeover.y=6080;

    iSetTimer(10, golden_egg_change);
    iSetTimer(10, blue_egg_change);
	iSetTimer(10, white_egg_change);
    iSetTimer(10, time_change);
    iSetTimer(10, poop_change);
    iSetTimer(10, eggfall_change);
    iSetTimer(10, timeover_change);
	iSetTimer(1000, t1);
	PlaySound(TEXT("pek.wav"),NULL,SND_LOOP|SND_ASYNC);
	iInitialize(1300, 1100, "Catch the egg");
	return 0;
}
