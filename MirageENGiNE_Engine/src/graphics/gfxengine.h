#ifndef GFXENGINE_H
#define GFXENGINE_H

// std includes
#include <string>
#include <vector>
#include <map>

// mirage includes
#include "core/runstate.h"

typedef unsigned int GLuint;
typedef unsigned int GLenum;

namespace mirage
{

	class CoreEngine;
	class Camera;
	class RenderCMD;
	class ShaderProgram;

	class GraphicsEngine
	{
	public:
		GraphicsEngine(
			CoreEngine * const coreEngine = nullptr
		);
		~GraphicsEngine();

		void initialize();
		void render();
		void glErrorCheck();
		void setCurrentCamera(Camera * const camera);
		Camera * const getCurrentCamera() const;
		void pushRenderCMD(RenderCMD * const r_cmd);
		void clearRenderCMDs();
		const std::vector<RenderCMD *> & getRenderCMDs() const;
		void addShaderProgram(const std::string & identifier, ShaderProgram * program);
		void removeShaderProgram(const std::string & identifier);
		ShaderProgram * const getShaderProgram(const std::string & identifier);
	private:
		EngineRunState m_runState;
		CoreEngine * m_coreEngine;
		Camera * m_currentCamera;
		std::vector<RenderCMD *> m_renderCmds;
		std::map<std::string, ShaderProgram *> m_shaderPrograms;
		std::map<std::string, GLenum> m_textureSamplers;
	};

}

#endif // GFXENGINE_H