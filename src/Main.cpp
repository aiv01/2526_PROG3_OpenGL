#include <string>
#include <format>
#include "OGLWindow.h"
#include "Ex01TriangleDraw.h"
#include "Ex02QuadDraw.h"
#include "Ex03QuadIndexDraw.h"
#include "Ex04QuadColorDraw.h"
#include "Ex05QuadTextureDrawA.h"
#include "Ex05QuadTextureDrawB.h"
#include "Ex05QuadTextureDrawC.h"

int main() 
{
	OGLWindow Window{800, 600, "Hello OpenGL"};

	//Ex01TriangleDraw Scene;
	//Ex02QuadDraw Scene;
	//Ex03QuadIndexDraw Scene;
	//Ex04QuadColorDraw Scene;
	//Ex05QuadTextureDrawA Scene;  //BOX and SMILE
	//Ex05QuadTextureDrawB Scene;  //RANDOM IMAGE AND SMILE
	Ex05QuadTextureDrawC Scene;  //TV SCART EFFECT
	

	while(Window.IsOpened()) 
	{
		static float TitleUpdateMaxTime = 1.f;
		static float TitleUpdateElapsed = 0.f;

		float DeltaTime = Window.GetDeltaTime();
		TitleUpdateElapsed += DeltaTime;
		if (TitleUpdateElapsed >= TitleUpdateMaxTime) 
		{
			int Fps = 1.f / DeltaTime;
			std::string Title = std::format("OpenGL App | DeltaTime: {} - FPS: {}", DeltaTime, Fps);
			Window.SetTitle(Title);
			TitleUpdateElapsed -= TitleUpdateMaxTime;
		}

		Scene.Update(DeltaTime);
		
		Window.Update();
	}
	return 0;	
}