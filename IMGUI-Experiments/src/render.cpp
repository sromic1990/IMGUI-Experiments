#include "render.h"
#include <imgui.h>
#include <implot.h>
#include <iostream>
#include <fmt/format.h>

void WindowClass::Draw(std::string_view label)
{
	constexpr static auto windowFlags =
		ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
	constexpr static auto windowSize = ImVec2(1280.0f, 720.0f);
	constexpr static auto windowPos = ImVec2(0.0f, 0.0f);

	ImGui::SetNextWindowSize(windowSize);
	ImGui::SetNextWindowPos(windowPos);

	ImGui::Begin(label.data(), nullptr, windowFlags);

	ImGui::End();
}

void render(WindowClass &window_obj)
{
	window_obj.Draw("Label");
}
