#include "stdafx.h"
#include "pillATKUP.h"

HRESULT pillATKUP::init(float x, float y)
{
	_pill.img = IMAGEMANAGER->addImage("pillAtk", "image/item/pillAtkUp.bmp", 34, 34, true, RGB(255, 0, 255));
	_pill.x = x;
	_pill.y = y;
	_pill.rc = RectMakeCenter(_pill.x, _pill.y, _pill.img->getWidth(), _pill.img->getHeight());
	_pill.isMove = true;
	_pill.speed = 0.0f;
	_pill.distance = 100;

	_gravity = -2.0f;
	_currnetAnlgeValue = PI / 2;

	_shadow = new shadow;
	_shadow->init(SHADOWSIZE_SMALL);
	return S_OK;
}

void pillATKUP::release(void)
{
	_shadow->release();
	SAFE_DELETE(_shadow);
}

void pillATKUP::update(void)
{
	if (_pill.isMove) move();
}

void pillATKUP::render(void)
{
	_shadow->render();
	_pill.img->render(getMemDC(), _pill.rc.left - CAMERAMANAGER->getX(), _pill.rc.top - CAMERAMANAGER->getY());
}

void pillATKUP::move(void)
{
	_pill.distance--;
	if (_pill.distance > 0)
	{
		_gravity += 0.055f;
		_pill.y -= sinf(_currnetAnlgeValue) * _pill.speed - _gravity;
		_pill.rc = RectMakeCenter(_pill.x, _pill.y, _pill.img->getWidth(), _pill.img->getHeight());
	}
	else
	{
		_shadow->update(_pill.x - 20, _pill.y + 10);
		_pill.isMove = false;
	}
}
