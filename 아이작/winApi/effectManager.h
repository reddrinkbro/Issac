#pragma once
#include "singletonbase.h"

class effect;

class effectManager : public singletonBase<effectManager>
{
private:
	//����Ʈ Ŭ������ ���� ����
	typedef vector<effect*> arrEffects;
	typedef vector<effect*>::iterator iterEffects;
	//����Ʈ Ŭ������ ����ִ� ���͸� ���� ��
	typedef map<string, arrEffects> arrEffect;
	typedef map<string, arrEffects>::iterator iterEffect;
	typedef vector<map<string, arrEffects>> arrTotalEffect;
	typedef vector<map<string, arrEffects>>::iterator iterTotalEffect;

private:
	arrTotalEffect _vTotalEffects;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void addEffect(string effectName, const char* imageName,
		int imageWidth, int imageHeight, int effectWidth, int effectHeight,
		int fps, int buffer);

	void play(string effectName, int x, int y);

	bool isRunning(string effectName);

	effectManager() {}
	~effectManager() {}
};
