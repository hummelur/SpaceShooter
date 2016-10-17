#ifndef INCLUDED_EXPLOTIONMANAGER
#define INCLUDED_EXPLOTIONMANAGER

#include "Explotion.h"
#include <vector>
#include "GameObject.h"

class ExplotionManager {
public:
	static ExplotionManager * instance();

	ExplotionManager();
	~ExplotionManager();

	void addExplotion(GameObject *explotion);
	void delExplotion();
	void draw();
	void update();

	typedef std::vector<GameObject*> Explotions;
	Explotions m_explotions;

private:
	Timer *_timer;
	static ExplotionManager * sm_instance;
};
#endif // !INCLUDED_EXPLOTIONMANAGER
