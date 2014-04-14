#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#define TYPE_FIRE   1

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(int type);

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene(int type);
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    void OnBackMenu_Click(CCObject* pSender);
    
    void runEffect(int type);
    
    // implement the "static node()" method manually
   // CREATE_FUNC(HelloWorld);
    static HelloWorld* create(int type)
    {
        HelloWorld *pRet = new HelloWorld();
        if (pRet && pRet->init(type))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
 
    }
    
    CC_SYNTHESIZE(int, _nType , nType);
};

#endif // __HELLOWORLD_SCENE_H__
