#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene(int type)
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create(type);
   
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init(int type)
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    _nType = type;
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
/*
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
*/
    
    //brainc add text button
    CCMenuItemFont *itemBack = CCMenuItemFont::create("Back", this, menu_selector(HelloWorld::OnBackMenu_Click) );
    itemBack->setFontSizeObj(40);
    itemBack->setFontName("Arial");
    //创建CCMenu菜单，其他可认为是菜单项
    CCMenu* pMenu = CCMenu::create( itemBack, NULL);
   // menu->alignItemsVertically();//可以理解为设置成垂直排列
    //menu->alignItemsHorizontally();//水平排列
    pMenu->setPosition(ccp(visibleSize.width-80,40));
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel;
    if(_nType==TYPE_FIRE)
    {
        pLabel = CCLabelTTF::create("Fire test", "Arial", 24);
    }else
    {
        pLabel = CCLabelTTF::create("test", "Arial", 24);
    }
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);
/*
    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
*/
    runEffect(_nType);
    
    return true;
}

void HelloWorld::runEffect(int type)
{
    CCLOG("type=%d",_nType);
    
    if(_nType==TYPE_FIRE)
    {
        this->removeChildByTag(10001 ,true);
        CCParticleSystemQuad* system = CCParticleSystemQuad::create("fire.plist");
    
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

        system->setPosition(ccp(visibleSize.width/2,10));
        this->addChild(system ,1,10001);
    }
}

void HelloWorld::OnBackMenu_Click(CCObject* pSender)
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    
   
    pDirector->popScene();

}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
