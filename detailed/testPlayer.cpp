#include <stdio.h>
#include "fssimplewindow.h"
#include "player.h"
#include "arm.h"
#include "body.h"
#include "leg.h"

int main(void) 
{

	FsOpenWindow(16,16,800,600,1);
	Player p1,p2;
	p1.SetCharacter(1);
	int T=0;
	for(;;) 
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
		T++;
		FsPollDevice(); 
		auto key=FsInkey();
		if(FSKEY_ESC==key) 
		{
			break; 
		}
		else if(FSKEY_A==key)
		{
			p1.ChangeDirc(1);
			p1.Move();
		}
		else if(FSKEY_D==key)
		{
			p1.ChangeDirc(0);
			p1.Move();
		}
		else if(FSKEY_W==key)
		{
			p1.Punch();
		}
		else if(FSKEY_S==key)
		{
			p1.Punch();
		}
		p1.Draw();
		FsSwapBuffers();
		FsSleep(10);
	}
	return 0; 
}