#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define kanan 77
#define kiri 75
#define atas 72
#define bawah 80

typedef struct{
	int score;
	int mulut;
}pacman_game;

pacman_game pacman;

void pacman_jalan(int map[24][27]);
void gambar_tembok(int map[24][27]);
void timer();
void menang();

int i,j;


int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm, "C:\\TC\\BGI");
    
     int map[24][27]= {
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
                    {1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1},
                    {1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
                    {1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
                    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                    {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
                    {1, 0, 1, 0, 1, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 1, 0, 1, 0, 1},
                    {1, 0, 1, 1, 1, 0, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 0, 1, 1, 1, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 0, 0, 0, 0, 0, 1},
                    {5, 0, 1, 1, 1, 0, 0, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 0, 0, 1, 1, 1, 0, 5},
                    {1, 0, 0, 0, 0, 0, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 0, 0, 0, 0, 0, 1},
                    {1, 0, 1, 1, 1, 0, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 0, 1, 1, 1, 0, 1},
                    {1, 0, 1, 0, 1, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 1, 0, 1, 0, 1},
                    {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
                    {1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1},
                    {1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1},
                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};	
	pacman_jalan(map);
   getch();
   closegraph();
    return 1;

}
/*
void timer()
{
	int detik=1;
	int menit=4;
	char waktu[20];
	while(1)
	{
		
	delay(100);
	detik--;	
	sprintf(waktu,  "%d : %d", menit, detik);
    outtextxy(550, 15, waktu);
		if(detik==0&&menit!=0)
		{
			detik=59;
			menit--;
		}
		if(detik==0&&menit==0)
		{
			cleardevice();
    		outtextxy(550, 20, "GAME OVER");
		}
	}
}
*/

void menang()
{
	char menang[20];
	if (pacman.score==1000)
	{
		cleardevice();
		sprintf(menang, "YOU WIINNNNN !!!!", pacman.score);
		outtextxy(50, 50, menang);
	}
}

void gambar_tembok(int map[24][27]){
	
		for( i=0; i<24 ; i++){
    		for ( j=0;j< 27;j++){
    			if (map[i][j]==1)
    			{
    				rectangle(j*20,i*20,(j+1)*20,(i+1)*20);
					setfillstyle(SOLID_FILL,10);	
				}
				else if
				(map[i][j]==0)
				{
						pieslice(j*20+(20/2),i*20+(20/2),0,0,5);
				}
			}
		}
		    menang();		// kondisi untuk pacman menang
}



void pacman_jalan(int map[24][27]){
	pacman.score = 0 ;	
	pacman.mulut=1;
	int a=45,b=-45,r=10 ,c=1, d=1;
	int x= d * 20 + (20/2); 
	int y= c * 20 + (20/2); 
	int input;	 // pacman initial state
	int page=0;
	
	for(;;) {
 	gambar_tembok(map);//menampilakn tembok pacman
	if(kbhit())
	{
		input=getch();
		}	
	switch(input){
	case kanan :  //kondisi input kanan
	if(pacman.mulut%2==0 ){
	if (map[c][d+1]==0||map[c][d+1]==2){
	cleardevice();
	x=x+20;
	pacman.mulut=pacman.mulut+1;
	a=45;
	b=-45;
	pieslice(x,y,a,b,r);
	c=c;
	d=d+1;
		if (map[c][d]==0)			// kondisi pengambilan makanan
		{
			pacman.score=pacman.score+100;
		}
	map[c][d]=2;
	}
	else if(map[c][d+1]==5){
		cleardevice();
		x=x+20;
		pacman.mulut=pacman.mulut+1;
		a=45;
		b=-45;
		pieslice(x,y,a,b,r);
		d=d+1;
		if(map[c][d]==5){
		pieslice(x,y,a,b,r);
		d=0;
		c=12;
		x= d * 20 + (20/2); 
		y= c * 20 + (20/2); 
		cleardevice();
		pieslice(x,y,a,b,r);}
	} //akhir kondisi yang map[c][d]==5
}
	else
	{
	if (map[c][d+1]==0||map[c][d+1]==2){
	cleardevice();
	x=x+20;
	pacman.mulut=pacman.mulut+1;
	a=10;
	b=-10;
	pieslice(x,y,a,b,r);
    d=d+1;
    if (map[c][d]==0)
		{
			pacman.score=pacman.score+100;
		}
    map[c][d]=2;
	} // akhir kondisi map[c][d]==0
	
	if(map[c][d+1]==5){
		cleardevice();
		x=x+20;
		pacman.mulut=pacman.mulut+1;
		a=45;
		b=-45;
		pieslice(x,y,a,b,r);
		d=d+1;
		if(map[c][d]){
		pieslice(x,y,a,b,r);
		d=0;
		c=12;
		x= d * 20 + (20/2); 
		y= c * 20 + (20/2); 
		cleardevice();
		pieslice(x,y,a,b,r);}
		} // akhir kondisi map[c][d] == 5
	}
 break;// akhir kondisi if input == kanan



	
case kiri : //konsisi input kiri

	if(pacman.mulut%2==0 ){
	if (map[c][d-1]==0||map[c][d-1]==2){
	cleardevice();
	x=x-20;
	pacman.mulut=pacman.mulut+1;
	a=225;
	b=-225;
	pieslice(x,y,a,b,r);
	d=d-1;
	if (map[c][d]==0) 		// kondisi pengambilan makanan
		{
			pacman.score=pacman.score+100;
		}
	map[c][d]=2;
	}
	if(map[c][d-1]==5){
		cleardevice();
		x=x-20;
		pacman.mulut=pacman.mulut+1;
		a=225;
		b=-225;
		pieslice(x,y,a,b,r);
		d=d-1;
		} //akhir kondisi map[c][d]==5
	    if(map[c][d] == 5){
		pieslice(x,y,a,b,r);
		d=26;
		c=12;
		x= d * 20 + (20/2); 
		y= c * 20 + (20/2); 
		cleardevice();
		pieslice(x,y,a,b,r);
		}
} // akhir kondisi if input == kiri
	else
	{
	if (map[c][d-1]==0||map[c][d-1]==2){
	cleardevice();
	x=x-20;
	pacman.mulut=pacman.mulut+1;
	a=-170;
	b=170;
	pieslice(x,y,a,b,r);
	d=d-1;
	if (map[c][d]==0)
		{
		pacman.score=pacman.score+100;
		}
	map[c][d]=2;
	}
		if(map[c][d-1]==5){
		cleardevice();
		x=x-20;
		pacman.mulut=pacman.mulut+1;
		a=225;
		b=-225;
		pieslice(x,y,a,b,r);
		d=d-1;
		if(map[c][d]==5){
		pieslice(x,y,a,b,r);
		d=26;
		c=12;
		x= d * 20 + (20/2); 
		y= c * 20 + (20/2); 
		cleardevice();
		pieslice(x,y,a,b,r);}
		} // akhir kondisi map[c][d]==5
}		
break;//akhir input kiri




case atas: //kondisi input atas
	if(pacman.mulut%2==0 ){
	if (map[c-1][d]==0||map[c-1][d]==2){
	cleardevice();
	y=y-20;
	pacman.mulut=pacman.mulut+1;
	a=135;
	b=45;
	pieslice(x,y,a,b,r);
    c=c-1;
    if (map[c][d]==0)				// kondisi pengambilan makanan
		{
			pacman.score=pacman.score+100;
		}
	map[c][d]=2;
	}
}
else
{
	if (map[c-1][d]==0||map[c-1][d]==2){
	cleardevice();
	y=y-20;
	pacman.mulut=pacman.mulut+1;
	a=100;
	b=80;
	pieslice(x,y,a,b,r);
   	c=c-1;
   	if (map[c][d]==0) 		// kondisi pengambilan makanan
		{
			pacman.score=pacman.score+100;
		}
	map[c][d]=2;   
	}	
}
break; //akhir input atas
	
	
	
	
	
case bawah : //kondisi input bawah
	if(pacman.mulut%2==0 ){
	if (map[c+1][d]==0||map[c+1][d]==2){
	cleardevice();
	y=y+20;
	pacman.mulut=pacman.mulut+1;
	a=-45;
	b=-135;
	pieslice(x,y,a,b,r);
  	c=c+1;
  	if (map[c][d]==0)				// kondisi pengambilan makanan
		{
			pacman.score=pacman.score+100;
		}
  	map[c][d]=2;
		} 
	}
	else
	{
	if (map[c+1][d]==0||map[c+1][d]==2){
	cleardevice();
	y=y+20;
	pacman.mulut=pacman.mulut+1;
	a=-80;
	b=260;
	pieslice(x,y,a,b,r);
  	c=c+1;
  	if (map[c][d]==0)				// kondisi pengambilan makanan
		{
			pacman.score=pacman.score+100;
		}
  	map[c][d]=2;
	}
	}
break;
 //kondisi akhir input bawah


}
	char skor[20];
	sprintf(skor, "Score : %d", pacman.score);	// menampilkan skor
    outtextxy(550, 10, skor);
	gambar_tembok(map);
	setactivepage(page);
	setvisualpage(1-page);
	page=1-page;
	delay(80);
}
}//akhir modul
