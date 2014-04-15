#ifndef __HelloCpp__MainScene__
#define __HelloCpp__MainScene__

#include "cocos2d.h"
#include "cocos-ext.h"



class MainScene
: public cocos2d::CCLayer //从CCLayer派生
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCNodeLoaderListener
{
public:

    MainScene();
    ~MainScene();

  static cocos2d::CCScene* scene();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MainScene, create);

    //button test
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    
    void onButtonTest(cocos2d::CCObject *pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void onButtonDream(cocos2d::CCObject *pSender, cocos2d::extension::CCControlEvent pCCControlEvent);

    // init label text
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    
    // label test
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject* pTarget, const char* pMemberVariableName, cocos2d::CCNode* pNode);
private:
    cocos2d::CCLabelBMFont *mLabelText;

};


class MainSceneLayerLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MainSceneLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MainScene);
};

#endif /* defined(__HelloCpp__MainScene__) */