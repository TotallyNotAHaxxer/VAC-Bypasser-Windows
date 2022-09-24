#pragma once
#include <d3d9.h>
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"

/*
....................................................................................................................................
:													VECTOR 2 Explanation														   :																									
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: 
:																																   : 
: Vector 2 is a vector that represents 2 dimensional planes. X is going to be your left and right and Y is your up and down.	   :
:																																   : 
: In simplicity any function calling IMGUI that allows the vector or calls the Vector2 MUST have a X and a Y integer value.		   : 
:																																   :
: Again X will be the left or right orientation / width, the Y value will be your up and down values or your height. Please		   :
:																																   :
: Keep this in mind throughout developing the GUI, it is needed during styling.													   : 
:																																   :
: ~ RE43P3R 																													   :
:																																   :
:																																   :
:..................................................................................................................................:
*/

namespace ui {
	void init(LPDIRECT3DDEVICE9);
	void render();
	void Theme();
	void CheckF();
}

namespace ui {
	inline LPDIRECT3DDEVICE9 dev;
	inline const char* window_title = "CSGO Load Library Injector";
}


namespace ui {
	inline ImVec2 screen_res{ 000, 000 };
	inline ImVec2 window_pos{ 0, 0 };
	inline ImVec2 window_size{ 190, 200 }; // Vector 2 coresponds to a 2 Dimensional plane, X is the width and Y is the height.
	inline DWORD  window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
}