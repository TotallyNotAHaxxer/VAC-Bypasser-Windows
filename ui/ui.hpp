#pragma once
#include "ui.hh"
#include "../globals.hh"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include "Icons.h"
#include "Call_Explore.h"
#include "../Hardware/WINDOWS_EXTERNAL_HARDWARE_INFORMATION(CPU Information X86+X64).h"
#include "../Hardware/WINDOWS_EXTERNAL_HARDWARE_INFORMATION(Included Header Files).h"
#include "../Hardware/WINDOWS_EXTERNAL_HARDWARE_INFORMATION(Memory Information).h"
#include "../Hardware/WINDOWS_EXTERNAL_HARDWARE_INFORMATION(Operating System Information).h"
#include "../Hardware/WINDOWS_EXTERNAL_HARDWARE_INFORMATION(CPU MANUFAC ID).h"
#include "Process_Modules.h"
#include "DLL_Injector.h"
#include "ByPasser.h"
#include <iostream>


namespace Settings {
	static std::string FILE;
	static int Tab = 0;
	static std::string Processname;
}

void ui::CheckF() {
	if (Settings::FILE == "") {
		result = openFile();
		switch (result) {
		case(TRUE): {
			Settings::FILE = sFilePath.c_str();
		}
		case(FALSE): {
			ImGui::Text("ERROR: \n", GetLastError());
		}
		}
	}
}




void ui::render() {
	{

		ImGuiStyle* style = &ImGui::GetStyle();
		style->WindowBorderSize = 0;
		style->WindowTitleAlign = ImVec2(0.5, 0.5);
		style->WindowMinSize = ImVec2(300, 200);
		style->FramePadding = ImVec2(8, 6);
		style->Colors[ImGuiCol_TitleBg] = ImColor(81, 2, 166, 255);
		style->Colors[ImGuiCol_TitleBgActive] = ImColor(81, 2, 166, 255);
		style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(0, 0, 0, 130);
		style->Colors[ImGuiCol_Button] = ImColor(31, 30, 31, 255);
		style->Colors[ImGuiCol_ButtonActive] = ImColor(41, 40, 41, 255);
		style->Colors[ImGuiCol_ButtonHovered] = ImColor(41, 40, 41, 255);
		style->Colors[ImGuiCol_Separator] = ImColor(70, 70, 70, 255);
		style->Colors[ImGuiCol_SeparatorActive] = ImColor(76, 76, 76, 255);
		style->Colors[ImGuiCol_SeparatorHovered] = ImColor(76, 76, 76, 255);
		style->Colors[ImGuiCol_FrameBg] = ImColor(37, 36, 37, 255);
		style->Colors[ImGuiCol_FrameBgActive] = ImColor(37, 36, 37, 255);
		style->Colors[ImGuiCol_FrameBgHovered] = ImColor(37, 36, 37, 255);
		style->Colors[ImGuiCol_Header] = ImColor(0, 0, 0, 0);
		style->Colors[ImGuiCol_HeaderActive] = ImColor(0, 0, 0, 0);
		style->Colors[ImGuiCol_HeaderHovered] = ImColor(46, 46, 46, 255);
		if (!globals.active) return;
		ImGui::SetNextWindowPos(ImVec2(window_pos.x, window_pos.y), ImGuiCond_Once);
		ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
		ImGui::SetNextWindowBgAlpha(1.0f);
		ImGui::Begin(window_title, &globals.active, window_flags); {
			ImGui::Spacing();
			ui::CheckF();
			ImGui::Spacing();
			if (ImGui::Button(ICON_FA_FIRE " Exit", ImVec2(230 - 15, 41))) {exit(0);}
			ImGui::Spacing();
			if (ImGui::Button(ICON_FA_PHONE " Simple Hardware Info", ImVec2(230 - 15, 41))) {Settings::Tab = 3;}
			ImGui::Spacing();
			if (ImGui::Button(ICON_FA_BUG " Inject Process", ImVec2(230 - 15, 41))) { Settings::Tab = 5; }
			ImGui::Spacing();
		}
	}


	
	{
		if (Settings::Tab == 3) {
			std::string MEMORYTAB = " MEMORY               - " + MEMI();
			std::string OPERATTAB = " OPERATING SYSTEM     - " + OSI();
			std::string MANUFACID1 = " CPU MANUFACTURE ID   - ", MANUFACID();
			std::string CPUTYPEN = " CPU TYPE NAME        - " + TYPE();
			if (ImGui::Begin("Hardware Information")) {
				ImGui::Text(MEMORYTAB.c_str());
				ImGui::Text(OPERATTAB.c_str());
				ImGui::Text(MANUFACID1.c_str());
				ImGui::Text(CPUTYPEN.c_str());
			}
			ImGui::End();
		}
		if (Settings::Tab == 5) {
			if (ImGui::Begin("Injector")) {
				DWORD PID = ProcFuncs::ProcData("csgo.exe");
				if (!PID) {
					ImGui::Text("ERROR: Could not find the process ID. Could not find the CSGO exe path");
				}
				else {
					ImGui::Text("Data Section: Was able to find process (csgo.exe) ");
					HANDLE handler = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
					uintptr_t MB = ProcFuncs::GMADDR(PID, "client.dll");
					if (Extra_Functions::F_Exists(Settings::FILE)) {
						if (!Bypass::EXEC(handler)) {
							ImGui::Text("Can not bypass VALVE ANTI CHEAT (VAC)");
						}
						if (Injector::Inject_Process(PID, Settings::FILE)) {
							Bypass::BUP(handler);
							ImGui::Text("DLL Has been successfully injected into the process");
						}
						else {
							Bypass::BUP(handler);
							ImGui::Text("DLL was not injected successfully, injection failed");

						}
					}
				}
			}
			ImGui::End();


		}

	}
    ImGui::End();
}

void ui::init(LPDIRECT3DDEVICE9 device) {
    dev = device;
    ImGui::StyleColorsDark();
	if (window_pos.x == 0) {
		RECT screen_rect{};
		GetWindowRect(GetDesktopWindow(), &screen_rect);
		screen_res = ImVec2(float(screen_rect.right), float(screen_rect.bottom));
		window_pos = (screen_res - window_size) * 0.5f;
	}
}
