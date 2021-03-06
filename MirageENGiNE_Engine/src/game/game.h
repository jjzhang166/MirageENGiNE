#ifndef GAME_H
#define GAME_H

// std includes
#include <string>
#include <vector>

namespace mirage
{

	class CoreEngine;
	class GraphicsEngine;
	class GameObject;
	class GameComponent;

	class Game
	{
	public:
		Game();
		virtual ~Game();

		virtual void initialize() = 0;
		virtual void update(float dt) = 0;
		virtual void render(GraphicsEngine * const gfxEngine) = 0;
		virtual void renderGUI() = 0;
		virtual void renderGUI_GameObjectTree(GameObject * const node);
		virtual void setEngine(CoreEngine * const engine);
		virtual CoreEngine * const getEngine();
		virtual void addRootLevelObject(GameObject * const object);
		virtual void clearAllObjects();
		virtual const std::vector<GameObject *> & getRootLevelObjects() const;
		virtual GameObject * const getObject(const std::string & identifier, GameObject * const node = nullptr);

		virtual void api_lockCursor(bool lock) const;
		virtual bool api_isCursorLocked() const;
		virtual void api_setCursorPos(float x, float y);
	private:
	protected:
		CoreEngine * m_coreEngine;
		std::vector<GameObject *> m_objects;
	};

}

#endif // GAME_H