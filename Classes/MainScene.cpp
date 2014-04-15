#include "MainScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

// label test
MainScene::MainScene()//构造函数
: mLabelText(NULL)
{}

MainScene::~MainScene()//析构函数中释放内存不能忘
{
    CC_SAFE_DELETE(mLabelText);
}

bool MainScene::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mLabelText", CCLabelBMFont*, this->mLabelText);
    
    return true;
}

// button test
SEL_MenuHandler MainScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler MainScene::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onButtonTest", MainScene::onButtonTest);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onButtonDream", MainScene::onButtonDream);
    
    return NULL;
}


void MainScene::onButtonTest(cocos2d::CCObject *pSender, cocos2d::extension::CCControlEvent pCCControlEvent)
{
   //this->mLabelText->setString("Hello CocosBuilder!!!");
    
    CCLOG("onButtonTest");
   
    CCDirector* pDirector = CCDirector::sharedDirector();
    
    CCScene *pScene = HelloWorld::scene(TYPE_FIRE);
    pDirector->pushScene(pScene);
}

void MainScene::onButtonDream(cocos2d::CCObject *pSender, cocos2d::extension::CCControlEvent pCCControlEvent)
{
    //this->mLabelText->setString("Hello CocosBuilder!!!");
    
    CCLOG("onButtonDream");
    
    CCDirector* pDirector = CCDirector::sharedDirector();
    
    CCScene *pScene = HelloWorld::scene(TYPE_DREAM);
    pDirector->pushScene(pScene);
}

// init label text
void MainScene::onNodeLoaded(cocos2d::CCNode *pNode, cocos2d::extension::CCNodeLoader *pNodeLoader)
{
   this->mLabelText->setString("vers 1.0");
}

CCScene* MainScene::scene()
{

    CCScene *scene = CCScene::create();
    
    CCNodeLoaderLibrary *lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary(); //生成一个默认的Node Loader

    lib->registerCCNodeLoader("MainScene", MainSceneLayerLoader::loader());
    
    CCBReader *reader = new CCBReader(lib); //用node load lib 初始化一个ccb reader
    
    CCNode *node = reader->readNodeGraphFromFile("MainScene.ccbi", scene); //从ccbi文件中加载node //
    
    reader->release(); //注意手动释放内存
    
    if (node!=NULL)
    {
        scene->addChild(node); //将node 添加到scene中
    }
  
    return scene;

}