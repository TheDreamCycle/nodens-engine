#include "ndpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "implot.h"
#include "implot3d.h"
#include "Nodens/Application.h"

#include "Tracy.hpp"

// TEMPORARY
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

namespace Nodens {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{

	}

	ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::OnAttach()
	{
		ZoneScoped;

		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImPlot::CreateContext();
		ImPlot3D::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		io.ConfigFlags |= ImGuiDockNodeFlags_PassthruCentralNode;

		// Set up Dear ImGui style
		ImGui::StyleColorsDark();

		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		Application& app = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 330");
		
	}

	void ImGuiLayer::OnDetach()
	{
		ZoneScoped;
		
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImPlot3D::DestroyContext();
		ImPlot::DestroyContext();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::Begin()
	{
		ZoneScoped;
		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::OnImGuiRender(TimeStep ts)
	{
	}


	void ImGuiLayer::End()
	{
		ZoneScoped;
		
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
		}
		glfwMakeContextCurrent(backup_current_context);
	}

}