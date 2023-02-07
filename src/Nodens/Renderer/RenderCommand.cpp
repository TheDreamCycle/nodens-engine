#include "ndpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Nodens {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}