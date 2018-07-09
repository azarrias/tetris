/*
* IScene.h
*
*  Created on: Jul 09, 2018
*      Author: adolfo
*/

#ifndef ISCENE_H_
#define ISCENE_H_

enum SceneType
{
	MENU_SCENE,
	GAME_SCENE,
	UNKNOWN
};

class IScene
{
public:
	virtual bool CleanUp() = 0;
	virtual bool Init() = 0;
	virtual bool Update() = 0;

	SceneType mType = UNKNOWN;
};

#endif // ISCENE_H_