/*
 * GameObject.cpp
 *
 *  Created on: May 26, 2018
 *      Author: adolfo
 */

#include "GameObject.h"
#include "Globals.h"

GameObject::GameObject()
: mVelocity({ 0, 0 }), mType(GameObjectType::UNKNOWN), mRect({ 0, 0, 0, 0 })
{}

GameObject::GameObject(GameObjectType type, int xPos, int yPos, int width, int height)
: mVelocity({ 0, 0 }), mRect({ xPos, yPos, width, height })
{}

GameObject::~GameObject()
{}

bool GameObject::CheckCollision(const GameObject &other) const
{
	return SDL_HasIntersection(GetRect(), other.GetRect());
}

const SDL_Rect* GameObject::GetRect() const
{
	return &mRect;
}

void GameObject::SetPos(int xPos, int yPos)
{
	mRect.x = xPos;
	mRect.y = yPos;
}

void GameObject::UpdatePos()
{

}

void GameObject::UpdateVel()
{

}
